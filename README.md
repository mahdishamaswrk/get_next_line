# get_next_line

## Overview

**get_next_line** is a project from the 42 School curriculum that focuses on reading and returning a file one line at a time from a file descriptor.

The objective of this project is to understand static variables, memory management, file handling, and buffer manipulation in C.

The function allows programs to read text efficiently by retrieving each line individually without loading the entire file into memory.

## Features

The project includes:

* Reading files line by line
* Handling variable buffer sizes
* Dynamic memory allocation
* Proper memory management
* Managing file descriptors
* Bonus support for multiple file descriptors simultaneously

## Function Prototype

```c
char *get_next_line(int fd);
```

### Parameters

| Parameter | Description                  |
| --------- | ---------------------------- |
| `fd`      | File descriptor to read from |

### Return Value

* Returns the next line from the file descriptor
* Returns `NULL` when there is nothing left to read or an error occurs

## How It Works

The function reads data from a file descriptor using a buffer and stores the remaining content using a static variable.

Each call retrieves the next available line while keeping track of unread data for future calls.

This approach allows the function to continue reading from where it stopped without restarting the process.

## Bonus Part

The bonus version extends the project by supporting multiple file descriptors at the same time.

Example:

```c
get_next_line(fd1);
get_next_line(fd2);
get_next_line(fd1);
```

Each file descriptor maintains its own reading state, allowing multiple files to be processed independently.

## Compilation

Compile the project using:

```bash
make
```

This creates the library:

```text
get_next_line.a
```

Available Makefile commands:

```bash
make        # Compile the project
make bonus  # Compile bonus version
make clean  # Remove object files
make fclean # Remove object files and library
make re     # Recompile everything
```

## Usage

Include the header file:

```c
#include "get_next_line.h"
```

Compile your program with the source files:

```bash
cc main.c get_next_line.c get_next_line_utils.c
```

Example:

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd;
    char *line;

    fd = open("example.txt", O_RDONLY);

    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }

    close(fd);
    return (0);
}
```

## Project Structure

```text
get_next_line/
├── get_next_line.c
├── get_next_line_utils.c
├── get_next_line.h
├── get_next_line_bonus.c
├── get_next_line_utils_bonus.c
├── get_next_line_bonus.h
├── Makefile
└── README.md
```

## Concepts Learned

Through this project, I improved my understanding of:

* File descriptors
* Reading from files using system calls
* Static variables
* Memory allocation and freeing
* Buffer management
* Handling edge cases
* Writing efficient and reusable C code

## Challenges

The main challenges of this project were:

* Managing memory correctly to avoid leaks
* Handling lines of different sizes
* Keeping leftover data between function calls
* Supporting multiple file descriptors in the bonus part

## Author

Mahdi Shamas

