/**
不基于比较的排序
基于特定的数据状况的排序，需要分析数据状况，数值还好，但是如果是class就不好分析了。
容器使用队列是稳定的，使用栈是不稳定的。
容器叫做桶，时间复杂度N，空间复杂度N

计数排序，容器中不放入数据，只记录出现的一个次数就行
基数排序，适用的范围更广。

题：一组数，无序，找有序后，两个数之间差值的最大值。

用桶排

然后统计的时候只统计每个桶的最大值和最小值，只关注桶与桶之间的，后一个非空桶的最小值减去
前一个非空桶的

*/




#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;
class Solution{
    public:
    int bucketsort(vector<int>&nums)//只利用了桶的概念没有真正进行桶排序
    {
        //首先
        int len=nums.size();
        int maxnum=INT_MIN;
        int minnum=INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            maxnum=max(maxnum,nums[i]);
            minnum=min(minnum,nums[i]);
        }
        if(maxnum==minnum)
            return 0;
        //构建n+1个桶
        vector<bool> hasnum(len+1,false);
        vector<int> mins(len+1,INT_MAX);
        vector<int> maxs(len+1,INT_MIN);
        //往桶里面放数
        for(int i=0;i<nums.size();i++)
        {
            int index=bucket(nums[i],len,maxnum,minnum);
            //有数值才比较
            mins[index]=hasnum[index]?min(mins[index],nums[i]):nums[i];
            maxs[index]=hasnum[index]?max(maxs[index],nums[i]):nums[i];
            hasnum[index]=true;
        }
        //然后计算结果
        int res=0;
        int lastmax=maxs[0];//第一个桶肯定有数
        int i=1;
        for(;i<=len;i++)//其实这个是核心点。
        {
            if(hasnum[i])//当桶非空的时候才行
            {
                res=max(mins[i]-lastmax,res);
                lastmax=maxs[i];
            }
        }
        return res;

    }
    //返回桶的号
    int bucket(int x,int len,int maxnum,int minnum)
    {
        return (int)(x-minnum)*len/(maxnum-minnum);
    }
};
int main()
{
    vector<int> x={1,6,2,4,8,10,34,26};

    for(auto xx:x)
    {
        cout<<xx<<" ";
    }
    cout<<endl;

    Solution s;
    int res=s.bucketsort(x);
    cout<<res<<endl;
    cout<<"nice"<<endl;
    return 0;
}
