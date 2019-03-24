#include<stdio.h>
#include<string.h>//strlen,strcmp
#include<time.h>//date
#include<ctype.h>//isalph isnum
#define fileh "hospital.txt"
#define fileb "bed.txt"
#define filep "patient.txt"
#define filee "employe.txt"
#define temp "temp.txt"
#define systemc system("cls");

FILE *fp,*fp1,*fp2,*fp3,*sp,*fe1,*fe2;

struct  hospital
{
	char hname[20];
	int floors;
	int nobeds;
	int room[10];
	int bed[10][10];
	int cpday;
}h;
struct beds
{
    int p_id,b_id;
}b[10][10][10];
struct date
	{
	    int dd,mm,yy;
	}today;
 struct patient
{
	char name[20],gender[2],phone_num[11];
	int age,p_id,ab_id,total_amount;
	struct date admit_date;
	struct date discharge_date;
}p,p1;

 struct emp
 {
     char ename[20],password[10],eid[20];
 };
//fumtions for take inputs
struct date gdate();
void get(char *p);
void gete(char *p);
void phone(char *p);
int num();
int numh();//charge
void gender(char *p);
//programm look or designe
void sleep(int);//1000->1s
void returnfunc(void);
void mainmenu(void);
//main function
void input_hospital();
void display_hospital();
void input_patient();
void display_patient();
void print_patient();
void discharge_patient();
int bedallocation(int i1,int j1,int k1,int pid);
int beddeallocation(int i1,int j1,int k1);
//get defrene between 2 date
int countLeapYears(struct date d);
int day(struct date dt1,struct date dt2);

//employee
int avlempid(char *p);
void display_employe();
void insert_emp();
int passwd();
int main()
{
    int i=1;
    fe1=fopen(filee,"r");
    if(fe1==NULL)
    {
        fclose(fe1);
        fe1=fopen(filee,"w");
        fclose(fe1);
        insert_emp();
    }
    else
        fclose(fe1);

    i=passwd();
    if(i==1)
    {
    today=gdate();
    fp=fopen(fileh,"r");
    if((fread(&h,sizeof(h),1,fp))==NULL)
    {
        input_hospital();
        fp1=fopen("pids.txt","w");
        fprintf(fp1,"0");
        fclose(fp1);
    }
    fclose(fp);
    mainmenu();
    }
return 0;
}
void mainmenu()
{
    fp=fopen(fileh,"r");
fread(&h,sizeof(h),1,fp);
fclose(fp);
systemc
int i;
printf("\t\t  %s\n",h.hname);
printf("*****************MAIN MENU******************************");
printf("\n [1]. Add patient record   ");
printf("\n [2]. View patient details");
printf("\n [3]. Patient discharge");
printf("\n [4]. Display hospital details");
printf("\n [5]. Print patient details");
printf("\n [6]. Enter new employee details");
printf("\n [7]. View employee details");
printf("\n [8]. Close Application\n");
printf("*********************************************************");
printf("\n today date %d/%d/%d",today.dd,today.mm,today.yy);
sw:printf("\nEnter your choice:");
i=num();
switch(i)
{
case 1:
    systemc
    printf("\t\t  %s\n",h.hname);
    input_patient();
    returnfunc();
break;
case 2:
    systemc
    printf("\t\t  %s\n",h.hname);
    display_patient();
    returnfunc();
break;
case 3:
    systemc
    printf("\t\t  %s\n",h.hname);
    discharge_patient();
    returnfunc();
break;
case 4:
    systemc
    display_hospital();
    returnfunc();
break;
case 5:
    systemc
    printf("\t\t  %s\n",h.hname);
    print_patient();
    returnfunc();
break;
case 6:
    systemc
    printf("\t\t  %s\n",h.hname);
    insert_emp();
    returnfunc();
case 7:
    systemc
    printf("\t\t  %s\n",h.hname);
    display_employe();
    returnfunc();
case 8:
{
systemc
printf("\n hospital Management System");
printf("\nExiting in 3 second...........>");sleep(1000);
printf("\nExiting in 2 second...........>");sleep(1000);
printf("\nExiting in 1 second...........>");sleep(1000);

exit(0);
}
default:
{
printf("\a\nWrong Entry!!Please re-entered correct option");
goto sw;
}
}
}
void returnfunc(void)
{
int i;
a:printf("\n Press 1 to return to main menu");
i=num();
if(i==1)
{
mainmenu();
}
else{goto a;}

}
void input_hospital()
{

    fp=fopen(fileh,"w");
    fp1=fopen(fileb,"w");
    int i,j,k;
    h.nobeds=0;
    printf("\nEnter hospital name :  ");                         get(h.hname);
    printf("charge of bed per day:");                             h.cpday=numh();
    printf("Enter no of floors:   ");                             h.floors=num();
    for(i=1;i<=h.floors;i++)
    {
        printf("no of room in %d floors:   ",i);                   h.room[i]=num();
        for(j=1;j<=h.room[i];j++)
        {
            printf("\tno of bed on %d room:   ",j);                h.bed[i][j]=num();
        }
    }
    for(i=1;i<=h.floors;i++)
    {
        for(j=1;j<=h.room[i];j++)
        {
            for(k=1;k<=h.bed[i][j];k++)
            {
                b[i][j][k].b_id=(i*100)+(j*10)+k;
                h.nobeds++;
                fwrite(&b[i][j][k],sizeof(b[i][j][k]),1,fp1);
            }
        }
    }
fwrite(&h,sizeof(h),1,fp);
fclose(fp);
fclose(fp1);

}
void display_hospital()
{
    //printf("\nnow in files\n");
    fp=fopen(fileh,"r");
    fp1=fopen(fileb,"r");
    int i,j,k;
    fread(&h,sizeof(h),1,fp);

    printf("\t\t\t");          printf("%s\n",h.hname);
    printf("No of floors   ");            printf("%d\n",h.floors);
    for(i=1;i<=h.floors;i++)
    {
        printf("\nfloor:: %d\n",i);
        for(j=1;j<=h.room[i];j++)
        {
            printf("\t\tRoom %d\n",j);
              for(k=1;k<=h.bed[i][j];k++)
            {
				 printf("\tBed %d",k);
                fread(&b[i][j][k],sizeof(b[i][j][k]),1,fp1);
				 printf("\t bed id %d",b[i][j][k].b_id);
				  if(b[i][j][k].p_id==0)
                 {
                    printf("\t bed is available");
                 }
                 else
                 {
                     printf("\t patient id %d",b[i][j][k].p_id);
                 }
                 printf("\n");
            }
        }
    }

fclose(fp);
fclose(fp1);
}

