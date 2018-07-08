l#include <stdio.h>

int main() {
  int line = 0;
  int line_digit = 0;
  int i = 0;
  int char_number = 0;
  char character[1001];

  while (!feof(stdin)) {

    char_number = 0;
    line ++;

    scanf("%c", &character[char_number]);

    /* Read characters. If it is the last character then also leave the loop. */
    while ((character[char_number] != '\n') && !feof(stdin)) {
      /* Special case when it is a tab. */
      if (character[char_number] == '\t') {
	         char_number++;
	while (char_number % 8 != 0) {
	         char_number++;
	}
      } else {
	char_number ++;
      }
      scanf("%c", character[char_number]);
      
    }

    /* If already read all the data then skip all the next steps. */
    if (!feof(stdin)) {
      
      line_digit = line;
    
      printf(char_number > 80 ? "*" : " ");

      /* To determine how many spaces should be keep for lines. */
      while (line_digit < 10000) {
	line_digit *= 10;
	printf(" ");
      }
      printf("%d: ", line);

      /* Print out characters. */
      i = 0;
      while (i < char_number) {
	printf("%c", character[i]);
	if (character[i] == '\t') {
	  i++;
	  while (i % 8 != 0) {
	    i++;
	  }
	} else {
	  i++;
	}
      }

      /* When the character is over 80, leave '^' on the next line. */
      if (char_number > 80) {
	printf("\n");
	for (i = 0; i < 88; i++) {
	  printf(" ");
	}
	for (i = 0; i < char_number - 80; i++) {
	  printf("^");
	}
      }

      printf("\n");
    
    }
  }
  
  return 0;
}
