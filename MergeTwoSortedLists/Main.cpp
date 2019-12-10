/* 
	LeetCode.com 
	Question #2: Add Two Numbers

	You are given two non-empty linked lists representing two non-negative integers.
	The digits are stored in reverse order and each of their nodes contain a single digit. 
	Add the two numbers and return it as a linked list.
	You may assume the two numbers do not contain any leading zero, except the number 0 itself.

	Example:

	Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
	Output: 7 -> 0 -> 8
	Explanation: 342 + 465 = 807.
*/
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(0) {}
	ListNode(int x, ListNode* y) : val(x), next(y) {}
};
bool isDoneSort(ListNode* current) {
	bool isDone = false;
	ListNode* tester = current;
	int first, second;

	first = tester->val;
	second = first;

	while (tester) {
		if (first > second) return false;
		else {
			tester = tester->next;
			first = second;
			second = tester->val;
		}
	}
	return true;
}
class Solution {
public:
	static ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode* currentNode;
		ListNode* returnNode;
		if (l1->val <= l2->val) {
			currentNode = new ListNode(l1->val);
			l1 = l1->next;
		}
		else {
			currentNode = new ListNode(l2->val);
			l2 = l2->next;
		}
		returnNode = &(*currentNode);
		while (l1 && l2) {

			if (l1->val <= l2->val) {
				currentNode->next = new ListNode(l1->val);
				l1 = l1->next;
			}
			else {
				currentNode->next = new ListNode(l2->val);
				l2 = l2->next;
			}
			currentNode = currentNode->next;
		}
		if (l1) {
			while (l1) {
				currentNode->next = new ListNode(l1->val);
				currentNode = currentNode->next;
				l1 = l1->next;
			}
		}
		if (l2) {
			while (l2) {
				currentNode->next = new ListNode(l2->val);
				currentNode = currentNode->next;
				l2 = l2->next;
			}
		}
		return returnNode;
	}
};
int main() {
	ListNode top = ListNode(1, &ListNode(9, &ListNode(6)));
	ListNode bottom = ListNode(2, &ListNode(15, &ListNode(5)));

	ListNode * answer = Solution::mergeTwoLists(&top, &bottom);

}