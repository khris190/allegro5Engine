# Makefile for Allegro5 programs
####################

PROGRAM_NAME=program
SOURCES=main.cpp


####################
OUTPUT_DIR=bin
LINUX_GCC=g++
LINUX_CFLAGS=-O2 -Wall
WINDOWS_GCC=x86_64-w64-mingw32-g++
WINDOWS_CFLAGS=-O2 -Wall
#ALLEGRO5_LINUX=`pkg-config --cflags --libs allegro-5 allegro_ttf-5 allegro_primitives-5 allegro_physfs-5 allegro_memfile-5 allegro_main-5 allegro_image-5 allegro_font-5 allegro_dialog-5 allegro_color-5 allegro_audio-5 allegro_acodec-5`
ALLEGRO5_LINUX=`pkg-config --cflags --libs allegro-5 allegro_ttf-5 allegro_primitives-5 allegro_physfs-5 allegro_memfile-5 allegro_main-5 allegro_image-5 allegro_font-5 allegro_color-5 allegro_audio-5 allegro_acodec-5`
ALLEGRO5_WINDOWS=`pkg-config --cflags --libs allegro-5 allegro_ttf-5 allegro_primitives-5 allegro_physfs-5 allegro_memfile-5 allegro_main-5 allegro_image-5 allegro_font-5 allegro_color-5 allegro_audio-5 allegro_acodec-5`
#export PKG_CONFIG_PATH=/usr/x86_64-w64-mingw32/lib/pkgconfig/
####################

.PHONY: all run clean help linux windows

all: linux

help:
	@echo "##### HELP #####"
	@echo "make all - build for linux and windows"
	@echo "make clean - clean up"
	@echo "make linux - build for linux only"
	@echo "make windows - build for windows only"
	@echo "make help - print this help"
	@echo "################"
linux:
	mkdir -p $(OUTPUT_DIR)/linux/
	$(LINUX_GCC) $(LINUX_CFLAGS) -o $(OUTPUT_DIR)/linux/$(PROGRAM_NAME) $(SOURCES) $(ALLEGRO5_LINUX)
	$(OUTPUT_DIR)/linux/$(PROGRAM_NAME)

lin:
	mkdir -p $(OUTPUT_DIR)/linux/
	$(LINUX_GCC) $(LINUX_CFLAGS) -v -o $(OUTPUT_DIR)/linux/$(PROGRAM_NAME) $(SOURCES) $(ALLEGRO5_LINUX)
	$(OUTPUT_DIR)/linux/$(PROGRAM_NAME)

windows:
	mkdir -p $(OUTPUT_DIR)/windows/
	$(WINDOWS_GCC) $(WINDOWS_CFLAGS) -o $(OUTPUT_DIR)/windows/$(PROGRAM_NAME).exe $(SOURCES) $(ALLEGRO5_WINDOWS)

win:
	mkdir -p $(OUTPUT_DIR)/windows/
	$(WINDOWS_GCC) $(WINDOWS_CFLAGS) -v -o $(OUTPUT_DIR)/windows/$(PROGRAM_NAME).exe $(SOURCES) $(ALLEGRO5_WINDOWS)

run:
	$(OUTPUT_DIR)/linux/$(PROGRAM_NAME)

clean: