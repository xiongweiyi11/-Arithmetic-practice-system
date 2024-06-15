#include <iostream>
#include <string>
#include <stack>
#include <fstream>
#include <algorithm>
#include <windows.h>
#include <cctype>
#include <cmath>
#include <ctime>

#include <random>
//#pragma comment(lib, "winmm.lib")
using namespace std;

int level(char a);

double cal(double a, double b, char opt);

void s_tack(stack<double>& a, stack<char>& b);

int num_detect(string ntwo);

int test(int x, int& num);

int test1(int x, int& num, int& s);

void exchange(int& a, int& b);

void f1(int& b, int& c, int& d);

const int N = 100;

int getrand(int maxn) {
    static random_device rd;
    return rd() % maxn + 1;
}

int main() {
    system("color 0A");
    //PlaySound(TEXT(".\\��Ӱսʿ.wav"), NULL, SND_ASYNC | SND_LOOP);
    cout << "��ӭ����Сѧ������ѵ��ϵͳ" << endl;
    cout << "1.��ϰģʽ" << endl;
    cout << "2.��ʱģʽ��1���ӣ�" << endl;
    cout << "3.�Զ���ģʽ" << endl;
    cout << "4.���Ȿ" << endl;
    cout << "5.�˳�" << endl;
    string choice;
    int flag0 = 1;
    while (true) {
        while (true) {
            cin >> choice;
            if (choice != "1" && choice != "2" && choice != "3" && choice != "4" && choice != "5") {
                cout << "�������������룡" << endl;
            }
            else break;
        }
        ofstream fout1("ct.txt", ios_base::app);
        ifstream fin1("ct.txt");
        ofstream fout2("da.txt", ios_base::app);
        ifstream fin2("da.txt");
        string ct[100] = { "0" };
        double da[100] = { 0 };
        int l = 0;
        int m = 0;
        while (fin1 >> ct[l]) {
            l++;
            m++;
        }
        l = 0;
        while (fin2 >> da[l]) {
            l++;
        }
       // PlaySound(NULL, NULL, SND_FILENAME);
        if (choice == "1") {
            system("cls");
            int num1 = 0;
            int num2 = 0;
            string a;
            flag0 = 0;
            cout << "��ѡ����ϰ���ͣ�" << endl;
            cout << "1.�ӷ�" << endl;
            cout << "2.����" << endl;
            cout << "3.�˷�" << endl;
            cout << "4.����" << endl;
            cout << "5.�������" << endl;
            cout << "6.������һ��" << endl;
            while (true) {
                cin >> a;
                if (a != "1" && a != "2" && a != "3" && a != "4" && a != "5" && a != "6") {
                    cout << "�������ݴ�������������" << endl;
                    cin.clear();    //�����������������־λ������Ӱ���´�����
                    cin.sync(); //���������������
                }
                else
                    break;
            }
            system("cls");
            if (a != "6") {
                cout << "������Ҫ��������" << endl;
                while (true) {
                    cin >> num2;
                    if (num2 > 0) {
                        break;
                    }
                    else {
                        cout << "�������ݴ�������������" << endl;
                        cin.clear();    //�����������������־λ������Ӱ���´�����
                        cin.sync(); //���������������
                    }
                }
                system("cls");         //���������λ�ô�ͷ��ʼ
                for (int i = 0; i < num2; ++i) {
                    cout << "�ܹ�" << num2 << "���⣬" << "���ǵ�" << i + 1 << "��" << endl;
                    int b, c, d;
                    b = getrand(N);
                    c = getrand(N);
                    d = getrand(N);

                    if (a == "1") {
                        cout << b << "+" << c << "=" << endl;
                        flag0 = test(b + c, num1);
                        if (!flag0) {
                            fout1 << b << "+" << c << "=" << endl;
                            fout2 << b + c << endl;
                        }
                    }
                    if (a == "2") {
                        if (b < c) exchange(b, c);
                        cout << b << "-" << c << "=" << endl;
                        flag0 = test(b - c, num1);
                        if (!flag0) {
                            fout1 << b << "-" << c << "=" << endl;
                            fout2 << b - c << endl;
                        }
                    }
                    if (a == "3") {
                        while (b * c > 200 && b != 1 && c != 1) {
                            b = getrand(N);
                            c = getrand(N);
                        }
                        cout << b << "*" << c << "=" << endl;
                        flag0 = test(b * c, num1);
                        if (!flag0) {
                            fout1 << b << "*" << c << "=" << endl;
                            fout2 << b * c << endl;
                        }
                    }
                    if (a == "4") {
                        if (b < c) exchange(b, c);
                        if (c == 0) c++;
                        while (b % c != 0 && b != 1 && c != 1) {
                            b = getrand(N);
                            c = getrand(N);
                            if (b < c) exchange(b, c);
                            if (c == 0) c++;
                        }
                        cout << b << "/" << c << "=" << endl;
                        flag0 = test(b / c, num1);
                        if (!flag0) {
                            fout1 << b << "/" << c << "=" << endl;
                            fout2 << b / c << endl;
                        }
                    }

                    if (a == "5") {
                        int f = getrand(16);
                        int g = getrand(3);
                        if (g == 1) {
                            switch (f) {
                            case 1:
                                cout << b << "+" << c << "+" << d << "=" << b + c + d << endl;
                                flag0 = test(b + c + d, num1);
                                if (!flag0) {
                                    fout1 << b << "+" << c << "+" << d << "=" << b + c + d << endl;
                                    fout2 << b + c + d << endl;
                                }
                                break;
                            case 2:
                                while (b + c - d < 0) {
                                    f1(b, c, d);
                                }
                                cout << b << "+" << c << "-" << d << "=" << endl;
                                flag0 = test(b + c - d, num1);
                                if (!flag0) {
                                    fout1 << b << "+" << c << "-" << d << "=" << endl;
                                    fout2 << b + c - d << endl;
                                }
                                break;
                            case 3:
                                while (b + c * d > 200) {
                                    f1(b, c, d);
                                }
                                cout << b << "+" << c << "*" << d << "=" << endl;
                                flag0 = test(b + c * d, num1);
                                if (!flag0) {
                                    fout1 << b << "+" << c << "*" << d << "=" << endl;
                                    fout2 << b + c * d << endl;
                                }
                                break;
                            case 4:
                                if (c < d) exchange(c, d);
                                if (d == 0) d++;
                                while (c % d != 0) {
                                    f1(b, c, d);
                                    if (c < d) exchange(c, d);
                                    if (d == 0) d++;
                                }
                                cout << b << "+" << c << "/" << d << "=" << endl;
                                flag0 = test(b + c / d, num1);
                                if (!flag0) {
                                    fout1 << b << "+" << c << "/" << d << "=" << endl;
                                    fout2 << b + c / d << endl;
                                }
                            case 5:
                                while (b - c + d < 0) {
                                    f1(b, c, d);
                                }
                                cout << b << "-" << c << "+" << d << "=" << endl;
                                flag0 = test(b - c + d, num1);
                                if (!flag0) {
                                    fout1 << b << "-" << c << "+" << d << "=" << endl;
                                    fout2 << b - c + d << endl;
                                }
                                break;
                            case 6:
                                while (b - c - d < 0) {
                                    f1(b, c, d);
                                }
                                cout << b << "-" << c << "-" << d << "=" << endl;
                                flag0 = test(b - c - d, num1);
                                if (!flag0) {
                                    fout1 << b << "-" << c << "-" << d << "=" << endl;
                                    fout2 << b - c - d << endl;
                                }
                                break;
                            case 7:
                                while (b - c * d < 0 || b - c * d > 200) {
                                    f1(b, c, d);
                                }
                                cout << b << "-" << c << "*" << d << "=" << endl;
                                flag0 = test(b - c * d, num1);
                                if (!flag0) {
                                    fout1 << b << "-" << c << "*" << d << "=" << endl;
                                    fout2 << b - c * d << endl;
                                }
                                break;
                            case 8:
                                if (c < d) exchange(c, d);
                                if (d == 0) d++;
                                while (c % d != 0) {
                                    f1(b, c, d);
                                    if (c < d) exchange(c, d);
                                    if (d == 0) d++;
                                }
                                while (b - c % d < 0) {
                                    b = getrand(N);
                                }
                                cout << b << "-" << c << "/" << d << "=" << endl;
                                flag0 = test(b - c / d, num1);
                                if (!flag0) {
                                    fout1 << b << "-" << c << "/" << d << "=" << endl;
                                    fout2 << b - c / d << endl;
                                }
                                break;
                            case 9:
                                while (b * c + d) {
                                    f1(b, c, d);
                                }
                                cout << b << "*" << c << "+" << d << "=" << endl;
                                flag0 = test(b * c + d, num1);
                                if (!flag0) {
                                    fout1 << b << "*" << c << "+" << d << "=" << endl;
                                    fout2 << b * c + d << endl;
                                }
                                break;
                            case 10:
                                while (b * c - d < 0 || b * c - d > 200) {
                                    f1(b, c, d);
                                }
                                cout << b << "*" << c << "-" << d << "=" << endl;
                                flag0 = test(b * c - d, num1);
                                if (!flag0) {
                                    fout1 << b << "*" << c << "-" << d << "=" << endl;
                                    fout2 << b * c - d << endl;
                                }
                                break;
                            case 11:
                                while (b * c * d > 200) {
                                    f1(b, c, d);
                                }
                                cout << b << "*" << c << "*" << d << "=" << endl;
                                flag0 = test(b * c * d, num1);
                                if (!flag0) {
                                    fout1 << b << "*" << c << "*" << d << "=" << endl;
                                    fout2 << b * c * d << endl;
                                }
                                break;
                            case 12:
                                if (c < d) exchange(c, d);
                                if (d == 0) d++;
                                while (c % d != 0) {
                                    f1(b, c, d);
                                    if (c < d) exchange(c, d);
                                    if (d == 0) d++;
                                }
                                while (b * c / d > 200) {
                                    b = getrand(N);
                                }
                                cout << b << "*" << c << "/" << d << "=" << endl;
                                flag0 = test(b * c / d, num1);
                                if (!flag0) {
                                    fout1 << b << "*" << c << "/" << d << "=" << endl;
                                    fout2 << b * c / d << endl;
                                }
                                break;
                            case 13:
                                if (b < c) exchange(b, c);
                                if (c == 0) c++;
                                while (b % c != 0) {
                                    f1(b, c, d);
                                    if (b < c) exchange(b, c);
                                    if (c == 0) c++;
                                }
                                cout << b << "/" << c << "+" << d << "=" << endl;
                                flag0 = test(b / c + d, num1);
                                if (!flag0) {
                                    fout1 << b << "/" << c << "+" << d << "=" << endl;
                                    fout2 << b / c + d << endl;
                                }
                                break;
                            case 14:
                                if (b < c) exchange(b, c);
                                if (c == 0) c++;
                                while (b % c != 0) {
                                    f1(b, c, d);
                                    if (b < c) exchange(b, c);
                                    if (c == 0) c++;
                                }
                                while (b / c - d < 0) {
                                    d = getrand(N);
                                }
                                cout << b << "/" << c << "-" << d << "=" << endl;
                                flag0 = test(b / c - d, num1);
                                if (!flag0) {
                                    fout1 << b << "/" << c << "-" << d << "=" << endl;
                                    fout2 << b / c - d << endl;
                                }
                                break;
                            case 15:
                                if (b < c) exchange(b, c);
                                if (c == 0) c++;
                                while (b % c != 0) {
                                    f1(b, c, d);
                                    if (b < c) exchange(b, c);
                                    if (c == 0) c++;
                                }
                                while (b / c * d > 200) {
                                    d = getrand(N);
                                }
                                cout << b << "/" << c << "*" << d << "=" << endl;
                                flag0 = test(b / c * d, num1);
                                if (!flag0) {
                                    fout1 << b << "/" << c << "*" << d << "=" << endl;
                                    fout2 << b / c * d << endl;
                                }
                                break;
                            case 16:
                                if (b < c) exchange(b, c);
                                if (c == 0) c++;
                                while (b % c != 0) {
                                    f1(b, c, d);
                                    if (b < c) exchange(b, c);
                                    if (c == 0) c++;
                                }
                                int t = b / c;
                                if (d == 0) d++;
                                while (t % d != 0) {
                                    d = getrand(N);
                                    if (d == 0) d++;
                                }
                                cout << b << "/" << c << "/" << d << "=" << endl;
                                flag0 = test(b / c / d, num1);
                                if (!flag0) {
                                    fout1 << b << "/" << c << "/" << d << "=" << endl;
                                    fout2 << b / c / d << endl;
                                }
                                break;
                            }
                        }
                        if (g == 2) {
                            int h = getrand(4);
                            int i = getrand(4);
                            int j;
                            switch (h) {
                            case 1:
                                j = b + c;
                                break;
                            case 2:
                                if (b < c) exchange(b, c);
                                j = b - c;
                                break;
                            case 3:
                                while (b * c > 200) {
                                    b = getrand(N);
                                    c = getrand(N);
                                }
                                j = b * c;
                                break;
                            case 4:
                                if (b < c) exchange(b, c);
                                if (c == 0) c++;
                                while (b % c != 0) {
                                    b = getrand(N);
                                    c = getrand(N);
                                    if (b < c) exchange(b, c);
                                    if (c == 0) c++;
                                }
                                j = b / c;
                                break;
                            }
                            switch (i) {
                            case 1:
                                cout << "(" << b << (h == 1 ? "+" : h == 2 ? "-" : h == 3 ? "*" : "/") << c << ")"
                                    << (i == 1 ? "+" : i == 2 ? "-" : i == 3 ? "*" : "/") << d << "=" << endl;
                                flag0 = test(j + d, num1);
                                if (!flag0) {
                                    fout1 << "(" << b << (h == 1 ? "+" : h == 2 ? "-" : h == 3 ? "*" : "/") << c
                                        << ")" << (i == 1 ? "+" : i == 2 ? "-" : i == 3 ? "*" : "/") << d << "="
                                        << endl;
                                    fout2 << j + d << endl;
                                }

                                break;
                            case 2:
                                while (j - d < 0) {
                                    d = getrand(N);
                                }
                                cout << "(" << b << (h == 1 ? "+" : h == 2 ? "-" : h == 3 ? "*" : "/") << c << ")"
                                    << (i == 1 ? "+" : i == 2 ? "-" : i == 3 ? "*" : "/") << d << "=" << endl;
                                flag0 = test(j - d, num1);
                                if (!flag0) {
                                    fout1 << "(" << b << (h == 1 ? "+" : h == 2 ? "-" : h == 3 ? "*" : "/") << c
                                        << ")" << (i == 1 ? "+" : i == 2 ? "-" : i == 3 ? "*" : "/") << d << "="
                                        << endl;
                                    fout2 << j - d << endl;
                                }
                                break;
                            case 3:
                                while (j * d > 200) {
                                    d = getrand(N);
                                }
                                cout << "(" << b << (h == 1 ? "+" : h == 2 ? "-" : h == 3 ? "*" : "/") << c << ")"
                                    << (i == 1 ? "+" : i == 2 ? "-" : i == 3 ? "*" : "/") << d << "=" << endl;
                                flag0 = test(j * d, num1);
                                if (!flag0) {
                                    fout1 << "(" << b << (h == 1 ? "+" : h == 2 ? "-" : h == 3 ? "*" : "/") << c
                                        << ")" << (i == 1 ? "+" : i == 2 ? "-" : i == 3 ? "*" : "/") << d << "="
                                        << endl;
                                    fout2 << j * d << endl;
                                }
                                break;
                            case 4:
                                if (d == 0) d++;
                                while (j % d != 0) {
                                    d = getrand(N);
                                    if (d == 0) d++;
                                }
                                cout << "(" << b << (h == 1 ? "+" : h == 2 ? "-" : h == 3 ? "*" : "/") << c << ")"
                                    << (i == 1 ? "+" : i == 2 ? "-" : i == 3 ? "*" : "/") << d << "=" << endl;
                                flag0 = test(j / d, num1);
                                if (!flag0) {
                                    fout1 << "(" << b << (h == 1 ? "+" : h == 2 ? "-" : h == 3 ? "*" : "/") << c
                                        << ")" << (i == 1 ? "+" : i == 2 ? "-" : i == 3 ? "*" : "/") << d << "="
                                        << endl;
                                    fout2 << j / d << endl;
                                }
                                break;
                            }
                        }
                        if (g == 3) {
                            int h = getrand(4);
                            int i = getrand(4);
                            int j;
                            switch (h) {
                            case 1:
                                j = b + c;
                                break;
                            case 2:
                                if (b < c) exchange(b, c);
                                j = b - c;
                                break;
                            case 3:
                                while (b * c > 200) {
                                    b = getrand(N);
                                    c = getrand(N);
                                }
                                j = b * c;
                                break;
                            case 4:
                                if (b < c) exchange(b, c);
                                if (c == 0) c++;
                                while (b % c != 0) {
                                    b = getrand(N);
                                    c = getrand(N);
                                    if (b < c) exchange(b, c);
                                    if (c == 0) c++;
                                }
                                j = b / c;
                                break;
                            }
                            while (true) {
                                if (j > 100 && i == 2) {
                                    i = getrand(4);
                                    continue;
                                }
                                else if (j > 100 && i == 4) {
                                    i = getrand(4);
                                    continue;
                                }
                                else if (j == 0 && i == 4) {
                                    i = getrand(4);
                                    continue;
                                }
                                else
                                    break;
                            }
                            switch (i) {
                            case 1:
                                cout << d << (i == 1 ? "+" : i == 2 ? "-" : i == 3 ? "*" : "/") << "(" << b
                                    << (h == 1 ? "+" : h == 2 ? "-" : h == 3 ? "*" : "/") << c << ")" << " ="
                                    << endl;
                                flag0 = test(d + j, num1);
                                if (!flag0) {
                                    fout1 << d << (i == 1 ? "+" : i == 2 ? "-" : i == 3 ? "*" : "/") << "(" << b
                                        << (h == 1 ? "+" : h == 2 ? "-" : h == 3 ? "*" : "/") << c << ")" << "="
                                        << endl;
                                    fout2 << d + j << endl;
                                }
                                break;
                            case 2:
                                while (d - j < 0) {
                                    d = getrand(N);
                                }
                                cout << d << (i == 1 ? "+" : i == 2 ? "-" : i == 3 ? "*" : "/") << "(" << b
                                    << (h == 1 ? "+" : h == 2 ? "-" : h == 3 ? "*" : "/") << c << ")" << "="
                                    << endl;
                                flag0 = test(d - j, num1);
                                if (!flag0) {
                                    fout1 << d << (i == 1 ? "+" : i == 2 ? "-" : i == 3 ? "*" : "/") << "(" << b
                                        << (h == 1 ? "+" : h == 2 ? "-" : h == 3 ? "*" : "/") << c << ")" << "="
                                        << endl;
                                    fout2 << d - j << endl;
                                }
                                break;
                            case 3:
                                while (d * j > 200) {
                                    d = getrand(N);
                                }
                                cout << d << (i == 1 ? "+" : i == 2 ? "-" : i == 3 ? "*" : "/") << "(" << b
                                    << (h == 1 ? "+" : h == 2 ? "-" : h == 3 ? "*" : "/") << c << ")" << "="
                                    << endl;
                                flag0 = test(d * j, num1);
                                if (!flag0) {
                                    fout1 << d << (i == 1 ? "+" : i == 2 ? "-" : i == 3 ? "*" : "/") << "(" << b
                                        << (h == 1 ? "+" : h == 2 ? "-" : h == 3 ? "*" : "/") << c << ")" << "="
                                        << endl;
                                    fout2 << d * j << endl;
                                }
                                break;
                            case 4:
                                while (d % j != 0 || d < j) {
                                    d = getrand(N);
                                }
                                cout << d << (i == 1 ? "+" : i == 2 ? "-" : i == 3 ? "*" : "/") << "(" << b
                                    << (h == 1 ? "+" : h == 2 ? "-" : h == 3 ? "*" : "/") << c << ")" << "="
                                    << endl;
                                flag0 = test(d / j, num1);
                                if (!flag0) {
                                    fout1 << d << (i == 1 ? "+" : i == 2 ? "-" : i == 3 ? "*" : "/") << "(" << b
                                        << (h == 1 ? "+" : h == 2 ? "-" : h == 3 ? "*" : "/") << c << ")" << "="
                                        << endl;
                                    fout2 << d / j << endl;
                                }
                                break;
                            }
                        }
                    }
                }
                if (a != "6")
                    cout << "�ܹ�" << num2 << "����," << "������" << num1 << "���⣬" << "��ȷ��Ϊ"
                    << num1 * 100 / num2 << "%,";
                if (num1 * 100 / num2 >= 90) {
                    cout << "̫����" << endl;
                }
                else if (num1 * 100 / num2 >= 80) {
                    cout << "���" << endl;
                }
                else if (num1 * 100 / num2 >= 70) {
                    cout << "������" << endl;
                }
                else if (num1 * 100 / num2 >= 60) {
                    cout << "��������" << endl;
                }
                else {
                    cout << "û�����ϣ��ٽ�����" << endl;
                }
                system("pause");
                system("cls");
            }
          //  PlaySound(TEXT(".\\��Ӱսʿ.wav"), NULL, SND_ASYNC | SND_LOOP);
            cout << "��ӭ����Сѧ������ѵ��ϵͳ" << endl;
            cout << "1.��ϰģʽ" << endl;
            cout << "2.��ʱģʽ��1���ӣ�" << endl;
            cout << "3.�Զ���ģʽ" << endl;
            cout << "4.���Ȿ" << endl;
            cout << "5.�˳�" << endl;

        }
        else if (choice == "2") {
            flag0 = 1;
            int timeLimit = 60; // ���ô���ʱ������Ϊ60��
            system("cls");
            cout << "��ʼ���⣬����" << timeLimit << "������ɾ����ܶ����Ŀ" << endl;
            time_t startTime = time(nullptr);
            time_t endTime = startTime + timeLimit;
            int s = 0;
            while (time(nullptr) < endTime) {
                int b, c, opt;
                int num1 = 0;
                b = getrand(N);
                c = getrand(N);
                opt = getrand(4);
                if (opt == 1) {
                    cout << b << "+" << c << "=" << endl;
                    flag0 = test1(b + c, num1, s);
                    if (!flag0) {
                        fout1 << b << "+" << c << "=" << endl;
                        fout2 << b + c << endl;
                    }
                }
                if (opt == 2) {
                    if (b < c) exchange(b, c);
                    cout << b << "-" << c << "=" << endl;
                    flag0 = test1(b - c, num1, s);
                    if (!flag0) {
                        fout1 << b << "-" << c << "=" << endl;
                        fout2 << b - c << endl;
                    }
                }
                if (opt == 3) {
                    while (b * c > 200 && b != 1 && c != 1) {
                        b = getrand(N);
                        c = getrand(N);
                    }
                    cout << b << "*" << c << "=" << endl;
                    flag0 = test1(b * c, num1, s);
                    if (!flag0) {
                        fout1 << b << "*" << c << "=" << endl;
                        fout2 << b * c << endl;
                    }
                }
                if (opt == 0) {
                    if (b < c) exchange(b, c);
                    if (c == 0) c++;
                    while (b % c != 0 && b != 1 && c != 1) {
                        b = getrand(N);
                        c = getrand(N);
                        if (b < c) exchange(b, c);
                        if (c == 0) c++;
                    }
                    cout << b << "/" << c << "=" << endl;
                    flag0 = test1(b / c, num1, s);
                    if (!flag0) {
                        fout1 << b << "/" << c << "=" << endl;
                        fout2 << b / c << endl;
                    }
                }
            }
            //ʱ�������ֹͣ����
            cout << "ʱ�䵽���������" << endl;
            cout << "��һ�������" << s << "����" << endl;//��ֵ����
            system("pause");
            system("cls");
           // PlaySound(TEXT(".\\��Ӱսʿ.wav"), NULL, SND_ASYNC | SND_LOOP);
            cout << "��ӭ����Сѧ������ѵ��ϵͳ" << endl;
            cout << "1.��ϰģʽ" << endl;
            cout << "2.��ʱģʽ��1���ӣ�" << endl;
            cout << "3.�Զ���ģʽ" << endl;
            cout << "4.���Ȿ" << endl;
            cout << "5.�˳�" << endl;
        }
        else if (choice == "3") {
            int n;
            string ntwo;
            string infix;
            stack<double> num_stack;
            stack<char> str_stack;
            stack<char> detect;
            bool key = true;
            system("cls");
            cout << "��������ϰ����" << endl;
            cin >> ntwo;
            cout << "��������Ŀ���������������������У���" << endl;
            n = num_detect(ntwo);
            auto* data = new double[n];
            auto* in_fix = new string[n];
            int* ertance = new int[n];
            fill_n(ertance, n, 0);
            for (int k = 0; k < n; ++k) {
                cin >> infix;
                while (true) {
                    int flag = 0;
                    for (string::size_type t = 0; t < infix.length(); ++t) {
                        detect.push(infix[t]);
                        if (t == 0) {
                            if (!isdigit(detect.top()) && detect.top() != '(')
                                flag = 1;
                        }
                        if (infix[t] == '(' && infix[t + 1] == ')')
                            flag = 1;
                        if (t != 0) {
                            int al_detect = 0;
                            if (infix[t - 1] == '+' || infix[t - 1] == '-' || infix[t - 1] == '*' ||
                                infix[t - 1] == '/')
                                ++al_detect;
                            if (infix[t] == '+' || infix[t] == '-' || infix[t] == '*' || infix[t] == '/')
                                ++al_detect;
                            if (al_detect == 2)
                                flag = 1;
                        }
                        if (!isdigit(detect.top()) && detect.top() != '+' && detect.top() != '-' &&
                            detect.top() != '*' && detect.top() != '/' && detect.top() != '(' && detect.top() != ')')
                            flag = 1;
                    }
                    if (flag == 1) {
                        cout << "���ʽ����!��������!" << endl;
                        cin >> infix;
                    }
                    else break;
                }
                in_fix[k] = infix;
                for (char i : infix) {
                    if (i == '(') {
                        key = true;
                        str_stack.push(i);
                    }
                    else if (i == ')') {
                        key = true;
                        while (str_stack.top() != '(')
                            s_tack(num_stack, str_stack);
                        str_stack.pop();
                    }
                    else if (i == '+' || i == '-' || i == '*' || i == '/') {
                        key = true;
                        if (!str_stack.empty() && str_stack.top() != '(' && (level(i) < level(str_stack.top())))
                            s_tack(num_stack, str_stack);
                        str_stack.push(i);
                    }
                    else {
                        double temp = i - '0';
                        if (key) {
                            num_stack.push(temp);
                            key = false;
                        }
                        else {
                            double temp2 = num_stack.top();
                            num_stack.pop();
                            temp2 = 10 * temp2 + temp;
                            num_stack.push(temp2);
                        }
                    }
                }
                while (!str_stack.empty())
                    s_tack(num_stack, str_stack);
                data[k] = num_stack.top();
                num_stack.pop();
                key = true;
            }
            double answer = 0;
            double aver = 100.0 / n;
            int sum = 0;
            cout << "��������Ĵ�(�漰�������ĵ��뱣��6λС��)" << endl;
            for (int m = 0; m < n; ++m) {
                string str_answer;
                bool key_2 = false;
                cin >> str_answer;
                for (char i : str_answer) {
                    if (i == '.')
                        key_2 = true;
                }
                if (key_2 == 0) {
                    answer = num_detect(str_answer);
                    if (answer != data[m])
                        ertance[m] = 1;
                    else
                        ++sum;
                }
                else {
                    bool key_3 = true;
                    string momo;
                    int sum_tem = 0;
                    int flag_tem = 0;
                    momo = to_string(data[m]);
                    for (string::size_type i = 0; i < str_answer.length(); ++i) {
                        ++sum_tem;
                        if (str_answer[i] == '.')
                            flag_tem = i;
                    }
                    if ((sum_tem - flag_tem - 1) == 6) {
                        for (string::size_type i = 0; i < str_answer.length(); ++i) {
                            if (str_answer[i] != momo[i])
                                key_3 = false;
                        }
                    }
                    else key_3 = false;
                    if (key_3)
                        ++sum;
                    else
                        ertance[m] = 1;
                }
            }
            for (int m = 0; m < n; ++m) {
                if (ertance[m]) {
                    fout1 << in_fix[m] <<"="<< endl;
                    fout2 << data[m] << endl;
                }
            }
            cout << "��ȷ����:" << endl;
            for (int i = 0; i < n; ++i)
                cout << data[i] << "  ";
            double score = aver * sum;
            cout << endl;
            cout << "��ķ�����" << " " << score << endl;
            if (score > 80.0) {
                cout << "̫����" << endl << endl;
                Sleep(1000);
            }
            else if (score <= 80.0) {
                cout << "�ٽ�����" << endl << endl;
                Sleep(1000);
            }
            delete[] data;
            data = nullptr;
            delete[] in_fix;
            in_fix = nullptr;
            delete[] ertance;
            ertance = nullptr;
            system("pause");
            system("cls");
          //  PlaySound(TEXT(".\\��Ӱսʿ.wav"), NULL, SND_ASYNC | SND_LOOP);
            cout << "��ӭ����Сѧ������ѵ��ϵͳ" << endl;
            cout << "1.��ϰģʽ" << endl;
            cout << "2.��ʱģʽ��1���ӣ�" << endl;
            cout << "3.�Զ���ģʽ" << endl;
            cout << "4.���Ȿ" << endl;
            cout << "5.�˳�" << endl;
        }
        else if (choice == "4") {
            system("cls");
            cout << "ѡ�\n1.�鿴���Ȿ\n2.��������\n";
            string choice1;
            do {
                cin >> choice1;
                if (choice1 != "1" && choice1 != "2") {
                    cout << "�������������룡" << endl;
                }
                else
                    break;
            } while (true);
            if (choice1 == "1") {
                system("cls");
                cout << "������Ĵ��Ȿ" << endl;
                for (l = 0; l < m; ++l) {
                    cout << ct[l] << da[l] << endl;
                }
                system("pause");
                system("cls");
             //   PlaySound(TEXT(".\\��Ӱսʿ.wav"), NULL, SND_ASYNC | SND_LOOP);
                cout << "��ӭ����Сѧ������ѵ��ϵͳ" << endl;
                cout << "1.��ϰģʽ" << endl;
                cout << "2.��ʱģʽ��1���ӣ�" << endl;
                cout << "3.�Զ���ģʽ" << endl;
                cout << "4.���Ȿ" << endl;
                cout << "5.�˳�" << endl;
            }
            else {
                ofstream fout3("ct.txt", ios::out);
                ofstream fout4("da.txt", ios::out);
                double answer6;
                system("cls");
                for (l = 0; l < m; ++l) {
                    cout << ct[l] << endl;
                    cout << "��������Ĵ�(����������5λС��)" << endl;
                    cin >> answer6;
                    if (answer6 == da[l]) {
                        cout << "����ȷ" << endl;

                    }
                    else {
                        cout << "����𰸴�����ȷ��Ϊ" << da[l] << endl;

                        fout1 << ct[l] << endl;
                        fout2 << da[l] << endl;
                    }
                    system("pause");
                    system("cls");
                }
                system("pause");
                system("cls");
                //PlaySound(TEXT(".\\��Ӱսʿ.wav"), NULL, SND_ASYNC | SND_LOOP);
                cout << "��ӭ����Сѧ������ѵ��ϵͳ" << endl;
                cout << "1.��ϰģʽ" << endl;
                cout << "2.��ʱģʽ��1���ӣ�" << endl;
                cout << "3.�Զ���ģʽ" << endl;
                cout << "4.���Ȿ" << endl;
                cout << "5.�˳�" << endl;
            }
        }
        else if (choice == "5") {
            return 0;
        }
    }
}

