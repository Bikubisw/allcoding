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
    char arr[3][3];
    int countx=0;
    int counto=0;
    int countspace=0;
    for(int i=0;i<3;i++){
    	for(int j=0;j<3;j++){
    		cin>>arr[i][j];
    		if(arr[i][j]=='X'){countx++;}
    		else if(arr[i][j]=='O'){counto++;}
    		else {countspace++;}
    	}
    }
    int wx=0;
    int wo=0;
   	if(arr[0][0]=='X' && arr[0][1]=='X'&&arr[0][2]=='X')wx=1;
   	if(arr[1][0]=='X' && arr[1][1]=='X'&&arr[1][2]=='X')wx=1;
   	if(arr[2][0]=='X' && arr[2][1]=='X'&&arr[2][2]=='X')wx=1;

    if(arr[0][0]=='X' && arr[1][0]=='X'&&arr[2][0]=='X')wx=1;
    if(arr[0][1]=='X'&&arr[1][1]=='X'&&arr[2][1]=='X')wx=1;
    if(arr[0][2]=='X'&&arr[1][2]=='X'&&arr[2][2]=='X')wx=1;
    if(arr[0][0]=='X'&&arr[1][1]=='X'&&arr[2][2]=='X')wx=1;
    if(arr[0][2]=='X'&&arr[1][1]=='X'&&arr[2][0]=='X')wx=1;

   	if(arr[0][0]=='O' && arr[0][1]=='O'&&arr[0][2]=='O')wo=1;
   	if(arr[1][0]=='O' && arr[1][1]=='O'&&arr[1][2]=='O')wo=1;
   	if(arr[2][0]=='O' && arr[2][1]=='O'&&arr[2][2]=='O')wo=1;
    if(arr[0][0]=='O'&&arr[1][0]=='O'&&arr[2][0]=='O')wo=1;
    if(arr[0][1]=='O'&&arr[1][1]=='O'&&arr[2][1]=='O')wo=1;
    if(arr[0][2]=='O'&&arr[1][2]=='O'&&arr[2][2]=='O')wo=1;
    if(arr[0][0]=='O'&&arr[1][1]=='O'&&arr[2][2]=='O')wo=1;
    if(arr[0][2]=='O'&&arr[1][1]=='O'&&arr[2][0]=='O')wo=1;

    if((wo==1&&wx==1)||(counto>countx)||(countx-counto)>1)cout<<3<<endl;
    else if(countx==0&&counto==0&&countspace==9)cout<<2<<endl;
    else if(wx==1&&wo==0&&(countx>counto))cout<<1<<endl;
    else if(wx==0&&wo==1&&(countx==counto))cout<<1<<endl;
    else if(wx==0&&wo==0&&countspace==0)cout<<1<<endl;
    else if(wx==0&&wo==0&&countspace>0)cout<<2<<endl;
    else cout<<3<<endl;
    }
    return 0;
}