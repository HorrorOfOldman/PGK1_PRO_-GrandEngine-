//https://www.youtube.com/watch?v=QTqNVHtc_us
#include <iostream>
#include <windows.h>
#include <vector>
#include <stack>
#include <cmath>
#include <algorithm>
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/keyboard.h>
#include <allegro5/mouse.h>

#define M_PI 3.14
using namespace std;


ALLEGRO_COLOR white = al_map_rgb(255, 255, 255);
ALLEGRO_COLOR red = al_map_rgb(255, 0, 0);
ALLEGRO_COLOR green = al_map_rgb(0, 255, 0);
ALLEGRO_COLOR blue = al_map_rgb(0, 0, 255);
ALLEGRO_COLOR black = al_map_rgb(0, 0, 0);

class PrimitiveRenderer
{
public:
	PrimitiveRenderer() {}

public:
	ALLEGRO_COLOR white = al_map_rgb(255, 255, 255);
	ALLEGRO_COLOR red = al_map_rgb(255, 0, 0);
	ALLEGRO_COLOR green = al_map_rgb(0, 255, 0);
	ALLEGRO_COLOR blue = al_map_rgb(0, 0, 255);
	ALLEGRO_COLOR black = al_map_rgb(0, 0, 0);

	// Funkcja pomocnicza do pobierania koloru piksela
	ALLEGRO_COLOR GetPixel(int x, int y)
	{
		return al_get_pixel(al_get_target_bitmap(), x, y);
	}

	// Funkcja pomocnicza do porównywania kolorów (ze wzglêdu na strukturê ALLEGRO_COLOR)
	bool CompareColors(ALLEGRO_COLOR c1, ALLEGRO_COLOR c2)
	{
		return c1.r == c2.r && c1.g == c2.g && c1.b == c2.b && c1.a == c2.a;
	}

	//// Funkcje rysuj¹ce///////////////////////////////////
public:
	//zrób pixel
	void PutPixel(int x0, int y0, ALLEGRO_COLOR color)
	{
		al_put_pixel(x0, y0, color);
		//al_flip_display();
	}

	// Rysowanie linii
	void DrawLine(int x0, int y0, int x1, int y1, ALLEGRO_COLOR color)
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
	void DrawCircle(int x0, int y0, int R, ALLEGRO_COLOR color)
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
	void DrawCircleSymmetry(int x0, int y0, int R, ALLEGRO_COLOR color)
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
	void DrawEllipse(int x0, int y0, int Rx, int Ry, ALLEGRO_COLOR color)
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
	void DrawRectangle(int x0, int y0, int x1, int y1, ALLEGRO_COLOR color)
	{
		DrawLine(x0, y0, x0, y1, color);
		DrawLine(x0, y1, x1, y1, color);
		DrawLine(x1, y1, x1, y0, color);
		DrawLine(x1, y0, x0, y0, color);
		//al_flip_display();
		cout << "Prostokat prostokatuje\n";
	}

	// Funkcja do rysowania trójk¹ta
	void DrawTriangle(int x0, int y0, int x1, int y1, int x2, int y2, ALLEGRO_COLOR color)
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
	void DrawFilledRectangle(int x0, int y0, int x1, int y1, ALLEGRO_COLOR color)
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
	void DrawFilledTriangle(int x0, int y0, int x1, int y1, int x2, int y2, ALLEGRO_COLOR color)
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
	void DrawFilledCircle(int x0, int y0, int R, ALLEGRO_COLOR color)
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
	void BorderFill(int x, int y, ALLEGRO_COLOR fillColor, ALLEGRO_COLOR borderColor)
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
	void FloodFill(int x, int y, ALLEGRO_COLOR fillColor)
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
	void xd(int x, int y, int size, ALLEGRO_COLOR color)
	{

	}

	//Zegar, bo czemu by nie
	void DrawClock(int x0, int y0, int R, ALLEGRO_COLOR color, int time)
	{
		int y, x;
		for (int i = 0; i < time; i++)
		{
			DrawCircle(x0, y0, R, color);
			x = x0 + R * cos(i) + 0.5;
			y = y0 + R * sin(i) + 0.5;
			DrawLine(x0, y0, x, y, color);
			Sleep(1);
			al_map_rgb(0, 0, 0);
			al_flip_display();
		}
	}
};

