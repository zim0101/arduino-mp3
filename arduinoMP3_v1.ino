#include <SD.h>
#include <TMRpcm.h>

#define SD_ChipSelectPin 4

TMRpcm speech;

static const char wav_1[] PROGMEM = "0001.wav";
static const char wav_2[] PROGMEM = "0002.wav";
static const char wav_3[] PROGMEM = "0003.wav";
static const char wav_4[] PROGMEM = "0004.wav";
static const char wav_5[] PROGMEM = "0005.wav";
static const char wav_6[] PROGMEM = "0006.wav";
static const char wav_7[] PROGMEM = "0007.wav";
static const char wav_8[] PROGMEM = "0008.wav";
static const char wav_9[] PROGMEM = "0009.wav";
static const char wav_10[] PROGMEM = "0010.wav";

const char *wav_table[] = { wav_1, wav_2, wav_3, wav_4, wav_5, wav_6, wav_7, wav_8, wav_9, wav_10};

void setup()
{
    Serial.begin(9600);

    speech.speakerPin = 9;


    if (!SD.begin(SD_ChipSelectPin)) // see if the card is present and can be initialized:
    {
        return;   // don't do anything more if not
    }

    speech.setVolume(6);
}

void loop()
{
    int randNumber = random(500, 3000);
    char wavFile[10];  //String variable for the name of wav files

    for(int i=0; i<10; i++)            //Loop for playing music on after another
    {
        strcpy_P(wavFile, wav_table[i]);
        speech.play(wavFile);

        while(speech.isPlaying()) { ; }  //While playing the music no other work is done.
        delay(randNumber);
    }
}
