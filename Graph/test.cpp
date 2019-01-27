#include <bits/stdc++.h>
using namespace std;
     
int n, ans = 0;
set< vector<int> > st;
set< vector<int> >::iterator it;

int main(){
    /*vector<int> v;
    for(int i=0;i<4;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    vector <int> go;
    go = v;
    for(int i=2;i<4;i++){
        reverse(go.begin(), go.begin()+i);
        cout<<go[0]<<' '<<go[1]<<' '<<go[2]<<' '<<go[3]<<endl;
        st.insert(go);
    }
    for(it=st.begin();it!=st.end();++it ){
        std::vector<int>::const_iterator it2 = (*it).begin();
        std::vector<int>::const_iterator it2End = (*it).end();

        for (; it2 != it2End; ++it2){
            std::cout<<*it2<<' ';
        }
    }*/
    /*vector<pair<int,int>> q;
    q.push_back(make_pair(2,4));
    cout<<q[0].first;*/
    int x = 6,y =8;
    int temp = __gcd(x,y);
    cout<<temp;
    return 0;
}