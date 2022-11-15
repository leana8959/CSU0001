#include <stdio.h>
#include "logic.h"
#include "smallten.h"

void multiplier(bool x0, bool x1, bool x2, bool x3, bool y0, bool y1, bool y2, bool y3){
    z0 = andGate(x0,y0);
    z1 = halfAdder(andGate(x1, y0), andGate(x0, y1));

    //first row
    z2 = fullAdder(andGate(x2, y0), andGate(x1, y1), cOut);
    z3 = fullAdder(andGate(x3, y0), andGate(x2, y1), cOut);
    z4 = halfAdder(andGate(x3, y1), cOut);
    tmpC = cOut;

    //second row
    z2 = halfAdder(z2, andGate(x0, y2));
    z3 = fullAdder(z3, andGate(x1, y2), cOut);
    z4 = fullAdder(z4, andGate(x2, y2), cOut);
    z5 = fullAdder(tmpC, andGate(x3, y2), cOut);
    tmpC = cOut;

    //third row
    z3 = halfAdder(z3, andGate(x0, y3));
    z4 = fullAdder(z4, andGate(x1, y3), cOut);
    z5 = fullAdder(z5, andGate(x2, y3), cOut);
    z6 = fullAdder(tmpC, andGate(x3, y3), cOut);
    z7 = cOut;
}

int binaryToDecimal(int number){
    int remainder = 0, base = 1;
    int decimal = 0;
    while(number>0){
        remainder = number%10;
        decimal += remainder*base;
        number /= 10;
        base *= 2;
    }
    return decimal;
}

int main(){
    int aBinary = 0, bBinary = 0, aDecimal = 0, bDecimal = 0;

    communicate();

    printf("Please enter the first number (A) in binary: ");
    scanf("%d", &aBinary);
    printf("Please enter the second number (B) in binary: ");
    scanf("%d", &bBinary);


    aDecimal = binaryToDecimal(aBinary);
    bDecimal = binaryToDecimal(bBinary);

    printf("A = %d (2) = %d (10)\n", aBinary, aDecimal);
    printf("B = %d (2) = %d (10)\n", bBinary, bDecimal);

    bool a4 = aBinary / 1000;
    bool a3 = (aBinary / 100) % 10;
    bool a2 = (aBinary / 10) % 10;
    bool a1 = aBinary % 10;
    bool b4 = bBinary / 1000;
    bool b3 = (bBinary / 100) % 10;
    bool b2 = (bBinary / 10) % 10;
    bool b1 = bBinary % 10;

    multiplier(a1,a2,a3,a4,b1,b2,b3,b4);
    printf("A x B = %d * %d = %d%d%d%d%d%d%d%d (2) = %d (10)", aDecimal, bDecimal, z7, z6, z5, z4, z3, z2, z1, z0, aDecimal*bDecimal);

    return 0;
}
