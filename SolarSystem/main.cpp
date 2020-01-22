#include "SolarSystemModel.h"

int main() {
    //setlocale(0, ".1251");
    RenderWindow window(VideoMode(X, Y), "SolarSystemModel");
    window.setFramerateLimit(60);

    Sprite space;
    Texture spacet;
    spacet.loadFromFile("space.jpg");

    space.setTexture(spacet);

    Font SolSys;
    SolSys.loadFromFile("SolarSystemFont.ttf");

    Solar_System ss("The solar system - the planetary system, includes a central star - \nthe Sun - and all the natural cosmic objects that revolve \naround the Sun. It was formed by gravitational compression \nof a gas-dust cloud about 4.57 billion years ago.");

    ss.sky[0] = new star("A star without which life on Earth could not exist. "
                         "It gives us energy and heat. According to the classification of stars, the Sun is a yellow dwarf. Age about 5 billion years.\n"
                         "Has a diameter at the equator of 1392000 km, 109 times larger than the Earth. The rotation period at the equator is 25.4 days.\n"
                         "and 34 days at the poles. The mass of the Sun 2x10 is 27 degrees tons, approximately 332950 times the mass of the Earth. Temperature\n"
                         "inside the nucleus, about 15 million degrees Celsius. The surface temperature is about 5500 degrees Celsius. Chemical\n"
                         "composition of the Sun consists of 75% of hydrogen, and of the other 25% of the elements the largest amount of helium.", "Sun", Vector2f(885, 465), 0.3, SolSys);

    ss.sky[1] = new planet("The period of revolution around the Sun: 87.97 days.\n"
                           "Diameter at the equator: 4878 km.\n"
                           "Period of rotation (revolution around the axis): 58 days.\n"
                           "Surface temperature: 350 during the day and -170 at night.\n"
                           "Atmosphere: very thin, helium.\n"
                           "How many satellites: 0.\n"
                           "The main satellites of the planet: 0.", "Merkury", 110, 286027, Vector2f(X/2, Y/2 + 110), 0.034, SolSys);

    ss.sky[2] = new planet("Period of revolution around the Sun: 224.7 days.\n"
                           "Diameter at the equator: 12104 km.\n"
                           "Rotation period (revolution about an axis): 243 days.\n"
                           "Surface temperature: 480 degrees (average).\n"
                           "Atmosphere: dense, mostly carbon dioxide.\n"
                           "How many satellites: 0.\n"
                           "The main satellites of the planet: 0.", "Venus", 140, 1104657, Vector2f(X/2, Y/2 + 140), 0.07, SolSys);

    ss.sky[3] = new planet("Period of revolution around the Sun: 365.3 days.\n"
                           "Diameter at the equator: 12756 km.\n"
                           "The period of rotation of the planet (revolution around the axis): 23 hours 56 min.\n"
                           "Surface temperature: 22 degrees (average).\n"
                           "Atmosphere: mostly nitrogen and oxygen.\n"
                           "Number of satellites: 1.\n"
                           "The main satellites of the planet: the moon.", "Earth", 180, 1800000, Vector2f(X/2, Y/2 + 180), 0.1, SolSys);

    ss.sky[4] = new planet("Period of revolution around the Sun: 687 days.\n"
                           "The diameter of the planet at the equator: 6794 km.\n"
                           "Rotation period (revolution about an axis): 24 hours 37 min.\n"
                           "Surface temperature: –23 degrees (average).\n"
                           "Atmosphere of the planet: rarefied, mainly carbon dioxide.\n"
                           "How many satellites: 2.\n"
                           "The main companions in order: Phobos, Deimos.", "Mars", 220, 3387945, Vector2f(X/2, Y/2 + 220), 0.07, SolSys);

    ss.sky[5] = new planet("The period of revolution around the Sun: 11 years 314 days.\n"
                           "The diameter of the planet at the equator: 143884 km.\n"
                           "Rotation period (revolution about an axis): 9 hours 55 min.\n"
                           "The surface temperature of the planet: -150 degrees (average).\n"
                           "Atmosphere: mostly hydrogen and helium.\n"
                           "Number of satellites: 16 (+ rings).\n"
                           "The main satellites of the planets in order: Io, Europe, Ganymede, Callisto.", "Jupiter", 270, 21348493, Vector2f(X/2, Y/2 + 270), 0.23, SolSys);

    ss.sky[6] = new planet("The period of revolution around the Sun: 29 years 168 days.\n"
                           "The diameter of the planet at the equator: 120536 km.\n"
                           "Rotation period (revolution about an axis): 10 hours 14 min.\n"
                           "Surface temperature: -180 degrees (average).\n"
                           "Atmosphere: mostly hydrogen and helium.\n"
                           "Number of satellites: 18 (+ rings).\n"
                           "Main Companions: Titan.", "Saturn", 340, 53028493, Vector2f(X/2, Y/2 + 340), 0.23, SolSys);

    ss.sky[7] = new planet("Period of circulation: 84 years 4 days.\n"
                           "Diameter at the equator: 51118 km.\n"
                           "The period of rotation of the planet (revolution around the axis): 17 hours 14 min.\n"
                           "Surface temperature: –214 degrees (average).\n"
                           "Atmosphere: mostly hydrogen and helium.\n"
                           "How many satellites: 15 (+ rings).\n"
                           "Main Companions: Titania, Oberon.", "Uranus", 400, 151219726, Vector2f(X/2, Y/2 + 390), 0.13, SolSys);

    ss.sky[8] = new planet("The period of revolution around the Sun: 164 years 292 days.\n"
                           "Diameter at the equator: 50538 km.\n"
                           "Rotation period (revolution about an axis): 16 hours 7 min.\n"
                           "Surface temperature: –220 degrees (average).\n"
                           "Atmosphere: mostly hydrogen and helium.\n"
                           "The number of satellites: 8.\n"
                           "Main Companions: Triton.", "Neptune", 450, 296640000, Vector2f(X/2, Y/2 + 430), 0.13, SolSys);

    ss.sky[9] = new planet("The largest among dwarf planets.\n"
                           "It consists of a rocky core covered with a layer of ice.\n"
                           "Only in 2015, a spacecraft flew to Pluto\n"
                           "and took detailed pictures. His main companion is Charon.", "Pluto", 490, 4464000/*00*/, Vector2f(X/2, Y/2 + 470), 0.05, SolSys);

    satellite *sp[num_sp];
    sp[0] = new satellite(250, 133150, "moon", Vector2f(X/2, Y/2 + 250));
    sp[1] = new satellite(250, 100000, "fobos", Vector2f(X/2, Y/2 + 250));
    sp[2] = new satellite(350, 150000, "deymos", Vector2f(X/2, Y/2 + 350));
    sp[3] = new satellite(250, 100000, "io", Vector2f(X/2, Y/2 + 250));
    sp[4] = new satellite(350, 150000, "europe", Vector2f(X/2, Y/2 + 250));
    sp[5] = new satellite(450, 200000, "ganimed", Vector2f(X/2, Y/2 + 250));
    sp[6] = new satellite(550, 250000, "kallisto", Vector2f(X/2, Y/2 + 250));
    sp[7] = new satellite(350, 100000, "titan", Vector2f(X/2, Y/2 + 350));
    sp[8] = new satellite(250, 100000, "titania", Vector2f(X/2, Y/2 + 250));
    sp[9] = new satellite(350, 150000, "oberon", Vector2f(X/2, Y/2 + 250));
    sp[10] = new satellite(250, 100000, "triton", Vector2f(X/2, Y/2 + 250));
    sp[11] = new satellite(250, 100000, "haron", Vector2f(X/2, Y/2 + 250));


    Event event;

    while (window.isOpen()) {
        Vector2i cl = Mouse::getPosition(window);
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == Event::MouseButtonReleased) {
                if (event.mouseButton.button == Mouse::Left) {
                    for (int i = 0; i < num; i++) {
                        ss.sky[i]->setS(ss.sky[i]->IsClick(&cl));
                    }
                }
                if (event.type == sf::Event::KeyPressed) {
                    if (event.key.code == sf::Keyboard::Escape) {
                        break;
                    }
                }
            }
        }
        window.clear();
        window.draw(space);
        for (int i = 0; i < num_sp; i++) {
            sp[i]->load();
        }
        for (int i = 0; i < num; i++) {
            ss.sky[i]->load();
        }
        int temp = -1;
        for (int i = 0; i < num; i++) {
            if (ss.sky[i]->isS()) {
                temp = i;
            }
        }
        if (temp == -1) {
            for (int i = 0; i < num; i++) {
                ss.sky[i]->draw(&window);
                ss.write(&SolSys, &window);
            }
        }
        else {
            ss.sky[temp]->Click(&window);
            ss.sky[temp]->write(&window);
            if (temp == 3) {
                sp[0]->draw(&window);
            }
            if (temp == 4) {
                sp[1]->draw(&window);
                sp[2]->draw(&window);
            }
            if (temp == 5) {
                sp[3]->draw(&window);
                sp[4]->draw(&window);
                sp[5]->draw(&window);
                sp[6]->draw(&window);
            }
            if (temp == 6)
                sp[7]->draw(&window);
            if (temp == 7)
            {
                sp[8]->draw(&window);
                sp[9]->draw(&window);
            }
            if (temp == 8)
            {
                sp[10]->draw(&window);
            }
            if (temp == 9)
            {
                sp[11]->draw(&window);
            }
        }
        window.display();
    }
    return 0;
}