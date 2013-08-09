/*****************************************************************************/ 
/* Source.hh for BlasterBox Amplifier                                        */
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
#ifndef SOURCE_HH_
#define SOURCE_HH_

#include <array>
#include <vector>

namespace BlasterBox {

	 typedef std::vector<unsigned char> PCM16Data;

	 class Source 
	 {
	 public:			
			virtual bool hasData() const = 0;
			virtual const PCM16Data & getNextData() = 0;			
	 };

}

#endif /* SOURCE_HH_ */
