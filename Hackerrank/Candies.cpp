#include <bits/stdc++.h>

using namespace std;

// Complete the candies function below.
long candies(int n, vector<int> arr) {
int a[n];
for(int i=0;i<n;i++){
    a[i]=1;
}
for(int i=1;i<n;i++){
    if(arr[i]>arr[i-1]){
        a[i]=a[i-1]+1;
    }
    //cout<<a[i]<<' ';
}
//cout<<endl;
for(int i=n-2;i>=0;i--){
    if(arr[i]>arr[i+1]){
        a[i] = max(a[i],a[i+1]+1);
    }
}
long int sum = 0;
for(int i=0;i<n;i++){
    //cout<<a[i]<<' ';
    sum+=a[i];
}
return sum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item;
        cin >> arr_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        arr[i] = arr_item;
    }

    long result = candies(n, arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
