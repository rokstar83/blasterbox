/*****************************************************************************/ 
/* AmplifierTests.hh                                                         */
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
#ifndef AMPLIFIERTESTS_HH_
#define AMPLIFIERTESTS_HH_
#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

namespace BlasterBox {
	 class AmplifierTests : public CppUnit::TestFixture
	 {
			CPPUNIT_TEST_SUITE(AmplifierTests);
			CPPUNIT_TEST(checkBadConfFile);
			CPPUNIT_TEST(checkBadLogFile);
			CPPUNIT_TEST_SUITE_END();
	 public:
			void setup();
			void tearDown();

			void checkBadConfFile();
			void checkBadLogFile();
	 };

	 CPPUNIT_TEST_SUITE_REGISTRATION(AmplifierTests);
}

#endif /* AMPLIFIERTESTS_HH_ */
