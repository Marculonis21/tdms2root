# tdms2root

Application for conversion of of *.tdms* files into root file format for
analysis.

## Requirements

Requirements with tested versions: 

- CMake (3.16.3), GNU Make (4.2.1), C++17
- ROOT library (6.30/0.4) accessible on the machine (`root` in the
 command line)

## Building and installation

### Building 

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
[100%] Linking CXX executable _tdms2root
[100%] Built target _tdms2root
```

At this point the built binary `_tdms2root` should be located in the build
directory.

### Installation
To be able to run the application in any directory run the following command
(this command needs 'sudo' privilages to install into a protected
`/usr/local/bin` folder):
```bash
sudo make install
```

To test that everything was done correctly we can run `tdms2root` in the
command line which should output the following message: 

```
Incorrect number of parameters, use-cases:
 - tdms2root <tdms_file> <output_dir>
 - tdms2root <dir_of_tdms_files> <output_dir
``````

## Usage

There are two use-cases of this application prepared:

### Single conversion

We can use the application to convert one *tdms* file to a *root* file by
running the application with two arguments:
1) path to the *tdms* file
2) path to output directory 

Example of running the application in this mode:

```bash
tdms2root data/example.tdms .
```

This example runs conversion of a file `example.tdms` and result is put into
current working directory. The result's name is going to be the same as example
with root extension (`example.root`).

### Bulk conversion

During bulk conversion we can select a specific directory with tdms files and
the application will convert all of them to specified output directory:
1) path to directory with *tdms* files
2) path to output directory

If the output directory does not exist and the path is not corresponding to any
existing file, the application creates a new directory to which converted files
are saved.

Example of this conversion can look like this:
```bash
tdms2root data/ data/out
```

This example finds all *tdms* files in selected folder (`data/*.tdms`;
subdirectories are not searched) and converts them into root files which are
saved into `data/out` directory with same name as originals.
