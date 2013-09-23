#include "gameobj.h"
#include "AIE.h"
#include <cmath>

const int SCREEN_X = 1280;
const int SCREEN_Y = 780;
const int PLAYER1_X = 100;
const int PLAYER1_W = 100;
const int PLAYER1_H = 175;

const int PLAYER2_X = 1200;
const int PLAYER2_W = 100;
const int PLAYER2_H = 175;

const int BALL_W = 32;
const int BALL_H = 32;

unsigned int bgImage = -1;
moveableobject player1 = {PLAYER1_X, 100, 0, 0, -1 , PLAYER1_H, PLAYER1_W};
moveableobject player2 = {PLAYER2_X, 100, 0, 0, -1, PLAYER2_W, PLAYER2_H};
moveableobject ball = {500, 500, 1, 1, -1, BALL_W, BALL_H};



void initGame(){
	bgImage = CreateSprite( "./images/PBG.png", SCREEN_X, SCREEN_Y, true );
	MoveSprite(bgImage, SCREEN_X>>1, SCREEN_Y>>1);
	ball.sprite = CreateSprite( "./images/ball.png", BALL_W, BALL_H, true );
	MoveSprite(ball.sprite, ball.position.x ,ball.position.y);
	player1.sprite = CreateSprite( "./images/OnixP1.png", PLAYER1_W, PLAYER1_H, true );
	MoveSprite(player1.sprite, player1.position.x, player1.position.y);
	player2.sprite = CreateSprite( "./images/OnixP2.png", PLAYER2_W, PLAYER2_H, true );
	MoveSprite(player2.sprite, player2.position.x, player2.position.y);
}

bool checkPaddleCollision(moveableobject& ball, moveableobject& player) {
	int speed = ball.speed.x;
	
	int ballHalfW = ball.width>>1;
	int playerHalfW = player.width>>1;
	int playerHalfH = player.height>>1;
	
	if(speed == 0)
		return false;

	if(speed < 0){
		if(ball.position.x - ballHalfW < player.position.x + playerHalfW && 
			ball.position.y > player.position.y - playerHalfH &&
			ball.position.y < player.position.y + player.height){
				return true;
		}
	}
	else {
		if(ball.position.x + ballHalfW > player.position.x - playerHalfW && 
			ball.position.y > player.position.y - playerHalfH &&
			ball.position.y < player.position.y + player.height){
				return true;
		}
	}
	return false;
}

void movePlayer(moveableobject &player)
{
float speed = sqrt (ball.speed.x*ball.speed.x + ball.speed.y*ball.speed.y - 30);

if(IsKeyDown('S'))
{
	//int diff = player.position.y;
	player.speed.y = 1;
}
else if(IsKeyDown('W'))
{
	//int diff = player.position.y;
	player.speed.y = -1;
}else
{
	player.speed.y = 0;
}
}

	void updateGame(){

		movePlayer(player1);
	
		ball.position.x += ball.speed.x;
		ball.position.y += ball.speed.y;

		player1.position.y += player1.speed.y;
		//(checkPaddleCollision(ball, player1) || checkPaddleCollision(ball, player2))
		
			if(ball.speed.x <0){
				if(checkPaddleCollision(ball, player1) == true)
				{
				ball.speed.x *= -1;
				}
			}
			else {
				if(checkPaddleCollision(ball, player2) == true)
				ball.speed.x *= -1;
			}
		
	
		
		testOnScreen(ball);
		MoveSprite(ball.sprite, ball.position.x ,ball.position.y);
		RotateSprite(player1.sprite, 0);
		MoveSprite(player1.sprite, player1.position.x ,player1.position.y);
		//MoveSprite(ball.sprite, ball.position.x ,ball.position.y);

	}

	void drawGame()
	{
	DrawSprite(bgImage);
	DrawSprite(ball.sprite);
	DrawSprite(player1.sprite);
	DrawSprite(player2.sprite);

	}

	void testOnScreen(moveableobject &obj)
	{
	if(obj.position.x > SCREEN_X) {
		obj.speed.x *= -1;
		return ;
	}
	if(obj.position.x < 0) {
		obj.speed.x *= -1;
		return;
	}
	if(obj.position.y > SCREEN_Y) {
		obj.speed.y *= -1;
		return;
	}
	if(obj.position.y < 0) {
		obj.speed.y *= -1;
	
	}
}

	void destroyGame() {
	DestroySprite(bgImage);
	DestroySprite(ball.sprite);
	DestroySprite(player1.sprite);
	DestroySprite(player2.sprite);
	}