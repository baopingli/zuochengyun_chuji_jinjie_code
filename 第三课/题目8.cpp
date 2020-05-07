/**
之字形打印矩阵

思路：定义两个坐标，a和b，其中a从左往右走，然后

这种题主要看宏观调度，宏观调度想好，然后实现里面的函数即可
*/

#include<iostream>
#include<vector>
using namespace std;
class Solution
{
    public:
    //思路是构建两个点，a和b，a点从左往右走，然后从上往下走，b点先从上往下走然后从左往右走。
    //a和b两个点可以构成一条对角线
    //然后打印对角线。
    void printdiagonal(vector<vector<int>>& nums,vector<int>& res,int row1,int col1,int row2,int col2,bool fromup)
    {
        //从上往下也就是从a点到b点打印对角线
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
            row2=row2==m-1?row2:row2+1;//这里有个坑，row2不能在col2前面
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
