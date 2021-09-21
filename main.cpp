#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>


int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }


        // clear the window with black color
        window.clear(sf::Color::Black);

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){


            int mousePOS_X = sf::Mouse::getPosition(window).x;
            int mousePOS_Y = sf::Mouse::getPosition(window).y;
            return mousePOS_X,mousePOS_Y;


        }

        sf::Vertex line[] =
                {

                        sf::Vertex(sf::Vector2f(1,10)),
                        sf::Vertex(sf::Vector2f(150, 150))
                };


        // draw everything here...
        window.draw(line,2, sf::Lines);

        // end the current frame
        window.display();
    }

    return 0;
}

/*
#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    int mouse_x = 0;
    int mouse_y = 0;
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(10.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){

                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                mouse_x = sf::Mouse::getPosition(window).x;
                mouse_y = sf::Mouse::getPosition(window).y;
                shape.setPosition(mouse_x, mouse_y);

            }

            if (event.type == sf::Event::Closed) 
                window.close();
        }




        window.clear();
        window.draw(shape);
        window.display();

        
    }

    return 0;
}
*/