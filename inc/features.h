#ifndef FEATURES_H_INCLUDED
#define FEATURES_H_INCLUDED

#include <stdio.h>
#include <libxml/xmlreader.h>

extern xmlChar *filename; 

void process_usespermission();
void process_intentfilter(xmlTextReaderPtr reader,const xmlChar *name);
void process_manifest(reader);

#endif
