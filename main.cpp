#include "TXLib.h"

struct Forma
{
    string text_question;
    HDC pic_answer1;
    string text_answer1;
    HDC pic_answer2;
    string text_answer2;
    HDC pic_answer3;
    string text_answer3;
};

int main()
{
txCreateWindow (800, 600);

    Forma quest;

    Forma quest1 = {"� ����� ������ ������ �������?",
                    txLoadImage("��������/���������.bmp"), "���������",
                    txLoadImage("��������/������.bmp"), "������",
                    txLoadImage("��������/������.bmp"), "������"};

    Forma quest2 = {"��������� ������� ������?",
                    txLoadImage("��������/�����.bmp"), "�����",
                    txLoadImage("��������/�����.bmp"), "�����",
                    txLoadImage("��������/����.bmp"), "����"};

    Forma quest3 = {"����� �������� ����� ������?",
                    txLoadImage("��������/������.bmp"), "������",
                    txLoadImage("��������/�����.bmp"), "�����",
                    txLoadImage("��������/��������.bmp"), "��������"};

    int n_question = 1;
    int kol_question = 3;

    while(n_question <= kol_question)
    {
        txSetColor (TX_BLACK);
        txSetFillColor (TX_BLACK);
        txClear();
        txBegin();

        if(n_question == 1) quest = quest1;
        else if(n_question == 2) quest = quest2;
        else if(n_question == 3) quest = quest3;

        //������
        txSetColor (TX_WHITE);
        txSetFillColor (TX_TRANSPARENT);
        txRectangle (10, 10, 790, 590);
        //����� � ���������� ��������
        char str[50];
        sprintf(str, "������ %d/%d", n_question, kol_question);
        txDrawText(0, 20, 800, 50, str);
        //������
        txSelectFont("Times New Roman", 60);
        txDrawText(0, 0, 800, 200, quest.text_question.c_str());
        //������
        txSelectFont("Times New Roman", 40);
        txRectangle (50, 320, 250, 470);
        txBitBlt(txDC(), 50, 320, 200, 150, quest.pic_answer1);
        txDrawText(50, 500, 250, 550, quest.text_answer1.c_str());
        txRectangle (300, 320, 500, 470);
        txBitBlt(txDC(), 300, 320, 200, 150, quest.pic_answer2);
        txDrawText(300, 500, 500, 550, quest.text_answer2.c_str());
        txRectangle (550, 320, 750, 470);
        txBitBlt(txDC(), 550, 320, 200, 150, quest.pic_answer3);
        txDrawText(550, 500, 750, 550, quest.text_answer3.c_str());

        if( txMouseButtons() == 1 &&
            txMouseX() > 50 && txMouseX() < 250 &&
            txMouseY() > 320 && txMouseY() < 470)
        {
            txSleep(200);
            n_question++;
        }

        if( txMouseButtons() == 1 &&
            txMouseX() > 300 && txMouseX() < 500 &&
            txMouseY() > 320 && txMouseY() < 470)
        {
            txSleep(200);
            n_question++;
        }

        if( txMouseButtons() == 1 &&
            txMouseX() > 550 && txMouseX() < 750 &&
            txMouseY() > 320 && txMouseY() < 470)
        {
            txSleep(200);
            n_question++;
        }
        txEnd();
        txSleep(20);
    }

    txSetColor (TX_WHITE);
    txSetFillColor (TX_BLACK);
    txClear();
    txDrawText(0, 0, 800, 600, "���������");

    txDeleteDC (quest.pic_answer1);
    txDeleteDC (quest.pic_answer2);
    txDeleteDC (quest.pic_answer3);

txTextCursor (false);
return 0;
}
