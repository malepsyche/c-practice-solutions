// Write a function compress2D() that takes as input a square 2‐dimensional array of binary data, compresses each row of the array by replacing each run of 0s or 1s with a single 0 or 1 and the number of times it occurs, and prints on each line the result of compression. For example, the row with data 0011100011 may be compressed into 02130312. The prototype of the function is given as follows:
// void compress2D(int data[SIZE][SIZE], int rowSize, int colSize);

// Some sample input and output sessions are given below:
// (1) TestCase1:
// Enter the array size (rowSize, colSize): 44
// Enter the matrix (4x4):
// 1110
// 0011
// 1111
// 0000
// compress2D():
// 1301
// 0212
// 14
// 1
// 04

// (2) TestCase2:
// Enter the array size (rowSize, colSize): 55
// Enter the matrix (5x5):
// 11100
// 00111
// 11111
// 00000
// 11111
// compress2D():
// 1302
// 0213
// 15
// 05
// 15

// (3) TestCase3:
// Enter the array size (rowSize, colSize): 55
// Enter the matrix (5x5):
// 00000
// 11111
// 11111
// 00000
// 11111
// compress2D():
// 05
// 15
// 15
// 05
// 15

// (4) TestCase4:
// Enter the array size (rowSize, colSize): 10 10
// Enter the matrix (10x10): 1010101010
// 0101010101
// 1010101010
// 0101010101
// 1010101010
// 0101010101
// 1010101010
// 0101010101
// 1010101010
// 0101010101
// compress2D(): 11011101110111011101 01110111011101110111
// 2

// 11011101110111011101 01110111011101110111 11011101110111011101 01110111011101110111 11011101110111011101 01110111011101110111 11011101110111011101 01110111011101110111


#include <stdio.h>
#define SIZE 100
void compress2D(int data[SIZE][SIZE], int rowSize, int colSize);
int main() 
{
   int data[SIZE][SIZE];
   int i,j;
   int rowSize, colSize;

   printf("Enter the array size (rowSize, colSize): \n");
   scanf("%d %d", &rowSize, &colSize); 
   printf("Enter the matrix (%dx%d): \n", rowSize, colSize);  
   for (i=0; i<rowSize; i++)
      for (j=0; j<colSize; j++)
         scanf("%d", &data[i][j]);     
   printf("compress2D(): \n");
   compress2D(data, rowSize, colSize);
   return 0;
}
void compress2D(int data[SIZE][SIZE], int rowSize, int colSize) 
{
    int i,j=0,counter1=0,counter0=0;
    for (i=0;i<rowSize;i++)
    {
        j=0; 
        while (j<colSize)
            {
                if (data[i][j]==1)
                {
                    while ((data[i][j]==1)&&(j<colSize))
                    {
                        counter1+=1;
                        j++;
                    }
                    printf("1 "); printf("%d ", counter1);
                    counter1=0;
                }
                
                else if (data[i][j]==0)
                {
                    while ((data[i][j]==0)&&(j<colSize))
                    {
                        counter0+=1;
                        j++;
                    }
                    printf("0 "); printf("%d ", counter0);
                    counter0=0;
                }
            }
        printf("\n");
    }
}

//