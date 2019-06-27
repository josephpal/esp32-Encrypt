#include "mbedtls/aes.h"
#include "SPIFFSTest.h"
#include "Cipher.h"

CSPIFFS mSpiffs;


void setup() {
 
  Serial.begin(115200);
  Cipher * cipher = new Cipher();
  
  SPIFFS.begin(true);
  mSpiffs.listDir(SPIFFS, "/", 0);
  
  char * key = "weogrbasztvszvas";
  
  String ssid = "Android-AP";
  String password = "123456789";

  Serial.print("\nSetting cipher key: ");
  Serial.println(key);
  cipher->setKey(key);

  Serial.println("\nOriginal plain text:");
  Serial.println("SSID: " + ssid);
  Serial.println("PASSWORD: " + password);

  Serial.println("\nCiphered text:");
  String cipheredConfig = cipher->encryptString(ssid) + "\n" + cipher->encryptString(password);
  Serial.println(cipheredConfig);
  mSpiffs.writeFile(SPIFFS, "/wlanConfiguration.txt", cipheredConfig);

  Serial.println("\nDeciphered text:");
  
  String cipheredConfigFileContent = mSpiffs.getFile(SPIFFS, "/wlanConfiguration.txt");
  String cipheredSsid = cipheredConfigFileContent.substring(0, cipheredConfigFileContent.indexOf('\n'));
  String cipheredPassword = cipheredConfigFileContent.substring(cipheredConfigFileContent.indexOf('\n') + 1);

  String decipheredSsid = cipher->decryptString(cipheredSsid);
  String decipheredPassword = cipher->decryptString(cipheredPassword);
  
  Serial.println("SSID: " + decipheredSsid);
  Serial.println("PASSWORD: " + decipheredPassword);
}
 
void loop() {
  
}
