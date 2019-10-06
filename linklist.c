#include <iostream>
struct node
{
	int data;
	struct node *next;
};
void print_list(node* head)
{
	node* tmp = head;
	while (tmp != NULL)
	{
		printf("%d  ", tmp->data);
		tmp = tmp->next;
	}
	printf("%s", "\n");
}
void add_node(int n, node*& head)
{
	node *tmp = new node;
	tmp->data = n;
	tmp->next = NULL;

	if (head == NULL)
	{
		head = tmp;
	}
	else
	{
		tmp->next = head;
		head = tmp;
	}
}

int main()
{
	node *head = NULL;
	for (int i = 0; i < 5; i++)
		add_node(i + 1, head);
	print_list(head);
}