#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
#define rep( i , a , b ) for( int i = (a) , i##end = (b) ; i <= i##end ; ++ i )
#define per( i , a , b ) for( int i = (a) , i##end = (b) ; i >= i##end ; -- i )
const int MAXN = 2006;
int x;
string ch;
 
int cnt = 0;
int src , dst;
int S[MAXN][9] , ww[MAXN][9] , nxt[MAXN][9] , g[MAXN][10][9];
 
struct note {
	int s , t , len , ind;
};
 
namespace flow {
	const int MAXN = 2e5 + 6;
	const int MAXM = 1e6 + 6;
	int N;
	int head[MAXN] , to[MAXM] , nex[MAXM] , wto[MAXM] , cto[MAXM] , cur[MAXN] , ecn = -1;
	inline void Ade( int u , int v , int w , int c ) {
		to[++ ecn] = v , nex[ecn] = head[u] , wto[ecn] = w , cto[ecn] = c , head[u] = ecn;
	}
	inline void ade( int u , int v , int w , int c ) {
		if( !u || !v ) return;
		//cout << u << ' ' << v << ' ' << w << ' ' << c << endl;
		Ade( u , v , w , c ) , Ade( v , u , 0 , -c );
	}
	void in( int t ) {
		N = t;
		rep( i , 1 , N ) head[i] = -1;
		ecn = -1;
	}
	queue<int> Q;
	int dis[MAXN] , vis[MAXN];
	const int inf = 1e9;
	int s , t;
	bool spfa( ) {
		memset( dis , -0x3f , sizeof dis ) , memset( vis , 0 , sizeof vis );
		rep( i , 1 , N ) cur[i] = head[i];
		dis[s] = 0 , vis[s] = 1;
		Q.push( s );
		while( !Q.empty() ) {
			int u = Q.front(); Q.pop();
			vis[u] = 0;
			for( int i = head[u] ; ~i ; i = nex[i] ) if( wto[i] && dis[to[i]] < dis[u] + cto[i] ) {
				int v = to[i];
				dis[v] = dis[u] + cto[i];
				if( !vis[v] ) Q.push( v ) , vis[v] = 1;
			}
		}
		return dis[t] > -inf;
	}
	int co;
	int dfs( int u , int lim ) {
		if( !lim || u == t ) return lim;
		vis[u] = 1;
		int f , flow = 0;
		for( int& i = cur[u] ; ~i ; i = nex[i] ) if( !vis[to[i]] && wto[i] && dis[to[i]] == dis[u] + cto[i] && ( f = dfs( to[i] , min( lim , wto[i] ) ) ) ) {
			lim -= f , flow += f , wto[i] -= f , wto[i ^ 1] += f;
			co += f * cto[i];
			if( !lim ) break;
		}
		vis[u] = 0;
		return flow;
	}
	int dinic( ) {
		int re = 0;
		co = 0;
		while( spfa( ) ) {
			re += dfs( s , 0x3f3f3f3f );
			//cout << " DINIC " << re << endl;
		}
		return co;
	}
}
 
using flow::ade;
 
vector<note> vec[MAXN];
int parse_number( int l , int r ) {
	int ret = 0;
	for( int i = l ; i < r ; ++ i ) if( ch[i] >= '0' && ch[i] <= '9' ) {
		ret = ret * 10 + ch[i] - '0';
	}
	return ret;
}
 
int getnode( int i , int k , int c ) {
	int &x = g[i][k][c];
	if( !k ) {
		if( ww[i][c] ) return ww[i][c];
		return -1;
	}
	if( x ) return x;
	int ls = getnode( i , k - 1 , c ) , rs = getnode( i + ( 1 << k - 1 ) , k - 1 , c );
	if( ls || rs ) {
		x = ++ cnt;
		if( ls != -1 ) ade( x , ls , 15 , 0 );
		if( rs != -1 ) ade( x , rs , 15 , 0 );
		return x;
	}
	return x = -1;
}
 
void ade_seg( int u , int l , int r , int c ) {
	int len = r - l + 1 , cur = l;
	for( int i = 9 ; i >= 0 ; -- i ) if( len & ( 1 << i ) ) {
		int nd = getnode( cur , i , c );
		if( nd != -1 ) ade( u , nd , 14 , 0 );
		cur += ( 1 << i );
	}
}
 
int main() {
//	freopen(".in","r",stdin);
	cin >> x;
	cin >> ch;
	flow::in( 200000 );
	int cur = 1;
	for( int l = 0, r ; l < ch.size() ; l = r + 1 ) {
		r = l;
		while( r < ch.size() && ch[r] != ',' && ch[r] != '/' ) ++ r;
		note p;
		p.s = ch[l] - '0';
		p.len = p.t = 0;
		if( r > l + 1 ) {
			if( ch[l + 1] == '-' ) {
				p.t = ch[l + 2] - '0';
				p.len = parse_number( l + 4 , r - 1 );
			}
			if( ch[l + 1] == '[' ) {
				p.t = 0;
				p.len = parse_number( l + 2 , r - 1 );
			}
		}
		if( l != r )
			vec[cur].push_back( p );
		if( r < ch.size() && ch[r] == ',' ) ++ cur;
	}
	int tot = 0;
	src = ++ cnt , dst = ++ cnt;
	vector<int> las( 9 );
	rep( i , 1 , cur ) {
		for( auto& p : vec[i] ) {
			int ind = ++ cnt;
			int outd = ++ cnt;
			ww[i][p.s] = ind;
			S[i][p.s] = ++ cnt;
			ade( src , ind , 10 , 0 );
			ade( S[i][p.s] , ind , 17 , 0 );
			ade( ind , outd , 1 , 1 );
			ade( outd , dst , 11 , 0 );
			p.ind = ind;
			if( las[p.s] ) ade( las[p.s] , S[i][p.s] , 12 , 0 );
			las[p.s] = S[i][p.s];
			++ tot;
		}
	}
	per( i , cur , 1 ) {
		rep( s , 1 , 8 ) {
			nxt[i][s] = ( S[i + 1][s] ? S[i + 1][s] : nxt[i + 1][s] );
		}
	}
	rep( i , 1 , cur ) for( auto nt : vec[i] ) {
		int s = nt.s , t = nt.t , len = nt.len;
		int ind = nt.ind , outd = ind + 1;
//		cout << "NOTE " << i << ' ' << ind << ' ' << outd << ' ' << len << endl;
		if( len == 0 ) {
			ade( outd , nxt[i][s % 8 + 1] , 13 , 0 );
			ade( outd , nxt[i][s == 1 ? 8 : s - 1] , 13 , 0 );
		} else {
			if( t ) {
				int l = i + 1 , r = i + len;
				ade_seg( outd , l , r , t % 8 + 1 );
				ade_seg( outd , l , r , t == 1 ? 8 : t - 1 );
			} else {
				int l = i + len - 1;
				ade( outd , nxt[l][s % 8 + 1] , 16 , 0 );
				ade( outd , nxt[l][s == 1 ? 8 : s - 1] , 16 , 0 );
			}
		}
	}
	flow::s = ++ cnt;
	ade( cnt , src , x , 0 );
	flow::t = dst;
	flow::dinic( );
	int c = flow::co;
	if( c == tot ) cout << "FC" << endl;
	else cout << c << "/" << tot << endl;
}