int bedallocation(int i1,int j1,int k1,int pid)
{
    int i,j,k;
    fp=fopen(fileh,"r");
    fp1=fopen(fileb,"r");
    fp2=fopen(temp,"w");
    fread(&h,sizeof(h),1,fp);
    for(i=1;i<=h.floors;i++)
    {
        for(j=1;j<=h.room[i];j++)
        {
            for(k=1;k<=h.bed[i][j];k++)
            {
               fread(&b[i][j][k],sizeof(b[i][j][k]),1,fp1);
               if(i==i1&&j==j1&&k==k1)
               {
                   if(b[i][j][k].p_id==0)
                   {
                       b[i][j][k].p_id=pid;
                       fwrite(&b[i][j][k],sizeof(b[i][j][k]),1,fp2);
                   }
                   else{
                    return 0;
                   }
               }
               else
               {
                   fwrite(&b[i][j][k],sizeof(b[i][j][k]),1,fp2);
               }
            }
        }
    }
    fclose(fp1);
    fclose(fp2);

    fp2=fopen(fileb,"w");
    fp1=fopen(temp,"r");
    for(i=1;i<=h.floors;i++)
    {
        for(j=1;j<=h.room[i];j++)
        {
            for(k=1;k<=h.bed[i][j];k++)
            {
                fread(&b[i][j][k],sizeof(b[i][j][k]),1,fp1);
                   fwrite(&b[i][j][k],sizeof(b[i][j][k]),1,fp2);
            }
        }
    }
    fclose(fp1);
    fclose(fp2);
    fclose(fp);
    return 1;
}

