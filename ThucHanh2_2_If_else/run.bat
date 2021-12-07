@echo off
set file=%1
@REM set ex=%file:.cpp=% 
Del "output.exe"
@echo on
g++ -o output %file% 
output.exe