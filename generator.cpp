#include "testlib.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);

    int t = opt<int>(1);

    int ln = opt<int>(2);
    int rn = opt<int>(3);

    ln /= 2;
    rn /= 2;

    cout << t << "\n";
    while (t--){
        int n = rnd.next(ln, rn);
        n *= 2;
        int k = rnd.next(1, n);

        cout << n << " " << k << "\n";
    }
}   
