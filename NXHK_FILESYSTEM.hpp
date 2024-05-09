#include <iostream>
#include <Windows.h>
#include <fstream>
#include <sstream>
#include <type_traits>
#include <sstream>




std::ofstream FileOut;
std::ifstream FileIn;




// NIXHEKOO - CREATE PATH (IF NOT EXIST)
void NXHK_CREATEPATH(std::string PATH){
    std::string tempmessage = "if not exist \"" + PATH + "\" (md \"" + PATH + "\")";
    system(tempmessage.c_str());
}





// NIXHEKOO - CONVERT TO STRING
template<typename T>
std::string NXHK_TO_STRING(const T& VALUE){
    std::stringstream ss;
    ss << VALUE;
    return ss.str();
}




// NIXHEKOO - CONVERT DATA TYPE TO INTEGER
template<typename T>
int NXHK_TO_INT(const T& VALUE){
    int tempInt;
    std::stringstream ss(VALUE);
    ss >> tempInt;
    return tempInt;
}




// NIXHEKOO - CONVERT DATA TYPE TO BOOLIAN
template<typename T>
bool NXHK_TO_BOOL(const T& VALUE){
    int tempInt;
    std::stringstream ss(VALUE);
    ss >> tempInt;
    if(tempInt == 1){
        return true;
    } else if(tempInt == 0){
        return false;
    } else {
        return -1;
    }
}




// NIXHEKOO - CONVERT DATA TYPE TO FLOAT
template<typename T>
float NXHK_TO_FLOAT(const T& VALUE){
    float tempFloat;
    std::stringstream ss(VALUE);
    ss >> tempFloat;
    return tempFloat;
}




// NIXHEKOO - CONVERT DATA TYPE TO CHAR
template<typename T>
char NXHK_TO_CHAR(const T& VALUE){
    return VALUE[0];
}





// NIXHEKOO - FIND FILE DIRECTORY
std::string NXHK_FILEDIR(std::string PATH){
    std::string temp;
    system("echo %localappdata%>savelocation.txt");
    FileIn.open("savelocation.txt");
    FileIn >> temp;
    FileIn.close();
    while(FileIn.is_open()){
        Sleep(50);
        FileIn.close();
    }
    const char *filenametodelete = "savelocation.txt";
    std::remove(filenametodelete);
    NXHK_CREATEPATH(temp + "\\" + PATH);
    return temp + "\\" + PATH;
}






// NIXHEKOO - FILE EXISTS
bool NXHK_FILEEXISTS(std::string FOLDERPATH, std::string FILENAME){
    std::string FULLPATH = FOLDERPATH + "\\" + FILENAME;
    FileIn.open(FULLPATH);
    bool temp = FileIn.good();
    while(FileIn.is_open()){
        Sleep(50);
        FileIn.close();
    }
    return temp;
}






// NIXHEKOO - SAVE DATA TO FILE
void NXHK_SAVE(std::string FOLDERPATH, std::string FILENAME, std::string CONTENT, int LINE){


    // Creates folder if it doesnt exist yet
    NXHK_CREATEPATH(FOLDERPATH);


    // Sets up local variables
    std::string FULLPATH = FOLDERPATH + "\\" + FILENAME;
    std::string TEMPPATH = FOLDERPATH + "\\" + "NXHKTEMPORARY.nxhksystem";
    int currentline = 1;
    std::string linecontent;


    // Open Files for Reading or Writing
    FileOut.open(TEMPPATH);
    FileIn.open(FULLPATH);
    if(!FileOut.is_open()){
        Sleep(50);
        FileOut.open(TEMPPATH);
    }
    if(!FileIn.is_open()){
        Sleep(50);
        FileIn.open(FULLPATH);
    }


    // Iterates through Lines
    while(getline(FileIn, linecontent)) {
        if(currentline == LINE) {
            FileOut << CONTENT << std::endl;
        } else {
            FileOut << linecontent << std::endl;
        }
        currentline++;
    }

    // Add empty lines if the desired LINE was not reached
    while(currentline <= LINE) {
        if(currentline == LINE) {
            FileOut << CONTENT << std::endl;
        } else {
            FileOut << std::endl;
        }
        currentline++;
    }
    

    // Close File if it is open
    FileOut.close();
    FileIn.close();
    if(FileOut.is_open()){
        Sleep(50);
        FileOut.close();
    }
    if(FileIn.is_open()){
        Sleep(50);
        FileIn.close();
    }

    // Delete the files
    const char *filenametodelete = FULLPATH.c_str();
    std::remove(filenametodelete);


    // Rename old file to new one
    const char *oldfilename = TEMPPATH.c_str();
    const char *newfilename = FULLPATH.c_str();
    std::rename(oldfilename, newfilename);
}





// NIXHEKOO - LOAD STRING DATA FROM FILE
std::string NXHK_LOAD(std::string FOLDERPATH, std::string FILENAME, int LINE){


    // Creates folder if it doesnt exist yet
    NXHK_CREATEPATH(FOLDERPATH);


    // Sets up local variables
    std::string FULLPATH = FOLDERPATH + "\\" + FILENAME;
    int currentline = 1;
    std::string linecontent;


    // Open Files for Reading or Writing
    FileIn.open(FULLPATH);
    if(!FileIn.is_open()){
        Sleep(50);
        FileIn.open(FULLPATH);
    }


    // Iterates through Lines
    while(getline(FileIn, linecontent)) {
        if(currentline == LINE) {
            FileIn.close();
            if(FileIn.is_open()){
                Sleep(50);
                FileIn.close();
            }
            return linecontent;
        } else {
            currentline++;
        }
    }


    // Close File if it is open
    FileIn.close();
    if(FileIn.is_open()){
        Sleep(50);
        FileIn.close();
    }


    return "0";
}