
//Ameya Bhujbal
//netid: ameyabhujbal
//Description: This is the code file for project 10
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"





//This is a function which reads the elements of the input file into the linked list.
struct species *insert_elements(struct species *list,char name[],char location[],int quantity)
{
    struct species *new_node,*p;
    new_node=malloc(sizeof(struct species));
    if(new_node==NULL)
    {
        printf("Out of memory\n");
        return list;
    }
    
    strcpy(new_node->name,name);
    strcpy(new_node->location,location);
    new_node->quantity=quantity;
    if(list==NULL)
    {
        new_node->next=NULL;
        return new_node;
    }
    for(p=list;p->next!=NULL;p=p->next);
    p->next=new_node;
    new_node->next=NULL;
    return list;

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

struct species *birth(struct species *first,char name[],int born_convert)
    {
             struct species *p;
             for(p=first;p!=NULL;p=p->next)
             {
                 if(strcmp(p->name,name)==0)
                 {
                     p->quantity+=born_convert;
                 }
             }
        return first;
     }

struct species *death(struct species *first,char name3[],int died_convert)
    {
        struct species *p;
        struct species *cur,*prev;
        for(p=first;p!=NULL;p=p->next)
        {
            
            if(strcmp(p->name,name3)==0)
            {
                p->quantity-=died_convert;
                if(p->quantity!=0 && p->quantity>0)
                {
                    return first;
                    break;
                }
                else {
                    for(cur=first,prev=NULL;cur!=NULL && cur->quantity!=0;prev=cur,cur=cur->next);
                    if(cur==NULL)
                        return first;
                    if(prev==NULL)
                        first=first->next;
                    else
                        prev->next=cur->next;
                    free(cur);
                    
                }
            }
        }
        return first;
    }

struct species *transfer_in(struct species *first,char name2[],char location2[],int arriving_in)
    {
        struct species *p,*prev,*cur;
        int flag=0;
        for(p=first;p!=NULL;p=p->next)
        {
            if(strcmp(p->name,name2)==0)
            {
                p->quantity+=arriving_in;
                flag=1;
                return first;
                break;
            }
            
        }
        
        if(flag==0)
        {
            for(cur=first,prev=NULL;cur!=NULL &&(strcmp(cur->name,name2))<0;prev=cur,cur=cur->next);
            struct species *new_node;
            new_node=malloc(sizeof(struct species));
            if(new_node==NULL)
            {
                printf("Out of memory!?!?");
            }
            strcpy(new_node->name,name2);
            strcpy(new_node->location,location2);
            new_node->quantity=arriving_in;
            new_node->next=cur;
            if(prev!=NULL)
            {
                prev->next=new_node;
                return first;
                
            }
            else
            {
                return new_node;
            }
        }
    return first;
    }



struct species *transfer_out(struct species *first,char name4[],int going_out)
    {
        struct species *p;
        struct species *cur,*prev;
        for(p=first;p!=NULL;p=p->next)
        {
            
            if(strcmp(p->name,name4)==0)
            {
                p->quantity-=going_out;
                if(p->quantity!=0 && p->quantity>0)
                {
                    return first;
                    break;
                }
                else {
                    for(cur=first,prev=NULL;cur!=NULL && cur->quantity!=0;prev=cur,cur=cur->next);
                    if(cur==NULL)
                        return first;
                    if(prev==NULL)
                        first=first->next;
                    else
                        prev->next=cur->next;
                    free(cur);
                }
            }
        }
    return first;
    }

    struct species *relocate(struct species *first,char location[],char location2[])
    {
        struct species *p;
        for(p=first;p!=NULL;p=p->next)
        {
            if(strcmp(p->location,location)==0)
            {
                strcpy(p->location,location2);
            }
        }
        return first;
    }







