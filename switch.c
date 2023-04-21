//  Created by Ameya Bhujbal on 10/22/21.
//NETID: ameyabhujbal
//DESCRIPTION: Program illustrates the conversion of phone-word to phone number and prints the percentage of occurrences of the letter in a word.


#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{
    //Checking if the second argument of argv is "phone" or not
    if(strcmp(argv[1],"phone")==0)
    {
       //if true then input the phone-word to convert
        char input[ 15 ]={};
        scanf("%s",input);
        char *p=input;
        for(;*p;p++)
        {
            //To print the - in between the numbers check if the input has - and print .If not then convert the phone-word.
            if(*p=='-')
            {
                printf("-");
            }
            else
            {
                switch(*p)
                {
                    case 'A':
                    case 'B':
                    case 'C':
                        printf("2");
                    break;
                    case 'D':
                    case 'E':
                    case 'F':
                        printf("3");
                    break;
                    case 'G':
                    case 'H':
                    case 'I':
                        printf("4");
                    break;
                    case 'J':
                    case 'K':
                    case 'L':
                        printf("5");
                    break;
                    case 'M':
                    case 'N':
                    case 'O':
                        printf("6");
                    break;
                    case 'P':
                    case 'Q':
                    case 'R':
                    case 'S':
                        printf("7");
                    break;
                    case 'T':
                    case 'U':
                    case 'V':
                        printf("8");
                    break;
                    case 'W':
                    case 'X':
                    case 'Y':
                    case 'Z':
                        printf("9");
                    break;
                }
            }
        }
        //Printing the phone-word
        printf("%s\n",p);
    }
    
    //If argv[1] is not phone and is "phrase" then do the following.
    
    else if(strcmp(argv[1],"phrase")==0)
    {
        char str[ 1000 ]={};
        //Character variable for getchar()
        char ch=0;
        int i=0;
        int n=1000;
        
    //Count variables to count the number of words and letter occurrences
        int count=1;
        int count1=0;
        int flag=0;
        
    //Inputting string do-while loop.(Readline function partly)
        do
        {
            if(i>=n)
            {
                break;
            }
            ch=getchar();
            str[i]=ch;
            i++;
        }while(ch!='\n');
        str[i]='\0';
        
        //Counting the no of words and occurrences of letter.
        char *q=str;
        for(;*q!='\0';q++)
        {
            if(*q==' '|| *q=='\n'|| *q=='\t')
            {
                count++;
                flag=0;
            }
            if(*q==argv[2][0] && flag==0)
            {
                count1++;
                flag=1;
            }
            
        }
        //Finding the percentage of the occurrence of the letter 1dp.
        float percentage;
        percentage=(float)count1/(count-1)*100;
        printf("%.1f\n",percentage);
    }

        return 0;
}
//End of program
