include Makefile.arch

#
# Pre-requisite
#
.PHONY: check-core-dir

#
# stuff to make
#
SOURCES=$(wildcard *.cc)
OBJECTS=$(SOURCES:.cc=.o)
LIB=coreutil.so

#
# how to make it
#

$(LIB): $(OBJECTS)
	$(LD) $(LDFLAGS) $(SOFLAGS) $(OBJECTS) $(ROOTLIBS) -lTMVA -lEG -lGenVector -lXMLIO -lMLP -lTreePlayer -o $@
	ln -sf $@ lib$@

%.o: %.cc check-core-dir
	$(CXX) -Wunused-variable $(CXXFLAGS) -I$(COREDIR) -c $< -o $@

check-core-dir:
ifndef COREDIR
    $(error COREDIR is not set. Please export COREDIR=/abspath/to/CORE)
endif


#
# target to build
# likelihood id library
#

all: $(LIB)
clean:
	rm -f *.o \
	rm -f *.d \
	rm -f *.so \
