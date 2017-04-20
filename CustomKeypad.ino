/* @file CustomKeypad.pde
|| @version 1.0
|| @author Alexander Brevig
|| @contact alexanderbrevig@gmail.com
||
|| @description
|| | Demonstrates changing the keypad size and key values.
|| #
*/
#include <Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
int DW, MW, SW, DN, MN, SN, key, num = 0;
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'5','6','7','C'},
  {'C','D','E','F'}
};
byte rowPins[ROWS] = {52, 50, 46, 38}; //connect to the row pinouts of the keypad52
byte colPins[COLS] = {53, 51, 47, 49}; //connect to the column pinouts of the keypad53

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup(){
  Serial.begin(9600);
}
  
//void loop(){
int GetNumber()
{
   //int num = 0;
  int   key = customKeypad.getKey();
   switch (key)
   {
     case NO_KEY:
      break;
    case '*':
    {
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
      //serial.println(key);
      num = num * 10 + (key - '0');
      break;
    }
    case '#':
        return num;
        break;

    
   }
//}
DW = GetNumber();   //gets the degrees latitude
MW = GetNumber();   //gets the minutes latitude
  MW = MW/60;       //converts minutes to decimal degreees
SW = GetNumber();   //gets the seconds latitude
  SW = SW/60;       //converts seconds to decimal degrees
DW = DW + MW + SW;  //adds all the decimals together
DN = GetNumber();   //gets the degrees longitude
MN = GetNumber();   //gets the minutes longitude
  MN = MN/60;       //converts minutes to decimal degrees
SN = GetNumber();   //gets the seconds longitude
  SN = SN/60;       //converts seconds to decimal degrees
DN = MN + SN;       //adds all the decimals together

  }
