#include "EncryptEngine.h"

EncryptEngine::EncryptEngine()
{

}

bool EncryptEngine::EncryptCezar(std::string& text, int symbols)
{
    char* chars = new char[text.size() + 1];
    std::copy(text.begin(), text.end(), chars);
    chars[text.size()] = '\0';


    for (int clk = 0; clk < text.size(); clk++) {
        chars[clk] += symbols;
    }
    text = chars;
    return true;
}


bool EncryptEngine::Encrypt(std::string& text, std::string key)
{
    int* code = new int[key.size() + 1];
    char* codeChars = new char[key.size() + 1];
    std::copy(key.begin(), key.end(), codeChars);
    for (int clk = 0; clk < key.size(); clk++) code[clk] = (int)codeChars[clk] - 48;
    code[key.size()] = -1;


    char* chars = new char[text.size() + 1];
    std::copy(text.begin(), text.end(), chars);
    chars[text.size()] = '\0';


    for (int clk = 0, clkCode = 0; clk < text.size(); clk++) {
        if (code[clkCode] == -1) clkCode = 0;
        chars[clk] += code[clkCode];
        clkCode++;
    }
    text = chars;
    return true;
}

bool EncryptEngine::DecryptCezar(std::string& text, int symbols)
{
    char* chars = new char[text.size() + 1];
    std::copy(text.begin(), text.end(), chars);
    chars[text.size()] = '\0';


    for (int clk = 0; clk < text.size(); clk++) {
        chars[clk] -= symbols;
    }
    text = chars;
    return true;
}


bool EncryptEngine::Decrypt(std::string& text, std::string key)
{
    int* code = new int[key.size() + 1];
    char* codeChars = new char[key.size() + 1];
    std::copy(key.begin(), key.end(), codeChars);
    for (int clk = 0; clk < key.size(); clk++) code[clk] = (int)codeChars[clk] - 48;
    code[key.size()] = -1;


    char* chars = new char[text.size() + 1];
    std::copy(text.begin(), text.end(), chars);
    chars[text.size()] = '\0';


    for (int clk = 0, clkCode = 0; clk < text.size(); clk++) {
        if (code[clkCode] == -1) clkCode = 0;
        chars[clk] -= code[clkCode];
        clkCode++;
    }
    text = chars;
    return true;
}

