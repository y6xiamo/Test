.PHONY:clean
myls:myls.o
	gcc -g $^ -o $@
%.o:%.c
	gcc -c -g $^ -o $@

clean:
	rm -rf *.o myls
