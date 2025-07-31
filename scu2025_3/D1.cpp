#include<iostream>
#include<vector>
using namespace std;
const int N = 1e5 + 9;
int n, k;
int arr[N], dp1[N][21], dp2[N][21];
vector<int> v[N];
void dfs1(int son,int parent)
{
    dp1[son][0] = arr[son];
    for (int i = 0; i < v[son].size(); i++)
    {
        int nx = v[son][i];
        if (nx == parent) continue;
        dfs1(nx, son);
        for (int j = 1; j <= k; j++) dp1[son][j] += dp1[nx][j - 1];
    }
    
}
void dfs2(int son, int parent)
{
    for (int i = 0; i < v[son].size(); i++)
    {
        int nx = v[son][i];
        dp2[nx][0] = arr[nx];
        if (nx == parent) continue;
        dp2[nx][1] = dp1[nx][1] + dp2[son][0];
        for (int j = 2; j <= k; j++) dp2[nx][j] = dp1[nx][j] + dp2[son][j - 1] - dp1[nx][j - 2];
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    for (int i = 1; i <= n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for (int i = 1; i <= n; i++) cin >> arr[i];
    dfs1(1, 0);
    for (int j = 0; j <= k; j++) dp2[1][j] = dp1[1][j];
    dfs2(1, 0);
    for (int i = 1; i <= n; i++) 
    {
        int ans = 0;
        for (int j = 0; j <= k; j++) 
        {
            ans += dp2[i][j];
        }
        cout << ans << endl;
    }
    return 0;
}