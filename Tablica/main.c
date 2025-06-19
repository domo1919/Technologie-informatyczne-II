#include <stdio.h>

// #define length 10

int main(){
    // Inicjalizacja tablicy 10-elementowej z wartościami całkowitymi
    int array[10] = {13, 254, 31, 41, 35, 62, 75, 78, 94, 20};

    int i = 0;

    // Pętla wypisująca wszystkie wartości z tablicy
    for(i = 0; i < 10; i++) {
        printf("wartosci tablicy: %d\n", array[i]);
    }

    int sum = 0;

    // Pętla obliczająca sumę wszystkich elementów tablicy
    for(i = 0; i < 10; i++){
        sum = sum + array[i];
    }
    printf("Suma: %d\n", sum);

 //   float sumF

    // Obliczenie średniej arytmetycznej z elementów tablicy
    // float sumF  // Komentarzowany fragment nieużywanej zmiennej
    float average = (float) sum / 10;

    printf("Srednia: %f\n", average);

    // Znalezienie najmniejszej wartości w tablicy
    int minArrValue = array[0];     // Założenie: pierwszy element jest najmniejszy

    for(int i = 0; i < 9; i++){     // Iteracja do przedostatniego elementu
        if (minArrValue > array[i + 1]){        // Porównanie z kolejnym elementem
            minArrValue = array[i + 1];         // Aktualizacja najmniejszej wartości
        }
    }

    printf("Wartosc minimalna: %d\n", minArrValue);


    return 0;
}
