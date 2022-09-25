#include "stdio.h"
#include "stdlib.h"

int Search(const int a[], int n, int key) {
    int i = 0;
    while(1) {
        if(i == n)
            return -1;
        if(a[i] == key)
            return i;
        i++;
    }
}

int main(void) {
    int i, nx, ky, idx;
    int *x;

    puts("선형 검색");
    printf("요소 개수 : ");
    scanf("%d", &nx);
    x = calloc(nx, sizeof(int));
    for(i = 0; i < nx; i++) {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }
    printf("검색값 : ");
    scanf("%d", &ky);
    idx = Search(x, nx, ky);
    if(idx == -1)
        puts("검색 실패");
    else
        printf("%d는 x[%d]에 있다.", ky, idx);
    free(x);

    return 0;
}