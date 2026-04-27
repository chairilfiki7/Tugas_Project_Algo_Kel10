#include <iostream>
using namespace std;

struct Kontak{
    char nama[50];
    char noTelp[20];
    
    Kontak *next;
    Kontak *prev;
};

Kontak *head;
Kontak *tail;

void tampilMenu(){
    cout << "Menu Kontak" << endl;
    cout << "1. Tambah Kontak" << endl;
    cout << "2. Tampilkan Kontak" << endl;
    cout << "3. Hapus Kontak" << endl;
    cout << "4. Edit Kontak" << endl;
    cout << "5. Cari Kontak" << endl;
    cout << "6. Sorting Kontak" << endl;
    cout << "7. Keluar" << endl;
}

void menu1(){
    
}


int main() {
    head = NULL;
    tail = NULL;

    int pilihan;

do {
    tampilMenu();
    cout << "Pilihan: ";
    cin >> pilihan;
    switch (pilihan) {
        case 1:
            cout << "Tambah Kontak" << endl;
            break;
        case 2:
            cout << "Tampilkan Kontak" << endl;
            break;
        case 3:
            cout << "Hapus Kontak" << endl;
            break;
        case 4:
            cout << "Edit Kontak" << endl;
            break;
        case 5:
            cout << "Cari Kontak" << endl;
            break;
        case 6:
            cout << "Sorting Kontak" << endl;
            break;
        case 7:
            cout << "Keluar dari program." << endl;
            return 0;
            break;
        default:
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
    }
} while (pilihan != 7);

    return 0;
}