#include <iostream>
#include "AES.h"

int main()
{
  unsigned char plain[] = "Hello World"; //plaintext example
  unsigned char key[] = { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f }; //key example
  unsigned int plainLen = 16 * sizeof(unsigned char);  //bytes in plaintext  should always be multiple for 16. Use 32 for 256bit encryption

  AES aes(AESKeyLength::AES_128);  ////128 - key length, can be 128, 192 or 256
  unsigned char *encrypted = aes.EncryptECB(plain, plainLen, key);

  std::cout << encrypted << std::endl;

  unsigned char* decrypted = aes.DecryptECB(encrypted, plainLen, key);

  std::cout << decrypted << std::endl;

  return 0;
}
