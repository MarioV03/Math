#include <GL/freeglut.h>

#include <time.h>
#include <iostream>
#include <vector>

using namespace std;

class Game
{
public:
   int WIDTH;
   int HEIGHT;
   int scale;
   int delay;

   vector<bool> grid[2];
   int current;

   Game(int _width, int _height, int _scale, int _delay)
   {
      WIDTH = _width;
      HEIGHT = _height;
      scale = _scale;
      delay = _delay;

      grid[0].reserve(WIDTH * HEIGHT);
      grid[1].reserve(WIDTH * HEIGHT);
      current = 0;
   }

   void init_grid()
   {
      bool temp;
      for (int y = 0; y < HEIGHT; y++)
         for (int x = 0; x < WIDTH; x++)
         {
            cin >> temp;
            grid[0][x + WIDTH * y] = temp;
         }
   }

   void random_grid(int seed)
   {
      srand(seed);
      for (int y = 0; y < HEIGHT; y++)
         for (int x = 0; x < WIDTH; x++)
            grid[0][x + WIDTH * y] = rand() % 100 > 90;
   }

   void update()
   {
      for (int x = 0; x < WIDTH; x++)
      {
         for (int y = 0; y < HEIGHT; y++)
         {
            grid[!current][x + WIDTH * y] = check_cell(x, y);
         }
      }
   }

   void draw_sq(int x, int y, bool active)
   {
      glColor3f(active, active, active);
      glVertex2f(x, y);
      glVertex2f((x + 1), y);
      glVertex2f((x + 1), (y + 1));
      glVertex2f(x, (y + 1));
   }

   void print_grid()
   {
      for (int y = 0; y < HEIGHT; y++)
      {
         for (int x = 0; x < WIDTH; x++)
         {
            cout << (char)(' ' + 3 * grid[current][x + WIDTH * y]) << " ";
         }
         cout << endl;
      }
      cout << endl;
   }

private:
   bool
   check_cell(int x, int y)
   {

      int neighbors = 0;
      neighbors += grid[current][(x - 1 + WIDTH) % WIDTH + WIDTH * ((y + 1) % HEIGHT)];
      neighbors += grid[current][x + WIDTH * ((y + 1) % HEIGHT)];
      neighbors += grid[current][(x + 1) % WIDTH + WIDTH * ((y + 1) % HEIGHT)];
      neighbors += grid[current][(x - 1 + WIDTH) % WIDTH + WIDTH * ((y - 1 + HEIGHT) % HEIGHT)];
      neighbors += grid[current][x + WIDTH * ((y - 1 + HEIGHT) % HEIGHT)];
      neighbors += grid[current][(x + 1) % WIDTH + WIDTH * ((y - 1 + HEIGHT) % HEIGHT)];
      neighbors += grid[current][(x - 1 + WIDTH) % WIDTH + WIDTH * y];
      neighbors += grid[current][(x + 1) % WIDTH + WIDTH * y];

      return neighbors == 3 || (neighbors == 2 && grid[current][x + WIDTH * y]);
   }
} game(17,17, 32, 500);

void timer(int value)
{
   game.update();
   game.current = (game.current + 1) & 1;
   glutPostRedisplay();
   glutTimerFunc(game.delay, timer, 0);
}

void draw_grid()
{
   glClear(GL_COLOR_BUFFER_BIT);
   glBegin(GL_QUADS);
   for (int y = 0; y < game.HEIGHT; y++)
   {
      for (int x = 0; x < game.WIDTH; x++)
      {
         game.draw_sq(x, y, game.grid[game.current][x + game.WIDTH * y]);
      }
   }
   glEnd();
   glutSwapBuffers();
}

int main(int argc, char **argv)
{
   int seed = time(NULL);
   // cin >> seed;
   //game.random_grid(seed);

   game.init_grid();
   
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_RGB);
   glutInitWindowSize(game.WIDTH * game.scale, game.HEIGHT * game.scale);
   glutInitWindowPosition(50, 50);

   glutCreateWindow("The Game of Life");
   glutDisplayFunc(draw_grid);
   glutTimerFunc(game.delay, timer, 0);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(0, game.WIDTH, 0, game.HEIGHT, -1, 1);

   glutMainLoop();

   return 0;
}