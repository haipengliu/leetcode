ListNode* addTwoNumbers(ListNode* L1, ListNode* L2)
{
  if ( !L1 )
  {
    return L2;
  }

  if ( !L2 )
  {
    return L2;
  }

  ListNode *head = new ListNode(0);
  ListNode *p = head;
  ListNode *q = NULL;
  int carry = 0;
  int sum = 0;
  int digit = 0;

  while ( L1 && L2 )
  {
    sum = L1->val + L2->val + carry;

    digit = sum%10;
    carry = sum/10;

    q = new ListNode(digit);
    p->next = q;

    p = p->next;
    L1 = L1->next;
    L2 = L2->next;
  }

  while ( L1 )
  {
    sum = L1->val + carry;

    digit = sum%10;
    carry = sum/10;

    q = new ListNode(digit);
    p->next = q;

    p = p->next;
    L1 = L1->next;
  }

  while ( L2 )
  {
    sum = L2->val + carry;

    digit = sum%10;
    carry = sum/10;

    q = new ListNode(digit);
    p->next = q;

    p = p->next;
    L2 = L2->next;
  }

  if ( carry > 0 )
  {
    q = new ListNode(carry);
    p->next = q;
  }

  return head->next;
}
