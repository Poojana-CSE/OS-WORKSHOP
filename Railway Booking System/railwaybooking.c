#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#define MAX_TICKET 5
int available_tickets = MAX_TICKET;
// sem_t, sem_wait, sem_trywait, sem_timedwait.

sem_t ticket_lock;

void book_ticket(int user_id){ // user_id = 1001
    sem_wait(&ticket_lock); // 0(No. of tickets) (A15)
    if(ticket_lock < available_tickets){

    }
    else if(ticket_lock > available_tickets){

    }
}