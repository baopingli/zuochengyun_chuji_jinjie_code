/**
ʵ��һ�������ջ��������ջ��������Ĺ���֮�⣬��Ҫ�ܷ���ջ����С��Ԫ��
pop push getmin����O(1)�ĸ��Ӷ�
����ʹ�����е�ջ�Ľṹ
ջ�����˫������ṹ
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
//����һ�ַ�������ʹ�ý���һ��Ŀռ䣬����minsջֻ���浱ǰԪ��<=minsջջ����Ԫ�أ�Ȼ�󵯳���ʱ���жϵ�ǰ��Ԫ�غ�minsջջ��Ԫ��
//�ǲ�����ȵģ������ȵĻ��Ͷ������������ֻ����dataջ
int main()
{

    cout<<"nice"<<endl;
    return 0;
}

