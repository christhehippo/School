LIBS = -lm
INC = -I .
CFLAGS = -g -Wall --std=c99 $(LIBS)
CC = gcc
SRC = $(shell /bin/ls -1 *.c 2>/dev/null)
OBJ = $(SRC:.c=.o)
BIN = cka0
DESIG = cprog
PROJ = cka0
SEMESTER = $(shell /bin/cat /usr/local/etc/semester)
USERPWD = $(USERPATH)
PROJPWD = /var/public/$(SEMESTER)/$(DESIG)/$(PROJ)
BINPATH = .
all: clean $(SRC) $(OBJ) bin 

debug: CFLAGS += -DDEBUG -g
debug: DEBUG = debug
debug: clean $(SRC) $(OBJ) $(BIN) 

.c.o:
ifneq ($(MAKECMDGOALS),debug)
	@printf "[\033[0;33mCC\033[0m]   %-20s ... " "$<"
	@$(CC) $(CFLAGS) $(INC) -c $< 2>> errors && echo "\033[0;32mOK\033[0m" || echo "\033[0;31mFAIL\033[0m"
else
	$(CC)  $(CFLAGS) $(INC) -c $<
endif

bin:
ifneq ($(MAKECMDGOALS),debug)
	@printf "[\033[0;33mCC\033[0m]   %-20s ... " "$(BIN)"
	@$(CC) $(CFLAGS) $(INC) -o $(BIN) *.o 2>> errors && echo "\033[0;32mOK\033[0m" || echo "\033[0;31mFAIL\033[0m"
else
	$(CC)  $(CFLAGS) $(INC) -o $(BIN) *.o
endif

check:
	@$(PWD)/$(PROJ) | /usr/bin/md5sum | cut -d' ' -f1 > MD5SUM
	@/usr/bin/diff $(PWD)/MD5SUM $(PROJPWD)/.MANIFEST > /dev/null && echo "SUCCESS" || echo "MISMATCH"

show:
	@$(PWD)/$(PROJ) > OUTPUT
	@echo "Reference:                              Your Implementation:"
	@echo "=========                               =================== "
	@/usr/bin/paste $(PROJPWD)/.OUTPUT $(PWD)/OUTPUT

copy:
	@/bin/cp -av $(PROJPWD)/* $(USERPWD)/

submit: save
	@submit $(DESIG) $(PROJ) `/bin/ls -1 ../$(PROJ)*gz | tail -1`

save: clean
	@echo
	@echo    "Project backup process commencing"
	@echo
	@echo -n "Taking snapshot of current project ($(PROJ))      ... "
	@(cd ..; /bin/tar cf $(PROJ)-`/bin/date +%Y%m%d-%H`.tar $(PROJ) && echo "OK" || echo "error")
	@echo -n "Compressing snapshot of $(PROJ) project archive   ... "
	@/bin/gzip -f -9 ../$(PROJ)-*.tar && echo "OK" || echo "error"
	@echo -n "Setting secure permissions on $(PROJ) archive     ... "
	@/bin/chmod 600 ../$(PROJ)-*.gz && echo "OK" || echo "error"
	@echo
	@echo    "Project backup process complete"
	@echo

update:
	@/bin/cp -f $(PROJPWD)/Makefile .

info:
	@cat $(PROJPWD)/.INFO | more

clean:
	@/bin/rm -vf .*.sw[op] *.save* *~ $(BIN) $(OBJ) core errors
