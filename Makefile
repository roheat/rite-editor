all:
	gcc editor.c -o editor `pkg-config --libs --cflags gtk+-2.0`
