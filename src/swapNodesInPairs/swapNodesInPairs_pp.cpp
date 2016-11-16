/* Given a linked list, swap every two adjacent nodes and return its head. */

/*   For example, */
/*   Given 1->2->3->4, you should return the list as 2->1->4->3. */

/*   Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed. */

/*   Hide Tags Linked List */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <iostream>

using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}  
};

ListNode* swapPairs(ListNode* head)
{
  ListNode *auxi = NULL;
  ListNode *prev = NULL, *left = NULL, *right = NULL, *p = NULL;

  auxi = new ListNode(0);

  auxi->next = head;

  prev = auxi;
  
  left = right = p = head;

  while ( p && p->next )
  {
    p = p->next->next;
    
    left = prev->next;
    right = left->next;

    prev->next = right;
    right->next = left;
    left->next = p;

    prev = left;    
  }

  return auxi->next;  
}

void print_list(ListNode *head)
{
  while(head)
  {
    cout << head->val << " ";
    head = head->next;
  }

  cout<<endl; 
}


int main()
{
  ListNode *L1 = new ListNode(1);
  ListNode *L2 = new ListNode(2);
  ListNode *L3 = new ListNode(3);
  ListNode *p = NULL;
  
  L1->next = L2;
  L2->next = L3;

  print_list(L1);

  p = swapPairs(L1);

  print_list(p);
  
  return 0;
}
