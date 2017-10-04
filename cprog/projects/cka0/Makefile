LIBS = -lm
INC = -I .
CFLAGS = -g -Wall --std=c99 $(INC) $(LIBS)
CC = gcc
SRC = $(shell /bin/ls -1 *.c 2>/dev/null)
BIN = $(SRC:.c=)
DESIG = cprog
PROJ = cka0
SEMESTER = fall2017
USERPWD = $(USERPATH)
PROJPWD = /var/public/$(SEMESTER)/$(DESIG)/$(PROJ)
BINPATH = .
all: clean $(BIN)

debug: CFLAGS += -DDEBUG -g
debug: DEBUG = debug
debug: clean $(SRC)

.c:
ifneq ($(MAKECMDGOALS),debug)
	@printf "[\033[0;33mCC\033[0m]   %-20s ... " "$<"
	@$(CC) $(CFLAGS) -o $@ $< 2>> errors && echo "\033[0;32mOK\033[0m" || echo "\033[0;31mFAIL\033[0m"
else
	$(CC)  $(CFLAGS) -o $@ $<
endif

check:
	@$(PWD)/$(PROJ)top    | /usr/bin/md5sum | cut -d' ' -f1 > MD5SUMTOP
	@$(PWD)/$(PROJ)bottom | /usr/bin/md5sum | cut -d' ' -f1 > MD5SUMBOTTOM
	@echo -n "   TOP-DRIVEN: "
	@/usr/bin/diff $(PWD)/MD5SUMTOP    $(PROJPWD)/.MANIFEST > /dev/null && echo "SUCCESS" || echo "MISMATCH"
	@echo -n "BOTTOM-DRIVEN: "
	@/usr/bin/diff $(PWD)/MD5SUMBOTTOM $(PROJPWD)/.MANIFEST > /dev/null && echo "SUCCESS" || echo "MISMATCH"

show:
	@/bin/cat $(PROJPWD)/.OUTPUT

showends:
	@echo "   TOP-DRIVEN: "
	@echo "============== "
	@$(PWD)/$(PROJ)top    | cat -e > OUTPUTTOP
	@echo "Reference:              Your Implementation:"
	@echo "=========               =================== "
	@/usr/bin/paste $(PROJPWD)/.OUTPUTLE $(PWD)/OUTPUTTOP
	@echo
	@echo "BOTTOM-DRIVEN: "
	@echo "============== "
	@$(PWD)/$(PROJ)bottom | cat -e > OUTPUTBOTTOM
	@echo "Reference:              Your Implementation:"
	@echo "=========               =================== "
	@/usr/bin/paste $(PROJPWD)/.OUTPUTLE $(PWD)/OUTPUTBOTTOM


compare:
	@echo "   TOP-DRIVEN: "
	@echo "============== "
	@$(PWD)/$(PROJ)top > OUTPUTTOP
	@echo "Reference:              Your Implementation:"
	@echo "=========               =================== "
	@/usr/bin/paste $(PROJPWD)/.OUTPUT $(PWD)/OUTPUTTOP
	@echo
	@echo "BOTTOM-DRIVEN: "
	@echo "============== "
	@$(PWD)/$(PROJ)bottom > OUTPUTBOTTOM
	@echo "Reference:              Your Implementation:"
	@echo "=========               =================== "
	@/usr/bin/paste $(PROJPWD)/.OUTPUT $(PWD)/OUTPUTBOTTOM

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

help:
	@echo "make          - compile programs"
	@echo "make clean    - remove all compiled code"
	@echo "make check    - verify your output against my sample"
	@echo "make compare  - display my reference output and yours"
	@echo "make showends - visualize line-endings in output"
	@echo "make debug    - be more verbose while compiling"
	@echo "show          - display my reference output"
	@echo "submit        - submit the knowledge assessment"

info:
	@clear
	@cat $(PROJPWD)/.INFO | more

clean:
	@/bin/rm -vf .*.sw[op] *.save* *~ $(BIN) $(OBJ) core errors
