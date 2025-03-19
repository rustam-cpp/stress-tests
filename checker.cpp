#include <cstdlib>

int main() {
#ifdef DEFAULT
    if (system("diff -w outs/nok.txt outs/ok.txt > /dev/null")) {
        return 1;
    } else {
        return 0;
    }
#else
    // write here your own checker
    // if it's many correct answers

    // use freopen("outs/nok.txt", "r", stdin);
    // if you want to get the answer from wrong programm

    // use freopen("outs/ok.txt", "r", stdin);
    // if you want to get the answer from correct programm
#endif
}