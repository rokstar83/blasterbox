CXX=g++
OPTS=-Wall -O0 -g -std=gnu++0x -pthread

SRC_DIR=src/
BIN_DIR=bin/
TEST_DIR=../../src/
TEST_BIN_DIR=../../bin/
MOCK_DIR=../mocks/
MOCK_BIN_DIR=../mocks/

SRC_FILES=main.cc Mp3SourceTests.cc 
TEST_SRC_FILES=Mp3Source.cc Mp3SourceException.cc
MOCK_SRC_FILES=

HDR_FILES=Mp3SourceTests.hh 
TEST_HDR_FILES=Mp3Source.hh Mp3SourceException.hh
MOCK_HDR_FILES=

OBJS=$(patsubst %.cc, $(BIN_DIR)%.o, $(SRC_FILES))
TEST_OBJS=$(patsubst %.cc, $(TEST_BIN_DIR)%.o, $(TEST_SRC_FILES))
MOCK_OBJS=$(patsubst %.cc, $(MOCK_BIN_DIR)%.o, $(MOCK_SRC_FILES))

LDLIBS=
LDFLAGS=-lcppunit -lmpg123

.PHONY: all clean TAGS

all: Mp3SourceTests TAGS

TAGS: $(patsubst %, $(SRC_DIR)%, $(SRC_FILES) $(HDR_FILES)) \
			$(patsubst %, $(TEST_DIR)%, $(TEST_SRC_FILES) $(TEST_HDR_FILES)) \
			$(patsubst %, $(MOCK_DIR)%, $(MOCK_SRC_FILES) $(MOCK_HDR_FILES))
	etags --members --declarations -l c++ $<

Mp3SourceTests: $(OBJS) $(TEST_OBJS) $(MOCK_OBJS)
	$(CXX) $(OPTS) -o $(BIN_DIR)RemoteListenerTests \
				 $(OBJS) $(TEST_OBJS) $(MOCK_OBJS) $(LDFLAGS)
$(BIN_DIR)%.o: $(SRC_DIR)%.cc
	echo $<
	$(CXX) $(OPTS) -c $< -o $@ $(LDFLAGS)

$(TEST_BIN_DIR)%.o: $(TEST_DIR)%.cc
	echo $<
	$(CXX) $(OPTS) -c $< -o $@ $(LDFLAGS)

$(MOCK_BIN_DIR)%.o: $(MOCK_DIR)%.cc
	echo $<
	$(CXX) $(OPTS) -c $< -o $@ $(LDFLAGS)

clean:
	rm $(BIN_DIR)/*.o $(BIN_DIR)/Mp3SourceTests
