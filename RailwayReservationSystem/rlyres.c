#include <stdio.h>
#include "conio2.h"
#include <string.h>
#include "rlyres.h"
#include <ctype.h>
#include <malloc.h>
#include <errno.h>
int enterchoice()
{
    gotoxy(30,1);
    textcolor(LIGHTBLUE);
    printf("RAILWAY RESERVATION SYSTEM\n");
    int i;
    int choice;
    for(i=1;i<=80;i++)
         printf("-");
    printf("\n\nSELECT OPTION\n");
    printf("1-VIEW TRAIN\n");
    printf("2-BOOK TICKET\n");
    printf("3-VIEW TICKET\n");
    printf("4-SEARCH TICKET NO\n");
    printf("5-VIEW ALL ALL BOOKINGS\n");
    printf("6-VIEW TRAINS BOOKINGS\n");
    printf("7-CANCLE TICKET\n");
    printf("8-CANCLE TRAIN\n");
    printf("9-QUIT\n");
    printf("\nENTER YOUR CHOICE:");
    scanf("%d",&choice);
    return choice;
}
void add_trains()
{
    FILE* fp=fopen("E:\\myproject1\\alltrains.dat","rb");
    if(fp==NULL)
    {
         Train alltrains[4]={
              {"123","BPL","GWA",2100,1500},
              {"456","BPL","DEL",3500,2240},
              {"678","HBJ","AGR",1560,1135},
              {"891","HBJ","MUM",4500,3360},
              };
         fp=fopen("E:\\myproject1\\alltrains.dat","wb");
         fwrite(alltrains,4*sizeof(Train),1,fp);
         textcolor(LIGHTBLUE);
         fclose(fp);
         printf("File saved!\n");
    }
    else
    {
        fclose(fp);
        textcolor(LIGHTBLUE);
        printf("File already saved!\n");
    }
}

void view_trains()
{
    int i;
    printf("TRAIN NO\tFROM\tTO\tFIRST AC FARE\tSECOND AC FARE\n");
    for(i=1;i<=80;i++)
        printf("-");
    FILE *fp=fopen("E:\\myproject1\\alltrains.dat","rb");
    Train tr;

    while(fread(&tr,sizeof(tr),1,fp)==1)
    printf("\n%s\t\t%s\t%s\t%d\t\t%d",tr.train_no,tr.from,tr.to,tr.fac_fare,tr.sac_fare);
    printf("\n\n\n\n");
    textcolor(LIGHTGREEN);
fclose(fp);
}

