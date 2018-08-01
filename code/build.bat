@echo off
cd c:\EagleFly\eaglefly\code\

set CommonCompilerFlags= -Od -MTd -nologo -Gm- -GR- -EHa- -Zo -Oi -WX -W4 -wd4100 -wd4189 -wd4366 -wd4838 -wd4065 -wd4505 -wd4201 -FC -Z7 
set CommonCompilerFlags= -DPLATFORM_MSVC=1 -DEAGLEFLY_INTERNAL=1 %CommonCompilerFlags% 
set CommonLinkerFlags= -incremental:no -opt:ref user32.lib gdi32.lib winmm.lib

IF NOT EXIST ..\..\testbuild\ mkdir..\..\testbuild\
pushd ..\..\testbuild\ 
cl %CommonCompilerFlags% ..\eaglefly\code\test_debug_target.cpp /link %CommonLinkerFlags%
popd

IF NOT EXIST ..\..\build mkdir ..\..\build
pushd ..\..\build
del *.pdb > NUL 2> NUL

cl %CommonCompilerFlags% ..\eaglefly\code\eaglefly_pdb_parser.cpp /link %CommonLinkerFlags%

echo WAITING FOR PDB > lock.tmp
cl %CommonCompilerFlags%  ..\eaglefly\code\eaglefly.cpp -LD /link -incremental:no -opt:ref -PDB:eaglefly_%random%.pdb -EXPORT:DebugUpdateAndRender 
del lock.tmp

cl %CommonCompilerFlags% ..\eaglefly\code\win32_eaglefly.cpp -Fmwin32_eaglefly.map /link %CommonLinkerFlags%

REM BSCMAKE win32_eaglefly.sbr eaglefly.sbr   

popd 


