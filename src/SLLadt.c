#include "SLLadt.h"

struct Node* head = NULL;
struct Node* tail = NULL;

//CariPosisi
int CariPosisi(int nilaiCari) {
    struct Node *current = head;
    int posisi = 0;
    while (current != NULL && current->data != nilaiCari) {
        current = current->next;
        posisi++;
    }
    if (current == NULL)
        return -1; // Data tidak ditemukan
    else
        return posisi; // Data ditemukan pada posisi tertentu
}

// Operasi Alokasi
struct Node *Alokasi(int nilai) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Alokasi memori gagal.\n");
        exit(1);
    }
    newNode->data = nilai;
    newNode->next = NULL;
    return newNode;
}

// Operasi PengisianNilai
void SetterNilai(int posisi, int nilai) {
    struct Node *current = head;
    for (int i = 1; i < posisi; i++) {
        if (current == NULL) {
            printf("Posisi tidak valid.\n");
            return;
        }
        current = current->next;
    }
    current->data = nilai;
}

// Operasi InsertAwal
void InsertAwal(int nilai) {
    struct Node *newNode = Alokasi(nilai);
    newNode->next = head;
    head = newNode;
}

// Operasi InsertAkhir
void InsertAkhir(int nilai) {
    struct Node *newNode = Alokasi(nilai);
    if (head == NULL) {
        head = newNode;
        return;
    }
    struct Node *current = head;
    while (current->next != NULL)
        current = current->next;
    current->next = newNode;
    tail = current;
}

// Operasi InsertTengah
void InsertTengah(int posisi, int nilai) {
    if (posisi == 1) {
        InsertAwal(nilai);
        return;
    }
    struct Node* current = head;
    for (int i = 1; i < posisi - 1; i++) {
        if (current == NULL) {
            printf("Posisi tidak valid.\n");
            return;
        }
        current = current->next;
    }
    struct Node *newNode = Alokasi(nilai);
    newNode->next = current->next;
    current->next = newNode;
}

// Operasi DeleteTengah
void DeleteTengah(int posisi) {
    if (posisi == 1) {
        DeleteAwal();
        return;
    }
    struct Node *current = head;
    for (int i = 1; i < posisi - 1; i++) {
        if (current == NULL || current->next == NULL) {
            printf("Posisi tidak valid.\n");
            return;
        }
        current = current->next;
    }
    struct Node *temp = current->next;
    current->next = temp->next;
    free(temp);
}

// Operasi DeleteAwal
void DeleteAwal() {
    if (head != NULL) {
        struct Node *temp = head;
        head = head->next;
        free(temp);
    }
}

// Operasi DeleteAkhir
void DeleteAkhir() {
    if (head != NULL) {
        if (head->next == NULL) {
            free(head);
            head = NULL;
        } else {
            struct Node *current = head;
            while (current->next->next != NULL)
                current = current->next;
            free(current->next);
            current->next = NULL;
            tail = current;
        }
    }
}


// Fungsi untuk menampilkan isi Linked List
void PrintList() {
    struct Node *current = head;
    printf("Linked List: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
// Update / repalce nilai yang sudah ada dalam suatu list
void updateReplaceList(int nilai, int nilaiInput){
    if (CariPosisi(nilai) != -1)
    {
        SetterNilai(CariPosisi(nilai)+1,nilaiInput);
    }
}