/*****************************************************************************/ 
/* RemoteListener.hh for BlasterBox Amplifier                                */
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
#ifndef REMOTELISTENER_HH_
#define REMOTELISTENER_HH_
#include "Constants.hh"
#include <fcntl.h>
#include <netinet/in.h>
#include <list>
#include <vector>
#include <utility>

struct hostent;

namespace BlasterBox {
	 class RemoteCommandQueue;
	 class Logger;

#ifdef UNIT_TESTING
	 class RemoteListenerTests;
#endif//UNIT_TESTING
	 
	 class RemoteListener 
	 {
			typedef std::pair<int, std::vector<unsigned char>> SocketData;
	 public:
			RemoteListener(RemoteCommandQueue & cmdQueue, Logger & logger, 
										 unsigned int port = DEFAULT_LISTEN_PORT);
			~RemoteListener();

			void listenLoop();
			void stopListening();

			bool hasConnections() const;
			unsigned int numConnections() const;

			bool isInitialized() const;
			
	 private:
			void initialize();
			void processNewConnection();
			void buildFDs(fd_set & fds);
			void readSocket(SocketData & sd);
			void processSocketBuffer(std::vector<unsigned char> & buf);
			void makeNonBlocking(int fd) const;

			RemoteCommandQueue & _cmdQueue;
			Logger & _logger;
			
			unsigned int _port;
			int _listenSock;
			unsigned int _listenPort;
			::hostent * _hostInfo;
			struct sockaddr_in _socketInfo;

			std::list<SocketData> _remoteSocks;
			bool _initialized;
			bool _listening;

#ifdef UNIT_TESTING			
			friend class RemoteListenerTests;
#endif//UNIT_TESTING

	 };
}

#endif /* REMOTELISTENER_HH_ */
