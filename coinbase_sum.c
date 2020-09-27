#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main()
{

   int blockheight = 0;
   int64_t coinmarketcap = 0;

   while (blockheight < 4209402)
   {
      blockheight += 1;
      
      if (blockheight == 1)                                    { coinmarketcap += 3000000;  }
      if (blockheight > 1 && blockheight <= 1000)              { coinmarketcap += 0;  }
      if (blockheight >= 1001 && blockheight <= 530201)        { coinmarketcap += 20; }
      if (blockheight >= 530202 && blockheight <= 1055801)     { coinmarketcap += 16; }
      if (blockheight >= 1055802 && blockheight <= 1581401)    { coinmarketcap += 14; }
      if (blockheight >= 1581402 && blockheight <= 2107001)    { coinmarketcap += 12; }
      if (blockheight >= 2107002 && blockheight <= 2632601)    { coinmarketcap += 10; }
      if (blockheight >= 2632602 && blockheight <= 3158201)    { coinmarketcap += 8; }
      if (blockheight >= 3158202 && blockheight <= 3683801)    { coinmarketcap += 6; }
      if (blockheight >= 3683802 && blockheight <= 4209401)    { coinmarketcap += 4; }
      if (blockheight >= 4209402 && blockheight <= 4736001)    { coinmarketcap += 2; }
      if (blockheight >= 4736002)                              { coinmarketcap += 1; }

      printf ("block #%08d - %lu \n", blockheight, coinmarketcap);

          }

}
