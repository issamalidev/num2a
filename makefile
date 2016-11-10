override CFLAGS +=-Wall -Isrc $(OPTFLAGS)
LIBS=-ldl $(OPTLIBS)
PREFIX?=usr/local

SOURCES=$(wildcard src/**/*.c src/*.c)
OBJECTS=$(patsubst %.c,%.o,$(SOURCES))


TARGET=build/libnum2a.a
SO_TARGET=$(patsubst %.a,%.so,$(TARGET))

all: $(TARGET) $(SO_TARGET)

dev:CFLAGS= -g -Wall -Wextra -Isrc $(OPTFLAGS)
dev: all

$(TARGET): CFLAGS += -fpic
$(TARGET): build $(OBJECTS)
	ar rcs $@ $(OBJECTS)
	ranlib $@
$(SO_TARGET): $(TARGET) $(OBJECTS)
	$(CC) -shared -o $@ $(OBJECTS)

mingw: CFLAGS=-Wall -Isrc -D BUILD_DLL $(OPTFLAGS)
mingw: $(OBJECTS)
		$(CC) -shared -o build/num2a.dll $(OBJECTS) -Wl,--subsystem,windows,--out-implib,build/libnum2a.a

static: build/libnum2a.a
$(static):CFLAGS += -c
$(static): build $(OBJECTS)
	ar rcs $@ $(OBJECTS)
		
build:
	@mkdir -p build
	
install: all
	install -d $(DESTDIR)/$(PREFIX)/lib/
	install $(TARGET) $(DESTDIR)/$(PREFIX)/lib/
	