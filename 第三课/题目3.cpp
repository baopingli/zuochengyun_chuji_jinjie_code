/**
ʹ��ջ�ṹʵ�ֶ���
ʹ�ö���ʵ��ջ

���磺ͼ��������ȱ�����Ҫ�õ�ջ�ṹ��ʵ�֣��������Թ�Ҫ���� ���� ��ʵ�֣�

1��ջ�ö�����ʵ�ֵ�˼·��
���������У�һ������һֱ���ⵯ����Ȼ�󵯳�����������һ�����������룬Ȼ��ֻʣ��һ�����������������أ�Ȼ��
������Ǹ�����ͬ���������ֻʣ��һ�������������أ������������ص���

2������������ջ��ʵ�ֵ�˼·��
������ջ���ֱ����pushջ��popջ��pushջ��
��֤����ԭ��
1��popջ������Ԫ�ص�ʱ��һ����Ҫ��pushջ�е�Ԫ�ص���popջ
2��pushջ��Ԫ�ص���popջ�е�ʱ��Ҫһ����ȫ�����롣

*/
#include<iostream>
#include<queue>
using namespace std;
class twoqueuestack{
private:
    queue<int> my_queue;
    queue<int> help;
public:
    void push(int num)
    {
        my_queue.push(num);
    }
    int pop()
    {
        if(my_queue.empty())
            throw "the stack is empty";
        while(my_queue.size()>1)
        {
            int t=my_queue.front();
            help.push(t);
            my_queue.pop();
        }
        int res=my_queue.front();
        my_queue.pop();
        swapname();
        return res;
    }
    void swapname()
    {
        queue<int> temp=my_queue;
        my_queue=help;
        help=temp;
    }
    int peek()
    {
       if(my_queue.empty())
            throw "the stack is empty";
       while(my_queue.size()!=1)
       {
           int t=my_queue.front();
           help.push(t);
           my_queue.pop();
       }
       int res=my_queue.front();
       my_queue.pop();
       help.push(res);
       swapname();
       return res;
    }
};


class twostackqueue{
private:
    stack<int> push_stack;
    stack<int> pop_stack;
public:
    //��pushջ����popջ�е��Ĳ���
    void dao()
    {
        //��popջ��Ϊ�յ�ʱ��ŵ�
        if(pop_stack.empty())
        {
            while(!push_stack.empty())
            {
                int t=push_stack.top();
                pop_stack.push(t);
                push_stack.pop();
            }
        }
    }
    void push(int num)
    {
        push_stack.push(num);
        dao();
    }
    int poll()
    {
        if(push_stack.empty()&&pop_stack.empty())
            throw "this queue is empty";
        int x=pop_stack.top();
        dao();
        pop_stack.pop();
        return x;
    }
    int peek()
    {
        if(push_stack.empty()&&pop_stack.empty())
            throw "this queue is empty";
        dao();
        return pop_stack.top();
    }
};



int main()
{

    cout<<"nice"<<endl;
    return 0;
}
