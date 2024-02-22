#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n;
    string n1;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> n1;
        if(n1[n1.size()-1] == '0'){
            cout << 'E' << '\n';
        }else{
            cout << 'B' << '\n';
        }
    }

}
