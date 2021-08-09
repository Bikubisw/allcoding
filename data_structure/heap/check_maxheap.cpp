#include <iostream>
using namespace std;
bool isMaxHeap(int *&arr, int n){
	int parenindex=0;
	int leftchild=2*parenindex+1;
	int rightchild=2*parenindex+2;
	while(leftchild<n){
		if(arr[parenindex]<arr[leftchild]||arr[parenindex]<arr[rightchild]){
			return false;
		}
		parenindex++;
		leftchild=2*parenindex+1;
		rightchild=2*parenindex+2;
	}
	return true;

}

int main() {
    int n;
    cin >> n;
    int *arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << (isMaxHeap(arr, n) ? "true\n" : "false\n");

    delete[] arr;
}