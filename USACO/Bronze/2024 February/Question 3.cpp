#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

void farmVisit(int N, int Q, vector<int>& closingT, vector<int>& moveTime, const vector<pair<int, int>>& questions) {

    vector<int> latestStime(N);
    for (int i = 0; i < N; ++i) {
        latestStime[i] = closingT[i] - moveTime[i];
    }
    
  
    sort(latestStime.begin(), latestStime.end());
    

    vector<int> prefixSum(*max_element(latestStime.begin(), latestStime.end()) + 1, 0);
    for (int time : latestStime) {
        if (time >= 0) {
            prefixSum[time]++;
        }
    }
    

    for (int i = 1; i < prefixSum.size(); ++i) {
        prefixSum[i] += prefixSum[i - 1];
    }
    
    
    for (const auto& query : questions) {
        int V = query.first;
        int S = query.second;
        
        int farm = S < prefixSum.size() ? prefixSum.back() - prefixSum[S] : 0;
        
        cout << (farm >= V ? "YES" : "NO") << endl;
    }
}

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<int> closeTime(N), moveTime(N);
    for (int& time : closeTime) {
        cin >> time;
    }

    for (int& time : moveTime) {
        cin >> time;
    }

    vector<pair<int, int>> queries(Q);
    for (auto& query : queries) {
        cin >> query.first >> query.second;
    }

    farmVisit(N, Q, closeTime, moveTime, queries);

    return 0;
}

