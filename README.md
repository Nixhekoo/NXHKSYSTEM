<div align="center">
<h1 align=center>Nixhekoo's File System</h1>
• [0] About the Header <br>
• [1] How to Use <br>
• [2] Main Functions Explained <br>
• [3] Side Functions Explained <br>

</div>

# About the Header
- A helpful header for people who don't know how to properly save their game in C++. This header will help you with all file managment you would ever need when saving data to files in your PC.

# How to Use
- THE HEADER IS WINDOWS ONLY!
- Download the [NXHK_FILESYSTEM.zip](https://github.com/Nixhekoo/NXHK_FILESYSTEM/archive/refs/heads/main.zip)
- If the browser blocks the download for suspicion of a Virus, click "Download Anyways" *(This is because you are downloading Standalone Executable File)*
- *(If While trying to run the game Windows Defender blocks the file, click "More Information" and "Run Anyways")*
- *(If Windows Antivirus blocks the file, disable antivirus or allow the file to be downloaded)*
- Place the Header anywhere you want <br>
## How to include the header (3 Ways)
1. In your main project file, include the file by typing in the PATH to the file like this:
```
#include "C:\Users\Admin\Documents\Headers\NXHK_FILESYSTEM.hpp"
```
2. If you are gonna place the header file in same directory as the main file, you can use this:
```
#include "NXHK_FILESYSTEM.hpp"
```
3. If you are gonna place the header file in same directory as the main file BUT in it's own specific folder, you can use this:
```
#include "Folder\NXHK_FILESYSTEM.hpp"
```

# Main Functions Explained
> [!IMPORTANT]
> ***Explanation & The Correct Types!*** <br>
> <br>
> ***PathToFolder*** = String <br>
> ***FileName*** = String <br>
> ***ContentToSave*** = Any Type <br>
> ***LineToSaveOn*** = Integer <br>
1. PathToFolder = *This is the path to the folder where you want your files to be saved in. If you want to have your files saved in localappdata of Windows, use the [NXHK_FILEDIR](https://github.com/Nixhekoo/NXHK_FILESYSTEM?tab=readme-ov-file#nxhk_filedir) function*
2. FileName = *This is the name of the file where the data should be stored. The data can be stored in almost any file type.*
3. ContentToSave = *This is the content you want to save. If you dont like converting types to string, use the [NXHK_TOSTRING](https://github.com/Nixhekoo/NXHK_FILESYSTEM?tab=readme-ov-file#nxhk_tostring) function to help you*
4. LineToSaveOn = *This is the specified line by user, that determines on which line you want to save the ***ContentToSave***.*

## NXHK_SAVE 💾
- The syntax for this function is as follows:
```
NXHK_SAVE(PathToFolder, FileName, ContentToSave, LineToSaveOn);
```

## NXHK_LOAD 💾
- The syntax for this function is as follows:
```
std::string TestVariable;
TestVariable = NXHK_LOAD(PathToFolder, FileName, LineToSaveOn);
```
- This function will return the value of the Line from the specified File as String. 

# Side Functions Explained
## NXHK_TOSTRING
- The correct syntax for this function is:
```
NXHK_TOSTRING(AnythingYouWant);
```
- The correct syntax to use this function inside ***NXHK_SAVE*** is:
```
NXHK_SAVE(PathToFolder, FileName, NXHK_TOSTRING(ContentToSave), LineToSaveOn);
```
1. AnythingYouWant = You can enter information of any data type and it will get converted to String. Useful for NXHK_SAVE

## NXHK_FILEDIR
- The correct syntax for this function is:
```
NXHK_FILEDIR(PathFromLocalappdata);
```
- The correct syntax to use this function inside ***NXHK_SAVE*** or ***NXHK_LOAD*** is:
```
// SAVE FUNCTION
NXHK_SAVE(NXHK_FILEDIR(PathToFolder), FileName, ContentToSave, LineToSaveOn);

// LOAD FUNCTION
std::string TestVariable;
TestVariable = NXHK_LOAD(NXHK_FILEDIR(PathToFolder), FileName, LineToSaveOn);
```
1. PathFromLocalappdata = This is the path that will be placed in Localappdata of Windows. For example this:
```
NXHK_FILEDIR(Projects\Folder);
```
Will create Path like this:
```
C:\Users\Admin\AppData\Local\Projects\Folder
```
> [!IMPORTANT]
> Do NOT use backslash at the beginning of the Path, that will be automatically added by the function!

# Combining The Functions
- You can also combine multiple functions into one. (Atleast those that are compatibile with eachother). As of right now, only NXHK_SAVE and NXHK_LOAD are compatibile with other functions.
```
// SAVE FUNCTION
NXHK_SAVE(NXHK_FILEDIR(PathToFolder), FileName, NXHK_TOSTRING(ContentToSave), LineToSaveOn);

// LOAD FUNCTION
std::string TestVariable;
TestVariable = NXHK_LOAD(NXHK_FILEDIR(PathToFolder), FileName, LineToSaveOn);
```
