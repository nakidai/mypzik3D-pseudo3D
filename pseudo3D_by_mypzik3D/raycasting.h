#pragma once
#include "cmath"
#include "data.h"

//world size
#define sizex 10
#define sizey 10
//world scale
#define scale 10

//disctance ray
#define distance 100
#define PI 3.14159265

int map[sizex][sizey]{
        {1,1,1,1,1,1,1,1,1},
        {1,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,1},
        {1,0,0,0,1,1,0,0,1},
        {1,0,0,0,1,1,0,0,1},
        {1,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,1},
        {1,1,1,1,1,1,1,1,1}
};
vector2 playerPos;

float RayCast(float angle,int mapc[sizex][sizey]){
    float step_x = cos(angle*PI/180);
    float step_y = sin(angle*PI/180);
    vector2 pos = playerPos;
    for(int i = 0; i < distance; i++){
        for(int y = 0; y < sizex; y++){
            for(int x = 0; x < sizex; x++){
                if(mapc[x][y]>=1) {
                    if (pos.x >= (float)x*scale && pos.x <= ((float)x+1)*scale && pos.y >= (float)y*scale && pos.y <= ((float)y+1)*scale) {
                        return (sqrt(pow(pos.x, 2) + pow(pos.y, 2)));
                    }
                }
            }
        }
        pos.x += step_x;
        pos.y += step_y;
    }
    return(0);
}