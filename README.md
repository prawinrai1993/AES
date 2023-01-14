# AES
C++ AES(Advanced Encryption Standard) implementation  

# Usage

**This class is very simple to use:**
```c++
...
unsigned char plain[] = { 0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff }; //plaintext example
unsigned char key[] = { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f }; //key example
unsigned int plainLen = 16 * sizeof(unsigned char);  //bytes in plaintext

AES aes(AESKeyLength::AES_128);  ////128 - key length, can be 128, 192 or 256
c = aes.EncryptECB(plain, plainLen, key);
//now variable c contains plainLen bytes - ciphertext
...
```
Or for vectors:
```c++
...


vector<unsigned char> plain = { 0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff }; //plaintext example
vector<unsigned char> key = { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f }; //key example

AES aes(AESKeyLength::AES_128);
c = aes.EncryptECB(plain, key);
//now vector c contains ciphertext
...
```
ECB, CBC, CFB modes are supported.




# Padding
This library does not provide any padding because padding is not part of AES standard. Plaintext and ciphertext length in bytes must be divisible by 16. If length doesn't satisfy this condition exception will be thrown

# BUILD Instructoions
Use Cmake 3.15 above version.
To specify specific compiler add -G "compiler name" to build.bat file.
all executable are generated in build folder

