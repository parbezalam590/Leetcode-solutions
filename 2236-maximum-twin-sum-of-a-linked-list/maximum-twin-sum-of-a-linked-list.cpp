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
    int pairSum(ListNode* head) {
        vector<int> nums;
        ListNode *temp = head;
        while(temp != NULL) {
            nums.push_back(temp->val);
            temp = temp -> next;
        }

        int low = 0 ;
        int high = nums.size() - 1;
        int sum = INT_MIN;
        while(low < high) {
            sum = max(sum , nums[high] + nums[low]);
            low++;
            high--;
        }
        return sum;
        
    }
};