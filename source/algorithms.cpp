#include <iostream>
#include <vector>
#include <utility>
#include <chrono>
#include <thread>
#include "raylib.h"
#include "../headers/algorithms.h"
#include "../headers/externalFunctions.h"
using namespace std;
/* 
selection = 0
bubble = 1
insertion = 2 
cocktail = 3
*/
void selectionSort(vector<pair<int,Color>>& List,int length,int i) {
	int minIndex = i;
	for (int j = i+1; j < length; j++) {
		if (List[minIndex].first > List[j].first) {
			minIndex = j;
		}
	}
	int temp = List[i].first;
	List[i].first = List[minIndex].first;
	List[minIndex].first = temp;
}
void bubbleSort(vector<pair<int,Color>>& List, int length,int i) {
	for (int j = 0; j < length - i - 1; j++) {
		if (List[j].first > List[j + 1].first) {
			int temp = List[j].first;
			List[j].first = List[j + 1].first;
			List[j + 1].first = temp;
		}
	}
}
void insertionSort(vector<pair<int,Color>>& List, int length,int i) {
	int j,key;
    j = i-1;
    key = List[i].first;
    while(j >= 0 && List[j].first > key){
        List[j+1].first = List[j].first;
        j--;
    }
    List[j + 1].first = key;
}
void cocktailSort(vector<pair<int,Color>>& List, int length,int i) {
    int start = 0;
    int end = length-1;
        for (int i = start; i < end; ++i)
        {
            if (List[i].first > List[i + 1].first) {
                swap(List[i].first, List[i+1].first);
            }
        }
        end--;
        for (int i = end - 1; i >= start; --i)
        {
            if (List[i].first > List[i + 1].first) {
                swap(List[i].first, List[i + 1].first);
            }
        }
        start++;
}