/********************************************/
/*	features.c intents to process all the	
	necessary features from the xml to be 
	considered to post avaliation			*/
#include "../inc/features.h"

const xmlChar *filename;

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

//this will name the file by application
void processManifest(xmlTextReaderPtr reader){

	const xmlChar* atribute = (const xmlChar*)"package";

	filename = xmlTextReaderGetAttribute(reader,atribute);
}

void processIntentFilter(xmlTextReaderPtr reader,const xmlChar *filename){

	const xmlChar* node= xmlTextReaderConstName(reader);
	const xmlChar* atribute= xmlTextReaderReadInnerXml(reader);
	char input[strlen((char*)node)+strlen((char*)atribute)+4];

	snprintf(input, sizeof(input), "%s - %s",(char*)node,(char*)atribute);

	saveToFile(filename, input);
	
}

void processUsesPermission(xmlTextReaderPtr reader,const xmlChar *filename){
	
	const xmlChar* node= xmlTextReaderConstName(reader);
	const xmlChar* atribute= xmlTextReaderGetAttribute(reader,(const xmlChar*)"android:name");
	char input[strlen((char*)node)+strlen((char*)atribute)+4];

	snprintf(input, sizeof(input), "%s - %s",(char*)node,(char*)atribute);

	saveToFile(filename,input);
}

void processActivity
