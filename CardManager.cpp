/*
 * CardManager.cpp
 *
 *  Created on: Sep 24, 2023
 *      Author: ahmed
 */

#include "CardManager.h"

//extern const int screenWidth;
//extern const int screenHeight;


CardManager::CardManager() {
	// TODO Auto-generated constructor stub

	    pos.x=100;
	    pos.y=100;

	texture = LoadTexture("assets/card.png");
	Vector2 backSize;
	backSize.x=texture.width;
	backSize.y=texture.height;

	sourceRect = { 0.0f, 0.0f, (float)backSize.x, (float)backSize.y };
	  destRect = { pos.x, pos.y,(float)texture.width*scale, (float)texture.height*scale };

	for(int i=0;i<cardSize;i++){
		Texture2D front;
		front=LoadTexture(path[i]);
		frontText.push_back(front);
//		frontText[i]=LoadTexture(path[i]);

	}



	        for(int i=0;i<cardSize*2;i++){

	       	 Card* card=new Card(destRect,texture,frontText[i%cardSize]);
	       		        	  cards.push_back(card);

	        	  if(destRect.x>720-texture.width){
	                		  destRect.y+=texture.height/2;
	                		  destRect.x=0;
	                	  }
	        	  destRect.x+=100;

	        }




}


void CardManager::update(){

    for(int i=0;i<cards.size();i++){
     	cards[i]->update();

     	if(cards[i]->isIsClicked()&&i!=cardIndex2&&nextCard==false&&cardIndex1==-1){

     		cardIndex1=i;
     		nextCard=true;
     		std::cout<<"cardIndex1 "<<cardIndex1<<std::endl;
     	}

   	 if(cards[i]->isIsClicked()&&i!=cardIndex1&&nextCard==true&&cardIndex2==-1){
   		cardIndex2=i;
   		std::cout<<"cardIndex2 "<<cardIndex2<<std::endl;

   	  }

   	 //reset after two
   	 if(cardIndex1!=-1&&cardIndex2!=-1&&cards[i]->isIsClicked()&&!isReset){
   		isReset=true;
   		 startTimer=true;

//   		 cards[cardIndex1]->setIsClicked(false);
//   		cards[cardIndex2]->setIsClicked(false);
//
//   		cardIndex1=-1;cardIndex2=-1;
//   		nextCard=false;
//   		startTimer=false;



   	 }



     }

    if(startTimer){cout<<"yes"<<std::endl;
    	StartTimer(&intervalCard,1.4f);
    	startTimer=false;
      }
		 if(isReset&&TimerDone(&intervalCard)){
cout<<"yes";
		 cards[cardIndex1]->setIsClicked(false);
		cards[cardIndex2]->setIsClicked(false);

		cardIndex1=-1;cardIndex2=-1;
		nextCard=false;
		startTimer=false;
isReset=false;
	    }



	    if(isReset&&!TimerDone(&intervalCard))
	 	 UpdateTimer(&intervalCard);

}



void CardManager::draw(){
    for(int i=0;i<cards.size();i++){

    	cards[i]->draw();
    }

}
CardManager::~CardManager() {
	// TODO Auto-generated destructor stub
    UnloadTexture(texture);
    for(int i=0;i<frontText.size();i++){
	    UnloadTexture(frontText[i]);
    }

    for(int i=0;i<cards.size();i++){
    	delete cards[i];
    }


}
