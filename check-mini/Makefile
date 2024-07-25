ifndef OS # linux
EXECUTABLE_EXTENSION=.exe
LIBRARY_EXTENSION=.a
RM=rm -f $(1)
else ifeq ($(OS), Windows_NT) # windows
EXECUTABLE_EXTENSION=
LIBRARY_EXTENSION=.lib
RM=if exist $(1) del $(1)
else
$(error os not supported)
endif


.PHONY: default
default:
	@echo check-mini is a header only library

test$(EXECUTABLE_EXTENSION): test.o ../test-mini/libtest-mini$(LIBRARY_EXTENSION)
	gcc -Wl,--wrap=malloc,--wrap=free,--wrap=main -o test$(EXECUTABLE_EXTENSION) test.o -L../test-mini/ -ltest-mini

test.o: test.c check_mini.h
	gcc -c test.c -I../test-mini/

#******************************************************************************

release: test$(EXECUTABLE_EXTENSION)
	./test$(EXECUTABLE_EXTENSION)

.PHONY: clean
clean:
	$(call RM,test.o)
	$(call RM,test)
	$(call RM,test.exe)