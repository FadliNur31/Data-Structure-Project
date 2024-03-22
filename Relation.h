#ifndef RELATION_H_INCLUDED
#define RELATION_H_INCLUDED

#include <iostream>

#define next(p) (p)->next
#define prev(p) (p)->prev
#define first(L) ((L).first)
#include "Child.h"
#include "Parents.h"
#define child(p) (p)->child
#define parent(p) (p)->parent

using namespace std;
typedef struct Elm_Relation *addressR;

struct Elm_Relation{
    addressM child;
    addressB parent;
    addressR next;
    addressR prev;
};

struct LR{
    addressR first;
};

void CreateRelation(LR &L);
addressR AllocateRelation(addressM C, addressB B);
void InsertLastRelation(LR &L, addressR P);
void DeleteRelation(LR &L, addressR P);
addressR FindElmRelation(LR &L, Maskapai x1, Data_Bandara x2);
void printInfoRelation(LR L);
int HitungChildPadaParentTertentu(LR relation, string x);

#endif // RELATION_H_INCLUDED
