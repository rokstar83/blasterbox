/*****************************************************************************/ 
/* MockCommandQueue.cc for BlasterBox Amplifier                              */
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
#include "RemoteCommandQueue.hh"
#include "RemoteCommand.hh"

namespace BlasterBox {

	 RemoteCommandQueue::RemoteCommandQueue()
	 {
	 }

	 RemoteCommandQueue::~RemoteCommandQueue()
	 {
			flushCommands();
	 }

	 void RemoteCommandQueue::parseCommand(const std::vector<unsigned char> & cmdData)
	 {
			throw -1;
	 }

	 void RemoteCommandQueue::push(RemoteCommand * cmd)
	 {
			_cmdQueue.push(cmd);
	 }

	 RemoteCommand * RemoteCommandQueue::pop()
	 {
			if(!hasCommands())
				 return NULL;

			RemoteCommand * retval = _cmdQueue.front();
			_cmdQueue.pop();
			return retval;
	 }

	 bool RemoteCommandQueue::hasCommands() const
	 {
			return _cmdQueue.size() == 0 ? false : true;
	 }

	 unsigned int RemoteCommandQueue::size() const
	 {
			return _cmdQueue.size();
	 }

	 void RemoteCommandQueue::flushCommands() 
	 {
			while(hasCommands()) {
				 RemoteCommand * cmd = pop();
				 if(cmd != NULL)
						delete cmd;
			}
	 }
}
