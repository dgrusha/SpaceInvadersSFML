#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Header.h"


int main()
{
    int spState = 0;
    int movaEn = 0;
    int frequency = 501;
    bool trans1= false;
    bool trans2 = false;
    int end = 0;
    
    //creating hero
    sf::Texture hero34;
    hero34.loadFromFile("hero2.png");
    sf::Sprite* sprite = new sf::Sprite(hero34);
    float sprite_pos_x = 10.5f;
    hero* hero2 = new hero(450, 550, sprite);
    //creating bullet
    bullet* bulet1 = new bullet();
    //creating window
    int w = 900, h = 600;
    sf::RenderWindow window(sf::VideoMode(w, h), "Space invaders");
    window.setMouseCursorVisible(false);
    float x = 0, y = 0, dx = 1.0f, dy = 1.0f;
    
    //Creating alien 
    //First row
    alien* alien1 = new alien(20, 20,  1 , 0);
    alien* alien2 = new alien(100, 20, 1 , 0);
    alien* alien3 = new alien(180, 20, 1 , 0);
    alien* alien4 = new alien(260, 20, 1 , 0);
    alien* alien5 = new alien(340, 20, 1 , 0);
    alien* alien6 = new alien(420, 20, 1 , 0);
    //Second row
    alien* alien11 = new alien(859, 100, 2, 1);
    alien* alien12 = new alien(779, 100, 2, 1);
    alien* alien13 = new alien(699, 100, 2, 1);
    alien* alien14 = new alien(619, 100, 2, 1);
    alien* alien15 = new alien(539, 100, 2, 1);
    alien* alien16 = new alien(459, 100, 2, 1);
    //Third row
    alien* alien21 = new alien(20, 180, 3, 0);
    alien* alien22 = new alien(100, 180, 3, 0);
    alien* alien23 = new alien(180, 180, 3, 0);
    alien* alien24 = new alien(260, 180, 3, 0);
    alien* alien25 = new alien(340, 180, 3, 0);
    alien* alien26 = new alien(420, 180, 3, 0);
    //Fourth row
    alien* alien31 = new alien(859, 260, 4, 1);
    alien* alien32 = new alien(779, 260, 4, 1);
    alien* alien33 = new alien(699, 260, 4, 1);
    alien* alien34 = new alien(619, 260, 4, 1);
    alien* alien35 = new alien(539, 260, 4, 1);
    alien* alien36 = new alien(459, 260, 4, 1);
    std::vector<alien*> preset = { alien1, alien2,  alien3, alien4, alien5, alien6, alien11, alien12,  alien13, alien14,
        alien15, alien16, alien21, alien22,  alien23, alien24, alien25, alien26, alien31, alien32,  alien33, alien34, alien35, alien36 };
    int presetSize = preset.size();
    //randomizer
    std::srand(time(NULL));
    //game process
    while (window.isOpen())
    {
        //y of the nearest ufo
        int last = -1;
        
        sf::sleep(sf::milliseconds(1));
        //killing ufo
        for (size_t i = 0; i < preset.size(); i++)
        {
            if (preset[i]->destroyed == true)
            {
                preset.erase(preset.begin() + i);
            }
        }
        spState = spState + 1;
        movaEn++;
        //moving ufo and checking states
        for (size_t i = 0; i < preset.size(); i++)
        {
            preset[i]->move(spState, movaEn, bulet1, sprite);
            if (preset[i]->y >= last)
            {
                last = preset[i]->y;
            }
            if (preset[i]->humiliated == true)
            {
                std::cout << "YOU DIED";
                end = -1;
            }
            if (preset[i]->y >= 470)
            {
                std::cout << "YOU DIED";
                end = -1;
            }
        }
        //shooting
        for (size_t i = 0; i < preset.size(); i++)
        {
            int res = std::rand() % 1000;
            if (preset[i]->y >= last && res == 100)
            {
                preset[i]->shootable = true;
                preset[i]->xR = preset[i]->x+20;
                preset[i]->yR = preset[i]->y + 40;
            }
            else { preset[i]->shootable = false; }

        }
        //displaying heroes
        hero2->move(*bulet1);
        bulet1->move();
        window.clear();
        window.draw(*sprite);
        window.draw(*bulet1->Draw());
        for (size_t i = 0; i < preset.size(); i++)
        {
            window.draw(*preset[i]->Draw());
            window.draw(*preset[i]->DrawB());
        }
        window.display();
        //winning condition
        if (preset.size()==0)
        {
            std::cout << "YOU WON" << std::endl;
            end = 1;
            break;
        }
        if (spState >= 401)
        {
            spState = 0;

        }
        //changing speed
        if (preset.size() == presetSize/2 && trans1 == false)
        {
            frequency = frequency = 301;
            for (size_t i = 0; i < preset.size(); i++)
            {
                preset[i]->moveP1 = 150;
                preset[i]->moveP2 = 300;
            }
            trans1 = true;
        }
        if (preset.size() == presetSize / 4 && trans2 == false)
        {
            frequency = frequency = 151;
            for (size_t i = 0; i < preset.size(); i++)
            {
                preset[i]->moveP1 = 75;
                preset[i]->moveP2 = 150;
            }
            trans1 = true;
        }
        //changing state of a ufo
        if (movaEn >= frequency) 
        {
            movaEn = 0;
        }
        //ending game
        if (end != 0)
        {
            break;
        }
    }
    //final screen
    while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        if (end == -1)
        { 
            sf::Texture tend;
            tend.loadFromFile("youdied.jpg");
            sf::Sprite* youd = new sf::Sprite(tend);
            //sf::Sprite youd;
            youd->setTexture(tend);
            youd->setPosition({ (float)200, (float)150 });
            window.clear();
            window.draw(*youd); 
            window.display();
        }
        if (end == 1)
        {
            sf::Texture tend;
            tend.loadFromFile("youwon.jpg");
            sf::Sprite* youd = new sf::Sprite(tend);
            //sf::Sprite youd;
            youd->setTexture(tend);
            youd->setPosition({ (float)50, (float)75 });//50,75
            window.clear();
            window.draw(*youd);
            window.display();
        }
    }
    return 0;
}