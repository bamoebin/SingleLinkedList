#ifndef SLLadt_H
#define SLLadt_H

#include <stdio.h>
#include <stdlib.h>

// Struktur Node
struct Node {
    int data;
    struct Node* next;
};

// Inisialisasi Linked List
extern struct Node* head;
extern struct Node* tail;

// cari posisi
int CariPosisi(int nilaiCari);
//alokasi untuk menyediakan ruangan untuk suatu node
struct Node *Alokasi(int nilai); 
// Operasi PengisianNilai
void SetterNilai(int posisi, int nilai);
// Operasi InsertAwal
void InsertAwal(int nilai);
// Operasi InsertAkhir
void InsertAkhir(int nilai);
// Operasi InsertTengah
void InsertTengah(int posisi, int nilai);
// Operasi DeleteTengah
void DeleteTengah(int posisi);
// Operasi DeleteAwal
void DeleteAwal();
// Operasi DeleteAkhir
void DeleteAkhir();
// Fungsi untuk menampilkan isi Linked List
void PrintList();
// Update / repalce nilai yang sudah ada dalam suatu list
void updateReplaceList(int nilai, int nilaiInput);

#endif