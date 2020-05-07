/**
完全二叉树。
每一层都是从左往右填的树。可以不填满。
落地结构是数组结构。
左孩子就是2*i+1
右孩子就是2*i+2
父节点为 （i-1）/2
完全通过下标变换就可以找到左右子节点
把二叉树结构用数组实现。

pipline:
1、heapInsert构建大根堆
2、然后将最大节点和最后的节点进行交换
3、heapsize-1
4、然后heapify

节点数为N，那么深度为logN，调整的话时间复杂度就是logN的
建立大根堆的时间复杂度为log1+log2+log3+。。。。。+logN这个复杂度是O(N)
建立大根堆的时间复杂度是N。
调整的时候应该是logN的复杂度，但是每一个数都需要调整所以复杂度为N*logN，
所以堆排的复杂度为N*logN1

但是在工程上堆排序用的比较少，原因是 不稳定（指的是相对顺序）和 常数项 比较多，快排工程上用的比较多。

系统中的排序
arr.sort() 综合排序，如果数组的size小于60进行插入排序，size>60 mergesort或者quicksort
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
    //insert是往下走的过程
    void heapInsert(vector<int>& nums,int index)
    {
        //构建大根堆
        //让树最大的节点为根节点
        while(nums[index]>nums[(index-1)/2])
        {
            swap(nums[index],nums[(index-1)/2]);
            index=(index-1)/2;
        }
    }
    //heapify是往上走的过程
    void heapify(vector<int>& nums,int index,int heapSize)
    {
        //调整大根堆，从index=0开始
        int left=index*2+1;
        while(left<heapSize)//当左孩子不越界
        {
            //如果右孩子不越界，并且大于左孩子
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
