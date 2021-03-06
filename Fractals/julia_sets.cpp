#include <graphics.h>
#include <complex>

float metallic_ratio(int n)
{
	return (n + sqrt(n*n + 4))/2;
}

bool julia(int x, int y, std::complex<float> c)
{
	float R = 3;
	std::complex<float> z = std::complex<float>((x - 320) / 200.0, (y - 240) / 200.0);

	for (int i = 0; i < 300; i++)
	{
		z = z*z + c;
	}

	return (z.real() * z.real() + z.imag() * z.imag()) < R*R;
}

int main()
{
	int gd = DETECT, gm;

	initgraph(&gd, &gm, NULL);

	std::complex<float> c = std::complex<float>(-0.8, 0.156);
	
	for (int x = 0; x < 640; x++)
		for (int y = 0; y < 480; y++)
			putpixel(x, y, WHITE * julia(x, y, c));

	getch();
	closegraph();
	return 0;
}