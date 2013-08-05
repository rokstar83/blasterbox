/*****************************************************************************/ 
/* SourceDataBuffer.hh                                                       */
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
#ifndef SOURCEDATABUFFER_HH_
#define SOURCEDATABUFFER_HH_

#include "Constants.hh"
#include <chrono>

namespace BlasterBox {
	 class SourceDataNode;	 

	 class SourceDataBuffer 
	 {
			class SourceDataNode {
			public:
				 SourceDataNode(SourceDataNode * next, std::chrono::miliseconds,
												std::vector<unsigned char>);

				 std::chrono::miliseconds getTimeStamp();
				 void setTimeStamp(std::chrono::miliseconds timestamp);
				 std::vector<unsigned char> getData();
				 void setData(std::vector<unsigned char> data);
				 SourceDataNode * getNext() const;
				 void setNext(SourceDataNode * next);				 

			private:
				 SourceDataNode * _next;
				 std::chrono::miliseconds _timestamp;
				 std::vector<unsigned char> _data;
			};

	 public:
			SourceDataBuffer(int bufferSize = MAX_SOURCE_BUFFER_SIZE);

			SourceDataIterator begin() const;
			SourceDataIterator end() const;

			friend class SourceDataIterator;
	 private:
			int _bufferSize;
			SourceDataNode * _begin;
			SourceDataNode * _end;
	 };

	 class SourceDataIterator {
	 public:
			SourceDataIterator(SourceDataBuffer & buf);
			SourceDataIterator(const SourceDataIterator & a);
			
			SourceDataIterator & operator=(const SourceDataIterator & lhs);
			bool operator==(const SourceDataIterator & lhs) const;
			bool operator!=(const SourceDataIterator & lhs) const;
			SourceDataIterator & operator++();
			SourceDataNode & operator*();
			
	 private:
			SourceDataBuffer & _buf;
			SourceDataNode * pos;
	 };
}

#endif /* SOURCEDATABUFFER_HH_ */
