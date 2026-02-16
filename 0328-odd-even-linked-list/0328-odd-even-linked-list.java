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
    public ListNode oddEvenList(ListNode head) {
        if (head == null) return null; // Edge case: empty list

        ListNode temp = head;
        int count = getIndex(head); // Get the total count of nodes

        // Arrays to store odd and even indexed node values
        int[] odd = new int[(count / 2) + (count % 2)];
        int[] even = new int[count / 2];
        int i = 1, od = 0, ev = 0;

        // Fill the odd and even arrays
        while (temp != null) {
            if (i % 2 != 0) {
                odd[od++] = temp.val; // Add to odd array
            } else {
                even[ev++] = temp.val; // Add to even array
            }
            temp = temp.next;
            i++;
        }

        // Rearrange the list with odd values followed by even values
        temp = head;
        for (int m = 0; m < odd.length; m++) {
            temp.val = odd[m];
            temp = temp.next;
        }
        for (int m = 0; m < even.length; m++) {
            temp.val = even[m];
            temp = temp.next;
        }

        return head; // Return the modified list
    }

    // Helper method to count the number of nodes in the list
    public static int getIndex(ListNode head) {
        ListNode temp = head;
        int count = 0;
        while (temp != null) {
            count++;
            temp = temp.next; // Move to the next node
        }
        return count;
    }
}
