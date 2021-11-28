#include <stdio.h>
#include <stdlib.h>
#include "conio2.h"
#include "rlyres.h"
int main()
{
    int choice;
    int ticket_no,result;
    Passenger* ptr;
    int* pticket_no;
    char* ptrain_no;
    char* pmob_no;
    add_trains();
    while(1)
    {
        choice=enterchoice();
        if(choice==9)
        {
            exit(0);
        }
        switch(choice)
        {
            case 1:
                          clrscr();
                          view_trains();
                          textcolor(WHITE);
                          printf("\nPress any key to go back to the main screen");
                          getch();
                          clrscr();
                          textcolor(LIGHTBLUE);
                          break;

            case 2:
                        ptr=get_passenger_details();
                        clrscr();
                        if(ptr!=NULL)
                        {
                            ticket_no=book_ticket(*ptr);
                            if(ticket_no==-1)
                            {
                                textcolor(LIGHTRED);
                                printf("Booking faild try agian !");
                                textcolor(LIGHTBLUE);
                            }
                            else
                            {
                                textcolor(LIGHTGREEN);
                                printf("Ticket successfully booked and your ticket no is:%d",ticket_no);
                                textcolor(LIGHTBLUE);
                            }
                        }
                        textcolor(WHITE);
                        printf("\nPress any key to go back to the main screen");
                        getch();
                        clrscr();
                        textcolor(LIGHTBLUE);
                        break;

            case 3:
                          ticket_no=accept_ticket_no();
                          clrscr();
                          if(ticket_no!=0)
                              view_ticket(ticket_no);
                          textcolor(WHITE);
                          printf("\nPress any key to go back to the main screen");
                          getch();
                          textcolor(LIGHTBLUE);
                          clrscr();
                          break;

            case 4:
                         pmob_no=accept_mob_no();
                         clrscr();
                         if(pmob_no!=NULL)
                         {
                              pticket_no=get_ticket_no(pmob_no);
                              view_all_tickets(pmob_no,pticket_no);
                         }
                         clrscr();
                         break;

            case 5:
                        clrscr();
                        view_all_bookings();
                        getch();
                        clrscr();
                        textcolor(LIGHTBLUE);
                        break;

             case 6:
                         ptrain_no=accept_train_no();
                         clrscr();
                         if(ptrain_no!=NULL)
                            view_booking(ptrain_no);
                         textcolor(WHITE);
                         printf("\nPress any key to go back to the main screen");
                         getch();
                         clrscr();
                         textcolor(LIGHTBLUE);
                         break;

            case 7:
                          clrscr();
                          ticket_no=accept_ticket_no();
                          clrscr();
                          if(ticket_no!=0)
                          {
                              result=cancel_ticket(ticket_no);
                              if(result==0)
                              {
                                  textcolor(LIGHTRED);
                                  printf("Sorry ! No tickets booked against ticket no %d",ticket_no);
                              }
                              else if(result==1)
                              {
                                  textcolor(LIGHTGREEN);
                                  printf("Ticket number %d successfully cancelled",ticket_no);
                              }
                              else if(result==2)
                              {
                                  textcolor(LIGHTRED);
                                  printf("\nSorry something went wrong !");
                              }
                          }
                          textcolor(WHITE);
                          printf("\nPress any key to go back to the main screen");
                          getch();
                          clrscr();
                          textcolor(LIGHTBLUE);
                          break;
            case 8:
                         clrscr();
                         ptrain_no=accept_train_no();
                         clrscr();
                         if(ptrain_no!=NULL)
                         {
                                result=cancel_train(ptrain_no);
                                 if(result==0)
                                {
                                  textcolor(LIGHTRED);
                                  printf("Sorry ! No tickets booked yet");
                                }
                                else if(result==1)
                                {
                                    textcolor(LIGHTGREEN);
                                    printf("Train number successfully cancelled");
                                }
                                else if(result==2)
                                {
                                    textcolor(LIGHTRED);
                                    printf("\nSorry something went wrong !");
                                }
                         }
                          textcolor(WHITE);
                          printf("\nPress any key to go back to the main screen");
                          getch();
                          clrscr();
                          textcolor(LIGHTBLUE);
                          break;
        default:
                     {
                         textcolor(WHITE);
                         printf("Wrong choice ! try again");
                         getch();
                         clrscr();
                     }
        }
    }
    return 0;
}


