//������ṹʵ�̶ֹ���С��ջ�Ͷ���

#include<iostream>
#include<vector>
using namespace std;


class array_for_stack{
private:
    vector<int> arr;
    int index;
public:
    void arraystack(int initsize)
    {
        if(initsize<0)
            throw "init size can not less than 0";
        arr.resize(initsize);
        index=0;
    }
    int peek()
    {
        if(index==0)
            return null;
        return arr[index-1];
    }
    void push(int num)
    {
        if(index==arr.size())
            throw "the stack is full";
        arr[index++]=num;
    }
    int pop()
    {
        if(index==0)
            throw "the stack is empty";
        return arr[--index];
    }
};
//���У�������ѭ����������
class array_for_queue
{
private:
    vector<int> arr;
    int cursize;
    int start_position;
    int end_position;
public:
    void arrayqueue(int initsize)
    {
        if(initsize<0)
            throw "the init size can not be less than 0";
        arr.resize(initsize);
        cursize=0;
    }
    int peek()
    {
        if(cursize==0)
            return null;
        return arr[start_position];
    }
    void push(int num)
    {
        if(cursize==arr.size())
            throw "the queue is full";
        cursize++;
        arr[end_position]=num;//end_positionָ�������һ�������λ��
        end_position=nextindex(arr.size(),end_position);
    }
    int pop()
    {
        if(cursize==0)
            throw "the queue is empty";
        cursize--;
        int temp=start_position;//start_positionָ����ǵ�һ��Ԫ�ص�λ��
        start_position=next_position(arr.size(),start_position);
        return arr[temp];
    }
    //��װ����Ҫ��
    int nextindex(int len,int index)
    {
        return index==len-1?0:index+1;
    }

};
int main()
{
    vector<int> x;
    x.resize(5);
    //x.reserve(5);
    int res=x.size();
    cout<<res<<endl;

    cout<<"nice"<<endl;
    return 0;
}
