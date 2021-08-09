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
Node *middle(Node* head){
	Node* slow=head;
	Node* fast=head;
	if(head!=NULL)fast=head->next;
	while(fast!=NULL&&fast->next!=NULL){
		slow=slow->next;
		fast=fast->next->next;
	}
	return slow;
}
Node *reverse(Node* head){
	Node* curr=head;
	Node *prev=NULL;
	Node* nextp=NULL;
	while(curr!=NULL){
		nextp=curr->next;
		curr->next=prev;
		prev=curr;
		curr=nextp;
	} 
	return prev;
	
}
int main()
{
    IOS;
    int n;cin>>n;
    if(n==0)return 0;
    Node* head=takeinput(n);
	Node* newhead=head->next;
	Node* p1=head;
	Node* p2=newhead;
	while(p2!=NULL&&p2->next!=NULL){
		p1->next=p1->next->next;
		p2->next=p2->next->next;
		p1=p1->next;
		p2=p2->next;
	}
	newhead=reverse(newhead);
	p1->next=newhead;
	print(head);
    delete head;
    return 0;
}
