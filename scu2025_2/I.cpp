#include <bits/stdc++.h>

using namespace std;

#define mod 100000000
typedef long long ll;
ll A[500000];
int main() {   
    ll N = 0;
    cin >> N;
    ll ret = 0;
    for(int i = 0; i < N; i++) {
        scanf("%lld", &A[i]);
    }
    for(int i = 0; i < N - 1; i++) {
        for(int j = i + 1; j < N; j++) {
            ret += (A[i] + A[j]) % mod;
        }
    }
    cout << ret << endl;

    return 0;
}