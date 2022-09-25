#include <stdio.h>
#include <stdlib.h>

int BinSearch(const int a[], int n, int key) {
    int pl = 0;
    int pr = n - 1;
    int pc;
    do {
        pc = (pl + pr) / 2;
        if(a[pc] == key)
            return pc;
        else if(a[pc] < key)
            pl = pc + 1;
        else
            pr = pc - 1;
    } while (pl <= pr);
    return -1;
}

int main(void) {
    int i, nx, ky, idx;
    int *x;

    puts("Binary Search");
    printf("Number of elements : ");
    scanf("%d", &nx);

    x = calloc(nx, sizeof(int));
    printf("input sorted by ascedning order\n");
    printf("x[0] : ");
    scanf("%d", &x[0]);
    for (i = 1; i < nx; i++) {
        do {
            printf("x[%d] : ", i);
            scanf("%d", &x[i]);
        } while (x[i] < x[i - 1]);
    }
    printf("검색값 : ");
    scanf("%d", &ky);
    idx = BinSearch(x, nx, ky);
    if(idx == -1)
        puts("failed to find");
    else
        printf("%d is at x[%d]", ky, idx);
    free(x);
    return 0;
}