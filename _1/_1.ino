#include <PS2X_lib.h>
PS2X ps2x;

int x;
int error = 0;
byte type = 0;
byte vibrate = 0;
int LY, LX, RY, RX, LYold, LXold, RYold, RXold;
int pwm = 180,pwm1=5,pwm2,pwm3=133;

void setup() {
  Serial.begin(9600);

  error = ps2x.config_gamepad(13,11,10,12, false, false);
  
  if(error == 0){
    Serial.println("Found Controller, configured successful");
  }

}

void loop() {
  if (Serial.available() > 0) {
//    x = Serial.read();
  }

   ps2x.read_gamepad(false, vibrate);

  if(ps2x.ButtonPressed(PSB_PAD_UP))
    {  
      Serial.println("A");
    }
      
  if(ps2x.ButtonReleased(PSB_PAD_UP))
    {
      Serial.println("Z");
    }
  if(ps2x.ButtonPressed(PSB_PAD_DOWN))
    {
      Serial.println("B");
    }
    
  if(ps2x.ButtonReleased(PSB_PAD_DOWN))
    {
      Serial.println("Z");
    }

  if(ps2x.ButtonPressed(PSB_PAD_LEFT))
    {
      Serial.println("C");
    }
    
  if(ps2x.ButtonReleased(PSB_PAD_LEFT))
    {
      Serial.println("Z");
    }

  if(ps2x.ButtonPressed(PSB_PAD_RIGHT))
    {
      Serial.println("D");    
    }
    
  if(ps2x.ButtonReleased(PSB_PAD_RIGHT))
    {
      Serial.println("Z");
    }
    
  if(ps2x.ButtonPressed(PSB_START))
    {
      Serial.println("7");
    }
  if(ps2x.ButtonReleased(PSB_START))
    {
      Serial.println("Z");
    }

  if(ps2x.ButtonPressed(PSB_SELECT))
    {
      Serial.println("8");
    }
  if(ps2x.ButtonReleased(PSB_SELECT))
    {
      Serial.println("Z");
    }

  if(ps2x.ButtonPressed(PSB_TRIANGLE))
    {
      Serial.println("Y");
    }
      
  if(ps2x.ButtonReleased(PSB_TRIANGLE))
    {

    }
      
  if(ps2x.ButtonPressed(PSB_CIRCLE)) //lingkaran
    {
      Serial.println("J");
    }
      
  if(ps2x.ButtonReleased(PSB_CIRCLE))
    {
      
    }
      
  if(ps2x.ButtonPressed(PSB_SQUARE)) //kotak
    {
      Serial.println("P");
    }
    
  if(ps2x.ButtonReleased(PSB_SQUARE))
    {
    
    }
    
  if(ps2x.ButtonPressed(PSB_CROSS))
    {
      Serial.println("K");
    }
    
  if(ps2x.ButtonReleased(PSB_CROSS))
    {
//     Serial.println("Z");
    }

  if(ps2x.ButtonPressed(PSB_L1))
    {
      Serial.println("E");
    }
    
  if(ps2x.ButtonReleased(PSB_L1))
    {
      Serial.println("Z");  
    }

  if(ps2x.ButtonPressed(PSB_R1))
    {
      Serial.println("F");
    }
    
  if(ps2x.ButtonReleased(PSB_R1))
    {
      Serial.println("Z");
    }

  if(ps2x.ButtonPressed(PSB_L2))
    {
      Serial.println("I");
    }
    
  if(ps2x.ButtonReleased(PSB_L2))
    {
     Serial.println("Z");  
    }

  if(ps2x.ButtonPressed(PSB_R2))
    {
      Serial.println("H");
    }
    
  if(ps2x.ButtonReleased(PSB_R2))
    {
      Serial.println("Z");
    }

  if(ps2x.ButtonPressed(PSB_L3))
    {
      Serial.println("V");
    }
    
  if(ps2x.ButtonReleased(PSB_L3))
    {
      
    }

  if(ps2x.ButtonPressed(PSB_R3))
    {
       Serial.println("0");
    }
    
  if(ps2x.ButtonReleased(PSB_R3))
    {
  
    }

  LY = (int) ps2x.Analog(PSS_LY);
  LX = (int) ps2x.Analog(PSS_LX);
  RY = (int) ps2x.Analog(PSS_RY);
  RX = (int) ps2x.Analog(PSS_RX);

  if(LX != LXold || LY != LYold)
  {
    if(LY ==0 && LX == 123) //majupelan
    {
      Serial.println("1");
    }

    if(LY ==255 && LX == 123) //mundurpelan
    {
      Serial.println("2");
    }

    if(LY ==123 && LX == 0) //kiripelan
    {
      Serial.println("3");
    }

    if(LY ==123 && LX == 255) //kananpelan
    {
      Serial.println("4");
    }

    if(LY ==123 && LX == 123) //stopotor
    {
      Serial.println("Z");
    }
    
//    Serial.print("L Stick Values:");
//    Serial.print(LY, DEC);
//    Serial.print(",");
//    Serial.println(LX, DEC);
  }
  
  if(RX != RXold || RY != RYold)
  {
    if(RY ==0 && RX == 123) //majupelan
    {
      Serial.println("5");
    }

    if(RY ==255 && RX == 123) //mundurpelan
    {
      Serial.println("6");
    }

    if(RY ==123 && RX == 0) //kiripelan
    {
      //Serial.println("7");
    }

//    if(RY ==128 && RX == 255) //kananpelan
//    {
//      Serial.println("8");
//    }

    if(RY ==123 && RX == 123) //stopotor
    {
      Serial.println("Z");
    }
    

//    Serial.print("R Stick Values:");
//    Serial.print(RY, DEC);
//    Serial.print(",");
//    Serial.println(RX, DEC);  
  }

  LYold = LY;
  LXold = LX;
  RYold = RY;
  RXold = RX;


  delay(20);

}


