#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int r = 3;
    int g = 4;
    int b = 5;
    int sum = 0;
    vector<int> arr;
    for(int i = 0; i < 3; i++){
        int n;
        cin >> n;
        arr.push_back(n);
    }
    sum += r*arr[0];
    sum += g*arr[1];
    sum += b*arr[2];
    cout << sum;

}
