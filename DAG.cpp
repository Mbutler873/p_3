#include "DAG.h"

int getGraphSize(std::string fileName)
{
  std::ifstream myFile;
  myFile.open(fileName);

  int i = 0;
  int maxSize = 0;
  while(myFile.good())
  {
    ++i;
    if(i == 1)
    {
      int num;
      myFile >> num;
      if(myFile.eof())
        break;
      if(num > maxSize)
        maxSize = num;
    }
    else if(i == 2)
    {
      int num;
      myFile >> num;
      if(num > maxSize)
        maxSize = num;
    }
    else if(i == 3)
    {
      float num;
      myFile >> num;
      i = 0;
    }
  }
  return maxSize;
}

void readFile()
{
  std::string fileName;
  std::cout << "Enter File Name: ";
  std::cin >> fileName;

  int maxSize = getGraphSize(fileName);

  float graph[maxSize][maxSize] = {0};
  for(int i = 0; i < maxSize; ++i)
  {
    for(int j = 0; j < maxSize; ++j)
    {
      graph[i][j] = 0;
    }
  }

  std::ifstream myFile;
  myFile.open(fileName);

  int i = 0;
  while(myFile.good())
  {
    ++i;
    int first;
    int second;
    float weight;
    if(i == 1)
    {
      myFile >> first;
      if(myFile.eof())
        break;
    }
    else if(i == 2)
    {
      myFile >> second;
    }
    else if(i == 3)
    {
      myFile >> weight;
      i = 0;
      graph[first - 1][second - 1] = weight;
    }
  }

  for(int i = 0; i < maxSize; ++i)
  {
    for(int j = 0; j < maxSize; ++j)
    {
      std::cout << "[" << graph[i][j] << "]";
    }
    std::cout << '\n';
  }
  return;
}

void topSort()
{
  std::string fileName;
  std::cout << "Enter File Name: ";
  std::cin >> fileName;

  int maxSize = getGraphSize(fileName);

  float graph[maxSize][maxSize] = {0};
  for(int i = 0; i < maxSize; ++i)
  {
    for(int j = 0; j < maxSize; ++j)
    {
      graph[i][j] = 0;
    }
  }
  int inDegree[maxSize] = {0};

  std::ifstream myFile;
  myFile.open(fileName);

  int i = 0;
  while(myFile.good())
  {
    ++i;
    int first;
    int second;
    float weight;
    if(i == 1)
    {
      myFile >> first;
      if(myFile.eof())
        break;
    }
    else if(i == 2)
    {
      myFile >> second;
    }
    else if(i == 3)
    {
      myFile >> weight;
      i = 0;
      graph[first - 1][second - 1] = weight;
      inDegree[second - 1]++;
    }
  }

  int sortList[maxSize] = {0};
  std::cout << '\n';
  int inputPlace = 0;
  while(!(checkFinish(inDegree, maxSize)))
  {
    int next = checkZero(inDegree, maxSize);
    sortList[inputPlace] = next + 1;
    inputPlace++;
    inDegree[next]--;

    for(int i = 0; i < maxSize; ++i)
    {
      if(graph[next][i] != 0)
      {
        inDegree[i]--;
      }
    }
  }

  for(int i = 0; i < maxSize; ++i)
  {
    if(sortList[i] != 0)
      std::cout << sortList[i] << " ";
  }
  std::cout << '\n';

  return;
}

bool checkFinish(int arr[],int arr_size)
{
  for(int i = 0; i < arr_size; ++i)
    if(arr[i] != -1)
      return false;

  return true;
}

int checkZero(int arr[],int arr_size)
{
  for(int i = 0; i < arr_size; ++i)
    if(arr[i] == 0)
      return i;
}
