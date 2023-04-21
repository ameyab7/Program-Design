/*Name: Ameya Bhujbal
 NetID: ameyabhujbal
 Description:Building a code to update the database of animals in the zoo.
 */


#include <stdio.h>
#define MAX_LEN 200
#define MAX_SIZE 200
#include <string.h>
#include <stdlib.h>

//Defining a struct species which stores the database of the current animals in the zoo.
struct species
{
    char name[MAX_LEN+1];
    char location[MAX_LEN+1];
    int quantity;
};

//Defining another struct named logfile that stores the content of the logfile.
struct logfile
{
    char name[MAX_LEN+1];
    char operation[MAX_LEN+1];
    char location1[MAX_LEN+1];
    char location2[MAX_LEN+1];
    int quantity_log;
};

//Main function. All operations performed here
int main(int argc, char *argv[])
{
    
    //I have opened the file containing the names of the animals and their location and quantity
    FILE *fp=fopen(argv[1],"r");
    
    //Struct array 1
    struct species database[200];
    if(fp==NULL)
    {
        printf("File not found!");
        return 1;
    }
    int i=0;
    //I have taken a counter to count the number of lines.I printed it code is working properly up till here.
    int count=0;
    while(!feof(fp) && !ferror(fp) && (i<201))
    {
        fscanf(fp,"%[^,] ,%[^,] ,%d\n",database[i].name,database[i].location,&database[i].quantity);
        i++;
        count++;
    }
    //I printed the content of the file and code is working properly up till here.
    
    //I am opening the second file to scan the contents of the log file into my struct array.
    FILE *fp2=fopen(argv[2],"r");
    
    //Struct array 2
    struct logfile logdata[200];
    if(fp2==NULL)
    {
        printf("File not found!");
        return 1;
    }
    
    
    int j=0;
    //Variables used to store the value obtained from the logfile
    char name[MAX_LEN],name2[MAX_LEN],name3[MAX_LEN],name4[MAX_LEN],born[MAX_LEN],died[MAX_LEN],location[MAX_LEN],location2[MAX_LEN],arriving[MAX_LEN],going[MAX_LEN];
    int born_convert,died_convert,arriving_in,going_out;
    //Variables for death function.
    while(!feof(fp2) && !ferror(fp2))
    {
        //Using strtok and fgets I extract the first line and word uptill the ",".
        fgets(logdata[j].operation,MAX_LEN+1,fp2);
        strtok(logdata[j].operation,",");
        
        //Performing the birth operation
        if(strcmp(logdata[j].operation,"birth")==0)
        {
            strcpy(name,strtok(NULL,","));
            strcpy(born,strtok(NULL,","));
            born_convert=atoi(born);
            for(int i=0;i<count;i++)
            {
                if(strcmp(database[i].name,name)==0)
                {
                    database[i].quantity+=born_convert;
                }
            }
        }
        //Performing the death operation, removing the array if value is 0 else just decrementing it.
        else if(strcmp(logdata[j].operation,"death")==0)
        {
            strcpy(name2,strtok(NULL,","));
            strcpy(died,strtok(NULL,","));
            died_convert=atoi(died);
            
            for(int i=0;i<count;i++)
            {
                if(strcmp(database[i].name,name2)==0)
                {
                    database[i].quantity-=died_convert;
                    if(database[i].quantity<=0)
                    {
                        for(int p=i;p<count;p++)
                        {
                            database[p]=database[p+1];
                        }
                        count--;
                        break;
                    }
                    
                }
            }
            
        }
        //Performing the transfer in operation, adding value to present species else adding new species.
        else if(strcmp(logdata[j].operation,"transfer_in")==0)
        {
            int flag=0;
            strcpy(name3,strtok(NULL,","));
            strcpy(location,strtok(NULL,","));
            strcpy(arriving,strtok(NULL,","));
            arriving_in=atoi(arriving);
            
            //Values stored above now just comparing and evaluating.
            for(int i=0;i<count;i++)
            {
                if(strcmp(database[i].name,name3)==0)
                {
                    database[i].quantity+=arriving_in;
                    break;
                }
                flag++;
                
            }
            if(flag==count)
            {
                strcpy(database[flag].name,name3);
                strcpy(database[flag].location,location);
                database[flag].quantity=arriving_in;
                count++;
            }
            
        }
        
        //transfer out function same as the death function.
        else if(strcmp(logdata[j].operation,"transfer_out")==0)
        {
            strcpy(name4,strtok(NULL,","));
            strcpy(going,strtok(NULL,","));
            going_out=atoi(going);
            for(int i=0;i<count;i++)
            {
                if(strcmp(database[i].name,name4)==0)
                {
                    database[i].quantity-=going_out;
                    if(database[i].quantity<=0)
                    {
                        for(int p=i;p<count;p++)
                        {
                            database[p]=database[p+1];
                        }count--;
                        break;
                    }
                }
            
            }
        }
        
        //Performing the relocate function if only to change the locations
        else if(strcmp(logdata[j].operation,"relocate")==0)
        {
            strcpy(location,strtok(NULL,","));
            strcpy(location2,strtok(NULL,"\n"));
            for(int i=0;i<count;i++)
            {
                if(strcmp(database[i].location,location)==0)
                {
                    strcpy(database[i].location,location2);
                }
            }
        }
        j++;
    }

    
    
    //Printing the updated array content into the database file using fprintf.
    FILE *fp3=fopen("database.txt","w");
    if(fp3==NULL)
    {
        printf("Database input file not found");
    }
    
    for(int i=0;i<count;i++)
    {
        
        fprintf(fp3,"%s,%s,%d\n",database[i].name,database[i].location,database[i].quantity);
    }
}





