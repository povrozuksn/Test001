#include "TXLib.h"
#include <fstream>

using namespace std;

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

string getPart(string str, int *pos2)
{
    int pos1 = *pos2 + 1;
    *pos2 = str.find(",", pos1);
    string Part = str.substr(pos1, *pos2-pos1);
    return Part;
}

int main()
{
setlocale(LC_ALL, "Russian");
txCreateWindow (800, 600);

    int kol_question;
    Forma quest_buf;
    Forma quest[20];
    int n_question = 1;
    int kol_right_answer = 0;
    char stroka[50];
    string str;

    ifstream file("�������.txt");

    int n = 0;
    while(file.good())
    {
        getline(file, str);
        int pos2 = -1;
        quest[n].text_question = getPart(str, &pos2);
        quest[n].right_answer = atoi(getPart(str, &pos2).c_str());
        quest[n].pic_answer1 = txLoadImage(getPart(str, &pos2).c_str());
        quest[n].text_answer1 = getPart(str, &pos2);
        quest[n].pic_answer2 = txLoadImage(getPart(str, &pos2).c_str());
        quest[n].text_answer2 = getPart(str, &pos2);
        quest[n].pic_answer3 = txLoadImage(getPart(str, &pos2).c_str());
        quest[n].text_answer3 = getPart(str, &pos2);
        n++;
    }

    kol_question = n;

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
        sprintf(stroka, "������ %d/%d", n_question, kol_question);
        txDrawText(0, 20, 800, 50, stroka);
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
    sprintf(stroka, "���������� ���������� ������� %d", kol_right_answer);
    txDrawText(0, 0, 800, 600, stroka);

    if(kol_right_answer<=2) txDrawText(0, 200, 800, 600, "�� ��������");
    else if(kol_right_answer>2 && kol_right_answer<=5) txDrawText(0, 200, 800, 600, "�� ����");
    else if(kol_right_answer>=6) txDrawText(0, 200, 800, 600, "�� �������");

    txDeleteDC (quest_buf.pic_answer1);
    txDeleteDC (quest_buf.pic_answer2);
    txDeleteDC (quest_buf.pic_answer3);

txTextCursor (false);
return 0;
}
