#include <graphics.h>
#include <complex>

void iter(std::complex<float>& z, std::complex<float>& c)
{
   
}

bool mandelbrot(int x, int y)
{
   float c_real = (x - 420) / 200.0;
   float c_imag = (y - 240) / 200.0;
   std::complex<float> c = std::complex<float>((x - 420) / 200.0, (y - 240) / 200.0);
   std::complex<float> z = std::complex<float>(0.0, 0.0);
   float z_real = 0.0;
   float z_imag = 0.0;

   for (int i = 0; i < 20; i++)
   {
      z = z*z + c;
   }

   return (z.real() * z.real() + z.imag() * z.imag()) < 3;
}

int main()
{
   int gd = DETECT, gm;

   initgraph(&gd, &gm, NULL);

   for (int x = 0; x < 640; x++)
      for (int y = 0; y < 480; y++)
         putpixel(x, y, WHITE * mandelbrot(x, y));

   getch();
   closegraph();
   return 0;
}