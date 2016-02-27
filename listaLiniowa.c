#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct e{
	int n;
	struct e *next; 
};

struct e* addFirst(struct e*, int);
void printList(struct e* pointerToList);
struct e* deleteElement(struct e*, int);
struct e* deleteList(struct e*); 

int main(){
	int i;
	typedef struct e *list;
	list l = NULL;

	srand(time(NULL));


	for (i=0; i<rand() % 41 + 10;i++)
		l = addFirst(l, rand() % 10 );
	printf("Added random (10-50) number of random values (0-9):");
	printList(l);

	l = deleteElement(l, 1);
	printf("Removed all 1s:");
	printList(l);
	l = deleteElement(l, 2);
	printf("Removed all 2s:");
	printList(l);
	l = deleteElement(l, 3);
	printf("Remove all 3s:");
	printList(l);

	l = deleteList(l);
	printList(l);

	for (i=0; i<20;i++)
	{
		l = addFirst(l, (i%3 < 2) ? 7 : 3 );
	}

	printf("Created a list of 773773773... pattern emove all 3s:");
	printList(l);

	l = deleteElement(l, 7);
	l = deleteElement(l, 1);

	printf("Removed all 7s and all 1s:");
	printList(l);
 
	l = deleteList(l);
	printList(l);



	for (i=0; i<20;i++)
	{
		l = addFirst(l, 5);
	}

	printf("Created a list of 20 5s:");
	printList(l);

	l = deleteElement(l, 5);
	printf("Removed all 5s and all 1s:");
	printList(l);
 
	l = deleteList(l);
	printList(l);


	return 0;	
}



struct e* addFirst(struct e* pointerToList, int number){
	struct e* newNode = malloc(sizeof * newNode);
	newNode->n = number;
	
	newNode->next = pointerToList;
	return newNode;
}

void printList(struct e* pointerToList){
	struct e *tmp = pointerToList;

	if(pointerToList == NULL)
		printf("Lista pusta!\n");
  else{
		while(tmp != NULL){
			printf("%d \t",tmp->n);
			tmp = tmp -> next;
		}

	}
	printf("\n");
}


struct e* deleteElement(struct e* firstElement, int pattern){
	
 	struct e* prev;
	struct e* curr = firstElement;


	while(firstElement != NULL && firstElement -> n == pattern){
		prev = firstElement;
		firstElement = firstElement -> next;
		free(prev);
	}
	
	if(firstElement == NULL)
		return firstElement;
	
	prev = firstElement;
	curr = prev->next;
	while(curr != NULL){
		if (curr -> n == pattern){
			prev -> next = curr -> next;
			free(curr);
			curr = prev -> next;
		}
		
		else{
		curr = curr -> next;
		prev = prev -> next;	
		}
	}
	
	return firstElement;

/*


  if(firstElement)
  {
		struct e* prev = firstElement;
		struct e* del = firstElement;

		while(del != NULL)
		{
			if(del->n == pattern)
			{
				if(del == firstElement)
				{
					prev = firstElement->next;
			  	free(del);
					del = prev;
					firstElement = prev;
					continue;
				}
		
				else
				{
					prev->next = del->next;
					free(del);
					del = prev->next;
					continue;
				}
			}
				if(prev == del)
					del = del->next;
			  else
				{
					prev = prev->next;
					del = prev->next;	
				}
		}
	}
		return firstElement;
*/

}


struct e* deleteList(struct e* firstElement){
	struct e* tmp; 
	if ( firstElement == NULL)
		return firstElement;

	while(firstElement -> next != NULL){
		tmp = firstElement->next; 	
		free(firstElement);
		firstElement = tmp;
	}
	free(firstElement);
	firstElement = NULL;
	return firstElement;
} 

	
		
	
	
	

