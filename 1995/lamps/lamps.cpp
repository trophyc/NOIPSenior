#include <stdio.h>
#include <memory.h>
#define MAX 20

int n;

struct color {
   char clr;
   int nbr;
   bool used;
};

color input[MAX];
int colors = 0;
int totalExtraSpace;
int count = 0;
bool printed = false;

void Init ();
void dfs (int usedColors, int ptr, int usedExtraSpace);
int FindNextColor (int s);
void PrintOutInput ();
void PrintOne ();

int main ()
{
   Init();

   int sum = 0;   
   for (int i = 0; i < colors; i++) {
      sum += input[i].nbr;
   }
   sum += colors - 1;
   if (sum > n) {
      printf ("0");
      return 0;
   }
   totalExtraSpace = n - sum;
//printf ("ExtraSpace = %d\n", totalExtraSpace) ; 
   PrintOne ();
   dfs (0, 0, 0);
   printf ("%d", count);
   return 0;
}

void Init ()
{
   scanf ("%d\n", &n);
   char clr;
   scanf ("%c ", &clr);
   while (clr != 'Q') {
      int nbr;
      scanf ("%d\n", &nbr);
      input[colors].clr = clr;
      input[colors].nbr = nbr;
      input[colors].used = false;
      scanf ("%c ", &clr);
      colors++;
   }
//PrintOutInput();
}

void dfs (int usedColors, int ptr, int usedExtraSpace)
{
   if (usedColors == colors) {
      count ++;
      return;
   }

   int allUsableExtra = totalExtraSpace - usedExtraSpace;
   for (int s = 0; s <= allUsableExtra; s++) {
//printf ("-- %d spaces\n", s);
      int i = FindNextColor (0);
//printf ("\t -- Next color is %d.\n", i);      
      while (i != -1) {
         int tmpPtr = ptr + s + input[i].nbr + 1;
         input[i].used = true;
         dfs (usedColors + 1, tmpPtr, usedExtraSpace + s);
         input[i].used = false;
         i = FindNextColor (i+1);
      }
   }
   return;
}

int FindNextColor (int start)
{
   for (int i = start; i < colors; i++) {
      if (!input[i].used) {
         return i;
      }
   }
   return -1;
}

void PrintOutInput ()
{
   printf ("%d\n", n);
   for (int i = 0; i < colors; i++) {
      printf ("%c %d\n", input[i].clr, input[i].nbr);
   }   
}

void PrintOne ()
{
   for (int i = 0; i < colors; i++) {
      for (int j = 0; j < input[i].nbr; j++) {
         printf ("%c", input[i].clr);
      }
      if (i != colors -1) {
         printf (" ");
      }
   }
   for (int i = 0; i < totalExtraSpace; i++) {
      printf (" ");
   }
   printf ("\n");   
}