#include <PCM.h>

// array of samples 
const unsigned char aSample[] PROGMEM = {};
void setup()
{
  // plays sample
  startPlayback(aSample, sizeof(aSample));
}

void loop()
{
}
