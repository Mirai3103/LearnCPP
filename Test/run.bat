@echo off
set file=%1
@REM set ex=%file:.cpp=% 
@echo on
g++ -o output %file% 
output.exe