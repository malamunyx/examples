#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

struct node { 
	int elem;
	int order;
	struct node *next;
	struct node *prev;
};

struct queue {
	struct node sentinel;
};

void init_queue(struct queue *q) {
	q->sentinel.next = &q->sentinel;
	q->sentinel.prev = &q->sentinel;
	q->sentinel.elem = -1;
	q->sentinel.order = -1;
}

void enqueue(struct queue *q, struct node *n, int (*cmp)(int, int)) {
	struct node **cursor = &(q->sentinel.next);
	
	while (*cursor != &q->sentinel) {
		if (cmp(n->elem, (*cursor)->elem) < 0) {
			break;
		}
		cursor = &(*cursor)->next;
	}

	n->next = *cursor;
	n->prev = (*cursor)->prev;

	n->next->prev = n;
	n->prev->next = n;
}

void delete(struct queue *q, struct node *del) {
	/* Traversal not necessary */
	/*
	struct node **cursor = &(q->sentinel.next);
	
	while (*cursor != &q->sentinel && *cursor != del) {
		cursor = &(*cursor)->next;
	}

	if (*cursor == &q->sentinel) {
		return;
	}
	*/

	if (del == &q->sentinel)
		return;
	
	del->prev->next = del->next;
	del->next->prev = del->prev;

	//free(del);
}

void dequeue(struct queue *q) {
	delete(q, q->sentinel.next);
}

void print_pqueue(struct queue *q) {
	struct node **cursor = &(q->sentinel.next);

	while (*cursor != &q->sentinel) {
		printf("%d [ORD: %d]", (*cursor)->elem, (*cursor)->order);

		((*cursor)->next == &(q->sentinel)) ?
			printf("\tNEXT [SENTINEL]") :
			printf("\tNEXT [%d, ord %d]", (*cursor)->next->elem, (*cursor)->next->order);
		((*cursor)->prev == &(q->sentinel)) ?
			printf("\t\tPREV [SENTINEL]\n") :
			printf("\t\tPREV [%d, ord %d]\n", (*cursor)->prev->elem, (*cursor)->prev->order);
		cursor = &(*cursor)->next;
	}
}

struct node *init_node(int elem, int order) {
	struct node *tmp = malloc(sizeof(struct node));

	tmp->elem = elem;
	tmp->order = order;
	tmp->prev = NULL;
	tmp->next = NULL;

	return tmp;
}

int cmp_min(int a, int b) {
	return a - b;
}

int cmp_max(int a, int b) {
	return b - a;
}

int main(void) {
	int order = 0;

	struct node *a = init_node(5, ++order);
	struct node *b = init_node(3, ++order);
	struct node *c = init_node(3, ++order);
	struct node *d = init_node(4, ++order);
	struct node *e = init_node(2, ++order);
	struct node *f = init_node(1, ++order);
	struct node *g = init_node(3, ++order);
	struct node *h = init_node(3, ++order);

	struct queue q;
	init_queue(&q);

	enqueue(&q, a, cmp_max);
	enqueue(&q, b, cmp_max);
	enqueue(&q, c, cmp_max);
	enqueue(&q, d, cmp_max);
	enqueue(&q, e, cmp_max);
	enqueue(&q, f, cmp_max);
	enqueue(&q, g, cmp_max);
	enqueue(&q, h, cmp_max);

	print_pqueue(&q);

	puts("Deleting 4");
	sleep(1);

	delete(&q, d);
	print_pqueue(&q);

	for (int i = 0; i < 9; i++) {
	puts("Dequeueing");
	sleep(1);

	dequeue(&q);
	print_pqueue(&q);
	}

	free(a);
	free(b);
	free(c);
	free(d);
	free(e);
	free(f);
	free(g);
	free(h);

	return 0;
}
