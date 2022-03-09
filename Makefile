SHELL = /bin/sh
CXX := g++
CXXFLAGS := -std=c++17 -Wall -g
# -std=c++17  	- Use C++17 standard
# -Wall  		- turns on most compiler warnings
# -g     		- adds debug information to the executable

srcdir := .\/src\/
bindir := .\/bin\/

APPNAME := atap
INCLUDES := -I./src/header/
LDLIBS := -lncurses

srcfiles := $(srcdir)main.cpp $(srcdir)snakegame.cpp


#Build the app specified in APPNAME for the "all" or "default" target
all: $(APPNAME)
default: $(APPNAME)

echo: 									#Print source files
	@echo -e "\nSource files"
	@echo $(srcfiles)
	@echo -e ""

clean:
	rm -f $(bindir)$(APPNAME)

$(APPNAME):
	$(CXX) ${INCLUDES} $(CXXFLAGS) $(LDFLAGS) -o $(bindir)$(APPNAME) $(srcfiles) $(LDLIBS)
