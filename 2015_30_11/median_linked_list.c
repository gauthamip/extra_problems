#include<stdio.h>

struct node{
	int num;
	struct node *next;
};
struct node *head;
struct node *p,*prev;
struct nose* create_node(int N)
{
	head = NULL;
	p = NULL;
	if (N < 0)
		N = 0 - N;

	if (N == 0)
	{
		head = (struct node *)malloc(sizeof(struct node*));
		head->num = N;
		head->next = NULL;
	}
	else
	{
		while (N > 0)
		{
			if (head == NULL)
			{
				head = (struct node *)malloc(sizeof(struct node*));
				head->num = N % 10;
				N = N / 10;
				head->next = NULL;
			}
			else
			{
				p = (struct node *)malloc(sizeof(struct node*));
				p->num = N % 10;
				N = N / 10;
				p->next = head;
				head = p;
			}

		}
	}
}
void display()
{
	p = head;
	while (p->next != NULL)
	{
		printf("%d->  ", p->num);
		p = p->next;
	}
	printf("%d", p->num);
}
float find_median(struct node *list)
{
	int len=0,pos,i=1;
	float med;
	p = (struct node*)malloc(sizeof(struct node*));
	p = list;
	while (p != NULL)
	{
		p = p->next;
		len++;
	}
	p = list;
	if (len % 2 != 0)
	{
		pos = (len + 1) / 2;
		while (i < pos)
		{
			prev = p;
			p = p->next;
			i++;
		}
		med = p->num;
	}
	else
	{
		pos = len / 2;
		while (i<pos)
		{
			prev = p;
			p = p->next;
			i++;
		}
		med = p->num;
		p = p->next;
		med = med + p->num;
		med = med / 2;
	}
	return med;
}
main()
{
	int n;
	float result;
	struct node *list;
	list = (struct node*)malloc(sizeof(struct node*));
	printf("enter the number\n");
	scanf("%d", &n);
	list=create_node(n);
	display();
	result = find_median(list);
	printf("\nthe median of the given linked list is %f", result);
	getch();
	return 0;
}