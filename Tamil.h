#ifndef Tamil_h
#define Tamil_h

#include <TamilFont.h>
#include <LiquidCrystal.h>
#include <Arduino.h>

void clean();
void charcreator(LiquidCrystal);
void setcreator(int,LiquidCrystal);
void paint(LiquidCrystal);
void searchandadd(int,int *);
void tamilDisplay(LiquidCrystal,String input);

#endif
