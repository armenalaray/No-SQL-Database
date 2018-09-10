@echo off
cd c:\EagleFly\eaglefly\practice\

pushd ..\..\practicebuild\
cl -MTd -Od -nologo ../eaglefly/practice/test_debug.cpp  
popd
