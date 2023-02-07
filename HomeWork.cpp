#include <SFML/Graphics.hpp>
using namespace sf;
const int height = 80;
const int width = 80;

int main() {
    RenderWindow window(VideoMode(800, 800), "SFML");


    while (window.isOpen()) {
	Event event;
    
	while (window.pollEvent(event)) {
		if (event.type == Event::Closed)
		window.close();
	}
    
    
	window.clear(Color(Color::Black));
    
	window.display();
	}
	return 0;
}