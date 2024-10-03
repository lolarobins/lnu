TARGET:=basename
CC:=gcc
OUTPUT_DIR:=../bin/
CFLAGS:=-g -Wall -O2

target: basename.c
	@-mkdir -p $(OUTPUT_DIR)
	$(CC) $(CFLAGS) basename.c -o $(OUTPUT_DIR)$(TARGET)
