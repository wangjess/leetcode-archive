//https://leetcode.com/problems/remove-duplicates-from-sorted-list/?difficulty=EASY
#include <iostream>
#include <cassert>

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

// Compares two LinkedLists
bool linkedListEqual(ListNode* a, ListNode* b) {
	while (a && b) {
		if (a->val != b->val) {
			return false;
		} else {
			a = a->next;
			b = b->next;
		}
	}

	return a == nullptr & b == nullptr;
}

// Solution to LeetCode
// O(n) time complexity
// O(1) space
ListNode* deleteDuplicates(ListNode* head) {
	if (!head) { 
		return head; 
	}

	ListNode* true_head = head;
	ListNode* next = head->next;

	while (next != nullptr) {
		if (head->val == next->val) {
			head->next = next->next;

			ListNode* del = next;	// Save the location of the duplicate node
			next = next->next;
			delete del;				// Delete the duplicate node
		} else {
			head = next;
			next = next->next;
		}
	}

	return true_head;
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

int main() {
	// Example 1
	ListNode* head1 = nullptr;
	head1 = pushFront(head1, 2);
	head1 = pushFront(head1, 1);
	head1 = pushFront(head1, 1);

	ListNode* ex1_sol = nullptr;
	ex1_sol = pushFront(ex1_sol, 2);
	ex1_sol = pushFront(ex1_sol, 1);

	// Example 2
	ListNode* head2 = nullptr;
	head2 = pushFront(head2, 3);
	head2 = pushFront(head2, 3);
	head2 = pushFront(head2, 2);
	head2 = pushFront(head2, 1);
	head2 = pushFront(head2, 1);

	ListNode* ex2_sol = nullptr;
	ex2_sol = pushFront(ex2_sol, 3);
	ex2_sol = pushFront(ex2_sol, 2);
	ex2_sol = pushFront(ex2_sol, 1);

	// Testing...
	deleteDuplicates(head1);
	deleteDuplicates(head2);

	assert(linkedListEqual(head1, ex1_sol) == true);
	assert(linkedListEqual(head2, ex2_sol) == true);

	return 0;
}
