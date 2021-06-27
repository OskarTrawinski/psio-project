//biblioteki
#include <iostream>
#include <vector>
//sfml
#include <SFMl/Window.hpp>
#include <SFML/Graphics.hpp>
//klasy
#include "Player_car.h"
#include "Bad_car.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

//---| Menu Window |---
    //window size defintion:
    int window_width, window_height;
    window_width = 800;
    window_height = 600;
a:
    //menu window:
    sf::RenderWindow Game_window(sf::VideoMode(window_width, window_height), "ECTS RIDE");
    Game_window.setFramerateLimit(60);

    //menu texture and sprite:
    sf::Texture menu_texture;
    if (!menu_texture.loadFromFile("textures/menu/menu.png")) {
        std::cout << "menu texture not found!" << std::endl;
    }
    sf::Sprite menu_sprite;
    menu_sprite.setTexture(menu_texture);

    //player car:
    Player_car player_car;

    while(Game_window.isOpen()){
        sf::Event event;
        while (Game_window.pollEvent(event)){
            switch (event.type) {
                case sf::Event::Closed:
                    Game_window.close();
                    break;

                case sf::Event::MouseButtonPressed:
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        sf::Vector2i mouse_pos = sf::Mouse::getPosition(Game_window);
                        std::cout << "Mouse button clicked: " << mouse_pos.x << ", " << mouse_pos.y << std::endl;

                        //---| Game Window |---
                        if (mouse_pos.x > 250 && mouse_pos.x < 550 && mouse_pos.y > 190 && mouse_pos.y < 270) {

                            sf::Clock Game_clock;

                            //road sprite:
                            sf::Texture road_texture;
                            road_texture.loadFromFile("textures/roads/road1.png");
                            sf::Sprite road_sprite;
                            road_sprite.setTexture(road_texture);

                            //win and game over information:
                            sf::Font font;
                            font.loadFromFile("Bebas-Regular.ttf");

                            sf::Text Game_Over_Text;
                            Game_Over_Text.setFont(font);
                            Game_Over_Text.setFillColor(sf::Color::Red);
                            Game_Over_Text.setCharacterSize(100);
                            Game_Over_Text.setString("Game over");
                            Game_Over_Text.setPosition(200.0, 200.0);

                            sf::Text Win_Text;
                            Win_Text.setFont(font);
                            Win_Text.setFillColor(sf::Color::Green);
                            Win_Text.setCharacterSize(100);
                            Win_Text.setString("you win!!!");
                            Win_Text.setPosition(200.0, 200.0);

                            //actual points info in game:
                            sf::Text Points_text;
                            Points_text.setFont(font);
                            Points_text.setFillColor(sf::Color::Black);
                            Points_text.setCharacterSize(25);
                            Points_text.setString("points: "+ std::to_string(player_car._points));
                            Points_text.setPosition(720.0, 20.0);

                            //cars:
                            std::vector <std::unique_ptr <bad_car>> cars_vactor;
                            for (int i = 0; i < 4; ++i) {
                                cars_vactor.emplace_back(std::make_unique<bad_car>());
                            }

                            //other needed stuff:
                            bool end_game;
                            end_game = false;

                            bool win;
                            win = false;

                            //---| Game Loop |---
                            while (Game_window.isOpen()) {
                                // check all the window's events that were triggered since the last iteration of the loop
                                sf::Event event;
                                while (Game_window.pollEvent(event)) {
                                    if (event.type == sf::Event::Closed) {
                                        std::cout << "Closing Window!" << std::endl;
                                        Game_window.close();
                                    }
                                }

                                //checking collisions:
                                if (!end_game) {
                                    for (auto &car : cars_vactor) {
                                        if (car->Check_Collision(player_car._horizontal_position, player_car._vertical_position)) {
                                            end_game = true;
                                        }
                                    }
                                }

                                //points:
                                if (!end_game) {
                                    for (auto  &car : cars_vactor) {
                                        if (car->_vertical_position >= window_height - 10) {
                                            player_car.Points_counting();
                                        }
                                    }

                                    Points_text.setString("points: \n"+ std::to_string(player_car._points));
                                }

                                //end_game info:
                                if ((end_game) && (!win)) {
                                    Game_window.clear(sf::Color::Black);
                                    Game_window.draw(Game_Over_Text);
//                                    music.stop();
                                }

                                if ((win) && (end_game)) {
                                    Game_window.clear(sf::Color::Black);
                                    Game_window.draw(Win_Text);
//                                    music.stop();
                                }

                                //game animation:
                                if (!end_game) {
                                    if (player_car._points == 100.0) {
                                        player_car._speed += 10.0;
                                        for (auto  &car : cars_vactor) {
                                            car->_speed += 10;
                                        }
                                    }

                                    if (player_car._points == 200.0) {
                                        player_car._speed += 10.0;
                                        for (auto  &car : cars_vactor) {
                                            car->_speed += 10;
                                        }
                                    }

                                    if (player_car._points == 300.0) {
                                        player_car._speed += 10.0;
                                        for (auto  &car : cars_vactor) {
                                            car->_speed += 10;
                                        }
                                    }

                                    if (player_car._points == 400.0) {
                                        player_car._speed += 10.0;
                                        for (auto  &car : cars_vactor) {
                                            car->_speed += 10;
                                        }
                                    }

                                    if (player_car._points >= 500.0) {
                                        win = true;
                                        end_game = true;
                                    }

                                    //clear the window with black color:
                                    Game_window.clear(sf::Color::Black);
                                    sf::Time elapsed = Game_clock.restart();

                                    //opponents spawning:
                                    if (!end_game) {
                                        for (auto &car : cars_vactor) {
                                            car->Animation_down(elapsed);
                                        }

                                        //move player car:
                                        player_car.Move_player(elapsed);
                                    }

                                    //draw everything here:
                                    Game_window.draw(road_sprite);
                                    Game_window.draw(Points_text);

                                    Game_window.draw(player_car);
                                    for (auto &car : cars_vactor) {
                                        Game_window.draw(*car);
                                    }
                                }

                                //end the current frame
                                Game_window.display();
                            }
                        }
                        //---| Shop Window |---
                        if (mouse_pos.x > 250 && mouse_pos.x < window_width - 250 && mouse_pos.y > 310 && mouse_pos.y < 390) {
                            //shop window:
                            //sf::RenderWindow Shop_window(sf::VideoMode(window_width, window_height), "ECTS RIDE");

                            //shop texture and sprite:
                            sf::Texture shop_texture;
                            if (!shop_texture.loadFromFile("textures/menu/shop.png")) {
                                std::cout << "menu graphic not found!" << std::endl;
                            }
                            sf::Sprite shop_sprite;
                            shop_sprite.setTexture(shop_texture);

                            //cars gallery in the shop:
                            std::vector<sf::Sprite> cars_in_shop;

                            //show cars in the shop:
                            Car car;
                            car.Show_cars(cars_in_shop);

                            //---|Shop Loop|---
                            while (Game_window.isOpen()) {
                                // check all the window's events that were triggered since the last iteration of the loop
                                sf::Event Shop_event;
                                while (Game_window.pollEvent(Shop_event)) {
                                    if (Shop_event.type == sf::Event::Closed) {
                                        std::cout << "Closing Window!" << std::endl;
                                        Game_window.close();
                                    }
                                    if (Shop_event.type == sf::Event::MouseButtonPressed) {
                                        if (event.mouseButton.button == sf::Mouse::Left) {
                                            sf::Vector2i mouse_pos = sf::Mouse::getPosition(Game_window);
                                            std::cout << "Mouse clicked: " << mouse_pos.x << ", " << mouse_pos.y
                                                      << std::endl;

                                            //back to menu button:
                                            if (mouse_pos.x > 550.0 && mouse_pos.x < window_width &&
                                                mouse_pos.y > 50.0 && mouse_pos.y < 125.0) {
                                                goto a;
                                            }

                                            player_car.Skin_select(mouse_pos);
                                        }
                                    }
                                }

                                Game_window.clear(sf::Color::Black);

                                Game_window.draw(shop_sprite);
                                for (auto _car : cars_in_shop) {
                                    Game_window.draw(_car);
                                }
                                Game_window.display();
                            }

                        }
                        //---| Quit Game before game |---
                        if (mouse_pos.x > 250 && mouse_pos.x < 550 && mouse_pos.y > 430 && mouse_pos.y < 510) {
                            Game_window.close();
                        }
                    }
            }
        }

        Game_window.clear(sf::Color::Black);
        Game_window.draw(menu_sprite);
        Game_window.display();
    }

    return 0;
}