/*****************************************************************************/ 
/* Mp3Source.cc for BlasterBox Amplifier                                     */
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
#include "Mp3Source.hh"
#include "Mp3SourceException.hh"
#include <fstream>
#include <algorithm>
#include <mpg123.h>

namespace BlasterBox {

	 Mp3Source::Mp3Source() : _mh(NULL), _id3v1(NULL), _id3v2(NULL), 
														_hasData(false)
	 {
			int err = mpg123_init();
			if(err != MPG123_OK) {
				 throw Mp3SourceException(std::string("Unable to initialize mpg123. ") + 
																	mpg123_plain_strerror(err));
			}

			_mh = mpg123_new(NULL, &err);
			if(_mh == NULL) {
				 mpg123_exit();
				 throw Mp3SourceException(std::string("Error while creating mpg123"
																							" handle. ") +
																	mpg123_plain_strerror(err));
			}			
	 }

	 Mp3Source::~Mp3Source() 
	 {
			if(_mh != nullptr) {
				 mpg123_close(_mh);
				 mpg123_delete(_mh);
			}

			mpg123_exit();
	 }

	 bool Mp3Source::hasData() const
	 {
			return _hasData;
	 }

	 const PCM16Data & Mp3Source::getNextData()
	 {
			if(!_hasData) {
				 throw Mp3SourceException(std::string("No data left to get."));
			}

			size_t done;
			int err = mpg123_read(_mh, _data.data(), _bufferLen, &done);

			if(err == MPG123_ERR) {
				 throw Mp3SourceException(std::string("Error while decoding mp3 '") + 
																	_filePath + std::string("'. ") + 
																	std::string(mpg123_strerror(_mh)));
			}
			
			if(err == MPG123_DONE) {
				 _hasData = false;
			}

			return _data;
	 }

	 void Mp3Source::setFilePath(const std::string & filePath) 
	 {
			{
				 std::ifstream in(filePath);
				 if(!in) {
						throw Mp3SourceException("Path '" + filePath + "' does not exist.");
				 }
			}

			if(mpg123_open(_mh, filePath.c_str()) != MPG123_OK || 
				 mpg123_getformat(_mh, &_rate, &_channels, &_encoding)) {
				 mpg123_close(_mh);
				 throw Mp3SourceException("Problem with opening mp3. " + 
																	 std::string(mpg123_strerror(_mh)));
			}
			
			if(_encoding != MPG123_ENC_SIGNED_16 && _encoding != MPG123_ENC_FLOAT_32) {
				 mpg123_close(_mh);
				 throw Mp3SourceException("Unknown encoding format.");
			}

			mpg123_scan(_mh);
			_metaType = mpg123_meta_check(_mh);
			if(mpg123_id3(_mh, &_id3v1, &_id3v2) != MPG123_OK) {
				 mpg123_close(_mh);
				 throw Mp3SourceException(std::string("Unable to get id3 information "
																							"from '") + mpg123_strerror(_mh));
			}

			_filePath = filePath;
			_bufferLen = mpg123_outblock(_mh);
			_data.resize(_bufferLen);

			_hasData = true;
	 }

	 const std::string & Mp3Source::getFilePath() const
	 {
			return _filePath;
	 }

	 int Mp3Source::getNumChannels() const
	 {
			if(_channels & MPG123_MONO) 
				 return 1;
			else if(_channels & MPG123_STEREO)
				 return 2;
			else 
				 return 0;
	 }

	 long Mp3Source::getRate() const
	 {
			return _rate;
	 }
}
