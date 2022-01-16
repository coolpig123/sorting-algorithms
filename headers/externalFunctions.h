#pragma once
#include <vector>
#include <utility>
#include "raylib.h"
#include "button.h"
using namespace std;
void randomList(vector<pair<int,Color>>& List,int length);
void drawList(vector<pair<int,Color>> List, int length,int screenWidth,int screenHeight);
bool isSorted(vector<pair<int,Color>> List,int& sortType);
void sort(vector<pair<int,Color>>& List,int& listLength,int& i,int& sortType,int& delay);
void changeSize(vector<pair<int,Color>>& List,int& listLength,int& i,int& sortType);
void checkButtons(vector<pair<int,Color>>& List,int& listLength,int& i,int& sortType,Button bubbleButton,Button selectionButton,Button cocktailButton,Button insertionButton,Button shuffleButton);
void changeDelay(int& delay);