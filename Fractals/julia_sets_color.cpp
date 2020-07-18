#include <graphics.h>
#include <complex>
#include <cmath>

float metallic_ratio(int n)
{
	return (n + sqrt(n*n + 4))/2;
}

int julia_color(int x, int y, std::complex<float> c)
{
	float R = 3;
	std::complex<float> z = std::complex<float>((x - 320) / 200.0, (y - 240) / 200.0);
	
	int color = 0;
	while (std::abs(z) < R && color < 500)
	{
		z = z*z + c;
		color++;
	}
	

	if(color > 270) return 0;
	if(color > 150) return 4;
	if(color > 80) return 14;
	if(color > 55) return 3;
	if(color > 35) return 9;
	if(color > 15) return 1;
	return 0;
	
	// return (int)(log(700/color)) + 6;
	
}

int main()
{
	int gd = DETECT, gm;

	initgraph(&gd, &gm, NULL);

	std::complex<float> c = std::complex<float>(-0.8, 0.156);
	
	for (int x = 0; x < 640; x++)
		for (int y = 0; y < 480; y++)
			putpixel(x, y, julia_color(x, y, c));

	getch();
	closegraph();
	return 0;
}