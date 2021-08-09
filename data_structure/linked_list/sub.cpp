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
struct Node{
	int data;
	Node* next;
	Node(int d){
		data=d;
		next=NULL;
	}
	~Node(){
		delete next;
	}
};
Node* takeinput(int n){
	int data;
	Node *head=NULL;
	Node* tail=NULL;
	while(n--){
		cin>>data;
		Node* newnode=new Node(data);
		if(head==NULL){
			head=newnode;
			tail=newnode;
		}else{
			tail->next=newnode;
			tail=newnode;
		}
	}
	return head;
	
}
void print(Node* head){
	Node* temp=head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}
Node* reverse(Node* head){
	Node* next=NULL;
	Node* prev=NULL;
	Node* curr=head;
	while(curr!=NULL){
		next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
	}
	return prev;
}
int main()
{
    IOS;
    int n;
    cin>>n;
    Node* head1=takeinput(n);
    int m;
    cin>>m;
    Node* head2=takeinput(m);
	head1=reverse(head1);
	//print(head1);
	head2=reverse(head2);
	Node* temp1=head1;Node*temp2=head2;
	int borrow=0;
	while(temp1!=NULL){
		int ans=0;
		if(temp2!=NULL&&temp1->data<temp2->data){
			ans=(10+temp1->data)-(temp2->data+borrow);
			borrow=1;
		}else if(temp2!=NULL&&temp1->data>temp2->data){
			ans=temp1->data-(temp2->data+borrow);
			borrow=0;
		}
		else if(temp2!=NULL&&temp1->data==temp2->data){
			if(borrow){
			ans=(10+temp1->data)-(temp2->data+borrow);
			borrow=1;
			}else{
				ans=temp1->data-temp2->data;
			}
		}
		else if(temp2==NULL){
			ans=temp1->data-borrow;
			borrow=0;
		}
		temp1->data=ans;
		temp1==NULL?temp1:temp1=temp1->next;
		temp2==NULL?temp2:temp2=temp2->next;
	}
	head1=reverse(head1);
	if(head1->data==0){Node*temp=head1;head1=head1->next;temp->next=NULL;delete temp;}
    print(head1);
	delete head1;
	delete head2;
    return 0;
}
