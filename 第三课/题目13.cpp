/**
���Ƹ������������

˼·��
map���� ԭ�ڵ� �� �����ڵ� ��ӳ���ϵ

����һ��ʹ��hashmap
������������hashmap�����½��Ľڵ����ԭ�ڵ�ĺ��棬���˶�Ӧ�Ĺ�ϵ�����ǲ���ʵ�ְ�
�����Ҫ��������
*/
#include<iostream>
#include<unordered_map>
using namespace std;
//�����ýṹ�嶨��ڵ�Ҳ�������ඨ��ڵ�
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution{
public:
    Node* copylist(Node* head)
    {
        unordered_map<Node*,Node*> m;
        Node* cur=head;
        while(cur!=nullptr)
        {
            m[cur]=new Node(cur->val);
            cur=cur->next;
        }
        //Ȼ�����´�head��ʼ
        cur=head;
        while(cur!=nullptr)
        {
            m[cur]->next=m[cur->next];
            m[cur]->random=m[cur->random];
            cur=cur->next;
        }
        return m[head];
    }

};

class Solution2{
public��
    Node* copylist2(Node* head)
    {
        Node* cur=head;
        while(cur!=nullptr)
        {
            Node* node=new Node(cur->val);
            node->next=cur->next;
            cur->next=node;
            cur=cur->next->next;
        }
        //Ȼ����random�ڵ�
        cur=head;
        cur2=head->next;
        while(cur2!=nullptr&&cur2->next!=nullptr)
        {
            cur2->random=cur->random->next;
            cur=cur->next->next;
            cur2=cur2->next->next;
        }
        //Ȼ������¾�����
        Node* res=head->next;
        cur=head;
        cur2=res;
        while(cur2!=nullptr&&cur2->next!=nullptr)
        {
            cur->next=cur->next->next;
            cur2->next=cur2->next->next;
        }
        return res;
    }

};

//����Ĵ���
class Solution3
{
public:
    Node* copylist(Node* head)
    {
        if(head==nullptr)
            return nullptr;
        Node* cur=head;
        Node* next=nullptr;
        while(cur!=nullptr)
        {
            next=cur->next;
            cur->next=new Node(cur->val);
            cur->next->next=next;
            cur=next;
        }
        //ָ��random
        cur=head;
        Node* curcopy=null;
        while(cur!=nullptr)
        {
            next=cur->next->next;
            curcopy=cur->next;//�ó���Ӧ��copy�ڵ�
            curcopy->random=cur->random==nullptr?nullptr:cur->random->next;
            cur=next;
        }
        //�������������
        Node res=head->next;
        cur=head;
        while(cur!=nullptr)
        {
            next=cur->next->next;
            curcopy=cur->next;
            cur->next=next;
            curcopy->next=next==nullptr?nullptr:next->next;
            cur=next;
        }
        return res;

    }

};
int main()
{

    cout<<"nice"<<endl;
    return 0;
}
