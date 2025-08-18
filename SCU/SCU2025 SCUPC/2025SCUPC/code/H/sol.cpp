#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a, b, c;
long double solve(){
    return 1.00l * abs(a-b) * abs(c) / 8.00;
}
int main(){
    int _; scanf("%d", &_);
    while(_--){
        scanf("%d%d%d", &a, &b, &c);
        printf("%.10LF\n", solve());
    }
    return 0;
}
