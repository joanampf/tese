#ifndef FEATURES_H_INCLUDED
#define FEATURES_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include "../inc/savetofile.h"
#include <libxml/xmlreader.h>

extern const xmlChar *filename; 

void process_usespermission();
void process_intentfilter(xmlTextReaderPtr reader,const xmlChar *name);
void process_manifest(xmlTextReaderPtr reader);

#endif
