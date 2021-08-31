#ifndef _ZIP_FILES_H_
#define _ZIP_FILES_H_
#include "miniz.h"

/// @brief Initializes a zip object to the zip file at filepath
/// @param zip Address to zip object to be initialized
/// @param filepath The filepath to a zip
/// @return mz_zip error code
int initZip(mz_zip_archive *zip, const char *filepath);

/// @brief Extracts files in zip archive to file with given filepath
/// @param zip The zip archive
/// @param zipFilepath The filepath within the zip archive
/// @param newFilepath The filepath of the output file
void extractZipFiles(mz_zip_archive* zip, char* outputDirectory);

/// @brief Creates a folder 
/// @param outputDirectory The directory to create the folder in
/// @param folderName The name of the folder
void createFolder(char *outputDirectory, char *folderName);

/// @brief Checks if a file from a zip is a folder
/// @param filename 
/// @return True if the file is a folder, false otherwise
_Bool isZipFolder(char *filename);

/// @brief Checks if a directory is legal
/// @param directory 
/// @return True if the directory is legal, false otherwise
_Bool isDirectory(char *directory);

/// @brief Concatenates two strings
/// @param destination First string in the new string
/// @param source Second string in the new string
/// @return allocated concatenated string
char *concatDir(char *destination, char *source);

/// @brief Formats the zip directory to work for Windows
/// @param directory
/// @return An allocated directory formatted for Windows
char *formatDirectory(char *directory);

/// @brief gets the directory of the folder the given filepath is in
/// @param filepath 
/// @return The directory of the folder the file is in
char *getFolder(char *filepath);

/// @brief Get the file name from a filepath
/// @param filepath 
/// @return The allocated file name string
char *getFileName(char* filepath);

/// @brief Removes the file extension from a file name
/// @param filepath 
/// @return allocated file name without the extension
char *stripFileExtension(char *filepath);

#endif