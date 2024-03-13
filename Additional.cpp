#include <iostream>
#include "Additional.h"
#include "Parents.h"
#include "Child.h"
#include "Relation.h"

using namespace std;

int selectMenu(){
    cout << "===== MENU =====" << endl;
    cout << "1.  Insert Data Parent Dari Depan/Belakang " << endl;
    cout << "2.  Show all Data Parent" << endl;
    cout << "3.  Menghapus Data Parent Beserta Relasi" << endl;
    cout << "4.  Mencari Data Parent" << endl;
    cout << "5.  Mencari Data Child" << endl;
    cout << "6.  Menambah Data Child" << endl;
    cout << "7.  Menghubungkan Data Parent Ke Child" << endl;
    cout << "8.  Menampilkan Seluruh Data Parent dan Child" << endl;
    cout << "9.  Mencari Data Child Pada Parent Tertentu" << endl;
    cout << "10. Menghapus Data Child Pada Parent Terentu Beserta Relasi nya " << endl;
    cout << "11. Menghitung Jumlah Data Child Dari Parent Tertentu" << endl;
    cout << "12. Menambahkan Data Grand Child Pada Child Tertentu" << endl;
    cout << "13. Menampilkan Data Grand Child Pada Child Tertentu" << endl;
    cout << "14. Menghapus Data Grand Child dari Child Tertentu" << endl;
    cout << "15. Menampilkan Parent, Child, dan Grand Child" << endl;
    cout << "0.  Exit" << endl;
    int input = 0;
    cin >> input;
    return input;
}

void InsertDataParent(L1 &Parent, addressB &P){
    Data_Bandara A;
    addressB Q;
    int c;
    cout << "Masukkan Nama Bandara   : ";
    cin >> A.Nama_Bandara;
    cout << "Masukkan Daerah Bandara : ";
    cin >> A.Daerah_bandara;
    cout << "Masukkan Jumlah Max Maskapai pada bandara : ";
    cin >> A.max_maskapai;
    Q = FindElmParent(Parent, A.Nama_Bandara);
    if (Q == NULL){
        P = AllocateParent(A);
        cout << "Tekan 1 Untuk Insert Dari Depan Atau Tekan 2 Untuk Insert Dari Belakang"<<endl;
        cin >> c;
        switch(c){
        case 1 :
        InsertFirstParent(Parent,P);
            break;
        case 2:
        InsertLastParent(Parent, P);
            break;
        }
        cout << "Data Berhasil Ditambahkan"<<endl;;
    }else{
        cout << "Maaf Bandara Sudah Ada!"<<endl;
    }

}
void ShowAllDataParent(L1 Parent){
    PrintInfoParent(Parent);
}
void MenghapusDataParentSertaRelasi(L1 &Parent){
    string Nama_Bandara;
    addressB P;
    cout << "Masukkan Nama Bandara Yang Akan Dihapus : ";
    cin >> Nama_Bandara;
    P = FindElmParent(Parent, Nama_Bandara);
    if (P != NULL){
        DeleteParent(Parent,P);
        cout << "Parent Saat Ini"<<endl;
        cout<<endl;
        PrintInfoParent(Parent);
    }else{
        cout << "Maaf Data Tidak Ditemukan"<<endl;
    }
}
void MencariDataParent(L1 Parent){
    string Nama_Bandara;
    addressB P;
    cout << "Masukkan Nama Bandara Yang Akan Dicari : ";
    cin >> Nama_Bandara;
    P = FindElmParent(Parent, Nama_Bandara);
    if (P != NULL){
        cout << "Nama Bandara   : "<< info(P).Nama_Bandara << endl;
        cout << "Daerah Bandara : "<< info(P).Daerah_bandara << endl;
    }else{
        cout << "Maaf Data Tidak Ditemukan"<<endl;
    }

}
void MencariDataChild(L2 Child) {
    string cari;
    addressM P;
    cout << "Masukkan Nama Maskapai Yang Ingin Dicari : ";
    cin >> cari;
    P = FindElmChild(Child, cari);
    if (P != NULL) {
        cout << "Nama Maskapai : " << info(P).Nama_Maskapai << endl;
        cout << "Kode Pesawat : " << info(P).Kode_Pesawat << endl;
        cout << "Tujuan : " << info(P).Tujuan << endl;
        cout << "Maksimal Penumpang : " << info(P).Max_Penumpang << endl;
    } else {
        cout << "Maaf Data Tidak Ditemukan"<<endl;
    }

}

void InsertDataChild(L2 &Child, addressM P) {
    Maskapai B;
    addressM Q;
    cout << "Masukkan Nama Maskapai : ";
    cin >> B.Nama_Maskapai;
    cout << "Kode Pesawat : ";
    cin >> B.Kode_Pesawat;
    cout << "Masukkan Tujuan : ";
    cin >> B.Tujuan;
    cout << "Masukkan Maksimal Penumpang : ";
    cin >> B.Max_Penumpang;
    Q = FindElmChild(Child, B.Nama_Maskapai);
    if (Q == NULL){
        P = AllocateChild(B);
        InserLastChild(Child, P);
        cout << "Data Berhasil Ditambahkan";
    } else {
        cout << "Maaf Maskapai Sudah Ada!";
    }
    cout << endl;
}

