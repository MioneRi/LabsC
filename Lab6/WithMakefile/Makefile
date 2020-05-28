all: build run clean
NAME_PART = main

build:
	cd $(CURDIR)
	gcc -std=c11 -c StrokiLiba.c -o StrokiLiba.o
	ar rcs libStrokiLiba.a StrokiLiba.o
	gcc -std=c11 -c dynamicStructuresLiba.c -o dynamicStructuresLiba.o
	ar rcs libdynamicStructuresLiba.a dynamicStructuresLiba.o
	gcc -std=c11 -I "$(CURDIR)" -c "$(NAME_PART).c" -o "$(NAME_PART).o"
	gcc -std=c11 "$(NAME_PART).o" -L . -l StrokiLiba -o "$(NAME_PART).exe"
	gcc -std=c11 "$(NAME_PART).o" -L . -l dynamicStructuresLiba -o "$(NAME_PART).exe"

run:
	./$(NAME_PART)

clean:
	del *.exe
	del *.o
	del *.a