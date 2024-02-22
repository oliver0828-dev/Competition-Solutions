#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> scores(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> scores[i];
    }

    sort(scores.rbegin(), scores.rend());

    int uniqueScores = 1;
    int bronzeScore = scores[0];

    for (int i = 1; i < N; ++i) {
        if (scores[i] != scores[i - 1]) {
            uniqueScores++;
            if (uniqueScores == 3) {
                bronzeScore = scores[i];
                break;
            }
        }
    }


    int bronzeCount = count(scores.begin(), scores.end(), bronzeScore);
    
    cout << bronzeScore << " " << bronzeCount;
    
}
