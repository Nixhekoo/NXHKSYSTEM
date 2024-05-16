# Nixhekoo's System
- [About the Header](https://github.com/Nixhekoo/NXHKSYSTEM?tab=readme-ov-file#about-the-header) <br>
- [How to Use](https://github.com/Nixhekoo/NXHKSYSTEM?tab=readme-ov-file#how-to-use) <br>
- [All Functions](https://github.com/Nixhekoo/NXHKSYSTEM?tab=readme-ov-file#all-functions) <br>

# About the Header
- A helpful header for people who don't know how to properly save their game in C++. This header will help you with all file managment you would ever need when saving data to files in your PC.

# How to Use
- THE HEADER IS WINDOWS ONLY!
- Download the [NXHKSYSTEM.zip](https://github.com/Nixhekoo/NXHKSYSTEM/archive/refs/heads/main.zip)
- If the browser blocks the download for suspicion of a Virus, click "Download Anyways" *(This is because you are downloading Standalone Executable File)*
- *(If While trying to run the game Windows Defender blocks the file, click "More Information" and "Run Anyways")*
- *(If Windows Antivirus blocks the file, disable antivirus or allow the file to be downloaded)*
- Place the Header anywhere you want <br>
## How to include the header (3 Ways)
1. In your main project file, include the file by typing in the PATH to the file like this:
```
#include "C:\Users\Admin\Documents\Headers\NXHKSYSTEM.hpp"
```
2. If you are gonna place the header file in same directory as the main file, you can use this:
```
#include "NXHKSYSTEM.hpp"
```
3. If you are gonna place the header file in same directory as the main file BUT in it's own specific folder, you can use this:
```
#include "Folder\NXHKSYSTEM.hpp"
```

# All Functions
### Set
  - NXHK_SET_CONSOLE_CURSOR_POSITION (X, Y)
  > Sets Console Cursor Position to X and Y Coordinates
  - NXHK_SET_CONSOLE_TITLE (TITLE)
  > Changes Console Title
  - NXHK_SET_FILE_DIRECTORY (PATH)
  > Creates path inside LocalAppData
  - NXHK_SET_CONSOLE_COLOR (COLOR NUMBER)
  > Changes Console Text Color
### Reset
  - NXHK_RESET_CONSOLE_CURSOR_POSITION
  > Sets Console Cursor Position to X = 0 and Y = 0
### Get
  - NXHK_GET_MOUSE_POSITION_X
  > Returns Mouse Position X
  - NXHK_GET_MOUSE_POSITION_Y
  > Returns Mouse Position Y
  - NXHK_GET_SCREEN_SIZE_X
  > Returns Screen Size on X
  - NXHK_GET_SCREEN_SIZE_Y
  > Returns Screen Size on Y
  - NXHK_GET_MONITORS_AMMOUNT
  > Returns Ammount of Monitors Connected
### Create
  - NXHK_CREATE_PATH (PATH)
  > Creates Directory Specified
  - NXHK_CREATE_ENCRYPT_SEED (ENCRYPT POWER, LOADING BAR LENGHT, LOADING BAR TEXT)
  > Creates Seed for Encryption and Decryption
### Check
  - NXHK_CHECK_IF_FILE_EXISTS (FOLDERPATH, FILENAME)
  > Checks if File Exists in your PC
### Convert
  - NXHK_CONVERT_TO_STRING
  > Converts Anything to String
  - NXHK_CONVERT_TO_INT
  > Converts String to Integer
  - NXHK_CONVERT_TO_BOOL
  > Converts String to Bool
  - NXHK_CONVERT_TO_FLOAT
  > Converts String to Float
  - NXHK_CONVERT_TO_CHAR
  > Converts String to Character
### Encrypt / Decrypt
  - NXHK_ENCRYPT_MESSAGE (MESSAGE, ENCRYPTSEED)
  > Encrypts Message using EncryptSeed
  - NXHK_DECRYPT_MESSAGE (MESSAGE, ENCRYPTSEED)
  > Decrypts Message using EncryptSeed
### Save / Load
  - NXHK_SAVE_TO_FILE (FOLDERPATH, FILENAME, CONTENT TO SAVE, LINE TO SAVE ON)
  > Saves Content to Specified File in Specified Directory on Specified Line
  - NXHK_LOAD_FROM_FILE (FOLDERPATH, FILENAME, LINE TO LOAD FROM)
  > Loads Content from Specified File in Specified Directory from Specified Line
