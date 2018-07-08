#include <stdio.h>

/* (c) Larry Herman, 2017.  You are allowed to use this code yourself, but
   not to provide it to anyone else. */

static int is_prime(int n);
static int is_prime_helper(int k, int n);

int x, y, i, result;

int main() {
  scanf("%d %d", &x, &y);
  result= -1;

  if (x < 2)
    x= 2;

  i= x;

  if (y > 0)
    while (i <= y && result == -1)
      if (is_prime(i))
        result= i;
      else i++;

  printf("%d\n", result);

  return 0;
}

static int is_prime(int n) {
  return is_prime_helper(2, n);
}

static int is_prime_helper(int k, int n) {
  int prime= 1;

  if (k < n / 2 + 1 && prime) {
    if (n % k == 0)
      prime= 0;
    else prime= is_prime_helper(k + 1, n);
  }

  return prime;
}
