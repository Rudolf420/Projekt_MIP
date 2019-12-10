#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node {
    char name[30];
    char surname[30];
    char pohlavie[5];
    char IN[11];
    int year;
    long long int I;
    double revenue;
    struct node *next;
} node;

node* newNode(){
	int i = 0;
	int j = 0;
	int space = 0;		
	char tmp[10];
	char input[100];
	char year[4] = {'1', '9'};
	gets(input);
	printf("%s",input);
	
	node* new_node;
	new_node = (node*)malloc(sizeof(node));
	for(i = 0; i < strlen(input)-1; i++)
			{
				if(input[i] == ' ')
				{
					space++;
					j = 0;
					i++;
				}
					
				if(space == 0){
					new_node->name[j] = input[i];
					new_node->name[j+1] = '\0';
					j++;
				}
				
				if(space == 1)
				{
					new_node->surname[j] = input[i];
					new_node->surname[j+1] = '\0';
					j++;	
				}
				
				if(space == 2)
				{
					new_node->IN[j] = input[i];
					j++;
				}
				
				if(space == 3)
				{
					tmp[j] = input[i];
					if(i == strlen(input)-2)
						new_node->revenue = atof(tmp);
					j++;
				}
				input[i] = '0';
			}
			
			if(new_node->IN[2] > '4')
				strcpy(new_node->pohlavie, "zena");
			else
				strcpy(new_node->pohlavie, "muz");
			
			char tmp_IN[10];
			new_node->I = atoll(new_node->IN);
			
			for(i = 0; i < 10; i++)
			{
				if(i < 2)
				{
					tmp_IN[i] = new_node->IN[i+4];
				}
				
				if(i == 3 && new_node->pohlavie[0] == 'z')
				{
					tmp_IN[i] = new_node->IN[i-1] - 5;
				}
				
				if(i == 4 && new_node->pohlavie[0] == 'z')
				{
					tmp_IN[i] = new_node->IN[i-1];
				}
				
				if(i < 5 && i > 2 && new_node->pohlavie[0] == 'm')
				{
					tmp_IN[i] = new_node->IN[i-1];
				}
				
				if(i == 6)
					tmp_IN[i] = '1';
				
				if(i == 7)
				{
					tmp_IN[i] = '9';
				}
				
				if(i > 7 && i < 10)
				{
					tmp_IN[i] = new_node->IN[i-8];
					year[i-6] = new_node->IN[i-8];
				}
				
				if(i == 2 || i == 5)
					tmp_IN[i] = '.';
				
				if(i == 9)
					tmp_IN[i+1] = '\0';
			}
		
		new_node->year = atoi(year);
			
		strcpy(new_node->IN, tmp_IN);
		
		new_node->next = NULL;
		
		return new_node;
}

void printStatus(node* head) {
	if(head == NULL)
		printf("Nenacitano data\n");
	else
		printf("Nacitane data\n");
}

node* createNode(int *size)
{
	FILE *f;
	node *head = NULL;
	node *temp = NULL;
	node *p = NULL;
	char input[100];
	f = fopen("zamestnanci.txt","r");
	
	if((*size) > 0)
		*size = 0;
	
	while(fgets(input,100,f) != NULL)
	{
		int i = 0;
		int j = 0;
		int space = 0;
		char year[4] = {'1', '9'};
		char tmp[10];
		temp = (node*)malloc(sizeof(node));
			
			for(i = 0; i < strlen(input)-1; i++)
			{
				if(input[i] == ' ')
				{
					space++;
					j = 0;
					i++;
				}
					
				if(space == 0){
					temp->name[j] = input[i];
					temp->name[j+1] = '\0';
					j++;
				}
				
				if(space == 1)
				{
					temp->surname[j] = input[i];
					temp->surname[j+1] = '\0';
					j++;	
				}
				
				if(space == 2)
				{
					temp->IN[j] = input[i];
					j++;
					temp->IN[10] = '\0';
				}
				
				if(space == 3)
				{
					tmp[j] = input[i];
					if(i == strlen(input)-2)
						temp->revenue = atof(tmp);
					j++;
				}
				input[i] = '0';
			}
			if(temp->IN[2] > '4')
				strcpy(temp->pohlavie, "zena");
			else
				strcpy(temp->pohlavie, "muz");
			
			char tmp_IN[10];
			temp->I = atoll(temp->IN);
			
			for(i = 0; i < 10; i++)
			{
				if(i < 2)
				{
					tmp_IN[i] = temp->IN[i+4];
				}
				
				if(i == 3 && temp->pohlavie[0] == 'z')
				{
					tmp_IN[i] = temp->IN[i-1] - 5;
				}
				
				if(i == 4 && temp->pohlavie[0] == 'z')
				{
					tmp_IN[i] = temp->IN[i-1];
				}
				
				if(i < 5 && i > 2 && temp->pohlavie[0] ==  'm')
				{
					tmp_IN[i] = temp->IN[i-1];
				}
				
				if(i == 6)
					tmp_IN[i] = '1';
				
				if(i == 7)
				{
					tmp_IN[i] = '9';
				}
				
				if(i > 7 && i < 10)
				{
					tmp_IN[i] = temp->IN[i-8];
					year[i-6] = temp->IN[i-8];
				}
				
				if(i == 2 || i == 5)
					tmp_IN[i] = '.';
					
				if(i == 9)
					tmp_IN[i+1] = '\0';
			}
			
		strcpy(temp->IN, tmp_IN);
		temp->year = atoi(year);
				
		temp->next = NULL;
		
		if(head == NULL)
		{	
			head = temp;	
		
		}
		
		else
		{	
		
			p = head;
			while(p->next != NULL)
				p = p->next;
			p->next = temp;
				
			}
			(*size)++;
		}
	
	printf("Nacitalo sa %d zaznamov\n",*size);	
	return head;
}


