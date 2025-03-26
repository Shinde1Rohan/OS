#include <stdio.h>
#include <stdlib.h>
void SCAN(int disk[], int n, int head, int direction) {
    int total_movement = 0;
    int left = 0, right = 0;

    int left_requests[n], right_requests[n];
    int left_index = 0, right_index = 0;

    for (int i = 0; i < n; i++) {
        if (disk[i] < head)
            left_requests[left_index++] = disk[i];
        else
            right_requests[right_index++] = disk[i];
    }

    for (int i = 0; i < left_index - 1; i++) {
        for (int j = i + 1; j < left_index; j++) {
            if (left_requests[i] < left_requests[j]) {
                int temp = left_requests[i];
                left_requests[i] = left_requests[j];
                left_requests[j] = temp;
            }
        }
    }

    for (int i = 0; i < right_index - 1; i++) {
        for (int j = i + 1; j < right_index; j++) {
            if (right_requests[i] > right_requests[j]) {
                int temp = right_requests[i];
                right_requests[i] = right_requests[j];
                right_requests[j] = temp;
            }
        }
    }
    if (direction == 0) {  
        total_movement += head - left_requests[left_index - 1];
        head = left_requests[left_index - 1];

        for (int i = left_index - 1; i >= 0; i--) {
            total_movement += abs(head - left_requests[i]);
            head = left_requests[i];
        }
        for (int i = 0; i < right_index; i++) {
            total_movement += abs(head - right_requests[i]);
            head = right_requests[i];
        }
    } else {
        total_movement += right_requests[right_index - 1] - head;
        head = right_requests[right_index - 1];

        for (int i = right_index - 1; i >= 0; i--) {
            total_movement += abs(head - right_requests[i]);
            head = right_requests[i];
        }
        for (int i = left_index - 1; i >= 0; i--) {
            total_movement += abs(head - left_requests[i]);
            head = left_requests[i];
        }
    }
    printf("Total head movement: %d\n", total_movement);
}
int main() {
    int n, head, direction;
    printf("Enter number of disk requests: ");
    scanf("%d", &n);
    int disk[n];
    printf("Enter the disk requests: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &disk[i]);
    }
    printf("Enter the current head position: ");
    scanf("%d", &head);
    printf("Enter the direction (0 for left, 1 for right): ");
    scanf("%d", &direction);
    SCAN(disk, n, head, direction);
    return 0;
}

