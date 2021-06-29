//biblioteki
#include <iostream>
#include <vector>
//sfml
#include <SFMl/Window.hpp>
#include <SFML/Graphics.hpp>
//klasy
#include "Player_car.h"
#include "Bad_car.h"
#include "Background.h"

int main() {
    std::cout << "Hello, ECTS RIDE!" << std::endl;

//---| Menu Window |---
    //window size defintion:
    int window_width, window_height;
    window_width = 800;
    window_height = 600;

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
menu:
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
                            sf::Time elapsed;

                            //background:
                            Background background;

                            //win and game over information:
                            sf::Font font;
                            font.loadFromFile("Bebas-Regular.ttf");

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
                                }
                                int points = player_car._points;

                                //end_game info:
                                if ((end_game) && (!win)) {
                                    background.Game_over(Game_window, points);
                                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                                        player_car._points = 0;
                                        goto menu;
                                    }
                                }

                                if ((win) && (end_game)) {
                                   background.You_win(Game_window, points);
                                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                                        player_car._points = 0;
                                        goto menu;
                                    }
                                }

                                //game animation:
                                if (!end_game) {
                                    if ((player_car._points >= 100.0) && (player_car._points < 102.0)) {
                                        player_car._speed += 20*elapsed.asSeconds();
                                        for (auto  &car : cars_vactor) {
                                            car->_speed += 20*elapsed.asSeconds();
                                        }
                                    }

                                    if ((player_car._points >= 200.0) && (player_car._points < 202.0)) {
                                        player_car._speed += 20*elapsed.asSeconds();
                                        for (auto  &car : cars_vactor) {
                                            car->_speed += 20*elapsed.asSeconds();
                                        }
                                    }

                                    if ((player_car._points >= 300.0) && (player_car._points < 302.0)) {
                                        player_car._speed += 20*elapsed.asSeconds();
                                        for (auto  &car : cars_vactor) {
                                            car->_speed += 20*elapsed.asSeconds();
                                        }
                                    }

                                    if ((player_car._points >= 400.0) && (player_car._points < 402.0)) {
                                        player_car._speed += 20*elapsed.asSeconds();
                                        for (auto  &car : cars_vactor) {
                                            car->_speed += 20*elapsed.asSeconds();
                                        }
                                    }

                                    if (player_car._points >= 500.0) {
                                        win = true;
                                        end_game = true;
                                    }

                                    //clear the window with black color:
                                    Game_window.clear(sf::Color::Black);

                                    //opponents spawning:
                                    if (!end_game) {
                                        for (auto &car : cars_vactor) {
                                            car->Animation_down(elapsed);
                                        }

                                        //move player car:
                                        player_car.Move_player(elapsed);
                                    }

                                    elapsed = Game_clock.restart();
                                    //draw everything here:
                                    Game_window.draw(background);
                                    background.Points_display(Game_window, points);
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
                                                goto menu;
                                            }

                                            //pick right skin:
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
                    break;
            }
        }

        Game_window.clear(sf::Color::Black);
        Game_window.draw(menu_sprite);
        Game_window.display();
    }

    return 0;
}