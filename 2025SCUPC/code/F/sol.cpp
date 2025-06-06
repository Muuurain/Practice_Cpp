#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128 i128;
i128 read(){
    char ch = getchar();
    while(!isdigit(ch)) ch = getchar();
    i128 ans = 0;
    while(isdigit(ch)) ans = ans * 10 + ch - '0', ch = getchar();
    return ans;
}
void write(i128 w){
    if(w >= 10) write(w / 10);
    putchar(w%10+'0');
}
const int N = 121;
int in(i128 w, int id){
    return (w >> id) & 1;
}
ll m, k;
i128 C[N][N];
i128 solve(i128 lim){
    int hv = 0;
    i128 ans = 0;
    for(int i = 120; i >= 0; i--){
        if(!in(lim, i)) continue;
        ans += C[i][k-hv];
        hv++;
        if(hv > k) break;
    }
    if(hv == k) ans++;
    return ans;
}
bool check(i128 n){
    return solve(n*2) - solve(n) >= m;
}
i128 binary_search(){
    i128 l = 0, r = 1e18, ans = -1;
    r *= r;
    while(l <= r){
        i128 mid = (l + r) >> 1;
        if(check(mid)) ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    if(solve(ans<<1ll) - solve(ans) != m) return -1;
    return ans;
}
int main(){
    //freopen("./data/data.in", "r", stdin);
    for(int i = 0; i < N; i++){
        C[i][0] = C[i][i] = 1;
        for(int j = 1; j < i; j++) C[i][j] = C[i-1][j-1] + C[i-1][j];
    }
    int _; scanf("%d", &_);
    while(_--){
        scanf("%lld%lld", &m, &k);
        write(binary_search()); putchar('\n');
    }
    return 0;
}
/*
1 
10000000000000000 35
*/
