/**
转圈打印矩阵

*/
#include<iostream>
#include<vector>
using namespace std;
class Solution{

public:
    void printEdge(vector<vector<int>>& nums,vector<int>& res,int row1,int col1,int row2,int col2)
    {

        //方法是定义四个坐标,这是一种做法
        //还有一种做法就是定义四个变量，然后一直循环即可。
        if(row1==row2)
        {
            for(int i=col1;i<=col2;i++)
            {
                res.push_back(nums[row1][i]);
            }
        }
        else if(col1==col2)
        {
            for(int i=row1;i<=row2;i++)
            {
                res.push_back(nums[i][col1]);
            }
        }
        else
        {
            int currow=row1;
            int curcol=col1;

            while(curcol!=col2)
            {
                res.push_back(nums[currow][curcol++]);
            }
            while(currow!=row2)
            {
                res.push_back(nums[currow++][curcol]);
            }
            while(curcol!=col1)
            {
                res.push_back(nums[currow][curcol--]);
            }
            while(currow!=row1)
            {
                res.push_back(nums[currow--][curcol]);
            }
        }

    }

    vector<int> printcircle(vector<vector<int>> nums)
    {
        vector<int> res;
        int row1=0;
        int col1=0;
        int row2=nums.size()-1;
        int col2=nums[0].size()-1;
        while(row1<=row2&&col1<=col2)
        {
            printEdge(nums,res,row1++,col1++,row2--,col2--);
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
    vector<int> res;
    res=s.printcircle(x);
    for(auto r:res)
    {
        cout<<r<<" ";
    }
    cout<<endl;
    cout<<"nice"<<endl;
    return 0;
}
