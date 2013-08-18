/*****************************************************************************/ 
/* Amplifier.cc                                                              */
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
#include "Amplifier.hh"
#include "AmplifierException.hh"

namespace BlasterBox {
	 Amplifier::Amplifier(std::string confFile, std::string logFile) :
			_confFile(confFile), _logFile(logFile)
	 {	 
	 }

	 void Amplifier::start()
	 {
			throw AmplifierException("Not Implemented");
	 }
}
