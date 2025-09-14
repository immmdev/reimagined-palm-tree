#include<bits/stdc++.h>
using namespace std;



int main(){
    int n,k;
    cin>>n>>k;
    vector<int>nums(n);
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }

    // array to mark how many placed
    vector<int>howmany(n-1,0); 
    // going through every k
    for(int i=1; i<=k; i++){
        long double maxsecLength=-1;
        long double maxind=-1;
        // finding max section to place the gas station 
        for(int i=0; i<n-1; i++){
            long double diff=nums[i+1]-nums[i];
            long double secLength=diff/(long double)(howmany[i]+1);
            if(secLength>maxsecLength){
                maxsecLength=secLength;
                maxind=i;
            }

        }
        // placing gas station
         howmany[maxind]++;
    }

    long double maxAns=-1;
    for(int i=0; i<n-1; i++){
        long double diff=nums[i+1]-nums[i];
        long double secLength=diff/(long double)(howmany[i]+1);
        maxAns=max(maxAns,secLength);
    }
    // return maxAns;
    cout<<maxAns<<endl;
}