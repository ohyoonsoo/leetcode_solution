#include <iostream>


/* Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* node { head };
        ListNode* frontTarget { head };
        int length { 0 };
        while (node != nullptr) {
            node = node->next;
            length++;
        }

        if (length == n) {
            if (length == 1) {
                return nullptr;
            }
            else {
                return head->next;
            }
        }

        //find the front node of target
        for (int i { 0 }; i < length - n - 1; i++) {
            frontTarget = frontTarget->next;
        }
        frontTarget->next = frontTarget->next->next;
        return head;
    }
};


int main(int argc, char *argv[]) {
    Solution solution;
    ListNode* head = new ListNode();
    ListNode* node = head;
    int input;
    int n;
    std::cout << "enter the node value(terminate if negative)" << std::endl;
    while (true) {
        std::cin >> input;
        if (input < 0) {
            break;
        }
        node->next = new ListNode(input);
        node = node->next;
    }
    std::cout << "enter n" << std::endl;
    std::cin >> n;
    head = solution.removeNthFromEnd(head->next, n);
    while(head != nullptr) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}