#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution{
    public:
    //返回相等的数的左边界和右边界
    //荷兰国旗问题和我原来的partition不太一样
    vector<int> partition_my(vector<int>& nums,int left,int right)
    {
        //构造两个边界
        int xiaoyu=left-1;
        int dayu=right;
        while(left<dayu) //当index到右边界的时候停止
        {
            if(nums[left]<nums[right])
            {
                //swap(nums[++xiaoyu],nums[left++]);
                swap_my(nums,++xiaoyu,left++);
            }
            else if(nums[left]>nums[right])
            {
                //swap(nums[--dayu],nums[left]);
                swap_my(nums,--dayu,left);
            }
            else
            {
                left++;
            }
        }
        //swap(nums[dayu],nums[right]);
        swap_my(nums,dayu,right);
        return {xiaoyu+1,dayu};
    }
    void fastsort(vector<int>& nums,int left,int right)
    {
        if(left<right)
        {
        //随机产生一个p然后和right元素交换
        int p=left+rand()%(right-left+1);
        //swap(nums[p],nums[right]);
        swap_my(nums,p,right);
        vector<int> xx=partition_my(nums,left,right);
        fastsort(nums,left,xx[0]-1);
        fastsort(nums,xx[1]+1,right);
        }
    }
    void swap_my(vector<int>& nums,int index1,int index2)
    {
        int temp=nums[index1];
        nums[index1]=nums[index2];
        nums[index2]=temp;
    }

};


int main()
{
    vector<int> x={3,8,5,0,2,1,6,7};
    Solution s;
    /*
    vector<int> res=s.partition_my(x,0,x.size()-1);
    for(auto xx:x)
    {
        cout<<xx<<" ";
    }
    cout<<endl;
    for(auto r:res)
    {
        cout<<r<<" ";
    }
    cout<<endl;
    */
    s.fastsort(x,0,x.size()-1);
    for(auto xx:x)
    {
        cout<<xx<<" ";
    }
    cout<<endl;

    cout<<"hello"<<endl;
    return 0;
}

/**
如果遇到这个题：一组数有奇有偶，实现在O(1)的空间复杂度下，保持奇数偶数相对位置都不变的情况下
使得奇数在左边，偶数在右边。这个题就是在考察快排 稳定的实现做法，是不能实现的，因为涉及到一篇
论文0 1 stable sort的问题。

比较器：自定义的比较函数
返回负数第一个参数排在前面，返回整数第二个参数排在前面。什么负数都行。
比较器用在数组或者有序结构。

快排期望N*logN的复杂度但是在工程中用的比较多，因为常数项少，堆排常数项就多了。
当N比较小的时候使用插入排序，因为常数项少，所以有优势。当大于60的时候，当排序的时候是基础类型的时候
综合排序使用qucicksort，当排序的是一个class的时候，综合排序使用的是mergesort，为什么？因为稳定性。
基础类型排序不要求稳定性，mergesort排序的话保持稳定性。比如排序  国籍 + 年龄 ，先按年龄排了，然后
再国籍排，那么每个国籍中年龄也是从下小到大的次序，这样是很好的。可以保留相对顺序。
*/
