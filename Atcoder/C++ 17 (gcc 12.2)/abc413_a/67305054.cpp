#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> A(N);
    int total = 0;

    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        total += A[i];
    }

    if (total <= M)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}
