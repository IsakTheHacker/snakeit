SHELL = /bin/sh
CXX := g++
CXXFLAGS := -std=c++17 -Wall -g
# -std=c++17  	- Use C++17 standard
# -Wall  		- turns on most compiler warnings
# -g     		- adds debug information to the executable

srcdir := .\/src\/
bindir := .\/bin\/

APPNAME := snakeit
INCLUDES := -I./src/header/
LDLIBS := -lncursesw

srcfiles := $(srcdir)main.cpp $(srcdir)snakegame.cpp $(srcdir)food.cpp $(srcdir)snake.cpp $(srcdir)handyFunctions.cpp $(srcdir)collMgr.cpp $(srcdir)globals.cpp


#Build the app specified in APPNAME for the "all" or "default" target
all: $(APPNAME)
default: $(APPNAME)

echo: 									#Print source files
	@echo -e "\nSource files"
	@echo $(srcfiles)
	@echo -e ""

install:
	mv bin $(DESTDIR)

clean:
	rm -f $(bindir)$(APPNAME)

$(APPNAME):
	$(CXX) ${INCLUDES} $(CXXFLAGS) $(LDFLAGS) -o $(bindir)$(APPNAME) $(srcfiles) $(LDLIBS)
