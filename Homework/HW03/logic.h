#ifndef LOGIC_H
#define LOGIC_H
#include <stdbool.h>

extern bool cOut, tmpS, tmpC;
extern bool z0, z1, z2, z3, z4, z5, z6, z7;

bool norGate(bool, bool);
bool notGate(bool);
bool andGate(bool, bool);
bool orGate(bool, bool);
bool xorGate(bool, bool);
bool xnorGate(bool, bool);
bool nandGate(bool, bool);
bool halfAdder(bool, bool);
bool fullAdder(bool, bool, bool);
#endif

