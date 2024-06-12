#include "DoubleHashMap.h"

void DoubleHashMap::insert(int key, int value)  {
    int index = hash1(key);
    int index2 = hash2(key); // DE fakto krok, czyli nie do końca drugi index a dodanie tego kroku do indeksu poniżej da nam drugi index
    int initial_index = index;

    while (occupied[index] && table[index].first != key) {
        index = (index + index2) % TABLE_SIZE;
        if (index == initial_index) {
            throw std::overflow_error("Hash table is full");
        }
    }

    if (!occupied[index]) {
        size++;
    }

    table[index] = std::make_pair(key, value);
    occupied[index] = true;
}

void DoubleHashMap::remove(int key) {
    int index = hash1(key);
    int step = hash2(key);
    int initial_index = index;

    while (occupied[index]) {
        if (table[index].first == key) {
            table[index] = std::make_pair(-1, -1);
            occupied[index] = false;
            size--;
            return;
        }
        index = (index + step) % TABLE_SIZE;
        if (index == initial_index) {
            break;
        }
    }

    throw std::runtime_error("Key not found");
}

void DoubleHashMap::display() const {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (occupied[i]) {
            std::cout << "[" << i << "] -> (" << table[i].first << ", " << table[i].second << ")\n";
        } else {
            std::cout << "[" << i << "] -> (empty)\n";
        }
    }
}