int check_train_no(char* train_no)
{
    Train tr;
    FILE* fp=fopen("E:\\myproject1\\alltrains.dat","rb");
    while(fread(&tr,sizeof(tr),1,fp)==1)
    {
        if(strcmp(tr.train_no,train_no)==0)
        {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}
int check_mob_no(char* p_mob)
{
    if(strlen(p_mob)!=10)
    {
        return 0;
    }

    while(*p_mob!='\0')
    {
        if(isdigit(*(p_mob))==0)
            return 0;
            p_mob++;
    }
    return 1;
}
Passenger* get_passenger_details()
{
    clrscr();
    static Passenger psn;
    char* pos;
    gotoxy(60,1);
    textcolor(LIGHTGREEN);
    printf("Press 0 to eixt");
    gotoxy(1,1);
    textcolor(LIGHTBLUE);
    printf("Enter Passenger's name:");
    fflush(stdin);
    fgets(psn.p_name,20,stdin);
    pos=strchr(psn.p_name,'\n');
    *pos='\0';
    if(strcmp(psn.p_name,"0")==0)
    {
        gotoxy(1,25);
        textcolor(LIGHTRED);
        printf("Reservation canclled");
        getch();
        textcolor(LIGHTBLUE);
        return NULL;
    }
    printf("Enter gender:");
    int valid;
    do
    {
        fflush(stdin);
        valid=1;
        scanf("%c",&psn.gender);
        if(psn.gender=='0')
        {
           gotoxy(1,25);
          textcolor(LIGHTRED);
          printf("Reservation canclled");
          getch();
          textcolor(LIGHTBLUE);
          return NULL;
        }
        if(psn.gender!='M' && psn.gender!='F')
        {
            gotoxy(1,25);
            textcolor(LIGHTRED);
            printf("Error ! Invalid gender ,gender should be M or F iin upper case");
            gotoxy(14,2);
            printf(" \b");
            textcolor(LIGHTBLUE);
            valid=0;
        }
    }while(valid==0);
    gotoxy(1,25);
    printf("\t\t\t\t\t\t\t\t");
    gotoxy(1,3);
    textcolor(LIGHTBLUE);
    printf("Enter train no:");
    do
    {
        valid=1;
        fflush(stdin);
        fgets(psn.train_no,10,stdin);
        pos=strchr(psn.train_no,'\n');
        *pos='\0';
        if(strcmp(psn.train_no,"0")==0)
        {
           gotoxy(1,25);
           textcolor(LIGHTRED);
           printf("Reservation canclled");
           getch();
           textcolor(LIGHTBLUE);
           return NULL;
        }
        valid=check_train_no(psn.train_no);
        if(valid==0)
        {
            gotoxy(1,25);
            textcolor(LIGHTRED);
            printf("Error ! Invalid Train no");
            gotoxy(16,3);
            printf("\t\t\t\t\t\t");
            gotoxy(16,3);
            textcolor(LIGHTBLUE);
        }
    }while(valid==0);
    gotoxy(1,25);
    printf("\t\t\t\t\t\t\t\t");
    gotoxy(1,4);
    textcolor(LIGHTBLUE);
    printf("Enter Passenger's class:");
    do
    {
        fflush(stdin);
        valid=1;
        scanf("%c",&psn.p_class);
        if(psn.p_class=='0')
        {
           gotoxy(1,25);
           textcolor(LIGHTRED);
           printf("Reservation canclled");
           getch();
           textcolor(LIGHTBLUE);
           return NULL;
        }
        if(psn.p_class!='F' && psn.p_class!='S')
        {
            gotoxy(1,25);
            textcolor(LIGHTRED);
            printf("Error ! Invalid class");
            gotoxy(25,4);
            printf("\t\t\t\t\t\t");
            gotoxy(25,4);
            textcolor(LIGHTBLUE);
            valid=0;
        }
    }while(valid==0);
    gotoxy(1,25);
    printf("\t\t\t\t\t\t\t\t");
    gotoxy(1,5);
    textcolor(LIGHTBLUE);
    printf("Enter Passenger's address:");
    fflush(stdin);
    fgets(psn.address,30,stdin);
    pos=strchr(psn.address,'\n');
    *pos='\0';
    if(strcmp(psn.address,"0")==0)
    {
        gotoxy(1,25);
        textcolor(LIGHTRED);
        printf("Reservation canclled");
        getch();
        textcolor(LIGHTBLUE);
        return NULL;
    }
    printf("Enter Passenger's age:");
    do
    {
        valid=1;
        scanf("%d",&psn.age);
        if(psn.age==0)
        {
           gotoxy(1,25);
           textcolor(LIGHTRED);
           printf("Reservation canclled");
           getch();
           textcolor(LIGHTBLUE);
           return NULL;
        }
        if(psn.age<=0)
        {
            gotoxy(1,25);
            textcolor(LIGHTRED);
            printf("Error ! Invalid age ");
            gotoxy(22,6);
            printf("\t\t\t\t\t\t");
            gotoxy(22,6);
            textcolor(LIGHTBLUE);
            valid=0;
        }
    }while(valid==0);
    gotoxy(1,25);
    printf("\t\t\t\t\t\t\t\t");
    gotoxy(1,7);
    textcolor(LIGHTBLUE);
    printf("Enter Passenger's mobile no:");
    do
    {
        valid=1;
        fflush(stdin);
        fgets(psn.mob_no,12,stdin);
        pos=strchr(psn.mob_no,'\n');
        if(*pos!=NULL)
           *pos='\0';
        if(strcmp(psn.mob_no,"0")==0)
         {
            gotoxy(1,25);
            textcolor(LIGHTRED);
            printf("Reservation canclled");
            getch();
            textcolor(LIGHTBLUE);
            return NULL;
          }
        valid=check_mob_no(psn.mob_no);
        if(valid==0)
         {
            gotoxy(1,25);
            textcolor(LIGHTRED);
            printf("Error ! Invalid mobile no");
            gotoxy(29,7);
            printf("\t\t\t\t\t\t");
            gotoxy(29,7);
            textcolor(LIGHTBLUE);
         }
    }while(valid==0);
    return &psn;
}
int get_booked_ticket(char* train_no,char tc)
{
    FILE *fp=fopen("E:\\myproject1\\allbookings.dat","rb");
    if(fp==NULL)
    {
        return 0;
    }
    Passenger pr;
    int count=0;
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
        if( (strcmp(pr.train_no,train_no)==0) && (pr.p_class==tc) )
        {
            ++count;
        }
    }
    fclose(fp);
    return count;
}
int last_ticket_no()
{
    FILE *fp=fopen("E:\\myproject1\\allbookings.dat","rb");
    if(fp==NULL)
    {
        return 0;
    }
    Passenger pr;
    fseek(fp,-1L*sizeof(pr),SEEK_END);
    fread(&pr,sizeof(pr),1,fp);
    fclose(fp);
    return pr.ticketno;
}
int book_ticket(Passenger p)
{
    int count_ticket=get_booked_ticket(p.train_no,p.p_class);
    if(count_ticket==30)
    {
        textcolor(LIGHTRED);
        printf("All sets booked in train no:%s in class:%c",p.train_no,p.p_class);
        getch();
        textcolor(LIGHTBLUE);
        return -1;
    }
    int ticket_no=last_ticket_no()+1;
    p.ticketno=ticket_no;
    FILE *fp=fopen("E:\\myproject1\\allbookings.dat","ab");
    fwrite(&p,sizeof(p),1,fp);
    fclose(fp);
    return ticket_no;
}
int accept_ticket_no()
{
    clrscr();
    int ticket_no;
    gotoxy(60,1);
    textcolor(LIGHTRED);
    printf("Press 0 to exit");
    gotoxy(1,1);
    textcolor(LIGHTBLUE);
    printf("Enter ticket no:");
    int valid;
    do
    {
        valid=1;
        scanf("%d",&ticket_no);
        if(ticket_no==0)
        {
           gotoxy(1,25);
           textcolor(LIGHTRED);
           printf("Canclling input....");
           getch();
           textcolor(LIGHTBLUE);
           return 0;
        }
        if(ticket_no<=0)
        {
            gotoxy(1,25);
            textcolor(LIGHTRED);
            printf("Error ! Invalid ticket no,ticket no should be positive");
            gotoxy(17,1);
            printf("\t\t\t\t\t\t");
            gotoxy(17,1);
            textcolor(LIGHTBLUE);
            valid=0;
        }
    }while(valid==0);
    return ticket_no;
}
void view_ticket(int ticket_no)
{
    clrscr();
    FILE *fp=fopen("E:\\myproject1\\allbookings.dat","rb");
    if(fp==NULL)
    {
        textcolor(LIGHTRED);
        printf("No bookings done yet");
        textcolor(LIGHTBLUE);
        getch();
        clrscr();
        return ;
    }
    Passenger pr;
    int found=0;
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
        if(pr.ticketno==ticket_no)
        {
            printf("TRIAN NO:%s\nNAME:%s\nAGE:%d\nGENDER:%c\nCLASS:%c\nTRAIN NO:%s\nTICKET NO%d\nMOBILE NO:%S\nADDRESS:%s",pr.train_no,pr.p_name,pr.age,pr.gender,pr.p_class,pr.train_no,pr.ticketno,pr.mob_no,pr.address);
             found=1;
             printf("\n\n");
             fclose(fp);
            break;
        }
    }
    if(found==0)
    {
        textcolor(LIGHTRED);
        printf("\nNo details of the ticket no:%d found",ticket_no);
    }
    fclose(fp);
}
char* accept_mob_no()
{
    clrscr();
    static char mob_no[11];
    char* pos;
    gotoxy(60,1);
    textcolor(LIGHTRED);
    printf("Press 0 to exit");
    gotoxy(1,1);
    textcolor(LIGHTBLUE);
    printf("Enter mobile no:");
    int valid;
    do
    {
        fflush(stdin);
        fgets(mob_no,11,stdin);
        pos=strchr(mob_no,'\n');
        if(pos!=NULL)
           *pos='\0';
        if(strcmp(mob_no,"0")==0)
        {
            gotoxy(1,25);
            textcolor(LIGHTRED);
            printf("Cancelling Input. . .");
            getch();
            textcolor(LIGHTBLUE);
            return NULL;
        }
        valid=check_mob_no(mob_no);
        if(valid==0)
         {
            gotoxy(1,25);
            textcolor(LIGHTRED);
            printf("Error ! Invalid mobile no");
            gotoxy(17,1);
            printf("\t\t\t\t\t\t");
            gotoxy(17,1);
            textcolor(LIGHTBLUE);
         }
    }while(valid==0);
    clrscr();
    return mob_no;
}
int* get_ticket_no(char* p_mob_no)
{
    int count=0;
    FILE *fp=fopen("E:\\myproject1\\allbookings.dat","rb");
    if(fp==NULL)
    {
        textcolor(LIGHTRED);
        printf("No bookings done yet");
        textcolor(LIGHTBLUE);
        getch();
        return NULL;
    }
    Passenger pr;
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
        if(strcmp(pr.mob_no,p_mob_no)==0)
        {
            ++count;
        }
    }
    if(count==0)
    {
        fclose(fp);
        return NULL;
    }
    rewind(fp);
    int *p=(int*)malloc((count+1)*sizeof(int));
    int i=0;
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
        if(strcmp(pr.mob_no,p_mob_no)==0)
        {
            *(p+i)=pr.ticketno;
              i++;
        }
    }
    *(p+i)=-1;
    fclose(fp);
    return p;
}
void view_all_tickets(char* pmob_no,int* pticket_no)
{
    int i;
    if(pticket_no==NULL)
    {
        textcolor(LIGHTRED);
        printf("Sorry ! No tickets booked against mobile no:%s",pmob_no);
        textcolor(WHITE);
        printf("\nPress any key to go back to the main screen");
        textcolor(LIGHTBLUE);
        getch();
        return ;
    }
    printf("Following are tickets booked for mobile no:%s",pmob_no);
    printf("\nTICKET NO\n");
    printf("*********");
    for(i=0;*(pticket_no+i)!=-1;i++)
    {
        printf("\n%d",*(pticket_no+i));
    }
    textcolor(WHITE);
    printf("\n\nPress any key to back to the main screen");
    textcolor(LIGHTBLUE);
    getch();
    free(pticket_no);
}
char* accept_train_no()
{
    clrscr();
    static char train_no[10];
    char* pos;
    int valid;
    gotoxy(60,1);
    textcolor(LIGHTRED);
    printf("Press 0 to exit");
    gotoxy(1,1);
    textcolor(LIGHTBLUE);
    printf("Enter train no:");
    do
    {
        valid=1;
        fflush(stdin);
        fgets(train_no,10,stdin);
        pos=strchr(train_no,'\n');
        *pos='\0';
        if(strcmp(train_no,"0")==0)
        {
           gotoxy(1,25);
           textcolor(LIGHTRED);
           printf("Canclling input....");
           getch();
           clrscr();
           textcolor(LIGHTBLUE);
           return NULL;
        }
        valid=check_train_no(train_no);
        if(valid==0)
        {
            gotoxy(1,25);
            textcolor(LIGHTRED);
            printf("Error ! Invalid Train no");
            gotoxy(16,1);
            printf("\t\t\t\t\t\t");
            gotoxy(16,1);
            textcolor(LIGHTBLUE);
        }
    }while(valid==0);
    clrscr();
    return train_no;
}
void view_booking(char* p_train_no)
{
    clrscr();
    int i;
   FILE *fp=fopen("E:\\myproject1\\allbookings.dat","rb");
   if(fp==NULL)
   {
        textcolor(LIGHTRED);
        printf("No bookings done yet");
        fclose(fp);
        textcolor(LIGHTBLUE);
        getch();
        return ;
   }
   int row=3;
   int found=0;
   Passenger pr;
   printf("TRAIN NO\tCLASS\tNAME\tGENDER\tAGE\tMOBILE NO\n");
   for(i=1;i<=80;i++)
      printf("-");
   while(fread(&pr,sizeof(pr),1,fp)==1)
   {
       if(strcmp(pr.train_no,p_train_no)==0)
       {
            printf("%d\t\t%c\t%s",pr.ticketno,pr.p_class,pr.p_name);
            gotoxy(41,row);
            printf("%c\t%d\t%s\n",pr.gender,pr.age,pr.mob_no);
            row++;
            found++;
       }
   }
   if(found==0)
    {
        textcolor(LIGHTRED);
        printf("No details of train no %s  found",p_train_no);
        fclose(fp);
    }
    fclose(fp);
    textcolor(YELLOW);
}
void view_all_bookings()
{
    int i;

    FILE *fp=fopen("E:\\myproject1\\allbookings.dat","rb");
    if(fp==NULL)
    {
        textcolor(LIGHTRED);
        printf("No bookings done yet");
        fclose(fp);
        getch();
        textcolor(WHITE);
        printf("\nPress any key to go back to the main screen");
        textcolor(LIGHTBLUE);
        return ;
    }
    Passenger pr;
    printf("TRAIN NO\tCLASS\tNAME\t\tGENDER\tTICKET NO\tMOBILE NO\n");
    for(i=1;i<=80;i++)
        printf("-");
    int row=3;
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
            printf("%s\t\t%c\t%s",pr.train_no,pr.p_class,pr.p_name);
            gotoxy(41,row);
            printf("%c\t%d\t\t%s\n",pr.gender,pr.ticketno,pr.mob_no);
            row++;
    }
    fclose(fp);
    printf("\n\n");
    textcolor(WHITE);
    printf("\nPress any key to go back to the main screen");
    textcolor(LIGHTBLUE);
}
int cancel_ticket(int ticket_no)
{
    int result;
    extern int errno;
    FILE *fp1=fopen("E:\\myproject1\\allbookings.dat","rb");
    if(fp1==NULL)
    {
        textcolor(LIGHTRED);
        printf("\nNo bookings done yet");
        return -1;
    }
    FILE *fp2=fopen("E:\\myproject1\\temp.dat","wb");
    Passenger pr;
    int found=0;

    while(fread(&pr,sizeof(pr),1,fp1)==1)
    {
        if(pr.ticketno==ticket_no)
        {
             found=1;
        }
        else
        {
            fwrite(&pr,sizeof(pr),1,fp2);
        }
    }
    fclose(fp1);
    fclose(fp2);
    if(found==0)
    {
        remove("E:\\myproject1\\temp.dat");
    }
    else
    {
        result=remove("E:\\myproject1\\allbookings.dat");
        if(result!=0)
        {
            printf("Error of remove is:%s",strerror(errno));
            getch();
            return 2;
        }
        result=rename("E:\\myproject1\\temp.dat","E:\\myproject1\\allbookings.dat");
        if(result!=0)
        {
           printf("Error of rename is:%s",strerror(errno));
           getch();
           return 2;
        }
     }
    return found;
}

int cancel_train(char* train_no)
{
    int result;
    int found=0;
    FILE *fp1=fopen("E:\\myproject1\\allbookings.dat","rb");
     if(fp1==NULL)
    {
        textcolor(LIGHTRED);
        printf("\nNo bookings done yet");
        return -1;
    }
    FILE *fp2=fopen("E:\\myproject1\\temp1.dat","wb");
    Passenger pr;

    while(fread(&pr,sizeof(pr),1,fp1)==1)
    {
        if(strcmp(pr.train_no,train_no)==0)
        {
            found=1;
        }
        else
        {
            fwrite(&pr,sizeof(pr),1,fp2);
        }
    }
    fclose(fp1);
    fclose(fp2);
    if(found==0)
    {
        remove("E:\\myproject1\\temp1.dat");
    }
    else
    {
        result=remove("E:\\myproject1\\allbookings.dat");
        if(result!=0)
        {
            printf("Error of remove is:%s",strerror(errno));
           getch();
            return 2;
        }
        result=rename("E:\\myproject1\\temp1.dat","E:\\myproject1\\allbookings.dat");
        if(result!=0)
        {
           printf("Error of rename is:%s",strerror(errno));
           getch();
            return 2;
        }
    }
    return found;
}
