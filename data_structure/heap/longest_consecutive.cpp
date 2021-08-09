#include<iostream>
#include<vector>
#include <unordered_map>
#include <iterator>
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
    //IOS;
 	int n;
 	cin>>n;
 	vector<int> arr(n);
 	unordered_map<int,bool> mymap;
 	unordered_map<int,int> index;
 	for(int i=0;i<n;i++){
 		cin>>arr[i];
 		mymap[arr[i]]=true;
 		index[arr[i]]=i;
 	}
 	int maximumlength=1;
 	int globalminstartindex=0;
 	for(int i=0;i<n;i++){
 		int num=arr[i];
 		int currentindex=i;
 		int tempnum=num;
 		int count=0;
 		while(mymap[tempnum]==true&&mymap.count(tempnum)==1){
 			mymap[tempnum]=false;
 			count++;
 			tempnum++;
 		}
 		tempnum=num-1;
 		while(mymap[tempnum]==true&&mymap.count(tempnum)==1){
 			count++;
 			mymap[tempnum]=false;
 			currentindex=index[tempnum];
 			tempnum--;
 		}
 		if(count>maximumlength){
 			maximumlength=count;
 			globalminstartindex=currentindex;
 		}
 		else if(count==maximumlength){
 			if(currentindex<globalminstartindex){
 				globalminstartindex=currentindex;
 			}
 		}
 	}
 	vector<int> ans;
 	int globalnum=arr[globalminstartindex];
 	ans.push_back(globalnum);
 	globalnum++;
 	maximumlength--;
 	while(maximumlength!=0){
 		ans.push_back(globalnum);
 		globalnum++;
 		maximumlength--;
 	}
 	for(auto &it:ans){cout<<it<<endl;}
    return 0;
}