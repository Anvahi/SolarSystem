//
// Created by anvahi on 21.01.20.
//

#ifndef SOLARSYSTEM_SOLARSYSTEMMODEL_H
#define SOLARSYSTEM_SOLARSYSTEMMODEL_H

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <cmath>
#include "locale"
#define X 1920
#define Y 1080
#define num 10
#define num_sp 12

using namespace std;
using namespace sf;

class heavenly_body {
protected:
    string information;
    string name;
    int radius;
    int period;
    Vector2f size;
    double angle = 0.0;
    double scale = 0.0;
    Vector2f here;
    Texture texture;
    Font font;
    Sprite img;
    bool s = false;

public:
    heavenly_body() = default;

    bool isS() const {
        return s;
    }

    virtual void write (RenderWindow *window) {
        Text inf;
        inf.setFont(font);
        inf.setString(information);
        inf.setCharacterSize(20);
        inf.setColor(Color::White);
        inf.setPosition(3, 800);
        window->draw(inf);

        Text nam;
        nam.setFont(font);
        nam.setString(name);
        nam.setCharacterSize(48);
        nam.setColor(Color::White);
        nam.setPosition(3, 3);
        window->draw(nam);
    }

    virtual void load () {
        this->texture.loadFromFile(name + ".png");
        this->img.setTexture(texture);
        this->size = img.getGlobalBounds().getSize();
    }

    virtual void change_size(Sprite *sprite) {
        size = sprite->getGlobalBounds().getSize();
    }

    virtual void draw(RenderWindow *window) {};

    virtual void rotation(Sprite *img){};

    virtual void Click(RenderWindow *window) {};

    virtual bool IsClick (Vector2i *cl) {
        return (img.getGlobalBounds().contains(cl->x, cl->y));
    };

    void setS(bool s) {
        heavenly_body::s = s;
    }

    ~heavenly_body() = default;
};

class planet : public  heavenly_body {
public:
    planet (string _information, string _name, int _radius, int _period, Vector2f _here, double _scale, Font _font) {
        information = _information;
        name = _name;
        radius = _radius;
        period = _period;
        here = _here;
        scale = _scale;
        font = _font;
    }

    void draw(RenderWindow *window) override {
        img.setScale(scale, scale);
        change_size(&img);
        rotation(&img);
        img.setPosition(here);
        window->draw(img);
    }

    void rotation(Sprite *img) override {
        double delta = (16.66/(double)period * 360.0);
        angle = fmod((angle+delta), 360.0);
        here.x = (int)((radius*sin(angle))-img->getGlobalBounds().width/2 + X/2);
        here.y = (int)((radius*cos(angle))-img->getGlobalBounds().height/2 + Y/2);
    };

    void Click(RenderWindow *window) override {
        img.setScale(1,1);
        change_size(&img);
        img.setPosition(X/2 - img.getGlobalBounds().width/2, Y/2 - img.getGlobalBounds().height/2);
        window->draw(img);
    }

    ~planet() = default;
};

class satellite : public  heavenly_body {
public:
    satellite (int _radius, int _period, string _name, Vector2f _here) {
        radius = _radius;
        period = _period;
        name = _name;
        here = _here;
    }

    void draw(RenderWindow *window) override {
        rotation(&img);
        img.setPosition(here);
        window->draw(img);
    }

    void rotation(Sprite *img) override {
        double delta = (16.66/(double)period * 360.0);
        angle = fmod((angle+delta), 360.0);
        here.x = (int)((radius*sin(angle))-img->getGlobalBounds().width/2 + X/2);
        here.y = (int)((radius*cos(angle))-img->getGlobalBounds().height/2 + Y/2);
    };

    ~satellite() = default;
};

class star : public heavenly_body {
public:
    star (string _information, string _name, Vector2f _here, double _scale, Font _font) {
        information = _information;
        name = _name;
        here = _here;
        scale = _scale;
        font = _font;
    }

    void draw(RenderWindow *window) override {
        if (!s)
            img.setScale(scale, scale);
        change_size(&img);
        img.setPosition(here);
        window->draw(img);
    }

    void Click(RenderWindow *window) override {
        img.setScale(1,1);
        change_size(&img);
        img.setPosition(X/2 - img.getGlobalBounds().width/2, Y/2 - img.getGlobalBounds().height/2);
        window->draw(img);
    }

    ~star() = default;
};

class Solar_System {
protected:
    string information;

public:
    heavenly_body **sky;
    Solar_System (string _information) {
        this->information = _information;
        sky = new heavenly_body*[num];
    }

    void write (Font *font, RenderWindow *window) {
        Text inf;
        inf.setFont(*font);
        inf.setString(information);
        inf.setCharacterSize(20);
        inf.setColor(Color::White);
        inf.setPosition(3, 864);
        window->draw(inf);
    }

    ~Solar_System() = default;
};

#endif //SOLARSYSTEM_SOLARSYSTEMMODEL_H