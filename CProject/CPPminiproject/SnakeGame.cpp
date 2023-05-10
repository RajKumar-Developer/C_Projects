#include <iostream>
#include <conio.h>
#include<stdlib.h>
#include <synchapi.h>
#include <time.h>
using namespace std;
bool gameOver;
const int width = 20;
const int height = 20;
int x, y, foodPosX, foodPosY, Score;
int snakeX[100], snakeY[100];
int nTail;
enum eDirecton { STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirecton dir;
void Setup()
{
    gameOver = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    foodPosX = rand() % width;
    foodPosY = rand() % height;
    Score = 0;
}
void layOut()
{
    system("cls"); //system("clear");
    cout << endl;
    cout << " ";
    for (int i = 0; i < width+2; i++)
        cout << "#";
    cout << endl;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0)
                cout << " #";
            if (i == y && j == x)
                cout << "O";
            else if (i == foodPosY && j == foodPosX)
                cout << "F";
            else
            {
                bool print = false;
                for (int k = 0; k < nTail; k++)
                {
                    if (snakeX[k] == j && snakeY[k] == i)
                    {
                        cout << "o";
                        print = true;
                    }
               }
                if (!print)
                    cout << " ";
            }

            if (j == width - 1)
                cout << "#";
        }
        cout << endl;
    }

    cout << " ";
    for (int i = 0; i < width+2; i++)
        cout << "#";
    cout << endl;
    cout << " Score:" << Score << endl;
}
void getInput()
{
    if (kbhit())
    {
        switch (getch())
        {
            case 'a':
            case 'A':
                dir = LEFT;
                break;
            case 'd':
            case 'D':
                dir = RIGHT;
                break;
            case 'w':
            case 'W':
                dir = UP;
                break;
            case 's':
            case 'S':
                dir = DOWN;
                break;
            case 'x':
            case 'X':
            //case  0 :
                gameOver = true;
                break;
            default:
                break;
        }
    }
}
void gameConsept()
{
    int prevX = snakeX[0];
    int prevY = snakeY[0];
    int prev2X, prev2Y;
    snakeX[0] = x;
    snakeY[0] = y;
    for (int i = 1; i < nTail; i++)
    {
        prev2X = snakeX[i];
        prev2Y = snakeY[i];
        snakeX[i] = prevX;
        snakeY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
    switch (dir)
    {
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;
        default:
            break;
    }
    if (x > width || x < 0 || y > height || y < 0)
      gameOver = true;
      
    for (int i = 0; i < nTail; i++)
        if (snakeX[i] == x && snakeY[i] == y)
            gameOver = true;

    if (x == foodPosX && y == foodPosY)
    {
        srand(time(0));
        Score += 10;
        foodPosX = rand() % width;
        foodPosY = rand() % height;
        nTail++;
    }
}

//speed of the snake
void speedOfGame(int speed){
	Sleep(speed);
}

int main()
{
	int speed , speedOfSnake;
	cout<<"\n\n\tWhat speed that the game needed to be Start :";
	cout<<"\n\t\t\t 1. Maximum Speed \n\t\t\t 2. Average Speed \n\t\t\t 3. Minimum Speed \n\t\t\t 4.Close";
	cout<<"\n Enter your Option :";
	cin>>speedOfSnake;
	switch(speedOfSnake){
		case 1:
			speed=5;
			break;
		case 2:
			speed=50;
			break;
		case 3:
			speed=500;
			break;
		default:
			exit(0);
	}
    Setup();
    while (!gameOver)
    {
        layOut();
        getInput();
        gameConsept();
        speedOfGame(speed);
    }
	return 0;
}
