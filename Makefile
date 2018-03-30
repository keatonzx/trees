all: lab8 trees

ds: ds/lib/libds.a

ds/lib/libds.a:
	$(MAKE) -C ds
        
trees: lab8.c
	gcc lab8.c -o trees

clean:
	@rm -f *.o eval
	$(MAKE) -C ./ds clean
	
cleanall: clean
	$(MAKE) -C ./ds cleanall