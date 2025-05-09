# Simple Line Editor

## Description

This program implements a simple command-line-based line editor, written in C++. It allows users to create, modify, and navigate through a list of text lines. The editor operates on a file specified via a command-line argument, loading its content, allowing modifications, and saving changes back to the file upon exit.

## Features

The line editor supports the following commands:

* **`I` (Insert):** Inserts a new line of text after the current line.
* **`D` (Delete):** Deletes the current line.
* **`L` (List):** Prints the entire list of text lines, each preceded by its line number.
* **`P` (Previous):** Moves the current line pointer to the previous line in the list.
* **`N` (Next):** Moves the current line pointer to the next line in the list.
* **`E` (Exit):** Saves all changes made during the session to the input file and terminates the program.

The editor also displays the current line number as a prompt (`<line#>`) and provides feedback messages for various operations.

## File Structure

The project consists of the following key components:

* **`editor.cpp` (Client Program):** This is the main program file that handles user interaction, command parsing, and overall program flow. It utilizes the `LineList` class to manage the text lines.
* **`LineList.h` (Specification File):** This header file defines the `LineNode` struct and the interface for the `LineList` class.
    * **`LineNode` struct:** Represents a node within the doubly-linked list. Each node stores:
        * `info`: A string containing the text of the line.
        * `next`: A pointer to the next `LineNode` in the list.
        * `back`: A pointer to the previous `LineNode` in the list.
    * It also defines string constants `topMessage` and `bottomMessage` and includes `<string>`.
* **`LineList.cpp` (Implementation File):** This file contains the implementation of the `LineList` class methods.

## Core Data Structure: `LineList` Class

The `LineList` class is responsible for managing the collection of text lines using a doubly-linked list.

### Private Members:

* **`currLine` (`LineNode*`):** A pointer to the `LineNode` representing the current line in the list.
* **`currLineNum` (`int`):** An integer storing the line number of the `currLine`.
* **`length` (`int`):** An integer representing the total number of lines in the list.

### Public Member Functions (Operations):

* **`goToTop()`:** Moves `currLine` to the first line of the list.
* **`goToBottom()`:** Moves `currLine` to the last line of the list.
* **`insertLine(const std::string& newLine)`:** Inserts a new line containing `newLine` after the current line.
* **`deleteLine()`:** Deletes the line pointed to by `currLine`. The `currLine` is then typically updated to the next line, or the previous if the deleted line was the last.
* **`printList()`:** Displays all lines in the list to the console, along with their line numbers.
* **`getCurrLine() const` (`std::string`):** Returns the text content of the `currLine`.
* **`moveNextLine()`:** Advances `currLine` to the next line in the list.
* **`movePrevLine()`:** Moves `currLine` to the previous line in the list.
* **`getCurrLineNum() const` (`int`):** Returns the current line number (`currLineNum`).
* **`getLength() const` (`int`):** Returns the total number of lines in the list (`length`).

## Input/Output

* **Input File:** The program expects a filename as a command-line argument (e.g., `argv[1]`). This file (`testfile` in the original description) is opened, and its contents are read line by line into the `LineList`.
* **User Input:** Users interact with the editor by typing single-character commands followed by Enter. If a command requires further input (e.g., 'I' for inserting a line), the program will prompt for it.
* **Output:**
    * The editor displays the current line number as a prompt (e.g., ``).
    * Feedback messages are provided for actions (e.g., upon successful insertion or deletion).
    * The `L` command prints the entire list.
* **Output File:** When the 'E' command is issued, all modifications are written back to the original input file.

## Program Flow

1.  **Initialization:** The client program (`editor.cpp`) reads the filename from the command-line arguments.
2.  **File Loading:** The specified file is opened, and its content is read line by line. Each line is inserted into a `LineList` object.
3.  **Initial State:** After loading, the `printList()` method is called to display the initial content, and `goToBottom()` sets the current line to the last line of the file.
4.  **Command Loop:** The program enters a loop, prompting the user for commands. A `switch` statement handles the different commands ('I', 'D', 'L', 'P', 'N', 'E').
5.  **Saving and Exiting:** The 'E' command triggers the `finishUp()` method (or equivalent logic), which writes the current state of the `LineList` back to the input file and then terminates the program.Client Program Goal: The goal of the client program is to provide a simple line editor that allows users to manipulate a list of text lines through certain commands. For instance, users can insert and delete lines, print the list, move through the list, and exit to save the changes to a file. 

## How to Compile and Run

### Prerequisites

* A C++ compiler that supports C++11 or later (e.g., GCC g++, Clang).
* Standard C++ libraries.

### Compilation

To compile the program, you will typically compile `editor.cpp` and `LineList.cpp` and link them together. 

```bash
g++ editor.cpp LineList.cpp -o line_editor -std=c++11
./a.out testfile
```

## License
 No license has been provided for this project
