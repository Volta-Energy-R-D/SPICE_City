#
# SPICE City (tm) makefile 
#
# authors: Sharon Fan, Takis Zourntos
#
# (C) Volta Energy 2025
#

# define a variable to contain all of our object files (if this list changes, we only need to change the variable)
objects = main.o SC_infrastructure.o SC_railway.o SC_lights.o SC_powerstations.o 

# define a variable for our include directory
include = my_includes


# specify a search path for all prerequisites; looks for .o, .c or .h files in ./ or source/ or my_includes/
VPATH = source:my_includes:/usr/lib/x86_64-linux-gnu/

# provide a parameter for our implicit compilation rule (for gcc)
CFLAGS = -I$(include)

# our project will be called proj_ds, and it LINKS object files main_code.o, lib_ll.o and lib_bst.o
proj_SC : $(objects)
	gcc -o proj_SC $(objects) -lphidget22

# compile main.c to produce main.o, if needed
main.o : main.c SC_infrastructure.h SC_railway.h SC_lights.h SC_powerstations.h

# compile various source files for SPICE City
SC_infrastructure.o: SC_infrastructure.c SC_infrastructure.h
SC_railway.o: SC_railway.c SC_railway.h
SC_lights.o: SC_lights.c SC_lights.h
SC_powerstations.o: SC_powerstations.c SC_powerstations.h 


# a clean option that will remove proj_ds and any object files, with EXTRA features now!
.PHONY : clean # declaring clean as "phony" prevents it from being ignored if a file named "clean" happens to exist in the directory!
clean :
	-rm proj_SC $(objects)
#       ^
#       |_______ with the "-" in front of rm, the rm command will continue to execute in spite of any errors generated (such as "file does not exist")
