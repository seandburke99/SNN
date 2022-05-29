########################################################################
####################### Makefile Template ##############################
########################################################################

# Compiler settings - Can be customized.
CC = gcc
CXXFLAGS = -std=c11 -Wall -I$(INCDIR)
LDFLAGS = -lm

LIBCC = ar
LIBFLAGS = rcs
LIBDIR = build

# Makefile settings - Can be customized.
APPNAME = SNN
EXT = .c
SRCDIR = src
OBJDIR = obj
INCDIR = include
DEPDIR = dep
BINDIR = bin
DIRS = $(BINDIR) $(DEPDIR) $(OBJDIR)

############## Do not change anything from here downwards! #############
SRC = $(wildcard $(SRCDIR)/*$(EXT))
OBJ = $(SRC:$(SRCDIR)/%$(EXT)=$(OBJDIR)/%.o)
DEP = $(OBJ:$(OBJDIR)/%.o=$(DEPDIR)/%.d)
LIB = $(LIBDIR)/$(APPNAME).a
# UNIX-based OS variables & settings
RM = rm
DELOBJ = $(OBJ)
# Windows OS variables & settings
DEL = del
EXE = .exe
WDELOBJ = $(SRC:$(SRCDIR)/%$(EXT)=$(OBJDIR)\\%.o)

########################################################################
####################### Targets beginning here #########################
########################################################################

all: $(DIRS) $(APPNAME)

$(DIRS):
	mkdir -p $@

# Builds the app
$(APPNAME): $(OBJ)
	$(CC) $(CXXFLAGS) -o $(BINDIR)/$@ $^ $(LDFLAGS)

# Creates the dependecy rules
$(DEPDIR)/%.d: $(SRCDIR)/%$(EXT)
	@$(CPP) $(CFLAGS) $< -MM -MT $(@:$(DEPDIR)/%.d=$(OBJDIR)/%.o) >$@

# Includes all .h files
-include $(DEP)

# Building rule for .o files and its .c/.cpp in combination with all .h
$(OBJDIR)/%.o: $(SRCDIR)/%$(EXT)
	$(CC) $(CXXFLAGS) -o $@ -c $<

# Builds the static lib
SNN.a: $(OBJ)
	$(LIBCC) $(LIBFLAGS) $(LIBDIR)/$@ $^

####################   Cleaning rules   #####################
# Cleans complete project
.PHONY: clean
clean:
	$(RM) $(DELOBJ) $(BINDIR)/$(APPNAME)

# Cleans only all files with the extension .d
.PHONY: cleandep
cleandep:
	$(RM) $(DEP)