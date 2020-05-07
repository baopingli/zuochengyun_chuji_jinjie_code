/**
复制复杂链表，深拷贝。

思路：
map建立 原节点 和 拷贝节点 的映射关系

方法一：使用hashmap
方法二：不用hashmap，将新建的节点放在原节点的后面，有了对应的关系。但是不好实现啊
最后需要分离链表
*/
#include<iostream>
#include<unordered_map>
using namespace std;
//可以用结构体定义节点也可以用类定义节点
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
        //然后重新从head开始
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
public：
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
        //然后整random节点
        cur=head;
        cur2=head->next;
        while(cur2!=nullptr&&cur2->next!=nullptr)
        {
            cur2->random=cur->random->next;
            cur=cur->next->next;
            cur2=cur2->next->next;
        }
        //然后分离新旧链表
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

//左神的代码
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
        //指向random
        cur=head;
        Node* curcopy=null;
        while(cur!=nullptr)
        {
            next=cur->next->next;
            curcopy=cur->next;//拿出对应的copy节点
            curcopy->random=cur->random==nullptr?nullptr:cur->random->next;
            cur=next;
        }
        //将两个链表分离
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
