#include <iostream>
#include <cstring>
using namespace std;

struct Node{
    char nama[50];
    char noTelp[20];
    
    Node *kanan;
    Node *kiri;
};

Node *kepala;
Node *ekor;

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

void simpanFile() {
    FILE *tunjuk;
    tunjuk = fopen("kontak.txt", "wb");

    if (tunjuk == NULL) {
        cout << "Gagal membuka file kontak.txt!" << endl;
        return;
    }

    Node* bantu = kepala;

    while (bantu != NULL) {
        fwrite(bantu, sizeof(Node), 1, tunjuk);

        bantu = bantu->kanan;
    }

    fclose(tunjuk);
}

Node* buatNode(char namaBaru[], char noTelpBaru[]) {
    Node* nodeBaru = new Node;
    strcpy(nodeBaru->nama, namaBaru);
    strcpy(nodeBaru->noTelp, noTelpBaru);
    
    nodeBaru->kanan = NULL;
    nodeBaru->kiri = NULL;

    return nodeBaru;
}

void tambahBelakang(char namaBaru[], char noTelpBaru[]) {
    Node* nodeBaru = buatNode(namaBaru, noTelpBaru);

    if (kepala == NULL) {
        kepala = nodeBaru;
        ekor = nodeBaru;
    } else {
        ekor->kanan = nodeBaru;
        nodeBaru->kiri = ekor;
    }    ekor = nodeBaru;
    

}

void menu1(){
    cout << "=== Tambah Kontak Baru ===" << endl;

    char inputNama[50];
    char inputNo[20];

    cin.ignore();
    cout << "Masukkan Nama: ";
    cin.getline(inputNama, 50);
    cout << "Masukkan No Telepon: ";
    cin.getline(inputNo, 20);
    tambahBelakang(inputNama, inputNo);

    simpanFile();

    cout << "Kontak atas nama " << inputNama << " berhasil ditambahkan!" << endl;

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
    kepala = NULL;
    ekor = NULL;

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