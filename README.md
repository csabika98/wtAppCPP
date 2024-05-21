# HelloWtApp2

## Screenshots

## 1
![1.png](screenshots/1.png)
## 2
![2.png](screenshots/2.png)
## 3
![3.png](screenshots/3.png)

## Overview

HelloWtApp2 is a web application built in C++. 

This application demonstrates how to set up a simple server that serves an HTML template with embedded CSS.


## Project Structure
```sh
myapp/
├── src/
│   ├── main.cpp
│   └── (other source files)
├── include/
│   └── (header files)
├── docroot/
│   └── resources/
│       ├── index.html
│       ├── themes/
│       │   └── default/
│       │       └── wt.css
│       ├── webkit-transitions.css
│       └── (other resource files)
├── lib/
│   └── (library files)
├── bin/
│   └── (DLL files)
├── CMakeLists.txt
└── README.md
```
## Prerequisites

-   CMake 3.10 or higher
-   A C++ compiler that supports C++17
-   Wt libraries and their dependencies (e.g., Boost, OpenSSL)

## Building the Application

1.  Clone the repository: 
```sh    
git clone https://github.com/csabika98/HelloWtApp2.git
cd HelloWtApp2
```
    
2.  Create a build directory and navigate into it: 
```sh  
mkdir build 
cd build
```  
3.  Run CMake to configure the project: 
```sh
cmake ..
``` 

4.  Build the project: 
```sh
cmake --build .
```

## Running the Application

After building the application, you can run the executable with the following command:
```sh
./bin/HelloWtApp2 
```

This command starts the server on [http://localhost:8080](http://localhost:8080) and serves the application.


## Project Configuration

### CMake Configuration
```ssh
The CMakeLists.txt file is configured to:

-   Set the project name and version.
-   Specify the C++ standard to be used (C++17).
-   Include necessary directories.
-   Recursively gather source files from the src and docroot/resources directories.
-   Create an executable named HelloWtApp2.
-   Link necessary libraries.
-   Set the runtime output directory.
-   Copy necessary DLLs to the output directory after the build.
```
