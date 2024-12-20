#include <stdio.h>

void mergeSortedArrays(int a[], int m, int b[], int n, int new[]);

int main() {
    int a[] = {1, 3, 5, 7, 9, 11, 13, 31};
    int b[] = {2, 4, 6, 8, 10};
    int len_a = sizeof(a) / sizeof(a[0]);
    int len_b = sizeof(b) / sizeof(b[0]);
    int len_new = len_b + len_a;
    int new[len_new];

    printf("数组 a: ");
    for (int i = 0; i < len_a; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    printf("数组 b: ");
    for (int i = 0; i < len_b; i++) {
        printf("%d ", b[i]);
    }
    printf("\n");

    mergeSortedArrays(a, len_a, b, len_b, new);

    printf("合并后的数组: ");
    for (int i = 0; i < len_new; i++) {
        printf("%d ", new[i]);
    }
    printf("\n");

    return 0;
}

void mergeSortedArrays(int a[], int len_a, int b[], int len_b, int new[]) {
    int i = 0, j = 0, k = 0;
    while (i < len_a && j < len_b) {
        if (a[i] <= b[j]) {
            new[k++] = a[i++];
        } else {
            new[k++] = b[j++];
        }
    }
    while (i < len_a) {
        new[k++] = a[i++];
    }
    while (j < len_b) {
        new[k++] = b[j++];
    }
}
