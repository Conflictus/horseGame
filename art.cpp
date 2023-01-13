#include <SFML/Graphics.hpp>
using namespace sf;
const int height = 80;
const int width = 80;
int main() {
    RenderWindow window(VideoMode(400, 400), "SFML");

    RectangleShape ground(Vector2f(640, 250));
    ground.setFillColor(Color(79, 37, 6));
    ground.setPosition(0, 350);

    CircleShape sun (50);
    sun.setFillColor(Color::Yellow);
    /*
    RectangleShape building1(Vector2f(40, 250));
    building1.setFillColor(Color(Color::Blue));
    building1.setPosition (311,110);
    
    RectangleShape building2(Vector2f(90, 180));
    building2.setFillColor(Color(118, 5, 240));
    building2.setPosition (170 ,200);

    RectangleShape building3(Vector2f(100, 200));
    building3.setFillColor(Color(Color::Black));
    building3.setPosition (50 ,180); */

    Image hero_image;
    hero_image.loadFromFile("horse.png");
    Texture hero_texture;
    hero_texture.loadFromImage(hero_image);

    Sprite hero_sprite;
    hero_sprite.setTexture(hero_texture);
    hero_sprite.setTextureRect(IntRect(0,2*height , width ,height));

    Image rock_image;
    rock_image.loadFromFile("stone.png");
    Texture rock_texture;
    rock_texture.loadFromImage(rock_image);

    Sprite rock_sprite;
    rock_sprite.setTexture(rock_texture);
    rock_sprite.setTextureRect(IntRect(0,180,90,90));
    rock_sprite.setPosition (50 ,180);
    
    Clock clock;

    while (window.isOpen()) {
	Event event;
    float time = clock.getElapsedTime().asMicroseconds();
    time = time/1000;
    clock.restart();
    float current_rec = 0;
	while (window.pollEvent(event)) {
		if (event.type == Event::Closed)
		window.close();
	}
    if (Keyboard::isKeyPressed(Keyboard::Right)) {
        
        current_rec+=time*1.0;
        if (current_rec > 3) {
            current_rec-=3;
        }
        hero_sprite.setTextureRect(IntRect(int(current_rec)*width ,2*height, width, height));
        hero_sprite.move(0.1*time, 0);
    }
    if (Keyboard::isKeyPressed(Keyboard::Left)) {
        current_rec+=time*1.0;
        if (current_rec > 3) {
            current_rec-=3;
        }
        
        hero_sprite.setTextureRect(IntRect(int(current_rec)*width ,1*height ,width,height));
        hero_sprite.move(-0.1*time, 0);
    }
    if (Keyboard::isKeyPressed(Keyboard::Up)) {
        current_rec+=time*1.0;
        if (current_rec > 3) {
            current_rec-=3;
        }
        
        hero_sprite.setTextureRect(IntRect(int(current_rec)*width ,3*height ,width,height));
        hero_sprite.move( 0 , -0.1*time);
    }
    if (Keyboard::isKeyPressed(Keyboard::Down)) {
        current_rec+=time*1.0;
        if (current_rec > 3) {
            current_rec-=3;
        }
        
        hero_sprite.setTextureRect(IntRect(int(current_rec)*width ,0*height ,width,height));
        hero_sprite.move(0, 0.1*time);
    }
    if (Mouse::isButtonPressed(Mouse::Left)) {
        hero_sprite.setPosition(0,0);
    }
    if (Mouse::isButtonPressed(Mouse::Right)) {
        hero_sprite.setColor(Color::Green);
    }
    
	window.clear(Color(Color::Cyan));
    window.draw(ground);
    window.draw(sun);
    window.draw(hero_sprite);
    window.draw(rock_sprite);
    /* window.draw(building1);
    window.draw(building2);
    window.draw(building3); */
	window.display();
	}
	return 0;
}