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
using ll=long long int ;
using ull= unsigned long long int ;
using ppi= pair<int,pair<int,int>> ;
using pi= pair<int,int> ;
#define all(x) (x).begin(),(x).end()
#define MOD 1000000007
#define pb push_back
#define fi first
#define se second
#define INF 1e18;
#define NINF -1e18;
#define endl '\n'
#define IOS ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
bool isvalidvertical(vector<vector<char>>&board,vector<string>&input,int index,int row,int col){
	string word=input[index];
	int j=0;
	int count=0;
	for(int i=0;i<(int)word.length();i++){
		if(i+row==10)return false;
		else if(board[i+row][col]=='+')return false;
		count+=(board[i+row][col]=='-'||board[i+row][col]==word[j]);
		j++;
		}
		return count==(int)word.length();
	}
bool isvalidhorizontal(vector<vector<char>>&board,vector<string>&input,int index,int row,int col){
	string word=input[index];
	int j=0;
	int count=0;
	for(int i=0;i<(int)word.length();i++){
		if(i+col==10)return false;
		else if(board[row][i+col]=='+')return false;
		count+=(board[row][i+col]=='-'||board[row][i+col]==word[j]);
		j++;
		}
		return count==(int)word.length();
	}
void setvertical(vector<vector<char>>&board,vector<string>&input,int index,int row,int col,vector<bool>&helper){
	int j=0;
	string word=input[index];
	for(int i=0;i<(int)word.length();i++){
		if(board[i+row][col]=='-'){
		board[i+row][col]=word[j];
		helper[i]=true;
	}
	j++;
	}
	}
void sethorizontal(vector<vector<char>>&board,vector<string>&input,int index,int row,int col,vector<bool>&helper){
	int j=0;
	string word=input[index];
	for(int i=0;i<(int)word.length();i++){
		if(board[row][i+col]=='-'){
		board[row][i+col]=word[j];
		helper[i]=true;
	}
	j++;
	}
}
void resetvertical(vector<vector<char>>&board,vector<string>&input,int index,int row,int col,vector<bool>&helper){
	string word=input[index];
	for(int i=0;i<(int)word.length();i++){
		if(helper[i]){
			board[i+row][col]='-';
		}
	}
}
void resethorizontal(vector<vector<char>>&board,vector<string>&input,int index,int row,int col,vector<bool>&helper){
	string word=input[index];
	for(int i=0;i<(int)word.length();i++){
		if(helper[i]){
			board[row][i+col]='-';
		}
	}
}
void crossboard(vector<vector<char>>&board,vector<string>&input,int index){
	if(index==(int)input.size()){
		for(int i=0;i<10;i++){
			for(int j=0;j<10;j++){
				cout<<board[i][j];
			}
			cout<<endl;
		}
		return ;
	}
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			if(board[i][j]=='-'||board[i][j]==input[index][0]){
				if(isvalidvertical(board,input,index,i,j)){
				vector<bool> helper(input[index].length(),false);
				setvertical(board,input,index,i,j,helper);
				crossboard(board,input,index+1);
				resetvertical(board,input,index,i,j,helper);	
				}
				if(isvalidhorizontal(board,input,index,i,j)){
				vector<bool> helper(input[index].length(),false);
				sethorizontal(board,input,index,i,j,helper);
				crossboard(board,input,index+1);
				resethorizontal(board,input,index,i,j,helper);
					
				}
			}
		}
	}
}
int main()
{
    IOS;
    int n=10;
    vector<vector<char>>board(n,vector<char>(n));
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)cin>>board[i][j];
    int k;
    cin>>k;
    vector<string> input(k);
    for(auto &it:input)cin>>it;
    crossboard(board,input,0);
    return 0;
}
