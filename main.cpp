#include <iostream>
#include "Parents.h"
#include "Child.h"
#include "Relation.h"
#include "Additional.h"

using namespace std;

int main() {
    L1 Parent;
    L2 Child;
    LR Relation;
    addressB P;
    addressM Q, S;
    addressP Z;
    string x,g;
    CreateParent(Parent);
    CreateChild(Child);
    CreateRelation(Relation);
    int n = 0;
    int pilihan = selectMenu();
    while (pilihan != 0){
        switch(pilihan){
        case 1:
            InsertDataParent(Parent, P);
            break;
        case 2:
            ShowAllDataParent(Parent);
            break;
        case 3:
            MenghapusDataParentSertaRelasi(Parent);
            break;
        case 4:
            MencariDataParent(Parent);
            break;
        case 5:
            MencariDataChild(Child);
            break;
        case 6:
            InsertDataChild(Child, Q);
            break;
        case 7:
            MenghubungkanDataParentKeChild(Relation, Parent, Child);
            break;
        case 8:
            MenampilkanSeluruhDataParentDanChild(Relation, Parent);
            break;
        case 9:
            cout << "Silahkan Masukkan Parent : ";
            cin >> x;
            MencariDataChildDariParentTertentu(Relation, x);
            break;
        case 10:
            MenghapusDataChildDariParentTertentu(Relation, Child);
            break;
        case 11:
            MenghitungDataChildParentTertentu(Relation);
            break;
        case 12:
            cout << "Masukkan Child yang akan ditambahkan granchildnya : ";
            cin >> g;
            S = FindElmChild(Child,g);
            if (S == NULL){
                cout << "Maaf Child yang akan ditambahkan tidak ditemukan"<<endl;
            }else{
                InsertDataGrandChild(S,Z);
            }
            break;
        case 13:
            cout << "Masukkan Child yang akan ditampilkan Grand Child nya : ";
            cin >> g;
            S = FindElmChild(Child,g);
            ShowAllDataGrandChild(S);
            break;
        case 14:
            cout << "Masukkan Child yang ingin dihapus Grand Child nya : ";
            cin >> g;
            S = FindElmChild(Child,g);
            MenghapusDataGrandChildDariChildTertentu(S);
            break;
        case 15:
            printParentChildGrandchild(Relation, Parent, Child);
            break;
        }
        pilihan = selectMenu();
    }


    cout << "Assalamualaikum, Terima Kasih"<<endl;
    return 0;

}





