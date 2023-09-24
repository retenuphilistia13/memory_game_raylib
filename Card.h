/*
 * Card.h
 *
 *  Created on: Sep 22, 2023
 *      Author: ahmed
 */

#ifndef CARD_H_
#define CARD_H_
#include<raylib.h>

class Card {

	private:

	int ID;
	bool matched=false;
public:


Rectangle destRect;
Rectangle sourceRect ;
Vector2 position;

bool isClicked;

static bool isAbleToFlip;

Texture2D backTexture;
Texture2D frontTexture;

	Card(Rectangle rec,Texture2D backText,Texture2D frontText);
	virtual ~Card();

	void static setAbleToFlip(bool isFlip){
		isAbleToFlip=isFlip;
	}
	void draw();
	void update();
//	~Card();

	static bool isIsAbleToFlip() {
		return isAbleToFlip;
	}

	void setIsAbleToFlip( bool isAble = true) {
		this->isAbleToFlip = isAble;
	}

	bool isIsClicked() const {
		return isClicked;
	}

	void setIsClicked(bool isClicked) {
		this->isClicked = isClicked;
	}

	int getId() const {
		return ID;
	}

	void setId(int id) {
		ID = id;
	}

	bool isMatched() const {
		return matched;
	}

	void setMatched(bool matched = false) {
		this->matched = matched;
	}
};

#endif /* CARD_H_ */
