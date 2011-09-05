#include <SFML/Graphics.hpp>
#include "GameFacade.h"

int main()
{    
    sf::RenderWindow App(sf::VideoMode(1200, 1000), "SFML Graphics");
    App.SetFramerateLimit(60);
	GameFacade gf = GameFacade(&App);
    while (App.IsOpened())
    {
        
        sf::Event Event;
        while (App.GetEvent(Event))
        {
            if (Event.Type == sf::Event::Closed)
                App.Close();
			else
				gf.process_event(&Event);
        }
        
        App.Clear();
		gf.step();
        App.Display();
    }
    return EXIT_SUCCESS;
}