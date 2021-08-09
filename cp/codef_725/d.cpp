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
#include <numeric>
using namespace std;
using ll=long long int;
using ull= unsigned long long int;
using ppi= pair<int,pair<int,int>>;
using pi= pair<int,int>;
#define all(x) (x).begin(),(x).end()
#define MOD 1000000007
#define pb push_back
#define f first
#define s second
#define INF 1e18
#define NINF -1e18
#define endl '\n'
#define IOS ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
vector<pi> prime_factor(int num){
	vector<pi> output;
	int c=0;
	while(num%2==0){
		num/=2;
		c++;
	}
	if(c!=0){output.pb({2,c});}
	for(int i=3;i*i<=num;i+=2){
		int c=0;
		while(num%i==0){
			num/=i;
			c++;
		}
		if(c!=0){output.pb({i,c});}
	}
	if(num!=1){
		output.pb({num,1});
	}
	return output;
}
int main()
{
    IOS;
    int t;
    cin>>t;
    while(t--){
	int a,b,k;
	cin>>a>>b>>k;
	if(k==1){
		if(a==1&&b==1){
			cout<<"NO"<<endl;
			continue;
		}
		if(a==b){
			cout<<"NO"<<endl;
			continue;
		}
		if(a%b==0||b%a==0){
			cout<<"YES"<<endl;
			continue;
		}
		else{
			cout<<"NO"<<endl;
		}
		continue;
	}
	vector<pi> ans=prime_factor(a);
	ll total=0;
	for(auto it:ans){
		total+=it.second;
	}
	vector<pi> ans1=prime_factor(b);
	for(auto it:ans1){
		total+=it.second;
	}
	if(k<=total){
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
	}


    }
    return 0;
}