class Point2D
{
private:
	int x, y; // Wspó³rzêdne punktu
	ALLEGRO_COLOR color; // Kolor punktu

public:
	// Konstruktor domyœlny
	Point2D() : x(0), y(0), color(al_map_rgb(255, 255, 255)) {}

	// Konstruktor z parametrami (pozycja + kolor)
	Point2D(int x, int y, ALLEGRO_COLOR color) : x(x), y(y), color(color) {}

	// Metoda do odczytania wspó³rzêdnych
	void GetCoordinates(int& outX, int& outY) const
	{
		outX = x;
		outY = y;
	}

	// Metoda do zmiany wspó³rzêdnych
	void SetCoordinates(int newX, int newY)
	{
		x = newX;
		y = newY;
	}

	// Metoda do zmiany koloru punktu
	void SetColor(ALLEGRO_COLOR newColor)
	{
		color = newColor;
	}

	// Metoda do rysowania punktu
	void DrawPoint(PrimitiveRenderer& renderer)
	{
		renderer.PutPixel(x, y, color);
	}

	// Metoda do wyœwietlania wspó³rzêdnych w konsoli
	void DisplayCoordinates() const
	{
		cout << "Point coordinates: (" << x << ", " << y << ")" << endl;
	}
};

class LineSegment {
private:
	Point2D start; // Pocz¹tek odcinka
	Point2D end;   // Koniec odcinka

public:
	// Konstruktor
	LineSegment(Point2D start, Point2D end) : start(start), end(end) {}

	// Metoda do odczytu wspó³rzêdnych pocz¹tku i koñca
	void GetCoordinates(int& startX, int& startY, int& endX, int& endY) const {
		start.GetCoordinates(startX, startY);
		end.GetCoordinates(endX, endY);
	}

	// Metoda do zmiany wspó³rzêdnych pocz¹tku i koñca
	void SetCoordinates(Point2D newStart, Point2D newEnd) {
		start = newStart;
		end = newEnd;
	}

	// Metoda do rysowania odcinka
	void DrawSegment(PrimitiveRenderer& renderer, bool incremental = false)
	{
		int startX, startY, endX, endY;
		GetCoordinates(startX, startY, endX, endY);

//		if (incremental) {
//			DrawIncremental(renderer, startX, startY, endX, endY);
//		}
//		else
//		{
			renderer.DrawLine(startX, startY, endX, endY, renderer.white); // Domyœlny kolor
//		}
	}

private:
	// Metoda do rysowania przyrostowego (jeœli potrzebne)
	void DrawIncremental(PrimitiveRenderer& renderer, int x0, int y0, int x1, int y1) {
		int dx = x1 - x0;
		int dy = y1 - y0;
		int step = max(abs(dx), abs(dy));
		float xIncrement = dx / (float)step;
		float yIncrement = dy / (float)step;
		float x = x0;
		float y = y0;

		for (int i = 0; i <= step; i++) {
			renderer.PutPixel((int)(x + 0.5), (int)(y + 0.5), renderer.white); // Rysowanie pikseli
			x += xIncrement;
			y += yIncrement;
		}
	}
};

class Engine
{
private:
	ALLEGRO_DISPLAY* display;
	ALLEGRO_EVENT_QUEUE* event_queue;
	ALLEGRO_TIMER* timer;
	int screen_width;
	int screen_height;
	bool fullscreen;
	bool running;
	int fps;

	PrimitiveRenderer r1;

public:
	ALLEGRO_COLOR white = al_map_rgb(255, 255, 255);
	ALLEGRO_COLOR red = al_map_rgb(255, 0, 0);
	ALLEGRO_COLOR green = al_map_rgb(0, 255, 0);
	ALLEGRO_COLOR blue = al_map_rgb(0, 0, 255);
	ALLEGRO_COLOR black = al_map_rgb(0, 0, 0);

public:
	// Konstruktor
	Engine()
	{
		display = nullptr;
		event_queue = nullptr;
		timer = nullptr;
		screen_width = 800; // Domyœlna szerokoœæ
		screen_height = 600; // Domyœlna wysokoœæ
		fullscreen = false; // Domyœlnie tryb okienkowy
		fps = 60; // Domyœlna liczba FPS
		running = true;
	}

