/* Name:Ameya Bhujbal
   NetID: U55713417
   Description:Program to fix the bug in the facility using loops
*/


#include <stdio.h>
int main(void)
{	//Declaring the variables needed to compute

	int N,M,L,E,current=0,max=0;

	// Enter the no of lines in the log file and the max capacity of the facility.
	scanf("%d %d ",&N,&M);
	
	//Checking if the no of lines in the log file and the max capacity does not exceed 1000.

	if(N>1000 || M>1000)	
        {
                printf("Incorrect values");
        }


	for(int i=0;i<N;i++)

		{
			//Entering the no of people entering and leaving the facility.
			
			scanf("%d %d ",&L,&E);
			// Checking if the ppl entering and leaving the facility do not exceed 1000.
			if((L>1000) || (E>1000))
			{
				printf("Incorrect values");
			}
			//Customers leaving the facility
			current-=L;
			//Customers entering the facility
			current+=E;
			if(current>max)
			{
				max=current;
			}
		}
	//Checking if the no of customers exceeds the capacity of the facility.
	if(max>M)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
return 0;
}

