/********************************************/
/*	features.c intents to process all the	
	necessary features from the xml to be 
	considered to post avaliation			*/
#include <stdio.h>
#include <libxml/xmlreader.h>


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

void process_usespermission(){

}