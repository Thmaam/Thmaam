#include <stdlib.h>
#include "dsa.h"

void many(){
    printf("******ALGORITHM MENU*******\n");
    printf("1.BUBBLE SORT\n");
    printf("2.INSERTION SORT\n");
    printf("3.RADIX SORT\n");
    printf("EXIT\n");
}

int main(){
    int manuinput;
    int run = 1;
    int number_Of_Elements, elements;
    int random_array[0], array_numbers[0];
    while(run){
        many();
        scanf("%d", &manuinput);
        switch(manuinput){
                case 1:
                    print_Bubble_sort(random_array,number_Of_Elements);
                    getchar();
                break;

                case 2:
                    print_random_Array(array_numbers,elements);
                    getchar();
                break;

                case 3:
                    selection_sort();
                    
                break;
                case 4:
                    run = 0;

                break;
                default:
                    printf("Wrong input");
            }
    }
    return 0;
}