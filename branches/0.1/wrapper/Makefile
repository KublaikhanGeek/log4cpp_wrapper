# command:
# $ make build_type=debug
# or
# $ make

TARGET_NAME = liblogger.so

SRC_PATH = .

CC = g++
STRIP = strip

ifeq ($(build_type), debug)
CFLAGS = -g -D_DEBUG
else
CFLAGS = -O2
endif

SRCS = $(wildcard $(SRC_PATH)/*.cpp)
OBJS = $(SRCS:.cpp=.o)

LIBS = /usr/local/lib/liblog4cpp.a -lpthread 

INCS = /usr/local/include

all: $(TARGET_NAME)

$(TARGET_NAME): $(OBJS)
	$(CC) -fpic -shared -o $(TARGET_NAME) $(OBJS) $(LIBS);
	@echo "Done: $(TARGET_NAME).";

%.o: %.cpp
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@;

clean:
	@set -e; \
	rm -f $(OBJS) $(TARGET_NAME); \
	echo "Clean up $(TARGET_NAME).";

strip:
	@set -e;
	$(STRIP) $(TARGET_NAME);
	@echo "stripped $(TARGET_NAME).";
	cp $(TARGET_NAME) ..;
