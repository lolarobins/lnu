TARGET:=dirname
CC:=gcc
OUTPUT_DIR:=../bin/
CFLAGS:=-g -Wall -O2

target: dirname.c
	@-mkdir -p $(OUTPUT_DIR)
	$(CC) $(CFLAGS) dirname.c -o $(OUTPUT_DIR)$(TARGET)
