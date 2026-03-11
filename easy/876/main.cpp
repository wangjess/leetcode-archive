//https://leetcode.com/problems/middle-of-the-linked-list/description/
#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
};

// Helper function that creates a new node on the heap from value
// Makes that the new head
ListNode* pushFront(ListNode* head, int value) {
	ListNode* n = new ListNode(value);
	n->next = head;
	return n;
}

// Solution to LeetCode
ListNode* middleNode(ListNode* head) {
	ListNode* fast_ptr = head;
	ListNode* slow_ptr = head;

	while (fast_ptr && fast_ptr->next) {
		fast_ptr = fast_ptr->next->next;
		slow_ptr = slow_ptr->next;
	}

	return slow_ptr;
}

// Delete ListNodes that were created on the heap
void deleteList(ListNode* &head) {
	ListNode* tmp = head;
	while (head) {
		head = head->next;
		delete tmp;
		tmp = head;
	}
}

void check_answer(ListNode* a, ListNode* b) {
	if (a == b) {
		cout << "Equal\n";
	} else {
		cerr << "Failure\n";
	}
}

int main() {
	cout << "Init...\n";

	// Example 1
	ListNode* head = nullptr;
	head = pushFront(head, 5);
	head = pushFront(head, 4);
	head = pushFront(head, 3);
	head = pushFront(head, 2);
	head = pushFront(head, 1);

	// Solution to Example 1
	ListNode* solution_1 = head;
	solution_1 = head->next->next;

	// Example 2
	ListNode* head2 = nullptr;
	head2 = pushFront(head2, 6);
	head2 = pushFront(head2, 5);
	head2 = pushFront(head2, 4);
	head2 = pushFront(head2, 3);
	head2 = pushFront(head2, 2);
	head2 = pushFront(head2, 1);
	
	// Solution to Example 2
	ListNode* solution_2 = head2;
	solution_2 = head2->next->next->next;
	
	// Example 3 (edge-case)
	ListNode* head3 = nullptr;
	head3 = pushFront(head3, 2);
	head3 = pushFront(head3, 1);

	// Solution to Example 3
	ListNode* solution_3 = head3;
	solution_3 = head3->next;

	// Testing...
	ListNode* sol_ex_1 = middleNode(head);
	check_answer(sol_ex_1, solution_1);

	ListNode* sol_ex_2 = middleNode(head2);
	check_answer(sol_ex_2, solution_2);

	ListNode* sol_ex_3 = middleNode(head3);
	check_answer(sol_ex_3, solution_3);

	// Cleanup...
	deleteList(head);
	deleteList(head2);
	deleteList(head3);

	return 0;
}
