#include <iostream>
#include <queue>
using namespace std;

class node {
public:
	int data;
	node* left, *right;
	node(int d) {
		data = d;
		left = right = NULL;
	}
};
// Bhai pehli baari root toh NULL hoga, jab pehla data insert hoga toh root NULL todhi rhega
// Root ka new address return krna padega thus insertInBST has to return address of root node...
// Iska kaam hai data ki sahi position dhoondo and usse waha attach krdo as node
node* insertInBST(node* root, int data) {
	if (root == NULL) {
		root = new node(data);
		return root;
	}

	if (root->data > data) {
		root->left = insertInBST(root->left, data);
		return root;
	}
	else {
		root -> right = insertInBST(root->right, data);
		return root;
	}
}

// Yeh user se input leta rhega ek ek krke and vo saare input pass krega insertInBST ko taaki data
// as a node attach hota rhey in Tree
node* buildBST() {
	node* root = NULL;

	int data;
	cin >> data;

	while (data != -1) {
		// Jo bhi mera current tree hai usse le jaa aur data ko insert krde as node us tree ke andar
		// and merko new tree ki root ka address laakar dedo taaki I can store it
		root = insertInBST(root, data);

		cin >> data;
	}

	return root;
}

void preorder(node* root) {
	if (root == NULL) {
		return; // tree hi nhi toh print kya krunga vapis jaao
	}

	cout << root->data << " "; // root ko meine print kr diya
	preorder(root->left);// LST ka kaam recursion krega
	preorder(root->right); // RST ka kaam recursion krega
}

void inorder(node* root) {
	if (root == NULL) {
		return; // tree hi nhi toh print kya krunga vapis jaao
	}

	inorder(root->left);// LST ka kaam recursion krega
	cout << root->data << " "; // root ko meine print kro jab LST print ho jaaye
	inorder(root->right); // RST ka kaam recursion krega
}

void postorder(node* root) {
	if (root == NULL) {
		return; // tree hi nhi toh print kya krunga vapis jaao
	}

	postorder(root->left);// LST ka kaam recursion krega
	postorder(root->right); // RST ka kaam recursion krega
	cout << root->data << " "; // root ko meine print kro jab LST and RST dono print ho jaaye
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

class Tuple {
public:
	bool isBST;
	int mi, mx;
};

Tuple isBST(node* root) {
	// base case
	if (root == NULL) {
		Tuple ans;
		ans.isBST = true;
		ans.mi = INT_MAX;
		ans.mx = INT_MIN;

		return ans;
	}

	// recursive case
	Tuple left = isBST(root->left);
	Tuple right = isBST(root->right);

	Tuple ans;
	if (left.isBST == true and right.isBST == true and root->data >= left.mx and root->data <= right.mi) {
		ans.isBST = true;
	}
	else ans.isBST = false;
	ans.mx = max(root->data , max(left.mx, right.mx));
	ans.mi = min(root->data, min(left.mi, right.mi));

	return ans;
}

bool kyaBSTHai(node* root, int mi = INT_MIN, int mx = INT_MAX) {
	// base case
	if (root == NULL) {
		return true;
	}

	if (root->data >= mi and root->data <= mx
	        and kyaBSTHai(root->left, mi, root->data) == true
	        and kyaBSTHai(root->right, root->data, mx) == true) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	// 8 3 10 1 6 14 4 7 13 -1
	node* root = buildBST();
	inorder(root);
	cout << endl;
	Tuple ans = isBST(root);
	if (ans.isBST) cout << "BST hai\n";
	else cout << "BST nahi hai\n";

	if (kyaBSTHai(root) == true) cout << "BST hai\n";
	else cout << "BST nahi hai\n";




	return 0;
}
















