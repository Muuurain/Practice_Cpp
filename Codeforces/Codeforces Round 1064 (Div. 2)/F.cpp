#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 1e6 + 5;
bool vis[N];
int a[N], n;
vector<int> pos[N * 2];
int solve()
{
	int i, p, ans = 0;
	vector<int> tmp;
	for(i = 1; i < 2 * n; i++)
	{
		if(i & 1)
		{
			p = 0;
			for(auto o: pos[i])
			{
				while(p < pos[i + 1].size() && pos[i + 1][p] < o)
					p++;
				if(p < pos[i + 1].size())
					vis[pos[i + 1][p++]] = 1;
			}
		}
		else
		{
			p = pos[i + 1].size();
			reverse(pos[i].begin(), pos[i].end());
			for(auto o: pos[i])
			{
				while(p && pos[i + 1][p - 1] > o)
					p--;
				if(p)
					vis[pos[i + 1][--p]] = 1;
			}
		}
		tmp.clear();
		for(auto o: pos[i + 1])
			if(vis[o])
				ans++;
			else
				tmp.emplace_back(o);
		pos[i + 1] = tmp;
	}
	return ans;
}
 
int main()
{
	int t, i, ans;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		for(i = 1; i <= n; i++)
			scanf("%d", a + i);
		for(i = 1; i <= n; i++)
			vis[i] = 0;
		for(i = 1; i <= 2 * n; i++)
			pos[i].clear();
		for(i = 1; i <= n; i++)
			pos[a[i]].emplace_back(i);
		ans = n - solve();
		reverse(a + 1, a + n + 1);
		for(i = 1; i <= n; i++)
			vis[i] = 0;
		for(i = 1; i <= 2 * n; i++)
			pos[i].clear();
		for(i = 1; i <= n; i++)
			pos[a[i]].emplace_back(i);
		ans -= solve();
		printf("%d\n", ans);
	}
	return 0;
}