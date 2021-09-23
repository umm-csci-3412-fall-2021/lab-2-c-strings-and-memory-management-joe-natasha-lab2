#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "disemvowel.h"




bool is_vowel(char b) {
	if (b == 'a' ||b == 'e' ||b  == 'i' ||b == 'o' ||b == 'u'
			|| b == 'A' || b == 'E' ||b == 'I' || b == 'O' || b =='U') {
	return true;
	}
	else {
	return false;
	}
}
char *disemvowel(char *str) {
int len = strlen(str);
int consonant_count = 0;
for (int i=0; i<len; i++){
	if(!is_vowel(str[i])) {
	consonant_count++; 
	}
}

char * result = (char*) calloc(consonant_count+1, sizeof(char));
int j = 0;
for(int i=0; i<len; i++) {
	if(!is_vowel(str[i])){
	result[j] = str[i];
	j++;
	}
}
      	return result;
}

