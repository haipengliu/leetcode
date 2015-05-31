/* You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list. */

/* Input: (2 -> 4 -> 3) + (5 -> 6 -> 4) */
/*   Output: 7 -> 0 -> 8 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    
    ListNode *h  = new ListNode(0);
    ListNode *p  = NULL;
    ListNode *q  = NULL;
    int     sum  = 0;
    int residue  = 0;
    
    p = h;

    if ( !l1 && !l2 )
    {
      q = new ListNode(0);
      p->next = q;
      p = q;
      goto Finish;
    }

    residue = 0;
    while ( l1 || l2 || residue)
    {
      sum = (l1? l1->val:0) + (l2? l2->val:0) + residue;
      if ( l1 ) {l1=l1->next;}
      if ( l2 ) {l2=l2->next;}

      q = new ListNode(sum%10);
      residue = sum/10;

      p->next = q;
      p = q;
    }

  Finish:
    
    return h->next;    
  }
};
  
