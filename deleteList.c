 #include<stdio.h>
#include<stdlib.h>

#define size 10

  struct ListNode {
      int val;
      struct ListNode *next;
  };
 


struct ListNode* removeElements(struct ListNode* head, int val)
{
      
    if(head==NULL)
        return NULL;

    struct ListNode* ptr;
    struct ListNode* prev;
    prev = NULL;
    ptr = head;

    while(ptr!=NULL)
    {
        if(ptr->val == val)
        {
             ptr = ptr->next;
             if(prev!=NULL)
                prev->next = ptr;
            else
                head = ptr;
        }
        else
        {
            prev = ptr;
            ptr = ptr->next;
        }
       
    }
    
    return head;

}

int main()
{
    struct ListNode* head = malloc(sizeof(struct ListNode));
    struct ListNode* p = malloc(sizeof(struct ListNode));
    head->val = 1;
    p->val = 1;
    p->next = NULL;
    head->next = p;
    int k = 1;

    head = removeElements(head, k);
    struct ListNode* ptr = head;

     while(ptr!=NULL)
    {
        printf("%d  ", ptr->val);
        ptr = ptr->next;
    }
   

}