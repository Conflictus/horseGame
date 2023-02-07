#include <SFML/Graphics.hpp>
#include "Player.h"
#include "map.h"
#include "camera.h"
using namespace sf;
const int SCREEN_H = 800;
const int SCREEN_W = 800;
int main (){
    RenderWindow window(VideoMode(800, 800), "SFML");
    Player player("horse.png", 80, 80);
    Clock clock;
    view.reset(FloatRect(0,0,400,280));
    Image map_image;
    map_image.loadFromFile("images/map2.png");
    Texture map_texture;
    map_texture.loadFromImage(map_image);
    Sprite map_sprite;
    map_sprite.setTexture(map_texture);
    while (window.isOpen()) {
        float time = clock.getElapsedTime().asMicroseconds();
        time = time*0.001;
        
	    Event event;
    
    
	while (window.pollEvent(event)) {
		if (event.type == Event::Closed)
		    { window.close(); }
      
	}

    window.clear(Color(Color::White));
	    player.control();

        player.update(time);
        player.run_animate(time);
        change_view(player.get_x(), player.get_y());
        window.setView(view);
	clock.restart();
	    
    for (int h=0; h<HEIGHT_MAP; h++){
        for(int w=0; w<WIDTH_MAP; w++) {
            if(TileMap[h][w]=='s'){
                map_sprite.setTextureRect(IntRect(WIDTH_MAP_TILE*3, WIDTH_MAP_TILE*0, WIDTH_MAP_TILE, HEIGHT_MAP_TILE));
            }
            if(TileMap[h][w]=='g'){
                map_sprite.setTextureRect(IntRect(WIDTH_MAP_TILE*7, WIDTH_MAP_TILE*5, WIDTH_MAP_TILE, HEIGHT_MAP_TILE));
            }
            map_sprite.setPosition(w*WIDTH_MAP_TILE, h*HEIGHT_MAP_TILE);
            window.draw(map_sprite);
        }
    }
    window.draw(map_sprite);
    window.draw(player.sprite);
	window.display();
    
    
    }
    
	
    
}
