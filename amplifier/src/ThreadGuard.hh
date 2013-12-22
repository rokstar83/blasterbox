/*****************************************************************************/ 
/* ThreadGuard.hh                                                            */
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
#ifndef THREADGUARD_HH_
#define THREADGUARD_HH_
#include <thread>

namespace BlasterBox {
	 class ThreadGuard 
	 {
	 public:
			explicit ThreadGuard(std::thread & t) : _t(t) {}
			~ThreadGuard() { _t.join(); }
			ThreadGuard(ThreadGuard const &)=delete;
			ThreadGuard & operator=(ThreadGuard const &)=delete;
	 private:
			std::thread & _t;
	 };
}

#endif /* THREADGUARD_HH_ */
