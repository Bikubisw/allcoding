#include <iostream>
#include <vector>
#include <map>
#include <climits>
#include <cfloat>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <cmath>
#include <algorithm>
#include <iterator>
#include <cstdlib>
#include <cassert>
#include <utility>
#include <unordered_set>
#include <set>
#include <cmath>
#include <iomanip>
#include <functional>
using namespace std;
using ll=long long int;
using ull= unsigned long long int;
using ppi= pair<int,pair<int,int>>;
using pi= pair<int,int>;
#define all(x) (x).begin(),(x).end()
#define MOD 1e9+7
#define pb push_back
#define f first
#define s second
#define INF 1e18
#define NINF -1e18
#define endl '\n'
#define IOS ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
int main()
{
    IOS;
	int k;
	cin>>k;
	string s;
	cin>>s;
	s+='&';
	reverse(all(s));
	vector<int>arr((1<<(k+1)));
	for(int i=(1<<k);i<(1<<(k+1));i++){
		arr[i]=1;
	}
	for(int i=(1<<k)-1;i>0;i--){
	if(s[i]=='0')arr[i]=arr[2*i+1];
	else if(s[i]=='1')arr[i]=arr[2*i];
	else arr[i]=arr[2*i]+arr[2*i+1];
	}
	int q;
	cin>>q;
	while(q--){
		int p;
		char c;
		cin>>p>>c;
		p=(1<<k)-p;
		s[p]=c;
		while(p){
		if(s[p]=='0')arr[p]=arr[2*p+1];
		else if(s[p]=='1')arr[p]=arr[2*p];	
		else arr[p]=arr[2*p]+arr[2*p+1];
		p/=2;
		}
			cout<<arr[1]<<endl;
	}
    return 0;
}
