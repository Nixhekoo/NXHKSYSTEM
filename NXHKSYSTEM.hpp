#include <iostream>
#include <Windows.h>
#include <fstream>
#include <sstream>
#include <string>
#include <type_traits>
#include <ctime>
#include <cctype>
#include <cstdlib>




std::ofstream FileOut;
std::ifstream FileIn;
const int CharacterAmmount = 44;
const int SymbolAmmount = 18;
char Characters[CharacterAmmount] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ' ', '?', '!', '_', '.', ':', '-', '/'};
char CryptSeed[CharacterAmmount] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ' ', '?', '!', '_', '.', ':', '-', '/'};



// =============================================================================
// =============================== W I N D O W S ===============================
// =============================================================================





// NIXHEKOO - RESET CURSOR POSITION
void NXHK_RESET_CONSOLE_CURSOR_POSITION(){
    HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD restartCursorPosition = {0, 0};
    SetConsoleCursorPosition(Console, restartCursorPosition);
}





// NIXHEKOO - SET CURSOR POSITION
void NXHK_SET_CONSOLE_CURSOR_POSITION(short x, short y){
    HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD restartCursorPosition = {x, y};
    SetConsoleCursorPosition(Console, restartCursorPosition);
}





// NIXHEKOO - SET WINDOW TITLE
void NXHK_SET_CONSOLE_TITLE(std::string TITLE){
    SetConsoleTitleA(TITLE.c_str());
}





// NIXHEKOO - GET CURSOR X POSITION
int NXHK_GET_MOUSE_POSITION_X(){
    POINT cursorPos;

    // Get the cursor position
    if (GetCursorPos(&cursorPos)) {
        return cursorPos.x;
    } else {
        return 0;
    }
}





// NIXHEKOO - GET CURSOR Y POSITION
int NXHK_GET_MOUSE_POSITION_Y(){
    POINT cursorPos;

    // Get the cursor position
    if (GetCursorPos(&cursorPos)) {
        return cursorPos.y;
    } else {
        return 0;
    }
}





// NIXHEKOO - GET SCREEN SIZE X
int NXHK_GET_SCREEN_SIZE_X(){
    return GetSystemMetrics(SM_CXSCREEN);
}





// NIXHEKOO - GET SCREEN SIZE Y
int NXHK_GET_SCREEN_SIZE_Y(){
    return GetSystemMetrics(SM_CYSCREEN);
}





// NIXHEKOO - GET MONITORS AMMOUNT
int NXHK_GET_MONITORS_AMMOUNT(){
    return GetSystemMetrics(SM_CMONITORS);
}






// NIXHEKOO - SET CONSOLE COLOR
void NXHK_SET_CONSOLE_COLOR(int COLOR){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), COLOR);
}




// ===========================================================================
// ================================ F I L E S ================================
// ===========================================================================



// NIXHEKOO - CREATE PATH (IF NOT EXIST)
int NXHK_CREATE_PATH(std::string PATH){
    std::wstring wideString(PATH.begin(), PATH.end());
    CreateDirectoryW(wideString.c_str(), NULL);
    if(GetLastError() == ERROR_PATH_NOT_FOUND){
        return 0;
    }
    return 1;
}





// NIXHEKOO - FIND FILE DIRECTORY
std::string NXHK_SET_FILE_DIRECTORY(std::string PATH){
    std::string temp = getenv("LOCALAPPDATA");
    if(NXHK_CREATE_PATH(temp + "\\" + PATH)){
        return temp + "\\" + PATH;
    } else {
        return "NXHK_ERROR";
    }
}






// NIXHEKOO - FILE EXISTS
bool NXHK_CHECK_IF_FILE_EXISTS(std::string FOLDERPATH, std::string FILENAME){
    std::string FULLPATH = FOLDERPATH + "\\" + FILENAME;
    FileIn.open(FULLPATH);
    bool temp = FileIn.good();
    while(FileIn.is_open()){
        Sleep(50);
        FileIn.close();
    }
    return temp;
}



// =====================================================================================
// =========================== D A T A   C O N V E R S I O N ===========================
// =====================================================================================




// NIXHEKOO - CONVERT TO STRING
template<typename T>
std::string NXHK_CONVERT_TO_STRING(const T& VALUE){
    std::stringstream ss;
    ss << VALUE;
    return ss.str();
}




// NIXHEKOO - CONVERT DATA TYPE TO INTEGER
template<typename T>
int NXHK_CONVERT_TO_INT(const T& VALUE){
    int tempInt;
    std::stringstream ss(VALUE);
    ss >> tempInt;
    return tempInt;
}




