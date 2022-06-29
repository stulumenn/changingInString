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

	do {
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
	} while (choice != 'Q');
}

void delete (char sentence[][maxSize], char word[], int *size){
	int foundFlag = 0;

	for(int i=0; i< *size - 1; i++){
		if (strcmp(sentence[i],word)==0){
			foundFlag = 1;
		}

		if (foundFlag == 1) {
			strcpy(sentence[i], sentence[i + 1]);
		}
	}

	if (foundFlag == 1) {
		--*size;
	} else if (strcmp(sentence[*size - 1],word)==0) {
		strcpy(sentence[*size - 1], "");
		--*size;
	}

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

	for(int i = *size-1; i >= place; --i ) {
		strcpy(sentence[i + 1], sentence[i])
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
