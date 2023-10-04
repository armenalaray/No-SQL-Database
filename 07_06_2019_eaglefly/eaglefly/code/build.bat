@echo off
cd c:\EagleFly\eaglefly\code\

REM (IMPORTANT) to run exe files from the path where they access the data 

set CommonCompilerFlags= -Od -MTd -nologo -Gm- -GR- -EHa- -Zo -Oi -Oy- -WX -W4 -wd4408 -wd4100 -wd4189 -wd4101 -wd4366 -wd4838 -wd4065 -wd4505 -wd4201 -wd4706 -FC -Z7
set CommonCompilerFlags= -DPLATFORM_MSVC=1 -DEAGLEFLY_INTERNAL=1 %CommonCompilerFlags% 
set CommonLinkerFlags= -incremental:no -opt:ref user32.lib gdi32.lib winmm.lib
set ASM_OBJ= test_asm0.obj

IF NOT EXIST ..\..\build mkdir ..\..\build
pushd ..\..\build
del *.pdb > NUL 2> NUL

REM PDB Parser SECTION ----------------------------------------------------------------------

REM cl %CommonCompilerFlags% ..\eaglefly\code\eaglefly_pdb_parser.cpp /link %CommonLinkerFlags%

REM Win32 disasmsembler SECTION ------------------------------------------------------------

REM cl %CommonCompilerFlags% ..\eaglefly\code\win32_eaglefly_disasm.cpp /link %CommonLinkerFlags%

REM XML Tables SECTION ----------------------------------------------------------------------

set compile_xml_tables=0

IF "%compile_xml_tables%" EQU "1" (

cl %CommonCompilerFlags% -D_CRT_SECURE_NO_WARNINGS ..\eaglefly\code\xml_info.cpp /link %CommonLinkerFlags%

pushd ..\eaglefly\meta\source

..\..\..\build\xml_info.exe x86_64_tables.xml > ..\meta_opcode_filters\xml_tree.info

popd

cl %CommonCompilerFlags% -D_CRT_SECURE_NO_WARNINGS ..\eaglefly\code\instruction_infos_filter.cpp /link %CommonLinkerFlags%

pushd ..\eaglefly\meta\source

..\..\..\build\instruction_infos_filter.exe x86_64_tables.xml -16 > ..\meta_opcode_filters\assembly_grammars_16.info
..\..\..\build\instruction_infos_filter.exe x86_64_tables.xml -32 > ..\meta_opcode_filters\assembly_grammars_32.info

popd

cl %CommonCompilerFlags% -D_CRT_SECURE_NO_WARNINGS ..\eaglefly\code\instruction_infos_filter_64.cpp /link %CommonLinkerFlags%

pushd ..\eaglefly\meta\source

..\..\..\build\instruction_infos_filter_64.exe x86_64_tables.xml > ..\meta_opcode_filters\assembly_grammars_64.info

popd


cl %CommonCompilerFlags% -D_CRT_SECURE_NO_WARNINGS ..\eaglefly\code\opcode_ids_filter.cpp /link %CommonLinkerFlags%

pushd ..\eaglefly\meta\source

..\..\..\build\opcode_ids_filter.exe x86_64_tables.xml -16 > ..\meta_opcode_filters\opcode_ids_16.info
..\..\..\build\opcode_ids_filter.exe x86_64_tables.xml -32 > ..\meta_opcode_filters\opcode_ids_32.info

popd

cl %CommonCompilerFlags% -D_CRT_SECURE_NO_WARNINGS ..\eaglefly\code\opcode_ids_filter_64.cpp /link %CommonLinkerFlags%

pushd ..\eaglefly\meta\source

..\..\..\build\opcode_ids_filter_64.exe x86_64_tables.xml > ..\meta_opcode_filters\opcode_ids_64.info

popd


cl %CommonCompilerFlags% -D_CRT_SECURE_NO_WARNINGS ..\eaglefly\code\meta_instruction_infos_table.cpp /link %CommonLinkerFlags%

pushd ..\eaglefly\meta\source_opcode_tables

..\..\..\build\meta_instruction_infos_table.exe assembly_grammars_16.info 16 > ..\meta_opcode_tables\eflyfile_instruction_infos_16_generated.cpp
..\..\..\build\meta_instruction_infos_table.exe assembly_grammars_32.info 32 > ..\meta_opcode_tables\eflyfile_instruction_infos_32_generated.cpp
..\..\..\build\meta_instruction_infos_table.exe assembly_grammars_64.info 64 > ..\meta_opcode_tables\eflyfile_instruction_infos_64_generated.cpp

popd

cl %CommonCompilerFlags% -D_CRT_SECURE_NO_WARNINGS ..\eaglefly\code\meta_opcode_ids_table.cpp /link %CommonLinkerFlags%

pushd ..\eaglefly\meta\source_opcode_tables

..\..\..\build\meta_opcode_ids_table.exe opcode_ids_16.info 16 > ..\meta_opcode_tables\eflyfile_opcode_ids_16_generated.cpp
..\..\..\build\meta_opcode_ids_table.exe opcode_ids_32.info 32 > ..\meta_opcode_tables\eflyfile_opcode_ids_32_generated.cpp
..\..\..\build\meta_opcode_ids_table.exe opcode_ids_64.info 64 > ..\meta_opcode_tables\eflyfile_opcode_ids_64_generated.cpp

popd

cl %CommonCompilerFlags% -D_CRT_SECURE_NO_WARNINGS ..\eaglefly\code\checksum_entries.cpp /link %CommonLinkerFlags%


)

