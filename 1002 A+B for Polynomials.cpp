#include<iostream>
#include<cstdlib>
using namespace std;
typedef struct Lnode* List, * PtrL;
struct Lnode {
	double c;
	double e;
	List next;
};
List NewNode(double c, double e) {
	List T = (List)malloc(sizeof(struct Lnode));
	T->c = c;
	T->e = e;
	T->next = NULL;
	return T;
}
List Calc(List A, List B) {
	List T = (List)malloc(sizeof(struct Lnode));
	PtrL Pt = T;
	PtrL Pa = A->next;
	PtrL Pb = B->next;
	int count = 0;
	T->next = NULL;
	while (Pa && Pb) {
		if (Pa->e > Pb->e) {
			Pt->next = NewNode(Pa->c, Pa->e);
			Pa = Pa->next;
			Pt = Pt->next;
		}
		else if (Pa->e < Pb->e) {
			Pt->next = NewNode(Pb->c, Pb->e);
			Pb = Pb->next;
			Pt = Pt->next;
		}
		else {
			Pt->next = NewNode(Pa->c + Pb->c, Pa->e);
			Pa = Pa->next;
			Pb = Pb->next;
			Pt = Pt->next;
		}
		if (Pt->c != 0) {
			count++;
		}
	}
	if (Pa && !Pb) {
		Pt->next = Pa;
		while (Pt->next) {
			count++;
			Pt = Pt->next;
		}
	}
	if (!Pa && Pb) {
		Pt->next = Pb;
		while (Pt->next) {
			count++;
			Pt = Pt->next;
		}
	}
	cout << count;
	return T;
}
void Show(List T) {
	PtrL p = T->next;
	while (p) {
		if (p->c != 0) {
			printf(" %.f %.1f", p->e, p->c);
		}
		p = p->next;
	}
}
int main() {
	freopen("Text.txt", "r", stdin);
	List A = (List)malloc(sizeof(struct Lnode));
	List B = (List)malloc(sizeof(struct Lnode));
	PtrL PtrA = A;
	PtrL PtrB = B;
	A->next = NULL;
	B->next = NULL;
	int NA, NB;
	double e, c;
	cin >> NA;
	for (int i = 0; i < NA; i++) {
		cin >> e >> c;
		PtrA->next = NewNode(c, e);
		PtrA = PtrA->next;
	}
	cin >> NB;
	for (int i = 0; i < NB; i++) {
		cin >> e >> c;
		PtrB->next = NewNode(c, e);
		PtrB = PtrB->next;
	}
	Show(Calc(A, B));
	return 0;
}