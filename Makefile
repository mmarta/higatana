## General Flags
PROJECT=Higatana - Galaxy Gyro Fighter
GAME=higatana
MCU=atmega644
TARGET=$(GAME).elf
CC=avr-gcc
INFO=game.properties
UZEBIN_DIR=../uzebox/tools/packrom/
UZEM_DIR=../uzebox/tools/uzem/
GCONVERT_DIR=../uzebox/tools/gconvert/

## Kernel settings
KERNEL_DIR = ../uzebox/kernel
KERNEL_OPTIONS = -DVIDEO_MODE=3 -DINTRO_LOGO=0 -DRESOLUTION_EXT=1 -DVRAM_TILES_H=32 -DMIXER=1
KERNEL_OPTIONS += -DSCROLLING=0 -DTRANSLUCENT_COLOR=0x00 -DRAM_TILES_COUNT=32 -DMAX_SPRITES=20 -DTRUE_RANDOM_GEN=1

## Options common to compile, link and assembly rules
COMMON = -mmcu=$(MCU)

## Compile options common for all C compilation units.
CFLAGS = $(COMMON)
CFLAGS += -Wall -gdwarf-2 -std=gnu99 -DF_CPU=28636360UL -Os -fsigned-char -ffunction-sections -fno-inline
CFLAGS += -MD -MP -MT $(*F).o -MF dep/$(@F).d
CFLAGS += $(KERNEL_OPTIONS)


## Assembly specific flags
ASMFLAGS = $(COMMON)
ASMFLAGS += $(CFLAGS)
ASMFLAGS += -x assembler-with-cpp -Wa,-gdwarf2

## Linker flags
LDFLAGS = $(COMMON)
LDFLAGS += -Wl,-Map=$(GAME).map
LDFLAGS += -Wl,-gc-sections


## Intel Hex file production flags
HEX_FLASH_FLAGS = -R .eeprom

HEX_EEPROM_FLAGS = -j .eeprom
HEX_EEPROM_FLAGS += --set-section-flags=.eeprom="alloc,load"
HEX_EEPROM_FLAGS += --change-section-lma .eeprom=0 --no-change-warnings


## Objects that must be built in order to link
OBJECTS = uzeboxVideoEngineCore.o uzeboxCore.o uzeboxSoundEngine.o uzeboxSoundEngineCore.o uzeboxVideoEngine.o
OBJECTS += graphics.o system.o gamesys.o background.o bullet.o player.o invader.o collision.o main.o

## Objects explicitly added by the user
LINKONLYOBJECTS =

## Include Directories
INCLUDES = -I"$(KERNEL_DIR)"

## Build
all: $(TARGET) $(GAME).hex $(GAME).uze size clean

## Compile Kernel files
uzeboxVideoEngineCore.o: $(KERNEL_DIR)/uzeboxVideoEngineCore.s
	$(CC) $(INCLUDES) $(ASMFLAGS) -c  $<

uzeboxSoundEngineCore.o: $(KERNEL_DIR)/uzeboxSoundEngineCore.s
	$(CC) $(INCLUDES) $(ASMFLAGS) -c  $<

uzeboxCore.o: $(KERNEL_DIR)/uzeboxCore.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

uzeboxSoundEngine.o: $(KERNEL_DIR)/uzeboxSoundEngine.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

uzeboxVideoEngine.o: $(KERNEL_DIR)/uzeboxVideoEngine.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

## Compile game sources
system.o: src/system.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $< -o system.o

graphics.o: src/graphics.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $< -o graphics.o

gamesys.o: src/gamesys.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $< -o gamesys.o

background.o: src/background.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $< -o background.o

bullet.o: src/bullet.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $< -o bullet.o

player.o: src/player.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $< -o player.o

invader.o: src/invader.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $< -o invader.o

collision.o: src/collision.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $< -o collision.o

main.o: src/main.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $< -o main.o

##Link
$(TARGET): $(OBJECTS)
	 $(CC) $(LDFLAGS) $(OBJECTS) $(LINKONLYOBJECTS) $(LIBDIRS) $(LIBS) -o $(TARGET)

%.hex: $(TARGET)
	avr-objcopy -O ihex $(HEX_FLASH_FLAGS)  $< $@

%.uze: $(TARGET)
	$(UZEBIN_DIR)packrom $(GAME).hex $(GAME).uze $(INFO)

UNAME := $(shell sh -c 'uname -s 2>/dev/null || echo not')
AVRSIZEFLAGS := -A ${TARGET}
ifneq (,$(findstring MINGW,$(UNAME)))
AVRSIZEFLAGS := -C --mcu=${MCU} ${TARGET}
endif

size: ${TARGET}
	@echo
	@avr-size ${AVRSIZEFLAGS}

## Clean target
.PHONY: clean
clean:
	-rm -rf $(OBJECTS) $(GAME).hex $(GAME).elf $(GAME).map dep/*
	-rm -r dep

gfx:
	$(GCONVERT_DIR)gconvert gfxdata/gfx-tiles.xml
	$(GCONVERT_DIR)gconvert gfxdata/gfx-sprite-tiles.xml

test:
	$(UZEM_DIR)uzem $(GAME).uze

testfull:
	$(UZEM_DIR)uzem $(GAME).uze -f

## Other dependencies
-include $(shell mkdir dep 2>/dev/null) $(wildcard dep/*)
