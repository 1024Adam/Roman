#include "romanTools.h"

void convertToRoman(int argc, char * argv[])
{
    char * convert;
    int inputNum = 0;

    if (argc != 2)
    {
        printf("Usage: roman [NumberToConvert]\n");
	exit(0);
    }

    inputNum = strtol(argv[1], NULL, 10);
    convert = convertNum(inputNum);
    printf("%s\n", convert);

    free(convert);
}

int getLengthOfNum(int inputNum)
{
    int temp;
    int length;

    temp = 0;
    length = 0;

    temp = inputNum;
    /* Calculate the number of digits in the number */
    while(temp != 0)
    {
        temp /= 10;
        length++;
    }
    /*printf("%d\n", length);*/

    return(length);
}

char * convertNum(int inputNum)
{
    char * numerals[] = {"I", "V", "X", "L", "C", "D", "M"};

    char * convert;
    char romanNum[100] = "\0";
    char tempWord[100] = "\0";
    int temp = 0;
    int length = 0;
    int i = 0;
    int j = 0;

    length = getLengthOfNum(inputNum);

    do
    {
        /*printf("%s\n", romanNum);*/
        /*printf("%d\n", i);*/

        strcpy(tempWord, romanNum);
        strcpy(romanNum, "\0");

        if(i == 6)
        {
            /* If at the last roman numeral, print remaining numbers */
            /*printf("%d\n", inputNum);*/

            for(j = 0; j < inputNum; j++)
            {
                strcat(romanNum, numerals[i]);
            }
        }
        else
        {
            temp = inputNum % 10;
            /*printf("%d\n", temp);*/

            /* Condition: if the digit is 4 or 9 */
            if((temp % 5) == 4)
            {
                strcpy(romanNum, numerals[i]);
                strcat(romanNum, numerals[i + 1 + (temp / 5)]);
            }
            else
            {
                if(temp >= 5)
                {
                    strcpy(romanNum, numerals[i + 1]);
                    temp -= 5;
                }
                for(j = 0; j < temp; j++)
                {
                    strcat(romanNum, numerals[i]);
                }
            }
        }

        strcat(romanNum, tempWord);

        inputNum /= 10;
        length--;
        i += 2;
    }
    while(length != 0 && i <= 6);

    convert = malloc(sizeof(char)*(strlen(romanNum)+1));
    strcpy(convert, romanNum);

    return(convert);
}
