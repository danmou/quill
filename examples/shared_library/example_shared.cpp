#include <iostream>
#include <windows.h>

typedef void (*LaunchModules)();

int main()
{
  std::cout << "Application started." << std::endl;

  // Load Launcher
  HMODULE launcher_shared = LoadLibrary(TEXT("launcher_shared.dll"));
  if (!launcher_shared)
  {
    std::cout << "Failed to load launcher_shared" << std::endl;
    return -1;
  }
  else
  {
    std::cout << "launcher_shared loaded" << std::endl;
  }

  // Get the function addresses
  LaunchModules launch_modules = (LaunchModules)GetProcAddress(launcher_shared, "launch_modules");

  if (!launch_modules)
  {
    std::cerr << "Failed to get function addresses launch_modules!" << std::endl;
    return -1;
  }

  // Launch the modules via Launcher DLL
  launch_modules();

  std::cout << "Application exiting." << std::endl;
  FreeLibrary(launcher_shared);

  std::cout << "Application done." << std::endl;
  return 0;
}