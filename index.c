#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct cust_st
{
int acc_no;
char cust_nm[15];
char mob[15];
float bal;  
};

struct tran_st
{
int acc_no;
char trantype;
float amt;
char date[15];
};


int addcust()
{
FILE *fp;
struct cust_st custdata;
if((fp=fopen("cust1","a+"))==NULL)
{
printf("\nERROR opening cust1 file");
return 0;
}
else
{
printf("\n\nEnter Account number : ");
scanf("%d",&custdata.acc_no);
printf("\nenter customer name : ");
fflush(stdin);
gets(custdata.cust_nm);
printf("\nEnter mobile no. : ");
fflush(stdin);
gets(custdata.mob);
printf("\nEnter Account Balance : ");
scanf("%f",&custdata.bal);
fwrite(&custdata,sizeof(struct cust_st),1,fp);
}
fclose(fp);
}


deposits()
{
FILE *fp1,*fp2;
char flag='y' , found , val_flag;
struct cust_st custdata;
struct tran_st trandata;
int size=sizeof(struct cust_st);
if((fp1=fopen("cust1","r+w"))==NULL)
{
printf("\nERROR opening cust1 file");
return 0;
}
if((fp2=fopen("trans","a+"))==NULL)
{
printf("ERROR opening transaction file");
return 0;
}
printf("\n\nEnter Acount Number : ");
scanf("%d",&trandata.acc_no);
int accno=trandata.acc_no;
rewind(fp1);
while((fread(&custdata,sizeof(struct cust_st),1,fp1))==1)
{
if(custdata.acc_no==accno)
{
found='y';
break;
}
}
if (found=='y')
{
trandata.trantype='d';
printf("\nEnter amount : ");
scanf("%f",&trandata.amt);
printf("\nEnter deposite date : ");
fflush(stdin);
gets(trandata.date);
custdata.bal+=trandata.amt;
fwrite(&trandata,sizeof(struct tran_st),1,fp2);
fseek(fp1,(long)(-size),1);
fwrite(&custdata,size,1,fp1);
}
else
printf("\nThis account number does not exist . ");
fclose(fp1);
fclose(fp2);
}


withdrawls()
{
FILE *fp1,*fp2;
char flag='y' , found , val_flag;
struct cust_st custdata;
struct tran_st trandata;
int size=sizeof(struct cust_st);
if((fp1=fopen("cust1","r+w"))==NULL)
{
printf("\nERROR opening cust1 file");
return 0;
}
if((fp2=fopen("trans","a+"))==NULL)
{
printf("ERROR opening transaction file");
return 0;
}
printf("\n\nEnter Acount Number : ");
scanf("%d",&trandata.acc_no);
int accno=trandata.acc_no;
rewind(fp1);
while((fread(&custdata,sizeof(struct cust_st),1,fp1))==1)
{
if(custdata.acc_no==accno)
{
found='y';
break;
}
}
if (found=='y')
{
trandata.trantype='w';
printf("\nEnter amount : ");
scanf("%f",&trandata.amt);
printf("\nEnter deposite date : ");
fflush(stdin);
gets(trandata.date);
custdata.bal-=trandata.amt;
fwrite(&trandata,sizeof(struct tran_st),1,fp2);
fseek(fp1,(long)(-size),1);
fwrite(&custdata,size,1,fp1);
}
else
printf("\nThis account number does not exist . ");
fclose(fp1);
fclose(fp2);
}


prnlowbal()
{
FILE *fp;
struct cust_st custdata;
if((fp=fopen("cust1","r"))==NULL)
{
printf("\nERROR opening cust1 file");
return 0;
}
printf("\nreport on account balance \n\n");
while((fread(&custdata,sizeof(struct cust_st),1,fp))==1)
{
printf("\n%d\t%s\t%s\t%.2f",custdata.acc_no,custdata.cust_nm,custdata.mob,custdata.bal);
}
fclose(fp);
}


