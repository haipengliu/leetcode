/* Given a linked list, remove the nth node from the end of list and return its head. */

/*   For example, */

/*   Given linked list: 1->2->3->4->5, and n = 2. */

/*   After removing the second node from the end, the linked list becomes 1->2->3->5. */
/*   Note: */
/*   Given n will always be valid. */
/*   Try to do this in one pass. */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}  
};

ListNode* removeNthFromEnd(ListNode* head, int n)
{
  ListNode *auxi = new ListNode(0);
  auxi->next = head;
  
  ListNode *jump = NULL;
  ListNode *pre  = NULL;
  ListNode *cur  = NULL;
  int i;
  
  pre = auxi;

  while ( NULL != pre->next )
  {
    jump = pre;

    for ( i = 0; i < n; i++ )
    {
      jump = jump->next;
    }

    if ( NULL == jump->next )
    {
      cur = pre->next;
      pre->next = cur->next;
      cur->next = NULL;

      delete cur;
      break;
    }
    else
    {
      pre = pre->next;
    }
    
  }

  return auxi->next;
    
}





              
