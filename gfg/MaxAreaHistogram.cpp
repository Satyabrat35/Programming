// Max rectangle area in a histogram - watch the video
int maxrec(int a[],int n){
    stack<int>s;
    int i=0,cur,area,max=INT_MIN;
    while(i<=n){
           if(i==n){
              while(!s.empty()){
              cur=s.top();s.pop();
           if(s.empty())
              {area=a[cur]*i;
                  if(area>max) max=area;}
            else {
                area=a[cur]*(i-s.top()-1);
                  if(area>max) max=area;}
          }
           }
       else{ if(s.empty()||a[i]>=a[s.top()])
            s.push(i);
            else{  
                while(!s.empty()&&(a[s.top()]>=a[i])){
                cur=s.top();s.pop();
                if(s.empty())
                    {area=a[cur]*i;
                  if(area>max) max=area;}
                  else {
                    area=a[cur]*(i-s.top()-1);
                    if(area>max) max=area;}
          }   
          s.push(i);
       }
    }
i++;
}
    return max;
}
int maxArea(int M[MAX][MAX],int n,int m)
{
    int c,a[m]={},max=INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
             if(M[i][j]==1)
              a[j]+=M[i][j];
             else  a[j]=0;
        }
        c=maxrec(a,m);
        if(c>max)max=c;
    }return max;
}
