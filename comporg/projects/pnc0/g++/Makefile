LIBS = -lm
CFLAGS = -Wall $(LIBS)
INC = 
CC = g++
SRC = $(shell ls -1 *.cc 2>/dev/null)
BIN = $(SRC:.cc=)
DESIG = comporg
PROJ = pnc0
SEMESTER = spring2018
USERPWD = $(shell pwd)
DATAPATH = /var/public/$(SEMESTER)/$(DESIG)
PROJPATH = $(DATAPATH)/$(PROJ)
BINPATH = .
all: build

debug: CFLAGS += -DDEBUG -g
debug: DEBUG = debug
debug: build

status-begin:
	@rm -f errors
	@if [ -e "$(PROJPATH)/.updates/latest" ]; then if [ `cat .updates/current` -lt `cat $(PROJPATH)/.updates/latest` ]; then echo "*********************************************************"; echo "*** NEW UPDATE AVAILABLE: Type 'make update' to apply ***"; echo "*********************************************************"; fi; fi

status-end:
	@if [ -e "errors" ]; then if [ `cat errors | wc -l` -gt 0 ]; then echo " *** There were warnings or errors during compile! Type: 'cat errors' at the prompt to view."; fi; fi
	@if [ -e "$(PROJPATH)/.updates/latest" ]; then if [ `cat .updates/current` -lt `cat $(PROJPATH)/.updates/latest` ]; then echo "*********************************************************"; echo "*** NEW UPDATE AVAILABLE: Type 'make update' to apply ***"; echo "*********************************************************"; fi; fi

status-quit:
	@if [ -e "$(PROJPATH)/.updates/latest" ]; then if [ `cat .updates/current` -lt `cat $(PROJPATH)/.updates/latest` ]; then echo "*********************************************************"; echo "*** NEW UPDATE AVAILABLE: Type 'make update' to apply ***"; echo "*********************************************************"; /bin/false; fi; fi

build: status-begin $(SRC) $(BIN) status-end
	@if [ -e "$(PROJPATH)/.updates/.metrics/${USER}" ]; then date +'%Y%m%d%H%M%S' >> $(PROJPATH)/.updates/.metrics/${USER}; fi

.cc:
ifneq ($(MAKECMDGOALS),debug)
	@printf "[\033[0;33mCC\033[0m]   %-20s ... " "$<"
	@$(CC) $(INC) -o $@ $< $(CFLAGS) 2>> errors && echo "\033[0;32mOK\033[0m" || echo "\033[0;31mFAIL\033[0m"
else
	$(CC)  $(INC) -o $@ $< $(CFLAGS)
endif

checkqty: status-begin
	@DISPLAYMODE="new" STATS="$(DATAPATH)/$(PROJ)" primerun

verifyqty: status-begin
	@DISPLAYMODE="new" STATS="$(DATAPATH)/$(PROJ)" primerun verify

checkrange: status-begin
	@DISPLAYMODE="new" PROCMODE="range" STATS="$(DATAPATH)/$(PROJ)" primerun

verifyrange: status-begin
	@DISPLAYMODE="new" PROCMODE="range" STATS="$(DATAPATH)/$(PROJ)" primerun verify

verifyall: status-begin
	@DISPLAYMODE="new" STATS="$(DATAPATH)/$(PROJ)" primerun verifyall

