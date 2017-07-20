#include <stdio.h>
#include <memory.h>
#define MAX 20

char lamps[MAX];
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
void PrintArray(int ptr);
void PrintOutInput ();

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
   memset (lamps, ' ', sizeof(lamps));
}

void dfs (int usedColors, int ptr, int usedExtraSpace)
{
   if (usedColors == colors) {
      count ++;
      if (!printed) {
         PrintArray( ptr);
         printed = true;
      }
      return;
   }

   int allUsableExtra = totalExtraSpace - usedExtraSpace;
   for (int s = 0; s <= allUsableExtra; s++) {
//printf ("-- %d spaces\n", s);
      for (int j = 0; j < s; j++) {
         lamps[ptr+j] = ' ';
      }
      int i = FindNextColor (0);
//printf ("\t -- Next color is %d.\n", i);      
      while (i != -1) {
         int tmpPtr = ptr + s;
         for (int j = 0; j < input[i].nbr; j++) {
            lamps[tmpPtr++] = input[i].clr;
         }
         lamps[tmpPtr++] = ' ';
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

void PrintArray (int ptr)
{
   for (int i = 0; i < ptr; i++) {
      printf ("%c", lamps[i]);
   }
   for (int i = ptr; i < n; i++) {
      printf (" ");
   }
   printf ("\n");
}

void PrintOutInput ()
{
   printf ("%d\n", n);
   for (int i = 0; i < colors; i++) {
      printf ("%c %d\n", input[i].clr, input[i].nbr);
   }   
}