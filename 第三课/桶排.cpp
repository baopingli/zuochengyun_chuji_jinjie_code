/**
�����ڱȽϵ�����
�����ض�������״����������Ҫ��������״������ֵ���ã����������class�Ͳ��÷����ˡ�
����ʹ�ö������ȶ��ģ�ʹ��ջ�ǲ��ȶ��ġ�
��������Ͱ��ʱ�临�Ӷ�N���ռ临�Ӷ�N

�������������в��������ݣ�ֻ��¼���ֵ�һ����������
�����������õķ�Χ���㡣

�⣺һ�����������������������֮���ֵ�����ֵ��

��Ͱ��

Ȼ��ͳ�Ƶ�ʱ��ֻͳ��ÿ��Ͱ�����ֵ����Сֵ��ֻ��עͰ��Ͱ֮��ģ���һ���ǿ�Ͱ����Сֵ��ȥ
ǰһ���ǿ�Ͱ��

*/




#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;
class Solution{
    public:
    int bucketsort(vector<int>&nums)//ֻ������Ͱ�ĸ���û����������Ͱ����
    {
        //����
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
        //����n+1��Ͱ
        vector<bool> hasnum(len+1,false);
        vector<int> mins(len+1,INT_MAX);
        vector<int> maxs(len+1,INT_MIN);
        //��Ͱ�������
        for(int i=0;i<nums.size();i++)
        {
            int index=bucket(nums[i],len,maxnum,minnum);
            //����ֵ�űȽ�
            mins[index]=hasnum[index]?min(mins[index],nums[i]):nums[i];
            maxs[index]=hasnum[index]?max(maxs[index],nums[i]):nums[i];
            hasnum[index]=true;
        }
        //Ȼ�������
        int res=0;
        int lastmax=maxs[0];//��һ��Ͱ�϶�����
        int i=1;
        for(;i<=len;i++)//��ʵ����Ǻ��ĵ㡣
        {
            if(hasnum[i])//��Ͱ�ǿյ�ʱ�����
            {
                res=max(mins[i]-lastmax,res);
                lastmax=maxs[i];
            }
        }
        return res;

    }
    //����Ͱ�ĺ�
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
