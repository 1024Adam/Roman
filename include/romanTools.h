/* romanTools.h */
/* Author: Adam Reid */
/* Number - Roman Numeral Converter */
/*
The program takes in a user entered number, and converts the number to roman 
numerals.
*NOTE: The program will not convert any decimals, and will convert words to ""
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Function converts an input number to roman numerals */
void convertToRoman();
/* Function gets an integer value from the user; returns the integer */
int getInputNum();
/* Function calculates how many digits are in the number, returns the number of
digits */
int getLengthOfNum(int inputNum);
/* Function takes a number, and converts it to roman numerals; returns the roman
numeral *NOTE: must free the returned character pointer*/
char * convertNum(int inputNum);

