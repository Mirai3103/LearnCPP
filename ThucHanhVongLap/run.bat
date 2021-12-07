@echo off
set file=%1
@REM set ex=%file:.cpp=% 
Del *.exe
@echo on
g++ -o output %file% 
@echo off
output.exe
@echo on