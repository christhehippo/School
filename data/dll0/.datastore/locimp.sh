#!/bin/bash
#
# locimp.sh - revert to using local implementation
#
COMPONENT_LIST="src/node"
DATAPATH="/var/public/${2}/.datastore"
SRCPATH="${1}"

for component in ${COMPONENT_LIST}; do
	cp -f ${DATAPATH}/${component}/Makefile.orig ${SRCPATH}/${component}/Makefile
done

exit 0
