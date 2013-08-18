CXX=g++
OPTS=-Wall -O0 -g -std=gnu++0x -pthread
SRC_DIR=src/
BIN_DIR=bin/

vpath %.cc ${SRC_DIR}
vpath %.hh ${SRC_DIR}
vpath %.o ${BIN_DIR}

SRC_FILES=main.cc Mp3SourceTests.cc ../../src/Mp3Source.cc \
					../../src/Mp3SourceException.cc
HDR_FILES=Mp3SourceTests.hh ../../src/Mp3Source.hh \
					../../src/Mp3SourceException.hh

OBJS=$(patsubst %.cc, $(BIN_DIR)%.o, $(SRC_FILES))
LDLIBS=
LDFLAGS=-lcppunit -lmpg123

.PHONY: all clean tests TAGS

all: Mp3SourceTests TAGS

TAGS: $(SRC_FILES) $(HDR_FILES)
	etags --members --declarations -l c++ $<

Mp3SourceTests: $(OBJS)
	$(CXX) $(OPTS) -o $(BIN_DIR)Mp3SourceTests $(OBJS) $(LDFLAGS)

$(BIN_DIR)%.o: %.cc
	echo $<
	$(CXX) $(OPTS) -c $< -o $@ $(LDFLAGS)

clean:
	rm $(BIN_DIR)/*.o $(BIN_DIR)/Mp3SourceTests
