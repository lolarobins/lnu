CC:=gcc
OUTPUT_DIR:=./bin/
CFLAGS:=-g -Wall -O2

target: basename dirname tty uname

basename:
	@-mkdir -p $(OUTPUT_DIR)
	$(CC) $(CFLAGS) basename.c -o $(OUTPUT_DIR)basename

dirname:
	@-mkdir -p $(OUTPUT_DIR)
	$(CC) $(CFLAGS) dirname.c -o $(OUTPUT_DIR)dirname

tty:
	@-mkdir -p $(OUTPUT_DIR)
	$(CC) $(CFLAGS) tty.c -o $(OUTPUT_DIR)tty

uname:
	@-mkdir -p $(OUTPUT_DIR)
	$(CC) $(CFLAGS) uname.c -o $(OUTPUT_DIR)uname