void MenghubungkanDataParentKeChild(LR &Relation, L1 &Parent, L2 &Child){
    int i;
    string x,y;
    addressB P;
    addressM Q;
    addressR Z;
    cout << "Silahkan Input Parent : ";
    cin >> x;
    cout << "Silahkan Input Child : ";
    cin >> y;
    P = FindElmParent(Parent, x);
    Q = FindElmChild(Child, y);
    if (P == NULL || Q == NULL){
        cout << "Maaf Parent atau Child Tidak Ditemukan" << endl;
    } else {
        i = HitungChildPadaParentTertentu(Relation,info(P).Nama_Bandara);
        if (i < info(P).max_maskapai){
            Z = AllocateRelation(Q,P);
            InsertLastRelation(Relation, Z);
            cout << "Data Berhasil Dihubungkan" << endl;
        }else{
            cout << "Maaf jumlah maskapai pada bandara ini sudah penuh"<<endl;
        }
    }

}

void MencariDataChildDariParentTertentu(LR Relation, string x){
    addressR P;

    bool a = false;
    P = first(Relation);

    while (P != NULL) {
        if (info(parent(P)).Nama_Bandara == x) {
            a = true;
            cout << info(child(P)).Nama_Maskapai << ", ";
        }
        P = next(P);
    }
    cout<<endl;
    if (!a){
        cout << "Tidak Memiliki Child"<<endl;
    }
}


void MenampilkanSeluruhDataParentDanChild(LR Relation, L1 Parent){
    addressB P;
    P = first(Parent);
    while (P != NULL) {
        cout << info(P).Nama_Bandara << " - ";
        MencariDataChildDariParentTertentu(Relation, info(P).Nama_Bandara);
        P = next(P);
    }
    cout << endl;
}

void MenghapusDataChildDariParentTertentu(LR &Relation, L2 &Child) {
    addressR P = first(Relation);
    addressR Q;
    string x;
    cout << "Masukkan Nama Parent Yang Akan Dihapus : ";
    cin >> x;
    while (P != NULL) {
        Q = next(P);
        if (info(parent(P)).Nama_Bandara == x) {
            DeleteChild(Child, child(P));
            DeleteRelation(Relation, P);
        }
        P = Q;
    }
    cout << "Semua Data Child Pada Parent Ini Berhasil Dihapus" << endl;

}

void MenghitungDataChildParentTertentu(LR Relation){
    string x;
    int i = 0;
    addressR P;
    cout << "Masukkan Nama Parent : ";
    cin >> x;
    P = first(Relation);
    i = HitungChildPadaParentTertentu(Relation, x);
    if (first(Relation) == NULL){
        cout << "Parent tersebut tidak memiliki child"<<endl;
    }else{
        cout << "Jumlah Child Pada Parent Tersebut ialah "<< i <<endl;
    }
}

void InsertDataGrandChild(addressM &Child, addressP Q) {
    int i = 0;
    Data_Penumpang B;
    addressP P;
    cout << "Masukkan Nama Penumpang   : ";
    cin >> B.Nama_Penumpang;
    cout << "Masukkan Kode Pesawat Penumpang   : ";
    cin >> B.Kode_Pesawat;
    cout << "Masukkan Tujuan Penumpang   : ";
    cin >> B.Tujuan;
    if (GrandChild(Child) == NULL){
        Q = AllocateGrandchild(B);
        InserLastGrandchild(Child, Q);
        cout << "Data Berhasil Ditambahkan" << endl;
    }else{
        P = FindElmGrandchild(Child, B.Nama_Penumpang);
        if (P == NULL) {
            i = HitungGrandchildPadaChildTertentu(Child);
            if (i < info(Child).Max_Penumpang){
                Q = AllocateGrandchild(B);
                InserLastGrandchild(Child, Q);
                cout << "Data Berhasil Ditambahkan" << endl;
            }else{
                cout << "Jumlah Penumpang pada maskapai telah penuh"<<endl;
            }
        } else {
            cout << "Maaf Nama Penumpang Sudah Ada!" << endl;
        }
    }

}

void MenghapusDataGrandChildDariChildTertentu(addressM &Child) {
    addressP P;
    string grandChildName;
    cout << "Masukkan Grand Childnya: ";
    cin >> grandChildName;
    P = GrandChild(Child);
    if (P != NULL) {
        addressP Q = FindElmGrandchild(Child, grandChildName);
        if (Q != NULL) {
            DeleteGrandchild(Child,Q);
            cout << "Data GrandChild dengan nama " << grandChildName << " pada Child " << info(Child).Nama_Maskapai << " berhasil dihapus" << endl;
        } else {
            cout << "Maaf GrandChild dengan nama " << grandChildName << " tidak ditemukan pada Child " << info(Child).Nama_Maskapai << endl;
        }
    } else {
        cout << "Maaf Child dengan nama " << info(Child).Nama_Maskapai << " tidak ditemukan!" << endl;
    }
}

void ShowAllDataGrandChild(addressM Child) {
    PrintInfoGrandChild(Child);
}

void printParentChildGrandchild(LR Relation, L1 Parent, L2 Child) {
    addressB P;
    P = first(Parent);

    while (P != NULL) {
        cout << "Parent: " << info(P).Nama_Bandara << endl;

        addressR Q = first(Relation);
        while (Q != NULL) {
            if (info(parent(Q)).Nama_Bandara == info(P).Nama_Bandara) {
                cout << "Child: " << info(child(Q)).Nama_Maskapai << endl;

                addressP R = GrandChild(child(Q));
                if (R != NULL) {
                    cout << "Grandchild: ";
                    while (R != NULL) {
                        cout << info(R).Nama_Penumpang << ", ";
                        R = next(R);
                    }
                    cout << endl;
                } else {
                    cout << "Tidak ada Grandchild" << endl;
                }
            }
            Q = next(Q);
        }
        P = next(P);
        cout << endl;
    }
}

