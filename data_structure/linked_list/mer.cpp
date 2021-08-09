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
int main()
{
    IOS;
    int n;cin>>n;
    Node* head1=takeinput(n);
    int m;
    cin>>m;
    Node *head2=takeinput(m);
    if(head1==NULL){
        
        print(head2);
        return 0;
    }
        if(head2==NULL){
        
        print(head1);
        return 0;
    }
    Node* temp1=head1;
    Node *temp2=head2;
    Node* newhead=NULL;
    Node* newtail=NULL;
    while(temp1!=NULL&&temp2!=NULL){
		if(temp1->data<temp2->data){
			if(newhead==NULL){
			newhead=temp1;
			newtail=temp1;
			}else{
			newtail->next=temp1;
			newtail=newtail->next;
		}
		temp1=temp1->next;
		}else{
			if(newhead==NULL){
			newhead=temp2;
			newtail=temp2;
			}else{
			newtail->next=temp2;
			newtail=temp2;
			}
			temp2=temp2->next;
		}
	}
	if(temp1!=NULL){
		newtail->next=temp1;
	}
	if(temp2!=NULL){
		newtail->next=temp2;
	}
    print(newhead);
    delete newhead;
    return 0;
}
