#include <iostream>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int a[n],mx[n];
	    for(int i=0;i<n;i++){cin>>a[i];
	        mx[i]=a[i];
	    }
	    
	    int mxm=-1;
	    for(int i=0;i<n;i++){
	        for(int j=0;j<i;j++){
	            if(a[i]>a[j] && mx[i]<mx[j]+a[i]){
	                mx[i] = mx[j]+a[i];   
	            }
	        }
	        //cout<<mx[i]<<' ';
	        mxm = max(mxm,mx[i]);
	    }
	    cout<<mxm<<endl;
	}
	return 0;
}