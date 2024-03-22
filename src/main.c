#include "SLLadt.h"

int main() {

    InsertAkhir(10);
    InsertAkhir(20);
    printf("insert akhir 30\n");
    InsertAkhir(30);
    PrintList(); 

    printf("cari indeks 10\n");
    int i = CariPosisi(10);
    printf("Posisi indexs dari nilai yang dicari : %d\n",i); //Cari posisi index nilai*/

    printf("insert awal 5\n");
    InsertAwal(5);
    PrintList(); 

    //(posisi, nilai)
    printf("insert tengah 15\n");
    InsertTengah(3, 15);
    PrintList(); 

    printf("delete tengah list ke-3\n");
    DeleteTengah(3);
    PrintList(); 

    printf("delete awal\n");
    DeleteAwal();
    PrintList(); 

    printf("delete akhir\n");
    DeleteAkhir();
    PrintList(); 
    printf("Data di node terakhir : %d\n", tail->data);

    printf("Setter Nilai atau Update\nupdate 20 menjadi 55\n");
    updateReplaceList(20,55);
    //PengubahanNilai(1,25);
    PrintList();
    printf("Data di node terakhir : %d\n", tail->data);

    return 0;
}
