#ifndef STACKER_H
#define STACKER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class stacker {
 private:
  string magic_number; //"P3"
  string fileName;
  string inputFileName;
  string output;
  int width; //width of image
  int height; //height of image
  int max_color; //255
  int numberOfImages;
  struct pixel{
    int red;
    int green;
    int blue;
  };
  
  vector<pixel> pixels;
  
  vector<pixel> temp;

 public:
  stacker();
  void loadFile(string file, int numImages); 
  void saveToDisk();
  void check();
  void average();
  void setNumImages(int num);
};

#endif //stacker.h
