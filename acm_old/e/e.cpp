#include<cstdio>

class SegmentTree{
private :
	struct Node{
		int left, right, sum, push;
		Node *child[2];

		Node() : sum(0), push(0) {
			child[0] = child[1] = NULL;
		}
	};

	int n;
	Node *root;

	void Update(Node *now) {
		now->sum = 0;
		for (register int i = 0; i < 2; i++) {
			if (now->child[i]) {
				now->sum += now->child[i]->sum;
			}
		}
	}

	void PushDown(Node *now, int left, int right) {
		if (!now->push) {
			return;
		}
		int mid = (left + right) >> 1;
		if (!now->child[0]) {
			now->child[0] = new Node();
			now->child[0]->len = mid - left + 1;
		}
		if (!now->child[1]) {
			now->child[1] = new Node();
			now->child[1]->len = right - mid;
		}
		for (register int i = 0; i < 2; i++) {
			now->child[i]->push += now->push;
			now->child[i]
		}
	}

	void AddVal(Node *now, int left, int right, int l, int r) {
		if (left >= l && right <= r) {
			now->push++;
			now->sum += now->len;
			return;
		}
		PushDown(now);
	}

	//int Query(Node *now)

public :


};

int main() {}