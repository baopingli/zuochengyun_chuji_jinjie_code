/**
判断一个链表是不是回文结构
时间复杂度为O(N)，空间复杂度为O（1）

O(N)解：使用一个栈
O(N)解：快慢指针，找到链表的中点，然后右半部分压入栈中，然后前半部分和栈中的比如果
都能对上就是回文
O(1)解:把后半部分逆序，然后两边走，每个比对，但是最后还得调换回来
*/
#include<iostream>
using namespace std;
//新建一个链表节点得会
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };
class Solution{
public:
    bool isPalindrome1(ListNode* head)
    {
        //首先快慢指针找到中点然后将后半部分反转
        //然后从尾部和头部一一对比，如果不相等返回false
        if(head==nullptr||head->next==nullptr)
            return true;
        ListNode* fast=head;
        ListNode* slow=head;
        //找中间位置
        while(fast->next!=nullptr&&fast->next->next!=nullptr)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        //然后把链表割开
        fast=slow->next;
        slow->next=nullptr;
        //然后反转后半部分
        /*
        ListNode* t1=nullptr;
        ListNode* t2=fast->next;
        while(t2!=nullptr)
        {
            fast->next=t1;
            t1=fast;
            fast=t2;
            t2=t2->next;
        }
        */
        ListNode* n3=nullptr;
        while(fast!=nullptr)
        {
            n3=fast->next;
            fast->next=slow;
            slow=fast;
            fast=n3;
        }
        //都将指针进行了复用
        n3=slow;//队尾，n3现在的位置是链表尾部
        fast=head;
        bool res=true;
        //然后就是遍历
        while(slow!=nullptr&&fast!=nullptr)
        {
            if(slow->val!=fast->val)
            {
                res=false;
                break;
            }
            slow=slow->next;
            fast=fast->next;
        }
        //还需要把链表返回原来的模样
        slow=n3->next;
        n3->next=nullptr;
        while(slow!=nullptr)
        {
            fast=slow->next;
            slow->next=n3;
            n3=slow;
            slow=fast;
        }
        return res;
    }
};
int main()
{
    //构建链表
    ListNode* head=new ListNode(-1);
    ListNode* cur=head;
    for(int i=0;i<3;i++)
    {
        ListNode* node=new ListNode(i);
        cur->next=node;
        cur=cur->next;
    }

    //打印链表
    ListNode* cur2=head;
    while(cur2!=nullptr)
    {
        cout<<cur2->val<<" ";
        cur2=cur2->next;
    }
    cout<<endl;
    Solution s;
    bool res=s.isPalindrome1(head);
    cout<<res<<endl;

    cout<<"hello"<<endl;
    return 0;
}
