# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/marculonis/Desktop/mySocial/CERN/tdms2root

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/marculonis/Desktop/mySocial/CERN/tdms2root/build

# Include any dependencies generated for this target.
include CMakeFiles/tdms2root.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/tdms2root.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tdms2root.dir/flags.make

CMakeFiles/tdms2root.dir/src/main.cpp.o: CMakeFiles/tdms2root.dir/flags.make
CMakeFiles/tdms2root.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marculonis/Desktop/mySocial/CERN/tdms2root/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tdms2root.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tdms2root.dir/src/main.cpp.o -c /home/marculonis/Desktop/mySocial/CERN/tdms2root/src/main.cpp

CMakeFiles/tdms2root.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tdms2root.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marculonis/Desktop/mySocial/CERN/tdms2root/src/main.cpp > CMakeFiles/tdms2root.dir/src/main.cpp.i

CMakeFiles/tdms2root.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tdms2root.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marculonis/Desktop/mySocial/CERN/tdms2root/src/main.cpp -o CMakeFiles/tdms2root.dir/src/main.cpp.s

CMakeFiles/tdms2root.dir/src/tdmsReader/TdmsChannel.cpp.o: CMakeFiles/tdms2root.dir/flags.make
CMakeFiles/tdms2root.dir/src/tdmsReader/TdmsChannel.cpp.o: ../src/tdmsReader/TdmsChannel.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marculonis/Desktop/mySocial/CERN/tdms2root/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/tdms2root.dir/src/tdmsReader/TdmsChannel.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tdms2root.dir/src/tdmsReader/TdmsChannel.cpp.o -c /home/marculonis/Desktop/mySocial/CERN/tdms2root/src/tdmsReader/TdmsChannel.cpp

CMakeFiles/tdms2root.dir/src/tdmsReader/TdmsChannel.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tdms2root.dir/src/tdmsReader/TdmsChannel.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marculonis/Desktop/mySocial/CERN/tdms2root/src/tdmsReader/TdmsChannel.cpp > CMakeFiles/tdms2root.dir/src/tdmsReader/TdmsChannel.cpp.i

CMakeFiles/tdms2root.dir/src/tdmsReader/TdmsChannel.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tdms2root.dir/src/tdmsReader/TdmsChannel.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marculonis/Desktop/mySocial/CERN/tdms2root/src/tdmsReader/TdmsChannel.cpp -o CMakeFiles/tdms2root.dir/src/tdmsReader/TdmsChannel.cpp.s

CMakeFiles/tdms2root.dir/src/tdmsReader/TdmsGroup.cpp.o: CMakeFiles/tdms2root.dir/flags.make
CMakeFiles/tdms2root.dir/src/tdmsReader/TdmsGroup.cpp.o: ../src/tdmsReader/TdmsGroup.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marculonis/Desktop/mySocial/CERN/tdms2root/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/tdms2root.dir/src/tdmsReader/TdmsGroup.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tdms2root.dir/src/tdmsReader/TdmsGroup.cpp.o -c /home/marculonis/Desktop/mySocial/CERN/tdms2root/src/tdmsReader/TdmsGroup.cpp

CMakeFiles/tdms2root.dir/src/tdmsReader/TdmsGroup.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tdms2root.dir/src/tdmsReader/TdmsGroup.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marculonis/Desktop/mySocial/CERN/tdms2root/src/tdmsReader/TdmsGroup.cpp > CMakeFiles/tdms2root.dir/src/tdmsReader/TdmsGroup.cpp.i

CMakeFiles/tdms2root.dir/src/tdmsReader/TdmsGroup.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tdms2root.dir/src/tdmsReader/TdmsGroup.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marculonis/Desktop/mySocial/CERN/tdms2root/src/tdmsReader/TdmsGroup.cpp -o CMakeFiles/tdms2root.dir/src/tdmsReader/TdmsGroup.cpp.s

CMakeFiles/tdms2root.dir/src/tdmsReader/TdmsLeadIn.cpp.o: CMakeFiles/tdms2root.dir/flags.make
CMakeFiles/tdms2root.dir/src/tdmsReader/TdmsLeadIn.cpp.o: ../src/tdmsReader/TdmsLeadIn.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marculonis/Desktop/mySocial/CERN/tdms2root/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/tdms2root.dir/src/tdmsReader/TdmsLeadIn.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tdms2root.dir/src/tdmsReader/TdmsLeadIn.cpp.o -c /home/marculonis/Desktop/mySocial/CERN/tdms2root/src/tdmsReader/TdmsLeadIn.cpp

CMakeFiles/tdms2root.dir/src/tdmsReader/TdmsLeadIn.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tdms2root.dir/src/tdmsReader/TdmsLeadIn.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marculonis/Desktop/mySocial/CERN/tdms2root/src/tdmsReader/TdmsLeadIn.cpp > CMakeFiles/tdms2root.dir/src/tdmsReader/TdmsLeadIn.cpp.i

