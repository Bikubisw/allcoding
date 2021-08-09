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

void printKnightsTour(vector<vector<int>>&chess,int i,int j,int r,int c,int total,int upcomingMove){
	if(i<0||j<0||i>=r||j>=c||chess[i][j]==1){
		return;
	}
	if(upcomingMove==total){
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				cout<<chess[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
	}
		chess[i][j]=1;
	 	printKnightsTour(chess, i - 2, j + 1,r,c,total, upcomingMove + 1);
        printKnightsTour(chess, i - 1, j + 2 ,r,c,total,upcomingMove + 1);
        printKnightsTour(chess, i + 1, j + 2 , r,c,total,upcomingMove + 1);
        printKnightsTour(chess, i + 2, j + 1 , r,c,total,upcomingMove + 1);
         printKnightsTour(chess, i + 2, j - 1 ,r,c,total, upcomingMove + 1);
        printKnightsTour(chess, i + 1, j - 2 ,r,c,total, upcomingMove + 1);
        printKnightsTour(chess, i- 1, j - 2 ,r,c,total, upcomingMove + 1);
        printKnightsTour(chess, i - 2, j - 1 , r,c,total,upcomingMove + 1);
        chess[i][j]=0;
}
int main()
{
    IOS;
 	int r,c,n;
 	cin>>r;
 	cin>>c;
 	cin>>n;
 	vector<vector<int>>board(r,vector<int>(c)); 
 	for(int i=0;i<r;i++){
 		for(int j=0;j<c;j++){
 			printKnightsTour(board,i,j,r,c,n,0);
 		}
 	}




    return 0;
}