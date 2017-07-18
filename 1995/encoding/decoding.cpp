#include <stdio.h>
#include <memory.h>
#define MAX_NUMBERS 10000

int n;
int a[MAX_NUMBERS];
bool b[MAX_NUMBERS];
int decoding[MAX_NUMBERS];

int main ()
{
   memset (b, 1, sizeof(b));
   scanf ("%d", &n);
   for (int i = 0; i < n; i++) {
      scanf ("%d", &a[i]);
   }

   decoding[n-1] = a[n-1];
   b[a[n-1]] = false;
   for (int i = n-2; i >= 0; i--) {
      int c = 0;
      int j;
      for (j = 0; j < n; j++) {
         if (b[j]) {
            c ++;
            if (c == a[i] + 1) {
               b[j] = false;
               break;
            }
         }
      }
      decoding[i] = j;
   }
   
   printf ("%d", decoding[0]);
   for (int i = 1; i < n; i++) {
      printf (" %d", decoding[i]);
   }
   return 0;
}