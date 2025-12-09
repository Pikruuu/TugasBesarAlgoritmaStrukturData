#include <iostream>
#include "relasiList.h"

using namespace std;   

void createListRelasi(List_relasi &L) {
    L.first = NULL;
}

address_relasi alokasiRelasi(elmPenulis* P, addressJurnal J) {
    address_relasi Q = new elmlist_relasi;
    Q->child = J;
    Q->parent = P;
    Q->next = NULL;
    return Q;
}

address_relasi findRelasi(List_relasi L, elmPenulis P, addressJurnal J) {
    address_relasi Q = L.first;
    while (Q != NULL) {
        if (Q->parent->info.idPenulis == P.info.idPenulis && Q->child->info.idJurnal == J->info.idJurnal) {
            return Q;
        }
        Q = Q->next;
    }
    return NULL;
}

void insertRelasi(List_relasi &L, address_relasi R) {
    if (L.first == NULL) {
        L.first = R;
    } else {
        address_relasi Q = L.first;
        while (Q->next != NULL) {
            Q = Q->next;
        }
        Q->next = R;
    }
    R->next = NULL;
}

void deleteRelasi(List_relasi &L, address_relasi R) {
    if (L.first != NULL) {
        if (L.first == R) {
            L.first = R->next;
            delete R;
        } else {
            address_relasi Q = L.first;
            while (Q->next != NULL && Q->next != R) {
                Q = Q->next;
            }
            if (Q->next == R) {
                Q->next = R->next;
                delete R;
            }
        }
    }
}

void showChildOfParent(List_relasi LR, addressPenulis P) {
    if (P == NULL) {
        cout << "Parent tidak ditemukan." << endl;
        return;
    }

    cout << "Jurnal milik Penulis: " << P->info.namaPenulis << endl;

    address_relasi R = LR.first;
    bool found = false;

    while (R != NULL) {
        if (R->parent == P) {
            cout << "- " << R->child->info.judulJurnal << endl;
            found = true;
        }
        R = R->next;
    }

    if (!found) {
        cout << "(Tidak ada jurnal yang berelasi dengan penulis ini)" << endl;
    }
}

void showParentOfChild(List_relasi LR, addressJurnal C) {
    if (C == NULL) {
        cout << "Child tidak ditemukan." << endl;
        return;
    }

    cout << "Penulis dari Jurnal: " << C->info.judulJurnal << endl;

    address_relasi R = LR.first;
    bool found = false;

    while (R != NULL) {
        if (R->child == C) {
            cout << "- " << R->parent->info.namaPenulis << endl;
            found = true;
        }
        R = R->next;
    }

    if (!found) {
        cout << "(Tidak ada penulis yang berelasi dengan jurnal ini)" << endl;
    }
}

void showAllParentWithChild(ListPenulis LP, List_relasi LR) {
    addressPenulis P = LP.first;

    if (P == NULL) {
        cout << "List penulis kosong." << endl;
        return;
    }

    while (P != NULL) {
        cout << "\nPenulis: " << P->info.namaPenulis << endl;

        address_relasi R = LR.first;
        bool found = false;

        while (R != NULL) {
            if (R->parent == P) {
                cout << "   - " << R->child->info.judulJurnal << endl;
                found = true;
            }
            R = R->next;
        }

        if (!found) {
            cout << "   (Tidak ada jurnal terkait)" << endl;
        }

        P = P->next;
    }
}

void showAllChildWithParent(ListJurnal LJ, List_relasi LR) {
    addressJurnal C = LJ.first;

    if (C == NULL) {
        cout << "List jurnal kosong." << endl;
        return;
    }

    while (C != NULL) {
        cout << "\nJurnal: " << C->info.judulJurnal << endl;

        address_relasi R = LR.first;
        bool found = false;

        while (R != NULL) {
            if (R->child == C) {
                cout << "   - " << R->parent->info.namaPenulis << endl;
                found = true;
            }
            R = R->next;
        }

        if (!found) {
            cout << "   (Tidak ada penulis terkait)" << endl;
        }

        C = C->next;
    }
}

int countChildOfParent(List_relasi LR, addressPenulis P) {
    int count = 0;
    address_relasi R = LR.first;

    while (R != NULL) {
        if (R->parent == P) {
            count++;
        }
        R = R->next;
    }

    return count;
}
