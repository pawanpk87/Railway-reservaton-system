#ifndef RLYRES_H_INCLUDED
#define RLYRES_H_INCLUDED
struct Train
{
    char train_no[10];
    char from[10];
    char to[10];
    int fac_fare;
    int sac_fare;
};
struct Passenger
{
    char p_name[20];
    char gender;
    char p_class;
    char train_no[10];
    char address[30];
    int age;
    int ticketno;
    char mob_no[11];
};
typedef struct Train Train;
typedef struct Passenger Passenger;

int enterchoice();
void add_trains();
Passenger* get_passenger_details();
int check_train_no(char*);
int check_mob_no(char*);
void view_trains();
int get_booked_ticket(char*,char);
int last_ticket_no();
int book_ticket();
int accept_ticket_no();
void view_ticket(int);
char* accept_mob_no();
int* get_ticket_no(char*);
void view_all_tickets(char*,int*);
char* accept_train_no();
void view_booking(char*);
void view_all_bookings();
int cancel_ticket(int);
int cancel_train(char*);


#endif // RLYRES_H_INCLUDED
