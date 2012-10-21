#include <LiquidCrystal.h>
#include <Tamil.h>
LiquidCrystal lcd(8,9,10,11,12,13);
void setup()
{
  lcd.begin(16,2);
  lcd.clear();
}

void loop()
{
   tamilDisplay(lcd,"fprPljegkauytHswd");
//   tamilDisplay(lcd,"mmMnNzVbBicCcS");
}
