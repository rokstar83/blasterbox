/*****************************************************************************/ 
/* Mp3SourceTests.cc for BlasterBox Amplifier Tests                          */
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
#include "Mp3SourceTests.hh"
#include "../../../src/Mp3Source.hh"
#include "../../../src/Mp3SourceException.hh"

namespace BlasterBox {
	 
	 void Mp3SourceTests::setup() {}

	 void Mp3SourceTests::tearDown() {}

	 void Mp3SourceTests::testSetFile()
	 {
			Mp3Source mp3Source;

			/* Tests setting a non-existant file */
			CPPUNIT_ASSERT_THROW(mp3Source.setFilePath(std::string(DATA_PATH) + 
																								 "DNE.mp3"),
													 Mp3SourceException);
			CPPUNIT_ASSERT(!mp3Source.hasData());
			CPPUNIT_ASSERT(mp3Source.getFilePath() == std::string());

			/* Test setting a file that isn't an mp3 */
			CPPUNIT_ASSERT_THROW(mp3Source.setFilePath(std::string(DATA_PATH) + 
																								 "notanmp3.txt"),
													 Mp3SourceException);
			CPPUNIT_ASSERT(!mp3Source.hasData());
			CPPUNIT_ASSERT(mp3Source.getFilePath() == std::string());

			/* Test setting an mp3 file that is bad or corrupted */
			CPPUNIT_ASSERT_THROW(mp3Source.setFilePath(std::string(DATA_PATH) + 
																								 "badmp3.mp3"),
													 Mp3SourceException);
			CPPUNIT_ASSERT(!mp3Source.hasData());
			CPPUNIT_ASSERT(mp3Source.getFilePath() == std::string());

			/* Test a mono mp3 */
			CPPUNIT_ASSERT_NO_THROW(mp3Source.setFilePath(std::string(DATA_PATH) + 
																										"mono.mp3"));
			CPPUNIT_ASSERT(mp3Source.hasData());
			CPPUNIT_ASSERT(mp3Source.getFilePath() == std::string(DATA_PATH) + 
										 "mono.mp3");
			CPPUNIT_ASSERT(mp3Source.getNumChannels() == 1);
			CPPUNIT_ASSERT(mp3Source.getRate() == 44100);

			/* Test a stereo mp3 */
			CPPUNIT_ASSERT_NO_THROW(mp3Source.setFilePath(std::string(DATA_PATH) + 
																										"stereo.mp3"));
			CPPUNIT_ASSERT(mp3Source.hasData());
			CPPUNIT_ASSERT(mp3Source.getFilePath() == std::string(DATA_PATH) + 
										 "stereo.mp3");
			CPPUNIT_ASSERT(mp3Source.getNumChannels() == 2);
			CPPUNIT_ASSERT(mp3Source.getRate() == 44100);
	 }

	 void Mp3SourceTests::testGetData()
	 {
			Mp3Source mp3Source;			
			CPPUNIT_ASSERT_THROW(mp3Source.getNextData(), Mp3SourceException);
			
			CPPUNIT_ASSERT_NO_THROW(mp3Source.setFilePath(std::string(DATA_PATH) + "mono.mp3"));
			CPPUNIT_ASSERT(mp3Source.hasData());
			
			while(mp3Source.hasData()) {				 
				 CPPUNIT_ASSERT_NO_THROW(mp3Source.getNextData());
			}

			CPPUNIT_ASSERT_THROW(mp3Source.getNextData(), Mp3SourceException);
	 }
}
