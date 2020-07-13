#include "../../head.h"


int play(int n) {
    std::vector<int> nList(1024, 0);
    int nBal;
    int i = 0, j = 0;
    int iResult = 0;
    nBal = n; // 1
    while (nBal > 1) {
        i %= n; // 2
        if (nList[i] == 0) {
            j++;
            if (j == 3) { // 3
                nList[i] = 1;
                j = 0; // 4
                nBal--;
            } else {
                iResult = i; // 5
            }
        }
        i++;
    }
    std::cout << iResult + 1 << "\n";
    return iResult + 1;
}

int main() {
    play(200);
    return 0;
}
