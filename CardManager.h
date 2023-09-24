/*
 * CardManager.h
 *
 *  Created on: Sep 24, 2023
 *      Author: ahmed
 */

#ifndef CARDMANAGER_H_
#define CARDMANAGER_H_

#include<raylib.h>
#include<vector>
#include<iostream>
#include<algorithm>
#include"Card.h"
#include"Timer.h"
#include <random>

using std::vector;
using std::cout;
using std::endl;
template <typename T>
void customSwap(T& ptr1, T& ptr2) {
    T temp = ptr1;
    ptr1 = ptr2;
    ptr2 = temp;
}
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
int winPoint=0;


    float scale=0.3;
    Vector2 pos;
//    pos.x=100;
//    pos.y=100;

Vector2 backSize;
//backSize.x=texture.width;
//backSize.y=texture.height;

    Rectangle sourceRect ;
    Rectangle destRect ;



    // Function to shuffle a vector
    template <typename T>
    void shuffleVector(std::vector<T>& vec) {
        std::random_device rd;
        std::mt19937 gen(rd());

        // Shuffle the pointers using the Fisher-Yates shuffle algorithm
        for (int i = vec.size()-1 ; i > 0; --i) {
            std::uniform_int_distribution<int> dist(0, i);
            int j = dist(gen);
            customSwap(vec[i]->destRect, vec[j]->destRect);

            Vector2 pos;

            std::cout<<"rand";


        }
    }


//load front texture

vector<Texture2D>frontText;
const char* path[5]={"assets/gumball.png","assets/darwin.png","assets/ritchard.png","assets/sara.png","assets/banana_joe.png"};


	void update();
	void draw();
};

#endif /* CARDMANAGER_H_ */
