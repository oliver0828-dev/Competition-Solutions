#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    string s;
    cin >> s;
    vector<int> arr;
    long long sum = 0;
    s = s+s+s;
    for(int i = 0; i < N; i++){
        int n;
        cin >> n;
        arr.push_back(n);
        sum += n;
    }

    for(int i = N; i < 2*N; i++){
        if(s[i] == 'R' && s[i+1] == 'L'){
            long long l = i-1;
            long long lWaste = 0;
            while(s[l] == 'R'){
                lWaste += arr[l%N];
                l--;
            }
            sum -= min(M, lWaste);
            long long r = i + 2;
            long long rWaste = 0;
            while (s[r] == 'L') {
                rWaste += arr[r%N];
                r++;
            }
            sum -= min(M, rWaste);
        }
    }
    
    cout << sum; 
    
    
}
