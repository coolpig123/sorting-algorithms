#include "raylib.h"
#include "../headers/Button.h"
Button::Button(float xAxis,float yAxis,float buttonWidth,float buttonHeight,const char * Text,float bar) {
    x = xAxis;
    y = yAxis;
    width = buttonWidth;
    height = buttonHeight;
    text = Text;
    barThickness = bar;
}
void Button::draw(){
    DrawRectangle(x,y,width,height,DARKGREEN);
    DrawRectangleLinesEx(Rectangle{(float)x,(float)y,(float)width,(float)height},barThickness,DARKGRAY);
    DrawText(text,x+40, y+60 , 50, BLACK);

}
bool Button::isClicked(){
    if(GetMouseX() >= x && GetMouseX() <= x+width &&  GetMouseY() >= y && GetMouseY() <= y+height && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
        return true;
    }
    return false;
}