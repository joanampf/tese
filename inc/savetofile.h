#ifndef SAVETOFILE_H_INCLUDED
#define SAVETOFILE_H_INCLUDED

#include <libxml/xmlreader.h>
#include <stdio.h>

void saveToFile(const xmlChar* filename, const xmlChar* attribute);

#endif