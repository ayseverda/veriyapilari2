/**
* @file yigin.cpp
* @description yigin kodlari
* @course 2/A
* @assignment 2.ödev
* @date 24 ARALIK 2023
* @author Ayşe Verda Gülcemal ayseeverda@gmail.com
*/
#include "Yigin.hpp"
#include<exception>
#include<iostream>
#include <iomanip>
using namespace std;

Yigin::Yigin()
{
    tepe=0;
}
void Yigin::ekle(int veri)
{
    Dugum* yeni = new Dugum(veri);
    if(tepe!=0)
        yeni->sonraki=tepe;
    tepe= yeni;
}
void Yigin::cikar()
{
    if(tepe!=0)
    {
        Dugum* silinecek = tepe;
        tepe=tepe->sonraki;
        delete silinecek;
    }
    
}

int Yigin::getir()
{
    if(tepe!=0)
        return tepe->veri;
    throw std::out_of_range("Yigin::Getir(): Yigin Bos");
}