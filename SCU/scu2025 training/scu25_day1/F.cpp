#include <bits/stdc++.h>
using namespace std;

inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int f[(int)1e5 + 10][20];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    n = read();
    m = read();
    for(int i = 1; i <= n; i++) f[i][0] = read();
    for(int i = 1; i < 20; i++) {
        for(int j = 1; (j + (1 << i) - 1) <= n; j++) {
            f[j][i] = max(f[j][i - 1], f[j + (1 << (i - 1))][i - 1]);
        }
    }
    for(int i = 0; i < m; i++) {
        int l, r;
        l = read();
        r = read();
        int mj = log2(r - l + 1);
        int ret = max(f[l][mj], f[r - (1 << mj) + 1][mj]);
        cout << ret << '\n';
    }

    return 0;
}