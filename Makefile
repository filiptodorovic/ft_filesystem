CC      = /usr/bin/gcc
SHELL   = /bin/zsh
CFLAGS  = -g $(PKGFLAGS) $(FUSEFLAGS)
PKGFLAGS = `pkg-config fuse --cflags --libs`
FUSEFLAGS = -DFUSE_USE_VERSION=26 -D_FILE_OFFSET_BITS=64
BIN_DIR = bin
SRC     = fuse.c
TARGET  = $(BIN_DIR)/ftfs

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(TARGET)

.PHONY: all clean