#include <stdio.h>
struct dlink
{
	int data;
	struct dlink *next;
	struct dlink *prev;
}*node,*curr,*head,*last;
int n;
struct dlink *create_list(struct dlink *,int);
struct dlink *insert_beginning(struct dlink *);
struct dlink *insert_end(struct dlink *);
struct dlink *insert_position(struct dlink *);
struct dlink *delete_beginning(struct dlink *head);
struct dlink *delete_end(struct dlink *head);
void delete_position(struct dlink *);
void display_forward(struct dlink *);
void display_backward(struct dlink *);
main()
{
	printf("Enter number of node required initially\n");
	scanf("%d",&n);
	head=NULL;
	last=NULL;
	head=create_list(head,n);
	last=node;
	//head=insert_beginning(head);
	//last=insert_end(last);
	//head=insert_position(head);
	//last=delete_end(head);
	//head=delete_beginning(head);
	delete_position(head);
	printf("Displaying from the beginning\n");
	display_forward(head);
	printf("\n");
	printf("Displaying from the end\n");
	display_backward(last);
	getch();
}
struct dlink *create_list(struct dlink *head,int n)
{
	int i;
	node=(struct dlink *)malloc(sizeof(struct dlink *));
	printf("Enter number\n");
	scanf("%d",&node->data);
	node->next=NULL;
	node->prev=NULL;
	head=node;
	for (i=0;i<n-1;i++)
	{
		struct dlink *temp;
		temp=(struct dlink *)malloc(sizeof(struct dlink *));
		printf("Enter number\n");
		scanf("%d",&temp->data);
		node->next=temp;
		temp->prev=node;
		temp->next=NULL;
		node=temp;
	}
	return head;
}
struct dlink *insert_beginning(struct dlink *head)
{
	struct dlink *temp;
	temp=(struct dlink *)malloc(sizeof(struct dlink *));
	printf("Insertion at beginning\n");
	printf("Enter number\n");
	scanf("%d",&temp->data);
	temp->prev=NULL;
	temp->next=head;
	head->prev=temp;
	printf("Number inserted\n");
	head=temp;
	return head;
}
struct dlink *insert_end(struct dlink *last)
{
	struct dlink *temp;
	temp=(struct dlink *)malloc(sizeof(struct dlink *));
	printf("Insertion at the end\n");
	printf("Enter number\n");
	scanf("%d",&temp->data);
	temp->prev=last;
	temp->next=NULL;
	last->next=temp;
	printf("Number inserted\n");
	last=temp;
	return last;
}
struct dlink *insert_position(struct dlink *head)
{
	int loc,i=1;
	printf("Insertion at position\n");
	printf("Enter the position where you want to insert\n");
	scanf("%d",&loc);
	struct dlink *a;
	a=head;
	while(i<loc)
	{
		a=a->next;
		i++;
	}
	struct dlink *temp=(struct dlink *)malloc(sizeof(struct dlink *));
	printf("Enter number\n");
	scanf("%d",&temp->data);
	temp->next=a;
	temp->prev=a->prev;
	a->prev->next=temp;
	a->prev=temp;
	printf("Number inserted\n");
	return head;
}
struct dlink *delete_beginning(struct dlink *head)
{
	printf("Deletion from beginning\n");
	head=head->next;
	return head;
}
struct dlink *delete_end(struct dlink *head)
{
	printf("Deletion from the end\n");
	last=last->prev;
	return last;
}
void delete_position(struct dlink *head)
{
	int loc,i=1;
	printf("Deletion from position\n");
	printf("Enter the position from where you want to delete\n");
	scanf("%d",&loc);
	struct dlink *a,*b;
	a=head;
	while(i<loc-1)
	{
		a=a->next;
		i++;
	}
	b=a->next;
	a->next=b->next;
	b->next->prev=a;
	free(b);
	printf("Number deleted\n");
}
void display_forward(struct dlink *head)
{
	struct dlink *temp;
	temp=head;
	while(temp!=last)
	{
		printf("%d\t",temp->data);
		temp=temp->next;
	}
	printf("%d\t",temp->data);
}
void display_backward(struct dlink *last)
{
	struct dlink *temp;
	temp=last;
	while(temp!=head)
	{
		printf("%d\t",temp->data);
		temp=temp->prev;
	}
	printf("%d\t",temp->data);
}
