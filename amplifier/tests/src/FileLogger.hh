/*****************************************************************************/ 
/* FileLogger.hh for BlasterBox Server Tests                                 */
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
#ifndef FILELOGGER_HH_
#define FILELOGGER_HH_
#include "../../src/Logger.hh"
#include <fstream>

namespace BlasterBox {

	 class FileLogger : public Logger
	 {
	 public:
			FileLogger();
      ~FileLogger();
			virtual void log(const std::string & msg);

	 private:
			std::ofstream out;
	 };
}

#endif /* FILELOGGER_HH_ */
