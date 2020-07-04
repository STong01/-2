#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}node, *linklist;

linklist creat(linklist head)
{
	node *r, *s;
	int a;
	r = (linklist)malloc(sizeof(node));
	head = r;
	scanf("%d", &a);
	while (a != 0)
	{
		s = (node*)malloc(sizeof(node));
		s->data = a;
		r->next = s;
		r = s;
		printf("please input a data:");
		scanf("%d", &a);
	}
	r->next = NULL;
	return head;
}

int length(linklist l)
{
	linklist p = l->next;
	int i = 1;
	while (p)
	{
		i++;
		p = p->next;
	}
	return i;
}

linklist mergel(linklist A, linklist B)
{
	int m, n;
	node *p, *q, *s, *t;
	linklist C;
	p = A->next;
	q = B->next;
	m = length(A);
	n = length(B);
	C = A;
	if (m < n)
	{
		p = B->next;
		q = A->next;
		C = B;
	}

	while (p && q)
	{
		s = p->next;
		p->next = q;
		if (s)
		{
			t = q->next;
			q->next = s;
		}
		p = s;
		t = q->next;
		q = t;
	}
	return C;
}

linklist sort(linklist L)
{
	linklist p, q, min;
	int temp;
	p = L;
	while (p = p->next)
	{
		q = min = p;
		while (q = q->next)
		{
			if (q->data < min->data)
				min = q;
		}
		if (min != p)
		{
			temp = p->data;
			p->data = min->data;
			min->data = temp;
		}
	}
	return L;
}

linklist Delete(linklist l, int index)
{
	linklist p, t;
	int cx = 1;
	p = l;
	t = p;
	if (index < length(l))
	{
		while (p && (cx<index))
		{
			t = p;
			p = p->next;
			cx++;
		}
		t->next = p->next;
	}
	else
		printf("input indext error");
	return l;
}

linklist Delete_element(linklist l, int data)
{
	linklist p;
	p = l;
	if (p->next)
	{
		while (p->next->data != data)
		{
			p = p->next;
		}
		p->next = p->next->next;
	}
	else
		printf("don't faind the element");
	return l;
}

linklist display(linklist l)
{
	linklist p;
	printf("new linklist:\n");
	p = l->next;
	while (p)
	{
		printf("%d\n", p->data);
		p = p->next;
	}
	return l;
}

int main()
{
	linklist p, q, A, B, C, D;
	int indexs;
	int datas;
	char name;
	int cmd;
	printf("Creat linklist A:\n");
	printf("please input a data:");
	A = 0;
	A = creat(A);
	printf("Creat linklist B:\n");
	printf("please input a data:");
	B = 0;
	B = creat(B);
	C = mergel(A, B);
	printf("linklist C\n");
	p = C->next;
	while (p)
	{
		printf("%d\n", p->data);
		p = p->next;
	}
	D = C;
	sort(D);
	printf("linklist D:\n");
	q = D->next;
	while (p)
	{
		printf("%d\n", q->data);
		q = q->next;
	}
	printf("\nplease input 0 or 1 \n");
	scanf("%d", &cmd);
	if (cmd == 0)
	{
		printf("please input linklist name \n");
		fflush(stdin);
		scanf("%c", &name);
		printf("please input index \n");
		scanf("%c", &indexs);
		fflush(stdin);
		if (name == 'A')
		{
			Delete(A, indexs);
			display(A);
		}
		else if (name == 'B')
		{
			Delete(B, indexs);
			display(B);
		}
		else if (name == 'C')
		{
			Delete(C, indexs);
			display(C);
		}
		else if (name == 'D')
		{
			Delete(D, indexs);
			display(D);
		}
		else
			printf("nameError");
	}
	else if (cmd == 1)
	{
		fflush(stdin);
		printf("please input linklist name\n");
		scanf("%c", &name);
		printf("\nplease input datas \n");
		scanf("%c", &datas);
		if (name == 'A')
		{
			Delete_element(A, datas);
			display(A);
		}
		else if (name == 'B')
		{
			Delete_element(B, datas);
			display(B);
		}
		else if (name == 'C')
		{
			Delete_element(C, datas);
			display(C);
		}
		else if (name == 'D')
		{
			Delete_element(D, datas);
			display(D);
		}
		else
			printf("name2Error");
	}
	else
		printf("cmdError");
	printf("\nOver\n");
	getchar();

	return 0;
}