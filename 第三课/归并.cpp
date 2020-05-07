#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        //在归并排序的过程中统计逆序对,降序对
        int res=0;
        mergesort(nums,res,0,nums.size()-1);
        return res;
    }
    void mergesort(vector<int>& nums,int& res,int left,int right)
    {
        if(left==right)
            return;
        int mid=left+(right-left)/2;
        //int mid=(left+right)/2;
        mergesort(nums,res,left,mid);
        mergesort(nums,res,mid+1,right);
        merge(nums,res,left,mid,right);
    }
    void merge(vector<int>& nums, int& res,int left,int mid,int right)
    {
        if(left==right)
            return;
        int l1=left;
        int l2=mid+1;
        vector<int> temp(right-left+1,0);
        int i=0;
        while(l1<=mid&&l2<=right)
        {
            //在这里统计降序对
            if(nums[l2]<nums[l1])
            {
                res+=mid-l1+1;
                temp[i++]=nums[l2++];

            }
            else if(nums[l2]>=nums[l1])
                temp[i++]=nums[l1++];
        }
        while(l1<=mid)
        {
            temp[i++]=nums[l1++];
        }
        while(l2<=right)
        {
            temp[i++]=nums[l2++];
        }
        for(i=0;i<right-left+1;i++)
        {
            nums[left+i]=temp[i];
        }
    }

};

int main()
{

    Solution s;
    vector<int> num={1,3,2,3,1};
    int res=s.reversePairs(num);

    cout<<res<<endl;
    for(auto x:num)
    {
        cout<<x<<" ";
    }
    cout<<endl;
    //cout<<"hello"<<endl;
    return 0;
}
