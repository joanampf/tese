#ifndef SAVETOFILE_H_INCLUDED
#define SAVETOFILE_H_INCLUDED

#include <libxml/xmlreader.h>
#include <string.h>
#include <stdio.h>

void saveToFile(const xmlChar* filename, char* input);

#endif
