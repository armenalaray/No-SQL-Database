@echo off
cd c:\EagleFly\eaglefly\code\

set CommonCompilerFlags= -Od -MTd -nologo -Gm- -GR- -EHa- -Zo -Oi -WX -W4 -wd4408 -wd4100 -wd4189 -wd4101 -wd4366 -wd4838 -wd4065 -wd4505 -wd4201 -FC -Z7
set CommonCompilerFlags= -DPLATFORM_MSVC=1 -DEFLY_INTERNAL=1 %CommonCompilerFlags% 
set CommonLinkerFlags= -incremental:no -opt:ref user32.lib gdi32.lib winmm.lib
set ASM_OBJ= test_asm0.obj

IF NOT EXIST ..\..\build mkdir ..\..\build
pushd ..\..\build
del *.pdb > NUL 2> NUL

REM PDB Parser
REM cl %CommonCompilerFlags% ..\eaglefly\code\eaglefly_pdb_parser.cpp /link %CommonLinkerFlags%

REM PE/obj file Parser
cl %CommonCompilerFlags% ..\eaglefly\code\eaglefly_pe_parser.cpp /link %CommonLinkerFlags%

echo WAITING FOR PDB > lock.tmp
REM cl %CommonCompilerFlags%  ..\eaglefly\code\eaglefly.cpp -LD /link -incremental:no -opt:ref -PDB:eaglefly_%random%.pdb -EXPORT:DebugUpdateAndRender 
del lock.tmp

REM cl %CommonCompilerFlags% ..\eaglefly\code\win32_eaglefly.cpp -Fmwin32_eaglefly.map /link %CommonLinkerFlags%

REM BSCMAKE win32_eaglefly.sbr eaglefly.sbr   

popd 

REM Test Builds ------------------------------------------------------------------------------------------------

IF NOT EXIST ..\..\testbuild\ mkdir..\..\testbuild\
pushd ..\..\testbuild\ 

REM ML64 Tests
ML64 -DFIBONACCI_TEST -nologo -Zi -Fl -Fo %ASM_OBJ% -c ..\eaglefly\code\test_asm0.asm
REM ML64 -DMESSAGEBOX_TEST -nologo -Zi -Fl -w ..\eaglefly\code\test_asm0.asm /link /subsystem:console -defaultlib:kernel32.lib -defaultlib:user32.lib -entry:START 

REM cl %CommonCompilerFlags% ..\eaglefly\code\test_debug_target.cpp /link %CommonLinkerFlags% %ASM_OBJ% 
popd


