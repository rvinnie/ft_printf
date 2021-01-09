# ft_printf
My simplified printf implementation (project for School 21).
### Usage
Clone the repo  -> ```git clone https://github.com/rvinnie/libft```
 
Go into the cloned folder and run **make**.
This should create a file `libftprintf.a` (static library).  
To start using the library include the header file in your project: `#include "ft_printf.h"`
### Make
+ **make** -> compile and generate library
+ **make clean** -> remove objects
+ **make fclean** -> remove objects and generated library
+ **make re** -> re-compile
### What does this function supports?
|format specifiers  |flags|
|:-----------------:|:---:|
|cspdiuxX%          |-0.*|
