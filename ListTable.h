
#ifndef SD_3_LISTTABLE_H
#define SD_3_LISTTABLE_H
#include "Map.h"
#include <iostream>

struct Node {
    // każdy el. listy wiązanej
    int key;
    int value;
    Node* next;

    Node(int key, int value) : key(key), value(value), next(nullptr) {}
};

class ListTable : public Map {
private:
    static const int TABLE_SIZE = 100; // nawet jeśli liczba wstawionych elementów przekracza rozmiar tabeli
    // (w tym przypadku 100), tabela mieszająca poradzi sobie z tym, umieszczając wiele elementów w tym samym kub.
    // Elementy te utworzą połączoną listę w indeksie tego segmentu.
    Node* table[TABLE_SIZE]; // Tablica wskaźników na listy wiązane

    // Funkcja mieszająca
    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

public:
    ListTable() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            table[i] = nullptr;
        }
    }

    void insert(int key, int value) override;
    void remove(int key) override;
    void display()const override;
};

#endif //SD_3_LISTTABLE_H
