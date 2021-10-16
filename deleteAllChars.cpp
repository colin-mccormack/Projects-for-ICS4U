#include <stdio.h>
#include <stdlib.h>

void deleteAllChars(char *s, char c) {
	int i = 0;
	int j;
	
	while (s[i]) {
		if (s[i] == c) {
			j = i;
			while(s[j]) {
				if (s[j+1] != c) {
					s[i] = s[j+1];	
					i++;
				}
				j++;
			}
		} else {
			i++;
		}
	}
}

int main() {
	char deletedLetter;
	char word[256];
	
	while (1) {
	
		printf ("\nEnter a word : ");
		scanf ("%s", &word);
		
		fflush;
	
		printf ("\nEnter a char to delete : ");
		scanf ("%s", &deletedLetter);
		
		deleteAllChars(word, deletedLetter);
		
		printf ("\nYour word is now : %s", word);
		
	}
}
