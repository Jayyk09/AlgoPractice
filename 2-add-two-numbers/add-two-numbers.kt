/**
 * Example:
 * var li = ListNode(5)
 * var v = li.`val`
 * Definition for singly-linked list.
 * class ListNode(var `val`: Int) {
 *     var next: ListNode? = null
 * }
 */
class Solution {
    fun addTwoNumbers(l1: ListNode?, l2: ListNode?): ListNode? {
        var list1 = l1;
        var list2 = l2;

        var newHead = ListNode(0);
        var curr = newHead;
        var carry = 0;

        while (list1!= null || list2!=null || carry!=0){
            var sum = 0;

            if (list1!= null && list2!= null) {
                sum += list1.`val`;
                list1 = list1.next;
                sum += list2.`val`;
                list2 = list2.next;
            } else if (list2 != null && list1 == null) {
                sum += list2.`val`;
                list2 = list2.next;
            } else if (list1 != null && list2 == null) {
                sum += list1.`val`;
                list1 = list1.next;
            }

            sum += carry;
            carry = sum /10;
            var rem = sum % 10;
            var newNode = ListNode(rem);
            curr.next = newNode;
            curr = curr.next;
        }

        return newHead.next;
    }
}