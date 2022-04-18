#include "Header.h"

bullet::bullet() {
    this->rectangle = new  sf::RectangleShape(sf::Vector2f(5, 5));
    this->rectangle->setFillColor(sf::Color(0, 0, 250));
};

void bullet::move() {
    if (y - 1 > 1)
    {
        y = y - 1;
    }
    else { this->x = 1500; }
};

sf::RectangleShape* bullet::Draw() {
    this->rectangle->setPosition({ (float)x, (float)y });
    return this->rectangle;
};

void bullet::draw(sf::RenderWindow& win) {
    sf::RectangleShape rectangle(sf::Vector2f(5, 5));
    rectangle.setFillColor(sf::Color(150, 50, 250));
    rectangle.setPosition({ (float)x, (float)y });
    //draw
    win.draw(rectangle);
};

//alien
alien::alien(int x, int y, int choice, int side) {
    this->rectangle = new  sf::RectangleShape(sf::Vector2f(5, 5));
    this->rectangle->setPosition({ (float)xR, (float)yR });
    this->rectangle->setFillColor(sf::Color(150, 0, 250));

    this->x = x;
    this->y = y;
    this->text1.loadFromFile("3.png");
    this->text2.loadFromFile("4.png");
    if (side == 0)
    {
        this->right = true;
    }
    if (side == 1)
    {
        this->right = false;
    }
    if (choice == 1)
    {
        this->text1.loadFromFile("3.png");
        this->text2.loadFromFile("4.png");
    }
    if (choice == 2)
    {
        this->text1.loadFromFile("1.png");
        this->text2.loadFromFile("2.png");
    }
    if (choice == 3)
    {
        this->text1.loadFromFile("10.png");
        this->text2.loadFromFile("11.png");
    }
    if (choice == 4)
    {
        this->text1.loadFromFile("15.png");
        this->text2.loadFromFile("16.png");
    }
    this->text3.loadFromFile("21.png");
    this->model1 = new sf::Sprite(text1);
};

sf::Sprite* alien::Draw() {
    this->model1->setPosition({ (float)x, (float)y });
    return this->model1;
};

sf::RectangleShape* alien::DrawB() {
    this->rectangle->setPosition({ (float)xR, (float)yR });
    return this->rectangle;
};


bool alien::hit(bullet* bullet) {
    if (this->model1->getGlobalBounds().intersects(bullet->rectangle->getGlobalBounds()))
    {
        bullet->x = 1500;
    }
    return this->model1->getGlobalBounds().intersects(bullet->rectangle->getGlobalBounds());
};

bool alien::hitHE(sf::Sprite* he) 
{
    if (he->getGlobalBounds().intersects(rectangle->getGlobalBounds()))
    {
        xR = 1500;
    }
    return he->getGlobalBounds().intersects(rectangle->getGlobalBounds());
};

void alien::move_bul(sf::Sprite* he)
{
    if (yR <= 1000)
    {
        yR = yR + 1;
        shootable = false;
    }
    else {
        xR = 1500;
    }
    if (hitHE(he) == true)
    {
        humiliated = true;
    }
};

void alien::move(int count, int movaEn, bullet* bullet, sf::Sprite* he) {
    move_bul(he);
    if (this->x >= 1000)
    {
        destroyed = true;
        return;
    }
    if (afterHitC <= 1)
    {
        _hit = false;
    }

    if (hit(bullet) && !_hit) {
        this->_hit = hit(bullet);
    }
    if (_hit && afterHitC < 200)
    {
        this->model1->setTexture(text3);
        afterHitC = afterHitC + 1;

        //std::cout << afterHitC << std::endl;
        return;
    }
    if (afterHitC >= 200)
    {
        this->x = 1500;

        //std::cout << 12 << std::endl;
        afterHitC = 0;
    }
    if (count < 100)
    {
        this->model1->setTexture(this->text1);
    }
    if ((count > 100 && count < 200))
    {
        this->model1->setTexture(this->text2);
    }
    if ((movaEn == this->moveP1 || movaEn == this->moveP2) && right == true)
    {
        this->x = this->x + 10;
        //std::cout << this->x << std::endl;
    }
    if (this->x >= 859 && this->right == true)
    {
        this->right = false;
        this->y = this->y + 50;
        this->x = this->x - 10;
    }
    if ((movaEn == this->moveP1 || movaEn == this->moveP2) && right == false)
    {
        this->x = this->x - 10;

        //this->y = this->y + 50;
    }
    if (this->x <= 10 && this->right == false)
    {
        this->right = true;
        this->y = this->y + 50;
        this->x = this->x + 10;
    }
};;

hero::hero(int x, int y, sf::Sprite* heroSh) {
    this->text.loadFromFile("hero3.png");
    //sf::RectangleShape heroSh(sf::Vector2f(40, 40));
    this->heroSh = heroSh;
    this->x = x;
    this->y = y;
    //this->model = model;
};



void hero::move(bullet& bulet1) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && this->x > 0)
    {
        x = x - dx;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && this->x < 859)
    {

        x = x + dx;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && bulet1.y <= 2)
    {
        bulet1.x = this->x + 18;
        bulet1.y = this->y - 1;
        /*this->heroSh->setTexture(this->text);
       this->heroSh->setTextureRect(sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(this->text.getSize())));*/
       //this->heroSh->setScale(1.0f,2.0f);
    }

    this->heroSh->setPosition({ (float)x, (float)y });

};



