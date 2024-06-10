#include <iostream>

// Klasa reprezentująca tablicę mieszającą z adresowaniem otwartym
class HashTable {
private:
    static const int TABLE_SIZE = 100; // Rozmiar tablicy mieszającej
    int* keys; // Tablica kluczy
    int* values; // Tablica wartości
    bool* occupied; // Tablica flag zajętości
    int* probingSequence; // Tablica sekwencji próbkowania
    int currentSize; // Aktualny rozmiar tablicy

    // Funkcja mieszająca
    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

    // Funkcja próbkowania liniowego
    int linearProbe(int index, int attempt) {
        return (index + attempt) % TABLE_SIZE;
    }

public:
    HashTable() {
        keys = new int[TABLE_SIZE]();
        values = new int[TABLE_SIZE]();
        occupied = new bool[TABLE_SIZE]();
        probingSequence = new int[TABLE_SIZE]();
        currentSize = 0;
    }

    // Funkcja wstawiająca nową parę klucz-wartość
    void insert(int key, int value) {
        if (currentSize == TABLE_SIZE) {
            std::cout << "Tablica mieszająca jest pełna!" << std::endl;
            return;
        }

        int index = hashFunction(key);
        int attempt = 0;

        while (occupied[index]) {
            // Wybieramy kolejną pozycję za pomocą funkcji próbkowania
            index = linearProbe(index, ++attempt);
        }

        // Wstawiamy klucz i wartość na wybraną pozycję
        keys[index] = key;
        values[index] = value;
        occupied[index] = true;
        probingSequence[index] = attempt;
        currentSize++;
    }

    // Funkcja usuwająca parę związaną z kluczem
    void remove(int key) {
        int index = hashFunction(key);
        int attempt = 0;

        // Szukamy pozycji klucza
        while (occupied[index] && keys[index] != key && attempt < TABLE_SIZE) {
            index = linearProbe(index, ++attempt);
        }

        // Usuwamy klucz i wartość jeśli znaleziono
        if (keys[index] == key) {
            keys[index] = 0;
            values[index] = 0;
            occupied[index] = false;
            currentSize--;
            std::cout << "Klucz usunięty!" << std::endl;
        }
        else {
            std::cout << "Klucz nie został znaleziony!" << std::endl;
        }
    }

    // Funkcja wyświetlająca zawartość tablicy mieszającej
    void display() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            if (occupied[i]) {
                std::cout << "Index " << i << ": (" << keys[i] << ", " << values[i] << ")" << std::endl;
            }
        }
    }
};

int main() {
    HashTable hashTable;

    // Dodajemy kilka par klucz-wartość
    hashTable.insert(1, 10);
    hashTable.insert(2, 20);
    hashTable.insert(101, 30); // Kolizja z kluczem 1
    hashTable.insert(102, 40); // Kolizja z kluczem 2

    // Wyświetlamy zawartość tablicy mieszającej
    hashTable.display();

    // Usuwamy parę związaną z kluczem 2
    hashTable.remove(2);

    // Ponownie wyświetlamy zawartość tablicy mieszającej po usunięciu
    std::cout << "Po usunięciu:" << std::endl;
    hashTable.display();

    return 0;
}
