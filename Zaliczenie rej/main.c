#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CARS 100
#define TEXT_LENGTH 50

// Struktura przechowująca dane o samochodzie
typedef struct {
    char brand[TEXT_LENGTH];
    char model[TEXT_LENGTH];
    int mileage;
} Car;

Car cars[MAX_CARS];
int carCount = 0;

// Dodawanie nowego samochodu przez użytkownika
void addCar() {
    if (carCount >= MAX_CARS) {
        printf("Osiągnięto maksymalną liczbę samochodów.\n");
        return;
    }

    printf("Podaj marke samochodu: ");
    scanf("%s", cars[carCount].brand);

    printf("Podaj model samochodu: ");
    scanf("%s", cars[carCount].model);

    printf("Podaj przebieg samochodu: ");
    scanf("%d", &cars[carCount].mileage);

    carCount++;
    printf("Samochod dodany pomyślnie.\n");
}

// Wyświetlanie wszystkich zapisanych samochodów
void showCars() {
    if (carCount == 0) {
        printf("Brak zapisanych samochodów.\n");
        return;
    }

    printf("\nLista samochodów:\n");
    for (int i = 0; i < carCount; i++) {
        printf("%d. Marka: %s, Model: %s, Przebieg: %d km\n",
               i + 1,
               cars[i].brand,
               cars[i].model,
               cars[i].mileage);
    }
}

// Zapis danych do pliku tekstowego
void saveToFile(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Blad przy zapisie do pliku.\n");
        return;
    }

    for (int i = 0; i < carCount; i++) {
        fprintf(file, "%s %s %d\n",
                cars[i].brand,
                cars[i].model,
                cars[i].mileage);
    }

    fclose(file);
    printf("Dane zapisane do pliku \"%s\".\n", filename);
}

// Wczytanie danych z pliku tekstowego
void loadFromFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Nie mozna otworzyc pliku \"%s\".\n", filename);
        return;
    }

    carCount = 0;

    while (fscanf(file, "%s %s %d",
                  cars[carCount].brand,
                  cars[carCount].model,
                  &cars[carCount].mileage) == 3) {
        carCount++;
        if (carCount >= MAX_CARS) {
            break;
        }
    }

    fclose(file);
    printf("Dane wczytane z pliku \"%s\".\n", filename);
}

// Funkcja główna – menu użytkownika
int main() {
    int choice;
    char filename[] = "samochody.txt";

    do {
        printf("\n--- MENU ---\n");
        printf("1. Dodaj samochod\n");
        printf("2. Wyswietl samochody\n");
        printf("3. Zapisz do pliku\n");
        printf("4. Wczytaj z pliku\n");
        printf("5. Wyjscie\n");
        printf("Wybierz opcje: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addCar();
                break;
            case 2:
                showCars();
                break;
            case 3:
                saveToFile(filename);
                break;
            case 4:
                loadFromFile(filename);
                break;
            case 5:
                printf("Zamykanie programu...\n");
                break;
            default:
                printf("Nieprawidłowy wybor.\n");
        }
    } while (choice != 5);

    return 0;
}
