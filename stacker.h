/*Amie Newman and Charles Clayton
 *Last modified: 9/30/16
 *File: stacker.h
 *Desc: Header for the stacker class.
 */
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
  string fileName;   //fileName for manipulation in loadFile
  string inputFileName; //original copy of what user input, used in output file creation
  string output; //manipulated version of inputFileName for outFile.open()
  int width; //width of image
  int height; //height of image
  int max_color; //255
  int numberOfImages; //number of images to be processed
  struct pixel{ //struct to store RGB values
    int red;
    int green;
    int blue;
  };
  
  vector<pixel> pixels;  //vector of pixels for output and manipulation
  
  vector<pixel> temp; //temp vector to read in values before being stored in pixels

 public:
  stacker();  //constructor
  void loadFile(string file, int numImages); //reads data from given file and stores in vectors 
  void saveToDisk();  //writes stacked/averaged pixels to disk
  void average(); //loops through pixels and divides each location by numberOfImages
  void setNumImages(int num);  //sets internal private variable numberOfImages
};

#endif //stacker.h