	// Inicjalizacja Allegro
	bool Init()
	{
		if (!al_init())
		{
			LogError("Failed to initialize Allegro.");
			return false;
		}

		// Inicjalizacja dodatków do Allegro
		al_install_keyboard();
		al_install_mouse();
		al_init_primitives_addon();

		// W³¹czamy podwójne buforowanie (domyœlne w Allegro)
		al_set_new_display_option(ALLEGRO_SINGLE_BUFFER, 0, ALLEGRO_SUGGEST);  // Wy³¹czamy pojedyncze buforowanie
		al_set_new_display_option(ALLEGRO_SWAP_METHOD, 2, ALLEGRO_SUGGEST);   // 2 oznacza podwójne buforowanie

		return true;
	}

	//Podanie rozmiaru okna w konsoli-do pretestów
	void ScreenProperties()
	{
		cout << endl << "Podaj rozmiar x okna = "; cin >> screen_width;
		cout << endl << "Podaj rozmiar y okna = "; cin >> screen_height;
	}

	// Ustawienia trybu graficznego (parametryzacja)
	void SetGraphicsMode(int width, int height, bool is_fullscreen)
	{
		screen_width = width;
		screen_height = height;
		fullscreen = is_fullscreen;

		// Ustawienia trybu pe³noekranowego
		if (fullscreen)
		{
			al_set_new_display_flags(ALLEGRO_FULLSCREEN);
		}
		else
		{
			al_set_new_display_flags(ALLEGRO_WINDOWED);
		}

		display = al_create_display(screen_width, screen_height);
		al_set_window_position(display, 300, 300);
		al_set_window_title(display, "GrandeEngine(PapajEngine_WERSZYN)");

		if (!display)
		{
			LogError("Failed to create display.");
		}
	}

	// Parametryzacja innych ustawieñ (FPS, input)
	void SetOtherSettings(int target_fps)
	{
		fps = target_fps;

		// Tworzenie timera na podstawie FPS
		timer = al_create_timer(1.0 / fps);
		if (!timer)
		{
			LogError("Failed to create timer.");
		}

		event_queue = al_create_event_queue();
		if (!event_queue)
		{
			LogError("Failed to create event queue.");
		}

		// Rejestracja Ÿróde³ zdarzeñ
		al_register_event_source(event_queue, al_get_display_event_source(display));
		al_register_event_source(event_queue, al_get_timer_event_source(timer));
		al_register_event_source(event_queue, al_get_keyboard_event_source());
		al_register_event_source(event_queue, al_get_mouse_event_source());
	}

	// G³ówna pêtla gry
	void GameLoop()
	{
		al_start_timer(timer);
		while (running)
		{
			ALLEGRO_EVENT ev;
			al_wait_for_event(event_queue, &ev);

			if (ev.type == ALLEGRO_EVENT_TIMER)
			{
				// Aktualizacja logiki gry

				// Rysowanie ekranu
				//ClearScreen(al_map_rgb(0, 0, 0)); // Czarny ekran
				// Dodaj kod rysowania elementów gry
				al_flip_display();  // Zamiana buforów po rysowaniu
			}
			else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
			{
				running = false; // Zamyka grê
			}
			else if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
			{
				HandleKeyboard(ev.keyboard.keycode); // Obs³uga klawiatury
//				HandleKeyboard()
			}
			else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
			{
				HandleMouse(ev.mouse.button, ev.mouse.x, ev.mouse.y); // Obs³uga myszy
			}


		}
	}

