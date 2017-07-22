#include <stdio.h>

int Calc (int signs, int idxs, int numbers[]);
int CalcHelper (int n1, int n2, int s);
int FindOutSigns (int* s, int* i);

int a[4][8];

int main ()
{
   for (int i = 0; i < 7; i++) {
      scanf ("%d", &a[2][i]);
   }
   for (int i = 0; i < 8; i++) {
      scanf ("%d", &a[3][i]);
   }

   int signs, idxs;
   FindOutSigns(&signs, &idxs);

   for (int i = 0; i < 6; i++) {
      int numbers[2];
      numbers[0] = a[2][i];
      numbers[1] = a[2][i+1];
      a[1][i] = Calc (signs, idxs, numbers);
   }
   for (int i = 0; i < 5; i++) {
      int numbers[2];
      numbers[0] = a[1][i];
      numbers[1] = a[1][i+1];
      a[0][i] = Calc (signs, idxs, numbers);
   }

   for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 5 + i; j++) {
         if (j != 0) {
            printf (" ");
         }
         printf ("%d", a[i][j]);
      }
      printf ("\n");
   }

/*   printf ("2 + -7 = %d\n", CalcHelper (2, -7, 0));
   printf ("2 - -7 = %d\n", CalcHelper (2, -7, 1));
   printf ("2 * -7 = %d\n", CalcHelper (2, -7, 2));
   int n[2];
   n[0] = 2;
   n[1] = -7;
   printf ("%d\n", Calc (2, 5, n));*/
   return 0;
}

int Calc (int signs, int idxs, int numbers[])
{
   int s1, s2;
   s2 = signs % 4;
   s1 = (signs/4) % 4;
   int idx1, idx2, idx3;
   idx3  = (idxs % 2);
   idxs /= 2;
   idx2 = (idxs % 2);
   idxs /= 2;
   idx1 = (idxs % 2);

   int result = CalcHelper (numbers[idx1], numbers[idx2], s1);
   result = CalcHelper (result, numbers[idx3], s2);
   return result;
}

int CalcHelper (int n1, int n2, int s)
{
   switch (s) {
   case 0:
      return n1 + n2;
   case 1:
      return n1 - n2;
   case 2:
      return n1 * n2;
   case 3:
      return n1;
   default:
      return 0;
   }
}

int FindOutSigns (int* s, int* i)
{
   int numbers[2];
   for (int signs = 0; signs < 16; signs ++) {
      for (int idxs = 0; idxs < 8; idxs ++) {
         bool match = true;
         for (int j = 0; j < 7; j++) {
            numbers[0] = a[3][j];
            numbers[1] = a[3][j+1];
            if (a[2][j] != Calc(signs, idxs, numbers) ) {
               match = false;
               break;
            }
         }
         if (match) {
            *s = signs;
            *i = idxs;
            return 0;
         }
      }
   }
   return -1;
}