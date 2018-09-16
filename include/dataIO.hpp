#ifndef DATA_IO_HPP_
#define DATA_IO_HPP_ 1

//Create files
void createInFile(std::string fileName);
void createOutFile(std::string fileName);
//Input to file
void outputFile(char *inner);
void outputFile(int inner);
//Close file
void closeInFile();
void closeOutFile();


#endif