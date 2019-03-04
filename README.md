# esp32-Encrypt

This little example project will focus on how to cipher or decipher data with AES-128 in ECB mode, on the Arduino core running on the ESP32. Based on the examples mentioned on [techtutorialsx.com](https://techtutorialsx.com/2018/05/10/esp32-arduino-decrypt-aes-128-in-ecb-mode/) and [github.com](https://github.com/suculent/thinx-aes-lib) i have created the class Cipher (Cipher.h) to encrypt and decrypt a hole string with variable length. To store the result on the internal storage of the ESP32, the class CSPIFFS (SPIFFSTest.h) is quite helpfull to achieve this aim.

Here is a little arduino console output picture to visualize project achievements:

<p align="center"><img width="95%" src="demo.png"></p>
