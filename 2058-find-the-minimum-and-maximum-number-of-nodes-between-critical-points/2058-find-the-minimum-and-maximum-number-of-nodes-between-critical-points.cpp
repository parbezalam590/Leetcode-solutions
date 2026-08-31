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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans = {INT_MAX, INT_MIN};

        if (head == nullptr || head->next == nullptr || head->next->next == nullptr)
            return {-1, -1};

        int idx = 2;

        ListNode* prev = head;
        head = head->next;

        int first = -1;
        int consec = -1;

        while (head && head->next) {

            if ((head->val > prev->val && head->val > head->next->val) ||
                (head->val < prev->val && head->val < head->next->val)) {

                if (first == -1) {
                    first = consec = idx;
                } 
                else {
                    ans[0] = min(ans[0], idx - consec);
                    ans[1] = max(ans[1], idx - first);
                    consec = idx;
                }
            }

            idx++;
            prev = head;
            head = head->next;
        }

        if (first == consec)
            return {-1, -1};

        return ans;
    }
};