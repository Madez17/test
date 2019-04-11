.\" This is the manpage of simple_shell and how this function                                                          
.TH simple_shell "11/04/19" "VI" "simple_shell man page"                                                        
                                                                                                     
.SH NAME                                                                                              
Simple_Shell - format and print data                                                                                             
                                                                                                     
.SH SYNOPSIS                                                                                          
simple_shell  FORMAT [ARGUMENT]

#include <stdio.h> | 
#include <stdlib.h> |
#include "holberton.h"
                                                                                                     
.SH DESCRIPTION

This is  printf function that performs in a very similar way to the printf function of c.    
Upon successful return, these functions return the number of characters printed (excluding the null byte used to end output to strings).

FORMAT controls the output  as in c printf. Interpreted sequences are:
                                                                                                     
.SH OPTIONS                                                                                          
.IP -n                                                                                               
New line                                                                                                
.IP --%                                                                                                
a single %
.IP --%s
print string.
.IP --%c
print only char
.IP --%i
takes integer value as integer value with decimal, hexadecimal or octal type.
.IP --%d
takes integer value as signed decimal integer i.e. it takes negative values along with positive values but values should be in decimal otherwise it will print garbage value.
                                                                                                     
.SH BUGS                                                                                              
 GNU coreutils online help: <http://www.gnu.org/software/coreutils/>
 Report printf translation bugs to <http://translationproject.org/team/>
                                                                                                     
.SH AUTHOR
Written by Maria Fernanda Mendez & Diego Orjuela
