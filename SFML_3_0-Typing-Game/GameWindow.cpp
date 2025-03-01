#include "Header.hpp"

GameWindow::GameWindow(): event(sf::Event::Closed()) {
    this->window = new RenderWindow(videoMode.getDesktopMode(), "Typing Game", sf::State::Windowed);
    
//    this->window = new RenderWindow(VideoMode({800, 600}), "Typing Game");
    
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
        if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>();
            keyPressed && keyPressed->code == sf::Keyboard::Key::Escape) {
            cout<<"On Escape pressed"<<endl;
            window->close();
            
        }
        
        if(const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
            
            if(keyPressed && keyPressed->code == sf::Keyboard::Key::Num9) {
                cout<<"On Num9 pressed"<<endl;
                if (this->enemies.size() <= this->focusedEnemy + 1) {
                    this->focusedEnemy = 0;
                } else {
                    this->focusedEnemy += 1;
                }
            }
            else if (this->enemies.size()) {
                this->enemies[this->focusedEnemy].checkInput(static_cast<char>(keyPressed->code));
            }
        
    }
    
    
    //    while (this->window->pollEvent(this->event)) {
    //        switch (this->event.type) {
    //            case Event::Closed:
    //                this->window->close();
    //                break;
    //
    //            case Event::KeyPressed:
    //                if (event.key.code == Keyboard::Escape) {
    //                    this->window->close();
    //                }
    //                break;
    //
    //            case Event::TextEntered:
    //                if (this->event.key.code == 9) { // CHECK FOR TAB KEYPRESS
    //                    if (this->enemies.size() <= this->focusedEnemy + 1) {
    //                        this->focusedEnemy = 0;
    //                    } else {
    //                        this->focusedEnemy += 1;
    //                    }
    //                }
    //                else {
    //                    if (this->enemies.size()) {
    //                        this->enemies[this->focusedEnemy].checkInput(static_cast<char>(event.text.unicode));
    //                    }
    //                }
    //                break;
    //        }
    
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
