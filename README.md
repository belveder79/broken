# Example of pthread link mess on Linux 

This is an example of broken dynamic library loading of pthread, using a threadpool as an example. The Threadpool was taken from here:
https://github.com/progschj/ThreadPool/blob/master/ThreadPool.h

A detailed Stackoverflow discussion here:
https://stackoverflow.com/questions/52580992/linux-executable-opening-shared-library-through-dlopen-crashing-on-emplace-back

There is a single option to pass to the linker that makes/breaks things:

    SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,--no-as-needed")
  
This is the magic to make it work. If you remove this line from the _CMakeLists.txt_ file, _pthread_ does not get loaded and the app crashes. 
