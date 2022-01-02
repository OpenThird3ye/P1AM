#include <P1AM.h>
#include <P1_HSC.h>

/******************************************************************************************
 * Automationdirect.com
 * This version of ProductivityBlocks supports P1AM-100 Library V1.0.3
 * To download this library, please visit https://github.com/facts-engineering/P1AM
 * For information on the P1AM-100 hardware, please visit https://www.automationdirect.com
 ******************************************************************************************/

 /*Modules
  * P1AM-100
  * P1-08TRS
  * P1-08SIM
  */
  
/*declare variables*/

int disc01 = 0;
int disc02 = 0;
int disc08 = 0;
int xyz = 0;

  
void setup()
{
  Serial.begin(115200);
  while(!P1.init())
  {
  }

}

void loop()
{
  xyz = 0;
/* P1.printModules(); */

/* Discrete Status to Serial Monitor as start of each loop*/

 /* Discrete 01 */
  P1.readDiscrete(2, 0),1-1;
  disc01 = bitRead(P1.readDiscrete(2, 0),1-1);
  Serial.print("DISC01 Status = ");
  Serial.print(disc01);
  Serial.print("\n");

  /* Discrete 02 */
  P1.readDiscrete(2, 0),2-1;
  disc02 = bitRead(P1.readDiscrete(2, 0),2-1);
  Serial.print("DISC02 Status = ");
  Serial.print(disc02);
  Serial.print("\n");

   /* Discrete 08 */
  P1.readDiscrete(2, 0),8-1;
  disc08 = bitRead(P1.readDiscrete(2, 0),8-1);
  Serial.print("DISC08 Status = ");
  Serial.print(disc08);
  Serial.print("\n");

  /*Select SIM (slot 2, switch 1 to ON, slot 2 switch 2 to ON, slot 2 switch 8 to OFF)*/ 
  while (bitRead(P1.readDiscrete(2, 0),1-1) == 1 && (bitRead(P1.readDiscrete(2, 0),2-1)) == 1 && (bitRead(P1.readDiscrete(2, 0),8-1)) == 0 && (xyz == 0))
  {
    delay(50);
    
    /*Turn On  Slot 1, Relay 1*/
    P1.writeDiscrete( (uint32_t)HIGH, 1, 1);
    xyz = 1;
             
  }
  /*If relay was activated, it remains ON until both switches are OFF*/ 
  while (bitRead(P1.readDiscrete(2, 0),1-1) == 0 && (bitRead(P1.readDiscrete(2, 0),2-1)) == 0 && (bitRead(P1.readDiscrete(2, 0),8-1)) == 0 && (xyz == 0))
  {
    delay(50);
    
    P1.writeDiscrete( (uint32_t)LOW, 1, 1); 
    xyz = 1;
          
  } 
  Serial.print("End Loop \n");
  /*Wait 1 second*/
  delay(1000); 
}
