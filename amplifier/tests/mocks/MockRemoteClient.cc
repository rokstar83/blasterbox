/*****************************************************************************/ 
/* MockRemoteClient.cc for BlasterBox Server Tests                           */
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
#include "MockRemoteClient.hh"
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "../../src/Constants.hh"

namespace BlasterBox {
	 MockRemoteClient::MockRemoteClient()
	 {
			memset(&_socketInfo, 0, sizeof(sockaddr_in));
			_sd = -1;
			_hostname = "127.0.0.1";
	 }

	 MockRemoteClient::~MockRemoteClient()
	 {
			if(_sd != -1)
				 close(_sd);
	 }

	 void MockRemoteClient::connect() 
	 {
			_sd = ::socket(AF_INET, SOCK_STREAM, 0);
			if(_sd < 0) {
				 throw MockRemoteClientException("Unable to aquire socket.");
			}

			_hostInfo = gethostbyname(_hostname.c_str());
			if(_hostInfo == 0) {
				 throw MockRemoteClientException("Unable to find host '" + _hostname + "'");
			}

			_socketInfo.sin_family = AF_INET;
			_socketInfo.sin_addr.s_addr =
				 ((struct in_addr *)(_hostInfo->h_addr))->s_addr;
			_socketInfo.sin_port = htons(DEFAULT_LISTEN_PORT);

			int err;
			err = ::connect(_sd, (struct sockaddr *) &_socketInfo, sizeof(_socketInfo));

			if(err == -1) {
				 throw MockRemoteClientException("Unable to establish remote connection. "
																				 "Error is: " + std::to_string(errno)); 
			}
	 }

	 void MockRemoteClient::send(const unsigned char * msg, ssize_t msgLen)
	 {
			if(_sd == -1) {
				 throw MockRemoteClientException("Socket descriptor is invalid. Please "
																				 "call connect before send or recv.");
			}
			
			ssize_t len = ::send(_sd, msg, msgLen, 0);

			if(len != msgLen) {
				 throw MockRemoteClientException("Incomplete send of data.");
			}
	 }

	 void MockRemoteClient::recv(unsigned char ** msg, ssize_t & msgLen)
	 {
			if(_sd != -1) {
				 throw MockRemoteClientException("Socket descriptor is invalid. "
																				 "Please call connect before send or "
																				 "recv.");
			}

			throw MockRemoteClientException("Not implemented.");
	 }

	 MockRemoteClientException::MockRemoteClientException(const std::string & msg)
			: std::runtime_error(msg)
	 {
	 }
}
