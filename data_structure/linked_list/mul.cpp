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
void print(Node* head){
	Node* temp=head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}
Node* multiplydigit(Node* head,int digit){
	Node* curr=head;
	Node* newhead=NULL;
	Node* newtail=NULL;
	int carry=0;
	while(curr!=NULL){
		int ans=((curr->data*digit)+carry)%10;
		carry=(curr->data*digit)/10;
		Node* newnode=new Node(ans);
		if(newhead==NULL){
			newhead=newnode;
			newtail=newnode;
		}else{
			newtail->next=newnode;
			newtail=newnode;
		}
		curr=curr->next;
	}
	if(carry!=0){
		newtail->next=new Node(carry);
	}
	return newhead;
}
void addtwo(Node* head,Node*prod){
	int carry=0;
	Node* temp=head;
	while(prod!=NULL){
	int ans=head==NULL?(prod->data+carry)%10:(prod->data+head->data+carry)%10;
	carry=head==NULL?(prod->data+carry)/10:(prod->data+head->data+carry)/10;
	if(head==NULL){
	Node* newnode=new Node(ans);
	temp->next=newnode;
	}else{
	head->data=ans;
	}
	prod=prod->next;
	temp->next==NULL?temp:temp=temp->next;
	head==NULL?head:head=head->next;
	}
}
Node* multiply(Node* head1,Node* head2){
	
	Node *temp2=head2;
	Node *prod=multiplydigit(head1,temp2->data);
	Node *l1=prod->next;
	Node* prod2=NULL;
	temp2=temp2->next;
	while(temp2!=NULL){
		prod2=multiplydigit(head1,temp2->data);
		addtwo(l1,prod2);
		l1=l1->next;
		temp2=temp2->next;
	}
	return reverse(prod);
}
int main()
{
    //IOS;
    int n;cin>>n;
    Node* head1=takeinput(n);
	int m;cin>>m;
	Node* head2=takeinput(m);
	head1=reverse(head1);
	head2=reverse(head2);
	Node *head=multiply(head1,head2);
    print(head);
    delete head;
    delete head1;
    delete head2;
    return 0;
}
