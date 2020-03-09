#include <windows.h>
#include <string>
#include <atlstr.h>
#include <sstream>
#include <iostream>
#include <conio.h>
#include <tchar.h>

using tstring = std::basic_string<TCHAR>;

int gra(int x, int y, int z){               // funkcja odpowiada¹ca za rekurencjê, jest tak¿e g³ównym kodem gry
  char zz[100];                                //zamiana int na string
  sprintf_s(zz, "%d", z);                      //
  tstring str1 = _T("Czy liczba jest wiêksza od ");   // ³¹czenie stringów w pojedyncz¹ wiadomoœæ
  tstring str2 = _T(zz);                              //
  tstring str3 = _T("?");                             //
  tstring message = str1 + str2 + str3;               //

  int iRetKey = MessageBox(0, message.c_str(), "Aplikacja", MB_YESNO);
  
  if ((z != x) || (z != y)){          //sprawdzanie czy doszliœmy do koñca przeszukiwania binarnego, jeœli prawda szukamy dalej
   //while(x < y){
    if (iRetKey == IDYES){
      x = z + 1;
      return gra(x, y, z = (x + y) / 2);
    }
    else{
      y = z;
      return gra(x, y, z = (x + y) / 2);
    }
  }
  //else{                       //osi¹gniêto koniec(wynik) wyszukiwania binarnego u¿ytkownik porównuje swoj¹ liczbê z otrzyman¹
    tstring str4 = _T("Czy Twoja liczba to ");
    tstring str5 = _T(zz);
    tstring str6 = _T("?");

    tstring message2 = str4 + str5 + str6;

    int iRetKey1 = MessageBox(0, message2.c_str(), "Aplikacja", MB_YESNO);
    if (iRetKey1 == IDYES){
      MessageBox(0, "Hurra zgad³em", "Aplikacja", MB_ICONINFORMATION);
    }
    else{
      MessageBox(0, "Oj coœ posz³o nie tak", "Aplikacja", MB_OK | MB_ICONINFORMATION);
    }
  //}
}
int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow){
  int x = 1;              //   inicjalizacja zmiennych
  int y = 40;
  int z = 0;
  int iRetKey = MessageBox(0, "Wybierz liczbê z zakresu 1-40", "Aplikacja", MB_ICONINFORMATION);
  z = (x + y) / 2;
  gra(x, y, z);           //wywo³anie funkcji zawieraj¹cej g³ówny kod gry
  return 0;
}




/*kod pozwalaj¹cy na podobne rozwi¹zania jednak nie wykorzystany w tym poleceniu*/

//CString zz;
  //zz.Format(_T("%d"), z);
  //char zz[] = { z,"" };
  //tstring zz = z.toTstring();
  //tstring ^ zz = Convert::ToString(z);
/*
  //char zz[] = { z,"" };

  //LPCTSTR zz = z.c_int();
  LPCTSTR str1 = _T("Czy liczba jest wiêksza od");
  LPCTSTR str2 = _T(zz);
  LPCTSTR str3 = _T("?");
  LPTSTR message = new TCHAR[_tcslen(str1) + _tcslen(str2) + _tcslen(str3) + 1];
  _tcscpy(message, str1);
  _tcscat(message, str2);
  _tcscat(message, str3);*/
  //delete[] message;
/*LPCTSTR str4 = _T("Czy Twoja liczba to : ");
    LPCTSTR str5 = _T(zz);
    LPCTSTR str6 = _T("?");
    LPCTSTR message2 = new TCHAR[_tcslen(str1) + _tcslen(str2) + _tcslen(str3) ];*/