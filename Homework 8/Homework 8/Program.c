#include "ZipFiles.h"

int main(size_t argc, char *argv[])
{
    // check for right amount of arguments
    if (argc < 2)
    {
        return -1;
    }

    mz_zip_archive zip;
    int error = initZip(&zip, argv[1]);
    
    // check that the zip was initialized correctly
    if (error)
    {
        return error;
    }

    // get the directory and name of the file
    char *outputDirectory = getFolder(argv[1]);
    char *fileName = getFileName(argv[1]);
    
    // create a new folder with the file name in the file directory
    char *strippedFileName = stripFileExtension(fileName);
    createFolder(outputDirectory, strippedFileName);

    // add the new folder to the output directory
    char *temp = outputDirectory;
    outputDirectory = concatDir(outputDirectory, strippedFileName);

    // extract the files from the zip
    extractZipFiles(&zip, outputDirectory);

    // deallocate all the allocated variables
    free(temp);
    free(strippedFileName);
    free(fileName);

    return 0;
}