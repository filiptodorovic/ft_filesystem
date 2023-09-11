#!/bin/bash
clang fuse.c -o fs `pkg-config fuse --cflags --libs` -DFUSE_USE_VERSION=26 -D_FILE_OFFSET_BITS=64
