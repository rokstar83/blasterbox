/*****************************************************************************/ 
/* MockRemoteClient.hh for BlasterBox Server Tests                           */
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
#ifndef MOCKREMOTECLIENT_HH_
#define MOCKREMOTECLIENT_HH_
#include <string>
#include <sys/types.h>
#include <netdb.h>
#include <netinet/in.h>
#include <string>
#include <stdexcept>

namespace BlasterBox {

	 class MockRemoteClient
	 {
	 public:
			MockRemoteClient();
			~MockRemoteClient();
			
			void connect();
			void send(const unsigned char * msg, ssize_t msgLen);
			void recv(unsigned char ** msg, ssize_t & msgLen);
			
	 private:
			int _sd;
			hostent * _hostInfo;
			sockaddr_in _socketInfo;
			std::string _hostname;
	 };

	 class MockRemoteClientException : public std::runtime_error
	 {
	 public:
			explicit MockRemoteClientException(const std::string & msg);
	 };
	 
}
#endif /* MOCKREMOTECLIENT_HH_ */
