#include <iostream>
#include "Child.h"

using namespace std;

void CreateChild(L2 &L){
    first(L) = NULL;
}
addressM AllocateChild(Maskapai x){
    addressM P;
    P = new ElmList_Maskapai;
    info(P) = x;
    next(P) = NULL;
    GrandChild(P) = NULL;
    return P;
}
void InserLastChild(L2 &L, addressM P){
    addressM Q;
    Q = first(L);
    if (first(L) == NULL){
        first(L) = P;
    }else{
        while (next(Q) != NULL){
            Q = next(Q);
        }
        next(Q) = P;
    }
}

void DeleteChild(L2 &L, addressM P){
   addressM Q;
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

addressM FindElmChild(L2 &L, string x){
    addressM Q;
    addressM P = NULL;
    Q = first(L);
    while (Q != NULL){
        if (info(Q).Nama_Maskapai == x){
            P = Q;
            Q = next(Q);
        }else{
            Q = next(Q);
        }
    }
    return P;
}
void PrintInfoChild(L2 L){
    addressM Q;
    Q = first(L);
    while (Q != NULL){
        cout << info(Q).Nama_Maskapai<<endl;
        Q = next(Q);
    }
}
addressP AllocateGrandchild(Data_Penumpang x){
    addressP Q;
    Q = new ElmList_Penumpang;
    info(Q) = x;
    next(Q) = NULL;
    return Q;
}
void InserLastGrandchild(addressM &P, addressP Q){
    addressP Z;
    Z = GrandChild(P);
    if (GrandChild(P) == NULL){
        GrandChild(P) = Q;
    }else{
        while (next(Z) != NULL){
            Z = next(Z);
        }
        next(Z) = Q;
    }
}
void DeleteGrandchild(addressM &P, addressP Q){
   addressP Z;
   Z = GrandChild(P);
   if (GrandChild(P) != NULL){
        if (next(GrandChild(P)) == NULL && GrandChild(P) == Q){
            GrandChild(P) = NULL;
        }else if (next(GrandChild(P)) != NULL && GrandChild(P) == Q){
            GrandChild(P) = next(Q);
            next(Q) = NULL;
        }else{
            while(next(Z)!= Q){
                Z = next(Z);
            }
            next(Z) = next(Q);
            next(Q) = NULL;
        }
    delete Q;
   }
}
addressP FindElmGrandchild(addressM P, string x){
    addressP Q;
    addressP Z;
    Q = GrandChild(P);
    while (Q != NULL){
        if (info(Q).Nama_Penumpang == x){
            Z = Q;
            Q = next(Q);
        }else{
            Q = next(Q);
        }
    }
    return Z;
}
void PrintInfoGrandChild(addressM P){
    addressP Q;
    Q = GrandChild(P);
    if (Q == NULL){
        cout << "Tidak Memiliki Grandchild"<<endl;
    }else{
        while (Q != NULL){
            cout << info(Q).Nama_Penumpang<<endl;
            Q = next(Q);
        }
    }
}
int HitungGrandchildPadaChildTertentu(addressM child){
    int i;
    addressP P;
    P = GrandChild(child);
    while (P != NULL){
            i++;
            P = next(P);
    }
    return i;
}
