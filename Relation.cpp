#include<iostream>
#include "Relation.h"

void CreateRelation(LR &L){
    first(L) = NULL;
}
addressR AllocateRelation(addressM C, addressB B){
    addressR P;
    P = new Elm_Relation;
    child(P) = C;
    parent(P) = B;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}
void InsertLastRelation(LR &L, addressR P){
    addressR Q;
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
void DeleteRelation(LR &L, addressR P){
   addressR Q;
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
addressR FindElmRelation(LR &L, Maskapai x1, Data_Bandara x2){
    addressR Q;
    addressR P;
    Q = first(L);
    while (Q != NULL){
        if (info(parent(Q)).Nama_Bandara == x2.Nama_Bandara && info(child(Q)).Nama_Maskapai == x1.Nama_Maskapai){
            P = Q;
            Q = next(Q);
        }else{
            Q = next(Q);
        }
    }
    return P;
}
void printInfoRelation(LR L){
    addressR Q;
    Q = first(L);
    while (Q != NULL){
        cout << "Parent      : " << info(parent(Q)).Nama_Bandara<<endl;
        cout << "Child       : " <<info(child(Q)). Nama_Maskapai<<endl;
        Q = next(Q);
    }

}

int HitungChildPadaParentTertentu(LR relation, string x){
    int i;
    addressR P;
    P = first(relation);
    while (P != NULL){
        if (info(parent(P)).Nama_Bandara == x){
            i++;
        }
        P = next(P);
    }
    return i;
}
