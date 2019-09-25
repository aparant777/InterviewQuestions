/*
* This class serves as a general test bench for testing 
* and working with Linked List's utility functions and 
* 
*	Available functions are:
*	1. Displays the list
*	2. Removes duplicates without hashing
*	3. Removes duplicates with hashing
*	4. Get's the nth element iteratively
*	5. Get's the nth element recursively
*	6. Delete's a node
*	7. Get's the length of the list
*	8. Returns the number of times a value occurs
*	9. Get nth node from last
*	10. Reverse the list
*	11. Returns if the list is palindrome or not
*	12. Returns the node from where the list is circular
*	13. Returns the smallest/highest element in the list
*
*/

#include<iostream>
#include<map>
#include<stack>

using namespace std;

class Node {
	Node* next;
	int data;

public:
	void AddNode(int data) {
		Node* end = new Node(data);
		Node* currentNode = this;
		while (currentNode->next != nullptr) {
			currentNode = currentNode->next;
		}
		currentNode->next = end;
	}

	/*Dsiplay's the list*/
	void DisplayList() {
		Node* currentNode = this;
		while (currentNode != nullptr) {
			cout << currentNode->data << "->";
			currentNode = currentNode->next;
		}
		cout << endl;
	}

	/*remove duplicates without using any additional space for hashmap*/
	void RemoveDuplicates_SpaceSave() {
		Node* currentNode = this;	//head will be here
		while (currentNode != nullptr) {
			Node* n = currentNode;
			while (n->next != nullptr) {
				if (currentNode->data == n->next->data) {
					n->next = n->next->next;
				}
				else {
					n = n->next;
				}
			}
			currentNode = currentNode->next;
		}
	}

	/*remove duplicates by using hashtables for saving computations*/
	void RemoveDuplicates_ComputationSave() {

		map<int, Node*> hashtable;
		Node* currentNode = this;

		while (currentNode != nullptr) {
			for (auto iterator = hashtable.find(currentNode->data); iterator != hashtable.end(); iterator++) {
				cout << "We found you\n";
			}
			currentNode = currentNode->next;
		}
	}

	//get the nth node in a list
	void GetElement(int number) {
		Node* currentNode = this;
		int count = 1;
		while (currentNode != nullptr) {
			if (count == number) {
				cout << currentNode->data;
				return;
			}
			else {
				currentNode = currentNode->next;
				++count;
			}
		}
		cout << "No element found\n";
	}

	//get the nth node in a list recursively
	void GetElementRecursively(Node* currentNode, int number) {
		static int count = 1;

		if (count == number) {
			cout << currentNode->data << endl;
			return;
		}
		else {
			if (currentNode != nullptr) {
				++count;
				GetElementRecursively(currentNode->next, number);
			}
		}
	}

	//delete a node from a linked list. (CHECK AGAIN)
	void DeleteNode(int data) {
		Node* currentNode = this;

		while (currentNode->next != nullptr) {
			if (currentNode->next->data == data) {
				Node* temp = currentNode->next;
				currentNode->next = currentNode->next->next;
				delete temp;
			}
			else {
				currentNode = currentNode->next;
			}
		}
	}

	//get length of linked list
	int GetLength() {
		Node* currentNode = this;
		int length = 0;
		while (currentNode != nullptr) {
			length++;
			currentNode = currentNode->next;
		}
		return length;
	}

	//get the number of times a value occurs
	int GetNumberofTimesValueOccurs(int data) {
		int count = 0;
		Node* currentNode = this;
		if (this == nullptr)
			return 0;
		while (currentNode != nullptr) {
			if (currentNode->data == data)
				count++;
			currentNode = currentNode->next;
		}
		return count;
	}

	//get the kth node from the end of the list
	Node* GetNodeFromLast(int k) {
		Node* p1 = this;
		Node* p2 = this;

		for (int i = 0; i < k; i++) {
			if (p1 == nullptr)
				return nullptr;
			p1 = p1->next;
		}

		while (p1 != nullptr) {
			p1 = p1->next;
			p2 = p2->next;
		}
		return p2;
	}

	//reverse a linked list
	void ReverseList() {
		if (this == nullptr)
			return;

		Node* previous = nullptr;
		Node* next = nullptr;
		Node* currentNode = this;

		while (currentNode != nullptr) {
			next = currentNode->next;
			currentNode->next = previous;
			previous = currentNode;
			currentNode = next;
		}

		*this = *previous;
	}

	//check if the list is palindrome
	bool isPalindrome() {
		//slow/fast runner and push 
		Node* fast = this;	//head
		Node* slow = this;	//head
		stack<int> sampleStack = stack<int>();	//stack to store the first half of the list

		while (fast != nullptr && fast->next != nullptr) {

			//push the slow pointer
			sampleStack.push(slow->data);

			//incrent the pointers
			slow = slow->next;
			fast = fast->next->next;
		}

		//check for odd or even length

		//if odd, fast != null

		if (fast != nullptr) {
			slow = slow->next;
		}
		//if even, fast = null

		//pop and check
		while (slow != nullptr) {
			if (slow->data != sampleStack.top()) {
				return false;
			}
			sampleStack.pop();
			slow = slow->next;
		}
		return true;
	}

	//return the node from where the list is circular
	Node* GetCircularNode() {		
		Node* head;
		Node* slow = head;
		Node* fast = head;

		while (fast != nullptr && fast->next != nullptr) {
			slow = slow->next;
			fast = fast->next->next;

			if (slow == fast)
				break;
		}

		if (fast == nullptr || fast->next == nullptr)
			return nullptr;

		slow = head;
		while (slow != fast) {
			slow = slow->next;
			fast = fast->next;
		}
		return fast;
	}

	//find the smallest number in the list
	void FindSmallest() {
		Node* currentNode = this;
		int smallestNumber = INT_MAX;
		int highestNumber = -INT_MIN;

		while (currentNode != nullptr) {
			if (currentNode->data < smallestNumber) {
				smallestNumber = currentNode->data;
			}
			if (currentNode->data > highestNumber) {
				highestNumber = currentNode->data;
			}
			currentNode = currentNode->next;
		}
		cout << "Smallest number is " << smallestNumber << endl;
		cout << "Highest number is " << highestNumber << endl;
	}

	/*delete duplicates in a list-without hashing*/
	void DeleteDuplicateNodes() {

		Node* currentNode = this;
		while (currentNode != nullptr) {
			Node* runner = currentNode;
			while (runner->next != nullptr) {
				if (runner->next->data == currentNode->data) {
					runner->next = runner->next->next;
				}
				else {
					runner = runner->next;
				}
			}
			currentNode = currentNode->next;
		}
	}

	Node(int data) : data(data) {}
};

//Test Bench
int main() {

	Node* n = new Node(10);
	n->AddNode(20);
	n->AddNode(30);
	n->AddNode(40);
	n->AddNode(40);
	n->AddNode(40);
	n->AddNode(50);
	n->AddNode(60);
	n->AddNode(80);
	n->AddNode(90);

	n->DeleteDuplicateNodes();

	system("pause");
}