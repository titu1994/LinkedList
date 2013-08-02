/*
 ============================================================================
 Name        : LinkedList.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
/*
 * Use #include <conio.h>
 * and #include <alloc.h>
 * when using TurboC and
 *
 * Remove #include <stdlib.h>
 */

typedef struct node{
	int data;
	struct node *next;
}Node;


// Use void main(){ ... } when using TurboC
int main(void) {
	int choice = -1;
	int element,pos, size;

	Node *first = NULL;

	void addElement(Node **p, int v);
	void displayElements(Node *p);
	int searchElement(Node *p, int s);
	void addElementToFirstIndex(Node **p, int v);
	int deleteElement(Node **p, int v);
	int getListSize(Node *first);
	void addElementAtPosition(Node **p, int v, int position);

	//The next line is not required for Non-Windows PCs or when using TurboC
	setbuf(stdout, NULL);

	do{

		printf("Enter the choice : \n1 to add\n2 to print\n3 for searching\n4 for add element to first position\n5 for delete\n6 for list size\n7 for add element at position");
		scanf("%d",&choice);

		switch(choice){

			case 1:{
				printf("Enter the element\n");
				scanf("%d",&element);

				addElement(&first, element);
				break;
			}
			case 2:{
				displayElements(first);

				break;
			}
			case 3:{
				printf("Enter the element\n");
				scanf("%d",&element);

				if(searchElement(first, element) == 1){
					printf("Exists\n");
				}
				else{
					printf("Does'nt exist\n");
				}

				break;
			}
			case 4:{
				printf("Enter the element\n");
				scanf("%d",&element);

				addElementToFirstIndex(&first, element);

				break;
			}
			case 5:{
				printf("Enter the element\n");
				scanf("%d",&element);

				if(deleteElement(&first, element) == 1){
					printf("Deleted\n");
				}
				else{
					printf("Not deleted\n");
				}

				break;
			}
			case 6:{
				size = getListSize(first);

				printf("Size is %d\n", size);
				break;
			}
			case 7:{

				printf("Enter the element and position\n");
				scanf("%d%d",&element,&pos);

				addElementAtPosition(&first, element, pos);

				break;
			}

			default:{
				choice = -1;
			}
		}

	}while(choice  != -1);


	return EXIT_SUCCESS;
}


void addElement(Node **p, int v){
	Node *newNode = NULL;

	newNode = (Node*) calloc(1, sizeof(Node));
	newNode->data = v;
	newNode->next = NULL;

	if(*p == NULL){
		*p = newNode;
	}
	else{
		Node *temp = *p;

		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = newNode;
	}


}

void displayElements(Node *p){

	while(p != NULL){
		printf("%d\t",p->data);
		p = p->next;
	}

}

int searchElement(Node *first, int s){

	while(first != NULL){
		if(first->data == s){
			return 1;
		}
		else
			first = first->next;
	}

	return 0;

}

void addElementToFirstIndex(Node **p, int v){

	Node *newNode = NULL;

	newNode = (Node *) calloc(1, sizeof(Node));
	newNode->data = v;
	newNode->next = *p;

	*p = newNode;
}

int deleteElement(Node **p, int v){

	Node *temp,*previous;
	temp = *p;

	while(temp != NULL){

		if(temp->data == v){
			break;
		}

		previous = temp;
		temp = temp->next;

	}

	if(temp  == NULL){
		return 0;
	}
	else{

		if(temp == *p){
			*p = temp->next;
		}
		else{
			previous->next = temp->next;
			free(temp);
		}

		return 1;
	}

}

int getListSize(Node *first){

	int size = 0;

	while(first != NULL){
		size++;
		first = first->next;
	}

	return size;
}

void addElementAtPosition(Node **p, int v, int position){
	int i;
	int size;

	Node *newNode = NULL;

	newNode = (Node *) calloc(1, sizeof(Node));
	newNode->data = v;

	size = getListSize(*p);

	if(position >=0 && position <size){

		Node *temp,*previous;
		temp = *p;

		for(i = 0; i < position; i++){

			previous = temp;
			temp = temp->next;

		}

		if(temp == *p){

			newNode->next = *p;
			*p = newNode;

		}
		else if(temp == NULL){

			newNode->next = NULL;
			(*p)->next = newNode;

		}
		else{

			previous->next = newNode;
			newNode->next = temp;

		}

	}
	else{

		newNode->next = NULL;

		Node *temp = *p;

		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = newNode;
	}

}
