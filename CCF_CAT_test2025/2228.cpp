#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1e15 + 10;
unordered_map<ll, ll> ret;

int main() {
    ll m, n;
    cin >> n >> m;
    ll temp = n;
    ll num = 1;
    ret[num] = n;
    ll num1 = 1;
    while(temp != 1) {
        if(temp % 4 == 3) {
            temp -= 3;
            num1 = num + num1 + num;
            ret[num1]++;
            temp /= 2;
            num *= 2;
            ret[num] += temp;
            temp++;
        }
        else if(temp % 2 == 1) {
            temp -= 1;
            ret[num1]++;
            temp /= 2;
            num *= 2;
            ret[num] += temp;
            temp++;
        }
        else {
            temp /= 2;
            num *= 2;
            ret[num] += temp;
            num1 = num;
        }
    }
    while(m--) {
        ll q;
        scanf("%lld", &q);
        printf("%lld", ret[q]);
        if(m) {
            printf(" ");
        }
        else {
            printf("\n");
        }
    }

    return 0;
}