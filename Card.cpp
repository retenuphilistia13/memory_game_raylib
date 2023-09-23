/*
 * Card.cpp
 *
 *  Created on: Sep 22, 2023
 *      Author: ahmed
 */

#include "Card.h"

Card::Card(Rectangle rec,Texture2D backText,Texture2D frontText) {
	// TODO Auto-generated constructor stub
//	 position=pos;
	 backTexture=backText;
	 frontTexture=frontText;

	 destRect =rec;
	 position.x=destRect.x;
	 position.y=destRect.y;
		frontTexture.width=backTexture.width;
		frontTexture.height=backTexture.height;
	 sourceRect = { 0.0f, 0.0f, (float)backTexture.width, (float)backTexture.height };
	 isClicked=false;

}



void Card::draw(){
	   // Draw the textured rectangle
	if(!isClicked)
        DrawTexturePro(backTexture, sourceRect, destRect, Vector2{0, 0}, 0.0f, WHITE);
	else if(isClicked){

		 DrawTexturePro(frontTexture, sourceRect, destRect, Vector2{0, 0}, 0.0f, WHITE);
	}
}
void Card::update(){
if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
Vector2 mousePosition= GetMousePosition();

if(CheckCollisionPointRec(mousePosition,destRect)){
	isClicked=true;
}


}
//	position=GetMousePosition();
//
//	destRect.x=position.x;
//	destRect.y=position.y;
}
Card::~Card() {
	// TODO Auto-generated destructor stub

	  UnloadTexture(backTexture);
}
