#ifndef SD_3_DOUBLEHASHMAP_H
#define SD_3_DOUBLEHASHMAP_H


#include <iostream>
#include <vector>

#include <stdexcept>
#include "Map.h"

const int TABLE_SIZE = 101;  // dla lepszej dystrybucji

class DoubleHashMap : public Map {
private:
    std::vector<std::pair<int, int>> table;
    std::vector<bool> occupied;
    int size;

    int hash1(int key) const {
        return key % TABLE_SIZE;
    }

    int hash2(int key) const {
        return 1 + (key % (TABLE_SIZE - 2));
    }

public:
    DoubleHashMap() : table(TABLE_SIZE, std::make_pair(-1, -1)), occupied(TABLE_SIZE, false), size(0) {}

    void insert(int key, int value) override;

    void remove(int key) override;

    void display() const override;
};

#endif //SD_3_DOUBLEHASHMAP_H
