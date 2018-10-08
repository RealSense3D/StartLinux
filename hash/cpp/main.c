#include <iostream>
#include "StringHash.h"

using namespace std;

int main()
{
    unsigned long r1, r2;
    StringHash a;
    char str1[] = "arr\\units.dat";
    char str2[] = "unit\\ueutral\\acritter.grp";
    char str3[] = "unit\\ueutral\\acritter.grp";

    r1 = a.Hash(str1);
    r2 = a.Hash(str2);

    r1 = a.Hashed(str1);
    r2 = a.Hashed(str2);

    cout << "r1[" << dec << r1 << "]\n";
    cout << "r2[" << dec << r2 << "]\n";

    return 0;
}

