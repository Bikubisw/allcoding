#include <iostream>
#include<climits>
typedef long long int ll;
using namespace std;
int findMaxSquareWithAllZeros(int** arr, int row, int col){
	  int dp[row][col];
    int maximum=INT_MIN;
    for(int i=0;i<col;i++){
        dp[0][i]=arr[0][i]==0?1:0;
        maximum=max(dp[0][i],maximum);
    }
    for(int j=1;j<row;j++){
        dp[j][0]=arr[j][0]==0?1:0;
     maximum=max(dp[j][0],maximum);

    }
    
    for(int i=1;i<row;i++){
        for(int j=1;j<col;j++){
            if(arr[i][j]!=1){
                dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
            }else{
                dp[i][j]=0;
            }
            maximum=max(dp[i][j],maximum);
        }
    }
    return maximum;
    
}

int main()
{
	int **arr, n, m, i, j;
	cin >> n >> m;
	arr = new int *[n];
	
	for (i = 0; i < n; i++)
	{
		arr[i] = new int[m];
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}

	ll ans=findMaxSquareWithAllZeros(arr, n, m);
	ans=(ans*ans);
	cout<<ans<<endl;

	delete[] arr;

	return 0;
}
