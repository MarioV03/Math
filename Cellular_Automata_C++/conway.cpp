#include <GL/freeglut.h>

#include <time.h>
#include <iostream>

#define WIDTH 480
#define HEIGHT 250
#define scale 4
#define delay 30

int current = 0;

using namespace std;

bool * grid;

void init_grid()
{
   for (int y = 0; y < HEIGHT; y++)
      for (int x = 0; x < WIDTH; x++)
         cin >> grid[0][x][y];
}


void random_grid()
{
   for (int y = 0; y < HEIGHT; y++)
      for (int x = 0; x < WIDTH; x++)
         grid[0][x][y] = rand()%100 > 90;
}


bool check_cell(int x, int y)
{
   int neighbors = 0;
   neighbors += grid[current][(x - 1 + WIDTH) % WIDTH][(y + 1) % HEIGHT] + grid[current][x][(y + 1) % HEIGHT] + grid[current][(x + 1) % WIDTH][(y + 1) % HEIGHT]; //row above
   neighbors += grid[current][(x - 1 + WIDTH) % WIDTH][(y - 1 + HEIGHT) % HEIGHT] + grid[current][x][(y - 1 + HEIGHT) % HEIGHT] + grid[current][(x + 1) % WIDTH][(y - 1 + HEIGHT) % HEIGHT]; //row below
   neighbors += grid[current][(x - 1 + WIDTH) % WIDTH][y] + grid[current][(x + 1) % WIDTH][y];

   return neighbors == 3 || (neighbors == 2 && grid[current][x][y]);
}

void compute_next_grid()
{
   for (int x = 0; x < WIDTH; x++)
   {
      for (int y = 0; y < HEIGHT; y++)
      {
         grid[!current][x][y] = check_cell(x, y);
      }
   }
}

void print_grid()
{
   for (int y = 0; y < HEIGHT; y++)
   {
      for (int x = 0; x < WIDTH; x++)
      {
         cout << (char)(' ' + 3 * grid[current][x][y]) << " ";
      }
      cout << endl;
   }
   cout << endl;
}

void draw_sq(int x, int y, bool active)
{
   glColor3f(active, active, active);
   glVertex2f(x, y);
   glVertex2f((x + 1), y);
   glVertex2f((x + 1), (y + 1));
   glVertex2f(x, (y + 1));
}

void draw_grid()
{
   glClear(GL_COLOR_BUFFER_BIT);
   glBegin(GL_QUADS);
   for (int y = 0; y < HEIGHT; y++)
   {
      for (int x = 0; x < WIDTH; x++)
      {
         draw_sq(x, y, grid[current][x][y]);
      }
   }
   glEnd();
   glutSwapBuffers();
}

void timer(int value)
{
   compute_next_grid();
   current = (current + 1)&1;
   glutPostRedisplay();
   glutTimerFunc(delay, timer, 0);
}

int main(int argc, char **argv)
{
   srand(time(NULL));
   random_grid();
   
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_RGB);
   glutInitWindowSize(WIDTH * scale, HEIGHT * scale);
   glutInitWindowPosition(50, 50);

   glutCreateWindow("The Game of Life");
   glutDisplayFunc(draw_grid);
   glutTimerFunc(delay, timer, 0);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(0, WIDTH, 0, HEIGHT, -1, 1);

   glutMainLoop();

   return 0;
}