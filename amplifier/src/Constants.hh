/*****************************************************************************/ 
/* Constants.hh for BlasterBox Amplifier                                     */
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
#ifndef CONSTANTS_HH_
#define CONSTANTS_HH_

namespace BlasterBox {
	 const int DEFAULT_LISTEN_PORT = 9999;
	 const int MAX_HOST_NAME = 256;
	 const unsigned int MAX_REMOTE_CONNECTIONS = 6;
	 const int DEFAULT_TIMEOUT_SEC = 1;
	 const int DEFAULT_TIMEOUT_USEC = 0;
	 const int BUF_LEN = 50;
	 const unsigned char MSG_TERM = '\0';
}

#endif /* CONSTANTS_HH_ */