disdepo()
{
FILE *fp;
struct tran_st trandata;
if((fp=fopen("trans","r"))==NULL)
{
printf("\nERROR opening trans file");
return 0;
}
printf("\nreport on deposits \n\n");
while((fread(&trandata,sizeof(struct tran_st),1,fp))==1)
{
if(trandata.trantype=='d')
{
printf("\nAccount no. : %d",trandata.acc_no);
printf("\nStatus : %c",trandata.trantype);
printf("\nDeposite date :%s",trandata.date);
printf("\nDeposited amount : %.2f",trandata.amt);
}
}
fclose(fp);
}


diswith()
{
FILE *fp;
struct tran_st trandata;
if((fp=fopen("trans","r"))==NULL)
{
printf("\nERROR opening trans file");
return 0;
}
printf("\nreport on deposits \n\n");
while((fread(&trandata,sizeof(struct tran_st),1,fp))==1)
{
if(trandata.trantype=='w')
{
printf("\nAccount no. : %d",trandata.acc_no);
printf("\nStatus : %c",trandata.trantype);
printf("\nWithdrawl date :%s",trandata.date);
printf("\nWithdrawl amount : %.2f",trandata.amt);
}
}
fclose(fp);
}


balance()
{
FILE *fp1;
char flag='b' , found , val_flag;
struct cust_st custdata;
int size=sizeof(struct cust_st);
if((fp1=fopen("cust1","r+w"))==NULL)
{
printf("\nERROR opening cust1 file");
return 0;
}
printf("\n\nEnter Acount Number : ");
scanf("%d",&custdata.acc_no);
int accno=custdata.acc_no;
rewind(fp1);
while((fread(&custdata,sizeof(struct cust_st),1,fp1))==1)
{
if(custdata.acc_no==accno)
{
printf("\naccount number : %d",custdata.acc_no);
printf("\naccount holder name : %s",custdata.cust_nm);
printf("\naccount holder mobile number : %s",custdata.mob);
printf("\naccount balance : %.2f",custdata.bal);
}
}
}


statement()
{
FILE *fp1,*fp;
char flag='b' , found , val_flag;
struct tran_st trandata;
struct cust_st custdata;
int size=sizeof(struct cust_st);
if((fp1=fopen("cust1","r+w"))==NULL)
{
printf("\nERROR opening cust1 file");
return 0;
}
printf("\n\nEnter Acount Number : ");
scanf("%d",&custdata.acc_no);
int accno=custdata.acc_no;
rewind(fp1);
while((fread(&custdata,sizeof(struct cust_st),1,fp1))==1)
{
if(custdata.acc_no==accno)
{
printf("\naccount number : %d",custdata.acc_no);
printf("\naccount holder name : %s",custdata.cust_nm);
printf("\naccount holder mobile number : %s",custdata.mob);
printf("\naccount balance : %.2f",custdata.bal);
break;
}
}
if((fp=fopen("trans","r"))==NULL)
{
printf("\nERROR opening trans file");
return 0;
}
printf("\n\nstatement :\n");
printf("\nDATE \t\tAMOUNT \t\tSTATUS");
while((fread(&trandata,sizeof(struct tran_st),1,fp))==1)
{
if(trandata.acc_no==accno)
{
printf("\n%s\t\t%.2f\t\t%c",trandata.date,trandata.amt,trandata.trantype);
}
}
}


int main()
{
int choice=1;
while (choice!=0)
{
printf("\nselect choice from menu\n\n 1.  Add new customer details \n 2.  Deposits \n 3.  Withdrawals \n 4.  Display all accounts. \n 5.  Display all deposits \n 6.  Display all withdrawals. \n 7.  Show balance \n 8.  Show Statements \n 0.  EXIT \n\n enter choice : ");
scanf("%d",&choice);
if (choice==1)
addcust();
else if(choice==2)
deposits();
else if(choice==3)
withdrawls();
else if(choice==4)
prnlowbal();
else if(choice==5)
disdepo();
else if(choice==6)
diswith();
else if(choice==7)
balance();
else if(choice==8)
statement();
else if(choice==0)
break;
}
return 0;
}
