 #!/bin/bash         




echo -e '\E[1;32m' "Compile Project?[y/n]"
tput sgr0

read asr
 
if [ "$asr" == "y" ]; then
	if [ -f getAMinfo ]; then
	    echo "File Clean"
	    make cleanall 
	fi

echo -e '\E[1;32m' "Compiling Project"
tput sgr0

make
fi

./getAMinfo AndroidManifest.xml

./createDB Info/com.whatsapp.txt

echo -e '\E[1;32m' "Finished Execution"
tput sgr0

exit 0
