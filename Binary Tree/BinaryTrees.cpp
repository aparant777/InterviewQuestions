/*
* This class serves as a general test bench for testing
* and working with Binary Tree'ss utility functions and
*
*	Available functions are:
*	1. prints the left view of the tree
*	2. prints the right view of the tree
*	3. Inorder traversal
*	4. Preorder traversal
*	5. Postorder traversal
*	6. Returns the depth of the tree
*	7. Check's if 2 trees are identical
*	8. Returns the count of leaf nodes
*	9. Check's if 2 trees are symmetrical
*	10. Create a Binary Search tree from a sorted array
*	11. Returns the lowest node in a tree
*/


#include<iostream>
using namespace std;

class TreeNode {

public:
	int data;
	TreeNode* left;
	TreeNode* right;


	TreeNode(int data) : data(data) {}

	//prints the left view of the tree
	void PrintLeftViewOfBinaryTree() {
		TreeNode* currentNode = this;
		while (currentNode != nullptr) {
			cout << currentNode->data << " -> ";
			currentNode = currentNode->left;
		}
		cout << endl;
	}

	//prints the right view of the tree
	void PrintRightViewOfBinaryTree() {
		TreeNode* currentNode = this;
		while (currentNode != nullptr) {
			cout << currentNode->data << " -> ";
			currentNode = currentNode->right;
		}
		cout << endl;
	}

	//Inorder traversal (Left-Visit-Rright)
	void Inorder(TreeNode* node) {
		
		TreeNode* currentNode = node;
		if (currentNode == nullptr)
			return;

		Inorder(currentNode->left);
		cout << currentNode->data << " -> ";
		Inorder(currentNode->right);
	}

	//Preorder traversal (Visit-Left-Right)
	void Preorder(TreeNode* node) {

		TreeNode* currentNode = node;
		if (node == nullptr)
			return;
		cout << currentNode->data << " -> ";
		Preorder(currentNode->left);
		Preorder(currentNode->right);
	}

	//Preorder traversal (Left-Right-Visit)
	void PostOrder(TreeNode* node) {
		
		TreeNode* currentNode = node;
		if (node == nullptr)
			return;
		PostOrder(currentNode->left);
		PostOrder(currentNode->right);
		cout << currentNode->data << " -> ";
	}

	//Depth of the tree
	int Depth(TreeNode* node) {
		if (node == nullptr)
			return 0;


		int leftDepth = Depth(node->left);
		int rightDepth = Depth(node->right);

		if (leftDepth > rightDepth)
			return leftDepth + 1;
		else
			return rightDepth + 1;
	}

	//check if 2 trees are identical
	bool IfIdenticalTrees(TreeNode* root1, TreeNode* root2) {
		if (root1 == nullptr && root2 == nullptr)
			return true;

		if (root1 != nullptr && root2 != nullptr) {
			if (root1->data == root2->data) {
				return (
					(IfIdenticalTrees(root1->left, root2->left)) &&
					(IfIdenticalTrees(root1->right, root2->right)));
			}
		}
		return false;
	}

	//returns all the leaf nodes of a tree
	int GetLeafNodesCount(TreeNode* root) {
		if (root == nullptr)
			return 0;
		if (root->left == nullptr && root->right == nullptr)
			return 1;
		else {
			return (GetLeafNodesCount(root->left)) + (GetLeafNodesCount(root->right));
		}
	}

	//check if 2 trees are symmetric
	bool IsSymmetric(TreeNode* root1, TreeNode* root2) {
		if (root1 == nullptr && root2 == nullptr)
			return true;
		if (root1 != nullptr && root2 != nullptr) {
			if (root1->data == root2->data) {
				return (root1->left, root2->right) && (root1->right, root2->left);
			}
		}
	}

	//create a minimal height binary tree from a sorted array
	TreeNode* CreateBST(int array[], int start, int end) {
		if (start > end)
			return nullptr;

		int mid = (end + start) / 2;
		TreeNode* n = new TreeNode(array[mid]);

		n->left = CreateBST(array, start, mid - 1);
		n->right = CreateBST(array, mid + 1, end);

		return n;
	}

	//find the lowest value in a tree
	TreeNode* FindLowest(TreeNode* root) {
		if (root == nullptr)
			return nullptr;
		while (root != nullptr) {
			root = root->left;
		}
		return root;
	}
};


int main() {

	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);

	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);

	cout << "Depth is " << root->Depth(root) << endl;

	return 0;
	system("pause");
}