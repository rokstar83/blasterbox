/*****************************************************************************/ 
/* main.cc for BlasterBox Amplifier Tests (Amplifier)                        */
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
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include "SexpOutputter.hh"

int main(int argc, char *argv[])
{
   CppUnit::TestResult controller;

   CppUnit::TestResultCollector result;
   controller.addListener(&result);

   CppUnit::TestRunner runner;
   runner.addTest(CppUnit::TestFactoryRegistry::getRegistry().makeTest());
   
   try {
      runner.run(controller);
      CppUnit::SexpOutputter outputter(&result, std::cout);
      outputter.write();
   } catch(...) {
   }
   
   return (result.wasSuccessful() ? 0 : 1);
}
