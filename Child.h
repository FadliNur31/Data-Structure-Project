#ifndef CHILD_H_INCLUDED
#define CHILD_H_INCLUDED


#include <iostream>

#define first(L) ((L).first)
#define first(L) ((L).first)
#define info(p) (p)->info
#define next(p) (p)->next
#define GrandChild(p) (p)->GrandChild

using namespace std;
typedef struct ElmList_Maskapai *addressM;
typedef struct ElmList_Penumpang *addressP;

struct Data_Penumpang{
    string Nama_Penumpang, Tujuan, Kode_Pesawat;
};

struct Maskapai{
    string Nama_Maskapai, Kode_Pesawat, Tujuan;
    int Max_Penumpang ;
};

struct ElmList_Penumpang{
    Data_Penumpang info;
    int i;
    addressP next;
};

struct ElmList_Maskapai{
    Maskapai info;
    addressM next;
    addressP GrandChild;
};

struct L2{
    addressM first;
};

void CreateChild(L2 &L);
addressM AllocateChild(Maskapai x);
void InserLastChild(L2 &L, addressM P);
void DeleteChild(L2 &L, addressM P);
addressM FindElmChild(L2 &L, string x);
void PrintInfoChild(L2 L);
addressP AllocateGrandchild(Data_Penumpang x);
void InserLastGrandchild(addressM &P, addressP Q);
void DeleteGrandchild(addressM &P, addressP Q);
addressP FindElmGrandchild(addressM P, string x);
void PrintInfoGrandChild(addressM P);
int HitungGrandchildPadaChildTertentu(addressM child);

#endif // CHILD_H_INCLUDED
