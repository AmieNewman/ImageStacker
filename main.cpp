#include "stacker.h"
 

int main() {
  string fileName;
  stacker stack;
  int numberOfImages;
  
  
  cout << "Enter the image you wish to stack: ";
  cin >> fileName;
  
  cout << "Enter the number of images to stack: ";
  cin >> numberOfImages;
  
  stack.setNumImages(numberOfImages);
  
  
  cout << "Stacking images: " << endl;
  stack.loadFile(fileName,numberOfImages);
  stack.saveToDisk();
  stack.check();
  
return 0; 
}
