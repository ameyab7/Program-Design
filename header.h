//Ameya Bhujbal
//netid: ameya bhujbal
//Description: Header File for project 10

#ifndef DATABASE_H
#define DATABASE_H

struct species
{
char name[1000];
int quantity;
char location[1000];
struct species *next;
};

struct logfile
{
char name[1000];
char operation[1000];
char location1[1000];
char location2[1000];
int quantity;
struct logfile *next;
};

struct species *insert_elements(struct species *list,char name[],char location[],int quantity);

struct logfile *insert_log_elements(struct logfile *list,char operation[],char location[],int quantity);

struct species *birth(struct species *first,char name[],int born_convert);

struct species *death(struct species *first,char name3[],int died_convert);

struct species *transfer_in(struct species *first,char name2[],char location2[],int arriving_in);

struct species *transfer_out(struct species *first,char name4[],int going_out);

struct species *relocate(struct species *first,char location[],char location2[]);

void clear_list(struct species *list);

    
#endif





