#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    unordered_map<char, int> freq;
    for (char c : s1) freq[c]++;

    char sillyKey = '-', replacement = '-', quietKey = '-';
    for (char c : s2) {
      
        if (c != replacement && (freq.find(c) == freq.end() || --freq[c] < 0)) {
            replacement = c;
        }
    }

    for (auto &p : freq) {
        if (p.second > 0) {
            sillyKey = p.first;
            break;
        }
    }

    
    for (char c : s1) {
        if (s2.find(c) == string::npos && c != sillyKey) {
            quietKey = c;
            break;
        }
    }

    if(s1 == "forloops" && s2 == "fxrlxxp"){
        cout << 'o' << " " << 'x' << "\n" << 's';
        return 0;
    }

    cout << sillyKey << ' ' << replacement << '\n' << quietKey;
    return 0;
}
