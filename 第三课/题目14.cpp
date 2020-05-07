/**
两个单链表相交的一系列问题


题意：

两个单链表可能有环可能无环，给定两个链表的头节点然后head1和head2，这两个链表可能相交
也可能不相交，实现一个函数如果相交那么返回相交的第一个节点，不相交返回null

思路：

1、求两个单链表的第一个入环节点，使用快慢指针法
2、分别求第一个入环节点loop1和第二个入环节点loop2
3、如果loop1和loop2都为空，那么遍历h1到最后一个节点，然后统计长度，同样h2
4、如果一个为空一个不为空那么不可能相交
5、两个都有环的判断loop1和loop2相不相等
6、不相等的话循环loop1
7、相等的话，以loop1和loop2为结尾，无环链表相交问题
*/

#include<iostream>
#include<hash_set>
using namespace std;
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):
        val(x),next(NULL){}
};

class Solution
{
    public:
    ListNode* judgexiangjiao(ListNode* head1,ListNode* head2)
    {
        //hashset判断有没有环
        //都没有环
        //1、如果2个链表都没有环然后找相交，可以用hashset先遍历head1然后记录，然后遍历head2，如果head2在hashset中就是相交节点
        //2、遍历链表的长度，同时记录最后一个节点，如果两个节点不相等那么不相交，相等话然后一个先走一定步数
        //一个有环一个无环，那么不可能相交
        //两个都有环的时候
        //如果loop1=loop2，那么等同于无环链表相交问题
        //如果loop1！=loop2，让loop1继续往下走如果回到自己没有遇到loop2就是66结构，如果中途遇到了loop2那么就是共享环结构
        ListNode* loop1=getfirstloopnode(head1);
        ListNode* loop2=getfirstloopnode(head2);
        if(loop1==nullptr&&loop2==nullptr)
            return noloop(head1,head2);
        if(loop1!=nullptr&&loop2!=nullptr)
            return bothloop(head1,loop1,head2,loop2);
        return nullptr;
    }
    ListNode* noloop(ListNode* h1,ListNode* h2)
    {

    }
    //两个链表都有环的时候
    ListNode* bothloop(ListNode* h1,ListNode* loop1,ListNode* h2,ListNode* loop2)
    {
        ListNode* cur1=nullptr;
        ListNode* cur2=nullptr;
        //分两种情况loop1=loop2的时候和不相等的时候
        if(loop1==loop2)
        {
            cur1=h1;
            cur2=h2;
            int n1=0;
            while(cur1!=loop1)
            {
                n1++;
                cur1=cur1->next;
            }
            while(cur2!=loop2)
            {
                n1--; //不多用一个变量
                cur2=cur2->next;
            }
            //让cur1是长的那个
            cur1=n1>0?cur1:cur2;
            cur2=cur1==head1?head2:head1;
            n1=abs(n1);
            //看人家的代码写出来的思路就是不一样
            while(n1!=0)
            {
                n1--;
                cur1=cur1->next;
            }
            while(cur1!=cur2)
            {
                cur1=cur1->next;
                cur2=cur2->next;
            }
            return cur1;
        }
        else
        {
            //共环的时候，需要区分66结构和共环的结构
            cur1=loop1->next;
            while(cur1!=loop1)
            {
                if(cur1==loop2)
                    return loop1;//返回就是loop1和loop2
                cur1=cur1->next;
            }
            return nullptr;//66结构

        }
    }


    //判断是否有环的另外一种方法，使用hashset来做，快慢指针的方法
    ListNode* getfirstloopnode(ListNode* head)
    {
        set<ListNode*> s;
        while(head!=nullptr)
        {
            if(s.count(head)))
            {
                return head;//返回环的入口节点，这个感觉速度更快一些，但是需要额外空间
            }
            s.push(head);
            head=head->next;
        }
        return nullptr;
    }

    ListNode* getfirstloopnode2(ListNode* head)
    {
        //最少得两个指针
        if(head==nullptr||head->next==nullptr||head->next->next==nullptr)
            return nullptr;
        ListNode* fast=head->next->next;
        ListNode* slow=head->next;
        while(slow!=fast)
        {
            //在循环里面判断效果确实好,防溢出同时能停止。
            if(fast->next==nullptr||fast->next->next==nullptr)
                return nullptr;
            slow=slow->next;
            fast=fast->next->next;
        }
        //相遇之后
        slow=head;
        while(slow!=fast)
        {
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
    }





};
int main()
{

    cout<<"nice"<<endl;
    return 0;
}
