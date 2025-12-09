#ifndef PENULISLIST_H
#define PENULISLIST_H
#include <iostream>
#include <string>
using namespace std;

struct infotypePenulis {
    int idPenulis;
    string namaPenulis;
    string status;
};

struct elmPenulis {
    infotypePenulis info;
    elmPenulis* next;
};

typedef elmPenulis* addressPenulis;

struct ListPenulis {
    elmPenulis* first; 
};


void createListPenulis(ListPenulis &L);
elmPenulis* alokasiPenulis(int id, string nama, string status);
void insertPenulis(ListPenulis &L, elmPenulis* P);
elmPenulis* findPenulis(ListPenulis L, int id);
void deletePenulis(ListPenulis &L, int id);
void printListPenulis(ListPenulis L);

#endif