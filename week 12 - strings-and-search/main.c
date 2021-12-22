
/*

@author :		sazaam@gmail.com
@github :		https://www.github.com/sazaam/
@description :	Week #12 Project 1 -- This is the 'String Filtering-Searching' project

@mission:		Enter a string, (max 100 characters) tolerating spaces and word characters only.
				Enter an alphabetical character "Key".
				Then find the length of the string, without the spaces.
				Then finally find the number of times the searched character "Key" is found in the string.

*/

#include <stdlib.h>
#include <stdio.h>


/*

	Main Function

*/

#define ROWS 4
#define COLS 5
#define MAX 100


int main(void) {

	printf("\n\n\n");
	printf("\t12주차 ~ 문자열 미션\n");

	// initialize
	char str[MAX];
	char key;
	int i, len, ind;

	// Record the Sentence
	printf("\n\t문자열을 입력하세요 :");
	scanf_s("%[a-zA-Z ]", &str, MAX);

	// Record the desired searched alphabetical character
	printf("\n\t찾고자 하는 알파벳을 입력하세요 :"); 
	scanf_s(" %c", &key, 2); // TRIMMING SPACE SCAN_F ISSUE -> # HACK // THIS WAS NOT SO COOL
	while (getchar() != '\n'); // special getchar() case.

	// printf("==> %c \n\t", key);


	len = 0, ind = 0;
	
	// ONE LAST LOOP to check 
		// 1 - length of the string without spaces
		// 2 - Number of times the searched character is found.
	for (i = 0; i < MAX; i ++) {
		if (str[i] == NULL) break; // We met the end of the string no need to continue;
		
		if ((int)str[i] != 32) len++; // tracker of non-space characters
		if (str[i] == key) ind++; // tracker of searched character
	}

	// print our results out.
	printf("\n\t공백을 제외한 문자의 개수는 %d개입니다", len);
	printf("\n\t이 문자열에서 %c는 %d 번 나옵니다.", key, ind);


	printf("\n\n\n");
	return 0;
}
