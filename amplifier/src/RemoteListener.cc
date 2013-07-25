/*****************************************************************************/ 
/* RemoteListener.cc for BlasterBox Amplifier                                */
/* Copyright (c) 2013 Tom Hartman (rokstar83@gmail.com)                      */
/*                                                                           */
/* This program is free software; you can redistribute it and/or             */
/* modify it under the terms of the GNU General Public License               */
/* as published by the Free Software Foundation; either version 2            */
/* of the License, or the License, or (at your option) any later             */
/* version.                                                                  */
/*                                                                           */
/* This program is distributed in the hope that it will be useful,           */
/* but WITHOUT ANY WARRANTY; without even the implied warranty of            */
/* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             */
/* GNU General Public License for more details.                              */
/*****************************************************************************/
#include "RemoteListener.hh"
#include "RemoteListenerException.hh"
#include "RemoteCommandList.hh"
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/time.h>
#include <sys/select.h>
#include <sys/types.h>
#include <vector>
#include <algorithm>

namespace BlasterBox {
	 
	 RemoteListener::RemoteListener(RemoteCommandQueue & cmdQueue, 
																	Logger & logger, unsigned int port) :
			_cmdQueue(cmdQueue), _logger(logger)
	 {
			_port = port;
			_listenSock = -1;			
			_hostInfo = nullptr;
			_initialized = false;
			_listening = false;

      // setup socket options
			memset(&_socketInfo, 0, sizeof(_socketInfo));
			_socketInfo.sin_family = AF_INET;
			_socketInfo.sin_addr.s_addr = htonl(INADDR_ANY);
			_socketInfo.sin_port = htons(_port);		
	 }

	 RemoteListener::~RemoteListener()
	 {
			if(_listenSock > 0)
				 close(_listenSock);
	 }

	 void RemoteListener::listenLoop()
	 {
			initialize();
		 
			if(::listen(_listenSock, MAX_REMOTE_CONNECTIONS) != 0) {
				 throw RemoteListenerException("Unable to listen to socket. "
																			 "Error is : " + std::to_string(errno));
			}

			fd_set fds;
			::timeval timeout;
			_initialized = true;
			_listening = true;

			while(_listening) {
				 buildFDs(fds);
				 timeout.tv_sec = DEFAULT_TIMEOUT_SEC;
				 timeout.tv_usec = DEFAULT_TIMEOUT_USEC;
				 
				 int readable = select(FD_SETSIZE, &fds, nullptr, nullptr, &timeout);
				 if(readable < 0) {
						throw RemoteListenerException("Error on selecting fds. "
																					"Error number is: " + std::to_string(errno));
				 }else if(readable > 0) {
						if(FD_ISSET(_listenSock, &fds)) {
							 processNewConnection();							 
						}												
						
						std::for_each(_remoteSocks.begin(), _remoteSocks.end(), 
													[&] (SocketData sd) { 
														 if(FD_ISSET(sd.first, &fds)) readSocket(sd); });
				 }
			}
	 }

	 void RemoteListener::stopListening()
	 {
			_listening = false;
	 }

	 bool RemoteListener::hasConnections() const
	 {
			return (_remoteSocks.size() != 0);
	 }

	 unsigned int RemoteListener::numConnections() const
	 {
			return _remoteSocks.size();
	 }

	 bool RemoteListener::isInitialized() const
	 {
			return _initialized;
	 }

	 void RemoteListener::initialize()
	 {
			char hostname[MAX_HOST_NAME+1];

			::gethostname(hostname, MAX_HOST_NAME);
			if((_hostInfo = ::gethostbyname(hostname)) == nullptr) {
				 throw RemoteListenerException("Hostname misconfigured");
			}

			if((_listenSock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
			{
				 throw RemoteListenerException("Unable to acquire socket"
																			 "Error is : " + std::to_string(errno) + "\n");
			}

			int optval = 1;
			::setsockopt(_listenSock, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));			

			makeNonBlocking(_listenSock);

			/* Let open up us a socket */
			if(::bind(_listenSock, (struct sockaddr *)&_socketInfo, sizeof(struct sockaddr_in)) < 0) {
				 throw RemoteListenerException("Unable to bind socket to local address. "
				                               "Error is : " + std::to_string(errno) + "\n");
			}			
	 }

	 void RemoteListener::processNewConnection() 
	 {
			int conn = 0;
			conn = ::accept(_listenSock, nullptr, nullptr);
			if(conn < 0) {
				 throw RemoteListenerException("Error while accepting incoming "
																			 "remote connection. Error is : " + 
																			 std::to_string(errno));
			}

			makeNonBlocking(conn);

			if(_remoteSocks.size() == MAX_REMOTE_CONNECTIONS) {
				 // Send EBUSY message back to remote
				 // HUP the incomming connection
				 close(conn);
			}

			_remoteSocks.push_back(SocketData(conn,vector<unsigned char>()));
	 }

	 void RemoteListener::buildFDs(fd_set & fds)
	 {
			FD_ZERO(&fds);
			FD_SET(_listenSock, &fds);
			std::for_each(_remoteSocks.begin(), _remoteSocks.end(), 
										[&] (SocketData sd) { FD_SET(sd.first, &fds); });
	 }
	 
	 void RemoteListener::readSocket(SocketData & sd)
	 {
			unsigned char buf[BUF_LEN];
			int len = read(fd, buf, BUF_LEN);
			if(len < 0) { 
				 throw RemoteListenerException("Error while reading from socket."
																			 "Error number is : " + std::to_string(errno));
			} else if(len > 0) {
				 for(int x = 0; x < len; ++x) {
						sd.second.push_back(buf[x]);
				 }
				 processSocketBuffer(sd.second);
			}			
	 }

	 void RemoteListener::processSocketBuffer(std::vector<unsigned char> & buf)
	 {
			
	 }
	 
	 void RemoteListener::makeNonBlocking(int fd) const
	 {
			int opts = ::fcntl(fd, F_GETFL);
			if(opts < 0) {
				 throw RemoteListenerException("Failed to get file descriptor options."
																			 "Error number is : " + std::to_string(errno));
			}

			opts |= O_NONBLOCK;
			if(fcntl(fd, F_SETFL, opts) < 0) {
				 throw RemoteListenerException("Failed to set file descriptor options."
																			 "Error number is : " + std::to_string(errno));
			}
	 }
}
