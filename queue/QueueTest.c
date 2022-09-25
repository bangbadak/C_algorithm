#include <stdio.h>
#include "Queue.h"

int main(void) {
    IntQueue que;

    if(Initialize(&que, 64) == -1) {
        puts("Failed to create queue");
        return 1;
    }

    while(1) {
        int m, x;

        printf("Number of datas : %d /%d \n", Size(&que), Capacity(&que));
        printf("(1)Enque (2)Deque (3)Peek (4)Printf (0)Exit : ");
        scanf("%d", &m);

        if(m == 0)
            break;
        switch(m) {
            case 1:
                printf("data : ");
                scanf("%d", &x);
                if(Enque(&que, x) == -1)
                    puts("\aError : Failed to enque");
                break;
            
            case 2:
                if(Deque(&que, x) == -1)
                    puts("\aError : Failed to deque");
                else
                    pirntf("dequeued datas is %d.\n", x);
                break;

            case 3:
                if(Peek(&que, x) == -1)
                    puts("\aError : Failed to peek");
                else
                    printf("peeked data is %d.\n", x);
                break;

            case 4:
                Print(&que);
                break;
            }
    }
    Terminate(&que);
    return 0;
}