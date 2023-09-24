#include <iostream>
#include<raylib.h>


#include<vector>
#include<string>

#include "raymath.h"

#include"CardManager.h"
// define a timer


using std::string;


const int screenWidth = 720;
const int screenHeight = 1000;
//std::vector<Card*> cards;

void draw();
void update();



int main(int argc, char **argv) {
	  // Initialization

	    InitWindow(screenWidth, screenHeight, "meomary card");

//
//for(int i=0;i<cardSize;i++){
//	frontText[i]=LoadTexture(path[i]);
//
//}
//
////create cards(inintilzation)
//        for(int i=0;i<cardSize*2;i++){
//
//        	  Card* card=new Card(destRect,texture,frontText[i%cardSize]);
//        	  cards.push_back(card);
//
//        	  if(destRect.x>screenWidth-texture.width){
//                		  destRect.y+=texture.height/2;
//                		  destRect.x=0;
//                	  }
//        	  destRect.x+=100;
//
//        }
//
//        float totalWidth=texture.width*cardSize;

	    CardManager* cardGame=new CardManager();


	    SetTargetFPS(60);
//	    Timer* timer=new Timer();
//

	    // Main game loop


	    while (!WindowShouldClose()) {
	        // Update

	    	cardGame->update();
	        // Draw
	        BeginDrawing();

	        ClearBackground(RAYWHITE);

	        cardGame->draw();

	        	if(cardGame->winPoint==cardGame->cardSize){
	        		delete cardGame;
	        		cardGame=new CardManager();
	        		std::cout<<"you win";

	        	}

	        DrawText("Move card with mouse", 10, 10, 20, DARKGRAY);

	        EndDrawing();
	    }


//	    for(Card* c:cards){
//	    	delete c;
//	    }
//	    cards.clear();
//	    // Unload the texture when you're done with it


	    CloseWindow();

	    return 0;
}
//

int cardIndex1=-1,cardIndex2=-1;

bool nextCard=false;

int timer=0;

bool startTimer=false;
void update(){


//
//    for(int i=0;i<cards.size();i++){
//     	cards[i]->update();
//
//     	if(cards[i]->isIsClicked()&&i!=cardIndex2&&nextCard==false&&cardIndex1==-1){
//
//     		cardIndex1=i;
//     		nextCard=true;
//     		std::cout<<"cardIndex1 "<<cardIndex1<<std::endl;
//     	}
//
//   	 if(cards[i]->isIsClicked()&&i!=cardIndex1&&nextCard==true&&cardIndex2==-1){
//   		cardIndex2=i;
//   		std::cout<<"cardIndex2 "<<cardIndex2<<std::endl;
//
//   	  }
//
//   	 //reset after two
//   	 if(cardIndex1!=-1&&cardIndex2!=-1&&cards[i]->isIsClicked()){
//
//   		 startTimer=true;
//
//   		 if(startTimer>90){
//
//   		 cards[cardIndex1]->setIsClicked(false);
//   		cards[cardIndex2]->setIsClicked(false);
//
//   		cardIndex1=-1;cardIndex2=-1;
//   		nextCard=false;
//   		startTimer=false;
//
//   	    }
//
//
//   	 }
//
//     }


}


void draw(){
//
//    for(int i=0;i<cards.size();i++){
//    	cards[i]->draw();
//    }




}
