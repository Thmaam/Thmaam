#include <stdio.h>  
#include <stdlib.h>  
#include <math.h>
#include <time.h> 

int random_Numbers(){
    int input;     
    printf("enter how many numbers do you want to print\n");
    scanf("%d", &input);   
    for (int i = 0; i < input; i++)  
    {  
        printf(" %d\n", rand());
    }   
}

void bubble_sort(int random_array[], int number_Of_Elements) {
    int i = 0, j = 0, tmp;
    for (i = 0; i < number_Of_Elements; i++) {   // loop n times - 1 per element
        for (j = 0; j < number_Of_Elements - i - 1; j++) { // last i elements are sorted already
            if (random_array[j] > random_array[j + 1]) {  // swop if order is broken
                tmp = random_array[j];
                random_array[j] = random_array[j + 1];
                random_array[j + 1] = tmp;
            }
        }
    }
}
int print_Bubble_sort(int random_array[], int number_Of_Elements) {
    int i, d, swap;    
    printf("Enter number of elements in the array: ");
    scanf("%d", &number_Of_Elements); 
    for (i = 0; i < number_Of_Elements; i++)
        rand();
    bubble_sort(random_array,number_Of_Elements);
    printf("Printing the sorted array:\n");
    for (i = 0; i < number_Of_Elements; i++)
        printf("%d\n", random_array[i]);
}

void init_insertion_Sort(int array_numbers[], int elements)
{
    int i, key, j;
    for (i = 1; i < elements; i++) {
        key = array_numbers[i];
        j = i - 1;
 
        while (j >= 0 && array_numbers[j] > key) {
            array_numbers[j + 1] = array_numbers[j];
            j = j - 1;
        }
        array_numbers[j + 1] = key;
    }
}

int print_random_Array(int array_numbers[],int elements)
{
    int i;
    printf("Enter how many elements you want to insert: ");
    scanf("%d", &elements);
    for (i = 0; i < elements; i++)
        rand();
    init_insertion_Sort(array_numbers, elements);
    for (i = 0; i < elements; i++)
        printf("%d\n", array_numbers[i]);

}
 
int selection_sort()
{
    int a[100], number, i, j, temp;
    printf("\n Please Enter the total Number of Elements  :  ");
    scanf("%d", &number);
    for(i = 0; i < number; i++)
        rand();

    for(i = 0; i < number; i++) {
        for(j = i + 1; j < number; j++) {
            if(a[i] > a[j]) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    printf("\n Selection Sort Result : ");
    for(i = 0; i < number; i++)  {
        printf(" %d \t", a[i]);
    }
    printf("\n");
    return 0;
}