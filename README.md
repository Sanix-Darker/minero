# MINERO

Meet Minero, a customizable C++ miner for your personnal Blockchain !
The minning process was too long in python, so i implemented this lib in C++ using sha256 !

## Requirements

- python (3.x is recommended)
- pip (Install it by running sudo apt-get install python3-pip)
- C++11 (recommended)
- Conan (install it by running `pip install conan`)
- Boost C++ Python 3.7 (Install it by running : `sudo apt-get install cmake libblkid-dev e2fslibs-dev libboost-all-dev libaudit-dev`)

### Example of usage

We jus need to call mine from minero and we have to provide :
- The bloc (A json structure as below)
- The attribute name of the nonce, in this case it's nonce
- The difficulty, in this case 5 (defines the number of 0 at the start of the Hash)
- And true or false for the debug Mode

INPUT :
```python
from minero import mine

# You have your bloc you want to mine
example_block =  "{\
     \"index\": 1,\
     \"transactions\": [\
       {\
         \"from\": \"string\",\
         \"to\": \"string\",\
         \"type\": \"string\",\
         \"content\": \"value\",\
         \"timestamp\": 1582301090.8854582,\
         \"tx_previous_hash\": \"99ae4e4b32f8b29fba5277e30180f3d75436b9756d1ec075f5aa5519aa15c9c0\",\
         \"tx_nonce\": 183\
       },\
       {\
         \"from\": \"string\",\
         \"to\": \"string\",\
         \"type\": \"string\",\
         \"content\": \"qqvalue\",\
         \"timestamp\": 1582301834.1500485,\
         \"tx_previous_hash\": \"9cfd783ddabdb228bd70357446c49ed2b2d98df0cf5d315f4eb69eb5d3148f40\",\
         \"tx_nonce\": 20\
       }\
     ],\
     \"timestamp\": 1582301860.202116,\
     \"nonce\":0,\
     \"previous_hash\": \"19de66af7e186f2eeba3598e625548366237b7a99389de89f06a641ecf319e7e\"\
}"

print(">> mine: ", mine(example_block, "nonce", 5, True))
```

To test fast, you can run : `sh ./shells/build.sh && sh ./shells/build_whl.sh && python test.py`

OUTPUT:

```shell
[+] -> COMPUTED_HASH: fa96e823c9576e75c515d006bf606b0ed8d9c1b24debfd2082963e8f66a53d09 | NONCE: 1
[+] -> COMPUTED_HASH: ae9889b7823cc0f73f467e3c79572c7c780e332913ab94acee32ecfec6f07fda | NONCE: 2
[+] -> COMPUTED_HASH: c458b9d5fc14c54554027941a9966b4b5834175fd8dde8ae4dcc37f2d7d27c3c | NONCE: 3
.......
.........
.............
[+] -> COMPUTED_HASH: 3b53331eb4cfad903725768ec5af95763c637e9bae616b10eb967aceece1b559 | NONCE: 388658
[+] -> COMPUTED_HASH: 66490fb305f40ee259d078eb537a3cbb37a97dfd8c769c031e60c630fe275341 | NONCE: 388659
[+] -> COMPUTED_HASH: 0573834c7a8c06db92f3e8cf3b6e08e226b5d16d82b77bb2b1da56776e547fe5 | NONCE: 388660
[+] -> COMPUTED_HASH: 3712373e3857daffd4de554e03eb6ae074224ce50d32090a49390f9aa387082c | NONCE: 388661
[+] -> COMPUTED_HASH: 4d42b29c302b08ddcf3c22f64eb6178ce4e85f1b516ab3d59b12004fc07131d1 | NONCE: 388662
[+] -> COMPUTED_HASH: a1bc729c5e17aefdf2aea1cb5ef71e093ae2bd3be24bb3bb7e75891bfbd7701a | NONCE: 388663
[+] -> COMPUTED_HASH: 000002edefa82346d283eb4920ad506817ed10596d7017f5a2a0fffb741dfe46 | NONCE: 388664
>> mine:  {"hash" : "000002edefa82346d283eb4920ad506817ed10596d7017f5a2a0fffb741dfe46","nonce": 388664}
```

## Ho to test this project

#### 1- Install pre-requirements

Just run: `sh ./shells/install.sh`
What is done behind the scene:

```shell
pip install conan
```

#### 2- You need to configure your `conanfile.txt` like this sample:

Sample content :

```txt
[requires]

[generators]
cmake
```

you can also do a `conan search your-lib --remote=conan-center` and then select in the list what you want to use


#### 3- Config your `CMakeLists.txt`, conan-packages as follow:

The content of the file :
```txt
cmake_minimum_required(VERSION 3.12)

project(minero)

add_definitions("-std=c++11")
find_package(Boost COMPONENTS python37 REQUIRED)
find_package(PythonInterp 3.7.3)
find_package(PythonLibs 3.7.3)

include("./build/conanbuildinfo.cmake")
conan_basic_setup()

add_library(${PROJECT_NAME}
                SHARED
                module.cpp
                minero.cpp)

file(GLOB
        headers
        *.hpp)

target_include_directories(${PROJECT_NAME} PRIVATE ${Boost_INCLUDE_DIRS} ${PYTHON_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES} ${PYTHON_LIBRARIES} ${CONAN_LIBS})

# To build an eecutable
# add_executable(${PROJECT_NAME} minero.cpp)
target_link_libraries(${PROJECT_NAME} ${CONAN_LIBS})
set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "")

message("install ${Python_SITELIB}")
```

Now, we are set-up and we can build our sample app for streaming the camera of our laptop : 


#### 5- We can now build it to get our `.so` shared library.

Just run: `sh ./shells/build.sh`
What is done behind the scene:

```shell
rm -rf build
mkdir build && cd build
conan install ..
cmake .. -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release
cmake --build .
```

Some files will be added in `./build` + the portable of our application in `./build/bin` or the lib in `./build/lib` :-)


#### 6- if it was an executable we can run our application :

Just run: `sh ./start.sh`
What is done behind the scene:

```shell
./build/bin/----
```

#### If it was a library we want to call it in our python source code

Just run: `sh ./shells/build_whl.sh`
What is done behind the scene:

```shell
pip3 install wheel
pip3 uninstall ./dist/*
rm -rf ./dist/*
python3 setup.py bdist_wheel
pip3 install ./dist/*
```

In the Cpp sour-code we have : 

```c++
#include <iostream>
#include "minero.hpp" 

void help(std::string strr)
{
    std::cout << "Working Fine!" << std::endl;
    std::cout << "You said : " << strr;
}
.
.
.
```

We can call it in our python sourcode like this :

```python
from minero import help
print(help())
```

Or just run `python3 test.py` to test it your self.


## EXTRAS

Sometimes, generating the lib could block some method, use `nm -gD yourLib.so` to see wich methods are allowed to be use and not others



## Author

- Sanix-darker
