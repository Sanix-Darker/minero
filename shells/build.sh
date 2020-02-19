# For the first time:
# conan profile new default --detect  # Generates default profile detecting GCC and sets old ABI
# conan profile update settings.compiler.libcxx=libstdc++11 default  # Sets libcxx to C++11 ABI
rm -rf build
mkdir build && cd build
PATH=$PATH:/home/d4rk3r/.local/bin
conan install ..
cmake .. -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release
cmake --build .