bool EncryptEngine::Export(std::string text, std::string location, int pxDistance, std::string password)
{
    char* chars = new char[text.size() + 1];
    std::copy(text.begin(), text.end(), chars);
    chars[text.size()] = '\0';

    EncryptCezar(password, 20);
    char* charsPass = new char[password.size() + 1];
    std::copy(password.begin(), password.end(), charsPass);
    charsPass[password.size()] = '\0';

    int w = 255;
    double pixelsTmp = text.size() / 3.0;
    double hTmp = ((ceil(pixelsTmp) + ((ceil(pixelsTmp) * pxDistance) - 1)) / 256.0);
    int h = round(hTmp);
    if (h == 0)h = 1;
    std::ofstream stream(location += ".bmp", std::ios::binary);

    if (!stream.is_open()) {
        return false;
    }



    const int padSize = (4 - (w * 3) % 4) % 4;
    const int sizeData = (h * w * 3) + (32 * padSize);
    const int sizeAll = sizeData + sizeof(file) + sizeof(info);

    file[2] = (unsigned char)(sizeAll);
    file[3] = (unsigned char)(sizeAll >> 8);
    file[4] = (unsigned char)(sizeAll >> 16);
    file[5] = (unsigned char)(sizeAll >> 24);



    info[4] = (unsigned char)(w);
    info[5] = (unsigned char)(w >> 8);
    info[6] = (unsigned char)(w >> 16);
    info[7] = (unsigned char)(w >> 24);

    info[8] = (unsigned char)(h);
    info[9] = (unsigned char)(h >> 8);
    info[10] = (unsigned char)(h >> 16);
    info[11] = (unsigned char)(h >> 24);

    info[20] = (unsigned char)(sizeData);
    info[21] = (unsigned char)(sizeData >> 8);
    info[22] = (unsigned char)(sizeData >> 16);
    info[23] = (unsigned char)(sizeData >> 24);

    stream.write((char*)file, sizeof(file));
    stream.write((char*)info, sizeof(info));


    int clk = 0, clkNextRow = 0;
    char currentColor = 'r';
    char pixel[3] = {0, 0, 0};
    int lastPixelSet = -1;
    const char pad[3] = { (char)255, (char)255, (char)255 };
    int pxDistClock = 0;

    while (chars[clk] != '\0')
    {
        if (pxDistClock == 0) {
            if (currentColor == 'r')
            {
                currentColor = 'g';
                lastPixelSet = 0;
                pixel[lastPixelSet] = chars[clk];
                clk++;
            }
            else if (currentColor == 'g')
            {
                currentColor = 'b';
                lastPixelSet = 1;
                pixel[lastPixelSet] = chars[clk];
                clk++;
            }
            else if (currentColor == 'b')
            {
                currentColor = 'W';
                lastPixelSet = 2;
                pixel[lastPixelSet] = chars[clk];
                clk++;
            }
            else if (currentColor == 'W')
            {
                currentColor = 'r';
                lastPixelSet = -1;
                stream.write(pixel, 3);
                clkNextRow++;
                pxDistClock++;
            }
        }
        else
        {
            char randPx[3] = { (char)255, (char)0, (char)0 };
            RandomPixel(randPx);
            stream.write(randPx, 3);
            clkNextRow++;
            pxDistClock++;
        }

        if (clk >= text.size())
        {
            if (lastPixelSet = 0) pixel[1] = '\0';
            else if (lastPixelSet = 1) pixel[2] = '\0';
            stream.write(pixel, 3);
            clkNextRow++;
            char end[3] = { (char)0, (char)255, (char)255 };
            while (clkNextRow < w) {
                RandomPixel(end);
                stream.write(end, 3);
                clkNextRow++;
            }
            stream.write(pad, padSize);
            break;
        }

        if (clkNextRow >= w)
        {
            clkNextRow = 0;
            stream.write(pad, padSize);
            pxDistClock++;
        }

        if (pxDistClock > pxDistance) pxDistClock = 0;
    }


    currentColor = 'r';
    clk=0;

    while (charsPass[clk] != '\0')
    {
            if (currentColor == 'r')
            {
                currentColor = 'g';
                lastPixelSet = 0;
                pixel[lastPixelSet] = charsPass[clk];
                clk++;
            }
            else if (currentColor == 'g')
            {
                currentColor = 'b';
                lastPixelSet = 1;
                pixel[lastPixelSet] = charsPass[clk];
                clk++;
            }
            else if (currentColor == 'b')
            {
                currentColor = 'W';
                lastPixelSet = 2;
                pixel[lastPixelSet] = charsPass[clk];
                clk++;
            }
            else if (currentColor == 'W')
            {
                currentColor = 'r';
                lastPixelSet = -1;
                stream.write(pixel, 3);
            }
    }
    if(lastPixelSet!=-1){
        if(lastPixelSet==0){
            pixel[1] = '.';
            pixel[2] = '.';
        }
        else if(lastPixelSet==1){
            pixel[2] = '.';
        }
         stream.write(pixel, 3);
    }



    stream.close();
    return true;
}


bool EncryptEngine::Import(std::string& text, std::string location, int pxDistance)
{
    std::ifstream stream(location += ".bmp", std::ios::binary); // otwieramy plik do odczytu binarnego
    stream.read((char*)file, sizeof(file));
    stream.read((char*)info, sizeof(info));

    text = "";
    if (!stream.is_open()) {
        return false;
    }
    const char pad[3] = { (char)255,(char)255,(char)255 };
    char* temp = new char[3]; // tymczasowy bufor na dane

    while (true)
    {
        stream.read(temp, 3);
        if (temp[0] == pad[0] || temp[1] == pad[1] || temp[2] == pad[2])
        {}
        else
        {
            text = text + temp[0] + temp[1] + temp[2];
            if (temp[0] == '\0' || temp[1] == '\0' || temp[2] == '\0') break;
            for (int clk = 0; clk < pxDistance; clk++) stream.read(temp, 3);
        }
    }

    stream.close();
    return true;
}

void EncryptEngine::SeparateCode(std::string toSeparate, int& noisePx, std::string& cipher) {
    std::string noisePxString = toSeparate.substr(0, 2);
    noisePx = std::stoi(noisePxString);
    cipher = toSeparate.substr(2, toSeparate.size() - 2);
}


/*Funkcje pomocnicze, prywatne*/

void EncryptEngine::RandomPixel(char* val)
{

    int tmp[3] = { 0, 0, 0 };
    for (int clk = 0; clk < 3; ++clk) tmp[clk] = random();
    for (int clk = 0; clk < 3; ++clk) val[clk] = tmp[clk];
}

int EncryptEngine::random(void) {
    static unsigned long x = 123456789, y = 362436069, z = 521288629;
    unsigned long t;
    x ^= x << 16;
    x ^= x >> 5;
    x ^= x << 1;

    t = x;
    x = y;
    y = z;
    z = t ^ x ^ y;

    int val = (int)z;
    if (val < 0) val = val * -1;
    while (val > 255) val = val / 2;
    val += 169;
    return val;
}
