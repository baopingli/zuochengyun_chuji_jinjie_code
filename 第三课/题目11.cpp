/**
�ж�һ�������ǲ��ǻ��Ľṹ
ʱ�临�Ӷ�ΪO(N)���ռ临�Ӷ�ΪO��1��

O(N)�⣺ʹ��һ��ջ
O(N)�⣺����ָ�룬�ҵ�������е㣬Ȼ���Ұ벿��ѹ��ջ�У�Ȼ��ǰ�벿�ֺ�ջ�еı����
���ܶ��Ͼ��ǻ���
O(1)��:�Ѻ�벿������Ȼ�������ߣ�ÿ���ȶԣ�������󻹵õ�������
*/
#include<iostream>
using namespace std;
//�½�һ������ڵ�û�
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };
class Solution{
public:
    bool isPalindrome1(ListNode* head)
    {
        //���ȿ���ָ���ҵ��е�Ȼ�󽫺�벿�ַ�ת
        //Ȼ���β����ͷ��һһ�Աȣ��������ȷ���false
        if(head==nullptr||head->next==nullptr)
            return true;
        ListNode* fast=head;
        ListNode* slow=head;
        //���м�λ��
        while(fast->next!=nullptr&&fast->next->next!=nullptr)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        //Ȼ�������
        fast=slow->next;
        slow->next=nullptr;
        //Ȼ��ת��벿��
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
        //����ָ������˸���
        n3=slow;//��β��n3���ڵ�λ��������β��
        fast=head;
        bool res=true;
        //Ȼ����Ǳ���
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
        //����Ҫ��������ԭ����ģ��
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
    //��������
    ListNode* head=new ListNode(-1);
    ListNode* cur=head;
    for(int i=0;i<3;i++)
    {
        ListNode* node=new ListNode(i);
        cur->next=node;
        cur=cur->next;
    }

    //��ӡ����
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
