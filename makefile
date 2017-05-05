OBJ = main.o wifiscan.o screen.o
APPNAME = wifi.a

$(APPNAME) : $(OBJ)
	gcc -o $(APPNAME) $(OBJ)
	
%.o : %.c
	gcc -c -o $@ $< -std=c99
	
clean :
	rm $(OBJ) $(APPNAME)

archive :
	tar cf wifi.tar *.c *.h makefile README.md
