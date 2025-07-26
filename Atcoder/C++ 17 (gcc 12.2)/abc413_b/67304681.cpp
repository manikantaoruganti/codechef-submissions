#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<string> S(N);

    for (int i = 0; i < N; ++i) {
        cin >> S[i];
    }

    set<string> uniqueConcatenations;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i != j) {
                uniqueConcatenations.insert(S[i] + S[j]);
            }
        }
    }

    cout << uniqueConcatenations.size() << endl;

    return 0;
}
