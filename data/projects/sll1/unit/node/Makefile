LIBS = -lsupport -lnode
CFLAGS = -Wall -static -L../../lib $(LIBS)
INC = -I ../../inc/
CC = gcc
PROJECT = $(shell /bin/pwd | /bin/grep -o '[sd]l[nlsqt][0-9]' | /usr/bin/sort -u)
NAME = $(shell echo "$(LIBS)" | /usr/bin/cut -d' ' -f1 | /bin/sed 's/^..//' | tr '[:lower:]' '[:upper:]')
SRC = $(shell /bin/ls -1 *.c 2>/dev/null)
BIN = $(SRC:.c=)
BINPATH = ../../bin
all: intro $(SRC) $(BIN) install

intro:
ifneq ($(MAKECMDGOALS),debug)
	@printf "Building \033[1;36m$(NAME)\033[0m library unit tests\n"
	@printf "=======================================\n"
endif

debug: CFLAGS += -DDEBUG -g
debug: DEBUG = debug
debug: $(SRC) $(BIN) install

.c:
ifneq ($(MAKECMDGOALS),debug)
	@printf "[\033[0;33mCC\033[0m]   %-20s ... " "$<"
	@$(CC) $(INC) -o $@ $< $(CFLAGS) 2>> ../../errors && echo "\033[0;32mOK\033[0m" || echo "\033[0;31mFAIL\033[0m"
else
	$(CC)  $(INC) -o $@ $< $(CFLAGS)
endif

install:
ifneq ($(MAKECMDGOALS),debug)
	@echo -n "[\033[1;33mCP\033[0m] Copying to \033[1;35m$(PROJECT)/bin/\033[0m   ... "
	@/bin/cp -f *.sh $(BIN) $(BINPATH)/ 2>> ../../errors && echo "\033[1;32mSUCCESS\033[0m" || echo "\033[1;31mFAIL\033[0m"
	@echo
else
	@/bin/cp -f *.sh $(BIN) $(BINPATH)/
endif

clean:
	@rm -f .*.sw[op] *.save* *~ $(BIN) $(BINPATH)/$(BIN) core ../../errors
