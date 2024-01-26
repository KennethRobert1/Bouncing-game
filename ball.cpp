#include <iostream>
#include <cstdlib>  // For rand() function
#include <ctime>    // For time() function
#include <conio.h>  // For _kbhit() and _getch() functions
#include <windows.h> // For Sleep() function

using namespace std;

const int width = 40;
const int height = 20;

int ballX, ballY;
int ballSpeedX, ballSpeedY;
int paddleX, paddleY;

void setup() {
    ballX = width / 2;
    ballY = height / 2;
    ballSpeedX = 1;
    ballSpeedY = 1;

    paddleX = width / 2;
    paddleY = height - 1;
}

void draw() {
    system("cls");  // Clear the console screen

    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0)
                cout << "#"; // left wall

            if (i == ballY && j == ballX)
                cout << "O"; // ball

            else if (i == paddleY && j >= paddleX && j < paddleX + 5)
                cout << "#"; // paddle

            else
                cout << " ";

            if (j == width - 1)
                cout << "#"; // right wall
        }
        cout << endl;
    }

    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;
}

void input() {
    if (_kbhit()) {
        switch (_getch()) {
            case 'a':
                paddleX--;
                break;
            case 'd':
                paddleX++;
                break;
            case 'q':
                exit(0);
        }
    }
}

void logic() {
    ballX += ballSpeedX;
    ballY += ballSpeedY;

    // Bounce off the walls
    if (ballX == 0 || ballX == width - 1)
        ballSpeedX = -ballSpeedX;

    if (ballY == 0 || ballY == height - 1)
        ballSpeedY = -ballSpeedY;

    // Bounce off the paddle
    if (ballY == paddleY - 1 && ballX >= paddleX && ballX < paddleX + 5)
        ballSpeedY = -ballSpeedY;
}

int main() {
    setup();

    while (true) {
        draw();
        input();
        logic();
        Sleep(100); // Adjust this for ball speed
    }

    return 0;
}
