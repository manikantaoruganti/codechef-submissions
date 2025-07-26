#include <iostream>
#include <deque>
using namespace std;

using ll = long long;

int main() {
    int Q;
    cin >> Q;

    deque<pair<ll, ll>> dq; // pair: {value, count}
    
    while (Q--) {
        int type;
        cin >> type;
        
        if (type == 1) {
            ll c, x;
            cin >> c >> x;
            dq.emplace_back(x, c); // push to end
        } else {
            ll k;
            cin >> k;
            ll sum = 0;

            while (k > 0) {
                auto [val, cnt] = dq.front();
                dq.pop_front();
                if (cnt <= k) {
                    sum += val * cnt;
                    k -= cnt;
                } else {
                    sum += val * k;
                    dq.emplace_front(val, cnt - k);
                    k = 0;
                }
            }
            cout << sum << '\n';
        }
    }

    return 0;
}
