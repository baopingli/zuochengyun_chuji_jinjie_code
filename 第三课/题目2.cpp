/**
实现一个特殊的栈，在满足栈的最基本的功能之外，还要能返回栈中最小的元素
pop push getmin都是O(1)的复杂度
可以使用现有的栈的结构
栈落地是双向链表结构
*/
#include<iostream>
#include<stack>
using namespace std;
class Solution
{
private:
    stack<int> data;
    stack<int> mins;
public:
    void push(int num)
    {
        if(mins.empty())
        {
            mins.push(num);
        }
        else if(num<mins.top())
        {
            mins.push(num);
        }
        else
        {
            int t=mins.top();
            mins.push(t);
        }
        data.push(num);
    }
    int pop()
    {
        if(data.empty())
            throw "data stack is empty";
        int r=data.top();
        data.pop();
        mins.pop();
        return r;
    }
    int getMin()
    {
        if(mins.empty())
            return "this stack is empty";
        return mins.top();
    }
};
//还有一种方法可以使用较少一点的空间，就是mins栈只保存当前元素<=mins栈栈顶的元素，然后弹出的时候判断当前的元素和mins栈栈顶元素
//是不是相等的，如果相等的话就都弹出，否则就只弹出data栈
int main()
{

    cout<<"nice"<<endl;
    return 0;
}

