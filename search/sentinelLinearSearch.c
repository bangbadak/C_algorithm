#include <stdio.h>
#include <stdlib.h>

int Search(int a[], int n, int key) {
    int i = 0;
    a[n] = key;
    while(1) {
        if(a[i] == key)
            break;
        i++;
    }
    return i == n ? -1 : i;
}

int main(void) {
    int i, nx, ky, idx;
    int *x;

    puts("Sentinel Linear Search");
    printf("number of elements : ");
    scanf("%d", &nx);

    x = calloc(nx + 1, sizeof(int));
    for (i = 0; i < nx; i++) {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }

    printf("검색값 : ");
    scanf("%d", &ky);
    idx = Search(x, nx, ky);

    if(idx == -1)
        puts("failed to find");
    else
        printf("%dis at x[%d]", ky, idx);
    free(x);

    return 0;
}