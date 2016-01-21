#ifndef FEATURES_H_INCLUDED
#define FEATURES_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include "../inc/savetofile.h"
#include <libxml/xmlreader.h>

extern const xmlChar *filename; 

void processUsesPermission(xmlTextReaderPtr reader,const xmlChar *filename);
void processIntentFilter(xmlTextReaderPtr reader,const xmlChar *filename);
void processManifest(xmlTextReaderPtr reader);
void processApplication(xmlTextReaderPtr reader,const xmlChar *filename);

#endif
