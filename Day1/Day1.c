#include <stdio.h>
int area (int lenght , int width);
int temp (int F);
void Scour (int grade);
void mult(int number);
int main ()
{
    int ch;
     int lenght,width,f,score,grade,number;
   
    while (ch=1)
    {
    printf("enter '1' to area , '2' to temp , '3'to gread ,'4' to mult if went to exit print '5'\n");
    scanf("%d",&ch);
    if (ch ==1)
    {
        printf("pls enter your lenght and width ");
        scanf("%d %d",&lenght,&width);
        int res =area (lenght , width);
        printf("the ares is : %d\n",res);
    }
    else if (ch==2)
    {
        printf("pls enter yout temp in F :");
        scanf("%d",&f);
        temp (f);
        printf ("the temp in C is :%d\n",temp(f));
    }
    else if (ch ==3)
     {
        printf("pls enter your score");
        scanf("%d",&score);
        Scour(score);
     }
    else if (ch ==4)
    {
        printf ("pls enter the numer to mult:");
        scanf("%d",&number);
        mult(number);
    }
    else if (ch==5)
    {
        printf ("God bye");
        break;
    }
    else
    {
        printf ("error");
    }
    
    }
}


int area (int lenght , int width)
{
    int area = lenght*width;
    return area ;
}
int temp (int F)
{
    int c; 
    c = (5.0/9.0) * (F-32);
    return c ;
}
void Scour (int grade)
{
    if ((grade<=101)&&(grade<=-1))
    {
        printf ("error\n");
    }
    else
    {
        if ((grade<=100)&&(grade>=90))
    {
        printf ("the grade is A: \n");
    }
    else if ((grade<=89)&&(grade>=70))
    {
        printf ("the grade is B: \n");
    }
    else if ((grade<=69)&&(grade>=60))
    {
        printf ("the grade is c: \n");
    }
     else
    {
        printf ("the grade is f: \n");
    }
    }
}
void mult (int number)
{
    int res=0, i;
    for (i =0; i <= number; i++)
    {
        res = i * number;
        printf ("%d * %d = %d\n",i,number,res);
    }   
}