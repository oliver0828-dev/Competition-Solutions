#include <iostream>
using namespace std;

int main() {
    int D, y;
    cin >> D;
    while (cin >> y) {
        if (y >= D) {
            cout << D;
            break;
        } else {
            D += y;
        }
    }

    return 0;
}
