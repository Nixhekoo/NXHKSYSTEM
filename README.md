<div align="center">
<h1 align=center>Nixhekoo's File System</h1>
• [0] About the Header <br>
• [1] How to Use <br>
• [2] Main Functions Explained <br>
• [3] Side Functions Explained <br>
• [4] Source Code <br>

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
- There are many functions that i think should be well explained so you know how to use the header properly and to it's full potential. Lets start off with the Save function.
## NXHK_SAVE
- The syntax for this function is as follows:
```
NXHK_SAVE(<PathToFolder>, <FileName>, <ContentToSave>, <LineToSaveOn>);
```
> [!IMPORTANT]
> ***Use the Correct Types!*** <br>
> <br>
> ***PathToFolder*** = String <br>
> ***FileName*** = String <br>
> ***ContentToSave*** = Any Type <br>
> ***LineToSaveOn*** = Integer <br>
1. PathToFolder = This is the path to the folder where you want your files to be saved in.
2. FileName = This is the name of the file where the data should be stored. The data can be stored in almost any file type.
3. ContentToSave = This is the content you want to save. It is supposed to be String only but you can use [NXHK_TOSTRING](https://github.com/Nixhekoo/NXHK_FILESYSTEM?tab=readme-ov-file#nxhk_tostring)

# Side Functions Explained
## NXHK_TOSTRING
- The correct syntax for this function is:
```
NXHK_TOSTRING(<AnythingYouWant>);
```
1. AnythingYouWant = You can enter information of any variable type and it will get converted to String. Useful for NXHK_SAVE

## Source Code
- Click on this: [NXHK_FILESYSTEM.zip](https://github.com/Nixhekoo/NXHK_FILESYSTEM/archive/refs/heads/main.zip)
