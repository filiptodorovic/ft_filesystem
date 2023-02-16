#!/bin/bash
gcc fuse.c -o fs `pkg-config fuse --cflags --libs` -DFUSE_USE_VERSION=26
