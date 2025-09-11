#include<bits/stdc++.h>
using namespace std;

// Q- Given an array arr[] of integers, where each element arr[i] represents the number of pages in the i-th book. You also have an integer k representing the number of students. The task is to allocate books to each student such that:

// Each student receives atleast one book.
// Each student is assigned a contiguous sequence of books.
// No book is assigned to more than one student.
// The objective is to minimize the maximum number of pages assigned to any student. In other words, out of all possible allocations, find the arrangement where the student who receives the most pages still has the smallest possible maximum.

int possible(vector<int> nums, int pages, int students) {
    int n = nums.size();
    // allocating book to the first stud
    int permicible = nums[0];
    students--;   
    for (int i = 1; i < n; i++) {
        // checking id if i can load one more book to same stud
        if (permicible + nums[i] <= pages) {
            permicible += nums[i];
        } else {
            // if not possible move to next student load the book
            students--;       
            permicible = nums[i];
            // check on each node whether the students become negative
            if (students < 0)   
                return 0;
        }
    }
    // if not return 1
    return 1;   
}



int bs_bookallocation(vector<int>nums,int students){
    int low=*max_element(nums.begin(),nums.end()); // range of the bs on ans
    int high=accumulate(nums.begin(),nums.end(),0);
    int ans=high;
    while(low<=high){
        int mid=(low+high)/2;
        if(possible(nums,mid,students)==1){
            high=mid-1;
        } else {
            low=mid+1;
        }
    }
    // ans at low as the polarity gets changed
    return low;
}

int main(){
    int n,s;
    cin>>n>>s;
    vector<int>nums(n);
    int sum=0;
    for(int i=0; i<n; i++){
        cin>>nums[i];
        sum+=nums[i];
    }

    // Solution 1 :-
    // TC O((sum-max+1)*n)
    // SC O(1)
    // int low=*max_element(nums.begin(),nums.end());

    // for(int i=low; i<=sum; i++){
    //     if(possible(nums,i,s)==1){
    //         cout<<i<<endl;
    //         break;
    //     } 
    // }

    // solution 2:-
    // TC O(log(sum-max+1)*n)
    cout<<bs_bookallocation(nums,s)<<endl;


}