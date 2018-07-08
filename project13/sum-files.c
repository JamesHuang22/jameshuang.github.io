#include <stdio.h>

/* (c) Larry Herman, 2017.  You are allowed to use this code yourself, but
 * not to provide it to anyone else.
 */

int main(int argc, char *argv[]) {
  int i, n, one_file_sum, all_files_total= 0;
  FILE *fp;

  if (argc > 1) {

    for (i= 1; i < argc; i++) {

      fp= fopen(argv[i], "r");

      /* silently ignore nonexistent files, or ones that there was an error
         trying to open */
      if (fp != NULL) {

        one_file_sum= 0;
        fscanf(fp, "%d", &n);

        while (!feof(fp)) {
          one_file_sum += n;
          fscanf(fp, "%d", &n);
        }

        all_files_total += one_file_sum;

      }
    }

  }

  printf("%d\n", all_files_total);

  return 0;
}