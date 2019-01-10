CC = g++
CFLAGS = -c -Wall -g
PROG = turba2d

SRCS = main2d.cpp crowdsRVO2.cpp blocks.cpp
OBJECTS=$(SRCS:.cpp=.o)
HEADERS=$(SRCS:.cpp=.h)
INCLUDES = -I./include

ifeq ($(shell uname),Darwin)
	LIBS = -framework Cocoa -framework OpenGL -lglfw -framework IOKit
else
	LIBS = -lglfw -lGL -ldl -L./lib -lglad -lRVO
endif

all: $(PROG)

$(PROG):	$(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) $(LIBS) -o $@

.cpp.o: $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@

clean:
	rm -f $(PROG) *.o *~ shaders/*~