void displayList(node *head)
{
	int i = 1;
	node *p = head;
	
	while(p != NULL)
	{
		printf("%d. %s %s %s %s %.2f\n",i ,p->name, p->surname, p->pohlavie, p->IN, p->revenue);
		p = p->next;
		i++;
	}
}

void deduplikuj(node* head) 
{ 
    node *ptr1, *ptr2, *tmp; 
    ptr1 = head; 
    int count = 0;
  
    while (ptr1 != NULL && ptr1->next != NULL) 
    { 
        ptr2 = ptr1; 
  
        while (ptr2->next != NULL) 
        { 
            if (strcmp(ptr1->name,ptr2->next->name) == 0 && strcmp(ptr1->surname,ptr2->next->surname) == 0 && strcmp(ptr1->IN,ptr2->next->IN) == 0) 
            { 
                tmp = ptr2->next; 
                ptr2->next = ptr2->next->next; 
                free(tmp);
				count++; 
            } 
            else 
                ptr2 = ptr2->next; 
        } 
        ptr1 = ptr1->next; 
    } 
    printf("Vymazalo sa %d zaznamov\n", count);
}

void pridaj(node** head, int *size)
{
	int n;
	scanf("%d ",&n);
	if (n > *(size) + 1){
	
		n = *size + 1; 
        while(n--){
        	if (n == 0) { 
                node* temp = newNode(); 
                temp->next = *head;
                *head = temp; 
            } 
            else

              head = &(*head)->next; 
		}}
    else { 

        while (n--) { 
  
            if (n == 0) { 
                node* temp = newNode(); 
                temp->next = *head;
                *head = temp; 
            } 
            else

              head = &(*head)->next; 
        } 
        *(size)++; 
    } 
}

void aktualizuj(node* head){
	int year = 2019;
	int count = 0;
	node* current;
	float v;
	float p;
	scanf("%d %f",&v,&p);
	
	for(current = head; current; current = current->next){
		if(year - current->year > v ){
			current->revenue += current->revenue*(p/100);
			count++;
		}
	}
	printf("AKtualizovalo sa %d zaznamov\n",count);
}

void overRC(node* head, int *size){
	int count = 0;
	node* current = head;
	
	while(current->next != NULL){
		if((current->next->I % 11) != 0 && current->next->next != NULL){
			current->next = current->next->next;
			count++;
		}
		
		else
		{
			current->next = NULL;
			count++;
		}
		
		current = current->next;
	}
	printf("Vymazalo sa %d zaznamov\n",count);	
	
	*size = *size - count;
}

void delete_lin_list(node** head){    
	node* current = *head;  
	node* next;  
	  
	while (current != NULL)  
	{  
	    next = current->next;  
	    free(current);  
	    current = next;  
	}  
	      
	*head = NULL;  

}

int main(){
	node *HEAD = NULL;
	int size = 0;
	char c[10];
	
	while(scanf("%s",c) > 0){
		printStatus(HEAD);
	
	switch(c[0]) {
		case 'n':
			HEAD = createNode(&size);
			break;
		
		case 'v':
			displayList(HEAD);
			break;
		
		case 'p':
			pridaj(&HEAD, &size);
			break;
		
		case 'o':
			overRC(HEAD, &size);
			break;
		
		case 'd':
			deduplikuj(HEAD);
			break;
		
		case 'a':
			aktualizuj(HEAD);
			break;
		
		case 'k':
			delete_lin_list(&HEAD);
			return 0;
			break;
	};
};
	
	return 0;
}
