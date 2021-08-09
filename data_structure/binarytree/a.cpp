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
 	int n;
 	cin>>n;
 	vector<int>arr(n);
 	for(int i=0;i<n;i++){
 		cin>>arr[i];
 	} 
 	for(int i=0;i<n-1;i++){
 		if(i%2==0){
 			if(arr[i+1]<arr[i]){
 				int temp=arr[i+1];
 				arr[i+1]=arr[i];
 				arr[i]=temp;
 			}
 		}else{
 			if(arr[i]<arr[i+1]){
 				int temp=arr[i+1];
 				arr[i+1]=arr[i];
 				arr[i]=temp;
 			}
 		}
 	}
 	for(int i=0;i<n;i++){
 		cout<<arr[i]<<" ";
 	}




    return 0;
}