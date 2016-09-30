/*Amie Newman and Charles Clayton
 *Last modified: 9/30/16
 *File: main.cpp
 *Desc: Driver for stacker function
 */
#include "stacker.h"
 

int main() {
  string fileName;
  stacker stack;
  int numberOfImages;
  
  
  cout << "Enter the image you wish to stack: ";         //user interaction to get desired fileName and number of images to stack
  cin >> fileName;
  
  cout << "Enter the number of images to stack: ";
  cin >> numberOfImages;
  
  stack.setNumImages(numberOfImages);  //set numberOfImages in stacker class
  
  
  cout << "Stacking images: " << endl;
  stack.loadFile(fileName,numberOfImages);  //call to load file
  stack.saveToDisk(); //writing stacked image to disk
  
return 0; 
}