CMakeFiles/tdms2root.dir/src/tdmsReader/TdmsLeadIn.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tdms2root.dir/src/tdmsReader/TdmsLeadIn.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marculonis/Desktop/mySocial/CERN/tdms2root/src/tdmsReader/TdmsLeadIn.cpp -o CMakeFiles/tdms2root.dir/src/tdmsReader/TdmsLeadIn.cpp.s

CMakeFiles/tdms2root.dir/src/tdmsReader/TdmsMetaData.cpp.o: CMakeFiles/tdms2root.dir/flags.make
CMakeFiles/tdms2root.dir/src/tdmsReader/TdmsMetaData.cpp.o: ../src/tdmsReader/TdmsMetaData.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marculonis/Desktop/mySocial/CERN/tdms2root/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/tdms2root.dir/src/tdmsReader/TdmsMetaData.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tdms2root.dir/src/tdmsReader/TdmsMetaData.cpp.o -c /home/marculonis/Desktop/mySocial/CERN/tdms2root/src/tdmsReader/TdmsMetaData.cpp

CMakeFiles/tdms2root.dir/src/tdmsReader/TdmsMetaData.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tdms2root.dir/src/tdmsReader/TdmsMetaData.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marculonis/Desktop/mySocial/CERN/tdms2root/src/tdmsReader/TdmsMetaData.cpp > CMakeFiles/tdms2root.dir/src/tdmsReader/TdmsMetaData.cpp.i

CMakeFiles/tdms2root.dir/src/tdmsReader/TdmsMetaData.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tdms2root.dir/src/tdmsReader/TdmsMetaData.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marculonis/Desktop/mySocial/CERN/tdms2root/src/tdmsReader/TdmsMetaData.cpp -o CMakeFiles/tdms2root.dir/src/tdmsReader/TdmsMetaData.cpp.s

CMakeFiles/tdms2root.dir/src/tdmsReader/TdmsObject.cpp.o: CMakeFiles/tdms2root.dir/flags.make
CMakeFiles/tdms2root.dir/src/tdmsReader/TdmsObject.cpp.o: ../src/tdmsReader/TdmsObject.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marculonis/Desktop/mySocial/CERN/tdms2root/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/tdms2root.dir/src/tdmsReader/TdmsObject.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tdms2root.dir/src/tdmsReader/TdmsObject.cpp.o -c /home/marculonis/Desktop/mySocial/CERN/tdms2root/src/tdmsReader/TdmsObject.cpp

CMakeFiles/tdms2root.dir/src/tdmsReader/TdmsObject.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tdms2root.dir/src/tdmsReader/TdmsObject.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marculonis/Desktop/mySocial/CERN/tdms2root/src/tdmsReader/TdmsObject.cpp > CMakeFiles/tdms2root.dir/src/tdmsReader/TdmsObject.cpp.i

CMakeFiles/tdms2root.dir/src/tdmsReader/TdmsObject.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tdms2root.dir/src/tdmsReader/TdmsObject.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marculonis/Desktop/mySocial/CERN/tdms2root/src/tdmsReader/TdmsObject.cpp -o CMakeFiles/tdms2root.dir/src/tdmsReader/TdmsObject.cpp.s

CMakeFiles/tdms2root.dir/src/tdmsReader/TdmsParser.cpp.o: CMakeFiles/tdms2root.dir/flags.make
CMakeFiles/tdms2root.dir/src/tdmsReader/TdmsParser.cpp.o: ../src/tdmsReader/TdmsParser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marculonis/Desktop/mySocial/CERN/tdms2root/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/tdms2root.dir/src/tdmsReader/TdmsParser.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tdms2root.dir/src/tdmsReader/TdmsParser.cpp.o -c /home/marculonis/Desktop/mySocial/CERN/tdms2root/src/tdmsReader/TdmsParser.cpp

CMakeFiles/tdms2root.dir/src/tdmsReader/TdmsParser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tdms2root.dir/src/tdmsReader/TdmsParser.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marculonis/Desktop/mySocial/CERN/tdms2root/src/tdmsReader/TdmsParser.cpp > CMakeFiles/tdms2root.dir/src/tdmsReader/TdmsParser.cpp.i

CMakeFiles/tdms2root.dir/src/tdmsReader/TdmsParser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tdms2root.dir/src/tdmsReader/TdmsParser.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marculonis/Desktop/mySocial/CERN/tdms2root/src/tdmsReader/TdmsParser.cpp -o CMakeFiles/tdms2root.dir/src/tdmsReader/TdmsParser.cpp.s

