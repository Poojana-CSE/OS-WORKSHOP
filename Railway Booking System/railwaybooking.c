#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#define MAX_TICKET 5
int available_tickets = MAX_TICKET;

// sem_t, sem_wait, sem_trywait, sem_timedwait.
sem_t ticket_lock;

// void book_ticket(int user_id){ // user_id = 1001
// data type should not be used.
// void do not store the data but it can hold address

void* book_ticket(void* arg) {
    int user_id = *(int*)arg;

    sem_wait(&ticket_lock);
    if (available_tickets > 0) {
        printf("User id %d booked the ticket\n", user_id);
        available_tickets--;
    } else {
        printf("User id %d: No tickets available\n", user_id);
    }
    sem_post(&ticket_lock);

    return NULL;
}

int main() {
    pthread_t user[10];
    int user_id[10];
    sem_init(&ticket_lock, 0, 1);

    for (int i = 0; i < 10; i++) {
        user_id[i] = i + 1;
        // for a user create memory so "&", No attributes so null, funtion name, arguments
        // For memory allocation use pthread_create.
        pthread_create(&user[i], NULL, book_ticket, (void*)&user_id[i]);
    }

    for (int i = 0; i < 10; i++) {
        // Call the thread, same attribute story for null.
        // to activate the thread need join.
        pthread_join(user[i], NULL);
    }

    sem_destroy(&ticket_lock);
    return 0;
}

