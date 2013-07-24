/*****************************************************************************/ 
/* RemoteCommandList.hh BlasterBox Server                                    */
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
#ifndef REMOTECOMMANDLIST_HH_
#define REMOTECOMMANDLIST_HH_

namespace BlasterBox {
	 const char REMOTE_COMMAND_PREFIX[] = "HODOR!";
	 const unsigned short REMOTE_COMMAND_PREFIX_LEN = 6;
	 const unsigned short REMOTE_COMMAND_LEN = 8;

	 enum class CommandType : unsigned char { SIMPLE = 0x01,
				 VARLEN = 0X02, };

	 enum class SimpleCommand : unsigned char { NOOP = 0x00,
				 PLAY = 0x01, 
				 PAUSE = 0x02,
				 PREV = 0x03,
				 NEXT = 0x04, };

	 struct SimpleMessage {
			char _prefix[6];
			CommandType _type;
			SimpleCommand _cmd;
	 };
}

#endif /* REMOTECOMMANDLIST_HH_ */
