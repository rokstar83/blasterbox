CXX=g++
OPTS=-Wall -O0 -g -std=gnu++0x -pthread -DUNIT_TESTING
SRC_DIR=src/
BIN_DIR=bin/

vpath %.cc ${SRC_DIR}
vpath %.hh ${SRC_DIR}
vpath %.o ${BIN_DIR}

SRC_FILES=main.cc RemoteListenerTests.cc ../../src/RemoteListener.cc MockCommandQueue.cc \
					MockRemoteClient.cc StdOutLogger.cc FileLogger.cc ../../src/RemoteListenerException.cc \
					MockCommand.cc ../../src/RemoteCommandQueue.cc ../../src/Mp3Source.cc Mp3SourceTests.cc \
					.././src/Mp3SourceException.cc

HDR_FILES=RemoteListenerTests.hh MockCommandQueue.hh MockRemoteClient.hh StdOutLogger.hh \
					FileLogger.hh ../../src/RemoteCommand.hh MockCommand.hh ../../src/RemoteCommandQueue.hh \
					../../src/Mp3Source.hh ../../src/Source.hh Mp3SourceTests.hh \
					../../src/Mp3SourceException.hh

OBJS=$(patsubst %.cc, $(BIN_DIR)%.o, $(SRC_FILES))
LDLIBS=
LDFLAGS=-lcppunit -lmpg123

.PHONY: all clean tests TAGS

all: blasterboxServerTests TAGS

TAGS: $(SRC_FILES) $(HDR_FILES)
	etags --members --declarations -l c++ $<

blasterboxServerTests: $(OBJS)
	$(CXX) $(OPTS) -o $(BIN_DIR)blasterboxAmplifierTests $(OBJS) $(LDFLAGS)

$(BIN_DIR)%.o: %.cc
	echo $<
	$(CXX) $(OPTS) -c $< -o $@ $(LDFLAGS)

clean:
	rm $(BIN_DIR)/*.o $(BIN_DIR)/blasterboxAmplifierTests
