#include "stacker.h"

stacker::stacker(){
  temp = pixels;
   }

void stacker::setNumImages(int num){
  numberOfImages = num;
}

void stacker::loadFile(string file, int numberOfImages){
  int num;
  pixel color;
  inputFileName = file;
  
  fileName = file;
  //pixels.clear();
  //temp.clear();
  //pixels.reserve(0);
  // temp.reserve(0);
  
  //pixels.reserve(width*height*10);
  //temp.reserve(width*height*10);
  for(int i = 1; i <= numberOfImages; i++){
    stringstream toNumber;
    toNumber << i;
      string number = toNumber.str();

      if( i > 9)
	{
	  fileName = fileName + "_0" + number + ".ppm";
	}
      else
	{
	  fileName = fileName + "_00" + number  + ".ppm";
	}
      
      ifstream inFile;
      inFile.open(fileName.c_str());
      inFile >> magic_number;
      inFile >> width;
      inFile >> height;
      inFile >> max_color;
      cout << "max_color read in: " << max_color << endl;

      int j = 0;
      cout << temp.size() << endl;
      cout << temp.capacity() << endl;
      //cout << "temp.size before read loop: " << temp.size() << endl;
      while(inFile){
	//cout << "entered read loop " << endl;
	//cout << "temp.size():     " << temp.size() << endl;
	//cout << "temp.capacity(): " << temp.capacity() << endl;
	//cout << "temp.max_size(): " << temp.max_size() << endl;
	//temp.clear();
	//cout << "temp.size after clearing: " << temp.size() << endl;
	//cout << "capacity: " << temp.capacity() << endl;
	if(i == 1)
	  {
	    inFile >> color.red;
	    inFile >> color.green;
	    inFile >> color.blue;
	    pixels.push_back(color);
	    temp.push_back(color);
	  }
	else
	  {
	    inFile >> color.red;
	    inFile >> color.green;
	    inFile >> color.blue;
	    temp[j].red = color.red;
	    temp[j].green = color.green;
	    temp[j].blue = color.blue;
	    pixels[j].red += temp[j].red;
	    pixels[j].green += temp[j].green;
	    pixels[j].blue += temp[j].blue;
	    j++;
	  }
	/*pixels[j].red += temp[j].red;
	cout << "pixels[" << j << "].red " << pixels[j].red << endl;
	pixels[j].green += temp[j].green;
	pixels[j].blue += temp[j].blue;*/
      }
      
      cout << fileName << endl;
      inFile.close();
      fileName = file;
    }
  
}

void stacker::check(){
  cout << "pixels[125000].blue: " << pixels[125000].blue << endl;
 }

void stacker::average(){
  for(int i = 0; i < pixels.size(); i++){
    pixels[i].red = pixels[i].red / numberOfImages;
    pixels[i].green = pixels[i].green / numberOfImages;
    pixels[i].blue = pixels[i].blue / numberOfImages;
  }
}

void stacker::saveToDisk(){
  
  ofstream outFile;
  output = inputFileName + ".ppm";
  outFile.open(output.c_str());
  cout << "good(): " << outFile.good() << endl;

   
  outFile << magic_number << endl;
  //cout << magic_number << endl;
  outFile << width << " " << height << endl;
  //cout << width << " " << height << endl;
  outFile << max_color << endl;
  //cout << max_color << endl;

  average();
  
  for(int i = 0; i < pixels.size(); i++){
    outFile << pixels[i].red << " " << pixels[i].green << " " << pixels[i].blue << " ";
    //cout << pixels[i].red << " " << pixels[i].green << " " << pixels[i].blue << "\t";
  }
  outFile.close();
}
