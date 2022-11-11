// extEvenDigits
//  Write a function that extracts the even digits from a positive number, and combines the even digits sequentially into a new number. The new number is returned to the calling function. If the input number does not contain any even digits, then the function returns ‐1. For example, if the input number is 1234567, then 246 will be returned; and if the input number is 13, then –1 will returned. You do not need to consider the input number such as 0, 10, 3033, etc. Write the function in two versions. The function extEvenDigits1() returns the result to the caller, while the function extEvenDigits2() returns the result through the pointer parameter, result. The function prototypes are given as follows:
// int extEvenDigits1(int num);
// void extEvenDigits2(int num, int *result);

// Some sample input and output sessions are given below:

// (1) TestCase1:
// Enter a number: 1234 extEvenDigits1(): 24 extEvenDigits2(): 24

// (2) TestCase2: Enter a number: 1357

// extEvenDigits1(): ‐1 extEvenDigits2(): ‐1

// (3) TestCase3:
// Enter a number:
// 2468 extEvenDigits1(): 2468 extEvenDigits2(): 2468

// (4) TestCase4:
// Enter a number:
// 6 extEvenDigits1(): 6 extEvenDigits2(): 6

#include <stdio.h>
#define INIT_VALUE 999
int extEvenDigits1(int num);
void extEvenDigits2(int num, int *result);
int main()
{
   int number, result = INIT_VALUE;
   
   printf("Enter a number: \n");
   scanf("%d", &number);
   printf("extEvenDigits1(): %d\n", extEvenDigits1(number));        
   extEvenDigits2(number, &result);
   printf("extEvenDigits2(): %d\n", result);
   return 0;
}




int extEvenDigits1(int num) 
{ 
    int ar[10];
    int i,j=0;
//Append even digits to array
    while (num>1)
    {
        if (num%2==0)
        {
            ar[j] = num%10;
            j++;
        }
        num = num/10;
    }
    ar[j]='\0';

    if (j==0)
    {
        return -1;
    }
//Arrange array in ascending order
    int newar[10], min;
    
    min=10; j=0;
    while (min!=9)
    {
        min=10;
        for (i=0;ar[i]!='\0';i++)
        {
            if (ar[i]<min)
            {
                min = ar[i];
            }
        }
        
        if (min!=9)
        {
            newar[j] = min;
            j++;
        }
        
        for (i=0;ar[i]!='\0';i++)
        {
            if (ar[i]==min)
            {
                ar[i]=9;
            }
        }
    }
    newar[j] = '\0';
//Loop through array, re-append array elements and convert it to number. Return number
    int x = 1,placeholder,digit=0;
    for (i=j-1;i>=0;i--)
    {
        placeholder = newar[i]*x;
        x=x*10;
        digit+=placeholder;
    }
    return digit;
}



void extEvenDigits2(int num, int *result) 
{  
    int ar[10];
    int i,j=0;
//Append even digits to array
    while (num>1)
    {
        if (num%2==0)
        {
            ar[j] = num%10;
            j++;
        }
        num = num/10;
    }
    ar[j]='\0';

    if (j==0)
    {
        *result = -1;
    }
//Arrange array in ascending order
    int newar[10], min;
    
    min=10; j=0;
    while (min!=9)
    {
        min=10;
        for (i=0;ar[i]!='\0';i++)
        {
            if (ar[i]<min)
            {
                min = ar[i];
            }
        }
        
        if (min!=9)
        {
            newar[j] = min;
            j++;
        }
        
        for (i=0;ar[i]!='\0';i++)
        {
            if (ar[i]==min)
            {
                ar[i]=9;
            }
        }
    }
    newar[j] = '\0';
//Loop through array, re-append array elements and convert it to number. Return number
    int x = 1,placeholder,digit=0;
    for (i=j-1;i>=0;i--)
    {
        placeholder = newar[i]*x;
        x=x*10;
        digit+=placeholder;
    }
    *result = digit;
}

