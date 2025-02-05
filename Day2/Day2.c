#include <stdio.h>
float Func_tax(int salary);
float net_salary (int salary, float emp_tax);
struct empolyee {
char name [50];
int hour;
float salary;
float tax;
};
FILE *myfile;
int main ()
{
    int ch;
    while(1) // while true to trun on the app and if you went end press number "5"
    {
        printf("if you went to exit Enter '5'\n to start press any number \n");
        scanf("%d",&ch);
    if(ch!=5)
    {
    struct empolyee emp;
    int mount;
    float emp_tax,net;
    //to ask user Enter his info
    printf("pls Enter your name : ");
    scanf("%s",&emp.name);
    printf("pls Enter your hours : ");
    scanf("%d",&emp.hour);
    printf("pls Enter your mount : ");
    scanf("%d",&mount);
    // to calculate total salary based on hours and amount
    int res = emp.hour * mount;
    emp_tax = Func_tax(res);
    printf("your salary after tax = %f\n ",emp_tax);
    net =net_salary (res,emp_tax);
    //to check error if return 3 this is error
    if (emp_tax==3)
    {
        printf("error this is salary out of range \n\n");
        continue;
    }
    else{
    printf("your net salary = %f\n",net);
    //stronge the data in myfile
    float arr[2]={emp_tax,net};
    myfile =fopen("file3.txt","a");
    fprintf(myfile,"EMP_TAX= %f\n",0,arr[0]);
    fprintf(myfile,"EMP_net= %f\n",1,arr[1]);
    fprintf(myfile,"emp.name=%s\n",emp.name);
    fprintf(myfile,"emp.hour=%.2d\n",emp.hour);
    fprintf(myfile,"Gro_salary=%d\n",res);
    fprintf(myfile,"*******************\n");
    fclose(myfile);
    }
    }
    else
    {
        printf("good bye:");
        break;

    }
    }
}
float Func_tax(int salary) //this function to calculate a tax salary
{
    float tax=0.0;
    if ((salary<=14999)&&(salary>=0))
    {
        tax=0+((salary-0)*0.15);
    }
    else if ((salary<=29999)&&(salary>=15000))
    {
        tax=2250+((salary-15000)*0.16);
    }
    else if ((salary<=49999)&&(salary>=30000))
    {
        tax=4650+((salary-30000)*0.18);
    }
    else if ((salary<=79999)&&(salary>=50000))
    {
        tax=8250+((salary-50000)*0.20);
    }
    else if ((salary<=150000)&&(salary>=80000))
    {
        tax=14250+((salary-80000)*0.25);
    }
    else
    {
        return 3;
    }
    return tax;
}
float net_salary (int salary, float emp_tax) //this function to calculate a net salary
{
    float net =salary+ (salary*.52)-emp_tax;
    return net;
}

/*
FILE *myfile;
{
    
    myfile =fopen("file3.txt","r");
    char list [100];
    fgets(list,sizeof(list),myfile);
    printf("%s",list);
    fclose(myfile);
}*/
/*
{
 myfile =fopen("file3.c","w");

    fprintf(myfile,"hi,abdo");
    fclose(myfile);
}*/














/*struct empolyee{
char name[20] ;
float salary;
int id;

};
int main ()
{
struct empolyee emp;
printf("pls Enter your name : ");
scanf("%s",&emp.name);
printf("pls Enter your id : ");
scanf("%d",&emp.id);
printf("pls Enter your salary : ");
scanf("%f",&emp.salary);
 printf("your name is %s , id is %d and your salary is %f :",emp.name,emp.id,emp.salary);
}*/
