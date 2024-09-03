#include <stdio.h>

void findZeroSumSubarrays(int arr[], int n) {
    int found = 0;

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += arr[j];
            if (sum == 0) {
                found = 1;
                for (int k = i; k <= j; k++) {
                    printf("%d ", arr[k]);
                }
                printf("\n");
            }
        }
    }

    if (!found) {
        printf("[]\n");
    }
}

int main() {
    int n;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    findZeroSumSubarrays(arr, n);

    return 0;
}
