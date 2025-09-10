#include<bits/stdc++.h>
using namespace std;
// Tc=n
int sqrt_brute(int n){

    if(n==0) return 0;
    for(int i=1; i<=n; i++){
        int test=i*i;
        if(test==n) return i;

        else if(test>n) return i-1;
    }
    return -1;
}


// TC=log2n
int sqrt_optimal(int n){
    int low=0; 
    int high=n;
    int ans=-1;

    if(n==0) return 0;

    while(low<=high){
        int mid=(low+high)/2;
        if(mid*mid<=n){
            ans=mid;
            low=mid+1;

        }
        else{
            high=mid-1;
        }
    }

    return ans;
}

int main(){
    int n;
    cin >> n;

    // cout << sqrt_brute(n);
    cout << sqrt_optimal(n);
    
}