/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    
    public int length(ListNode head){
        int l = 0;
        while(head != null){
            l++;
            head = head.next;
        }
        
        return l;
    }
    public ListNode[] splitListToParts(ListNode head, int k) {
        ListNode nodes[] = new ListNode[k];
        
        int length = length(head);
        
        int perNode = length / k;
        int extra = length % k;
        int i = 0;
        ListNode prev = null;
        
        while(length > 0){
            int thisNode = perNode + ((extra != 0) ? 1 : 0);
            length = length - thisNode;
            
            if(extra != 0)
            extra--;
            
            nodes[i++] = head;
            
            while(thisNode-- > 0){
                prev = head;
                head = head.next;
            }
            prev.next = null;
        }
        
        return nodes;
    }
}