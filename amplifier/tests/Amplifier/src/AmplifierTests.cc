/*****************************************************************************/ 
/* AmplifierTests.cc                                                         */
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
#include "AmplifierTests.hh"
#include "../../../src/Amplifier.hh"
#include "../../../src/AmplifierException.hh"

namespace BlasterBox {
	 void AmplifierTests::setup() {}

	 void AmplifierTests::tearDown() {}

	 void AmplifierTests::checkBadConfFile()
	 {
			std::string badConfFileLocation = "/path/to/nowhere.conf";
			std::string logFileLocation = "../data/blasterbox.log";
			CPPUNIT_ASSERT_THROW(Amplifier(badConfFileLocation, logFileLocation),
													 AmplifierException);
	 }

	 void AmplifierTests::checkBadLogFile()
	 {
			std::string confFileLocation = "../data/blasterbox.conf";
			std::string badLogFileLocation = "/path/to/nowhere.conf";
			CPPUNIT_ASSERT_THROW(Amplifier(confFileLocation, badLogFileLocation),
													 AmplifierException);
	 }
}
