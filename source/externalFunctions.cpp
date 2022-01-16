#include <vector>
#include <chrono>
#include <thread>
#include <utility>
#include "../headers/externalFunctions.h"
#include "../headers/algorithms.h"
#include "raylib.h"
using namespace std;
void randomList(vector<pair<int,Color>>& List,int length) {
    vector<int> numbers;
    for(int i = 1;i<=length;i++){
        numbers.push_back(i);
    }
    int index;
    int listLength = length;
    List.clear();
	for (int i = 0; i < length; i++) {
        index = GetRandomValue(0,listLength-1);
		List.push_back(make_pair(numbers[index],WHITE));
        numbers.erase(numbers.begin()+index);
        listLength--;
	}
}
void drawList(vector<pair<int,Color>> List, int length,int screenWidth,int screenHeight){
    for(int i = 0;i < length;i++){
        DrawRectangle(i*(screenWidth/length),screenHeight-(List[i].first*(screenHeight/length)),screenWidth/length,List[i].first*(screenHeight/length),List[i].second);
    }
}
bool isSorted(vector<pair<int,Color>> List,int& sortType){
    int n = List.size()-1;
    for(int i = 0;i<n;i++){
        if(List[i].first > List[i+1].first){
            DrawText("the list is not sorted", 0, 0, 20, DARKGREEN);
            return false;
        }
    }
    DrawText("the list is sorted", 0, 0, 20, DARKGREEN);
    return true;
}
void sort(vector<pair<int,Color>>& List,int& listLength,int& i,int& sortType,int& delay){
    if(sortType == 0){
        selectionSort(List,listLength,i);
        this_thread::sleep_for(chrono::milliseconds(delay));
    }else if(sortType == 1){
        bubbleSort(List,listLength,i);
        this_thread::sleep_for(chrono::milliseconds(delay));
    }else if(sortType == 2){
        insertionSort(List,listLength,i);
        this_thread::sleep_for(chrono::milliseconds(delay));
    }else if(sortType == 3){
        cocktailSort(List,listLength,i);
        this_thread::sleep_for(chrono::milliseconds(delay));
    }
    i++;
}
void changeSize(vector<pair<int,Color>>& List,int& listLength,int& i,int& sortType){
    if(IsKeyPressed(KEY_RIGHT) && listLength < 1000){
            listLength*=10;
            randomList(List,listLength);
            i = 0;
            sortType = 10;
        }
    if(IsKeyPressed(KEY_LEFT) && listLength > 10){
        listLength/=10;
        randomList(List,listLength);
        i = 0;
        sortType = 10;
    }
    DrawText(TextFormat("elements : %i",listLength), 0, 20, 20, DARKGREEN);
}
void checkButtons(vector<pair<int,Color>>& List,int& listLength,int& i,int& sortType,Button bubbleButton,Button selectionButton,Button cocktailButton,Button insertionButton,Button shuffleButton){
    if(selectionButton.isClicked()){
        randomList(List,listLength);
        sortType = 0;
        i = 0;
    }else if(bubbleButton.isClicked()){
        randomList(List,listLength);
        sortType = 1;
        i = 0;
    }else if(insertionButton.isClicked()){
        randomList(List,listLength);
        sortType = 2;
        i = 1;
    }else if(cocktailButton.isClicked()){
        randomList(List,listLength);
        sortType = 3;
        i = 0;
    }else if(shuffleButton.isClicked()){
        randomList(List,listLength);
        sortType = 10;
        i = 0;
    }
}
void changeDelay(int& delay){
    if(IsKeyDown(KEY_UP) && delay < 50){
        delay++;
    }else if(IsKeyDown(KEY_DOWN) && delay > 0){
        delay--;
    }
}