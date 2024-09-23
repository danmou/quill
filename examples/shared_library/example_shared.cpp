#include "launcher/launcher.h"
#include <iostream>

int main()
{
  std::cout << "Application started." << std::endl;

  // Launch the modules via Launcher DLL
  launch_modules();

  std::cout << "Application exiting." << std::endl;
  return 0;
}