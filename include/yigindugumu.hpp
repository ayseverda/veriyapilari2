/**
* @file yigindugumu.hpp
* @description yigindakiler bagladik dugumle
* @course 2/A
* @assignment 2.ödev
* @date 24 ARALIK 2023
* @author Ayşe Verda Gülcemal ayseeverda@gmail.com
*/
#ifndef yigidugumu_hpp
#define yigindugumu_hpp


class Dugum
{
public:
    Dugum(int veri);
    int veri;
    Dugum* sonraki;
};
#endif