#include <graphics.h>

int main()
{
   int gd = DETECT, gm;

   initgraph(&gd, &gm, NULL);

   const int count = 100000;

   const int vertice[3][2] = {{50, 480}, {290, 1}, {530, 480}};

   int px = vertice[0][0], py = vertice[0][1];

   int seed;
   for (int i = 0; i < count; i++)
   {
      seed = rand()%3;
      px = (px + vertice[seed][0])/2;
      py = (py + vertice[seed][1])/2;
      putpixel(px, py, WHITE);
   }
   

   getch();
   closegraph();
   return 0;
}