#include "romanTools.h"

void convertToRoman()
{
    char * convert;
    int inputNum = 0;

    printf("Roman Numeral Converter\n");

    inputNum = getInputNum();
    convert = convertNum(inputNum);
    printf("> %s\n", convert);

    printf("\nPress enter to continue...");
    getchar();

    free(convert);
}

int getInputNum()
{
    char buffer[50];
    int inputNum = 0;
    int goodNum = 1;
    int i = 0;

    printf("Please enter an integer value:\n> ");
    /* Loop until the entered number is valid */
    do
    {
        goodNum = 1;
        fgets(buffer, 50, stdin);

        if(strcmp(buffer, "\n") == 0)
        {
            goodNum = 0;
        }

        i = 0;
        while(goodNum && buffer[i] != '\n')
        {
            /* Confirm that each character is a digit */
            if(isdigit(buffer[i]) == 0)
            {
                goodNum = 0;
            }
            i++;
        }

        if(strtol(buffer, NULL, 10) >= 100000)
        {
            goodNum = 0;
            printf("Please no number bigger than 100000.");
        }

        if(!goodNum)
        {
            printf("\nPlease enter an integer value only:\n> ");
        }
    }
    while(!goodNum);

    inputNum = strtol(buffer, NULL, 10);
    /*printf("%d\n", inputNum);*/

    return(inputNum);
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
