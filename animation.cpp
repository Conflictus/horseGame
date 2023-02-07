#include <SFML/Graphics.hpp>
using namespace sf;
int main() {
    RenderWindow window(VideoMode(400, 400), "SFML");

    RectangleShape ground(Vector2f(640, 250));
    ground.setFillColor(Color::Yellow);
    ground.setPosition(0, 350);

    CircleShape sun (50);
    sun.setFillColor(Color::Yellow);
    float speed = 1;

    CircleShape mountain (200, 3);
    mountain.setFillColor(Color(214,128,58));
    mountain.setPosition (150,50);
    
    while (window.isOpen()) {
	Event event;
	while (window.pollEvent(event)) {
		if (event.type == Event::Closed)
		window.close();
	}
	window.clear(Color(Color::Cyan));
    window.draw(ground);
    window.draw(sun);
    window.draw(mountain);
	window.display();
	}
	return 0;
}
