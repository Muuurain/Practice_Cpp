#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll cal(const vector<int>& a)
{
	int mid = a.size()/2;ll sum=0;
	for(int i=1;i+mid<a.size();i++)
		sum+=abs(abs(a[mid-i])-abs(a[i+mid]));
	return sum;
}
void cut(const vector<int>& a,vector<int>& b,vector<int>& c)
{
	int mid = a.size()/2;
	for(int i=1;i+mid<a.size();i++)
		b[mid-i]=b[mid+i]=(a[mid-i]+a[i+mid])/2;
	for(int i=0;i<a.size();i++) c[i]=a[i]-b[i];
	return;
}
int main()
{
	int n;cin>>n;
	vector<int> a(n,0),b(n,0),c(n,0);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	cut(a,b,c);
	if(cal(a)>n+cal(b)+cal(c))
	{
		printf("2 %lld\n",n+cal(b)+cal(c));
		for(int x:b) printf("%d ",x);printf("\n");
		for(int x:c) printf("%d ",x);
	}
	else
	{
		printf("1 %lld\n",cal(a));
		for(int x:a) printf("%d ",x);
	}
	return 0;
}
