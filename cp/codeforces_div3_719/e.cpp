#include<iostream>
#include<vector>
#include<map>
#include<climits>
#include<cfloat>
#include<unordered_set>
#include <unordered_map>
#include<string>
#include <cstring>
#include<stack>
#include<queue>
#include <cmath>
#include <algorithm>
#include <iterator>
#include <cstdlib>
#include<cassert>
#include<utility>
#include<unordered_set>
#include<set>
#include<cmath>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int,pair<int,int>> ppi;
typedef pair<int,int> pi;
#define MOD 1000000007
#define PINF LLONG_MAX
#define NINF LLONG_MIN
#define endl "\n"
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
{
    IOS;
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int> ans;
    for(int i=0;i<s.length();i++){
    	if(s[i]=='*')ans.push_back(i);
    }
    if(ans.size()==0){
    	cout<<0<<endl;
    	continue;
    }
    int mid=ans.size()/2;
    ll cnt=0;
    int temp=1;
    for(int i=0;i<mid;i++){
    	cnt+=ans[mid]-ans[i]-temp;
    	temp++;
    }
    temp=1;
    for(int i=mid+1;i<ans.size();i++){
    	cnt+=ans[i]-ans[mid]-temp;
    	temp++;
    }
    cout<<cnt<<endl;




    }
    return 0;
}