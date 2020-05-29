all: build run clean
NAME_PART = main

build:
	cd $(CURDIR)
	gcc -std=c99 -c dynamicStructuresLiba.c -o dynamicStructuresLiba.o
	ar rcs libdynamicStructuresLiba.a dynamicStructuresLiba.o
	gcc -std=c99 -I "$(CURDIR)" -c "$(NAME_PART).c" -o "$(NAME_PART).o"
	gcc -std=c99 "$(NAME_PART).o" -L . -l dynamicStructuresLiba -o "$(NAME_PART).exe"

run:
	./$(NAME_PART)

clean:
	del *.exe
	del *.o
	del *.a