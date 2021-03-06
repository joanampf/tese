/**
 * section: xmlReader
 * synopsis: Parse an XML file with an xmlReader
 * purpose: Demonstrate the use of xmlReaderForFile() to parse an XML file
 *          and dump the informations about the nodes found in the process.
 *          (Note that the XMLReader functions require libxml2 version later
 *          than 2.6.)
 */

#include <stdio.h>
#include <string.h>
#include <libxml/xmlreader.h>

#include "../inc/savetofile.h"
#include "../inc/features.h"
#ifdef LIBXML_READER_ENABLED

/**
 * processNode:
 * @reader: the xmlReader
 *
 * Dump information about the current node
 */
static void processNode(xmlTextReaderPtr reader) {
    const xmlChar *name;

    name = xmlTextReaderConstName(reader);
    
    if (name == NULL)
	name = BAD_CAST "--";
    
    if(strstr((char*)name,"uses-permission")!=NULL)
        processUsesPermission(reader,filename);
    else if (strstr((char*)name,"action")!=NULL || strstr((char*)name,"category")!=NULL)
        processIntentFilter(reader,filename);
        else if (strstr((char*)name,"manifest")!=NULL)
            processManifest(reader);
            else if (strstr((char*)name,"application")!=NULL)
                processApplication(reader,filename);
            else if(strstr((char*)name,"uses-library")!=NULL)
                processUsesLibrary(reader,filename);
    
}

/**
 * streamFile:
 * @filename: the file name to parse
 *
 * Parse and print information about an XML file.
 */
static void
streamFile(const char *filename) {
    xmlTextReaderPtr reader;
    int ret;

    reader = xmlReaderForFile(filename, NULL, 0);
    if (reader != NULL) {
        ret = xmlTextReaderRead(reader);
        while (ret == 1) {
            processNode(reader);
            ret = xmlTextReaderRead(reader);
        }
        xmlFreeTextReader(reader);
        if (ret != 0) {
            fprintf(stderr, "%s : failed to parse\n", filename);
        }
    } else {
        fprintf(stderr, "Unable to open %s\n", filename);
    }
}

int main(int argc, char **argv) {
    if (argc != 2)
        return(1);

    /*
     * this initialize the library and check potential ABI mismatches
     * between the version it was compiled for and the actual shared
     * library used.
     */
    LIBXML_TEST_VERSION

    streamFile(argv[1]);

    /*
     * Cleanup function for the XML library.
     */
    xmlCleanupParser();
    /*
     * this is to debug memory for regression tests
     */
    xmlMemoryDump();
    return(0);
}

#else
int main(void) {
    fprintf(stderr, "XInclude support not compiled in\n");
    exit(1);
}
#endif
