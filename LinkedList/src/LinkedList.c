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
	Node *second = NULL;
	Node *third = NULL;

	void addElement(Node **p, int v);
	void displayElements(Node *p);
	int searchElement(Node *p, int s);
	void addElementToFirstIndex(Node **p, int v);
	int deleteElement(Node **p, int v);
	int getListSize(Node *first);
	void addElementAtPosition(Node **p, int v, int position);
	void orderedInsert(Node **first, int v);
	void addByValue(Node **p, int v, int previous);
	void reverseElements(Node **p);

	Node* copyList(Node *first);
	Node* concatenateLists(Node *first, Node *second);
	Node* splitLists(Node **p, int pos);

	void listBubbleSort(Node *p);
	void listSelectionSort(Node *p);
	void listMergeSort(Node **first);

	int listIntersection(Node *p, Node *q);
	Node* listUnion(Node *p, Node *q);

	void listDestructor(Node **p);


	//The next line is not required for Non-Windows PCs or when using TurboC
	setbuf(stdout, NULL);

	printf("Enter the choice : \n1 to add\n2 to print\n3 for searching\n4 for add element to first position\n5 for delete\n6 for list size\n7 for add element at position\n8 for Merge Sort\n9 for ordered insert\n10 for Bubble Sort\n11 for Selection Sort\n12 for reversing the list\n13 for Copying lists\n14 for Concatenate 2 lists\n15 for Split two lists\n");

	do{

		printf("Enter Choice\n");
		scanf("%d",&choice);

		switch(choice){

			case 1:{
				//Add an element

				printf("Enter the element\n");
				scanf("%d",&element);

				addElement(&first, element);
				break;
			}
			case 2:{
				//Display all elements

				displayElements(first);

				break;
			}
			case 3:{
				//Search for an element

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
				//Add element to first index

				printf("Enter the element\n");
				scanf("%d",&element);

				addElementToFirstIndex(&first, element);

				break;
			}
			case 5:{
				//Delete Element

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
				//Get size of List

				size = getListSize(first);

				printf("Size is %d\n", size);
				break;
			}
			case 7:{
				//Add element at any position

				printf("Enter the element and position\n");
				scanf("%d%d",&element,&pos);

				addElementAtPosition(&first, element, pos);

				break;
			}
			case 8:{
				//Merge Sort on Linked List

				listMergeSort(&first);

				break;
			}
			case 9:{
				//Ordered Insert : Use this for inserting in a Asscending order

				printf("Enter the element\n");
				scanf("%d",&element);

				orderedInsert(&first, element);

				break;
			}
			case 10:{
				//Bubble Sort on Linled Lists

				listBubbleSort(first);

				break;
			}
			case 11:{
				// Selection Sort on Linked List

				listSelectionSort(first);

				break;
			}
			case 12:{
				//Reverse the Elements in the list

				reverseElements(&first);

				break;
			}
			case 13:{
				//Copy list

				second = copyList(first);

				if(first != NULL || second != NULL){

					displayElements(first);
					displayElements(second);

				}
				else{
					printf("First is NULL\n");
				}

				break;
			}
			case 14:{
				//Concatenate a list

				third = concatenateLists(first, second);

				if(third != NULL)
					displayElements(third);

				else
					printf("Error\n");

				break;
			}
			case 15:{
				//Split two lists

				printf("Enter position of split\n");
				scanf("%d", &pos);

				second = splitLists(&first, pos);

				if(second != NULL){
					displayElements(first);
					displayElements(second);
				}
				else{
					printf("Either of the lists is NULL\n");
				}


				break;
			}
			case 16:{
				//Intersection of Lists


				break;
			}
			case 17:{
				//Union of Lists


				break;
			}

			default:{
				choice = -1;
			}
		}

	}while(choice  != -1);

	listDestructor(&first);
	listDestructor((&second));
	listDestructor(&third);

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
	printf("\n");

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

void listMergeSort(Node **first){

	Node *head = *first;
	Node *firstNode,*lastNode;

	Node* sortedMerge(Node *a, Node *b);
	void elementarySplit(Node *ref, Node **firstRef, Node **lastRef);

	if(head == NULL || head->next == NULL){
		return;
	}

	elementarySplit(head, &firstNode, &lastNode);

	listMergeSort(&firstNode);
	listMergeSort(&lastNode);

	(*first) = sortedMerge(firstNode, lastNode);

}


Node* sortedMerge(Node *a, Node *b){

	Node *result = NULL;

	if(a == NULL){
		return b;
	}
	else if(b == NULL){
		return a;
	}


	if(a->data <= b->data){
		result = a;
		result->next = sortedMerge(a->next, b);
	}
	else{
		result = b;
		result->next = sortedMerge(a, b->next);
	}

	return result;

}

void elementarySplit(Node *ref, Node **firstRef, Node **lastRef){

	Node *fastWalker, *slowWalker;

	if(ref == NULL || ref->next == NULL){

		//Length of sub-list is less than 2

		*firstRef = ref;
		*lastRef = NULL;

	}

	else{

		slowWalker = ref;
		fastWalker = ref->next;

		/* Move 'fast' two nodes, and advance 'slow' one node */

		while(fastWalker != NULL){

			fastWalker = fastWalker->next;

			if(fastWalker != NULL){
				slowWalker = slowWalker->next;
				fastWalker = fastWalker->next;
			}

		}

		 /* 'slow' is before the midpoint in the list, so split it in two
		      at that point. */
		*firstRef = ref;
		*lastRef = slowWalker->next;
		 slowWalker->next = NULL;

	}

}


