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
    cout << "Tambah Kontak" << endl;
}

void menu2(){
    cout << "Tampilkan Kontak" << endl;
}

void menu3(){
    cout << "Hapus Kontak" << endl;
}

void menu4(){
    cout << "Edit Kontak" << endl;
}

void menu5(){
    cout << "Cari Kontak" << endl;
}

void menu6(){
    cout << "Sorting Kontak" << endl;
}


int main() {
    head = NULL;
    tail = NULL;

    int pilihan;
    char lanjut;

do {
    tampilMenu();
    cout << "Pilihan: ";
    cin >> pilihan;
    system("cls");

    if (cin.fail() || pilihan < 1 || pilihan > 7 ) {
        cin.clear();
        cin.ignore();
        cout << "\nMasukkan angka antara 1-7!!\n" << endl;
        continue;
    }    

    switch (pilihan) {
        case 1:
            menu1();
            break;
        case 2:
            menu2();
            break;
        case 3:
            menu3();
            break;
        case 4:
            menu4();
            break;
        case 5:
            menu5();
            break;
        case 6:
            menu6();
            break;
        case 7:
            cout << "Keluar dari program." << endl;
            return 0;
            break;
        default:
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
    }

    if (pilihan == 1 || pilihan == 2 || pilihan == 3 || pilihan == 4 || pilihan == 5 || pilihan == 6) {
        cout << endl;
        cout << "Apakah Anda ingin melanjutkan program? (y/t): ";
        cin >> lanjut;
        system("cls");

        do {
            if (lanjut == 'y' || lanjut == 'Y') {
                system("cls");
                break;
            } else if (lanjut == 't' || lanjut == 'T') {
                cout << "Terima kasih telah menggunakan program ini!" << endl;
                return 0;
            } else {
                cout << "Pilihan tidak tersedia. Silakan masukkan (y/t): ";
                cin >> lanjut;
            }
        } while (true);
    }



} while (pilihan != 7);

    return 0;
}