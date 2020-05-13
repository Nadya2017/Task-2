#include <stdio.h>
#include "list.h"
#include <stdlib.h>
int main() {
    int x,y,i;
list L = NULL;
for (i = 1; i < 6; i++)
    push(&L, rand() % 20 + 1);
    print(&L);
   menu();
    while (1){
        int action;
        scanf("%d", &action);
        switch (action){
            case 0:
                return 0;
            case 1: {
                scanf("%d", &x);
                push(&L,x);
                break;
            }
            case 2: {
                print(&L);
                break;
            }
            case 3: {
                printf("Vvedite snachala pered kem vstavlyayem, a potom sam element\n");
                scanf("%d %d", &x, &y);
                push_before(&L,x,y);
                break;
            }
            case 4: {
                printf("Vvedite snachala posle kogo vstavlyayem, a potom sam element\n");
                scanf("%d %d", &x, &y);
                push_after(&L,x,y);
                break;
            }
            case 5: {
                scanf("%d", &x);
                push_end(&L,x);
                break;
            }
            case 6: {
                pop(&L);
                break;
            }
            case 7: {
                pop_end(&L);
                break;
            }
            case 8: {
                scanf("%d", &x);
                pop_num(&L,x);
                break;
            }
            case 9: {
                printf("Vvedite snachala element, kotoryy vstavlyayem, a zatem element, posle kotorogo vstavlyayem\n");
                scanf("%d %d", &x, &y);
                individual(&L,x,y);
                break;
    }
    return 0;
}
}
}



