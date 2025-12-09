#ifndef RELASILIST_H
#define RELASILIST_H

#include <iostream>
#include "penulisList.h"
#include "jurnalList.h"

using namespace std;

typedef struct elmlist_relasi *address_relasi;

struct elmlist_relasi{
    address_relasi next;
    addressJurnal child;
    addressPenulis parent;
}; 

struct List_relasi{
    address_relasi first;
};

void createListRelasi(List_relasi &L);
void insertRelasi(List_relasi &L, address_relasi R);
address_relasi alokasiRelasi(elmPenulis* P, addressJurnal J);
address_relasi findRelasi(List_relasi L, elmPenulis P, addressJurnal J);
void deleteRelasi(List_relasi &L, address_relasi R);
void showChildOfParent(List_relasi LR, addressPenulis P);
void showParentOfChild(List_relasi LR, addressJurnal C);
void showAllParentWithChild(ListPenulis LP, List_relasi LR);
void showAllChildWithParent(ListJurnal LJ, List_relasi LR);
int countChildOfParent(List_relasi LR, addressPenulis P);

#endif