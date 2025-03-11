#include "Header.hpp"

GameWindow::GameWindow(): event(sf::Event::Closed()) {
    this->window = new RenderWindow(videoMode.getDesktopMode(), "Type India !", sf::State::Windowed);
    
    this->window->setFramerateLimit(60);
}

GameWindow::~GameWindow() {
    delete this->window;
}

void GameWindow::updateMousePositions() {
    this->mousePosWindow = Mouse::getPosition(*this->window);
    this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);
}

void GameWindow::updateEvents() {
    
    // Process events
    while (const std::optional event = window->pollEvent())
    {
        // Close window: exit
        if (event->is<sf::Event::Closed>()) {
            cout<<"On Window Exit"<<endl;
            this->window->close();
        }
        else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>();
            keyPressed && keyPressed->code == sf::Keyboard::Key::Escape) {
            cout<<"On Escape pressed"<<endl;
            window->close();
        }
        else if (const auto* textEvent = event->getIf<sf::Event::TextEntered>()) {
             // Text entered event
             char32_t unicode = textEvent->unicode;
             if (unicode < 128) { // ASCII range
                std::cout << "Character Typed: " << static_cast<char>(unicode) << std::endl;
                 
                if(unicode==9) { // CHECK FOR TAB KEYPRESS
                    if (this->enemies.size() <= this->focusedEnemy + 1) {
                        this->focusedEnemy = 0;
                    } else {
                        this->focusedEnemy += 1;
                    }
                }
                else {
                    if (this->enemies.size()) {
                        this->enemies[this->focusedEnemy].checkInput(static_cast<char>(unicode));
                    }
                }
            }
        }
    
    }
}

void GameWindow::updateWindowEvents() {
    updateMousePositions();
    updateEvents();
}

bool GameWindow::isRunning() {
    return this->window->isOpen();
}

RenderWindow* GameWindow::getWindow() {
    return this->window;
}

Vector2f GameWindow::getMousePos() {
    return this->mousePosView;
}