int beddeallocation(int i1,int j1,int k1)
{
    int i,j,k;
    fp=fopen(fileh,"r");
    fp1=fopen(fileb,"r");
    fp2=fopen(temp,"w");
    fread(&h,sizeof(h),1,fp);
    for(i=1;i<=h.floors;i++)
    {
        for(j=1;j<=h.room[i];j++)
        {
            for(k=1;k<=h.bed[i][j];k++)
            {
               fread(&b[i][j][k],sizeof(b[i][j][k]),1,fp1);
               if(i==i1&&j==j1&&k==k1)
               {
                   if(b[i][j][k].p_id!=0)
                   {
                       b[i][j][k].p_id=0;
                       fwrite(&b[i][j][k],sizeof(b[i][j][k]),1,fp2);
                   }
               }
               else
               {
                   fwrite(&b[i][j][k],sizeof(b[i][j][k]),1,fp2);
               }
            }
        }
    }
    fclose(fp1);
    fclose(fp2);
    fp2=fopen(fileb,"w");
    fp1=fopen(temp,"r");
    for(i=1;i<=h.floors;i++)
    {
        for(j=1;j<=h.room[i];j++)
        {
            for(k=1;k<=h.bed[i][j];k++)
            {
                   fread(&b[i][j][k],sizeof(b[i][j][k]),1,fp1);
                   fwrite(&b[i][j][k],sizeof(b[i][j][k]),1,fp2);
            }
        }
    }
    fclose(fp1);
    fclose(fp2);
    fclose(fp);
    return 1;
}

