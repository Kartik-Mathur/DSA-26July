#define node ListNode
class Solution {
public:

	void reverseLL(node* head) {
		node* p = NULL;
		node* c = head;
		node* n;
		while (c) {
			n = c->next;
			c->next = p;
			p = c;
			c = n;
		}
	}

	int lengthLL(node* head) {
		int cnt = 0;
		while (head) {
			head = head->next;
			cnt++;
		}
		return cnt;
	}

	node* reverseKGroup(node* head, int k) {
		if (k == 1 || head == NULL) return head;
		node* dummy = new node(-1);
		dummy->next = head;

		int len = lengthLL(head);
		node* prev = dummy, *hd, *td, *n;
		n = head;
		while (len >= k) {
			hd = n;
			td = hd;
			for (int i = 0; i < k - 1; ++i)
			{
				td = td->next;
			}

			n = td->next;
			td->next = NULL;
			reverseLL(hd);
			prev->next = td;
			hd->next = n;

			prev = hd;
			len -= k;
		}
		return dummy->next;
	}
};