cl %CommonCompilerFlags% -D_CRT_SECURE_NO_WARNINGS ..\eaglefly\code\meta_instruction_flags.cpp /link %CommonLinkerFlags%


pushd ..\eaglefly\meta\meta_opcode_tables

..\..\..\build\meta_instruction_flags.exe eflyfile_instruction_infos_16_generated.cpp > ..\..\code\eflyfile_instruction_infos_16_generated.cpp
..\..\..\build\meta_instruction_flags.exe eflyfile_instruction_infos_32_generated.cpp > ..\..\code\eflyfile_instruction_infos_32_generated.cpp
..\..\..\build\meta_instruction_flags.exe eflyfile_instruction_infos_64_generated.cpp > ..\..\code\eflyfile_instruction_infos_64_generated.cpp

popd


REM decoder SECTION ----------------------------------------------------------------------


cl %CommonCompilerFlags% -DNEW_EAGLEFLY_API=1 -DEFLYFILE_TABLES_GENERATED=1 ..\eaglefly\code\eaglefly_decoder.cpp /link %CommonLinkerFlags%


pushd ..\eaglefly\out_data\
REM	..\..\build\eaglefly_decoder.exe -64 "C:\MiscPrograms\quadratic_solver\build\quadratic_solver.exe" > eaglefly_quadraticsolver.asm
..\..\build\eaglefly_decoder.exe -64 "C:\RayTracer\build\ray.exe" > eaglefly_ray.asm

	..\..\build\eaglefly_decoder.exe -32 > eaglefly_32.asm
	..\..\build\eaglefly_decoder.exe -16 > eaglefly_16.asm

	"C:\Program Files (x86)\ObjConv\objconv.exe" /fmasm "C:\MiscPrograms\quadratic_solver\build\quadratic_solver.exe" objconv_quadraticsolver.asm

popd



REM other SECTION ----------------------------------------------------------------------

REM cl %CommonCompilerFlags% ..\eaglefly\code\win32_eaglefly_disasm_04.cpp /link %CommonLinkerFlags%


REM cl %CommonCompilerFlags% -D_CRT_SECURE_NO_WARNINGS  ..\eaglefly\code\eaglefly_opcode_tables_generator.cpp /link %CommonLinkerFlags%

REM cl %CommonCompilerFlags% ..\eaglefly\code\eaglefly_disasm___.cpp /link -STACK:0x2800000  %CommonLinkerFlags%

echo WAITING FOR PDB > lock.tmp
REM cl %CommonCompilerFlags%  ..\eaglefly\code\eaglefly.cpp -LD /link -incremental:no -opt:ref -PDB:eaglefly_%random%.pdb -EXPORT:DebugUpdateAndRender 
del lock.tmp

REM cl %CommonCompilerFlags% ..\eaglefly\code\win32_eaglefly.cpp -Fmwin32_eaglefly.map /link %CommonLinkerFlags%
popd 

REM MASM Language Test Builds ------------------------------------------------------------------------------------------------

IF NOT EXIST ..\..\testbuild\ mkdir..\..\testbuild\
pushd ..\..\testbuild\ 

REM ML64 Tests
REM ML64 -DFIBONACCI_TEST -nologo -Zi -Fl -Fo %ASM_OBJ% -c ..\eaglefly\code\test_asm0.asm

REM ML64 -DOPCODE_ENCODING -nologo -Zi  -Fl ..\eaglefly\code\test_asm0.asm /link -LARGEADDRESSAWARE:NO -subsystem:console /DEFAULTLIB:kernel32.lib -defaultlib:user32.lib -entry:START   

REM ML -nologo -Zi  -Fl ..\eaglefly\code\test_asm1.asm  /link -LARGEADDRESSAWARE:NO -subsystem:console -entry:START

REM cl %CommonCompilerFlags% ..\eaglefly\code\test_debug_target.cpp /link %CommonLinkerFlags% %ASM_OBJ% 
popd


