#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(NULL));
    int randValue = rand() % 20 + 1;
    printf("%d\n", randValue);

//    int randValue = rand()%20+1;

    printf("Zgadnij cyfre od 1 do 20.\nPodaj cyfre:\n");
    int userValue = 0;
    scanf("%d", &userValue);
//    printf("\n%d\n", userValue);

    while(userValue != randValue){
        if(userValue > randValue){
            printf("Nie zgadles. Liczba jest zbyt duza.\nSprobuj jeszcze raz:\n");
        } else{
            printf("Nie zgadles. Liczba jest zbyt mala.\nSprobuj jeszcze raz:\n");
        }
        scanf("%d", &userValue);
    }

    printf("Zgadles!");

    return 0;
}
