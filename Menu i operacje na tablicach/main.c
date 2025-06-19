#include <stdio.h>

#define SIZE 10      // stała określająca długość tablic


// Tablica z danymi stałymi (wbudowana)
int arrayConst[] = {1, 5, 4, 4, 8, 48, 122, 47, 55, 42,};

// Tablica do wypełnienia przez użytkownika
int arrayUser[SIZE];

// Wskaźnik na aktualnie używaną tablicę oraz jej nazwa
int* activeArray = arrayConst; 
char activeName[20] = "arrayConst";

// Deklaracje funkcji pomocniczych
void menu();
void sort(int arrTemp[], int size);
void showArray();
void fillUserArray();
int sum(int array[], int size);
int foundMinimum(int array[], int size);
int foundMaximum(int array[], int size);
float median(int array[], int size);
void opPrint();

int main() {
    // opPrint();
    int option = 0;

    //int c = 0;

//     do {
// //        menu();
//         scanf("%d", &option);
//         switch (option) {
//             case 0:
//                 break;
//             case 1:
//                 showArray();
//                 break;
//             case 2:
//                 foundMaximum();
//                 break;
//         }
//     } while (c = 0);

    // Pętla główna programu – menu wykonuje się aż do wybrania opcji 6 (wyjście)
    do {
        opPrint();
        printf("\nPodaj opcje (0–6): ");
        scanf("%d", &option);
        float med = 0.0;
        switch (option) {
            case 0: {       // wybór aktywnej tablicy do operacji
                int wybor;
                printf("Wybierz tablice:\n1. arrayConst\n2. arrayUser\n");
                scanf("%d", &wybor);
                if (wybor == 1) {
                    activeArray = arrayConst;
                    sprintf(activeName, "arrayConst");
                } else if (wybor == 2) {
                    activeArray = arrayUser;
                    sprintf(activeName, "arrayUser");
                } else {
                    printf("Nieprawidłowy wybór. Pozostaje %s.\n", activeName);
                }
                break;
                }

            case 1:
                showArray();        // wyświetl zawartość obu tablic
                break;
            case 2: {        // oblicz minimum dla aktywnej tablicy
                int min = foundMinimum(activeArray, SIZE);
                printf("Minimum tablicy: %d\n", min);
                break;
            }
            case 3: {       // oblicz maksimum
                int max = foundMaximum(activeArray, SIZE);
                printf("Maksimum tablicy: %d\n", max);
                break;
            }
            case 4: {       // suma wszystkich wartości
                int total = sum(activeArray, SIZE);
                printf("Suma tablicy: %d\n", total);
                break;
            }
            case 5:      // mediana
                med = median(activeArray, SIZE);
                printf("Mediana tablicy: %.2f\n", med);
                break;

            case 6:      // wyjście
                printf("Wyjście z programu.\n");
                break;

            case 7:     // wprowadzenie danych przez użytkownika
                fillUserArray();
                break;

            default:
                printf("Nieprawidlowa opcja.\n");
        }
    } while (option != 6);


return 0;
}


void opPrint(){
    // Wyświetla menu oraz nazwę aktualnie wybranej tablicy
    printf("Menu\n");
    printf("Wybierz jedna z ponizszych opcji:\n");
    printf("0. Wybierz tablice do operacji (aktualnie: %s)\n", activeName);
    printf("1. Pokaz istniejace tablice.\n");
    printf("2. Znajdz minimum.\n");
    printf("3. Znajdz maksimum.\n");
    printf("4. Oblicz sume.\n");
    printf("5. Oblicz mediane.\n");
    printf("6. Wyjscie z programu.\n");
    printf("7. Wprowadz dane do tablicy uzytkownika.\n");
}

void sort(int arrTemp[], int size){
    // Sortowanie
    int j, temp;
    for(int i = 0; i < size - 1; i++){
        for(j = 0; j < size - i - 1; j++){
            if(arrTemp[j] > arrTemp[j + 1]){
                temp = arrTemp[j];
                arrTemp[j] = arrTemp[j+1];
                arrTemp[j+1] = temp;
            }
        }
    }
}

void showArray(){
    // Wyświetla zawartość obu tablic (oryginalnej i użytkownika)
    printf("Wartosci Tab1:\n");

    for (int i = 0; i < SIZE; i++) {
        printf("%d\n", arrayConst[i]);
    }

    printf("Wartosci Tab2:\n");

    for (int i = 0; i < SIZE; i++) {
        printf("%d\n", arrayUser[i]);
    }
}

void fillUserArray() {
    // Pozwala użytkownikowi wpisać wartości do tablicy arrayUser
    printf("Wprowadz %d liczb do tablicy użytkownika:\n", SIZE);
    for (int i = 0; i < SIZE; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arrayUser[i]);
    }
}

int sum(int array[], int size){
    // Zwraca sumę wszystkich elementów tablicy
    int total = 0;
    for (int i = 0; i < size; i++){
        total += array[i];
    }
    return total;
}

int foundMaximum(int array[], int size){
    // Znajduje największą wartość w tablicy
    int maximum = array[0];
    for (int i = 1; i < size; i++){
        if (array[i] > maximum){
            maximum = array[i];
        }
    }
    return (maximum);
}

int foundMinimum(int array[], int size){
    // Znajduje najmniejszą wartość w tablicy
    int minimum = array[0];
    for (int i = 1; i < size; i++){
        if (array[i] < minimum){
            minimum = array[i];
        }
    }
    return minimum;
}

float median(int array[], int size){
    // Oblicza medianę tablicy (po wcześniejszym skopiowaniu i posortowaniu)
    int temp[SIZE];
    
        for(int i = 0; i < size; i++){
        temp[i] = array[i];
    }

        sort(temp, size);

    if (size % 2 == 0) {
        return (temp[size/2 - 1] + temp[size/2]) / 2.0;
    } else {
        return temp[size/2];
    }
}

