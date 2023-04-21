
/*Name:Ameya Bhujbal
 NetID:ameyabhujbal
 Description: Building a code to update the database of animals in the zoo using linked lists.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Structure for the animals in the zoo.
struct species
{
char name[200];
int quantity;
char location[200];
struct species *next;
};

//Structure for the new animals arriving or going out in the zoo.
struct logfile
{
char name[200];
char operation[200];
char location1[200];
char location2[200];
int quantity;
struct logfile *next;
};

//This is a function which reads the elements of the input file into the linked list.
struct species *insert_elements(struct species *list,char name[],char location[],int quantity)
{
    struct species *new_node;
    new_node=malloc(sizeof(struct species));
    if(new_node==NULL)
    {
        printf("Out of memory\n");
        return list;
    }
    strcpy(new_node->name,name);
    strcpy(new_node->location,location);
    new_node->quantity=quantity;
    new_node->next=list;
    return new_node;

}

//This is a function which reads the elements of the log file.
struct logfile *insert_log_elements(struct logfile *list,char operation[],char location[],int quantity)
{
    struct logfile *new_log_node;
    new_log_node=malloc(sizeof(struct logfile));
    if(new_log_node==NULL)
    {
        printf("Out of memory\n");
        exit(EXIT_FAILURE);
        return list;
    }
    strcpy(new_log_node->operation,operation);
    new_log_node->next=list;
    return new_log_node;
    
}

//This is a function that frees up the extra memory using the free function.
void clear_list(struct species *list)
{
    struct species *p;
    while(list!=NULL)
    {
        p=list;
        list=list->next;
        if(p!=NULL)
            free(p);
    }
}

//Main function here I will do all the operations. The functions were just for inputting.

int main(int argc,char *argv[])
{
    struct species *first=NULL;
    struct logfile *lfirst=NULL;
    char name[200],name2[200],location[200],arriving[200]; int quantity,arriving_in;
    char born[200]; int born_convert;
    char operation[200],location2[200];
    
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
    struct species *p;
    while(fgets(operation,sizeof(operation),fp2) && !feof(fp2) && !ferror(fp2))
    {
        strtok(operation,",");
        
        //Birth operation.
        if(strcmp(operation,"birth")==0)
        {
            strcpy(name,strtok(NULL,","));
            strcpy(born,strtok(NULL,","));
            born_convert=atoi(born);
            for(p=first;p!=NULL;p=p->next)
            {
                if(strcmp(p->name,name)==0)
                {
                    p->quantity+=born_convert;
                }
            }
        }
        //Transfer_in operation.
        else if(strcmp(operation,"transfer_in")==0)
        {
            struct species *new_node=malloc(sizeof(struct species));
            strcpy(name2,strtok(NULL,","));
            strcpy(location2,strtok(NULL,","));
            strcpy(arriving,strtok(NULL,","));
            arriving_in=atoi(arriving);
            int flag=0;
            for(p=first;p!=NULL;p=p->next)
            {
                if(strcmp(p->name,name2)==0)
                {
                    p->quantity+=arriving_in;
                    flag++;
                    break;
                }
                
            }
            
            if(flag==0)
            {
                    strcpy(new_node->name,name2);
                    strcpy(new_node->location,location2);
                    new_node->quantity=arriving_in;
                    new_node->next=first;
                    first=new_node;
            }
            
                
        }
        //Relocate operation.
        
        else if(strcmp(operation,"relocate")==0)
        {
            strcpy(location,strtok(NULL,","));
            strcpy(location2,strtok(NULL,"\n"));
            for(p=first;p!=NULL;p=p->next)
            {
                if(strcmp(p->location,location)==0)
                {
                    strcpy(p->location,location2);
                }
            }
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


