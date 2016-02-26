# define the C compiler to use
CC = gcc

# define any compile-time flags
CFLAGS = -Wall -g 

# define any directories containing header files other than /usr/include
#
INCLUDES = -I/usr/include/libxml2  -I../inc

# define any libraries to link into executable:
#   if I want to link in libraries (libx.so or libx.a) I use the -llibname 
#   option, something like (this will link in libmylib.so and libm.so:
LIBS = -lxml2

INFODIR = Info
DIR = src
# define the C source files
SRCS1 = src/savetofile.c src/features.c src/createInfo.c

SRCS2 = src/arfile.c src/analyseinfo.c

# define the C object files 
#
# This uses Suffix Replacement within a macro:
#   $(name:string1=string2)
#         For each word in 'name' replace 'string1' with 'string2'
# Below we are replacing the suffix .c of all words in the macro SRCS
# with the .o suffix
#
OBJS1 = $(SRCS1:.c=.o)
OBJS2 = $(SRCS2:.c=.o)
# define the executable file 
MAIN1 = getAMinfo

MAIN2 = createDB

#
# The following part of the makefile is generic; it can be used to 
# build any executable just by changing the definitions above and by
# deleting dependencies appended to the file from 'make depend'
#

.PHONY: depend clean

all:    $(MAIN1) $(MAIN2)
		@echo  Simple compiler named getAMinfo and createDB have been compiled

$(MAIN1): $(OBJS1)
		$(CC) $(CFLAGS) $(INCLUDES) -o $(MAIN1) $(OBJS1) $(LIBS)

$(MAIN2): $(OBJS2)
		$(CC) $(CFLAGS) $(INCLUDES) -o $(MAIN2) $(OBJS2)

# this is a suffix replacement rule for building .o's from .c's
# it uses automatic variables $<: the name of the prerequisite of
# the rule(a .c file) and $@: the name of the target of the rule (a .o file) 
# (see the gnu make manual section about automatic variables)
.c.o:
		$(CC) $(CFLAGS) $(INCLUDES) -c $<  -o $@

clean:
		$(RM) $(MAIN1) 
		$(RM) $(MAIN2)
		echo "Executable File removed!"
removeinfo:
		$(RM) $(INFODIR)/*
		$(RM) src/*.o
		@echo "Info Files removed!"

cleanall: clean removeinfo
depend: $(SRCS)
		makedepend $(INCLUDES) $^

# DO NOT DELETE THIS LINE -- make depend needs it