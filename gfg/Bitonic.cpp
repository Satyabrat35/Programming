#include <iostream>
#include <list>
using namespace std;

// Function to find Longest Bitonic Subsequence in an array
void LBS(int arr[], int n)
{
	// I[i] stores the longest increasing subsequence ending with arr[i]
	list<int> I[n+1];
	I[0].push_back(arr[0]);

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			if (I[i].size() < I[j].size() && arr[i] > arr[j])
				I[i] = I[j];
		}
		I[i].push_back(arr[i]);
	}

	// D[i] stores the longest decreasing subsequence starting from arr[i]
	list<int> D[n+1];
	D[n].push_front(arr[n]);

	for (int i = n - 1; i >= 0; i--) {
		for (int j = n; j > i; j--) {
			if (D[i].size() < D[j].size() && arr[i] > arr[j] )
				D[i] = D[j];
		}
		D[i].push_front(arr[i]);
	}

	// Uncomment below lines to print contents of vector LIS & LDS
	/* for (int i = 0; i <= n; i++)
	{
		cout << "LIS[" << i << "] - ";
		for (int j : I[i])
			cout << j << " ";

		cout << "\t\tLDS[" << i << "] - ";
		for (int j : D[i])
			cout << j << " ";
		cout << endl;
	} */

	// find peak element index
	int peak = 0;
	for (int i = 1; i <= n; i++)
		if ((I[i].size() + D[i].size()) > (I[peak].size() + D[peak].size()))
			peak = i;

	cout << "Longest Bitonic Subsequence is \n";

	// print longest increasing subsequence ending at peak element
	for (int i: I[peak])
		cout << i << " ";

	// pop front element of LDS as it points to same element as rear of LIS
	D[peak].pop_front();

	// print longest decreasing subsequence starting from peak element
	for (int i: D[peak])
		cout << i << " ";
}

// main function
int main()
{
	int arr[] = { 4, 2, 5, 9, 7, 6, 10, 3, 1 };
	int n = sizeof(arr) / sizeof(arr[0]);

	LBS(arr, n-1);

	return 0;
}