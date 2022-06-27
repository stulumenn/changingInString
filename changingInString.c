#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define maxSize 10

void delete (char sentence[][maxSize], char word[], int *size);
void insert (char sentence[][maxSize], char word[], int place, int *size);
void find (char sentence[][maxSize], char character, int size);
void quit (char sentence[][maxSize], int size);

int main(){
	int place;
	int size;
	char choice, character;
	
	printf("Enter size\n");
	scanf("%d", &size);

	char letter[maxSize];
	char string [size][maxSize];

	printf("Enter a source\n");

	for(int i=0; i<size; i++){
		scanf("%s", string[i]);
	}	

	while (choice != 'Q'){

		printf("Enter D-I-F-Q\n");
		scanf(" %c", &choice);

		switch (choice){
			case 'D':
				printf("Enter the word to delete\n");
				scanf("%s", letter);
				delete(string, letter, &size);
				break;
			case 'I':
				printf("Enter the word to add.\n");
				scanf("%s", letter);
				printf("Enter where to add\n");
				scanf("%d", &place);
				insert(string, letter, place, &size);
				break;
			case 'F':
				printf("Enter character to find.\n");
				scanf(" %c", &character);
				find(string, character, size);
				break;
			case 'Q':
				printf("String after editing: ");
				quit(string, size);
				break;
			default:
				printf("You did not pick the right letter\n");	
				break;
		}
	}
}

void delete (char sentence[][maxSize], char word[], int *size){
	int temp;
	for(int i=0; i< *size; i++){
		if (strcmp(sentence[i],word)==0){
			temp = i;
		}
	}
	printf("%d\n", temp);

	for(int j=0; j< *size-1; j++){
		strcpy(sentence[temp+j], sentence[temp+1+j]);
	}
	--*size;

	printf("After: ");
	for(int i=0; i< *size; i++){
		printf("%s ", sentence[i]);
	}
	printf("\n");
}
void insert (char sentence[][maxSize], char word[], int place, int *size){
	for(int i=0; i<*size-place; i++){
		strcpy(sentence[*size+i],sentence[*size-1+i]);
	}

	strcpy (sentence[place],word);

	++*size;
	for (int i = 0; i < *size; ++i)
	{
		printf("%s ", sentence[i]);
	}
	printf("\n");
}
void find (char sentence[][maxSize], char character, int size){
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			if(sentence[i][j]==character){
				printf("index: %d, place: %d\n",i,j);
			}
		}
	}
}
void quit (char sentence[][maxSize], int size){
	for(int i=0; i<size; i++){
		printf("%s ", sentence[i]);
	}
	printf("\n");

}
