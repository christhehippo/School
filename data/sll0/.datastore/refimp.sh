#!/bin/bash
#
# refimp.sh - establish reference implementation object files to test new functionality
#
COMPONENT_LIST="src/node"
DATAPATH="/var/public/${2}/.datastore"
SRCPATH="${1}"

for component in ${COMPONENT_LIST}; do
	cp -f ${DATAPATH}/${component}/Makefile ${SRCPATH}/${component}/
	cp -f ${DATAPATH}/${component}/*.o      ${SRCPATH}/${component}/
	touch ${SRCPATH}/${component}/*.o
done

exit 0
