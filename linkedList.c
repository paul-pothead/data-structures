#include <stdio.h>
#include <stdlib.h>

typedef struct List {
	int head;
	struct List* tail;
} List;

List* nil() {
	List* ls = malloc(sizeof(List));
	ls->tail = 0;
	return ls;
}

List* cons(int newHead, List* tail) {
	List* newList = malloc(sizeof(List));
	newList->head = newHead;
	newList->tail = tail;
	return newList;
}


List* map(int (*func)(int), List* ls) {
	if (ls->tail) {
		return cons(func(ls->head), map(func, ls->tail));
	} else {
		return nil();
	}
}

List* filter(int (*func)(int), List* ls) {
	if (ls->tail) {
		if (func(ls->head)) {
			return cons(ls->head, filter(func, ls->tail));
		} else {
			return filter(func, ls->tail);
		}
	} else {
		return nil();
	}
}

int get(int index, List* ls) {
	if (!index) {
		return ls->head;
	} else {
		return get(index-1, ls->tail);
	}
}

List* del(int index, List* ls) {
	if (!index) {
		return ls->tail;
	} else {
		return cons(ls->head, del(index-1, ls->tail));
	}
}

List* insert(int index, int val, List* ls) {
	if (!index) {
		return cons(val, ls);
	} else {
		return cons(ls->head, insert(index-1, val, ls->tail));
	}
}

List* range(int start, int end, int step) {
	if (start >= end) {
		return nil();
	} else {
		return cons(start, range(start+step, end, step));
	}
}

void printls(List* ls) {
	if (ls->tail) {
		printf("%d ", ls->head);
		printls(ls->tail);
	}
}
		
	
int mult2(int x) {
	return x*2;
}

int even(int x) {
	if (x % 2 == 0) {
		return 1;
	} else {
		return 0;
	}
}

int main() {
	List* ls = range(0, 12, 1);
	printf("Original list: ");
	printls(ls);
	printf("\n");
	ls = filter(&even, ls);
	printf("Even: ");
	printls(ls);
	printf("\n");
	ls = map(&mult2, ls);
	printf("*2: ");
	printls(ls);
	printf("\n");
	ls = insert(2, 666, ls);
	printf("666 inserted: ");
	printls(ls);
	printf("\n");
	return 0;
}








