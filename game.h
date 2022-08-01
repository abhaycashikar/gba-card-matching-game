#ifndef GAME_H
#define GAME_H

#include "gba.h"
#include "images/dragonFace.h"
#include "images/electrFace.h"
#include "images/fireFace.h"
#include "images/flyingFace.h"
#include "images/ghostFace.h"
#include "images/grassFace.h"
#include "images/normalFace.h"
#include "images/psychcFace.h"
#include "images/waterFace.h"

#define CARD_HEIGHT 46
#define CARD_WIDTH 36
#define FACE_HEIGHT CARD_HEIGHT - 6
#define FACE_WIDTH CARD_WIDTH - 6

// Resets the game to its original state. Called when the game is started or Select is pressed.
void resetState(void);

void initCards(void);

void redrawCards(u32, u32);

int flipCard(void);

void drawCard(int, int, const u16 *);

void wait(int);

typedef enum {
    UP,
    DOWN,
    LEFT,
    RIGHT
} Direction;

struct cursor {
    int row;
    int col;
    int prevRow;
    int prevCol;
} cursor;

typedef struct card {
    int row;
    int col;
    int value;
    int isFlipped;
    int isMatched;
} Card;

Card cards[18];
Card flippedCards[2];
int flippedCardCount;
int matchedPairs;
const u16 *faces[9] = {dragonFace, electrFace, fireFace, flyingFace, ghostFace, grassFace, normalFace, psychcFace, waterFace};

void drawFace(Card);

#endif
