.PHONY: all
all: build/libvector.a

build/libvector.a: build/vector.o
	ar rcs $@ $<

build/vector.o: src/vector.c include/vector.h
	gcc -Wall -c -I include $< -o $@

.PHONY: clean
clean:
	rm build/vector.o build/libvector.a