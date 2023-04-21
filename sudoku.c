
/* Name:Ameya Bhujbal
UID: U55713417
NETID: ameyabhujbal
Description: to check if a sudoku is valid or not.
*/



#include <stdio.h>

//Defining N as a constant. This value will be used in the array because sudoku has dimensions 9x9.
#define N 9

int sudoku[N][N];

//Function 1: Input.
//Description:Inputting numbers into the array.

int input()
{
    for(int row=0;row<N;row++)
    {
        for(int col=0;col<N;col++)
        {
            scanf("%d",&sudoku[row][col]);
        }
    }
    return 0;
}

//Function 2: Row check
/*Description: Check if the row in the sudoku is valid or not. It should contain the values from 1-9.
               The nos can be in any order and cannot be repetitive. */

int row_check()
{
    // Declaring another 1-D array named temp. Every value in temp is 0.
    int temp[10]={0};
    
    for(int row=0;row<N;row++)
    {
        for(int col=0;col<N;col++)
            {
                temp[sudoku[row][col]]++;
            }
    
    for(int k=1;k<=N;k++)
            if(temp[k]!=1)
            {
                return 0;
            }
    
    for(int k=1;k<=N;k++)
            temp[k]=0;
    }
    return 1;
}

//Function 3: Column Check
/* Description: Check if the column in the sudoku is valid or not. It should contain the values of 1-9
                The numbers can be in any order and cannot be repetitive.*/

int col_check()
{
    int temp[10]={0};
    
    for(int row=0;row<N;row++)
    {
        for(int col=0;col<N;col++)
        {
            temp[sudoku[col][row]]++;
        }
        
        
        for(int k=1;k<=N;k++)
            if(temp[k]!=1)
            {
                return 0;
            }
        
        
        for(int k=1;k<=N;k++)
            temp[k]=0;
    }
    return 1;
}

//Function 4: Block check
/*Description: Check if the 3x3 block in the sudoku is valid or not. It should contain the values between 1-9
                The numbers cannot repeat.*/

int block_check()
{
    int temp[10]={};
    int cnt=0;
    
    for(int i=0; i<N;i+=3)
    {
        for(int j=0;j<N;j+=3)
        {
            for(int row=i;row<i+3;row++)
            {
                for(int col=j;col<j+3;col++)
                {
                    temp[sudoku[row][col]]++;
                }
            }
            
            cnt++;
            
            for(int k=1;k<=N;k++)
                if(temp[k]!=1)
                {
                    return 0;
                }
            for(int k=1;k<=N;k++)
                temp[k]=0;
        }
    }
    return 1;
}

//Main function
int main(void)
{
    input();
    if(row_check()==1 && col_check()==1 && block_check()==1)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
    return 0;
}
