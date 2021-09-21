#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
using namespace sf;

struct Node {

    int x;
    int y;
    Node *next;
};

int main()
{

    Node *head = NULL;
    Node *temp;
    int mouse_x = 0;
    int mouse_y = 0;
    bool pressed = false;
    bool started_drawing = false;


    // create the window
    RenderWindow window(VideoMode(800, 600), "My window");

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == Event::Closed)
                window.close();
        }


        // clear the window with black color
        window.clear(Color::Black);
        mouse_x = Mouse::getPosition(window).x;
        mouse_y = Mouse::getPosition(window).y;
        if (Mouse::isButtonPressed(Mouse::Left) && !pressed){

            pressed = true;


            if(!started_drawing) {
                started_drawing = true;
            }

            temp = new Node{mouse_x, mouse_y, head};
            head = temp;
            std::cout << temp->next << " / " << head << std::endl;


        } else if(!Mouse::isButtonPressed(Mouse::Left)) pressed = false;
        
        if(started_drawing) {

            Node *iteration = head;
            Node *prev;
            while (iteration != NULL) {
                
                Vertex line[2];
                if(iteration == head) {


                    line[0] = Vertex(Vector2f(mouse_x, mouse_y));
                    line[1] = Vertex(Vector2f(iteration->x, iteration->y));

                } else {


                    line[0] = Vertex(Vector2f(prev->x, prev->y));
                    line[1] = Vertex(Vector2f(iteration->x, iteration->y));

                }
                //std::cout << iteration->next << " / " << iteration << std::endl;
                // draw everything here...
                window.draw(line, 2, Lines);
                prev = iteration;
                iteration = iteration->next;
            }
        }


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