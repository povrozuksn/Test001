#include "TXLib.h"
#include <iostream>
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

int main()
{

setlocale(LC_ALL, "Russian");

txCreateWindow (800, 600);

    int kol_question = 4;

    Forma quest_buf;

    Forma quest[kol_question];
    /*
    quest[0] = {"� ����� ������ ������ �������?", 2, txLoadImage("��������/���������.bmp"), "���������", txLoadImage("��������/������.bmp"), "������", txLoadImage("��������/������.bmp"), "������"};
    quest[1] = {"��������� ������� ������?", 3, txLoadImage("��������/�����.bmp"), "�����", txLoadImage("��������/�����.bmp"), "�����", txLoadImage("��������/����.bmp"), "����"};
    quest[2] = {"����� �������� ����� ������?", 3, txLoadImage("��������/������.bmp"), "������", txLoadImage("��������/�����.bmp"), "�����", txLoadImage("��������/��������.bmp"), "��������"};
    quest[3] = {"����� ����� ����� ������?", 3, txLoadImage("��������/��������.bmp"), "��������", txLoadImage("��������/���������.bmp"), "���������", txLoadImage("��������/����.bmp"), "����"};
    */
    int n_question = 1;
    int kol_right_answer = 0;
    char stroka[50];
    string str;

    ifstream file("�������.txt");

    while(file.good())
    {
        getline(file, str);

        int pos1 = str.find(",", 0);
        quest[0].text_question = str.substr(0, pos1-0);

        int pos2 = str.find(",", pos1+1);
        quest[0].right_answer = atoi((str.substr(pos1+1, pos2-(pos1+1))).c_str());

        int pos3 = str.find(",", pos2+1);
        quest[0].pic_answer1 = txLoadImage((str.substr(pos2+1, pos3-(pos2+1))).c_str());
        cout << quest[0].pic_answer1 << endl;

        int pos4 = str.find(",", pos3+1);
        quest[0].text_answer1 = str.substr(pos3+1, pos4-(pos3+1));

        int pos5 = str.find(",", pos4+1);
        quest[0].pic_answer2 = txLoadImage((str.substr(pos4+1, pos5-(pos4+1))).c_str());

        int pos6 = str.find(",", pos5+1);
        quest[0].text_answer2 = str.substr(pos5+1, pos6-(pos5+1));

        int pos7 = str.find(",", pos6+1);
        quest[0].pic_answer3 = txLoadImage((str.substr(pos6+1, pos7-(pos6+1))).c_str());

        int pos8 = str.find(",", pos7+1);
        quest[0].text_answer3 = str.substr(pos7+1, pos8-(pos7+1));

    }



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

    txDeleteDC (quest_buf.pic_answer1);
    txDeleteDC (quest_buf.pic_answer2);
    txDeleteDC (quest_buf.pic_answer3);

txTextCursor (false);
return 0;
}
