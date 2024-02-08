/**
* @file main.cpp
* @description main kodları
* @course 2/A
* @assignment 2.ödev
* @date 24 ARALIK 2023
* @author Ayşe Verda Gülcemal ayseeverda@gmail.com
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include "avltree.hpp"
#include "yigin.hpp"
using namespace std;

int main() {
    ifstream inputFile("veri.txt");
    if (!inputFile) {
        cerr << "Dosya acilamadi" << endl;
        return 1;
    }

    string line;
    while (getline(inputFile, line)) {
        AVLTree avlTree; // Reset AVL tree for each line

        istringstream iss(line);
        int num;
        while (iss >> num) {
            avlTree.root = avlTree.insert(avlTree.root, num);
        }

        int sum = avlTree.postorderSumOfNonLeafNodes(avlTree.root);
		 avlTree.postorderLeafNodesToStack(avlTree.root);
        avlTree.processLeafStack();

        int asciiSum = sum % (90 - 65 + 1) + 65;
        cout << endl <<"bu agacin ascii degeri : "<<static_cast<char>(asciiSum)<<endl;
		cout<<"------------------------------------------------------------------"<<endl;
    }
	

    inputFile.close();

}