#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_REQUESTS 100

// Function to calculate FCFS (First-Come, First-Served) Disk Scheduling
void calculate_fcfs(int requests[], int n, int initial_head) {
    int total_seek_movement = 0;
    int current_head = initial_head;

    printf("\n--- FCFS Disk Scheduling ---\n");
    printf("Traversal Sequence: %d", current_head);

    for (int i = 0; i < n; i++) {
        total_seek_movement += abs(requests[i] - current_head);
        current_head = requests[i];
        printf(" -> %d", current_head);
    }
    printf("\nTotal Seek Head Movement: %d cylinders\n", total_seek_movement);
}

// Function to calculate SSTF (Shortest Seek Time First) Disk Scheduling
void calculate_sstf(int requests[], int n, int initial_head) {
    int total_seek_movement = 0;
    int current_head = initial_head;
    int visited[MAX_REQUESTS] = {0};

    printf("\n--- SSTF Disk Scheduling ---\n");
    printf("Traversal Sequence: %d", current_head);

    for (int i = 0; i < n; i++) {
        int min_distance = 999999;
        int closest_index = -1;

        // Find the unvisited request closest to the current head position
        for (int j = 0; j < n; j++) {
            if (!visited[j]) {
                int distance = abs(requests[j] - current_head);
                if (distance < min_distance) {
                    min_distance = distance;
                    closest_index = j;
                }
            }
        }

        // Mark as visited and update head
        visited[closest_index] = 1;
        total_seek_movement += min_distance;
        current_head = requests[closest_index];
        printf(" -> %d", current_head);
    }
    printf("\nTotal Seek Head Movement: %d cylinders\n", total_seek_movement);
}

int main() {
    int n, initial_head;
    int requests[MAX_REQUESTS];

    printf("==================================================\n");
    printf("       DISK SCHEDULING ALGORITHM SIMULATOR        \n");
    printf("==================================================\n");

    printf("Enter number of disk I/O requests: ");
    if (scanf("%d", &n) != 1 || n <= 0 || n > MAX_REQUESTS) {
        printf("[!] Invalid number of requests.\n");
        return 1;
    }

    printf("Enter the request queue sequence (space-separated): ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }

    printf("Enter initial disk head position: ");
    scanf("%d", &initial_head);

    // Execute algorithms
    calculate_fcfs(requests, n, initial_head);
    calculate_sstf(requests, n, initial_head);

    printf("==================================================\n");
    return 0;
}
