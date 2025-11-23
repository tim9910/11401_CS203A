@echo off
REM Makefile.bat - Windows batch file using cl.exe for C/C++ compilation

REM Compilers
set CC=cl.exe
set CXX=cl.exe

REM Flags
set CFLAGS=/EHsc /W4 /Zi
set CXXFLAGS=/EHsc /W4 /Zi

REM Source files
set C_SRCS=C\main.c C\hash_fn.c
set C_OBJS=C\main.obj C\hash_fn.obj
set C_BIN=C\hash_function.exe

set CXX_SRCS=CXX\main.cpp CXX\hash_fn.cpp
set CXX_OBJS=CXX\main.obj CXX\hash_fn.obj
set CXX_BIN=CXX\hash_function_cpp.exe

if "%1"=="" goto all
if "%1"=="all" goto all
if "%1"=="c" goto c
if "%1"=="cxx" goto cxx
if "%1"=="clean" goto clean
goto usage

:all
call :c
call :cxx
goto end

:c
echo Building C version...
%CC% %CFLAGS% /c "C\main.c" /Fo"C\main.obj"
%CC% %CFLAGS% /c "C\hash_fn.c" /Fo"C\hash_fn.obj"
%CC% %CFLAGS% /Fe%C_BIN% %C_OBJS%
goto end

:cxx
echo Building C++ version...
%CXX% %CXXFLAGS% /c "CXX\main.cpp" /Fo"CXX\main.obj"
%CXX% %CXXFLAGS% /c "CXX\hash_fn.cpp" /Fo"CXX\hash_fn.obj"
%CXX% %CXXFLAGS% /Fe%CXX_BIN% %CXX_OBJS%
goto end

:clean
echo Cleaning...
if exist C\*.obj del C\*.obj
if exist CXX\*.obj del CXX\*.obj
if exist %C_BIN% del %C_BIN%
if exist %CXX_BIN% del %CXX_BIN%
goto end

:usage
echo Usage: Makefile.bat [all|c|cxx|clean]
echo   all   - Build both C and C++ versions (default)
echo   c     - Build C version only
echo   cxx   - Build C++ version only
echo   clean - Remove all generated files

:end