void orderedInsert(Node **p, int v){
	Node *newNode = NULL;

	newNode = (Node*) calloc(1, sizeof(Node));
	newNode->data = v;

	Node *temp, *previous;
	temp = *p;

	while(temp != NULL){

		if(temp->data > v){
			break;
		}

		previous = temp;
		temp = temp->next;
	}

	if(temp == *p){
		newNode->next = *p;
		*p = newNode;
	}
	else{
		newNode->next = previous->next;
		previous->next = newNode;
	}

}



void addByValue(Node **p, int v, int pre){
	Node *newNode = NULL;

	newNode  = (Node*) calloc(1, sizeof(Node));
	newNode->data = v;

	Node *temp = *p, *previous;

	while(temp != NULL){

		if(temp->data == pre){
			break;
		}

		previous = temp;
		temp = temp->next;
	}

	if(temp == NULL)
		return;

	if(temp == *p){
		newNode->next = *p;
		*p = newNode;
	}
	else{
		newNode->next = previous->next;
		previous->next = newNode;
	}

}


void listBubbleSort(Node *p){

	Node *i,*temp = p;
	int t;

	for(i = p; i->next != NULL; i = i->next){

		for(temp = p; temp->next != NULL; temp = temp->next){

			if(temp->data > temp->next->data){

				t = temp->data;
				temp->data = temp->next->data;
				temp->next->data = t;

			}

		}

	}

}

void listSelectionSort(Node *p){

	Node *temp;
	int t;

	for( ; p->next != NULL; p = p->next){

		for(temp = p->next; temp != NULL; temp = temp->next){

			if(p->data > temp->data){

				t = p->data;
				p->data = temp->data;
				temp->data = t;

			}

		}

	}


}

void reverseElements(Node **p){
	Node *first, *last, *temp;

	first = *p;
	last = NULL;

	while(first != NULL){
		temp = last;

		last = first;
		first = first->next;
		last->next = temp;
	}

	*p = last;

}

Node* copyList(Node *first){

	Node *newNode = NULL;

	if(first == NULL){
		return newNode;
	}

	newNode = (Node*) calloc(1, sizeof(Node));
	Node *ref = newNode;

	newNode->data = first->data;

	while(first->next != NULL){
		newNode->next = (Node*) calloc(1, sizeof(Node));
		newNode = newNode->next;
		first = first->next;
		newNode->data = first->data;
	}

	newNode->next = NULL;
	return ref;
}



Node* concatenateLists(Node *first, Node *second){

	Node *p = NULL;

	if(first == NULL && second == NULL){
		return p;
	}
	else if(first == NULL){
		return second;
	}
	else if(second == NULL){
		return first;
	}

	p = first;

	while(p->next != NULL){

		p = p->next;

	}

	p->next = second;

	return first;

}


Node* splitLists(Node **p, int pos){
	int i,size;
	Node *newList = NULL, *temp = NULL, *pTemp = *p,*pFinal;
	Node *previous;

	temp = (Node*) calloc(1, sizeof(Node));
	newList = temp;

	int getListSize(Node *p);

	size = getListSize(*p);

	if(size == 0){
		return *p;
	}

	if(pos > 0 && pos < size){

		for(i = 0; i < pos; i++){
			previous = pTemp;
			pTemp = pTemp->next;
		}

		temp->data = pTemp->data;

		pFinal = previous;

		while(pTemp->next != NULL){
			temp->next = (Node*) calloc(1, sizeof(Node));

			temp = temp->next;
			pTemp = pTemp->next;

			temp->data = pTemp->data;
		}

		pFinal->next = NULL;
		temp->next = NULL;


		return newList;
	}
	else{
		return *p;
	}


}


int listIntersection(Node *p, Node *q){
	Node *temp = q;
	int c = 0;

	while(p != NULL){
		while(q != NULL){

			if(p->data == q->data){

				c++;
				printf("%d\t",p->data);
				break;

			}

			q = q->next;
		}

		p = p->next;
		q = temp;
	}

	return c;
}

Node* listUnion(Node *p, Node *q){

	Node *t = NULL, *previous;
	Node *p1 = p, *q1 = q;

	Node *newNode = NULL;

	while(p != NULL){
		newNode = (Node*) calloc(1, sizeof(Node));
		newNode->data = p->data;
		newNode->next = NULL;

		if(t == NULL){
			t = newNode;
		}
		else{
			previous->next = newNode;
		}

		previous = newNode;
		p = p->next;
	}

	p = p1;

	while(q != NULL){

		while(p != NULL){

			if(p->data == q->data){
				break;
			}

			p = p->next;

		}

		if(p == NULL){
			newNode = (Node*) calloc(1, sizeof(Node));
			newNode->data = q->data;
			newNode->next = NULL;

			previous->next = newNode;
			previous = newNode;
		}

		p = p1;
		q = q->next;
	}

	return t;
}


void listDestructor(Node **p){

	Node *next, *del;
	del = *p;

	while(del != NULL){
		next = del->next;
		free(del);
		del = next;
	}

	free(*p);

}






