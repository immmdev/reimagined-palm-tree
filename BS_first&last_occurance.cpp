#include<bits/stdc++.h>
using namespace std;

int lb(int nums[], int n, int x){
    int low=0;
    int high=n-1;

    // initializing lb as largest index of array
    int lb=n;

    while(low<=high){

        // preventing int overflow
        int mid=low+(high-low)/2;

        // moving high left
        if(nums[mid]>=x){

            // updating with min value
            lb=mid;

            // look for small index at left
            high=mid-1;
        }

        // else only moving low no update if x is greater
        else{
            low=mid+1;
        }

    }

    return lb;
}

// upper bound smallest inx such that arr[i]>x
int ub(int nums[], int n, int x){
    int low=0;
    int high=n-1;

    // initializing lb as largest index of array
    int ub=n;

    while(low<=high){

        // preventing int overflow
        int mid=low+(high-low)/2;

        // moving high left
        if(nums[mid]>x){

            // updating with min value
            ub=mid;

            // look for small index at left
            high=mid-1;
        }

        // else only moving low no update if x is greater
        else{
            low=mid+1;
        }

    }

    return ub;
}

int main(){
    int n;
    cin >> n;

    int nums[n];

    for(int i=0; i<n; i++){
        cin >> nums[i];
    }

    int x;
    cin >> x;
    cout << x;

    pair<int,int> ans;

    int lb_1=lb(nums,n,x);
    int ub_1=ub(nums,n,x);

    
    if(lb_1==n || nums[lb_1]!=x) {
        ans.first=-1;
        ans.second=-1;

        cout << ans.first << "," << ans.second;
        
    }

    else{
        ans.first=lb_1;
        ans.second=ub_1-1;

        cout << ans.first << "," << ans.second;
        
    }
    

}

// tc-> 2log(base2)n
// sc-> o(1)

