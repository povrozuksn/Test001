#include "TXLib.h"

struct Forma
{
    string text_question;
    int right_answer;
    HDC pic_answer1;
    string text_answer1;
    HDC pic_answer2;
    string text_answer2;
    HDC pic_answer3;
    string text_answer3;
};

void drawAnswer(int x, HDC pic_answer, string text_answer)
{
    txSelectFont("Times New Roman", 40);
    txSetColor (TX_WHITE, 7);
    txRectangle (x, 320, x+200, 470);
    txBitBlt(txDC(), x, 320, 200, 150, pic_answer);
    txDrawText  (x, 500, x+200, 550, text_answer.c_str());
}

bool clickAnswer(int x)
{
    return(txMouseButtons()==1 && txMouseX()>x && txMouseX()<x+200 && txMouseY()>320 && txMouseY()<470);
}

int main()
{
txCreateWindow (800, 600);

    int kol_question = 3;

    Forma quest_buf;

    Forma quest[kol_question];

    quest[0] = {"� ����� ������ ������ �������?", 2,
                    txLoadImage("��������/���������.bmp"), "���������",
                    txLoadImage("��������/������.bmp"), "������",
                    txLoadImage("��������/������.bmp"), "������"};

    quest[1] = {"��������� ������� ������?", 3,
                    txLoadImage("��������/�����.bmp"), "�����",
                    txLoadImage("��������/�����.bmp"), "�����",
                    txLoadImage("��������/����.bmp"), "����"};

    quest[2] = {"����� �������� ����� ������?", 3,
                    txLoadImage("��������/������.bmp"), "������",
                    txLoadImage("��������/�����.bmp"), "�����",
                    txLoadImage("��������/��������.bmp"), "��������"};

    int n_question = 1;
    int kol_right_answer = 0;
    char str[50];

    while(n_question <= kol_question)
    {
        txSetColor (TX_BLACK);
        txSetFillColor (TX_BLACK);
        txClear();
        txBegin();

        quest_buf = quest[n_question - 1];

        //������
        txSetColor (TX_WHITE, 1);
        txSetFillColor (TX_TRANSPARENT);
        txRectangle (10, 10, 790, 590);
        //����� � ���������� ��������

        sprintf(str, "������ %d/%d", n_question, kol_question);
        txDrawText(0, 20, 800, 50, str);
        //������
        txSelectFont("Times New Roman", 60);
        txDrawText(0, 0, 800, 200, quest_buf.text_question.c_str());
        //������
        drawAnswer( 50, quest_buf.pic_answer1, quest_buf.text_answer1);
        drawAnswer(300, quest_buf.pic_answer2, quest_buf.text_answer2);
        drawAnswer(550, quest_buf.pic_answer3, quest_buf.text_answer3);

        if(clickAnswer(50))
        {
            if(quest_buf.right_answer == 1) kol_right_answer ++;
            txSleep(200);
            n_question++;
        }

        if(clickAnswer(300))
        {
            if(quest_buf.right_answer == 2) kol_right_answer ++;
            txSleep(200);
            n_question++;
        }

        if(clickAnswer(550))
        {
            if(quest_buf.right_answer == 3) kol_right_answer ++;
            txSleep(200);
            n_question++;
        }
        txEnd();
        txSleep(20);
    }

    txSetColor (TX_WHITE);
    txSetFillColor (TX_BLACK);
    txClear();
    txDrawText(0, 0, 800, 400, "���������");
    sprintf(str, "���������� ���������� ������� %d", kol_right_answer);
    txDrawText(0, 0, 800, 600, str);

    txDeleteDC (quest_buf.pic_answer1);
    txDeleteDC (quest_buf.pic_answer2);
    txDeleteDC (quest_buf.pic_answer3);

txTextCursor (false);
return 0;
}
