#include<iostream>
#include<algorithm>
using namespace std;
typedef struct node* Tree;
struct node {
	Tree left, right;
	int data, height;
};
Tree NewNode(int x) {
	Tree p = new node;
	p->data = x;
	p->left = p->right = NULL;
	p->height = 0;
	return p;
}
int getHeight(Tree T) {
	return T == NULL ? 0 : T->height;
}
void reHeight(Tree T) {
	T->height = max(getHeight(T->left), getHeight(T->right)) + 1;
}
int getBF(Tree T) {
	return getHeight(T->left) - getHeight(T->right);
}
Tree right_right_rotation(Tree T) {
	Tree K;
	K = T->right;
	T->right = K->left;
	K->left = T;
	reHeight(T);
	reHeight(K);
	return K;
}
Tree left_left_rotation(Tree T) {
	Tree K;
	K = T->left;
	T->left = K->right;
	K->right = T;
	reHeight(T);
	reHeight(K);
	return K;
}
Tree right_left_rotation(Tree T) {
	T->right = left_left_rotation(T->right);
	return right_right_rotation(T);
}
Tree left_right_rotation(Tree T) {
	T->left = right_right_rotation(T->left);
	return left_left_rotation(T);
}
Tree Insert(Tree T, int V) {
	if (!T) {
		T = NewNode(V);
	}
	else {
		if (V > T->data) {
			T->right = Insert(T->right, V);
			if (getBF(T) == -2) {
				if (T->right->data > V) {
					T = right_left_rotation(T);
				}
				else {
					T = right_right_rotation(T);
				}
			}
		}
		else if (V < T->data) {
			T->left = Insert(T->left, V);
			if (getBF(T) == 2) {
				if (T->left->data > V) {
					T = left_left_rotation(T);
				}
				else {
					T = left_right_rotation(T);
				}
			}
		}
	}
	reHeight(T);
	return T;
}
int main() {
	int n;
	cin >> n;
	Tree T = NULL;
	for (int i = 0; i < n; i++) {
		int tnode;
		scanf("%d", &tnode);
		T = Insert(T, tnode);
	}
	printf("%d", T->data);
	return 0;
}