CXX=g++
OPTS=-Wall -O2 -g
SRC_DIR=src/
BIN_DIR=bin/

vpath %.cc $(SRC_DIR)
vpath %.hh $(SRC_DIR)
vpath %.o $(BIN_DIR)

SRC_FILES=main.cc
HDR_FILES=
OBJS=$(patsubst %.cc, $(BIN_DIR)%.o, $(SRC_FILES))
LDLIBS=
LDFLAGS=

.PHONY: clean tests all

all: blasterboxAmplifier tests TAGS

TAGS: $(SRC_FILES) $(HDR_FILES)
	etags --members --declarations -l c++ $<

blasterboxAmplifier: $(OBJS)
	echo $(OBJS)
	$(CXX) $(OPTS) -o $(BIN_DIR)blasterboxAmplifier $(OBJS) $(LDLIBS)

$(BIN_DIR)%.o: %.cc
	echo $<
	$(CXX) $(OPTS) -c $< -o $@ $(LDFLAGS)

tests:
	$(MAKE) -C tests

clean:
	rm -f $(BIN_DIR)*.o $(BIN_DIR)/blasterboxAmplifier
	$(MAKE) -C tests clean
