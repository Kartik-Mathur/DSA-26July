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

// Tree mei hum kabhi -1 data nhi daalte
node* createTree() {
	// 1. root ka kaam mera
	int data;
	cin >> data; // meine user se root ke data ka input le lia....
	if (data == -1) {
		return NULL; // iska mtlb tree ki root node hi nhi ho skti
	}

	node* root = new node(data);
	// 2. LST ka kaam recursion krega: ASSUMPTION
	root->left = createTree(); // LST Bana aur LST ki root ka address return krde..
	// 3. RST ka kaam recursion krega: ASSUMPTION
	root->right = createTree(); // RST bana aur RST ki root ka address return krde..
	// 4. return kr dunga root ka address
	return root; // jab mei bade tree ki root ko return kr rha, toh recursion bhi chote tree ko
	// bana kar uski root ka address return krega..
}


// Traversal: PRE-ORder
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

int main() {
	// 8 10 1 -1 -1 6 4 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
	node* root = createTree();
	preorder(root);
	cout << endl;
	inorder(root);
	cout << endl;
	postorder(root);
	cout << endl;
	levelOrderTraversal(root);



	return 0;
}

















