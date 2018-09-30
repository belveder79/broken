#include <dlfcn.h>
#include <iostream>

int main (int argc, char* argv[])
{
  void* handle = dlopen("liblibrary.so", RTLD_LAZY);
  if (!handle) {
    std::cerr << "Cannot open library: " << dlerror() << '\n';
    return 1;
  }
  typedef void (*initFunction_t)();
  initFunction_t initFunction = (initFunction_t) dlsym(handle,"initFunction");
  const char *dlsym_error = dlerror();
 if (dlsym_error) {
   std::cerr << "Cannot load symbol 'hello': " << dlsym_error << '\n';
   dlclose(handle);
   return 1;
  }
  initFunction();
  dlclose(handle);
  return 0;
}
