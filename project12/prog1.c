#include <stdio.h>

/* (c) Larry Herman, 2017.  You are allowed to use this code yourself, but
   not to provide it to anyone else. */

int n, k, prime;

int main() {
  scanf("%d", &n);

  if (n < 2)
    prime= 0;
  else {

    k= 2;
    prime= 1;

    while (k < n / 2 + 1 && prime)
      if (n % k == 0)
        prime= 0;
      else k++;

  }

  printf("%d\n", prime);

  return 0;
}
