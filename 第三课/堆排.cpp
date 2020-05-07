/**
��ȫ��������
ÿһ�㶼�Ǵ�����������������Բ�������
��ؽṹ������ṹ��
���Ӿ���2*i+1
�Һ��Ӿ���2*i+2
���ڵ�Ϊ ��i-1��/2
��ȫͨ���±�任�Ϳ����ҵ������ӽڵ�
�Ѷ������ṹ������ʵ�֡�

pipline:
1��heapInsert���������
2��Ȼ�����ڵ�����Ľڵ���н���
3��heapsize-1
4��Ȼ��heapify

�ڵ���ΪN����ô���ΪlogN�������Ļ�ʱ�临�ӶȾ���logN��
��������ѵ�ʱ�临�Ӷ�Ϊlog1+log2+log3+����������+logN������Ӷ���O(N)
��������ѵ�ʱ�临�Ӷ���N��
������ʱ��Ӧ����logN�ĸ��Ӷȣ�����ÿһ��������Ҫ�������Ը��Ӷ�ΪN*logN��
���Զ��ŵĸ��Ӷ�ΪN*logN1

�����ڹ����϶������õıȽ��٣�ԭ���� ���ȶ���ָ�������˳�򣩺� ������ �Ƚ϶࣬���Ź������õıȽ϶ࡣ

ϵͳ�е�����
arr.sort() �ۺ�������������sizeС��60���в�������size>60 mergesort����quicksort
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class code_for_heapsort
{
    public:
    void heapsort(vector<int>&nums)
    {
        if(nums.size()<2)
            return;
        for(int i=0;i<nums.size();i++)
        {
            heapInsert(nums,i);
        }
        int heapSize=nums.size();
        swap(nums[0],nums[--heapSize]);
        while(heapSize>0)
        {
            heapify(nums,0,heapSize);
            swap(nums[0],nums[--heapSize]);
        }

    }
    //insert�������ߵĹ���
    void heapInsert(vector<int>& nums,int index)
    {
        //���������
        //�������Ľڵ�Ϊ���ڵ�
        while(nums[index]>nums[(index-1)/2])
        {
            swap(nums[index],nums[(index-1)/2]);
            index=(index-1)/2;
        }
    }
    //heapify�������ߵĹ���
    void heapify(vector<int>& nums,int index,int heapSize)
    {
        //��������ѣ���index=0��ʼ
        int left=index*2+1;
        while(left<heapSize)//�����Ӳ�Խ��
        {
            //����Һ��Ӳ�Խ�磬���Ҵ�������
            int largest=left+1<heapSize&&nums[left+1]>nums[left]?left+1:left;
            largest=nums[largest]>nums[index]?largest:index;
            if(largest==index)
                break;
            swap(nums[largest],nums[index]);
            index=largest;
            left=index*2+1;
        }
    }

};
int main()
{
    vector<int> x={3,4,1,2,7,6,9,4,5};
    code_for_heapsort c;
    c.heapsort(x);
    for(auto xx:x)
    {
        cout<<xx<<" ";
    }
    cout<<endl;

    cout<<"nice"<<endl;
    return 0;
}
