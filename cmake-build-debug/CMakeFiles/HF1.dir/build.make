# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.3.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.3.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Zsolt\CLionProjects\HF1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Zsolt\CLionProjects\HF1\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\HF1.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\HF1.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\HF1.dir\flags.make

CMakeFiles\HF1.dir\main.c.obj: CMakeFiles\HF1.dir\flags.make
CMakeFiles\HF1.dir\main.c.obj: ..\main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Zsolt\CLionProjects\HF1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/HF1.dir/main.c.obj"
	C:\PROGRA~2\MICROS~1\2017\ENTERP~1\VC\Tools\MSVC\1415~1.267\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoCMakeFiles\HF1.dir\main.c.obj /FdCMakeFiles\HF1.dir\ /FS -c C:\Users\Zsolt\CLionProjects\HF1\main.c
<<

CMakeFiles\HF1.dir\main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/HF1.dir/main.c.i"
	C:\PROGRA~2\MICROS~1\2017\ENTERP~1\VC\Tools\MSVC\1415~1.267\bin\Hostx86\x86\cl.exe > CMakeFiles\HF1.dir\main.c.i @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Zsolt\CLionProjects\HF1\main.c
<<

CMakeFiles\HF1.dir\main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/HF1.dir/main.c.s"
	C:\PROGRA~2\MICROS~1\2017\ENTERP~1\VC\Tools\MSVC\1415~1.267\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoNUL /FAs /FaCMakeFiles\HF1.dir\main.c.s /c C:\Users\Zsolt\CLionProjects\HF1\main.c
<<

# Object files for target HF1
HF1_OBJECTS = \
"CMakeFiles\HF1.dir\main.c.obj"

# External object files for target HF1
HF1_EXTERNAL_OBJECTS =

HF1.exe: CMakeFiles\HF1.dir\main.c.obj
HF1.exe: CMakeFiles\HF1.dir\build.make
HF1.exe: CMakeFiles\HF1.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Zsolt\CLionProjects\HF1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable HF1.exe"
	"C:\Program Files\JetBrains\CLion 2019.3.4\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\HF1.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100171~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100171~1.0\x86\mt.exe --manifests  -- C:\PROGRA~2\MICROS~1\2017\ENTERP~1\VC\Tools\MSVC\1415~1.267\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\HF1.dir\objects1.rsp @<<
 /out:HF1.exe /implib:HF1.lib /pdb:C:\Users\Zsolt\CLionProjects\HF1\cmake-build-debug\HF1.pdb /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\HF1.dir\build: HF1.exe

.PHONY : CMakeFiles\HF1.dir\build

CMakeFiles\HF1.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\HF1.dir\cmake_clean.cmake
.PHONY : CMakeFiles\HF1.dir\clean

CMakeFiles\HF1.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Users\Zsolt\CLionProjects\HF1 C:\Users\Zsolt\CLionProjects\HF1 C:\Users\Zsolt\CLionProjects\HF1\cmake-build-debug C:\Users\Zsolt\CLionProjects\HF1\cmake-build-debug C:\Users\Zsolt\CLionProjects\HF1\cmake-build-debug\CMakeFiles\HF1.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\HF1.dir\depend

