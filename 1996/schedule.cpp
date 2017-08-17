#include <stdio.h>
#include <memory.h>

#define MAXTEAMS 64
bool used[MAXTEAMS+1][MAXTEAMS+1];
bool scheduled[MAXTEAMS+1];

int total;
int GetTotal (int exp)
{
   int ans = 1;
   for (int i = 0; i < exp; i++) {
      ans *= 2;
   }
   return ans;
}

int SelectOneTeam ()
{
   for (int i = 1; i <= total; i++) {
      if (!scheduled[i]) {
         scheduled[i] = true;
         return i;
      }
   }
   return 0;
}

int FindAMatch(int a)
{
   for (int i = 1; i <= total; i++) {
      if (!scheduled[i] && !used[a][i]) {
         scheduled[i] = true;
         return i;
      }
   }
   return 0;
}

void MarkUsed (int a, int b)
{
   used[a][b] = used[b][a] = true;
}

int main ()
{
   int n;
   scanf ("%d", &n); 
   total = GetTotal(n);
   memset (used, 0, sizeof (used));
   for (int i = 1; i <= total; i++ ) {
      used[i][i] = true;
   }

   for (int i = 2; i <= total; i++) {
      memset (scheduled, 0, sizeof (scheduled));
      scheduled[1] = scheduled[i] = true;
      printf ("1==%d\t", i);
      MarkUsed (1, i);
      int a, b;
      while ((a = SelectOneTeam()) != 0) {
         b = FindAMatch(a);
         MarkUsed (a, b);
         printf ("%d==%d\t", a, b);
      }
      printf ("\n");
   }
   return 0;
}