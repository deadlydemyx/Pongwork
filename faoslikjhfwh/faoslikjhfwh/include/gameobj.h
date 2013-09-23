#pragma once
#ifndef _GAMEOBJ_H_
#define _GAMEOBJ_H_


struct vector2d{
float x;
float y;
};
struct moveableobject{
vector2d position;
vector2d speed;
int sprite;
int height;
int width;

};
void initGame();
void updateGame();
void drawGame();
void testOnScreen(moveableobject &obj);
void destroyGame();
void movePlayer(moveableobject &player);
#endif  //_GAMEOBJ_H_