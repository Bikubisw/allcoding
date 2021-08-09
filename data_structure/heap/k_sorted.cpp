#include<iostream>
#include<queue>
using namespace std;
void K_sorted_array(int *input,int n,int k){
	priority_queue<int,vector<int>,greater<int>> pq;
	for(int i=0;i<=k;i++){
		pq.push(input[i]);
	}
	int j=0;
	for(int i=k+1;i<n;i++){
		input[j]=pq.top();
		pq.pop();
		pq.push(input[i]);
		j++;
	}
	while(!pq.empty()){
		input[j]=pq.top();
		pq.pop();
		j++;
	}
}
int main(){
	int size;
	cin>>size;
	int* input=new int[size+1];
	for(int i=0;i<size;i++){
		cin>>input[i];                            
	}
	int k;
	cin>>k;
	K_sorted_array(input,size,k);
	for(int i=0;i<size;i++){
		cout<<input[i]<<endl;
	}
	delete[] input;
	return 0;
}