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

    //menu window:
    sf::RenderWindow Start_window(sf::VideoMode(window_width, window_height),"ECTS RIDE");
    Start_window.setFramerateLimit(60);

    //menu texture and sprite:
    sf::Texture menu_texture;
    menu_texture.loadFromFile("textures/menu/menu.png");
    sf::Sprite menu_sprite;
    menu_sprite.setTexture(menu_texture);

    //player car:
    Player_car player_car;

    while(Start_window.isOpen()){
        sf::Event event;
        while (Start_window.pollEvent(event)){
            switch (event.type) {
                case sf::Event::Closed:
                    Start_window.close();
                    break;

                case sf::Event::MouseButtonPressed:
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        sf::Vector2i mouse_pos = sf::Mouse::getPosition(Start_window);
                        std::cout << "Mouse clicked: " << mouse_pos.x << ", " << mouse_pos.y << std::endl;

                        //---| Game Window |---
                        if (mouse_pos.x > 250 && mouse_pos.x < 550 && mouse_pos.y > 190 && mouse_pos.y < 270){
                            Start_window.close();

                            //render game window:
                            sf::RenderWindow Game_window( sf::VideoMode( window_width, window_height), "ECTS RIDE" );
                            Game_window.setFramerateLimit(30);
                            sf::Clock Game_clock;

                            //road sprite:
                            sf::Texture road_texture;
                            road_texture.loadFromFile("textures/roads/road2.png");
                            sf::Sprite road_sprite;
                            road_sprite.setTexture(road_texture);

                            //win and game over information:
                            sf::Font font;
                            font.loadFromFile("Bebas-Regular.ttf");

                            sf::Text Game_Over_Text;
                            Game_Over_Text.setFont(font);
                            Game_Over_Text.setFillColor(sf::Color::White);
                            Game_Over_Text.setCharacterSize(100);
                            Game_Over_Text.setString("Game over");
                            Game_Over_Text.setPosition(200.0, 200.0);

                            sf::Text Win_Text;
                            Win_Text.setFont(font);
                            Win_Text.setFillColor(sf::Color::White);
                            Win_Text.setCharacterSize(100);
                            Win_Text.setString("you win!!!");
                            Win_Text.setPosition(200.0, 200.0);

                            //cars things:
                            bad_car car1,car2,car3,car4;
                            player_car.setSkin();

                            //other needed stuff:
                            bool end_game = false;
                            bool win = false;

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
                                if (end_game == false){
                                    if (car1.Check_Collision(player_car._position, player_car._top)){
                                        end_game = true;
                                    }
                                    if (car2.Check_Collision(player_car._position, player_car._top)){
                                        end_game = true;
                                    }
                                    if (car3.Check_Collision(player_car._position, player_car._top)){
                                        end_game = true;
                                    }
                                    if (car4.Check_Collision(player_car._position, player_car._top)){
                                        end_game = true;
                                    }
                                }

                                //points:
                                if (end_game == false) {
                                    if (car1._vertical_position > player_car._top + 90) {
                                        player_car.Points_counting();
                                    }
                                    if (car2._vertical_position > player_car._top + 90) {
                                        player_car.Points_counting();
                                    }
                                    if (car3._vertical_position > player_car._top + 90) {
                                        player_car.Points_counting();
                                    }
                                    if (car4._vertical_position > player_car._top + 90) {
                                        player_car.Points_counting();
                                    }

                                    std::cout << "Player points: " << player_car._points << std::endl;
                                }

                                //end_game info:
                                if ((end_game == true) && (win == false)){
                                    Game_window.clear(sf::Color::Red);
                                    Game_window.draw(Game_Over_Text);
                                }
                                if ((win == true) && (end_game == true)){
                                    Game_window.clear(sf::Color::Green);
                                    Game_window.draw(Win_Text);
                                }

                                //game animation:
                                if (end_game == false){
                                    if (player_car._points == 100.0){
                                        player_car._speed += 10.0;
                                        car1._speed += 10;
                                        car2._speed += 10;
                                        car3._speed += 10;
                                        car4._speed += 10;

                                    }
                                    if (player_car._points == 200.0){
                                        player_car._speed += 10.0;
                                        car1._speed += 10;
                                        car2._speed += 10;
                                        car3._speed += 10;
                                        car4._speed += 10;
                                    }
                                    if (player_car._points == 300.0){
                                        player_car._speed += 10.0;
                                        car1._speed += 10;
                                        car2._speed += 10;
                                        car3._speed += 10;
                                        car4._speed += 10;
                                    }
                                    if (player_car._points == 400.0){
                                        player_car._speed += 10.0;
                                        car1._speed += 10;
                                        car2._speed += 10;
                                        car3._speed += 10;
                                        car4._speed += 10;
                                    }
                                    if (player_car._points >= 500.0) {
                                        win = true;
                                        end_game = true;
                                    }

                                    //clear the window with black color:
                                    Game_window.clear(sf::Color::Black);
                                    sf::Time elapsed = Game_clock.restart();
                                    //opponents spawning:
                                    if (end_game == false){
                                        car1.Animation_down(elapsed);

                                        car2.Animation_down(elapsed);

                                        car3.Animation_down(elapsed);

                                        car4.Animation_down(elapsed);
//                                    }
//                                    if (end_game == false){
                                        //move player car:
                                        player_car.Move_player(elapsed);
                                    }

                                    //draw everything here:
                                    Game_window.draw(road_sprite);
                                    Game_window.draw(player_car.Player_sprite);
                                    Game_window.draw(car1._bad_car_sprite);
                                    Game_window.draw(car2._bad_car_sprite);
                                    Game_window.draw(car3._bad_car_sprite);
                                    Game_window.draw(car4._bad_car_sprite);
                                }

                                //end the current frame
                                Game_window.display();
                            }
                        }
                        //---| Shop Window |---
                        if (mouse_pos.x > 250 && mouse_pos.x < window_width-250 && mouse_pos.y > 310 && mouse_pos.y < 390){
                            //Start_window.close();

                            //shop window:
                            sf::RenderWindow Shop_window(sf::VideoMode(window_width, window_height),"ECTS RIDE");
                            Shop_window.setFramerateLimit(60);

                            //shop texture and sprite:
                            sf::Texture shop_texture;
                            shop_texture.loadFromFile("textures/menu/shop.png");
                            sf::Sprite shop_sprite;
                            shop_sprite.setTexture(shop_texture);

                            //cars gallery in the shop:
                            std::vector<sf::Sprite> cars_in_shop;
                            sf::Texture shop_car_texture;
                            if (!shop_car_texture.loadFromFile("textures/cars/cars.png")){
                                std::cout << "No texture found!" << std::endl;
                            }
                            for (auto i = 0; i < 2; i++) {
                                for (int j = 0; j < 5; j++) {
                                    float x = 75.0;
                                    float y = 200.0;

                                    sf::Sprite shop_car_sprite;
                                    shop_car_sprite.setTextureRect(sf::IntRect(0+(j*50.0), 0+(i*90.0), 50.0, 90.0));
                                    shop_car_sprite.setTexture(shop_car_texture);
                                    shop_car_sprite.setPosition(x+(j*150.0), y+(i*225.0));

                                    cars_in_shop.emplace_back(shop_car_sprite);
                                }
                            }

                            //---|Shop Loop|---
                            while (Shop_window.isOpen()) {
                                // check all the window's events that were triggered since the last iteration of the loop
                                sf::Event Shop_event;
                                while (Shop_window.pollEvent(Shop_event)) {
                                    if (Shop_event.type == sf::Event::Closed) {
                                        std::cout << "Closing Window!" << std::endl;
                                        Shop_window.close();
                                    }
                                    if (Shop_event.type == sf::Event::MouseButtonPressed){
                                        if (event.mouseButton.button == sf::Mouse::Left) {
                                            sf::Vector2i mouse_pos = sf::Mouse::getPosition(Start_window);
                                            std::cout << "Mouse clicked: " << mouse_pos.x << ", " << mouse_pos.y << std::endl;

                                            //back to menu button:
                                            if (mouse_pos.x > 550.0 && mouse_pos.x < window_width && mouse_pos.y > 50.0 && mouse_pos.y < 125.0) {
                                                Shop_window.close();
                                            }

                                            //first row in the shop:
                                            //set playre_car texture as car1 texture:
                                            if (mouse_pos.x > 50.0 && mouse_pos.x < 150.0 && mouse_pos.y > 150.0 && mouse_pos.y < 350.0) {
                                                player_car._skin_x = 0.0;
                                                player_car._skin_y = 0.0;
                                            }
                                            //set playre_car texture as car2 texture:
                                            if (mouse_pos.x > 200.0 && mouse_pos.x < 300.0 && mouse_pos.y > 150.0 && mouse_pos.y < 350.0) {
                                                player_car._skin_x = 50.0;
                                                player_car._skin_y = 0.0;
                                            }
                                            //set playre_car texture as car3 texture:
                                            if (mouse_pos.x > 350.0 && mouse_pos.x < 450.0 && mouse_pos.y > 150.0 && mouse_pos.y < 350.0) {
                                                player_car._skin_x = 100.0;
                                                player_car._skin_y = 0.0;
                                            }
                                            //set playre_car texture as car4 texture:
                                            if (mouse_pos.x > 500.0 && mouse_pos.x < 600.0 && mouse_pos.y > 150.0 && mouse_pos.y < 350.0) {
                                                player_car._skin_x = 150.0;
                                                player_car._skin_y = 0.0;
                                            }
                                            //set playre_car texture as car5 texture:
                                            if (mouse_pos.x > 650.0 && mouse_pos.x < 750.0 && mouse_pos.y > 150.0 && mouse_pos.y < 350.0) {
                                                player_car._skin_x = 200.0;
                                                player_car._skin_y = 0.0;
                                            }

                                            //second row in the shop:
                                            //set playre_car texture as car6 texture:
                                            if (mouse_pos.x > 50.0 && mouse_pos.x < 150.0 && mouse_pos.y > 375.0 && mouse_pos.y < 575.0) {
                                                player_car._skin_x = 0.0;
                                                player_car._skin_y = 90.0;
                                            }
                                            //set playre_car texture as car7 texture:
                                            if (mouse_pos.x > 200.0 && mouse_pos.x < 300.0 && mouse_pos.y > 375.0 && mouse_pos.y < 575.0) {
                                                player_car._skin_x = 50.0;
                                                player_car._skin_y = 90.0;
                                            }
                                            //set playre_car texture as car8 texture:
                                            if (mouse_pos.x > 350.0 && mouse_pos.x < 450.0 && mouse_pos.y > 375.0 && mouse_pos.y < 575.0) {
                                                player_car._skin_x = 100.0;
                                                player_car._skin_y = 90.0;
                                            }
                                            //set playre_car texture as car9 texture:
                                            if (mouse_pos.x > 500.0 && mouse_pos.x < 600.0 && mouse_pos.y > 375.0 && mouse_pos.y < 575.0) {
                                                player_car._skin_x = 150.0;
                                                player_car._skin_y = 90.0;
                                            }
                                            //set playre_car texture as car10 texture:
                                            if (mouse_pos.x > 650.0 && mouse_pos.x < 750.0 && mouse_pos.y > 375.0 && mouse_pos.y < 575.0) {
                                                player_car._skin_x = 200.0;
                                                player_car._skin_y = 90.0;
                                            }
                                        }
                                    }
                                }

                                Shop_window.clear(sf::Color::Black);

                                Shop_window.draw(shop_sprite);
                                for(auto car : cars_in_shop){
                                    Shop_window.draw(car);
                                }
                                Shop_window.display();
                            }

                        }
                        //---| Quit Game before game |---
                        if (mouse_pos.x > 250 && mouse_pos.x < 550 && mouse_pos.y > 430 && mouse_pos.y < 510){
                            Start_window.close();
                        }
                    }
                    break;
            }
        }

        Start_window.clear(sf::Color::Black);
        Start_window.draw(menu_sprite);
        Start_window.display();
    }

    return 0;
}