void input_patient()
{
    int pid,i=0,navlbed=0,j,k,fl,rl,bl;
    p=p1;
    fp=fopen(fileh,"r");
    fp2=fopen(fileb,"r");

    sp=fopen("pids.txt","r");
    fscanf(sp,"%d",&pid);
    fclose(sp);
    pid++;

    printf("-------------------------------\n");
    printf("Your serial no.=%d",pid);
    p.p_id=pid;
    p.admit_date=gdate();
    printf("\n-------------------------------\n");
    printf("Patient id: %d",p.p_id);
    printf("\nadmit date %d/%d/%d",p.admit_date.dd,p.admit_date.mm,p.admit_date.yy);
    printf("\n-------------------------------\n");
    printf("\nEnter the name          :");                      get(p.name);
    printf("Enter the gender(M/F)   :");                        gender(p.gender);
    printf("Enter the age           :");                         p.age=num();
    printf("contact no:             :");                         phone(p.phone_num);
    printf("\nAvailable beds");
    fread(&h,sizeof(h),1,fp);
  for(i=1;i<=h.floors;i++)
    {
        printf("\nFloor %d\n",i);
        for(j=1;j<=h.room[i];j++)
        {
            printf("\tRoom %d\n",j);
              for(k=1;k<=h.bed[i][j];k++)
                {
                     fread(&b[i][j][k],sizeof(b[i][j][k]),1,fp2);
                    if(b[i][j][k].p_id==0)
                     {
				             printf("\t\t\tBed %d\n",k);
                      }
                     else
                     {
                            printf("\t\t\tthis beds is given\n");
                            navlbed++;
                      }
                }
        }
    }

    if(navlbed==h.nobeds)
    {
        printf("\nhospital's all bed are used");
        printf("\nTIPS:: discharge patient");
        returnfunc();
    }
    else
    {
        A:
    printf("\nWhich bed ? ");
	floor: printf("\nfloor");             fl=num();
        if(fl<=h.floors && fl!=0)
        {
          room:  printf("room");          rl=num();
                if(rl<=h.room[fl] && rl!=0)
                {
                    bed: printf("bed");   bl=num();
                        if(bl<=h.bed[fl][rl] && bl!=0)
                        {
                        }
                        else
                            goto bed;
                }
                else
                    goto room;
        }
        else
            goto floor;


   if(bedallocation(fl,rl,bl,pid)==1)
    {
      fread(&b[fl][rl][bl],sizeof(b[fl][rl][bl]),1,fp2);
       p.ab_id = b[fl][rl][bl].b_id;
    }
    else
    {
        printf("No such bed is available\n");
        goto A;
    }
        fp1=fopen(filep,"a");
        fwrite(&p,sizeof(p),1,fp1);
        fclose(fp1);
        sp=fopen("pids.txt","w");
            fprintf(sp,"%d",pid);
        fclose(sp);
    }
fclose(fp2);fclose(fp);
}
void display_patient()
{
    char l[10];
int i=0,e,pid;
  sp=fopen("pids.txt","r");
    fscanf(sp,"%d",&pid);
    fclose(sp);
 printf("\nTotal patient 1 to %d\n",pid);
if(pid==0)
 {
     printf("\n please admit patients first");
     returnfunc();
 }
 for(i=0;i<50;i++)
{printf("*");}

    printf("\nEnter patient id to search.:-");                   e=num();
fp=fopen(filep,"r");
if(fp)
{
while((fread(&p,sizeof(p),1,fp))!=0)
{
    if(e==p.p_id)
    {
        printf("\npatient id       %d",p.p_id);
        printf("\npatient name     %s",p.name);
        printf("\ngender           %s",p.gender);
        printf("\nage              %d",p.age);
        printf("\nbed id           %d",p.ab_id);
        printf("\ncontact no       %s",p.phone_num);
        printf("\nadmit date       %d/%d/%d",p.admit_date.dd,p.admit_date.mm,p.admit_date.yy);
        if(p.discharge_date.dd)
        printf("\ndischarge date   %d/%d/%d",p.discharge_date.dd,p.discharge_date.mm,p.discharge_date.yy);
        printf("\n date date       %d/%d/%d",today.dd,today.mm,today.yy);
        printf("\n=====================================================================\n");
         if(p.total_amount)
        printf("\ntotal amount     %d\n",p.total_amount);
    }
}
fclose(fp);
}
else{
    printf("\nInvalid patient id no.\n");
}
}
void discharge_patient()
{
int i,j,k,z,a,c_b,e,pid;
      char l[10];
       sp=fopen("pids.txt","r");
    fscanf(sp,"%d",&pid);
    fclose(sp);
 printf("\nTotal patient1 to %d\n",pid);

 if(pid==0)
 {
     printf("\n please admit patients first");
     returnfunc();
 }
  for(i=0;i<50;i++)
{printf("*");}
    fp=fopen(fileh,"r");
    fread(&h,sizeof(h),1,fp);
    c_b=h.cpday;
    fclose(fp);
    printf("\nEnter patient id to be discharged:-");               e=num();
    fp=fopen(filep,"r");
    fp2=fopen("temp1.txt","w");
if(fp)
{
    while((fread(&p,sizeof(p),1,fp))!=0)
    {
        if(e==p.p_id)
        {
            if((p.discharge_date.dd)==0)
            {
            p.discharge_date=gdate();
            p.total_amount=(day(p.admit_date,p.discharge_date))*c_b;
            z=p.ab_id;
            i=z/100;
            z=z%100;
            j=z/10;
            z=z%10;
            k=z;
            fwrite(&p,sizeof(p),1,fp2);
            z=beddeallocation(i,j,k);
            printf("\npatient id       %d",p.p_id);
            printf("\ndischarge date   %d/%d/%d",p.discharge_date.dd,p.discharge_date.mm,p.discharge_date.yy);
            printf("\ntotal amount     %d\n",p.total_amount);
            printf("\nPatient is succesfully discharged\n");
            }
            else
            {
                printf("\npatient already discharged");
            }
        }
        else
        {
            fwrite(&p,sizeof(p),1,fp2);
        }
    }
}

if(z==0)
{
    printf("\npatient is not discharged");
}
if(z==1)
{

    fclose(fp);
    fclose(fp2);
fp=fopen("temp1.txt","r");
fp1=fopen(filep,"w");
fread(&p,sizeof(p),1,fp);
    fwrite(&p,sizeof(p),1,fp1);
fclose(fp);
fclose(fp1);
}
}

