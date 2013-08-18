/*****************************************************************************/ 
/* main.cc for Blasterbox Amplifier                                          */
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
#include <unistd.h>
#include <getopt.h>
#include <iostream>
#include <string>
#include "Amplifier.hh"
#include "AmplifierException.hh"
#include "ThreadGuard.hh"

static char short_opts[] = "c:l:h";
static struct option long_options[] = {
			{"conffile", required_argument, 0, 'c'},
			{"logfile", required_argument, 0, 'l'},
			{"help", no_argument, 0, 'h'},
			{0,0,0,0}
};

struct AmplifierOptions {
	 std::string confFile;
	 std::string logFile;
};

void usage();
AmplifierOptions parse_args(int argc, char *argv[]);

int main(int argc, char *argv[])
{
	 AmplifierOptions ampOpts = parse_args(argc, argv);

	 if(ampOpts.logFile == "" || ampOpts.confFile == "") {
			usage();
			return 1;
	 }

	 BlasterBox::Amplifier amp(ampOpts.confFile, ampOpts.logFile);
	 
	 try {
			amp.start();
	 } catch(BlasterBox::AmplifierException ex) {
			std::cerr << ex.what();
	 }
	 
	 return 0;
}

void usage()
{
	 std::cout << "blasterboxAmplifier options:" << std::endl;
	 std::cout << "\t-l, --logfile [path to log file]" << std::endl;
	 std::cout << "\t-c, --conffile [path to configuration file]" << std::endl;
	 std::cout << "\t-h, --help" << std::endl;
}

AmplifierOptions parse_args(int argc, char *argv[])
{
	 int opt_index = 0;
	 int c = getopt_long(argc, argv, short_opts, long_options, &opt_index);
	 AmplifierOptions retval;
	 
	 while(c != -1) {
			switch(c) {
				 case 'c':
						retval.confFile = optarg;
						break;
				 case 'l':
						retval.logFile = optarg;
						break;
				 default:
						break;
			}
			
			c = getopt_long(argc, argv, short_opts, long_options, &opt_index);
	 }
	 
	 return retval;
}

