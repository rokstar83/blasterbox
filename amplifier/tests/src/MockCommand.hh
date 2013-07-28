/*****************************************************************************/ 
/* MockCommand.hh for BlasterBox Amplifier                                   */
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
#ifndef MOCKCOMMAND_HH_
#define MOCKCOMMAND_HH_

#include "../../src/RemoteCommand.hh"
#include <vector>

namespace BlasterBox {
	 class MockCommand : public RemoteCommand {
	 public:
			MockCommand(std::vector<unsigned char> cmdData);
			virtual std::string to_string();
	 private:
			std::vector<unsigned char> _cmdData;
	 };
}

#endif/* MOCKCOMMAND_HH_ */
