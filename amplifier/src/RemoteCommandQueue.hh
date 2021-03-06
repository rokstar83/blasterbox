/*****************************************************************************/ 
/* RemoteCommandQueue.hh                                                     */
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
#ifndef REMOTECOMMANDQUEUE_HH_
#define REMOTECOMMANDQUEUE_HH_

#include <vector>
#include <queue>
#include <mutex>

namespace BlasterBox {
	 class RemoteCommand;

	 class RemoteCommandQueue
	 {
	 public:
			RemoteCommandQueue();
			~RemoteCommandQueue();

			virtual void parseCommand(const std::vector<unsigned char> & cmdData);
			virtual void push(RemoteCommand *);
			virtual RemoteCommand * pop();
			virtual bool hasCommands() const;
			virtual unsigned int size() const;

	 private:
			void flushCommands();

			std::queue<RemoteCommand *> _cmdQueue;
			std::mutex _mux;
	 };
}

#endif /* REMOTECOMMANDQUEUE_HH_ */
