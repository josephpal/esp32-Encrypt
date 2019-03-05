#include "mbedtls/aes.h"
#include "SPIFFSTest.h"
#include "Cipher.h"

CSPIFFS mSpiffs;
Cipher * cipher = new Cipher();

void setup() {
 
  Serial.begin(115200);
  
  SPIFFS.begin(true);
  mSpiffs.listDir(SPIFFS, "/", 0);
  
  char * key = "abcdefghijklmnop";
  String plainText = "Tech tutorials xTech tutorials xxyzgvszufsdgftzsdfgsdfzfsfdzfsdzfsdtzfdtzsfdtzsfdtzfsdtzfstzfzsfdfzs";

  Serial.print("\nSetting cipher key: ");
  Serial.println(key);
  cipher->setKey(key);

  Serial.println("\nOriginal plain text:");
  Serial.println(plainText);

  Serial.println("\nCiphered text:");
  String text = cipher->encryptString(plainText);
  Serial.println(text);
  mSpiffs.writeFile(SPIFFS, "/test.txt", text);

  Serial.println("\nDeciphered text:");
  Serial.println(cipher->decryptString(mSpiffs.getFile(SPIFFS, "/test.txt")));
}
 
void loop() {
  
}
