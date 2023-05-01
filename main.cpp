#include "TXLib.h"

int main()
{
txCreateWindow (800, 600);

    HDC uln = txLoadImage("Картинки/Ульяновск.bmp");
    HDC msk = txLoadImage("Картинки/Москва.bmp");
    HDC sam = txLoadImage("Картинки/Самара.bmp");
    HDC psk = txLoadImage("Картинки/Псков.bmp");
    HDC tvr = txLoadImage("Картинки/Тверь.bmp");
    HDC tla = txLoadImage("Картинки/Тула.bmp");

    string text_question = "В каком городе больше жителей?";
    HDC pic_answer1 = uln;
    string text_answer1 = "Ульяновск";
    HDC pic_answer2 = msk;
    string text_answer2 = "Москва";
    HDC pic_answer3 = sam;
    string text_answer3 = "Самара";


//ШАБЛОН
    txSetColor (TX_WHITE);
    txSetFillColor (TX_TRANSPARENT);
    txRectangle (10, 10, 790, 590);
    //Вопрос
    txSelectFont("Times New Roman", 60);
    txDrawText(0, 0, 800, 200, text_question.c_str());
    //Ответы
    txSelectFont("Times New Roman", 40);
    txRectangle (50, 320, 250, 470);
    txBitBlt(txDC(), 50, 320, 200, 150, pic_answer1);
    txDrawText(50, 500, 250, 550, text_answer1.c_str());
    txRectangle (300, 320, 500, 470);
    txBitBlt(txDC(), 300, 320, 200, 150, pic_answer2);
    txDrawText(300, 500, 500, 550, text_answer2.c_str());
    txRectangle (550, 320, 750, 470);
    txBitBlt(txDC(), 550, 320, 200, 150, pic_answer3);
    txDrawText(550, 500, 750, 550, text_answer3.c_str());




    txDeleteDC (uln);
    txDeleteDC (msk);
    txDeleteDC (sam);

txTextCursor (false);
return 0;
}

