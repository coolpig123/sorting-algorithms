#include <iostream>
#include <vector>
#include <utility>
#include "raylib.h"
#include "../headers/algorithms.h"
#include "../headers/externalFunctions.h"
#include "../headers/Button.h"
using namespace std;
/* 
selection = 0
bubble = 1
insertion = 2 *
cocktail = 3
*/
int main()
{
    const int screenWidth = 1300;
    const int screenHeight = 1000;
    int listLength = 1000;
    vector<pair<int,Color>> list;
    int sortType = 10;
    int i = 0;
    int fps = 60;
    int delay = 10;
    float buttonWidth = 300;
    int buttonHeight = screenHeight/6+9;
    int buttonX = 1000;
    int listWidth = 1000;
    bool pause = false;
    int barWidth = 10;
    Button selectionButton(buttonX,buttonHeight*0,buttonWidth,buttonHeight,"selection",barWidth);
    Button bubbleButton(buttonX,buttonHeight*1-barWidth*1,buttonWidth,buttonHeight,"bubble",barWidth);
    Button insertionButton(buttonX,buttonHeight*2-barWidth*2,buttonWidth,buttonHeight,"insertion",barWidth);
    Button cocktailButton(buttonX,buttonHeight*3-barWidth*3,buttonWidth,buttonHeight,"cocktail",barWidth);
    Button pauseButton(buttonX,buttonHeight*4-barWidth*4,buttonWidth,buttonHeight,"pause",barWidth);
    Button shuffleButton(buttonX,buttonHeight*5-barWidth*5,buttonWidth,buttonHeight,"shuffle",barWidth);
    InitWindow(screenWidth, screenHeight, "sorting-algorithms");
    SetTargetFPS(fps);
    randomList(list,listLength);
    while (!WindowShouldClose())    
    {
        if(pauseButton.isClicked() && pause){
                pause = !pause;
                pauseButton.text = "pause";
        }else if(pauseButton.isClicked() && !pause){
            pause = !pause;
            pauseButton.text = "resume";
        }
        BeginDrawing();
            ClearBackground(BLACK);
            drawList(list,listLength,listWidth,screenHeight);
            bubbleButton.draw();
            selectionButton.draw();
            insertionButton.draw();
            cocktailButton.draw();
            pauseButton.draw();
            shuffleButton.draw();
            DrawText(TextFormat("delay : %i ms",delay), 0, 40, 20, DARKGREEN);
        EndDrawing();
        checkButtons(list,listLength,i,sortType,bubbleButton,selectionButton,cocktailButton,insertionButton,shuffleButton);
        if(!isSorted(list,sortType) && !pause){
            sort(list,listLength,i,sortType,delay);
        }   
        changeSize(list,listLength,i,sortType);
        changeDelay(delay);
    }
    CloseWindow();  
}