#include <iostream>
#include "penulisList.h"
#include "jurnalList.h"
#include "relasiList.h"

using namespace std;

int main() {
    ListPenulis LP;
    ListJurnal LJ;
    List_relasi LR;

    createListPenulis(LP);
    createListJurnal(LJ);
    createListRelasi(LR);

    int menu = -1;
    while (menu != 0){
        cout << "\n=== MENU UTAMA ===\n";
        cout << "1. Insert element parent (Penulis)\n";
        cout << "2. Insert element child (Jurnal)\n";
        cout << "3. Insert element relation\n";
        cout << "4. Delete element parent\n";
        cout << "5. Delete element child\n";
        cout << "6. Delete element relation\n";
        cout << "7. Find element parent\n";
        cout << "8. Find element child\n";
        cout << "9. Cek apakah parent dan child memiliki relasi\n";
        cout << "10. Show all parent\n";
        cout << "11. Show all child\n";
        cout << "12. Show data child dari parent tertentu\n";
        cout << "13. Show data parent dari child tertentu\n";
        cout << "14. Show setiap parent beserta childnya\n";
        cout << "15. Show setiap child beserta parentnya\n";
        cout << "16. Hitung jumlah child dari parent tertentu\n";
        cout << "0. Exit\n";
        cout << "Pilih menu: ";
        cin >> menu;

        cout << endl;

        if (menu == 1) {
            int id;
            string nama, status;
            cout << "ID Penulis: ";
            cin >> id;
            cout << "Nama Penulis: ";
            cin >> nama;
            cout << "Status: ";
            cin >> status;
            insertPenulis(LP, alokasiPenulis(id, nama, status));
            cout << "Penulis ditambahkan.\n";
        }

        else if (menu == 2) {
            infotypeJurnal J;
            cout << "ID Jurnal: ";
            cin >> J.idJurnal;
            cout << "Judul Jurnal: ";
            cin >> J.judulJurnal;
            cout << "Akreditasi Jurnal (1 = ya, 0 = tidak): ";
            cin >> J.akreditasiJurnal;
            insertJurnal(LJ, createElment(J));
            cout << "Jurnal ditambahkan.\n";
        }

        else if (menu == 3) {
            int idP;
            string idJ;
            cout << "ID Penulis: ";
            cin >> idP;
            cout << "ID Jurnal: ";
            cin >> idJ;

            addressPenulis P = findPenulis(LP, idP);
            addressJurnal J = findJurnal(LJ, idJ);

            if (P != NULL && J != NULL) {
                insertRelasi(LR, alokasiRelasi(P, J));
                cout << "Relasi berhasil dibuat.\n";
            } else {
                cout << "Penulis atau jurnal tidak ditemukan.\n";
            }
        }

        else if (menu == 4) {
            int id;
            cout << "ID Penulis yang ingin dihapus: ";
            cin >> id;
            deletePenulis(LP, id);
        }

        else if (menu == 5) {
            string id;
            cout << "ID Jurnal yang ingin dihapus: ";
            cin >> id;
            deleteJurnal(LJ, id);
        }

        else if (menu == 6) {
            int idP;
            string idJ;
            cout << "ID Penulis: ";
            cin >> idP;
            cout << "ID Jurnal: ";
            cin >> idJ;

            addressPenulis P = findPenulis(LP, idP);
            addressJurnal J = findJurnal(LJ, idJ);

            if (P != NULL && J != NULL) {
                address_relasi R = findRelasi(LR, *P, J);
                if (R != NULL) {
                    deleteRelasi(LR, R);
                    cout << "Relasi dihapus.\n";
                } else {
                    cout << "Relasi tidak ditemukan.\n";
                }
            }
        }

        else if (menu == 7) {
            int id;
            cout << "ID Penulis dicari: ";
            cin >> id;
            addressPenulis P = findPenulis(LP, id);
            if (P != NULL)
                cout << "Ditemukan: " << P->info.namaPenulis << endl;
            else
                cout << "Penulis tidak ditemukan.\n";
        }

        else if (menu == 8) {
            string id;
            cout << "ID Jurnal dicari: ";
            cin >> id;
            addressJurnal J = findJurnal(LJ, id);
            if (J != NULL)
                cout << "Ditemukan: " << J->info.judulJurnal << endl;
            else
                cout << "Jurnal tidak ditemukan.\n";
        }

        else if (menu == 9) {
            int idP;
            string idJ;
            cout << "ID Penulis: ";
            cin >> idP;
            cout << "ID Jurnal: ";
            cin >> idJ;

            addressPenulis P = findPenulis(LP, idP);
            addressJurnal J = findJurnal(LJ, idJ);

            if (P != NULL && J != NULL) {
                if (findRelasi(LR, *P, J) != NULL)
                    cout << "ADA relasi.\n";
                else
                    cout << "TIDAK ADA relasi.\n";
            }
        }

        else if (menu == 10) {
            printListPenulis(LP);
        }

        else if (menu == 11) {
            printListJurnal(LJ);
        }

        else if (menu == 12) {
            int id;
            cout << "ID Penulis: ";
            cin >> id;
            addressPenulis P = findPenulis(LP, id);
            showChildOfParent(LR, P);
        }

        else if (menu == 13) {
            string id;
            cout << "ID Jurnal: ";
            cin >> id;
            addressJurnal J = findJurnal(LJ, id);
            showParentOfChild(LR, J);
        }

        else if (menu == 14) {
            showAllParentWithChild(LP, LR);
        }

        else if (menu == 15) {
            showAllChildWithParent(LJ, LR);
        }

        else if (menu == 16) {
            int id;
            cout << "ID Penulis: ";
            cin >> id;
            addressPenulis P = findPenulis(LP, id);
            cout << "Jumlah jurnal: " << countChildOfParent(LR, P) << endl;
        } else{
            cout << "ERROR 404 ### Input Salah ### ERROR 404" << endl << endl;
        }

    }

    cout << "Program selesai.\n";
    return 0;
}
