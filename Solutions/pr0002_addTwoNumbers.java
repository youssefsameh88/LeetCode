class ListNode {
    int val;
    ListNode next;

    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) {
        this.val = val;
        this.next = next;
    }
}
class Solution2 {
    
    public static ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode ans = new ListNode(0);
        ListNode c1 = l1;
        ListNode c2 = l2;
        ListNode curr = ans;
            int carry = 0;

        while (c1 != null || c2 != null){
            if(c1 == null)
                c1 = new ListNode(0);
            if(c2 == null)
                c2 = new ListNode(0);


            curr.next = new ListNode(c1.val + c2.val + carry) ;
                carry = curr.next.val / 10 ;
                curr.next.val -= 10 * carry;
              
            if (c1 != null) c1 = c1.next;
            if (c2 != null) c2 = c2.next;
            curr = curr.next; 
            
        }
        if(carry == 1){
            curr.next = new ListNode(1);
        }
        return ans.next ;
    }
}