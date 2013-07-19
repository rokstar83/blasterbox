CXX=g++
OPTS=-Wall -O2 -g -std=gnu++0x -pthread
SRC_DIR=src/
BIN_DIR=bin/

vpath %.cc ${SRC_DIR}
vpath %.hh ${SRC_DIR}
vpath %.o ${BIN_DIR}

SRC_FILES=main.cc 
#RemoteListenerTests.cc ../../src/RemoteSocket.cc ../../src/RemoteListener.cc \
#../../src/RemoteSocketException.cc MockCommandQueue.cc MockRemoteClient.cc \
#StdOutLogger.cc FileLogger.cc
#HDR_FILES=RemoteListenerTests.hh MockCommandQueue.hh MockRemoteClient.hh StdOutLogger.hh FileLogger.hh
OBJS=$(patsubst %.cc, $(BIN_DIR)%.o, $(SRC_FILES))
LDLIBS=
LDFLAGS=-lcppunit

.PHONY: all clean tests TAGS

all: blasterboxServerTests tests TAGS

TAGS: $(SRC_FILES) $(HDR_FILES)
	etags --members --declarations -l c++ $<

blasterboxServerTests: $(OBJS)
	$(CXX) $(OPTS) -o $(BIN_DIR)blasterboxServerTests $(OBJS) $(LDFLAGS)

$(BIN_DIR)%.o: %.cc
	echo $<
	$(CXX) $(OPTS) -c $< -o $@ $(LDFLAGS)

clean:
	rm $(BIN_DIR)/*.o $(BIN_DIR)/blasterboxServerTests
