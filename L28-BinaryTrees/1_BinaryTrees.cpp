#include <iostream>
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

int countNodes(node* root) {
	if (root == NULL) {
		return 0; // root nhi toh nodes bhi nhi ho skti
	}

	int lstNodesCount = countNodes(root->left); // Recursion ko bolo LST ki nodes count laakar de
	int rstNodesCount = countNodes(root->right); // Recursion ko bolo RST ki nodes count laakar de

	return 1 + lstNodesCount + rstNodesCount; // 1 is added for root node ka count..
}

int height(node* root) {
	if (root == NULL) {
		return 0; // tree nhi hai toh height bhi nhi hogi..
	}

	int lstKiHeight = height(root->left); // LST ki height recursion se maanglo
	int rstKiHeight = height(root->right); // LST ki height recursion se maanglo
	// Poore tree ki height hogi LST aur RST ki height ka max + 1
	int ans = max(lstKiHeight, rstKiHeight) + 1;
	return ans;
}

int diameter(node* root) {
	if (root == NULL) {
		return 0; // Tree hi nhi toh diameter bhi nhi
	}

	// Case 1: root node ke through diameter hota hai lstHeight + rstHeight
	int lstHeight = height(root->left);   // lst ki height ke liye height function use krlo
	int rstHeight = height(root->right);  // rst ki height ke liye height function use krlo
	int op1 = lstHeight + rstHeight; // Yeh vo dia hai jo root ke through hota hua jaata hai
	// Case 2: ho skta hai dia exist krta ho LST ke andar, choti problem ho gai toh bolo rec ko
	int op2 = diameter(root->left); // LST mei jaakar maximum diameter laakar dede (ASSUMPTION)

	// Case 3: ho skta hai dia exist krta ho RST ke andar, choti problem ho gai toh bolo rec ko
	int op3 = diameter(root->right); // RST mei jaakar maximum diameter laakar dede (ASSUMPTION)

	// Pehle op2 and op3 ka maximum nikal lo and then us result ka max lelo with op1
	// toh teeno ka max aa jaega... why? because max takes only two arguments at a time...
	return max(op1 ,  max(op2, op3)  );

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
	cout << "Nodes count: " << countNodes(root) << endl;
	cout << "Height     : " << height(root) << endl;
	cout << "Diameter   : " << diameter(root) << endl;


	return 0;
}
















