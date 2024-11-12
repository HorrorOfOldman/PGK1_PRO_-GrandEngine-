#include"PrimitiveRenderer.h"
#include<stack>
#include <iostream>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro.h>
using namespace std;
#define M_PI 3.14


// Funkcja pomocnicza do pobierania koloru piksela
ALLEGRO_COLOR PrimitiveRenderer::GetPixel(int x, int y)
{
	return al_get_pixel(al_get_target_bitmap(), x, y);
}

// Funkcja pomocnicza do porównywania kolorów (ze wzglêdu na strukturê ALLEGRO_COLOR)
bool PrimitiveRenderer::CompareColors(ALLEGRO_COLOR c1, ALLEGRO_COLOR c2)
{
	return c1.r == c2.r && c1.g == c2.g && c1.b == c2.b && c1.a == c2.a;
}

//// Funkcje rysuj¹ce///////////////////////////////////
	//zrób pixel
	void PrimitiveRenderer::PutPixel(int x0, int y0, ALLEGRO_COLOR color)
	{
		al_put_pixel(x0, y0, color);
		//al_flip_display();
	}

	// Rysowanie linii
	void PrimitiveRenderer::DrawLine(int x0, int y0, int x1, int y1, ALLEGRO_COLOR color)
	{
		int dx = abs(x1 - x0);
		int dy = abs(y1 - y0);
		int stepY = (y0 < y1) ? 1 : -1;
		int stepX = (x0 < x1) ? 1 : -1;
		int error = dx - dy;
		int error2;
		while (x0 != x1 || y0 != y1) {
			al_draw_pixel(x0, y0, color);
			error2 = error + error;
			if (error2 > -dy) {
				error -= dy;
				x0 += stepX;
			}
			if (error2 < dx) {
				error += dx;
				y0 += stepY;
			}
		}
		//al_flip_display();
		cout << "Line Drawn\n";
	}

	// Rysowanie okrêgu- zwyk³a
	void PrimitiveRenderer::DrawCircle(int x0, int y0, int R, ALLEGRO_COLOR color)
	{
		float a, step;
		int x, y;
		step = 1.0 / R; // Jeden krok
		for (a = 0; a < 2 * M_PI; a += step) {
			x = x0 + R * cos(a) + 0.5; // Zaokr¹glone X
			y = y0 + R * sin(a) + 0.5; // Zaokr¹glone Y
			al_put_pixel(x, y, color);
		}
		//al_flip_display();
		cout << "Circle Drawed\n";
	}

	// Metoda rysuj¹ca okr¹g za pomoc¹ 8-krotnej symetrii (algorytm Bresenhama)
	void PrimitiveRenderer::DrawCircleSymmetry(int x0, int y0, int R, ALLEGRO_COLOR color)
	{
		int x = 0;
		int y = R;
		int d = 3 - 2 * R;  // Decyzyjna zmienna
		while (y >= x)
		{
			// 8-krotna symetria
			PutPixel(x0 + x, y0 + y, color);
			PutPixel(x0 - x, y0 + y, color);
			PutPixel(x0 + x, y0 - y, color);
			PutPixel(x0 - x, y0 - y, color);
			PutPixel(x0 + y, y0 + x, color);
			PutPixel(x0 - y, y0 + x, color);
			PutPixel(x0 + y, y0 - x, color);
			PutPixel(x0 - y, y0 - x, color);

			x++;
			if (d > 0)
			{
				y--;
				d = d + 4 * (x - y) + 10;
			}
			else
			{
				d = d + 4 * x + 6;
			}
		}
		//al_flip_display();
		cout << "Okrag z 8-k symetria\n";
	}

	// Rysowanie elipsy
	void PrimitiveRenderer::DrawEllipse(int x0, int y0, int Rx, int Ry, ALLEGRO_COLOR color)
	{
		// Ustal minimalny krok
		const float min_step = 0.01f; // Minimalny krok
		float step;

		// Oblicz krok w zale¿noœci od wartoœci promieni
		if (Rx > 0 && Ry > 0) {
			step = min_step / (Rx + Ry); // Dostosowanie kroku w oparciu o sumê promieni
		}
		else {
			step = min_step; // U¿yj minimalnego kroku, jeœli promienie s¹ zerowe
		}

		for (float angle = 0; angle < 2 * M_PI; angle += step)
		{
			int x = static_cast<int>(x0 + Rx * cos(angle) + 0.5f);  // Przemieszczenie w osi X
			int y = static_cast<int>(y0 + Ry * sin(angle) + 0.5f);  // Przemieszczenie w osi Y
			PutPixel(x, y, color);
		}
		//al_flip_display();
		cout << "Elipsa narysowana\n";
	}

	// Funkcja do rysowania prostok¹ta
	void PrimitiveRenderer::DrawRectangle(int x0, int y0, int x1, int y1, ALLEGRO_COLOR color)
	{
		DrawLine(x0, y0, x0, y1, color);
		DrawLine(x0, y1, x1, y1, color);
		DrawLine(x1, y1, x1, y0, color);
		DrawLine(x1, y0, x0, y0, color);
		//al_flip_display();
		cout << "Prostokat prostokatuje\n";
	}

	// Funkcja do rysowania trójk¹ta
	void PrimitiveRenderer::DrawTriangle(int x0, int y0, int x1, int y1, int x2, int y2, ALLEGRO_COLOR color)
	{
		//   al_draw_triangle(x1, y1, x2, y2, x3, y3, color, thickness);
		DrawLine(x0, y0, x1, y1, color);
		DrawLine(x1, y1, x2, y2, color);
		DrawLine(x2, y2, x0, y0, color);
		//al_flip_display();
		cout << "Trujkatuje\n";
	}

	//// Kolorowanie metod¹ - MA DZIA£AÆ ////////////////////////

	// Wype³niony prostok¹t
	void PrimitiveRenderer::DrawFilledRectangle(int x0, int y0, int x1, int y1, ALLEGRO_COLOR color)
	{
		// Rysowanie prostok¹ta poprzez wype³nianie go liniami poziomymi
		for (int y = y0; y <= y1; y++)
		{
			DrawLine(x0, y, x1, y, color); // Wype³nianie
		}
		//al_flip_display();
		cout << "Wypelniony prostokat narysowany\n";
	}

	// Funkcja do rysowania wype³nionego trójk¹ta (metoda skan-linii)
	void PrimitiveRenderer::DrawFilledTriangle(int x0, int y0, int x1, int y1, int x2, int y2, ALLEGRO_COLOR color)
	{
		// Posortowanie wierzcho³ków wed³ug wspó³rzêdnych Y (y0 <= y1 <= y2)
		if (y0 > y1) { std::swap(x0, x1); std::swap(y0, y1); }
		if (y1 > y2) { std::swap(x1, x2); std::swap(y1, y2); }
		if (y0 > y1) { std::swap(x0, x1); std::swap(y0, y1); }

		auto interpolate = [](int x0, int y0, int x1, int y1, int y) -> int
		{
			if (y1 == y0) return x0; // Unikamy dzielenia przez zero
			return x0 + (x1 - x0) * (y - y0) / (y1 - y0);
		};

		for (int y = y0; y <= y2; y++) {
			int x_start = (y <= y1) ? interpolate(x0, y0, x1, y1, y) : interpolate(x1, y1, x2, y2, y);
			int x_end = interpolate(x0, y0, x2, y2, y);
			DrawLine(x_start, y, x_end, y, color);
		}
		//al_flip_display();
		cout << "Wypelniony trojkat narysowany\n";
	}

	// Wype³niony okr¹g (rysowanie linii poziomych dla ka¿dego "ringu")
	void PrimitiveRenderer::DrawFilledCircle(int x0, int y0, int R, ALLEGRO_COLOR color)
	{
		for (int y = -R; y <= R; y++) {
			int dx = (int)sqrt(R * R - y * y); // Odleg³oœæ pozioma dla ka¿dego Y
			DrawLine(x0 - dx, y0 + y, x0 + dx, y0 + y, color);
		}
		//al_flip_display();
		cout << "Wypelniony okrag narysowany\n";
	}

	//// Inteligentniejsze kolorowanie - to o którym wspomina³ ³ukawski na wyk³adzie /////////////////////////////////////

	// Border Fill Algorithm (iteracyjny)
	void PrimitiveRenderer::BorderFill(int x, int y, ALLEGRO_COLOR fillColor, ALLEGRO_COLOR borderColor)
	{
		std::stack<std::pair<int, int>> pixelStack;
		pixelStack.push({ x, y });

		while (!pixelStack.empty()) {
			std::pair<int, int> currentPixel = pixelStack.top();
			int px = currentPixel.first;
			int py = currentPixel.second;
			pixelStack.pop();

			ALLEGRO_COLOR currentColor = GetPixel(px, py);

			if (!CompareColors(currentColor, borderColor) && !CompareColors(currentColor, fillColor)) {
				PutPixel(px, py, fillColor);

				pixelStack.push({ px + 1, py });
				pixelStack.push({ px - 1, py });
				pixelStack.push({ px, py + 1 });
				pixelStack.push({ px, py - 1 });
			}
		}
		cout << "Obszar wypelniony (border fill)\n";
	}

	// Flood Fill Algorithm (iteracyjny)
	void PrimitiveRenderer::FloodFill(int x, int y, ALLEGRO_COLOR fillColor)
	{
		std::stack<std::pair<int, int>> pixelStack;
		ALLEGRO_COLOR targetColor = GetPixel(x, y);

		if (CompareColors(targetColor, fillColor)) return;

		pixelStack.push({ x, y });

		while (!pixelStack.empty()) {
			std::pair<int, int> currentPixel = pixelStack.top();
			int px = currentPixel.first;
			int py = currentPixel.second;
			pixelStack.pop();

			ALLEGRO_COLOR currentColor = GetPixel(px, py);

			if (CompareColors(currentColor, targetColor)) {
				PutPixel(px, py, fillColor);

				pixelStack.push({ px + 1, py });
				pixelStack.push({ px - 1, py });
				pixelStack.push({ px, py + 1 });
				pixelStack.push({ px, py - 1 });
			}
		}
		cout << "Obszar wypelniony (flood fill)\n";
	}

	// testownik
	void PrimitiveRenderer::xd(int x, int y, int size, ALLEGRO_COLOR color)
	{

	}