#pragma once
#include <string>
#include <algorithm>  // do u?ywania std::copy
#include <iostream>
#include <fstream> //ofstream
#include <cstdlib> //losowanie liczb
#include <ctime> //losowanie liczb
#include <direct.h> //mkdir
#include <math.h>  //floor
#include <random> //random
#include <Windows.h> //sleep

class EncryptEngine
{
private:
    std::string location;
    std::string text;
    std::string key;
    int lastColorGeneratorTmp;
    void SetInt(unsigned char* mem, int data);
    unsigned char file[14] = {
        'B','M',	        // magic
        0, 0, 0, 0,		// size in bytes
        0, 0,			// app data
        0, 0,			// app data
        40 + 14, 0, 0, 0	// start of data offset
    };
    unsigned char info[40] = {
        40, 0, 0, 0,	        // info size
        0, 0, 0, 0,		// width
        0, 0 ,0, 0,		// height
        1, 0,			// number color planes
        24, 0,		        // bits per pixel
        0, 0, 0, 0,		// compression is none
        0, 0, 0, 0,		// image bits size
        0x13, 0x0B, 0, 0,       // horz resolution in pixel / m
        0x13, 0x0B, 0, 0,       // vert resolutions (0x03C3 = 96 dpi, 0x0B13 = 72 dpi)
        0, 0, 0, 0,		// #colors in pallet
        0, 0, 0, 0,		// #important colors
    };
    void RandomPixel(char* val);
    int random(void);
public:
    EncryptEngine();

    void setLocation(std::string val) { location = val; }
    std::string getLocation() { return location; }
    void setText(std::string val) { text = val; }
    std::string getText() { return text; }
    void setKey(std::string val) { key = val; }
    std::string getKey() { return key; }

    bool EncryptCezar(std::string& text, int symbols);
    bool Encrypt(std::string& text, std::string key);
    bool DecryptCezar(std::string& text, int symbols);
    bool Decrypt(std::string& text, std::string key);
    bool Export(std::string text, std::string location, int pxDistance, std::string password);
    bool Import(std::string& text, std::string location, int pxDistance);
    void SeparateCode(std::string toSeparate, int& noisePx, std::string& cipher);
};