void print_patient()
{
    char l[10],k[20];
int i=0,e,pid,c;


sp=fopen("pids.txt","r");
    fscanf(sp,"%d",&pid);
    fclose(sp);
 printf("\nTotal patient 1  to %d\n",pid);
 if(pid==0)
 {
     printf("\n please admit patients first");
     returnfunc();
 }
  for(i=0;i<50;i++)
{printf("*");}
    printf("\nEnter p_id no search.:-");
    e=num();
sprintf(k,"%d.txt",e);

fp=fopen(fileh,"r");
fread(&h,sizeof(h),1,fp);
fclose(fp);
fp=fopen(filep,"r");
if(fp)
{

while(fread(&p,sizeof(p),1,fp)!=0)
{
    if(e==p.p_id)
    {
    fp3=fopen(k,"w");
    fprintf(fp3,"\n==============================================================================\n");
    fprintf(fp3,"\t\t\t%s",h.hname);
        fprintf(fp3,"\n==============================================================================\n");
        fprintf(fp3,"Patient id               %d",p.p_id);
        fprintf(fp3,"\n==============================================================================\n");
        fprintf(fp3,"\nPatient name           %s",p.name);
        fprintf(fp3,"\nGender                 %s",p.gender);
        fprintf(fp3,"\nAge                    %d",p.age);
        fprintf(fp3,"\n Bed id                %d",p.ab_id);
         fprintf(fp3,"\nContet no             %s",p.phone_num);
         fprintf(fp3,"\n==============================================================================\n");
        fprintf(fp3,"\nAdmit date             %d/%d/%d",p.admit_date.dd,p.admit_date.mm,p.admit_date.yy);
        if(p.discharge_date.dd)
        {
        fprintf(fp3,"\n==============================================================================\n");
        fprintf(fp3,"\nDischarge date         %d/%d/%d",p.discharge_date.dd,p.discharge_date.mm,p.discharge_date.yy);
       fprintf(fp3,"\n==============================================================================\n");
        fprintf(fp3,"\nTotal amount           %d",p.total_amount);
        }
        else
        {
            fprintf(fp3,"\nParient not dischage yet !!!!!!!!!!");
        }
        fclose(fp3);
        tryagain:
        printf("\ndo you want to open text file now( 1==y && 0==n)");
        i=num();
        if(i==1)
        {
            system(k);
        }
        else if(i==0)
            {
            mainmenu();
        }
        else
        {
                goto tryagain;
        }
    }
}
fclose(fp);


}else{
    printf("\nInvalid patient id no.\n");

}

}

void sleep(int n)
{
     int j;     double z;
for(j=0;j<=n;j++)
{
    for(z=0;z<99999.99;z++)
    {
        z++;
        z--;
    }
}
}

struct date gdate()
{
    struct date tempdate;
    time_t t=time(NULL);
    struct tm *local=localtime(&t);
    tempdate.dd=local->tm_mday;
    tempdate.mm=local->tm_mon+1;
    tempdate.yy=local->tm_year+1900;
    return tempdate;
}

void get(char *p)
{
    int i=0,j,k=0;
    char na[20];
   getc: scanf(" ");
    scanf("%[^\n]s",na);
    i=0,k=0;
    j=strlen(na);
    while(na[k]!='\0')
    {
        if((isalpha(na[k]))||na[k]==' ')
        {
            i++;
        }
        else if(na[k]=='.')
        {
            i++;
        }
        k++;
    }
    k=0;
    if(i==j)
    {
         while(na[k]!='\0')
        {
        *p=na[k];
        p++;
        k++;
        }
    }
    else
    {
        printf("Enter detail in alphabetical form  ::");
        goto getc;
    }
}
void phone(char *p)
{
    int i=0,j=0,k=0;
    char n[20];
   phone:
       scanf(" ");
    scanf("%s",n);
    i=0,j=0,k=0;
    j=strlen(n);
    if(j==10)
    {
        while(n[k]!='\0')
        {
            if((isdigit(n[k])))
            {
                i++;
            }
            k++;
        }

        k=0;
        if(i==j)
        {
            while(n[k]!='\0')
            {
                *p=n[k];
                p++;
                k++;
            }

        }
    }
      else
    {
        printf("Enter the phone correct number ::");
        goto phone;
    }
}
void gender(char *p)
{
    char na[3];
   g:
    scanf(" ");
     scanf("%[^\n]s",na);

    if((strcmp(na,"m")==0)||(strcmp(na,"M")==0))
    {           strcpy(p,na);
    }else if((strcmp(na,"f")==0)||(strcmp(na,"F")==0))
    {
         strcpy(p,na);
    }
    else{
            printf("Enter gender properly  ::");
         goto g;
    }
}
int num()
{
    int i=0,t,j,k=0;
    char na[20];
   num: scanf(" ");
    scanf("%[^\n]s",na);
    k=0,i=0;
    j=strlen(na);
    while(na[k]!='\0')
    {
        if((isdigit(na[k]))&&na[0]!='0')
        {
            i++;
        }
        k++;
    }
    if(i<3&&i==j)
    {

        t=atoi(na);
        return t;
    }
    else
    {
        printf("Enter only 2 digits    ::");
        goto num;
    }
}

