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
    cout << "=== Menu Kontak ===" << endl;
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
    tunjuk = fopen("kontak.dat", "wb");

    if (tunjuk == NULL) {
        cout << "Gagal membuka file kontak.dat!" << endl;
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
        ekor = nodeBaru;
    }    
    

}

void bacaFile (){
    FILE *tunjuk;
    tunjuk = fopen("kontak.dat", "rb");

    if (tunjuk == NULL) {
        return;
    }

    Node dataTemp;

    while (fread(&dataTemp, sizeof(Node), 1, tunjuk) == 1) {
        tambahBelakang(dataTemp.nama, dataTemp.noTelp);
    }

    fclose(tunjuk);
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
    cout << "=== Tampilkan Kontak ===" << endl;

    if (kepala == NULL) {
        cout << "Belum ada kontak yang tersimpan." << endl;
        return;
        
    }

    Node* bantu = kepala;
    int nomer = 1;

    cout << "------------------------------" << endl;
    while (bantu != NULL) {
        cout << nomer << ". Nama : " << bantu-> nama << endl;
        cout << "   No Telepon : " << bantu-> noTelp << endl;
        cout << "------------------------------" << endl;

        bantu = bantu->kanan;
        nomer++;
    }
}

void hapusNode(char namaHapus[]) {

    if (kepala == NULL) {
        cout << "Belum ada kontak yang tersimpan." << endl;
        return;
    }

    Node* hapus = kepala;
    bool ketemu = false;

    while (hapus != NULL) {
        if (strcmp(hapus->nama, namaHapus) == 0) {
            ketemu = true;
            break;
        }
        hapus = hapus->kanan;
    }

    if (!ketemu) {
        cout << "Kontak dengan nama " << namaHapus << " tidak ditemukan." << endl;
        return;
    }

    if (kepala == ekor) {
        kepala = NULL;
        ekor = NULL;
    } else if (hapus == kepala) {
        kepala = kepala->kanan;
        kepala->kiri = NULL;
    } else if (hapus == ekor) {
        ekor = ekor->kiri;
        ekor->kanan = NULL;
    } else {
        hapus->kiri->kanan = hapus->kanan;
        hapus->kanan->kiri = hapus->kiri;
    }

    delete hapus;

    simpanFile();

    cout << "Kontak dengan nama " << namaHapus << " berhasil dihapus." << endl;

}

void menu3(){
    cout << "=== Hapus Kontak ===" << endl;

    if (kepala == NULL) {
        cout << "Belum ada kontak yang tersimpan." << endl;
        return;
    }

    char hapusNama[50];
    cin.ignore();
    cout << "Masukkan Nama Kontak yang ingin dihapus: ";
    cin.getline(hapusNama, 50);

    hapusNode(hapusNama);


}

void editNode(char namaEdit[]) {

    Node* bantu = kepala;
    bool ketemu = false;

    while (bantu != NULL) {
        if (strcmp(bantu->nama, namaEdit) == 0) {
            ketemu = true;
            break;
        }
        bantu = bantu->kanan;
    }

    if (!ketemu) {
        cout << "Kontak dengan nama " << namaEdit << " tidak ditemukan." << endl;
        return;
    }

    char inputNama[50];
    char inputTlp[20];

    cout << "\nData ditemukan!" << endl;
    cout << "Nama Lama: " << bantu->nama << endl;
    cout << "No Telepon Lama: " << bantu->noTelp << endl;
    cout << "------------------------------" << endl;

    cout << "Masukkan Nama Baru: ";
    cin.getline(inputNama, 50);
    cout << "Masukkan No Telepon Baru: ";
    cin.getline(inputTlp, 20);

    strcpy(bantu->nama, inputNama);
    strcpy(bantu->noTelp, inputTlp);

    simpanFile();
    cout << "Kontak berhasil diedit." << endl;
}

void menu4(){
    cout << "=== Edit Kontak ===" << endl;

    if (kepala == NULL) {
        cout << "Belum ada kontak yang tersimpan." << endl;
        return;
    }

    char editNama[50];
    cin.ignore();
    cout << "Masukkan Nama Kontak yang ingin diedit: ";
    cin.getline(editNama, 50);

    editNode(editNama);

}

void cariNode(char namaCari[]) {
    Node* bantu = kepala;
    bool ketemu = false;

    while (bantu != NULL) {
        if (strcmp(bantu->nama, namaCari) == 0) {
            ketemu = true;
            break;
        }
        bantu = bantu->kanan;
    }

    if (!ketemu) {
        cout << "Kontak dengan nama " << namaCari << " tidak ditemukan." << endl;
        return;
    }

    cout << "\n=== Data ditemukan ===" << endl;
    cout << "Nama: " << bantu->nama << endl;
    cout << "No Telepon: " << bantu->noTelp << endl;
    cout << "------------------------------" << endl; 
}

void menu5(){
    cout << "=== Cari Kontak ===" << endl;

    if (kepala == NULL) {
        cout << "Belum ada kontak yang tersimpan." << endl;
        return;
    }

    char cariNama[50];
    cin.ignore();
    cout << "Masukkan Nama Kontak yang ingin dicari: ";
    cin.getline(cariNama, 50);

    cariNode(cariNama);


}

void urutkanNode(){
    if (kepala == NULL || kepala->kanan == NULL) {
        cout << "Data tidak cukup untuk diurutkan." << endl;
        return;
    }

    bool adaPertukaran;
    Node* bantu;

    do {
        adaPertukaran = false;
        bantu = kepala;

        while (bantu->kanan != NULL) {
            if (strcmp(bantu->nama, bantu->kanan->nama) > 0) {
                char tempNama[50];
                strcpy(tempNama, bantu->nama);
                strcpy(bantu->nama, bantu->kanan->nama);
                strcpy(bantu->kanan->nama, tempNama);

                char tempTlp[20];
                strcpy(tempTlp, bantu->noTelp);
                strcpy(bantu->noTelp, bantu->kanan->noTelp);
                strcpy(bantu->kanan->noTelp, tempTlp);

                adaPertukaran = true;
            }
            bantu = bantu->kanan;
        }
    } while (adaPertukaran);

    simpanFile();

    cout << "\n------------------------------" << endl;
    cout << "Kontak berhasil diurutkan." << endl;
    cout << "------------------------------\n" << endl;
}

void menu6(){
    cout << "=== Sorting Kontak ===" << endl;
    cout << "Data sebelum diurutkan:" << endl;
    menu2();
    
    if (kepala == NULL) {
        cout << "Belum ada kontak yang tersimpan." << endl;
        return;
    }

    urutkanNode();

    cout << "Data setelah diurutkan:" << endl;
    menu2();
}


int main() {
    kepala = NULL;
    ekor = NULL;

    bacaFile();

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
            cout << "Terima kasih telah menggunakan program ini!" << endl;
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