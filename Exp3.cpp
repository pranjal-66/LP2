/*
Name: Pranjal Govardhan Karande
Roll no: 35
Exp3:-  Implement Greedy search algorithm for any of the following application:
	I. Selection Sort
	II. Minimum Spanning Tree
	III. Single-Source Shortest Path Problem
	IV. Job Scheduling Problem
	V. Prim's Minimal Spanning Tree Algorithm
	VI. Kruskal's Minimal Spanning Tree Algorithm
	VII. Dijkstra's Minimal Spanning Tree Algorithm
*/
#include<iostream>
using namespace std;
void selecionSort(int arr[], int n) {
	for(int i=0; i<n-1; i++)
	{
		int min = 1;
		for(int j=i+1; j<n; j++)
		{
			if(arr[j]<arr[min])
			{
				min = j;
			}
		}
		//swap
		int temp = arr[i];
		arr[i]=arr[min];
		arr[min]=temp;
	}
}
int main(){
	int arr[] = {64,25,12,22,11};
	/*
	    int n;
	    cout << "Enter number of elements: ";
	    cin >> n;
	    int arr[n];
	    cout << "Enter elements:\n";
	    for(int i = 0; i < n; i++) {
		cin >> arr[i];
	    }
	*/
	int n = sizeof(arr)/sizeof(arr[0]);
	selecionSort(arr, n);
	cout<<"Sorted array: ";
	for(int i=0;i<n;i++) {
		cout<<arr[i]<<" ";
	}
	return 0;
}

