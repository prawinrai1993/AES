#include <iostream>
#include "AES.h"
#include <chrono>
using namespace std::chrono;

unsigned char * getRandomPlain(unsigned int length)
{
  unsigned char *plain = new unsigned char[length];
  for (unsigned int i = 0; i < length; i++) {
    plain[i] = rand() % 256;
  }

  return plain;

}

int main()
{
  const unsigned int MEGABYTE = 1024 * 1024 * sizeof(unsigned char);

  unsigned int megabytesCount = 10;
  unsigned int plainLength = megabytesCount * MEGABYTE;
  unsigned char key[] = { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f };

  std::cout << "Start speedtest" << std::endl;

  unsigned char *plain = getRandomPlain(plainLength);
  
  AES aes(AESKeyLength::AES_256);
  auto start = high_resolution_clock::now();
  unsigned char *out = aes.EncryptECB(plain, plainLength, key);
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>( stop - start);

  printf("%f MB/s", (double)MEGABYTE/(double)(duration.count()));

  delete[] plain;
  delete[] out;

  return 0;
}