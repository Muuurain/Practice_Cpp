#include <bits/stdc++.h>
using namespace std;

const int maxx = 1e5 + 10;
double fd[maxx];
int N, F;
double l = 0, r = 0;
double prefix[maxx];
bool value(double mid) {
    for(int i = 1; i <= N; i++) prefix[i] = prefix[i - 1] + fd[i] - mid;
    double t = 0;
    for(int i = F; i <= N; i++) {
        t = min(t, prefix[i - F]);
        if(prefix[i] > t) return true;
    }
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> F;
    for(int i = 1; i <= N; i++) {
        cin >> fd[i];
        r = max(r, fd[i]);
    }
    while(r - l > 1e-5) {
        double mid = (r + l) / 2;
        if(value(mid)) {
            l = mid;
        }
        else {
            r = mid;
        }
    }
    cout << (int)(r * 1000) << '\n';

    return 0;
}
