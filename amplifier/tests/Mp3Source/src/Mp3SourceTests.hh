/*****************************************************************************/ 
/* Mp3SourceTests.hh for BlasterBox Amplifier Tests                          */
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
#ifndef MP3SOURCETESTS_HH_
#define MP3SOURCETESTS_HH_
#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

namespace BlasterBox {

	 const char DATA_PATH[] = "../data/";
	 
	 class Mp3SourceTests : public CppUnit::TestFixture
	 {
			CPPUNIT_TEST_SUITE(Mp3SourceTests);
			CPPUNIT_TEST(testSetFile);
			CPPUNIT_TEST(testGetData);
			CPPUNIT_TEST_SUITE_END();

	 public:
			void setup();
			void tearDown();

			void testSetFile();
			void testGetData();
	 };

	 CPPUNIT_TEST_SUITE_REGISTRATION(Mp3SourceTests);
}

#endif /* MP3SOURCETESTS_HH_ */
