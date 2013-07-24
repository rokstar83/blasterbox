/*****************************************************************************/ 
/* RemoteListenerTest.cc for BlasterBox Server Tests                         */
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
#include "RemoteListenerTests.hh"
#include "../../src/RemoteListener.hh"
#include "MockCommandQueue.hh"
#include "MockRemoteClient.hh"
#include "StdOutLogger.hh"
#include "FileLogger.hh"
#include "../../src/RemoteCommandList.hh"
#include <thread>
#include <vector>
#include <string>

namespace BlasterBox {

	 class thread_guard {
			std::thread & _t;
			RemoteListener & _r;
	 public:
			explicit thread_guard(std::thread & t, RemoteListener & r) : _t(t), _r(r) {}
			~thread_guard() {if(_t.joinable()) { _r.stopListening(); _t.join(); } }
			thread_guard(thread_guard const &)=delete;
			thread_guard & operator=(thread_guard const &)=delete;
	 };
 
	 void RemoteListenerTests::setUp() { }

	 void RemoteListenerTests::tearDown() { }

	 void RemoteListenerTests::testConn() 
	 {
			MockCommandQueue mockQueue;
			StdOutLogger logger;
			RemoteListener listener(mockQueue, logger);
			MockRemoteClient client;

			std::thread listenerThread(&RemoteListener::listenLoop, 
																 std::ref(listener));
			thread_guard g(listenerThread, listener);

			// Spin until initialized
			while(!listener.isInitialized()) {}

			std::vector<MockRemoteClient> clients(MAX_REMOTE_CONNECTIONS);

			for(int x = 0; x < clients.size(); ++x) {				 
				 CPPUNIT_ASSERT_NO_THROW(clients[x].connect());
				 std::this_thread::sleep_for(std::chrono::milliseconds(1000));
				 CPPUNIT_ASSERT(listener.hasConnections());
				 CPPUNIT_ASSERT(listener.numConnections() == x+1);
			}
	 }

	 void RemoteListenerTests::testMultiConn()
	 {}
/*			MockCommandQueue mockQueue;
			StdOutLogger logger;
			RemoteListener listener(mockQueue, logger);
								
			std::thread listenerThread(&RemoteListener::listenLoop, 
																 std::ref(listener));
			thread_guard g(listenerThread, listener);
			
			while(!listener.isInitialized()) {}
*/
//			std::vector<MockRemoteClient> clients(MAX_REMOTE_CONNECTIONS);

//			for(int x = 0; x < MAX_REMOTE_CONNECTIONS - 1; ++x) {
//			MockRemoteClient cli;
//			CPPUNIT_ASSERT_NO_THROW(cli.connect());
//			CPPUNIT_ASSERT(listener.hasConnections());
//			CPPUNIT_ASSERT(listener.numConnections() == 1);
//			}
//	 }

/*			std::vector<unsigned char> msg(REMOTE_COMMAND_PREFIX_LEN + 
																		 sizeof(CommandType) + sizeof(SimpleCommand));

			for(int x = 0; x < REMOTE_COMMAND_PREFIX_LEN; ++x) {
				 msg[x] = REMOTE_COMMAND_PREFIX[x];
			}

			msg[REMOTE_COMMAND_PREFIX_LEN + 1] = (unsigned char)CommandType::SIMPLE;
			msg[REMOTE_COMMAND_PREFIX_LEN + 2] = (unsigned char)SimpleCommand::NOOP;

			CPPUNIT_ASSERT_NO_THROW(client1.send(msg.data(), msg.size()));

			int rc;
			unsigned char * msg = new
			CPPUNIT_ASSERT_NO_THROW(client1.recv(msg,));
			} */



/*	 void RemoteListenerTests::testHUP()
	 {
			MockCommandQueue mockQueue;
			StdOutLogger logger;
			RemoteListener listener(mockQueue, logger);
			MockRemoteClient client;

			std::shared_future<void> initialized = listener.initialized();

			std::thread listenerThread(&RemoteListener::listenLoop, std::ref(listener));
			thread_guard g(listenerThread);
			
			initialized.get();
			client.connect(); 
			} */
}
