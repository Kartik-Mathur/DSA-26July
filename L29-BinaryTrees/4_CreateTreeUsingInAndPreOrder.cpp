#include <iostream>
#include <queue>
using namespace std;

class node {
public:
	int data; // node ka data int maan lia hai abhi
	node* left, *right; // left and right child ke address yeh store krenge
	node(int d) {
		data = d;
		left = right = NULL;
	}
};

int pre[] = {8, 10, 1, 6, 4, 7, 3, 14, 13};
int k = 0;
node* createTree(int *in, int s, int e) {
	if (s > e) {
		return NULL;
	}

	// 1. Root node hum bana dete hai
	node* root = new node(pre[k]);
	k++;

	int i;
	for (int j = s; j <= e; ++j)
	{
		if (in[j] == root->data) {
			i = j;
			break;
		}
	}

	// 2. LST recursion ko bolo bana kar dede
	root->left = createTree(in, s, i - 1);
	root->right = createTree(in, i + 1, e);
	return root;
}


void levelOrderTraversal(node* root) {
	queue<node*> q;
	q.push(root);
	q.push(NULL);

	while (!q.empty()) {
		// queue mei address daala hai taaki jab left and right child ko insert krna ho
		// toh us address wali node par left and child ke address honge, integer daal deta agar
		// toh left and right child wali node nhi milti
		node* f = q.front();
		q.pop();

		if (f != NULL) { // If f is pointing to a valid address
			// 1. Print the data
			cout << f->data << " ";

			// 2. Left child hai toh insert kro in queue
			if (f->left != NULL) {
				// f->left is the address of left child node
				q.push(f->left);
			}

			// 3. Right child hai toh insert kro in queue
			if (f->right != NULL) {
				// f->right is the address of right child node
				q.push(f->right);
			}

		}
		else { // Agar f is NULL
			// 1. Print endl
			cout << endl;
			// 2. If queue is not empty push NULL again
			if (!q.empty()) {
				q.push(NULL);
			}
		}
	}
}

node* searchNode(node*root, int key) {
	// base case
	if (root == NULL) {
		return NULL;
	}

	// recursive case
	if (root->data == key) { // Agr root hi key ke barabar toh mill gaya return krdo root ko
		return root;
	}

	node* leftAns = searchNode(root->left, key);
	if (leftAns != NULL) { // iska mtlb left mei key mill gai
		return leftAns;
	}

	// Agar leftAns == NULL toh RST mei dekho ho skta hai waha ho
	node* rightAns = searchNode(root->right, key);
	return rightAns; // Agar right se ans aaya toh theek nhi aaya toh ab key nhi hai tree mei
}

int main() {
	int in[] = {1, 10, 4, 6, 7, 8, 3, 13, 14};
	int n = sizeof(in) / sizeof(int);

	node* root = createTree(in, 0, n - 1);

	levelOrderTraversal(root);
	node* ans = searchNode(root, 140);
	if (ans == NULL) {
		cout << "NOT FOUND\n";
	}
	else {
		cout << ans->data << "\n";
	}



	return 0;
}

















