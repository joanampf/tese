/********************************************/
/*	features.c intents to process all the	
	necessary features from the xml to be 
	considered to post avaliation			*/
#include "../inc/features.h"

xmlChar *filename;

/*	Its important to analyse INTENT-FILTER.
	Contained in:
		<activity>
		<activity-alias>
		<service>
		<receiver>
	Must contain:
		<action>
	Can contain:	
		<category>
		<data>								*/

void process_intentfilter(xmlTextReaderPtr reader,const xmlChar *name){
	saveToFile(name, xmlTextReaderReadInnerXml(reader));
	
}

void process_usespermission(xmlTextReaderPtr reader,const xmlChar *name){
	saveToFile(name, xmlTextReaderGetAttribute(reader,"android:name"));
}

void process_manifest(reader){
	filename = xmlTextReaderGetAttribute(reader,"package");
}