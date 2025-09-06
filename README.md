# tdms2root

Application for conversion of of *.tdms* files into root file format for
analysis.

## Requirements

Requirements with tested versions: 

- CMake (3.16.3), GNU Make (4.2.1), C++17
- ROOT library (6.30/0.4) accessible on the machine (`root` in the
 command line)
> HINT: You can check root version in command line by running `root --version`

## Building and installation

There are two ways how to download this repository: Cloning or Downloading the
latest released version from releases.

#### Clone repository

Before the build process please clone this repository to your desired location
(the location does not later alter the functionality of this application).
Navigate to the directory where you want this to be cloned and run command:
```bash
git clone https://github.com/Marculonis21/tdms2root.git
```

At time of writing this documentation the correct output looks something like
this: 

```bash
Cloning into 'tdms2root'...
remote: Enumerating objects: 371, done.
remote: Counting objects: 100% (371/371), done.
remote: Compressing objects: 100% (195/195), done.
remote: Total 371 (delta 172), reused 343 (delta 146), pack-reused 0
Receiving objects: 100% (371/371), 28.89 MiB | 2.45 MiB/s, done.
Resolving deltas: 100% (172/172), done.
```

When everything was done correctly navigate to the cloned repository with `cd
tdms2root` and proceed to the build step.

#### Download release

In Github [tdms2root](https://github.com/Marculonis21/tdms2root) navigate to
releases. Select the latest release and download the zip or tar archive. 

Unzip the archive into a new folder and then navigate into the folder with
`cd <folder-name>`, then proceed to the build step.

***

### Building 

Building of the application is done through CMake. From the main directory run:
```bash
cmake -B build
cd build
make
```

This process should finish with a message similar to this one: 
```
...
[100%] Linking CXX executable _tdms2root
[100%] Built target _tdms2root
```

At this point the built binary `_tdms2root` should be located in the current
build directory.

### Installation
For us to be able to run the application from any directory we want, we need to
install the application. Installation process needs *sudo* privilages to
install into a protected `/usr/local/bin` folder). While staying in the build
directory run this next command:
```bash
sudo make install
```

To test that everything was done correctly we can now run `tdms2root` in the
command line which should output the following message: 

```
TDMS2ROOT convertor - ISOLDE CERN 2024 - MB
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
saved into `data/out` directory with same name as original files. 
