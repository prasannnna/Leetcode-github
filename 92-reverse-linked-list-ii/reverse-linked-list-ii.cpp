/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
ListNode* reverseLL(ListNode* middle) {
    ListNode* prev = NULL;
    ListNode* curr = NULL;
    ListNode* temp = middle;
    while(temp) {
        curr = temp->next;
        temp->next = prev;
        prev = temp;
        temp = curr;
    }
    return prev;
}
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* temp = head;
        ListNode* left_part = NULL;
        for(int i = 1; i < left; i++) {
            left_part = temp;
            temp = temp->next;
        }
        ListNode* middle = temp;
        for(int i = left; i < right; i++) {
            middle = middle->next;
        }
        ListNode* right_part = middle->next;
        middle->next = NULL;
        ListNode* reversed = reverseLL(temp);
        if(left_part) left_part->next = reversed;
        else head = reversed;
        temp->next = right_part;
        return head;
    }
};