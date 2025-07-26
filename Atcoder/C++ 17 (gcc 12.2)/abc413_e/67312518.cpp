#include <bits/stdc++.h>
using namespace std;

void solve_case() {
    int N;
    cin >> N;
    int size = 1 << N;
    vector<int> P(size);
    for (int i = 0; i < size; ++i) {
        cin >> P[i];
    }

    function<vector<int>(vector<int>, int)> dfs = [&](vector<int> a, int depth) -> vector<int> {
        if (depth == 0) return a;
        int len = a.size();
        int mid = len / 2;

        vector<int> left(a.begin(), a.begin() + mid);
        vector<int> right(a.begin() + mid, a.end());

        left = dfs(left, depth - 1);
        right = dfs(right, depth - 1);

        vector<int> merged1, merged2;
        merged1.insert(merged1.end(), left.begin(), left.end());
        merged1.insert(merged1.end(), right.begin(), right.end());

        merged2.insert(merged2.end(), right.begin(), right.end());
        merged2.insert(merged2.end(), left.begin(), left.end());

        return min(merged1, merged2);
    };

    vector<int> res = dfs(P, N);
    for (int val : res) cout << val << " ";
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve_case();
    }

    return 0;
}
