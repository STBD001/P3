#ifndef SD_3_MAP_H
#define SD_3_MAP_H

// nie ma klucza - utworz i przypisz nowy
// przypisanie nowej wartosci do istniejacego klucza = zastapi poprzednia wartosc
// klucze typu: , wartosci typu:

class Map {
// ?? czy bool może bo debugowanie gdy klucze kolidują by dalej przechodzić sa te same naprzyklad
    virtual void insert(int key, int value)= 0;
    virtual void remove(int key)=0;
   // virtual bool exists(int key)=0;

    //virtual int returnKey() const =0;
    //virtual int returnValue() const =0;
    //virtual int returnSize() const = 0;

    virtual void display()const = 0;
};


#endif //SD_3_MAP_H
