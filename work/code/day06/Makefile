.PHONY : clean hanno
hanno:hanno.o main.o
	gcc $~ -o $@
%.o:%.c
	gcc -c $~ -o $@


clean:
	rm -rf *.o hanno
