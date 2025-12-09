#include <iostream>
#include "penulisList.h"
using namespace std;
void createListPenulis(ListPenulis &L){
    L.first = NULL;
}

elmPenulis* alokasiPenulis(int id, string nama, string status){
    elmPenulis* P = new elmPenulis;
    P->info.idPenulis = id;
    P->info.namaPenulis = nama;
    P->info.status = status;
    P->next = NULL;
    return P;
}

elmPenulis* findPenulis(ListPenulis L, int id){
    elmPenulis* P = L.first;
    while (P != NULL){
        if (P->info.idPenulis == id){
            return P;
        }
        P = P->next;
    }
    return NULL;
}
void insertPenulis(ListPenulis &L, elmPenulis* P){
    if (L.first == NULL){
        L.first = P;
    } else {
        elmPenulis* Q = L.first;
        while (Q->next != NULL){
            Q = Q->next;
        }
        Q->next= P;
    }
}
void deletePenulis(ListPenulis &L, int id) {
    elmPenulis* P = findPenulis(L, id);
    
    if (P != NULL) {
        if (P == L.first) {
            L.first = P->next; 
        } else {
            elmPenulis* Q = L.first;
            while (Q->next != P) {
                Q = Q->next;
            }
            Q->next = P->next;
        }
        
        delete P; 
    }
}



void printListPenulis(ListPenulis L) {
    if (L.first == NULL) {
        cout << "List Penulis Kosong." << endl;
    } else {
        elmPenulis* P = L.first;
        
        
        while (P != NULL) {
            cout << "ID: " << P->info.idPenulis 
                 << " | Nama: " << P->info.namaPenulis 
                 << " | Status: " << P->info.status << endl;
                 
            P = P->next; // Geser terus
        }
    }
}

