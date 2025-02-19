#
# Our most advanced makefile --- using implicit rules with CFLAGS, VPATH for prerequisites, .PHONY and
# suppressing errors in recipes. 
#
# author: T. Zourntos, emad studio
#

# define a variable to contain all of our object files (if this list changes, we only need to change the variable)
objects = gol.o cells.o display.o

# define a variable for our include directory
include = includes

# specify a search path for all prerequisites; looks for .o, .c or .h files in ./ or source/ or my_includes/
VPATH = source:includes

# provide a parameter for our implicit compilation rule (for gcc)
CFLAGS = -I$(include)

# our project will be called proj_pthreads, and it LINKS object files gol.o, cells.o and display.o
proj_pthreads : $(objects)
	gcc -o proj_pthreads $(objects) -l pthread -l ncurses

# compile main code to produce gol.o, if needed
gol.o : gol.c cells.h display.h

# compile cells.c, if needed
cells.o : cells.c cells.h

# compile display.c, if needed
display.o : display.c display.h

# a clean option that will remove proj_ds and any object files, with EXTRA features now!
.PHONY : clean # declaring clean as "phony" prevents it from being ignored if a file named "clean" happens to exist in the directory!
clean :
	-rm proj_pthreads $(objects)
#       ^
#       |_______ with the "-" in front of rm, the rm command will continue to execute in spite of any errors generated (such as "file does not exist")
