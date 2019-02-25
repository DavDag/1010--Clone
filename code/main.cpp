#include <SFML/Graphics.hpp>
#include "screenhandler.h"
#include "menu.h"
#include "settings.h"
#include "play.h"

using namespace sf;

int main(){
    srand(time(NULL));

    RenderWindow app(VideoMode(960, 640), "1010! by Davide");
    app.setFramerateLimit(480);
    Clock clock;
    ScreenHandler sh;
    Menu menu;
    Settings settings;
    Play play;
    sh.menu = &menu;
    sh.settings = &settings;
    sh.play = &play;
    menu.sh = &sh;
    settings.sh = &sh;
    play.sh = &sh;

    while (app.isOpen()){
        Event event;
        while (app.pollEvent(event)){
            switch(event.type){
                case Event::Closed:
                    app.close();
                    break;
                case Event::MouseButtonPressed:
                    sh.click(app.mapPixelToCoords(Mouse::getPosition(app)));
                default:
                    break;
            }
        }
        Time dt = clock.restart();
        Vector2f pos = app.mapPixelToCoords(Mouse::getPosition(app));
        sh.update(dt, pos);

        app.clear(sh.getTheme());
        app.draw(sh);
        app.display();
    }

    return EXIT_SUCCESS;
}
