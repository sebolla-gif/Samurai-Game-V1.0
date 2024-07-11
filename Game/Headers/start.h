#ifndef START_H_INCLUDED
#define START_H_INCLUDED
#include <unistd.h>
#include <iostream>
#include <allegro.h>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <ctime>
#define VX 1440
#define VY 900

extern BITMAP *buffer;
extern BITMAP *moon;
extern BITMAP *light;
extern BITMAP *sea;
extern BITMAP *cloud;
extern BITMAP *title;
extern BITMAP *press;

const float GRAVITY = 10;
const int FPS = 18;
const int FRAME_TIME = 1000 / FPS;
const int rows = 10;
const int cols = 6;



void start_program();
int** create_matrix();
void initialize_matrix(int** matrix);
void free_matrix(int** matrix);
int** obtenerMatriz(int numero);
void TimeControl(int startTime);
void menu();


#endif // START_H_INCLUDED
