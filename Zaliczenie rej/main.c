#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SAMOCHODY 100
#define DLUGOSC 50

typedef struct {
    char marka[DLUGOSC];
    char model[DLUGOSC];
    int przebieg;
} Samochod;

Samochod samochody[MAX_SAMOCHODY];
int liczba_samochodow = 0;

void dodajSamochod() {
    if (liczba_samochodow >= MAX_SAMOCHODY) {
        printf("Osiągnięto maksymalną liczbę samochodów.\n");
        return;
    }

    printf("Podaj marke samochodu: ");
    scanf("%s", samochody[liczba_samochodow].marka);

    printf("Podaj model samochodu: ");
    scanf("%s", samochody[liczba_samochodow].model);

    printf("Podaj przebieg samochodu: ");
    scanf("%d", &samochody[liczba_samochodow].przebieg);

    liczba_samochodow++;
    printf("Samochod dodany pomyślnie.\n");
}

void wyswietlSamochody() {
    if (liczba_samochodow == 0) {
        printf("Brak zapisanych samochodów.\n");
        return;
    }

    printf("\nLista samochodów:\n");
    for (int i = 0; i < liczba_samochodow; i++) {
        printf("%d. Marka: %s, Model: %s, Przebieg: %d km\n",
               i + 1,
               samochody[i].marka,
               samochody[i].model,
               samochody[i].przebieg);
    }
}

void zapiszDoPliku(const char *nazwaPliku) {
    FILE *plik = fopen(nazwaPliku, "w");
    if (plik == NULL) {
        printf("Blad przy zapisie do pliku.\n");
        return;
    }

    for (int i = 0; i < liczba_samochodow; i++) {
        fprintf(plik, "%s %s %d\n",
                samochody[i].marka,
                samochody[i].model,
                samochody[i].przebieg);
    }

    fclose(plik);
    printf("Dane zapisane do pliku \"%s\".\n", nazwaPliku);
}

void wczytajZPliku(const char *nazwaPliku) {
    FILE *plik = fopen(nazwaPliku, "r");
    if (plik == NULL) {
        printf("Nie mozna otworzyc pliku \"%s\".\n", nazwaPliku);
        return;
    }

    liczba_samochodow = 0;

    while (fscanf(plik, "%s %s %d",
                  samochody[liczba_samochodow].marka,
                  samochody[liczba_samochodow].model,
                  &samochody[liczba_samochodow].przebieg) == 3) {
        liczba_samochodow++;
        if (liczba_samochodow >= MAX_SAMOCHODY) {
            break;
        }
    }

    fclose(plik);
    printf("Dane wczytane z pliku \"%s\".\n", nazwaPliku);
}

int main() {
    int wybor;
    char nazwaPliku[] = "samochody.txt";

    do {
        printf("\n--- MENU ---\n");
        printf("1. Dodaj samochod\n");
        printf("2. Wyswietl samochody\n");
        printf("3. Zapisz do pliku\n");
        printf("4. Wczytaj z pliku\n");
        printf("5. Wyjscie\n");
        printf("Wybierz opcje: ");
        scanf("%d", &wybor);

        switch (wybor) {
            case 1:
                dodajSamochod();
                break;
            case 2:
                wyswietlSamochody();
                break;
            case 3:
                zapiszDoPliku(nazwaPliku);
                break;
            case 4:
                wczytajZPliku(nazwaPliku);
                break;
            case 5:
                printf("Zamykanie programu...\n");
                break;
            default:
                printf("Nieprawidłowy wybor.\n");
        }
    } while (wybor != 5);

    return 0;
}