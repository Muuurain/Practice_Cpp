#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    int t = 1;
    while(t < N) {
        N -= t;
        t++;
    }
    if (t % 2 == 0) {
        cout << N << "/" << t - N + 1 << endl;
    } else {
        cout << t - N + 1 << "/" << N << endl;
    }

    return 0;
}