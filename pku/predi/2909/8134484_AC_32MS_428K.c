#include <stdio.h>

int main()
{
    FILE *f, *g;
    short is_prime[32768];
    int i, j, n, count;

    for (i = 3; i < 32768; i+=2) is_prime[i] = 1;
    for (i = 3; i <= 256; i+=2)
      if (!is_prime[i]) continue;
      else
        for (j = 2 * i; j < 32768; j += i)
          is_prime[j] = 0;
    
    f = stdin;
    g = stdout;

    fscanf(f, "%d", &n);
    while (n)
    {      
      count = 0;
      for (i = 3; i <= n / 2; i += 2)
        if (is_prime[i] && is_prime[n - i]) count++;
      fprintf(g, "%d\n", count);
      fscanf(f, "%d", &n);
    }
}