#include<stdio.h>
#include<malloc.h>
#include<conio.h>
struct node{
	int num;
	struct node *next;
};
struct node *head;
struct node *p, *prev;
struct node* create_node(int N)
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
void display(struct node* list)
{
	p = list;
	while (p->next != NULL)
	{
		printf("%d->  ", p->num);
		p = p->next;
	}
	printf("%d", p->num);
}
struct node* merge(struct node* list1, struct node* list2)
{
	struct node* list;
	list = NULL;
	while ((list1 != NULL) || (list2 != NULL))
	{
		if (list1 == NULL)
		{
			if (list == NULL)
			{
				list = (struct node *)malloc(sizeof(struct node*));
				list->num = list2->num;
				list2 = list2->next;
				list->next = NULL;
			}
			else
			{
				p = (struct node *)malloc(sizeof(struct node*));
				p->num = list2->num;
				list2 = list2->next;
				p->next = list;
				list = p;
			}


		}
		else if (list2 == NULL)
		{
			if (list == NULL)
			{
				list = (struct node *)malloc(sizeof(struct node*));
				list->num = list1->num;
				list1 = list1->next;
				list->next = NULL;
			}
			else
			{
				p = (struct node *)malloc(sizeof(struct node*));
				p->num = list1->num;
				list1 = list1->next;
				p->next = list;
				list = p;
			}
		}
		else if ((list1->num) < (list2->num))
		{
			if (list == NULL)
			{
				list = (struct node *)malloc(sizeof(struct node*));
				list->num = list1->num;
				list1 = list1->next;
				list->next = NULL;
			}
			else
			{
				p = (struct node *)malloc(sizeof(struct node*));
				p->num = list1->num;
				list1 = list1->next;
				p->next = list;
				list = p;
			}
		}
		else
		{
			if (list == NULL)
			{
				list = (struct node *)malloc(sizeof(struct node*));
				list->num = list2->num;
				list2 = list2->next;
				list->next = NULL;
			}
			else
			{
				p = (struct node *)malloc(sizeof(struct node*));
				p->num = list2->num;
				list2 = list2->next;
				p->next = list;
				list = p;
			}
		}
	}
	return list;
}

int main()
{
	int n1, n2;
	struct node* list1 = (struct node*)malloc(sizeof(struct node*));
	struct node* list2 = (struct node*)malloc(sizeof(struct node*));
	struct node* list = (struct node*)malloc(sizeof(struct node*));
	printf("enter the values in list1 and list2");
	scanf("%d%d", &n1, &n2);
	list1 = create_node(n1);
	list2 = create_node(n2);
	list = merge(list1, list2);
	display(list);
	getch();
	return 0;
}