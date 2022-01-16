#pragma once
struct Button{
    float x;
    float y;
    float width;
    float height;
    float barThickness;
    const char * text;
    Button(float xAxis,float yAxis,float buttonWidth,float buttonHeight,const char * Text,float bar);
    void draw();
    bool isClicked();
};
        