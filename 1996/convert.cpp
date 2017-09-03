#include <stdio.h>

char str[50];

void Convert (long long n, int base);

int main ()
{
   scanf ("%s", str);
   
   int lastIdx = 0;
   int ptr = 0;
   while (str[ptr] != '<'){
      ptr++;
   }
   lastIdx = ptr -1;

   int oldBase = 0;
   ptr++;
   while (str[ptr] != '>') {
      oldBase *= 10;
      oldBase += str[ptr++] - '0';
   }

   int newBase = 0;
   ptr++;
   while (str[ptr] != '\0') {
      newBase *= 10;
      newBase += str[ptr++] - '0';
   }
   
   long long number = 0;
   for (int i = 0; i <= lastIdx; i++) {
      number *= oldBase;
      number += str[i] - '0';
   }

   Convert (number, oldBase);
   printf ("<%d>=", oldBase);
   Convert (number, newBase);
   printf ("<%d>\n", newBase);
   return 0;
}

void Convert (long long n, int base)
{
   if (n == 0) {
      return;
   }

   int r = n % base;
   Convert (n/base, base);
   printf ("%d", r);
}