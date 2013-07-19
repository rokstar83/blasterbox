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
#include <iostream>
#include <getopt.h>

static char short_opts[] = "c:l:";
static struct option long_options[] = 
{
	 {"conf", required_argument, 0, 'c'},
	 {"logfile", required_argument, 0, 'l'},
	 {0,0,0,0}
};

int main(int argc, char *argv[])
{			
	 return 0;
}

void usage()
{
}

void parse_args(int argc, char *argv[])
{
}
