/*NAME: Ameya Bhujbal
 NET ID: ameyabhujbal
 DESCRIPTION: To find the longest increasing subsequence within a given threshold.*/


#include <stdio.h>
//Defining a function LIS to compute the longest increasing subsequence.
void LIS(int *foo,int T,int n)
{
    int max=0;
    
    //Traversing the array using pointers
    for(int i=0;i<n;i++)
    {
        int cnt=0;
        
        for(int j=i+1;j<n;j++)
        {
            /*Finding the difference of the maximum and minimum elements and checking if it is
             less than the threshold value*/
            
            if((*(foo+j)-*(foo+i))<T)
            {
                cnt++;
            }
            else
            {
                break;
            }
        }
            if(max<cnt)
            {
                 max=cnt;
            }
        
        }
    printf("%d\n",(max+1));
}

//Main function.
int main()
{
    int no_of_elements,threshold;
    int *p; //Pointer
    //Entering the size and the threshold value.
    scanf("%d %d",&no_of_elements,&threshold);
    
    //Checking if all nos in the sequence are non-negative numbers smaller than or = 10^6
    if((no_of_elements<1 || no_of_elements>1000) && (threshold<1 || threshold>1000000))
        {
        printf("Invalid Input");
        }
    int x[no_of_elements];
    p=&x[0];
    //Adding the elements in the array
    for(int i=0;i<no_of_elements;i++)
    {
        scanf("%d",(p+i));
    }
    //Calling the function.
    LIS(p,threshold,no_of_elements);
}


