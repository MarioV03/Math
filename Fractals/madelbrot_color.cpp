#include <graphics.h>
#include <complex>
#include <cmath>

float metallic_ratio(int n)
{
	return (n + sqrt(n*n + 4))/2;
}

int mandelbrot_color(int x, int y)
{
	float R = 3;
	std::complex<float> z = std::complex<float>(0, 0);
	std::complex<float> c = std::complex<float>((x - 420) / 200.0, (y - 240) / 200.0);
	
	int color = 0;
	while (std::abs(z) < R && color < 50)
	{
		z = z*z + c;
		color++;
	}
	

	// 0 - BLACK, 1 - BLUE, 9 - LIGHT_BLUE, 3 - CYAN, 14 - YELLOW, 4 - RED
	if(color > 47) return 0;
	if(color > 22) return 4;
	if(color > 13) return 14;
	if(color > 9) return 9;
	return 1;
	// return (int)(log(700/color)) + 6;
	
}

int main()
{
	int gd = DETECT, gm;

	initgraph(&gd, &gm, NULL);

	std::complex<float> c = std::complex<float>(-0.8, 0.156);
	
	for (int x = 0; x < 640; x++)
		for (int y = 0; y < 480; y++)
			putpixel(x, y, mandelbrot_color(x, y));

	getch();
	closegraph();
	return 0;
}