/**************erik****************/
#include<bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long  int ll;
typedef unsigned long long int ull;
map<int,int> mp1;
//set<ll> s1;
//set<char>::iterator t;
#define maxm(a,b,c)  max(a,max(c,b))
#define minm(a,b,c)  min(a,min(c,b))
#define f(i,n)  for(int i=1;i<n;i++)
#define rf(i,n) for(int i=n-1;i>=0;i--)
int N;
void max_heapify (int Arr[ ], int i, int N)
{
    int left = 2*i;                   //left child
    int right = 2*i +1;
    int largest = i;
    if(left<= N and Arr[left] > Arr[i] )
          largest = left;
    else
         largest = i;
    if(right <= N and Arr[right] > Arr[largest] )
        largest = right;
    if(largest != i )
    {
        swap (Arr[i] , Arr[largest]);
        max_heapify (Arr, largest,N);
    } 
 }
void build_maxheap (int Arr[ ])
{
    for(int i = N/2 ; i >= 1 ; i-- )
    {
        max_heapify (Arr, i,N) ;
    }
}
int main() {
	cin>>N;
	int a[N+1];
	for(int i=1;i<=N;i++)cin>>a[i];
	build_maxheap(a);
	for(int i=1;i<=N;i++)cout<<a[i]<<' ';
	return 0;
}