# Tugas_Project_Algo_Kel10
Aplikasi Manajemen Kontak (C++)

Kelompok:
1. Chairil Fikri Maulidi (124250055)
2. Azriel Yalsha Hanifah (124250058)

## Deskripsi
Program CLI untuk menyimpan dan mengelola daftar kontak (nama dan no telepon).
Data disimpan di file `kontak.dat` agar bisa dibaca kembali saat program dijalankan.

## Fitur
- Tambah kontak
- Tampilkan kontak
- Hapus kontak
- Edit kontak
- Cari kontak berdasarkan nama
- Sorting kontak berdasarkan nama (A-Z)
- Simpan dan muat data dari file

## Struktur Data
- Doubly linked list (node memiliki pointer `kiri` dan `kanan`).

## Algoritma Searching
- Jenis: Linear search pada linked list.
- Alasan pemilihan:
	- Data disimpan sebagai linked list tanpa indeks acak.
	- Implementasi sederhana dan sesuai untuk jumlah data kecil-menengah.
	- Tidak membutuhkan struktur tambahan.

## Algoritma Sorting
- Jenis: Bubble sort (menukar isi data antar node).
- Alasan pemilihan:
	- Mudah diimplementasikan pada linked list dengan menukar data.
	- Cocok untuk kebutuhan pembelajaran dan ukuran data tidak terlalu besar.
	- Stabil untuk pengurutan nama.

## Kompleksitas
- Searching: O(n)
- Sorting: O(n^2)

## Cara Menjalankan
1. Pastikan compiler C++ terpasang (contoh: MinGW g++).
2. Compile:
```bash
g++ ProjectKel10.cpp -o ProjectKel10
```
3. Jalankan:
```bash
ProjectKel10
```

## Catatan
- File `kontak.dat` akan dibuat di folder yang sama untuk menyimpan data.
- Program menggunakan `system("cls")`, sehingga tampilan menu optimal di Windows.
