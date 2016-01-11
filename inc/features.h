#ifndef FEATURES_H_INCLUDED
#define FEATURES_H_INCLUDED

#include <libxml/xmlreader.h>

void process_usespermission();
void process_intentfilter(xmlTextReaderPtr reader,const xmlChar *name);

#endif