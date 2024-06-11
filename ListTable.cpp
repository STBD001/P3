#include "ListTable.h"

void ListTable::insert(int key, int value) {
    int index = hashFunction(key);
    Node* newNode = new Node(key, value);

    // czy na indexie jest lista wiązana
    if (table[index] == nullptr) {
        // if Brak listy, tworzymy nową
        table[index] = newNode;
    }
    else {
        // Lista istnieje, dodajemy nowy element na jej koniec
        Node* current = table[index];
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void ListTable::remove(int key) {
    int index = hashFunction(key);

    if (table[index] == nullptr) {
        std::cout << "Klucz nie został znaleziony!" << std::endl;
        return;
    }

    Node* current = table[index];
    Node* previous = nullptr;

    // już jest klucz, zwykłe przesuwanie się listą wiązaną
    while (current != nullptr && current->key != key) {
        previous = current;
        current = current->next;
    }

    // jeśli lista istnieje, przechodzi przez,by znaleźć węzeł z danym kluczem.
    // następnie - węzeł z listy
    if (current != nullptr) { // czy jest węzeł
        if (previous == nullptr) { // czy znaleziony na początku listy
            // Klucz znajduje się na początku listy
            table[index] = current->next; // table[index] - > $wskaźnik na początek listy$
            // zostanie ustawiony na current->next, czyli na następny węzeł po current.
            // W ten sposób pomijamy current i usuwamy go z listy.
        }
        else {
            // też pomija current
            previous->next = current->next;
        }
        delete current;
        std::cout << "Klucz usunięty!" << std::endl;
    }
//    else {
//        std::cout << "Klucz nie został znaleziony!" << std::endl;
//    }
}

void ListTable::display() const{
    for (int i = 0; i < TABLE_SIZE; ++i) {
        if (table[i] != nullptr) {
            // std::cout << "Indeks " << i << ": ";
            Node* current = table[i];
            while (current != nullptr) {
                //std::cout << "(" << current->key << ", " << current->value << ") ";
                std::cout<< current->key << " " << current->value;
                current = current->next;
            }
            std::cout << std::endl;
        }
    }
}
