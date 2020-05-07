/**
使用栈结构实现队列
使用队列实现栈

比如：图的深度优先遍历需要用到栈结构来实现，但是面试官要你用 队列 来实现？

1、栈用队列来实现的思路：
用两个队列，一个队列一直往外弹数，然后弹出的数往另外一个队列中输入，然后只剩下一个数不弹出用来返回，然后
另外的那个队列同样这个操作只剩下一个数，用来返回，两个队列来回倒。

2、队列用两个栈来实现的思路：
用两个栈，分别叫做push栈和pop栈，push栈，
保证两条原则：
1）pop栈里面有元素的时候一定不要将push栈中的元素导入pop栈
2）push栈中元素导入pop栈中的时候要一次性全部导入。

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
    //从push栈中往pop栈中导的操作
    void dao()
    {
        //当pop栈中为空的时候才导
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
