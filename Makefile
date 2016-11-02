all:
	gcc editor.c -o program `pkg-config --libs --cflags gtk+-2.0`
clean:
	rm -f program$
	rm -f plugin$ 
