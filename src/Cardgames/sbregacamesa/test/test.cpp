#include <iostream>

#include <sbregacamesa.h>

int main(int argc, char *argv[])
{
  Sbregacamesa sbregacamesa;
  unsigned int vincitore = 0;
  while (!vincitore)
  {
    vincitore = sbregacamesa.play_hand();
  }
  std::cout << "Ha vinto " << vincitore << std::endl;
  return 0;
}