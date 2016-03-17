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
	const xmlChar* atribute= xmlTextReaderGetAttribute(reader,(const xmlChar*)"android:name");
	char input[strlen((char*)node)+strlen((char*)atribute)+4];

	if (strcmp((char*)atribute, "")!=0){
		snprintf(input, sizeof(input), "%s",(char*)atribute);
		saveToFile(filename, input);
	}
	
}

void processUsesPermission(xmlTextReaderPtr reader,const xmlChar *filename){
	
	const xmlChar* node= xmlTextReaderConstName(reader);
	const xmlChar* atribute= xmlTextReaderGetAttribute(reader,(const xmlChar*)"android:name");
	char input[strlen((char*)node)+strlen((char*)atribute)+4];

	snprintf(input, sizeof(input), "%s",(char*)atribute);

	saveToFile(filename,input);

	
}

void processUsesLibrary(xmlTextReaderPtr reader,const xmlChar *filename){
	
	const xmlChar* node= xmlTextReaderConstName(reader);
	const xmlChar* atribute= xmlTextReaderGetAttribute(reader,(const xmlChar*)"android:name");
	char input[strlen((char*)node)+strlen((char*)atribute)+4];

	snprintf(input, sizeof(input), "%s",(char*)atribute);

	saveToFile(filename,input);
}

void processApplication(xmlTextReaderPtr reader,const xmlChar *filename){
	
	const xmlChar* node= xmlTextReaderConstName(reader);
	const xmlChar* attributePersistent= xmlTextReaderGetAttribute(reader,(const xmlChar*)"android:persistent");
	const xmlChar* attributeTestOnly= xmlTextReaderGetAttribute(reader,(const xmlChar*)"android:testOnly");
	const xmlChar* attributeRequiredAccountType= xmlTextReaderGetAttribute(reader,(const xmlChar*)"android:requiredAccountType");
	const xmlChar* attributeRestrictedAccountType= xmlTextReaderGetAttribute(reader,(const xmlChar*)"android:restrictedAccountType");
	const xmlChar* attributeVmSafeMode= xmlTextReaderGetAttribute(reader,(const xmlChar*)"android:vmSafeMode");	

	if (attributePersistent != NULL){
		char input[strlen((char*)node)+strlen((char*)attributePersistent)+strlen("android:persistent")+5];
		snprintf(input, sizeof(input), "persistent");
		saveToFile(filename,input);
	}
	if (attributeTestOnly != NULL){
		char input[strlen((char*)node)+strlen((char*)attributeTestOnly)+strlen("android:testOnly")+5];
		snprintf(input, sizeof(input), "testOnly");
		saveToFile(filename,input);
	}
	if (attributeRequiredAccountType != NULL){
		char input[strlen((char*)node)+strlen((char*)attributeRequiredAccountType)+strlen("android:requiredAccountType")+5];
		snprintf(input, sizeof(input), "requiredAccountType");
		saveToFile(filename,input);
	}

	if (attributeRestrictedAccountType != NULL){
		char input[strlen((char*)node)+strlen((char*)attributeRestrictedAccountType)+strlen("android:restrictedAccountType")+5];
		snprintf(input, sizeof(input), "restrictedAccountType");
		saveToFile(filename,input);
	}

	if (attributeVmSafeMode != NULL){
		char input[strlen((char*)node)+strlen((char*)attributeVmSafeMode)+strlen("android:vmSafeMode")+5];
		snprintf(input, sizeof(input), "vmSafeMode");
		saveToFile(filename,input);
	}
}