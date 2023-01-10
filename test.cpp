#include <SFML/Graphics.hpp>
using namespace sf;
int main()
{
	RenderWindow window(VideoMode(400, 400), "SFML");
	CircleShape triangle (100, 3);
	CircleShape square (100, 4);
	triangle.setFillColor(Color::Green);
	square.setFillColor(Color::Blue);
	square.move(-40,220);
	square.rotate(-45);
	
	
	triangle.setOutlineThickness(10);

	while (window.isOpen()) {
	Event event;
	while (window.pollEvent(event)) {
		if (event.type == Event::Closed)
		window.close();
	}
	window.clear(Color(255,255,255));
	window.draw(triangle);
	window.draw(square);
	window.display();
	}
	return 0;
}
