#define SIZE 100
#define COIN 6

#include<stdio.h>

int min[SIZE + 1], coin_num[COIN], change;
const int coin[] = { 5, 10, 20, 50, 100, 200 };

int find_minimal_hand(int amount);

int main(void)
{
   int i, j, temp, amount;
   double value;

   //Find the minimal number of coin needed to pay different amount by the shopkeeper.
   for(i = 1, min[0] = 0; i <= SIZE; i++)
   {      
      for(j = COIN - 1, amount = i * 5; j >= 0; j--)
      {
         if ((temp = amount / coin[j]) != 0) break;
      }

      min[i] = min[(amount - temp * coin[j]) / 5] + temp;
   }

   while(1)
   {
      for(i = 0; i < COIN; i++) scanf(" %d", &coin_num[i]);
      for(i = 0; i < COIN; i++) if (coin_num[i] != 0) break;
      if (i == COIN) break;

      scanf(" %lf", &value);
      amount = int(value * 100 + 0.5);

      if (amount == 0)
      {
         printf("%3d\n", 0);
         continue;
      }
      
      for(i = amount / 5, change = -1; i <= SIZE; i++)
      {
         if ((temp = find_minimal_hand(i * 5)) != 0)
         {
            temp += min[i - amount / 5];
            if (change == -1 || temp < change) change = temp;
         }
      }

      printf("%3d\n", change);
   }
   
   return(0);
}

int find_minimal_hand(int amount)
{
   int i, j, hand = 0;
   
   for(i = COIN - 1; i >= 0; i--)
   {
      for(j = 0; j < coin_num[i]; j++)
      {
         if (int(amount / coin[i]) == 0) break;
         
         hand++;
         amount -= coin[i];
         if (amount == 0) return(hand);
      }
   }
   
   return(0);
}