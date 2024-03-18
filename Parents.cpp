#include <iostream>
#include "Parents.h"

using namespace std;

void CreateParent(L1 &L){
    first(L) = NULL;
}
addressB AllocateParent(Data_Bandara X){
    addressB P;
    P = new ElmList_Bandara;
    info(P) = X;
    next(P) = NULL;
    return P;
}
void InsertFirstParent(L1 &L, addressB P){
    if (first(L) == NULL){
        first(L) = P;
    }else{
        next(P) = first(L);
        first(L) = P;
    }
}
void InsertLastParent(L1 &L, addressB P){
    addressB Q;
    Q = first(L);
    if (first(L) == NULL){
        first(L) = P;
    }else{
        while (next(Q)!= NULL){
            Q = next(Q);
        }
        next(Q) = P;
    }
}
void DeleteParent(L1 &L, addressB P){
   addressB Q;
   Q = first(L);
   if (first(L) != NULL){
        if (next(first(L)) == NULL && first(L) == P){
            first(L) = NULL;
        }else if (next(first(L)) != NULL && first(L) == P){
            first(L) = next(P);
            next(P) = NULL;
        }else{
            while(next(Q)!= P){
                Q = next(Q);
            }
            next(Q) = next(P);
            next(P) = NULL;
        }
    delete P;
   }
}
addressB FindElmParent(L1 &L, string x){
    addressB Q;
    addressB P = NULL;
    Q = first(L);
    while (Q != NULL){
        if (info(Q).Nama_Bandara == x){
            P = Q;
            Q = next(Q);
        }else{
            Q = next(Q);
        }
    }
    return P;

}
void PrintInfoParent(L1 L){
    int i = 0;
    addressB Q;
    Q = first(L);
    while (Q != NULL){
        i++;
        cout << i << ". " <<info(Q).Nama_Bandara<<endl;
        Q = next(Q);
    }
}

