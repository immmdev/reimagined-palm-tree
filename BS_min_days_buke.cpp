#include<bits/stdc++.h>
using namespace std;

int possible(vector<int>flower,int d,int b,int bundle){
    int cnt=0;
    int buquet=0;
    int n=flower.size();
    for(int i=0; i<n; i++){
        if(flower[i]<=d){
            cnt++;
        } else{
            buquet+=cnt/bundle;
            cnt=0;
        }
        if(i==(n-1)){
            buquet+=cnt/bundle;
        }
    }

    if(b<=buquet){
        return 1;
    } else {
        return 0;
    }
}

int bs_day(vector<int>a,int b,int bundle){
    int min_el=*min_element(a.begin(),a.end());
    int max_el=*max_element(a.begin(),a.end());
    int low=min_el;
    int high=max_el;
    int ans=high;
    while(low<=high){
        int mid=(high+low)/2;
        if(possible(a,mid,b,bundle)==1){
            ans=mid;
            high=mid-1;
        } else {
            low=mid+1;
        }
    }
    return ans;
}
// time complexity o(n*log(max-min+1))
// space complexity o(1);
int main(){
    int n;
    cin>>n;
    vector<int>f(n);
    for(int i=0; i<n; i++){
        cin>>f[i];
    }
    int totbuquet,totflower;
    cin>>totbuquet>>totflower;

    if(totbuquet*totflower>n){
        cout<<-1<<endl;
        return -1;
    }

    cout<<bs_day(f,totbuquet,totflower)<<endl;
}