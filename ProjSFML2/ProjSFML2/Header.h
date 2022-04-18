#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class bullet
{
public:
    int ind_of_destroyed = 99;
    int x = 500;
    int y = 0;
    sf::RectangleShape* rectangle;

    bullet();

    void move();

    sf::RectangleShape* Draw();

    void draw(sf::RenderWindow& win);
};

class alien
{
public:
    bool humiliated = false;
    int x;
    int y;
    int xL, yL;
    int devisor = 200;
    bool _hit = false;
    int afterHitC = 0;
    bool right = true;
    bool state = true;
    bool destroyed = false;
    bool transfered = false;
    int moveP1 = 250;
    int moveP2 = 500;
    bool shootable = false;

    sf::Sprite* model1;

    sf::Texture text1;
    sf::Texture text2;
    sf::Texture text3;

    int xR = 1500;
    int yR = 1500;
    sf::RectangleShape* rectangle;


    alien(int x, int y, int choice, int side);



    sf::Sprite* Draw();

    sf::RectangleShape* DrawB();


    bool hit(bullet* bullet);

    bool hitHE(sf::Sprite* he);

    void move_bul(sf::Sprite* he);

    void move(int count, int movaEn, bullet* bullet, sf::Sprite* he);

};




class hero
{
public:
    float x = 50, y = 50, dx = 1.0f, dy = 1.0f;

    int xL = x, yL = y;
    sf::Sprite* heroSh;
    sf::Texture text;

  
    hero(int x, int y, sf::Sprite* heroSh);

    //sf::RectangleShape Draw();
    
    void move(bullet& bulet1);


};
