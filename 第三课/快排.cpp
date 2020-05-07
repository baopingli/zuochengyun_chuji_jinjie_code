#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution{
    public:
    //������ȵ�������߽���ұ߽�
    //���������������ԭ����partition��̫һ��
    vector<int> partition_my(vector<int>& nums,int left,int right)
    {
        //���������߽�
        int xiaoyu=left-1;
        int dayu=right;
        while(left<dayu) //��index���ұ߽��ʱ��ֹͣ
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
        //�������һ��pȻ���rightԪ�ؽ���
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
�����������⣺һ����������ż��ʵ����O(1)�Ŀռ临�Ӷ��£���������ż�����λ�ö�����������
ʹ����������ߣ�ż�����ұߡ����������ڿ������ �ȶ���ʵ���������ǲ���ʵ�ֵģ���Ϊ�漰��һƪ
����0 1 stable sort�����⡣

�Ƚ������Զ���ıȽϺ���
���ظ�����һ����������ǰ�棬���������ڶ�����������ǰ�档ʲô�������С�
�Ƚ������������������ṹ��

��������N*logN�ĸ��Ӷȵ����ڹ������õıȽ϶࣬��Ϊ�������٣����ų�����Ͷ��ˡ�
��N�Ƚ�С��ʱ��ʹ�ò���������Ϊ�������٣����������ơ�������60��ʱ�򣬵������ʱ���ǻ������͵�ʱ��
�ۺ�����ʹ��qucicksort�����������һ��class��ʱ���ۺ�����ʹ�õ���mergesort��Ϊʲô����Ϊ�ȶ��ԡ�
������������Ҫ���ȶ��ԣ�mergesort����Ļ������ȶ��ԡ���������  ���� + ���� ���Ȱ��������ˣ�Ȼ��
�ٹ����ţ���ôÿ������������Ҳ�Ǵ���С����Ĵ��������Ǻܺõġ����Ա������˳��
*/
