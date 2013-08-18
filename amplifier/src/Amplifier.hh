/*****************************************************************************/ 
/* Amplifier.hh                                                              */
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
#ifndef AMPLIFIER_HH_
#define AMPLIFIER_HH_

#include <string>

namespace BlasterBox {

	 class Amplifier 
	 {
	 public:
			Amplifier(std::string confFile, std::string logFile);
			
			void start();
	 private:
			std::string _confFile;
			std::string _logFile;
	 };
}

#endif /* AMPLIFIER_HH_ */