CMakeFiles/tdms2root.dir/src/tdmsReader/TdmsSegment.cpp.o: CMakeFiles/tdms2root.dir/flags.make
CMakeFiles/tdms2root.dir/src/tdmsReader/TdmsSegment.cpp.o: ../src/tdmsReader/TdmsSegment.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marculonis/Desktop/mySocial/CERN/tdms2root/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/tdms2root.dir/src/tdmsReader/TdmsSegment.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tdms2root.dir/src/tdmsReader/TdmsSegment.cpp.o -c /home/marculonis/Desktop/mySocial/CERN/tdms2root/src/tdmsReader/TdmsSegment.cpp

CMakeFiles/tdms2root.dir/src/tdmsReader/TdmsSegment.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tdms2root.dir/src/tdmsReader/TdmsSegment.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marculonis/Desktop/mySocial/CERN/tdms2root/src/tdmsReader/TdmsSegment.cpp > CMakeFiles/tdms2root.dir/src/tdmsReader/TdmsSegment.cpp.i

CMakeFiles/tdms2root.dir/src/tdmsReader/TdmsSegment.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tdms2root.dir/src/tdmsReader/TdmsSegment.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marculonis/Desktop/mySocial/CERN/tdms2root/src/tdmsReader/TdmsSegment.cpp -o CMakeFiles/tdms2root.dir/src/tdmsReader/TdmsSegment.cpp.s

# Object files for target tdms2root
tdms2root_OBJECTS = \
"CMakeFiles/tdms2root.dir/src/main.cpp.o" \
"CMakeFiles/tdms2root.dir/src/tdmsReader/TdmsChannel.cpp.o" \
"CMakeFiles/tdms2root.dir/src/tdmsReader/TdmsGroup.cpp.o" \
"CMakeFiles/tdms2root.dir/src/tdmsReader/TdmsLeadIn.cpp.o" \
"CMakeFiles/tdms2root.dir/src/tdmsReader/TdmsMetaData.cpp.o" \
"CMakeFiles/tdms2root.dir/src/tdmsReader/TdmsObject.cpp.o" \
"CMakeFiles/tdms2root.dir/src/tdmsReader/TdmsParser.cpp.o" \
"CMakeFiles/tdms2root.dir/src/tdmsReader/TdmsSegment.cpp.o"

# External object files for target tdms2root
tdms2root_EXTERNAL_OBJECTS =

tdms2root: CMakeFiles/tdms2root.dir/src/main.cpp.o
tdms2root: CMakeFiles/tdms2root.dir/src/tdmsReader/TdmsChannel.cpp.o
tdms2root: CMakeFiles/tdms2root.dir/src/tdmsReader/TdmsGroup.cpp.o
tdms2root: CMakeFiles/tdms2root.dir/src/tdmsReader/TdmsLeadIn.cpp.o
tdms2root: CMakeFiles/tdms2root.dir/src/tdmsReader/TdmsMetaData.cpp.o
tdms2root: CMakeFiles/tdms2root.dir/src/tdmsReader/TdmsObject.cpp.o
tdms2root: CMakeFiles/tdms2root.dir/src/tdmsReader/TdmsParser.cpp.o
tdms2root: CMakeFiles/tdms2root.dir/src/tdmsReader/TdmsSegment.cpp.o
tdms2root: CMakeFiles/tdms2root.dir/build.make
tdms2root: /home/marculonis/Downloads/root/lib/libMathMore.so.6.30.04
tdms2root: /home/marculonis/Downloads/root/lib/libTree.so.6.30.04
tdms2root: /home/marculonis/Downloads/root/lib/libMathCore.so.6.30.04
tdms2root: /home/marculonis/Downloads/root/lib/libImt.so.6.30.04
tdms2root: /home/marculonis/Downloads/root/lib/libMultiProc.so.6.30.04
tdms2root: /home/marculonis/Downloads/root/lib/libNet.so.6.30.04
tdms2root: /home/marculonis/Downloads/root/lib/libRIO.so.6.30.04
tdms2root: /home/marculonis/Downloads/root/lib/libThread.so.6.30.04
tdms2root: /home/marculonis/Downloads/root/lib/libCore.so.6.30.04
tdms2root: CMakeFiles/tdms2root.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/marculonis/Desktop/mySocial/CERN/tdms2root/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable tdms2root"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tdms2root.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tdms2root.dir/build: tdms2root

.PHONY : CMakeFiles/tdms2root.dir/build

CMakeFiles/tdms2root.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tdms2root.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tdms2root.dir/clean

CMakeFiles/tdms2root.dir/depend:
	cd /home/marculonis/Desktop/mySocial/CERN/tdms2root/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/marculonis/Desktop/mySocial/CERN/tdms2root /home/marculonis/Desktop/mySocial/CERN/tdms2root /home/marculonis/Desktop/mySocial/CERN/tdms2root/build /home/marculonis/Desktop/mySocial/CERN/tdms2root/build /home/marculonis/Desktop/mySocial/CERN/tdms2root/build/CMakeFiles/tdms2root.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tdms2root.dir/depend

