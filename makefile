CC=/usr/bin/g++
LD=/usr/bin/g++

INCLUDES=-I$(CURDIR)
WARNINGS=-Wall
DEBUG=-g
CFLAGS=-c -fPIC  -D__USE_MISC
LDOPT=

TARGET=dataobject
SOURCES=$(shell echo *.cpp)
HEADERS=$(shell echo *.h)
OBJECTS=$(SOURCES:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(LD) $(LDOPT) -o $(TARGET) $(OBJECTS)

$(OBJECTS): $(SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) $(WARNINGS) $(DEBUG) $(INCLUDES) $(SOURCES)

clean: 
	rm $(OBJECTS) $(TARGET)
