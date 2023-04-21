//Ameya Bhujbal
//Description: Zoo code into different files. Program Designing.
//netid: ameyabhujbal

#include <stdio.h>
#include <string.h>
#include "header.h"
#include <stdlib.h>

int main(int argc,char *argv[])
{
    struct species *first=NULL;
    struct logfile *lfirst=NULL;
    char name[1000],name2[1000],name3[1000],name4[1000],location[1000],arriving[1000]; int quantity,arriving_in;
    char born[1000]; int born_convert;
    char died[1000];int died_convert;
    char going_out[1000];int gone;
    char operation[1000],location2[1000];
    
    //Opening the first database file.
    FILE *fp=fopen(argv[1],"r");
    int count=0;
    
    //Scanning the database file and calling the function where input gets stored in linked list.
    while(!feof(fp) && !ferror(fp))
    {
        fscanf(fp, "%[^,],%[^,],%d\n", name,location, &quantity);
        first=insert_elements(first,name,location,quantity);
        count++;
    }
    
    //Opening the log file and scanning it. Fgets used here to extract the line and using strtok over ",".
    
    
    FILE *fp2=fopen(argv[2],"r");
    while(fgets(operation,sizeof(operation),fp2) && !feof(fp2) && !ferror(fp2))
    {
        strtok(operation,",");
        
        //Birth operation.
        if(strcmp(operation,"birth")==0)
        {
            strcpy(name,strtok(NULL,","));
            strcpy(born,strtok(NULL,","));
            born_convert=atoi(born);
            first=birth(first,name,born_convert);
        }
        
        //Death operation using the delete node method.
        
        else if(strcmp(operation,"death")==0)
        {
            strcpy(name3,strtok(NULL,","));
            strcpy(died,strtok(NULL,","));
            died_convert=atoi(died);
            first=death(first,name3,died_convert);
        }
        //Transfer_in operation.
        else if(strcmp(operation,"transfer_in")==0)
        {
            strcpy(name2,strtok(NULL,","));
            strcpy(location2,strtok(NULL,","));
            strcpy(arriving,strtok(NULL,","));
            arriving_in=atoi(arriving);
            first=transfer_in(first,name2,location2,arriving_in);
        }
        
        //Transfer out operation using the delete node method
        
        else if(strcmp(operation,"transfer_out")==0)
        {
            strcpy(name4,strtok(NULL,","));
            strcpy(going_out,strtok(NULL,","));
            gone=atoi(going_out);
            first=transfer_out(first,name4,gone);
        }
        
        //Relocate operation.
        
        else if(strcmp(operation,"relocate")==0)
        {
            strcpy(location,strtok(NULL,","));
            strcpy(location2,strtok(NULL,"\n"));
            first=relocate(first,location,location2);
        }
        lfirst=insert_log_elements(lfirst,operation,location,quantity);
    }
    
    //Printing all content into the database file.
    FILE *fp3=fopen("database.txt","w");
    
    struct species *print;
    for(print=first;print!=NULL;print=print->next)
    {
        fprintf(fp3,"%s,%s,%d\n",print->name,print->location,print->quantity);
    }
    
    //Freeing up memory.
    clear_list(first);
        
        
    return 0;

    
}





