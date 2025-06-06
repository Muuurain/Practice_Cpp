#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
char s[3][N];
int n;
int calc(bitset<N> *b){
    int now = (b[1] & b[2]).count(), ans = -1;
    auto f = b[1] ^ b[2];
    for(int i = 0; i <= n; i++){
        ans = max(ans, now + (int)(b[0] & f).count());
        int c = b[0][0];
        b[0] >>= 1, b[0][n-1] = c; 
    }
    return ans;
}
int solve(){
    static bitset<N> b[3];
    int ans = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++) b[j].reset();
        int c = 1;
        for(int j = 0; j < 3; j++){
            int id;
            if(i == j) id = 0;
            else id = c, c++;
            for(int k = 0; k < n; k++) b[id][k] = (s[j][k] - '0');
        }
        ans = max(ans, calc(b));
    }
    return ans;
}
int main(){
    int _; scanf("%d", &_);
    while(_--){
        scanf("%d", &n);
        for(int i = 0; i < 3; i++) scanf("%s", s[i]);
        printf("%d\n", solve());
    }
    return 0;
}
