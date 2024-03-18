#ifndef PARENTS_H_INCLUDED
#define PARENTS_H_INCLUDED

#include <iostream>

#define info(p) (p)->info
#define next(p) (p)->next
#define first(L) ((L).first)

using namespace std;
typedef struct ElmList_Bandara *addressB;

struct Data_Bandara{
    string Nama_Bandara, Daerah_bandara;
    int max_maskapai;
};

struct ElmList_Bandara{
    Data_Bandara info;
    addressB next;
};
struct L1{
    addressB first;
};
void CreateParent(L1 &L);
addressB AllocateParent(Data_Bandara X);
void InsertFirstParent(L1 &L, addressB P);
void InsertLastParent(L1 &L, addressB P);
void DeleteParent(L1 &L, addressB P);
addressB FindElmParent(L1 &L, string x);
void PrintInfoParent(L1 L);

#endif // PARENTS_H_INCLUDED
