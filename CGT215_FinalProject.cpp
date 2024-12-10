// CGT215_FinalProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "Paddle.h"

using namespace std;
using namespace sf;

int main()
{
    Clock clock;
    float deltaTime = 0.0f;
    Vector2f ballVelocity(-0.8f, -0.8f);

    //speed
    float ballSpeed = 300;

    //window
    RenderWindow window(VideoMode(910, 512), "Breakout", Style::Close);

    //ball
    CircleShape ball(10);
    ball.setFillColor(Color::White);
    ball.setPosition(Vector2f(910 / 2 - (125 / 2) + 50, 512 - 25 - 100));

    //Paddle
    Paddle Paddle(Vector2f(392.5, 477), Vector2f(125, 25), Color::Blue, window.getSize().x);//( 910 / 2 - (125 / 2), 512 - (25 - 10));

    //Boards
    vector<RectangleShape> boardObjects;
    bool board[7][7] = { {true, true, true, true, true, true, true},
                            {true, true, true, true, true, true, true},
                            {true, true, true, true, true, true, true},
                            {true, true, true, true, true, true, true},
                            {true, true, true, true, true, true, true},
                            {true, true, true, true, true, true, true},
                            {true, true, true, true, true, true, true},
    };
    RectangleShape tempShape;
    //true appears, false not appears
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            if (board[i][j] == true) {
                tempShape.setSize(Vector2f(115, 25));
                tempShape.setPosition(Vector2f(20 + j * (115 + 10), 10 + i * (25 + 5)));//15 is starting value from window, 10 is value from other objects
                tempShape.setFillColor(Color::Red);
                boardObjects.push_back(tempShape);
            }
        }

    }


    while (window.isOpen()) {
        deltaTime = clock.restart().asSeconds();
        Event evnt;
        while (window.pollEvent(evnt)) {
            if (evnt.type == Event::Closed) {
                window.close();
            }
        }

        FloatRect ballBounds = ball.getGlobalBounds();
        FloatRect paddleBounds = Paddle.shape.getGlobalBounds();


        if (paddleBounds.intersects(ballBounds)) {
            ballVelocity.y = -ballSpeed * deltaTime;
        }

        //left
        if (ball.getPosition().x < 0) {
            ballVelocity.x = ballSpeed * deltaTime;
        }
        //right
        else if (ball.getPosition().x > window.getSize().x - ball.getRadius()) {
            ballVelocity.x = -ballSpeed * deltaTime;
        }
        //top
        else if (ball.getPosition().y < 0) {
            ballVelocity.y = ballSpeed * deltaTime;
        }
        //bottom
        else if (ball.getPosition().y > window.getSize().y - ball.getRadius()) {
            cout << "Game Over!" << endl;
        }

        Paddle.Update(deltaTime);
        ball.move(ballVelocity);

        window.clear();

        window.draw(Paddle.shape);
        window.draw(ball);

        //Board Objects Display
        for (int i = 0; i < boardObjects.size(); i++) {
            window.draw(boardObjects[i]);
        }
        window.display();
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file