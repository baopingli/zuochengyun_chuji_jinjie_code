/**
�����������ཻ��һϵ������


���⣺

��������������л������޻����������������ͷ�ڵ�Ȼ��head1��head2����������������ཻ
Ҳ���ܲ��ཻ��ʵ��һ����������ཻ��ô�����ཻ�ĵ�һ���ڵ㣬���ཻ����null

˼·��

1��������������ĵ�һ���뻷�ڵ㣬ʹ�ÿ���ָ�뷨
2���ֱ����һ���뻷�ڵ�loop1�͵ڶ����뻷�ڵ�loop2
3�����loop1��loop2��Ϊ�գ���ô����h1�����һ���ڵ㣬Ȼ��ͳ�Ƴ��ȣ�ͬ��h2
4�����һ��Ϊ��һ����Ϊ����ô�������ཻ
5���������л����ж�loop1��loop2�಻���
6������ȵĻ�ѭ��loop1
7����ȵĻ�����loop1��loop2Ϊ��β���޻������ཻ����
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
        //hashset�ж���û�л�
        //��û�л�
        //1�����2������û�л�Ȼ�����ཻ��������hashset�ȱ���head1Ȼ���¼��Ȼ�����head2�����head2��hashset�о����ཻ�ڵ�
        //2����������ĳ��ȣ�ͬʱ��¼���һ���ڵ㣬��������ڵ㲻�����ô���ཻ����Ȼ�Ȼ��һ������һ������
        //һ���л�һ���޻�����ô�������ཻ
        //�������л���ʱ��
        //���loop1=loop2����ô��ͬ���޻������ཻ����
        //���loop1��=loop2����loop1��������������ص��Լ�û������loop2����66�ṹ�������;������loop2��ô���ǹ����ṹ
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
    //���������л���ʱ��
    ListNode* bothloop(ListNode* h1,ListNode* loop1,ListNode* h2,ListNode* loop2)
    {
        ListNode* cur1=nullptr;
        ListNode* cur2=nullptr;
        //���������loop1=loop2��ʱ��Ͳ���ȵ�ʱ��
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
                n1--; //������һ������
                cur2=cur2->next;
            }
            //��cur1�ǳ����Ǹ�
            cur1=n1>0?cur1:cur2;
            cur2=cur1==head1?head2:head1;
            n1=abs(n1);
            //���˼ҵĴ���д������˼·���ǲ�һ��
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
            //������ʱ����Ҫ����66�ṹ�͹����Ľṹ
            cur1=loop1->next;
            while(cur1!=loop1)
            {
                if(cur1==loop2)
                    return loop1;//���ؾ���loop1��loop2
                cur1=cur1->next;
            }
            return nullptr;//66�ṹ

        }
    }


    //�ж��Ƿ��л�������һ�ַ�����ʹ��hashset����������ָ��ķ���
    ListNode* getfirstloopnode(ListNode* head)
    {
        set<ListNode*> s;
        while(head!=nullptr)
        {
            if(s.count(head)))
            {
                return head;//���ػ�����ڽڵ㣬����о��ٶȸ���һЩ��������Ҫ����ռ�
            }
            s.push(head);
            head=head->next;
        }
        return nullptr;
    }

    ListNode* getfirstloopnode2(ListNode* head)
    {
        //���ٵ�����ָ��
        if(head==nullptr||head->next==nullptr||head->next->next==nullptr)
            return nullptr;
        ListNode* fast=head->next->next;
        ListNode* slow=head->next;
        while(slow!=fast)
        {
            //��ѭ�������ж�Ч��ȷʵ��,�����ͬʱ��ֹͣ��
            if(fast->next==nullptr||fast->next->next==nullptr)
                return nullptr;
            slow=slow->next;
            fast=fast->next->next;
        }
        //����֮��
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
