/**
* @file yigin.hpp
* @description yigin metotlari
* @course 2/A
* @assignment 2.ödev
* @date 24 ARALIK 2023
* @author Ayşe Verda Gülcemal ayseeverda@gmail.com
*/
#ifndef Yigin_hpp
#define Yigin_hpp
#include "yigindugumu.hpp"
#include<exception>
#include<iostream>
#include <iomanip>
using namespace std;

class Yigin
{
public:
    Yigin();
    void ekle(int veri);

    void cikar();
    
    friend ostream& operator<<(ostream& os,Yigin& yigin);
    int getir();
	
	
//private:
    Dugum* tepe;
};

#endif