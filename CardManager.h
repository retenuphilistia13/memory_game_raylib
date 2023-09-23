

#ifndef CARDMANAGER_H_
#define CARDMANAGER_H_

#include<raylib.h>
#include<vector>
#include<iostream>

#include"Card.h"
#include"Timer.h"
using std::vector;
using std::cout;


class CardManager {
public:

	std::vector<Card*> cards;

	int cardIndex1=-1,cardIndex2=-1;

	bool nextCard=false;

	bool startTimer=false;

	bool isReset=false;
Timer intervalCard;

	CardManager();
	 ~CardManager();


    // Load a texture
    Texture2D texture ;
int cardSize=5;


    float scale=0.3;
    Vector2 pos;
//    pos.x=100;
//    pos.y=100;

Vector2 backSize;
//backSize.x=texture.width;
//backSize.y=texture.height;

    Rectangle sourceRect ;
    Rectangle destRect ;





//load front texture

vector<Texture2D>frontText;
const char* path[5]={"assets/gumball.png","assets/darwin.png","assets/ritchard.png","assets/sara.png","assets/banana_joe.png"};


	void update();
	void draw();
};

#endif /* CARDMANAGER_H_ */
