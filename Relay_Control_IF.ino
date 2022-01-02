#include <P1AM.h>
#include <P1_HSC.h>

/******************************************************************************************
 * Automationdirect.com
 * This version of ProductivityBlocks supports P1AM-100 Library V1.0.3
 * To download this library, please visit https://github.com/facts-engineering/P1AM
 * For information on the P1AM-100 hardware, please visit https://www.automationdirect.com
 ******************************************************************************************/

/*Switch control from the SIM module to force ON certain relays*/

/*Modules
 * P1AM
 * SLOT 1 = P1-08TRS
 * SLOT 2 = P1-08SIM
 */

void setup()
{
  Serial.begin(115200);
  while(!P1.init())
  {
  }

}

void loop()
{
  /* P1.printModules();	*/


  /*If SIM switch 1 is ON turn Relay 1 ON*/
  if (bitRead(P1.readDiscrete(2, 0),1-1))
  {
    P1.writeDiscrete( (uint32_t)HIGH, 1, 1);	
    delay( 250 );
    /*Print Status to Serial Monitor*/
    Serial.println("DISC_2_1 ON");
    
  }
  else
  {
    /*If SIM switch 1 is OFF turn Relay 1 OFF*/
    P1.writeDiscrete( (uint32_t)LOW, 1, 1);	
    delay( 250 );
    /*Print Status to Serial Monitor*/
    Serial.println("DISC_2_1 OFF");
    
  }
   /*If SIM switch 2 is ON turn Relay 2 ON*/
  if (bitRead(P1.readDiscrete(2, 0),2-1))
  {   
    P1.writeDiscrete( (uint32_t)HIGH, 1, 2);	
    delay( 250 );
    /*Print Status to Serial Monitor*/
    Serial.println("DISC_2_2 ON");
    
  }
  else
  {
    /*If SIM switch 2 is OFF turn Relay 2 OFF*/
    P1.writeDiscrete( (uint32_t)LOW, 1, 2);	
    delay( 250 );
    /*Print Status to Serial Monitor*/
    Serial.println("DISC_2_2 OFF");
    
  }
}
