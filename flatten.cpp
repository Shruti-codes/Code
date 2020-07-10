
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

class Solution {
public:
    Node* flatten(Node* head)
    {   
        Node *res = head;
        Node *tmp, *tmp1, *tail;
        
        while(res)
        {
            if(res->child != NULL)
            {
                tmp = res->next;
                tmp1 = flatten(res->child);
                res->child = NULL;
                res->next  = tmp1;
                tmp1->prev = res;
                tail = tmp1;
                
                while(tail->next != NULL)
                    tail = tail->next;
                
                tail->next = tmp;
                if(tmp)
                    tmp->prev = tail;
            }
            res = res->next;
        }
        return head;
    }
};

int main()
{
    //create doubly linked list
    Node *head = flatten(head);
    //print linked list
}