// Medical Devices (eg., Heart Rate Monitors, Insulin Pumps): These devices continuously monitor and respond to patient data.
// RTOS ensures deterministic behaviour, so that data collection and actions (like insulin delivery) happen exactly on time, avoiding patient risk

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* heart_rate_monitor() {
    while (1) {
        printf("[Heart Rate Monitor] ....////....||||....\\\\\\\\\n");
        usleep(1);
    }
}

void* insulin_pumps() {
    while (1) {
        printf("[Checking Glucose Level]....////....||||....\\\\\\\\\n");
        usleep(3);
        printf("[Insulin Pump] Inserting insulin...////....||||....\\\\\\\\\n");
        usleep(2);
    }
}

void* alert_message() {
    while (1) {
        printf("[ALERT] Checking patient status...OK\n");
        usleep(3);
    }
}

int main() {
    pthread_t heart_thread, insulin_thread, message_thread;

    pthread_create(&heart_thread, NULL, heart_rate_monitor, NULL);
    pthread_create(&insulin_thread, NULL, insulin_pumps, NULL);
    pthread_create(&message_thread, NULL, alert_message, NULL);

    pthread_join(heart_thread, NULL);
    pthread_join(insulin_thread, NULL);
    pthread_join(message_thread, NULL);

    return 0;
}
