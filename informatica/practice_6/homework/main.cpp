
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
using namespace sf;

const int cellSize = 50;
const int gridSize = 15;

int main()
{
	int n = 10;
	RenderWindow window(VideoMode({ 500, 500 }), "Grid 5x5 SFML");
	RectangleShape cells[gridSize][gridSize];

	for (int i = 0; i < gridSize; ++i) {

		for (int j = 0; j < gridSize; ++j) {
			cells[i][j].setSize(Vector2f(cellSize - 2, cellSize - 2));
			cells[i][j].setPosition(i * cellSize, j * cellSize);
			if (i + j < n - 1) 
			{
				cells[i][j].setFillColor(Color::Green);
			}
			cells[i][j].setOutlineColor(Color::Black);
			cells[i][j].setOutlineThickness(1);
		}
	}
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear(Color::White);
		for (int i = 0; i < gridSize; ++i) 
		{
			for (int j = 0; j < gridSize; ++j) 
			{
				window.draw(cells[i][j]);
			}
		}
		window.display();
	}
	
	return 0;
}