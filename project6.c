//Created by Ameya Bhujbal
//Netid-ameyabhujbal
//Desciption: Finding the statistics and the coastal land region using files.

#include <stdio.h>
int main(int argc,char *argv[])
{
    
//Opening the file
    FILE *fp;
    fp=fopen(argv[1],"r");
    //Checking if the file exists or not
    if(fp==NULL)
    {
        printf("File not found");
        return 1;
    }
    //Reading the 2 variables using the fscanf function
    int R,C;
    fscanf(fp,"%d %d",&R,&C);
    //Reading rows and col bounds from file passed.
    
    //Declaring a character array with 2 dimensions.
    char buffer [R][C];
    char str[R][C];
    int i=0;
    int wcount=0;
    
    //Reading the input into the character array while there is no error till the end of the file.
    while(!(feof(fp) && !(ferror(fp))))
    {
        fscanf(fp,"%s",buffer[i]);
        i++;
    }
    //Using for loops printing Y if Land is near coastal area. Printing W if water area.
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            if(buffer[i][j]=='W')
            {
                str[i][j]='N';
            }
            else if(buffer[i+1][j]=='L' && buffer[i-1][j]=='L' && buffer[i][j+1]=='L' && buffer[i][j-1]=='L')
                {
                    str[i][j]='N';
                  }
            else
            {
                str[i][j]='Y';
            }
            if((i==0||i==(R-1))||(j==0||j==(C-1)))
            
            {
                if(buffer[i][j]=='L')
                {
                    str[i][j]='Y';
                }
                else
                {
                str[i][j] = 'N';
                }
            }
            
        }
    }
    
    //Closing the first file.
    fclose(fp);
    //Taking another file pointer
    FILE *fp2;
    //Opening the coast file.
    fp2=fopen("coast.txt","w");
    
    //Writing all the data into the coast file and printing in it.
    
        for(int i=0;i<(R);i++)
        {
            for(int j=0;j<(C);j++)
            {
                fprintf(fp2,"%c",str[i][j]);
            }
            fprintf(fp2,"\n");
        }
    
    //Closing the second file.
    fclose(fp2);
    
    //For the statistics
    FILE *fp3;
    fp3=fopen("statistics.txt","w");
    int area=0;
    int cnt=0;
    
    //Calculating the total area
    
    area=(R*C);
    fprintf(fp3,"TOTAL AREA: %d\n",area);
    
    //Calculating the Land area.
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<R;j++)
        {
            if(buffer[i][j]=='L')
            {
                cnt++;
            }
            else
            {
                continue;
            }
            
            //Calculating the wet perimeter.
            if(buffer[i][j]=='W')
            {
                            continue;
            }
            else
            {
                if(i==0||i==(R-1)||j==0||j==C-1)
                    {
                        if(buffer[i+1][j]!='L'||buffer[i-1][j]!='L'||buffer[i][j+1]!='L'||buffer[i][j-1]!='L')
                            {
                                wcount++;
                            }
                    }
                else
                    {
                        if(buffer[i+1][j]!='L'||buffer[i-1][j]!='L'||buffer[i][j+1]!='L'||buffer[i][j-1]!='L')
                        {
                                wcount++;
                        }
                    }
            }
        }
    }
    fprintf(fp3,"TOTAL LAND AREA: %d\n",cnt);
    fprintf(fp3,"WET PERIMETER: %d\n",wcount);
    fclose(fp3);
}
    
    
