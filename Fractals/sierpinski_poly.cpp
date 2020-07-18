#include <graphics.h>
#include <math.h>

int main()
{
   int gd = DETECT, gm;

   initgraph(&gd, &gm, NULL);

   const int sides = 3;
   const int count = sides*100000;

   int vertice[sides][2];

   for (int i = 0; i < sides; i++)
   {
      vertice[i][0] = 300 + 240 * cos(2*M_PI/sides*i - M_PI_2);
      vertice[i][1] = 240 + 240 * sin(2*M_PI/sides*i - M_PI_2);
   }

   int px = vertice[0][0], py = vertice[0][1];

   int seed;
   for (int i = 0; i < count; i++)
   {
      seed = rand() % sides;
      px = (px + vertice[seed][0]) / 2;
      py = (py + vertice[seed][1]) / 2;
      putpixel(px, py, WHITE);
   }

   getch();
   closegraph();
   return 0;
}