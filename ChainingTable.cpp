#include "ChainingTable.h"

void ChainingTable::insert(int key, int value) {
    int index = hashFunction(key);
    KeyValuePair* newNode = new KeyValuePair;
    newNode->key = key;
    newNode->value = value;
    newNode->next = nullptr;

    if (table[index] == nullptr) {
        // Brak kolizji, wstawiamy nowy element jako pierwszy w łańcuchu
        table[index] = newNode;
    }
    else {
        // Kolizja, standardowo dodajemy nowy element na koniec łańcucha
        KeyValuePair* current = table[index];
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void ChainingTable::remove(int key) {
    int index = hashFunction(key);
    KeyValuePair* current = table[index];
    KeyValuePair* previous = nullptr;

    while (current != nullptr) {
        if (current->key == key) {
            // Znaleziono klucz, usuwamy odpowiadającą mu parę
            if (previous == nullptr) {
                // Element do usunięcia jest pierwszy w łańcuchu
                table[index] = current->next;
            }
            else {
                // Element do usunięcia nie jest pierwszy w łańcuchu
                previous->next = current->next;
            }
            delete current;
            return;
        }
        // następny el
        previous = current;
        current = current->next;
    }

    std::cout << "Klucz nie został znaleziony!" << std::endl;
}

void ChainingTable::display() const {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        KeyValuePair* current = table[i];
        if (current != nullptr) {
            std::cout << "Indeks " << i << ": ";
            while (current != nullptr) {
                std::cout << "(" << current->key << ", " << current->value << ") ";
                current = current->next;
            }
            std::cout << std::endl;
        }
    }
}
