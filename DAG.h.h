#ifndef DAG_H
#define DAG_H

#include <iostream>
#include <fstream>

void readFile();

int getGraphSize(std::string fileName);

void topSort();

bool checkFinish(int arr[],int arr_size);

int checkZero(int arr[],int arr_size);

#endif // DAG_H
