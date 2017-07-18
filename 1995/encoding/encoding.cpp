#include <stdio.h>
#include <memory.h>

#define MAX_NUMBERS 10000
int n;
int a[MAX_NUMBERS];
int coding[MAX_NUMBERS];

int main ()
{
   scanf ("%d", &n);
   for (int i = 0; i < n; i++) {
      scanf ("%d", &a[i]);
   }

   coding[0] = 0;
   for (int i = 1; i < n; i++) {
      int c = 0;
      for (int j = 0; j <= i-1; j++) {
         if (a[i] > a[j]) {
            c ++;
         }
      }
      coding[i] = c;
   }

   printf ("%d", coding[0]);
   for (int i = 1; i < n; i ++) {
      printf (" %d", coding[i]);
   }
   return 0;
}