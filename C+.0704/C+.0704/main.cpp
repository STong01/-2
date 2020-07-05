#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}node, *linklist;

//创建链表
linklist creat(linklist head, int length)
{
	node *r, *s;
	int a;
	r = (node*)malloc(sizeof(node));
	head = r;
	while (length != 0)
	{
		printf("please input a data:");
		scanf("%d", &a);
		s = (node*)malloc(sizeof(node));
		r->next = s;
		s->data = a;
		r = s;
		length--;
	}
	r->next = NULL;
	return head;
}

//计算链表长度
int length(linklist L)
{
	linklist p = L->next;
	int num = 1;
	while (p)
	{
		num++;
		p = p->next;
	}
	return num;
}

//合并两链表
linklist mergel(linklist A, linklist B)
{
	int m, n;
	node *p = 0;
	node *q = 0;
	node *s, *t;
	linklist C = 0;

	m = length(A);
	n = length(B);

	if (m >= n)
	{
		q = B->next;
		C = A;
		p = C->next;
	}
	
	if (m < n)
	{
		q = A->next;
		C = B;
		p = C->next;
	}

	while (p && q)
	{
		s = p->next;
		t = q->next;
		if (q)
		{
			p->next = q;
			q->next = s;
		}
		p = s;
		q = t;
	}
	return C;
}

//升序排序
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

//显示链表元素
linklist display(linklist L)
{
	linklist p;
	printf("new linklist:\n");
	p = L->next;
	while (p)
	{
		printf("%d  ", p->data);
		p = p->next;
	}
	printf("\n");
	return L;
}

int main()
{
	linklist p, q;

	int m, n;

	linklist A = 0;
	printf("Creat linklist A:\n");
	printf("please input A_sum:");
	scanf("%d", &m);
	A = creat(A, m);

	linklist B = 0;
	printf("Creat linklist B:\n");
	printf("please input B_sum:");
	scanf("%d", &n);
	B = creat(B, n);

	linklist C = 0;
	C = mergel(A, B);
	printf("linklist C\n");
	p = C->next;
	while (p)
	{
		printf("%d  ", p->data);
		p = p->next;
	}
	printf("\n");

	linklist D = 0;
	D = C;
	sort(D);
	printf("linklist D:\n");
	q = D->next;
	while (q)
	{
		printf("%d  ", q->data);
		q = q->next;
	}
	printf("\n");

	printf("\nOver\n");
	getchar();

	system("pause");
	return 0;
}