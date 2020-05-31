#include "Image.h"

Image::Image() = default;

Image::Image(std::string _fileName, std::string _magicNumber,std::vector<std::string> _comments, 
             int _width, int _height) : fileName (_fileName), magicNumber (_magicNumber),
             comments (_comments), width(_width), height(_height) {}

Image::~Image() = default;

void Image::grayscale() {}

void Image::monochrome() {}
