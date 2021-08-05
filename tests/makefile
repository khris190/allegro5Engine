# Makefile for Allegro5 programs
####################

PROGRAM_NAME=test
SOURCES=maintest.cpp

OBIECTNAME=tests.o
WINLIBNAME=libtests.dll

LINLIBNAME=libtests.so

####################
OUTPUT_DIR=bin
LINUX_GCC=g++
LINUX_CFLAGS=-O2 -Wall

WINDOWS_GCC64=x86_64-w64-mingw32-g++
WINDOWS_GCC32=i686-w64-mingw32-g++

WINDOWS_CFLAGS=-DWINDOWS -O2 -Wall

ENDFLAGS=-ldl -lstdc++fs

#ALLEGRO5_LINUX=`pkg-config --cflags --libs allegro-5 allegro_ttf-5 allegro_primitives-5 allegro_physfs-5 allegro_memfile-5 allegro_main-5 allegro_image-5 allegro_font-5 allegro_dialog-5 allegro_color-5 allegro_audio-5 allegro_acodec-5`
ALLEGRO5_LINUX=`pkg-config --cflags --libs allegro-5 allegro_ttf-5 allegro_primitives-5 allegro_physfs-5 allegro_memfile-5 allegro_main-5 allegro_image-5 allegro_font-5 allegro_color-5 allegro_audio-5 allegro_acodec-5`
ALLEGRO5_WINDOWS=`pkg-config --cflags --libs allegro-5 allegro_ttf-5 allegro_primitives-5 allegro_physfs-5 allegro_memfile-5 allegro_main-5 allegro_image-5 allegro_font-5 allegro_color-5 allegro_audio-5 allegro_acodec-5`
export LDFLAGS="$LDFLAGS -ldl"
####################

.PHONY: all run clean help linux win32 win64

all: linux

help:
	@echo "##### HELP #####"
	@echo "make all - build for linux and windows"
	@echo "make clean - clean up"
	@echo "make linux - build for linux only"
	@echo "make windows32 - build for windows 32 only"
	@echo "make windows64 - build for windows 64 only"
	@echo "make help - print this help"
	@echo "################"
linux:

	mkdir -p $(OUTPUT_DIR)/linux/

	$(LINUX_GCC) -c -Wall -Werror -fpic tests.cpp

	$(LINUX_GCC) -shared -o $(OUTPUT_DIR)/linux/$(LINLIBNAME) $(OBIECTNAME)

	rm $(OBIECTNAME)

	$(LINUX_GCC) $(LINUX_CFLAGS) -o $(OUTPUT_DIR)/linux/$(PROGRAM_NAME) $(SOURCES) $(ENDFLAGS)

win32:

	mkdir -p $(OUTPUT_DIR)/winX86/

	$(WINDOWS_GCC32) -c -Wall -Werror -fpic tests.cpp

	$(WINDOWS_GCC32) -shared -o $(OUTPUT_DIR)/winX86/$(WINLIBNAME) $(OBIECTNAME)

	rm $(OBIECTNAME)

	$(WINDOWS_GCC32) $(WINDOWS_CFLAGS) -o $(OUTPUT_DIR)/winX86/$(PROGRAM_NAME).exe $(SOURCES) $(ENDFLAGS)

win64:

	mkdir -p $(OUTPUT_DIR)/winX64/

	$(WINDOWS_GCC64) -c -Wall -Werror -fpic tests.cpp

	$(WINDOWS_GCC64) -shared -o $(OUTPUT_DIR)/winX64/$(WINLIBNAME) $(OBIECTNAME)

	rm $(OBIECTNAME)

	$(WINDOWS_GCC64) $(WINDOWS_CFLAGS) -o $(OUTPUT_DIR)/winX64/$(PROGRAM_NAME).exe $(SOURCES) $(ENDFLAGS)


run:
	$(OUTPUT_DIR)/linux/$(PROGRAM_NAME)

clean: