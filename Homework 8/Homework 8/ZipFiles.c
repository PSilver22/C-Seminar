#include "ZipFiles.h"
#include <stddef.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <direct.h>

int initZip(mz_zip_archive *zip, const char *filepath)
{
    int error = -99;

    if (isDirectory(filepath))
    {
        // sets the zip to be full of 0s
        mz_zip_zero_struct(zip);

        // Initializes zip to file at filepath
        mz_bool bool = mz_zip_reader_init_file(zip, filepath, 0);

        error = zip->m_last_error;
    }

    return error;
}

void extractZipFiles(mz_zip_archive *zip, char *outputDirectory)
{
    for (size_t i = 0; i < zip->m_total_files; ++i)
    {
        size_t size = mz_zip_reader_get_filename(zip, i, NULL, NULL);
        char *filename = malloc(size * (sizeof(char) + 1));
        filename[size] = '\0';

        mz_zip_reader_get_filename(zip, i, filename, size);

        if (isZipFolder(filename, size))
        {
            createFolder(outputDirectory, filename);
        }

        else
        {
            char *fileDirectory = concatDir(outputDirectory, filename);
            mz_zip_reader_extract_file_to_file(zip, filename, fileDirectory, 0);
            free(fileDirectory);
        }

        free(filename);
    }
}

_Bool isDirectory(char *directory)
{
    struct stat st = {0};
    return stat(directory, &st) != -1;
}

_Bool isZipFolder(char *filename)
{
    size_t len = strlen(filename);

    return filename[len - 1] == '/';
}

void createFolder(char *outputDirectory, char *folderName)
{
    // check the directory exists
    if (isDirectory(outputDirectory))
    {
        char *file = concatDir(outputDirectory, folderName);

        // check that the folder doesn't exist 
        if (!isDirectory(file))
        {
            _mkdir(file);
        }

        free(file);
    }
}

char *concatDir(char *destination, char *source)
{
    size_t resultLen = strlen(destination) + strlen(source) + 2;
    char *result = malloc(resultLen);
    
    char *currResultChar = result;
    
    // copy destionation then source
    for (char *currDestinationChar = destination; *(currDestinationChar) != '\0'; *(currResultChar++) = *(currDestinationChar++)) {}
    *(currResultChar++) = '\\';
    
    char *formattedSource = formatDirectory(source);
    for (char *currSourceChar = formattedSource; *(currSourceChar) != '\0'; *(currResultChar++) = *(currSourceChar++)) {}
    *(currResultChar) = '\0';

    free(formattedSource);

    return result;
}

char *getFolder(char *filepath)
{
    char *result;
    size_t resultSize = 0;
    for (size_t i = strlen(filepath); filepath[i] != '\\' && i >= 0; --i)
    {
        resultSize = i;
    }

    if (resultSize < 0)
    {
        return NULL;
    }

    result = malloc((resultSize) * sizeof(char));
    for (size_t i = 0; i < resultSize - 1; ++i)
    {
        result[i] = filepath[i];
    }

    result[resultSize - 1] = '\0';
    return result;
}

char* getFileName(char* filepath)
{
    char* result;
    size_t resultSize = 0;
    size_t prefixSize = 0;
    for (size_t i = strlen(filepath); filepath[i] != '\\' && i >= 0; --i)
    {
        ++resultSize;
        prefixSize = i;
    }

    if (resultSize == 0)
    {
        return NULL;
    }

    result = malloc((resultSize + 1) * sizeof(char));
    for (size_t i = 0; i < resultSize; ++i)
    {
        result[i] = filepath[prefixSize + i];
    }

    result[resultSize] = '\0';
    return result;
}

char *formatDirectory(char *directory)
{
    size_t size = strlen(directory);
    char *result = malloc(size + 1);

    // replace every '/' with '\'
    for (size_t i = 0; i < size + 1; ++i)
    {
        result[i] = directory[i];
        
        if (result[i] == '/')
        {
            result[i] = '\\';
        }
    }

    return result;
}

char *stripFileExtension(char *filepath)
{
    char* result;
    size_t resultSize = 0;
    for (size_t i = strlen(filepath); filepath[i] != '.' && i >= 0; --i)
    {
        resultSize = i;
    }

    if (resultSize == 0)
    {
        return NULL;
    }

    result = malloc((resultSize) * sizeof(char));
    for (size_t i = 0; i < resultSize - 1; ++i)
    {
        result[i] = filepath[i];
    }

    result[resultSize - 1] = '\0';

    return result;
}