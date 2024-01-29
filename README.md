<h1 align="center">
	Get_Next_Line
</h1>

<p align="center">
	:information_source: Reading a line on a fd is way too tedious
</p>
<p align="center"><a href="https://www.42porto.com" target="_blank"><img src="https://img.shields.io/static/v1?label=&message=Porto&color=000&style=for-the-badge&logo=42""></a></p>
<p align="center"><img src="https://github.com/Bruno0798/Bruno0798/blob/main/42-project-badges/badges/get_next_linee.png?raw=true"> </p>
<p align="center"> <strong>112/100</strong> ✅ </p>

<p align="center">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/bruno0798/get_next_line?color=blueviolet" />
	<img alt="Code language count" src="https://img.shields.io/github/languages/count/bruno0798/get_next_line?color=blue" />
  <img alt="GitHub top language" src="https://img.shields.io/github/languages/top/bruno0798/get_next_line?color=blue" />
	<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/bruno0798/get_next_line?color=brightgreen" />
</p>

---

## Description

The `get_next_line` project is a programming assignment designed to enhance your understanding of file descriptor manipulation and memory management in the C programming language. The goal is to implement a function that reads a line from a file descriptor, such as a file or standard input, and returns that line without the newline character.

> ⚠️ **Warning**: Don't copy/paste code you don't understand: it's bad for you, and for the school.

## Table of Contents

- [Requirements](#requirements)
- [Usage](#usage)
- [Function Prototype](#function-prototype)
- [Example](#example)
- [Notes](#notes)
- [Norminette](#norminette)
- [License](#license)

## Requirements

To use or test the `get_next_line` function, you should have a working knowledge of the C programming language. The project may have specific requirements based on the course or institution where it is assigned.

## Usage

**1. Clone the repository:**

```bash
git clone https://github.com/bruno0798/get_next_line.git
```

**2. Using it in your code**

To use the function in your code, simply include its header:

```C
#include "get_next_line.h"
```

and, when compiling your code, add the source files and the required flag:

```shell
get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=<size>
```

> ⚠️ **Warning:** If you don't have your own libft library, you need to download mine <a href="https://github.com/Bruno0798/42_libft">42_Libft</a>. Ensure the libft is available in the specified path, and adjust the compilation command accordingly.

## Function Prototype
```c
int	get_next_line(int fd, char **line);
```

## Example

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd = open("example.txt", O_RDONLY);
    char *line;

    while (get_next_line(fd, &line) > 0)
    {
        printf("%s\n", line);
        free(line);
    }

    close(fd);
    return 0;
}
```

 **Return value**
 | Value | Description         |
 |-----------|----------------------|
 |  1| A line has been read |
 |  0| EOF has been reached |
 |  -1| An error happened |


## Notes

This project may have specific requirements depending on the course or institution.
Ensure proper memory management to avoid memory leaks.
Handle errors and edge cases appropriately.

## NORMINETTE
At 42 School, aligning to the [42 Norms](en_norm.pdf), the school's coding standard, is a fundamental expectation for all projects.

## License

This project is licensed under the MIT License.
