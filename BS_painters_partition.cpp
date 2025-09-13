#include<bits/stdc++.h>
using namespace std;

int painters(vector<int>nums,int area){
    int painters=1;
    int areaPaint=0;
    for(int i=0; i<nums.size(); i++){
        if(areaPaint+nums[i]<=area){
            areaPaint+=nums[i];
        } else {
            areaPaint=nums[i];
            painters++;
        }
    }

    return painters;
}

int bs_minmax_area(vector<int>nums,int k){
    int minlimit=*max_element(nums.begin(),nums.end());
    int maxlimit=accumulate(nums.begin(),nums.end(),0);
    
    int low=minlimit;
    int high=maxlimit;

    while(low<=high){
        int mid=(low+high)/2;
        if(painters(nums,mid)>k){
           low=mid+1; 
        } else {
            high=mid-1;
        }
    }

    return low;

}


int main(){
    int n,k;
    cin>>n>>k;

    vector<int>nums(n);

    for(int i=0; i<n; i++){
        cin>>nums[i];
    }

    cout<<bs_minmax_area(nums,k)<<endl;
}