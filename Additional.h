#ifndef ADDITIONAL_H_INCLUDED
#define ADDITIONAL_H_INCLUDED
#include <iostream>
#include "Parents.h"
#include "Child.h"
#include "Relation.h"

using namespace std;

int selectMenu();
void InsertDataParent(L1 &Parent, addressB &P);
void ShowAllDataParent(L1 Parent);
void MenghapusDataParentSertaRelasi(L1 &Parent);
void MencariDataParent(L1 Parent);
void MencariDataChild(L2 Child);
void InsertDataChild(L2 &Child, addressM P);
void MenghubungkanDataParentKeChild(LR &Relation, L1 &Parent, L2 &Child);
void MenampilkanSeluruhDataParentDanChild(LR Relation, L1 Parent);
void MencariDataChildDariParentTertentu(LR Relation, string x);
void MenghapusDataChildDariParentTertentu(LR &Relation, L2 &Child);
void MenghitungDataChildParentTertentu(LR Relation);
void InsertDataGrandChild(addressM &Grand_Child, addressP Q);
void MenghapusDataGrandChildDariChildTertentu(addressM &Child);
void ShowAllDataGrandChild(addressM P);
void printParentChildGrandchild(LR Relation, L1 Parent, L2 Child);

#endif // ADDITIONAL_H_INCLUDED
