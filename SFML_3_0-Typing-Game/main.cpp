#include "Header.hpp"


Sprite createTempSprite(RenderWindow* window)
{
    // Create a texture
    sf::Texture texture;
    
    // Try to load the texture from file
    try
    {
        if (!texture.loadFromFile("/Users/hashir/Desktop/SFML/SFML_3_0-Typing_Game/SFML_3_0-Typing-Game/Resources/Textures/Desert.jpg"))
        {
            std::cerr << "Failed to load texture\n";
            //return -1;
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error loading texture: " << e.what() << "\n";
       // return -1;
    }

    // Create sprite and set its texture
    sf::Sprite sprite(texture);

    // Center the sprite
    sf::Vector2f position((window->getSize().x - sprite.getGlobalBounds().size.x) / 2.f, (window->getSize().y - sprite.getGlobalBounds().size.y) / 2.f);
    
    sprite.setPosition(position);
    return sprite;
}



int main() {

    
    
    
    srand(static_cast<unsigned>(time(NULL)));

    GameWindow game;
    Menu menu(&game.font);
    GameOver gameover(&game.font);

    Sprite tmpsprt = createTempSprite(game.getWindow());
    
    while (game.isRunning()) {
        game.getWindow()->clear(sf::Color::White);

        
        game.getWindow()->draw(game.background);
//        game.getWindow()->draw(tmpsprt);
        game.updateWindowEvents();
 
        if (game.getDead()) {
            gameover.renderGameOver(&game);
        } else {
            if (game.getStarted()) {
                game.renderGame(*game.getWindow());
            } else {
                menu.renderMenu(&game);
            }
        }

        game.getWindow()->display();
    }
}
