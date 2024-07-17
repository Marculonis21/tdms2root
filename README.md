# tdms2root

Application for conversion of of *.tdms* files into root file format for
analysis.

## Requirements

- CMake, Make, C++17
- The only requirement for the project to work is to have ROOT library (Tested
 with ROOT 6.16) accessible on the machine. CMakeList is supplied to help the
 building process and the only requirement is for it to be able to find ROOT
 for linking.

## Building 

Building the application is done through CMake. 

From the main directory do:

```bash
cmake -B build
cd build
make
```

This process should finish with the message: 
```
...
[100%] Linking CXX executable tdms2root
[100%] Built target tdms2root
```

To test this we can run `./tdms2root` which should output the message: 
```
Use: tdms2root your_file_name.tdms output_directory.
``````

## Usage

There are two use-cases of this application prepared:

### Single conversion

We can use the application to convert one *tdms* file to a *root* file by running the application with two arguments:
1) path to the *tdms* file
2) path to directory where to put the converted file 

Running the application (from the build folder/folder with tdms2root
application) then can look for example look like:

```bash
./tdms2root data/example.tdms .
```

This example runs conversion of a file `example.tdms` and result is put into
current working directory. The result's name is going to be the same as example
with root extension (`example.root`).

### Bulk conversion

