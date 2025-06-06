#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll choic(ll a) {
    ll sum = (1 + a) * a / 2;
    return sum;
}
ll calsq(int m, int n) {
    ll sum = 0;
    while(m * n != 0) {
        sum += m * n;
        m--;
        n--;
    }
    return sum;
}
int main() {
    ll m, n;
    cin >> m >> n;
    ll sum = choic(m) * choic(n);
    ll sumsq = calsq(m, n); 
    ll sumre = sum - sumsq;
    cout << sumsq << " " << sumre << endl;  

    return 0;
}