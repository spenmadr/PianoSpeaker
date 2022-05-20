#include <PCM.h>

const unsigned char aSample[] PROGMEM = {};
void setup()
{
  startPlayback(aSample, sizeof(sample));
}

void loop()
{
}