int numh()
{
    int i=0,t,j,k=0;
    char na[20];
   num1: scanf(" ");
    scanf("%[^\n]s",na);
    i=0,k=0;
    j=strlen(na);
    while(na[k]!='\0')
    {
        if((isdigit(na[k]))&&na[0]!='0')
        {
            i++;
        }
        k++;
    }
    if(i==j)
    {

        t=atoi(na);
        return t;
    }
    else
    {
        printf("Enter only digits ::");
        goto num1;
    }
}

void gete(char *p)
{
    int i=0,j,k=0;
    char na[20];
    scanf(" ");
    scanf("%[^\n]s",na);
    while(na[k]!='\0')
    {
    *p=na[k];
    p++;
    k++;
    }
    *p='\0';
}

int countLeapYears(struct date d)
{
     int years = d.yy;
     if(d.mm<=2)
     {
         years--;
     }
     return years/4 - years/100 + years/400;
}
int day(struct date dt1,struct date dt2)
{
    int i;
int   monthDays[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int n1 = dt1.yy * 365 + dt1.dd;
    for (i = 0; i < dt1.mm - 1; i++)
    {
        n1 += monthDays[i];
    }
        n1 += countLeapYears(dt1);
        int n2 = dt2.yy * 365 + dt2.dd;
        for (i = 0; i < dt2.mm - 1; i++)
        {
            n2 += monthDays[i];
        }
        n2 += countLeapYears(dt2);
        return (n2 - n1)+1;
}

int avlempid(char *p)
{
     struct emp e1,e;
    fe1=fopen(filee,"r");
    while((fread(&e1,sizeof(e1),1,fe1))!=0)
    {
        if(feof(fe1))
         {
             break;
         }
        if((strcmp(p,e1.eid))==0)
        {
            fclose(fe1);
            return 0;
        }

    }
    fclose(fe1);
    return 1;
}

void insert_emp()
{
     struct emp e1,e;
     int i;
     char id[30];
    emp: printf("Enter id no");
     gete(id);
     i=avlempid(id);
     if(i==1)
     {
         fe2=fopen(filee,"a");
         strcpy(e1.eid,id);
     printf("Enter the name ");
     gete(e1.ename);
     printf("Enter the password ");
     gete(e1.password);
      printf("%s\t\t %s\n",e1.eid,e1.ename);

     fwrite(&e1,sizeof(e1),1,fe2);
     fclose(fe2);
     display_employe();
     }
     else{
        printf("\nThis employee id is not available\n");
        goto emp;
     }
 }

void display_employe()
{
    struct emp e1,e;
     fe1=fopen(filee,"r");
     if(fp==NULL)
     {
         printf("\n file not open");
     }
     printf("\n employe no \t name \n ");
     while((fread(&e1,sizeof(e1),1,fe1))!=0)
     {

         printf("%s\t\t %s\n",e1.eid,e1.ename);
         if(feof(fe1))
         {
             break;
         }
     }
     fclose(fe1);
}


int passwd()
{
    struct emp e1,e;

char pw[20],id[20];
int i=0,j,avl;
char ch;
      printf("\nEnter employe id");
      gete(id);
      j=avlempid(id);
      if(j==1)
      {
          printf("employe %s is not found",id);
      }
      else
      {
        fe1=fopen(filee,"r");
        while((fread(&e,sizeof(e),1,fe1))!=0)
        {
            if((strcmp(id,e.eid))==0)
            {
          pass:
              i=0;
            printf("\nEnter  password");
            while(1)
            {
                ch=getch();
                if(ch==13)
                {
                    pw[i]='\0';
                    break;
                }
                else if(ch==8)
                {
                    if(i>0)
                    {
                        i--;
                        printf("\b \b");
                    }
                }
                else if(ch==9||ch==32)
                {continue;}
                else{
                        pw[i]=ch;
                        i++;
                        printf("*");
                    }
            }
           // getch();
            if((strcmp(pw,e.password))==0)
            {
                fclose(fe1);
                return 1;
            }
            else
            {
                printf("\nEnter correct password");
              goto pass;
            }
            }
        }
    }
}


