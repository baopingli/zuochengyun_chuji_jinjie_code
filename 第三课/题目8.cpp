/**
֮���δ�ӡ����

˼·�������������꣬a��b������a���������ߣ�Ȼ��

��������Ҫ����۵��ȣ���۵�����ã�Ȼ��ʵ������ĺ�������
*/

#include<iostream>
#include<vector>
using namespace std;
class Solution
{
    public:
    //˼·�ǹ��������㣬a��b��a����������ߣ�Ȼ����������ߣ�b���ȴ���������Ȼ����������ߡ�
    //a��b��������Թ���һ���Խ���
    //Ȼ���ӡ�Խ��ߡ�
    void printdiagonal(vector<vector<int>>& nums,vector<int>& res,int row1,int col1,int row2,int col2,bool fromup)
    {
        //��������Ҳ���Ǵ�a�㵽b���ӡ�Խ���
        if(fromup)
        {
            while(row1<=row2)
            {
                res.push_back(nums[row1++][col1--]);
            }
        }
        else
        {
            while(col2<=col1)
            {
                res.push_back(nums[row2--][col2++]);
            }
        }
    }
    vector<int> zhiziprint(vector<vector<int>>& nums)
    {
        int row1=0;
        int col1=0;
        int row2=0;
        int col2=0;
        int m=nums.size();
        int n=nums[0].size();
        bool fromup=false;
        vector<int> res;
        while(row1<=m-1)
        {
            printdiagonal(nums,res,row1,col1,row2,col2,fromup);
            row1=col1==n-1?row1+1:row1;
            col1=col1==n-1?col1:col1+1;
            col2=row2==m-1?col2+1:col2;
            row2=row2==m-1?row2:row2+1;//�����и��ӣ�row2������col2ǰ��
            fromup=!fromup;
        }
        return res;
    }
};
int main()
{
    vector<vector<int>> x={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    cout<<"input"<<endl;
    for(int i=0;i<x.size();i++)
    {
        for(int j=0;j<x[0].size();j++)
        {
            cout<<x[i][j]<<" ";
        }
        cout<<endl;
    }
    Solution s;
    vector<int> res=s.zhiziprint(x);
    for(auto r:res)
    {
        cout<<r<<" ";
    }
    cout<<endl;

    cout<<"nice"<<endl;
    return 0;
}
