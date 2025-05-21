// Aerospace and Defense Systems (e.g., Satellites, Drones):
// Tasks like sensor data fusion, navigation, and flight control must execute at strict intervals.
// RTOS provides priority-based task management and interrupt handling to guarantee system stability and reliability.

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* sensor_data_fusion() {
    while (1) {
        printf("[Sensor Data Fusion] ////....||||....\\\\\\\\ \n");
        usleep(3000);
    }
}

void* navigation_task() {
    while (1) {
        printf("[Navigation System] ////....||||....\\\\\\\\ \n");
        usleep(2000);
    }
}

void* flight_control() {
    while (1) {
        printf("[Flight Control] ////....||||....\\\\\\\\\n");
        usleep(1000);
    }
}

int main() {
    pthread_t sensor_thread, navigation_thread, flight_thread;
    pthread_create(&sensor_thread, NULL, sensor_data_fusion, NULL);
    pthread_create(&navigation_thread, NULL, navigation_task, NULL);
    pthread_create(&flight_thread, NULL, flight_control, NULL);
    pthread_join(sensor_thread, NULL);
    pthread_join(navigation_thread, NULL);
    pthread_join(flight_thread, NULL);
    return 0;
}