// NIXHEKOO - CONVERT DATA TYPE TO BOOLIAN
template<typename T>
bool NXHK_CONVERT_TO_BOOL(const T& VALUE){
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
float NXHK_CONVERT_TO_FLOAT(const T& VALUE){
    float tempFloat;
    std::stringstream ss(VALUE);
    ss >> tempFloat;
    return tempFloat;
}




// NIXHEKOO - CONVERT DATA TYPE TO CHAR
template<typename T>
char NXHK_CONVERT_TO_CHAR(const T& VALUE){
    return VALUE[0];
}




// ===============================================================================
// =============================== C R Y P T I O N ===============================
// ===============================================================================




// NIXHEKOO - CREATE ENCRYPT SEED
std::string NXHK_CREATE_ENCRYPT_SEED(int ENCRYPTPOWER, int LOADINGBAR, std::string LOADINGTEXT){


    // Stabilize Encrypt Power
    if(ENCRYPTPOWER > 500000){   // If Encrypt Power is more then 500K, set it to 500K.
        ENCRYPTPOWER = 500000;
    } else if(ENCRYPTPOWER > 100000){   // If Encrypt Power is more then 100K, set Loading Bar to 0.
        LOADINGBAR = 0;
    } else if(ENCRYPTPOWER < 100){   // If Encrypt Power is less then 100, set it to 100.
        ENCRYPTPOWER = 100;
    }


    // Begin
    NXHK_SET_CONSOLE_COLOR(7);
    srand(time(NULL));
    int random1;
    int random2;
    float percentage = 0;
    for(int i = 0; i < ENCRYPTPOWER; i++){
        // Letters
        random1 = 0;
        random2 = 0;
        while(random1 == random2){
            random1 = rand() % (CharacterAmmount - SymbolAmmount);
            random2 = rand() % (CharacterAmmount - SymbolAmmount);
        }
        std::swap(CryptSeed[random1], CryptSeed[random2]);

        // Symbols
        random1 = 0;
        random2 = 0;
        while(random1 == random2){
            random1 = 26 + (rand() % SymbolAmmount);
            random2 = 26 + (rand() % SymbolAmmount);
        }
        std::swap(CryptSeed[random1], CryptSeed[random2]);

        // Loading Bar
        if(LOADINGBAR > 0){
            NXHK_RESET_CONSOLE_CURSOR_POSITION();
            std::cout << "[";
            for(int j = 0; j < LOADINGBAR; j++){
                // Calculate the percentage progress
                percentage = static_cast<float>(i) / ENCRYPTPOWER * 100;

                // Display a filled segment if the progress is less than or equal to the percentage
                if(static_cast<float>(j) < percentage * LOADINGBAR / 100.0f){
                    std::cout << "#";
                } else {
                    std::cout << " ";
                }
            }std::cout << "] ";
            std::cout << LOADINGTEXT << percentage << "%";
        } else {
            NXHK_RESET_CONSOLE_CURSOR_POSITION();
            std::cout << LOADINGTEXT;
        }
    }
    system("cls");
    std::string ReturnThis;
    for(int i = 0; i < CharacterAmmount; i++){
        ReturnThis+= CryptSeed[i];
    }
    return ReturnThis;
}





// NIXHEKOO - ENCRYPT
std::string NXHK_ENCRYPT_MESSAGE(std::string MESSAGE, std::string ENCRYPTSEED){
    // Variables
    std::string EncryptedMessage;
    char temporaryLetter;

    // Check for each letter of Message
    for(int letter = 0; letter < MESSAGE.length(); letter++){
        for(int index = 0; index < CharacterAmmount; index++){
            // Sets the letter to be uppercase
            temporaryLetter = toupper(MESSAGE[letter]);

            // Checks if we found the position of the letter from the message in the Characters Array
            if(temporaryLetter == Characters[index]){
                if(islower(MESSAGE[letter])){
                    EncryptedMessage+= tolower(ENCRYPTSEED[index]);
                } else if(isupper(MESSAGE[index])){
                    EncryptedMessage+= toupper(ENCRYPTSEED[index]);
                } else {
                    EncryptedMessage+= ENCRYPTSEED[index];
                }
            }
        }
    }
    return EncryptedMessage;
}





// NIXHEKOO - DECRYPT
std::string NXHK_DECRYPT_MESSAGE(std::string MESSAGE, std::string DECRYPTSEED){
    // Variables
    std::string DecryptedMessage;
    char temporaryLetter;

    // Check for each letter of Message
    for(int letter = 0; letter < MESSAGE.length(); letter++){
        for(int index = 0; index < CharacterAmmount; index++){
            // Sets the letter to be uppercase
            temporaryLetter = toupper(MESSAGE[letter]);

            // Checks if we found the position of the letter from the message in the Characters Array
            if(temporaryLetter == DECRYPTSEED[index]){
                if(islower(MESSAGE[letter])){
                    DecryptedMessage+= tolower(Characters[index]);
                } else if(isupper(MESSAGE[index])){
                    DecryptedMessage+= toupper(Characters[index]);
                } else {
                    DecryptedMessage+= Characters[index];
                }
            }
        }
    }
    return DecryptedMessage;
}




// ===============================================================================
// ======================== F I L E   M A N A G E M E N T ========================
// ===============================================================================





// NIXHEKOO - SAVE DATA TO FILE
int NXHK_SAVE_TO_FILE(std::string FOLDERPATH, std::string FILENAME, std::string CONTENT, int LINE){
    if(FOLDERPATH != "NXHK_ERROR"){

        // Creates folder if it doesnt exist yet
        if(NXHK_CREATE_PATH(FOLDERPATH) == 1){


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
            return 1;
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}





// NIXHEKOO - LOAD STRING DATA FROM FILE
std::string NXHK_LOAD_FROM_FILE(std::string FOLDERPATH, std::string FILENAME, int LINE){
    if(FOLDERPATH != "NXHK_ERROR"){

        // Creates folder if it doesnt exist yet
        if(NXHK_CREATE_PATH(FOLDERPATH) == 1){


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
        } else {
        return "0";
        }
    } else {
        return "0";
    }
}