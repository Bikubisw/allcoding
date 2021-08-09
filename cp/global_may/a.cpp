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
#define endl '\n'
typedef long long int ll;
typedef unsigned long long int ull;
#define MOD 1000000007
#define PINF LLONG_MAX
#define NINF LLONG_MIN
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
int main()
{
    IOS;
    int t;
    cin>>t;
    while(t--){
    	int n,x;
    	cin>>n>>x;
    	vector<int>arr(n);
    	int fsum=0;
    	for(int i=0;i<n;i++){
    		cin>>arr[i];
    		fsum+=arr[i];
    	}
    	if(fsum<x){
    		cout<<"YES"<<endl;
    		for(int i=0;i<n;i++){
    			cout<<arr[i]<<" ";
    		}
    		cout<<endl;
    		continue;
    	}
    	int sum=0;
    	vector<int> index;
    	bool flag=false;

    	for(int i=0;i<n;i++){
    		sum+=arr[i];
    		index.push_back(arr[i]);
    		if(sum==x){
    			sum-=arr[i];
    			index.pop_back();
    		}
    		if(sum>x){
    			flag=true;
    			break;
    		}
    	}
    	if(!flag){
    		cout<<"NO"<<endl;
    	}else{
    		cout<<"YES"<<endl;

    	for(int i=0;i<n;i++){
    		auto it=find(index.begin(),index.end(),arr[i]);
    		if(it==index.end()){
    			index.push_back(arr[i]);
    		}
    	}
    	for(int i=0;i<index.size();i++){
    		cout<<index[i]<<" ";
    	}
    	cout<<endl;	
    	}



    }
    return 0;
}