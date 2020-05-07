/**
单向链表的partition过程
如果是数组的话就是两个边界然后交换。


1、声明一个node数组，然后partition，然后拿出来再连接
2、不用容器的话，定义三个指针，small、equal、big指针然后遍历链表，然后分别往3个指针后面放，然后连接。O（N）的时间复杂度

具体的思路为：
首先遍历一边找到，3个序列的头，然后再遍历，只要不等于头就往后加。

*/
#include<iostream>
using namespace std;
int main()
{

    cout<<"hello"<<endl;
    return 0;
}
