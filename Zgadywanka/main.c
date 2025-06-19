#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(NULL));      // Inicjalizacja generatora liczb losowych na podstawie czasu
    int randValue = rand() % 20 + 1;        // Wylosowanie liczby z zakresu 1–20
    printf("%d\n", randValue);      // Tymczasowy podgląd wylosowanej liczby (do debugowania)

//    int randValue = rand()%20+1;

    printf("Zgadnij cyfre od 1 do 20.\nPodaj cyfre:\n");           // Wiadomość zachęcająca do zgadywania
    int userValue = 0;      // Zmienna na odpowiedź użytkownika
    scanf("%d", &userValue);        // Odczyt liczby od użytkownika

// Linia wypisująca zgadywaną liczbę użytkownika
//    printf("\n%d\n", userValue);

 // Pętla dopóki użytkownik nie zgadnie liczby
    while(userValue != randValue){
        if(userValue > randValue){
            printf("Nie zgadles. Liczba jest zbyt duza.\nSprobuj jeszcze raz:\n");
        } else{
            printf("Nie zgadles. Liczba jest zbyt mala.\nSprobuj jeszcze raz:\n");
        }
        scanf("%d", &userValue);        // Kolejna próba
    }

    printf("Zgadles!");     // Komunikat po odgadnięciu liczby

    return 0;
}