int level(char a) {
    int lev = 0;
    if (a == '+' || a == '-')
        lev = 1;
    else if (a == '*' || a == '/')
        lev = 2;
    return lev;
}

double cal(double a, double b, char opt) {
    double result;
    switch (opt) {
    case '+':
        result = a + b;
        break;
    case '-':
        result = a - b;
        break;
    case '*':
        result = a * b;
        break;
    case '/':
        result = a / b;
        break;
    }
    return result;
}

void s_tack(stack<double>& a, stack<char>& b) {
    double num_stack2 = a.top();
    a.pop();
    double num_stack1 = a.top();
    a.pop();
    char str_stack = b.top();
    b.pop();
    double temp = cal(num_stack1, num_stack2, str_stack);
    a.push(temp);
}

int num_detect(string ntwo) {
    int n;
    stack<char> detect_small;
    while (true) {
        int flag_a = 0;
        for (char j : ntwo) {
            detect_small.push(j);
            if (!isdigit(detect_small.top()))
                flag_a = 1;
        }
        if (flag_a == 1) {
            cout << "�����������������" << endl;
            cin >> ntwo;
        }
        else break;
    }
    for (string::size_type j = 0; j < ntwo.length(); ++j) {
        char temp_n = detect_small.top();
        detect_small.pop();
        if (j == 0)
            n = temp_n - '0';
        else {
            int ci = 1;
            for (int i = j; i > 0; --i)
                ci = 10 * ci;
            n = ci * (temp_n - '0') + n;
        }
    }
    return n;
}

void f1(int& b, int& c, int& d) {
    b = getrand(N);
    c = getrand(N);
    d = getrand(N);
}

int test(int x, int& num) {
    int answer;
    int flag_test = 1;
    cout << "��������Ĵ�" << endl;
    cin >> answer;
    if (answer == x) {
        cout << "����ȷ" << endl;
        flag_test = 1;
        num++;
        system("pause");
        system("cls");
    }
    else {
        cout << "����𰸴�����ȷ��Ϊ" << x << endl;
        flag_test = 0;
        system("pause");
        system("cls");
    }
    cin.clear();
    cin.sync();
    return flag_test;
}

int test1(int x, int& num, int& s) {
    int answer;
    int flag_t1 = 1;
    cout << "��������Ĵ�" << endl;
    cin >> answer;
    if (answer == x) {
        cout << "����ȷ" << endl;
        flag_t1 = 1;
        num++;
        s++;
        system("pause");
        system("cls");
    }
    else {
        cout << "����𰸴�����ȷ��Ϊ" << x << endl;
        flag_t1 = 0;
        system("pause");
        system("cls");
    }
    cin.clear();
    cin.sync();
    return flag_t1;
}

void exchange(int& a, int& b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}