	// Obs³uga klawiatury
	void HandleKeyboard(int keycode)
	{
		if (keycode == ALLEGRO_KEY_ESCAPE)
		{
			running = false; // Zamknij grê po wciœniêciu ESC
		}
		if (keycode == ALLEGRO_KEY_W) // Rysuj kwadrat po wciœniêciu "w"
		{
			//cout << "W wciœniête" << endl;
			// Rysuj kwadrat, korzystaj¹c z metody DrawRectangle
			float side_length = 100; // D³ugoœæ boku kwadratu
			float x_start = 10;      // Pocz¹tkowa pozycja X
			float y_start = 10;      // Pocz¹tkowa pozycja Y
			ALLEGRO_COLOR color = al_map_rgb(255, 0, 0); // Kolor kwadratu (czerwony)

			// Rysowanie kwadratu o boku `side_length`
			r1.DrawRectangle(x_start, y_start, side_length, side_length, color);

			// Odœwie¿ ekran, aby wyœwietliæ rysunek
			al_flip_display();
			//Sleep(1000);

		}
		if (keycode == ALLEGRO_KEY_1) // odœwierz ekran po wciœniêciu "1"
		{
			al_flip_display();
			cout << "Special 1\n";
		}
		if (keycode == ALLEGRO_KEY_2) // zrób czarny ekran/"oczyœæ go"
		{
			ClearScreen(al_map_rgb(0, 0, 0)); // Czarny ekran
			cout << "Special 2\n";
		}
		// Dodaj obs³ugê innych klawiszy
	}

	// Obs³uga myszy
	void HandleMouse(int button, int x, int y)
	{
		if (button == 1) // Lewy przycisk myszy
		{
			cout << "LMouse clicked at (" << x << ", " << y << ")" << endl;
		}
		if (button == 2)// Prawy przycisk myszy
		{
			cout << "RMouse clicked at (" << x << ", " << y << ")" << endl;
		}
	}

	// Czyszczenie ekranu (bitmapy) do zadanego koloru
	void ClearScreen(ALLEGRO_COLOR color)
	{
		al_clear_to_color(color);
	}

	// Logowanie b³êdów
	void LogError(const char* message)
	{
		al_show_native_message_box(nullptr, "Error", "Engine Error", message, nullptr, ALLEGRO_MESSAGEBOX_ERROR);
	}

	// Zamykanie gry (deinicjacja Allegro)
	void Shutdown()
	{
		if (timer)
		{
			al_destroy_timer(timer);
		}
		if (display)
		{
			al_destroy_display(display);
		}
		if (event_queue)
		{
			al_destroy_event_queue(event_queue);
		}
	}


};

// G³ówna funkcja
int main()
{
	Engine engine;

	// Inicjalizacja silnika
	if (!engine.Init())
	{
		return -1;
	}

	// Ustawienia trybu graficznego (800x600, tryb okienkowy)
	engine.SetGraphicsMode(800, 600, false);

	// Ustawienia innych parametrów (60 FPS)
	engine.SetOtherSettings(60);

	// Utworzenie obiektu PrimitiveRenderer
	PrimitiveRenderer rysuj;

	// Utworzenie punktu 
	Point2D punkt(400, 300, engine.red);

	// Rysowanie punktu
	punkt.DrawPoint(rysuj);

	// Wyœietla wspó³rzêdne w konsoli
	
	punkt.DisplayCoordinates();
	al_flip_display();
	Sleep(2000);
	//////
	Point2D startPoint(100, 150, engine.red);
	Point2D endPoint(200, 450, engine.blue);
	LineSegment segment(startPoint, endPoint);
	segment.DrawSegment(rysuj);
	

	al_flip_display();
	Sleep(2000);
	

	// narysuj okr¹g za pomoc¹ symetrii
	rysuj.DrawCircleSymmetry(100, 100, 50, red);
	// elipsa za pomoca symetrii
	rysuj.DrawEllipse(300, 300, 50, 70, blue);
	al_flip_display();
	Sleep(1000);

	rysuj.DrawRectangle(300, 10, 400, 110, red);

	rysuj.DrawFilledRectangle(700, 500, 800, 600, red);
	rysuj.DrawFilledCircle(300, 300, 50, blue);
	rysuj.DrawFilledTriangle(50, 50, 100, 100, 50, 90, white);

	rysuj.DrawFilledRectangle(700, 500, 800, 600, red);
	rysuj.FloodFill(750, 550, blue);
	rysuj.DrawLine(50, 50,100, 300, blue);




	al_flip_display();
	Sleep(1000);
	// Uruchomienie g³ównej pêtli gry
	engine.GameLoop();

	// Zamykanie gry
	engine.Shutdown();

	return 0;
}
