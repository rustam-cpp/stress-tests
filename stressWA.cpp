#include <ctime>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <cstdlib>

using namespace std;

const int evtst = 100;

int main() {
    system("g++ ok.cpp -o outs/ok -O2");
    cout << "OK compiled\n";
    system("g++ nok.cpp -o outs/nok -O2");
    cout << "NOK compiled\n";
    system("g++ testgen.cpp -o outs/tst");
    cout << "TESTGEN compiled\n";
    system("g++ checker.cpp -o outs/chk -DDEFAULT -Ofast");
           // Leave -DDEFAULT if you just want to get WA
           // when ok.cpp and nok.cpp gives different answers
    cout << "CHECKER compiled\n";
    int test = 0;
    auto start = chrono::steady_clock::now().time_since_epoch().count();
    auto end = start;
    while (true) {
        system("./\"outs/tst\" > outs/tst.txt");
        system("./\"outs/ok\" < outs/tst.txt > outs/ok.txt");
        system("./\"outs/nok\" < outs/tst.txt > outs/nok.txt");
        if (system("./\"outs/chk\"")) {
            end = chrono::steady_clock::now().time_since_epoch().count();
            cout << "WA on test " << test + 1 << "\nstress-time: " << (end - start) / 1000000000.0 << " sec\n";
            cout << "TEST:\n";
            system("cat outs/tst.txt");
            cout << "\nExpected:\n";
            system("cat outs/ok.txt");
            cout << "\nFind:\n";
            system("cat outs/nok.txt");
            cout.flush();
            return 0;
        } else {
            if (test % evtst == evtst - 1) {
                end = chrono::steady_clock::now().time_since_epoch().count();
                cout << fixed << setprecision(3);
                cout << test + 1 << " OKs; stress-time: " << (end - start) / 1000000000.0 << " sec\n";
            }
            cout.flush();
        }
        test++;
    }
}