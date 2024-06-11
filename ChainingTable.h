#ifndef SD_3_CHAININGTABLE_H
#define SD_3_CHAININGTABLE_H

#include "Map.h"
#include <iostream>

// w sumie to samo node, można go nazwać tak i zrobić dla każdej z funkcji, tu po prostu lepiej rozróżnić
struct KeyValuePair {
    int key;
    int value;
    KeyValuePair* next;
};

class ChainingTable : public Map {
private:
    static const int TABLE_SIZE = 100;
    KeyValuePair* table[TABLE_SIZE];

    // Funkcja mieszająca
    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

public:
    ChainingTable() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            table[i] = nullptr;
        }
    }

    void insert(int key, int value) override;
    void remove(int key) override;
    void display()const override;
};


#endif //SD_3_CHAININGTABLE_H
