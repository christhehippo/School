SHELL = /bin/bash -e
INC = 
CCFLAGS = -Wall --std=gnu99
OPTS =
CC = gcc $(CCFLAGS) $(OPTS) $(INC)
OBJ = 
AR = ar
DEBUG = 
DESIG = discrete
SEMESTER = fall2018
USERPWD = $(USERPATH)
PROJPWD = /var/public/$(SEMESTER)/$(DESIG)/$(PROJ)
PROJ = $(shell /bin/pwd | /bin/sed 's/^.*\///')
LIBS = 
UNIT = 0x0 0x1 0x2 0x3 0x4 0x5
ALL = $(UNIT)
BIN = 
default: status-begin units status-end
debug: status-begin units-debug status-end

status-begin:
	@if [ `cat .updates/current` -lt `cat /var/public/$(SEMESTER)/$(DESIG)/$(PROJ)/.updates/latest` ]; then echo "*********************************************************"; echo "*** NEW UPDATE AVAILABLE: Type 'make update' to apply ***"; echo "*********************************************************"; fi

status-end:
	@if [ `cat .updates/current` -lt `cat /var/public/$(SEMESTER)/$(DESIG)/$(PROJ)/.updates/latest` ]; then echo "*********************************************************"; echo "*** NEW UPDATE AVAILABLE: Type 'make update' to apply ***"; echo "*********************************************************"; fi

status-quit:
	@if [ `cat .updates/current` -lt `cat /var/public/$(SEMESTER)/$(DESIG)/$(PROJ)/.updates/latest` ]; then echo "*********************************************************"; echo "*** NEW UPDATE AVAILABLE: Type 'make update' to apply ***"; echo "*********************************************************"; /bin/false; fi

units-debug: CC += -DDEBUG -g
units-debug: DEBUG = debug
units-debug: units

units:
	@for i in $(UNIT); do make -C $$i $(DEBUG); done

clean: status-begin
	@for i in $(ALL); do make -C $$i clean; done

copy:
	@echo    "Commencing copy process for project $(PROJ)"
	@echo
	@echo -n "Creating project $(PROJ) directory tree           ... "
	@mkdir -p $(USERPWD)/.updates && echo "OK" || echo "error"
	@echo -n "Copying $(PROJ) files into project directory      ... "
	@/bin/cp -av $(PROJPWD)/* $(USERPWD)/ && echo "OK" || echo "error"
	@echo -n "Synchronizing $(PROJ) project revision level      ... "
	@cp -f $(PROJPWD)/.updates/current $(USERPWD)/.updates/ && echo "OK" || echo "error"
	@echo -n "Establishing sane file permissions for $(PROJ)    ... "
	@chmod -R u=rwX,go= $(USERPWD) && echo "OK" || echo "error"
	@echo
	@echo    "Copy Complete! You may now switch to the $(USERPWD)/$(PROJ) directory"
	@echo
	@echo    "[${USER}] obtaining project '$(PROJ)' in `pwd` (`date +\"%Y%m%d%H%M\"`)" >> /var/public/$(SEMESTER)/$(DESIG)/$(PROJ)/.updates/log

save: clean
	@echo
	@echo    "Project backup process commencing"
	@echo
	@echo -n "Taking snapshot of current project ($(PROJ))      ... "
	@(cd ..; tar cf $(PROJ)-`date +%Y%m%d-%H`.tar $(PROJ) && echo "OK" || echo "error")
	@echo -n "Compressing snapshot of $(PROJ) project archive   ... "
	@gzip -f -9 ../$(PROJ)-*.tar && echo "OK" || echo "error"
	@echo -n "Setting secure permissions on $(PROJ) archive     ... "
	@chmod 600 ../$(PROJ)-*.gz && echo "OK" || echo "error"
	@echo
	@echo    "Project backup process complete"
	@echo

submit: save
	@submit $(DESIG) $(PROJ) `/bin/ls -1 ../$(PROJ)*gz | tail -1`
	@echo "[${USER}] submitting project '$(PROJ)' in `pwd` (`date +\"%Y%m%d%H%M\"`)" >> /var/public/$(SEMESTER)/$(DESIG)/$(PROJ)/.updates/log

use-test-reference: clean
	@if [ -e "/var/public/$(SEMESTER)/$(DESIG)/$(PROJ)/.datastore/refimp.sh" ]; then sh /var/public/$(SEMESTER)/$(DESIG)/$(PROJ)/.datastore/refimp.sh `pwd` "$(SEMESTER)/$(DESIG)/$(PROJ)"; fi
	@echo "NODE, LIST, and STACK reference implementation in place, run 'make' to build everything."

use-your-own-code:
	@if [ -e "/var/public/$(SEMESTER)/$(DESIG)/$(PROJ)/.datastore/locimp.sh" ]; then sh /var/public/$(DESIG)/$(SEMESTER)/$(PROJ)/.datastore/locimp.sh `pwd` "$(SEMESTER)/$(DESIG)/$(PROJ)"; fi
	@echo "Local node/list/stack implementation restored, run 'make clean; make' to build everything."

update:
	@for((i=`cat .updates/current`+1; i<=`cat /var/public/$(SEMESTER)/$(DESIG)/$(PROJ)/.updates/latest`; i++)); do sh /var/public/$(SEMESTER)/$(DESIG)/$(PROJ)/.updates/$$i $(SEMESTER) $(DESIG) $(PROJ); echo "[${USER}] applying revision $$i of '$(PROJ)' in `pwd` (`date +\"%Y%m%d%H%M\"`)" >> /var/public/$(SEMESTER)/$(DESIG)/$(PROJ)/.updates/log; done
	@chmod -R u=rwX,go= .
	@echo "Updated from revision `cat .updates/current` to revision `cat /var/public/$(SEMESTER)/$(DESIG)/$(PROJ)/.updates/latest`"
	@cat /var/public/$(SEMESTER)/$(DESIG)/$(PROJ)/.updates/latest > .updates/current

help: status-begin
	@echo
	@echo "***********[ Discrete Structures End of Course Experience ]*************"
	@echo "** make                     - build everything (libs and testing)     **"
	@echo "** make debug               - build everything with debug symbols     **"
	@echo "**                                                                    **"
	@if [ -e "/var/public/$(SEMESTER)/$(DESIG)/$(PROJ)/.datastore/refimp.sh" ]; then echo "**                                                                    **"; echo "** make use-test-reference  - use working implementation object files **"; echo "** make use-your-own-code   - use your node/list implementation code  **"; fi
	@echo "**                                                                    **"
	@echo "** make save                - create a backup archive                 **"
	@echo "** make submit              - submit assignment (based on dirname)    **"
	@echo "** make update              - check for and apply updates             **"
	@echo "**                                                                    **"
	@echo "** make clean               - clean; remove all objects/compiled code **"
	@echo "** make help                - this information                        **"
	@echo "************************************************************************"
