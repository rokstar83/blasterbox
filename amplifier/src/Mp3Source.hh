/*****************************************************************************/ 
/* Mp3Source.hh for BlasterBox Amplifier                                     */
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
#ifndef MP3SOURCE_HH_
#define MP3SOURCE_HH_
#include "Source.hh"
#include <string>
#include <mpg123.h>

namespace BlasterBox {

	 class Mp3Source : public Source
	 {
	 public:
			Mp3Source();
			~Mp3Source();

			virtual bool hasData() const;
			virtual const PCM16Data & getNextData();

			void setFilePath(const std::string & filePath);
			const std::string & getFilePath() const;

		  int getNumChannels() const;
			long getRate() const;

	 private:
			std::string _filePath;
			mpg123_handle * _mh;
			int _channels;
			int _encoding;
			long _rate;
			size_t _bufferLen;
			mpg123_id3v1 * _id3v1;
			mpg123_id3v2 * _id3v2;
			PCM16Data _data;
			int _metaType;
			bool _hasData;			
	 };
}

#endif /* MP3SOURCE_HH_ */
