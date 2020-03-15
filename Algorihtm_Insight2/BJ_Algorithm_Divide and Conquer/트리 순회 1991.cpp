
/* 2015112119 이현재 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <string.h>
#include <map>
#include <set>

using namespace std;

struct Tree {
	char key;
	Tree* l, * r;
	Tree(char k, Tree* ll, Tree* rr) {
		key = k; l = ll; r = rr;
	}
};

//struct node {
//	int key; double info;
//	struct node* l, * r;
//	node(int k, double i, struct node* ll, struct node* rr)  // node 생성시 초기값 부여 가능 
//	{
//		key = k; info = i; l = ll; r = rr;
//	};
//};
//struct node* head, * z; // z : List의 끝을 대표하는 node pointer – NULL에 해당

class Treeclass {
public:
	Tree* head, * z;
	Treeclass(char max = ' ') {
		z = new Tree(' ', 0, 0);
		head = new Tree(max, z, z);
	}~Treeclass() {

	}

	void insert(char a, char b, char c) {
		Tree* p, * x;
		p = head; x = head->r;

		if (x->key == ' ') {

			x = new Tree(a, z, z);
			p->r = x;
			p = p->r;

			x = new Tree(b, z, z);
			p->l = x;

			x = new Tree(c, z, z);
			p->r = x;

		}
		else {

			while (x != z) {
				if (x->key < a) {
					x = x->r;
				}
				else x = x->l;
			}

			x->l = new Tree(b, z, z);
			x->r = new Tree(c, z, z);

		}

	}


	void inprintTree(Tree* t) {
		if (t != z) {
			inprintTree(t->l);
			cout << t->key;
			inprintTree(t->r);
		}
	}

	void postprintTree(Tree* t) {
		if (t != z) {
			postprintTree(t->l);
			postprintTree(t->r);
			cout << t->key;
		}
	}

	void freeprintTree(Tree* t) {
		if (t != z) {
			cout << t->key;
			freeprintTree(t->l);
			freeprintTree(t->r);
		}
	}
};

int main() {
	int number;
	char ta, tb, tc;
	cin >> number;

	Treeclass TC;

	for (int i = 0; i < number; i++) {
		cin >> ta >> tb >> tc;
		TC.insert(ta, tb, tc);
	}

	TC.inprintTree(TC.head->r);
	TC.freeprintTree(TC.head->r);
	TC.postprintTree(TC.head->r);

}