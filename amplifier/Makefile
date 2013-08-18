CXX=g++
OPTS=-Wall -O2 -g -std=gnu++0x -pthread
SRC_DIR=src/
BIN_DIR=bin/

SRC_FILES=main.cc Amplifier.cc AmplifierException.cc
HDR_FILES=Amplifier.hh AmplifierException.hh
OBJS=$(patsubst %.cc, $(BIN_DIR)%.o, $(SRC_FILES))
LDLIBS=
LDFLAGS=

.PHONY: clean tests all

all: blasterboxAmplifier tests TAGS

TAGS: $(patsubst %, $(SRC_DIR)%, $(SRC_FILES) $(HDR_FILES))
	etags --members --declarations -l c++ $<

blasterboxAmplifier: $(OBJS)
	echo $(OBJS)
	$(CXX) $(OPTS) -o $(BIN_DIR)blasterboxAmplifier $(OBJS) $(LDLIBS)

$(BIN_DIR)%.o: $(SRC_DIR)%.cc
	echo $<
	$(CXX) $(OPTS) -c $< -o $@ $(LDFLAGS)

tests:
	$(MAKE) -C tests

clean:
	rm -f $(BIN_DIR)*.o $(BIN_DIR)/blasterboxAmplifier
	$(MAKE) -C tests clean
