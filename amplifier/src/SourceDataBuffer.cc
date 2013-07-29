/*****************************************************************************/ 
/* SourceDataBuffer.cc                                                       */
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
#include "SourceDataBuffer.hh"

namespace BlasterBox {

	 SourceDataBuffer::SourceDataNode::SourceDataNode(SourceDataNode * next, 
																										std::chrono::miliseconds timestamp,
																										std::vector<unsigned char> data)
	 {
			_next = next;
			_timestamp = timestamp;
			_data = data;
	 }
	 
	 std::chrono::miliseconds SourceDataBuffer::SourceDataNode::getTimeStamp() const
	 {
			return _timestamp;
	 }

	 void SourceDataBuffer::SourceDataNode::setTimeStamp(std::chrono::miliseconds timestamp)
	 {
			_timestamp = timestamp;
	 }

	 std::vector<unsigned char> SourceDataBuffer::SourceDataNode::getData() const
	 {
			return _data;
	 }

	 void SourceDataBuffer::SourceDataNode::setData(std::vector<unsigned char> data) 
	 {
			_data = data;
	 }

	 SourceDataNode * SourceDataBuffer::SourceDataNode::getNext() const
	 {
			return _next;
	 }
	 
	 void SourceDataBuffer::SourceDataNode::setNext(SourceDataNode * next)
	 {
			_next = next;
	 }

	 SourceDataBuffer::SourceDataBuffer(int bufferSize)
	 {
			_bufferSize = bufferSize;
			_end = new SourceDataBuffer(NULL, std::chrono::miliseconds(0),
																	std::vector<unsigned char>());
			SourceDataNode * cur;
			int count = bufferSize-1;
			while(count-- != 1) {
				 cur = new SourceDataNode(cur, std::chrono::miliseconds(0),
																	std::vector<unsigned char>());				 
			}
			
			_begin = new SourceDataBuffer(cur, std::chrono::miliseconds(0),
																		std::vector<unsigned char>());
			_end.setNext(_begin);
	 }

	 SourceDataIterator::SourceDataIterator(SourceDataBuffer & buf) : _buf(buf)			
	 {
			pos = _buf._begin;
	 }

	 SourceDataIterator::SourceDatatIterator(const SourceDataIterator & a) : 
			_buf(a._buf), _pos(a._pos)
	 {
	 }

	 SourceDataIterator & SourceDataIterator::operator=(const SourceDataIterator & lhs)
	 {
			_buf = lhs._buf;
			_pos = lhs._pos;

			return *this;
	 }

	 SourceDataIterator & SourceDataIterator::operator++() 
	 {				
			pos = pos->getNext();
			return *this;
	 }

	 SourceDataNode & SourceDataIterator::operator*()
	 {
			return *pos;
	 }
}