copy:
	@echo      "Commencing copy process for $(SEMESTER) $(DESIG) project $(PROJ):"
	@echo  -n  " -> Creating project $(PROJ) directory tree           ... "
	@mkdir -p  $(USERPWD)/.updates 2> /dev/null && echo "OK" || echo "error"
	@echo  -n  " -> Copying $(PROJ) project files                     ... "
	@cp    -a  $(PROJPATH)/* $(USERPWD)/ 2>/dev/null && echo "OK" || echo "error"
	@echo  -n  " -> Synchronizing $(PROJ) project revision level      ... "
	@cp    -f  $(PROJPATH)/.updates/current $(USERPWD)/.updates/ 2> /dev/null && echo "OK" || echo "error"
	@echo  -n  " -> Establishing sane file permissions for $(PROJ)    ... "
	@chmod -R  u=rwX,go= $(USERPWD) && echo "OK" || echo "error"
	@echo
	@echo      "*** Copy COMPLETE! You may now go to the '$(USERPWD)' directory ***"
	@echo
	@echo      "[${USER}] obtaining project '$(PROJ)' (revision `cat $(PROJPATH)/.updates/latest`) in $(USERPWD) (`date +\"%Y%m%d%H%M\"`)" >> $(PROJPATH)/.updates/log 2>/dev/null

submit: save
	@submit $(DESIG) $(PROJ) `/bin/ls -1 ../$(PROJ)*gz | tail -1`
	@echo "[${USER}] submitting project '$(PROJ)' in `pwd` (`date +\"%Y%m%d%H%M\"`)" >> $(PROJPATH)/.updates/log

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
	@for((i=`cat .updates/current`+1; i<=`cat $(PROJPATH)/.updates/latest`; i++)); do sh $(PROJPATH)/.updates/$$i $(SEMESTER) $(DESIG) $(PROJ); echo "[${USER}] applying revision $$i of '$(PROJ)' in `pwd` (`date +\"%Y%m%d%H%M\"`)" >> $(PROJPATH)/.updates/log; done
	@chmod -R u=rwX,go= .
	@echo "Updated from revision `cat .updates/current` to revision `cat $(PROJPATH)/.updates/latest`"
	@cat $(PROJPATH)/.updates/latest > .updates/current

reupdate:
	@for((i=`cat .updates/current`; i<=`cat .updates/current`; i++)); do sh $(PROJPATH)/.updates/$$i $(SEMESTER) $(DESIG) $(PROJ); echo "[${USER}] re-applying revision $$i of '$(PROJ)' in `pwd` (`date +\"%Y%m%d%H%M\"`)" >> $(PROJPATH)/.updates/log; done
	@chmod -R u=rwX,go= .
	@echo "Re-applying revision `cat .updates/current`"

reupdate-all:
	@for((i=1; i<=`cat .updates/current`; i++)); do sh $(PROJPATH)/.updates/$$i $(SEMESTER) $(DESIG) $(PROJ); echo "[${USER}] re-applying revision $$i of '$(PROJ)' in `pwd` (`date +\"%Y%m%d%H%M\"`)" >> $(PROJPATH)/.updates/log; done
	@chmod -R u=rwX,go= .
	@echo "Re-applied updates from revision 1 to revision `cat .updates/current`"

showerrors:
	@cat errors

clean:
	@rm -vf .*.sw[op] *.save* *~ $(BIN) $(BINPATH)/$(BIN) core errors
	@rm -rf prime*.dSYM

help: status-begin
	@echo "******************[ Discrete Structures $(PROJ) Project ]******************"
	@echo "** make                     - build everything                        **"
	@echo "** make showerrors          - display compiler warnings/errors        **"
	@echo "**                                                                    **"
	@echo "** make debug               - build everything with debug symbols     **"
	@echo "** make checkqty            - runtime evaluation for qty              **"
	@echo "** make checkrange          - runtime evaluation for range            **"
	@echo "**                                                                    **"
	@echo "** make verifyqty           - check implementation for qty validity   **"
	@echo "** make verifyrange         - check implementation for range validity **"
	@echo "** make verifyall           - verify project specifications           **"
	@echo "**                                                                    **"
	@echo "** make save                - create a backup archive                 **"
	@echo "** make submit              - submit assignment (based on dirname)    **"
	@echo "**                                                                    **"
	@echo "** make update              - check for and apply updates             **"
	@echo "** make reupdate            - re-apply last revision                  **"
	@echo "** make reupdate-all        - re-apply all revisions                  **"
	@echo "**                                                                    **"
	@echo "** make clean               - clean; remove all objects/compiled code **"
	@echo "** make help                - this information                        **"
	@echo "************************************************************************"
