 #!/bin/bash         


echo "Compile Project?[y/n]"

read asr
 
if [ "$asr" == "y" ]; then
	if [ -f getAMinfo ]; then
	    echo "File Clean"
	    make cleanall
	fi
echo "Compiling Project"
make
fi

./getAMinfo AndroidManifest.xml

echo "Finished Execution"
