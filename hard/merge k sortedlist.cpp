
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue<
            ListNode*,
            vector<ListNode*>,
            decltype([](ListNode* a, ListNode* b) {
                return a->val > b->val;
            })
        > pq;

        // Insert first node of every list
        for (auto node : lists) {
            if (node != NULL) {
                pq.push(node);
            }
        }

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (!pq.empty()) {

            // Get smallest node
            ListNode* curr = pq.top();
            pq.pop();

            // Attach it to result
            tail->next = curr;
            tail = tail->next;

            // Insert next node from same list
            if (curr->next != NULL) {
                pq.push(curr->next);
            }
        }

        return dummy.next;
    }
};
