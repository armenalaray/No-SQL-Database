-64
MOV qword ptr SS : [ RSP +  + 0x20 ], R9                    ;0000000140001000 4C 89 4C 24 20 
MOV qword ptr SS : [ RSP +  + 0x18 ], R8                    ;0000000140001005 4C 89 44 24 18 
MOV qword ptr SS : [ RSP +  + 0x10 ], RDX                   ;000000014000100A 48 89 54 24 10 
MOV qword ptr SS : [ RSP +  + 0x08 ], RCX                   ;000000014000100F 48 89 4C 24 08 
PUSH ESI                                                    ;0000000140001014 56 
PUSH EDI                                                    ;0000000140001015 57 
SUB RSP, 0x000001A8                                         ;0000000140001016 48 81 EC A8 01 00 00 
MOV RAX, CS : [ RIP + 0x00058FE4 ]                          ;000000014000101D 48 8B 05 E4 8F 05 00 
XOR RAX, RSP                                                ;0000000140001024 48 33 C4 
MOV qword ptr SS : [ RSP +  + 0x00000190 ], RAX             ;0000000140001027 48 89 84 24 90 01 00 00 
LEA RAX, invalid ptr SS : [ RSP +  + 0x00000170 ]           ;000000014000102F 48 8D 84 24 70 01 00 00 
MOV RDI, RAX                                                ;0000000140001037 48 8B F8 
XOR EAX, EAX                                                ;000000014000103A 33 C0 
MOV ECX, 0x00000010                                         ;000000014000103C B9 10 00 00 00 
REP STOSB                                                   ;0000000140001041 F3 AA 
MOV dword ptr SS : [ RSP +  + 0x48 ], 0x00000000            ;0000000140001043 C7 44 24 48 00 00 00 00 
MOVSS XMM0, CS : [ RIP + 0x000442D9 ]                       ;000000014000104B F3 0F 10 05 D9 42 04 00 
MOVSS oword ptr SS : [ RSP +  + 0x4C ], XMM0                ;0000000140001053 F3 0F 11 44 24 4C 
MOVSS XMM0, CS : [ RIP + 0x000442CB ]                       ;0000000140001059 F3 0F 10 05 CB 42 04 00 
MOVSS oword ptr SS : [ RSP +  + 0x50 ], XMM0                ;0000000140001061 F3 0F 11 44 24 50 
MOV dword ptr SS : [ RSP +  + 0x30 ], 0x00000000            ;0000000140001067 C7 44 24 30 00 00 00 00 
JMP 0x0A                                                    ;000000014000106F EB 0A 
MOV EAX, dword ptr SS : [ RSP +  + 0x30 ]                   ;0000000140001071 8B 44 24 30 
INC EAX                                                     ;0000000140001075 FF C0 
MOV dword ptr SS : [ RSP +  + 0x30 ], EAX                   ;0000000140001077 89 44 24 30 
CMP dword ptr SS : [ RSP +  + 0x30 ], 0x02                  ;000000014000107B 83 7C 24 30 02 
JAE 0x00000461                                              ;0000000140001080 0F 83 61 04 00 00 
MOVSS XMM0, CS : [ RIP + 0x000442C6 ]                       ;0000000140001086 F3 0F 10 05 C6 42 04 00 
MOVSS oword ptr SS : [ RSP +  + 0x20 ], XMM0                ;000000014000108E F3 0F 11 44 24 20 
MOV dword ptr SS : [ RSP +  + 0x24 ], 0x00000000            ;0000000140001094 C7 44 24 24 00 00 00 00 
JMP 0x0A                                                    ;000000014000109C EB 0A 
MOV EAX, dword ptr SS : [ RSP +  + 0x24 ]                   ;000000014000109E 8B 44 24 24 
INC EAX                                                     ;00000001400010A2 FF C0 
MOV dword ptr SS : [ RSP +  + 0x24 ], EAX                   ;00000001400010A4 89 44 24 24 
MOV RAX, qword ptr SS : [ RSP +  + 0x000001C8 ]             ;00000001400010A8 48 8B 84 24 C8 01 00 00 
MOV EAX, dword ptr DS : [ RAX + 0x10 ]                      ;00000001400010B0 8B 40 10 
CMP dword ptr SS : [ RSP +  + 0x24 ], EAX                   ;00000001400010B3 39 44 24 24 
JAE 0x00000130                                              ;00000001400010B7 0F 83 30 01 00 00 
MOV EAX, dword ptr SS : [ RSP +  + 0x24 ]                   ;00000001400010BD 8B 44 24 24 
IMUL RAX, RAX, 0x14                                         ;00000001400010C1 48 6B C0 14 
MOV RCX, qword ptr SS : [ RSP +  + 0x000001C8 ]             ;00000001400010C5 48 8B 8C 24 C8 01 00 00 
ADD RAX, qword ptr DS : [ RCX + 0x18 ]                      ;00000001400010CD 48 03 41 18 
MOV qword ptr SS : [ RSP +  + 0x58 ], RAX                   ;00000001400010D1 48 89 44 24 58 
LEA RAX, invalid ptr SS : [ RSP +  + 0x00000090 ]           ;00000001400010D6 48 8D 84 24 90 00 00 00 
MOV RDI, RAX                                                ;00000001400010DE 48 8B F8 
MOV RSI, qword ptr SS : [ RSP +  + 0x000001D8 ]             ;00000001400010E1 48 8B B4 24 D8 01 00 00 
MOV ECX, 0x0000000C                                         ;00000001400010E9 B9 0C 00 00 00 
REP MOVSB                                                   ;00000001400010EE F3 A4 
LEA RAX, invalid ptr SS : [ RSP +  + 0x000000A0 ]           ;00000001400010F0 48 8D 84 24 A0 00 00 00 
MOV RCX, qword ptr SS : [ RSP +  + 0x58 ]                   ;00000001400010F8 48 8B 4C 24 58 
MOV RDI, RAX                                                ;00000001400010FD 48 8B F8 
LEA RSI, invalid ptr DS : [ RCX + 0x04 ]                    ;0000000140001100 48 8D 71 04 
MOV ECX, 0x0000000C                                         ;0000000140001104 B9 0C 00 00 00 
REP MOVSB                                                   ;0000000140001109 F3 A4 
LEA RDX, invalid ptr SS : [ RSP +  + 0x00000090 ]           ;000000014000110B 48 8D 94 24 90 00 00 00 
LEA RCX, invalid ptr SS : [ RSP +  + 0x000000A0 ]           ;0000000140001113 48 8D 8C 24 A0 00 00 00 
CALL 0x000017B0                                             ;000000014000111B E8 B0 17 00 00 
MOVSS oword ptr SS : [ RSP +  + 0x34 ], XMM0                ;0000000140001120 F3 0F 11 44 24 34 
MOVSS XMM0, oword ptr SS : [ RSP +  + 0x4C ]                ;0000000140001126 F3 0F 10 44 24 4C 
XORPS XMM0, CS : [ RIP + 0x0004422D ]                       ;000000014000112C 0F 57 05 2D 42 04 00 
COMISS XMM0, oword ptr SS : [ RSP +  + 0x34 ]               ;0000000140001133 0F 2F 44 24 34 
JAE 0x11                                                    ;0000000140001138 73 11 
MOVSS XMM0, oword ptr SS : [ RSP +  + 0x34 ]                ;000000014000113A F3 0F 10 44 24 34 
COMISS XMM0, oword ptr SS : [ RSP +  + 0x4C ]               ;0000000140001140 0F 2F 44 24 4C 
JB 0x0000009D                                               ;0000000140001145 0F 82 9D 00 00 00 
LEA RAX, invalid ptr SS : [ RSP +  + 0x000000B0 ]           ;000000014000114B 48 8D 84 24 B0 00 00 00 
MOV RDI, RAX                                                ;0000000140001153 48 8B F8 
MOV RSI, qword ptr SS : [ RSP +  + 0x000001D0 ]             ;0000000140001156 48 8B B4 24 D0 01 00 00 
MOV ECX, 0x0000000C                                         ;000000014000115E B9 0C 00 00 00 
REP MOVSB                                                   ;0000000140001163 F3 A4 
LEA RAX, invalid ptr SS : [ RSP +  + 0x000000C0 ]           ;0000000140001165 48 8D 84 24 C0 00 00 00 
MOV RCX, qword ptr SS : [ RSP +  + 0x58 ]                   ;000000014000116D 48 8B 4C 24 58 
MOV RDI, RAX                                                ;0000000140001172 48 8B F8 
LEA RSI, invalid ptr DS : [ RCX + 0x04 ]                    ;0000000140001175 48 8D 71 04 
MOV ECX, 0x0000000C                                         ;0000000140001179 B9 0C 00 00 00 
REP MOVSB                                                   ;000000014000117E F3 A4 
LEA RDX, invalid ptr SS : [ RSP +  + 0x000000B0 ]           ;0000000140001180 48 8D 94 24 B0 00 00 00 
LEA RCX, invalid ptr SS : [ RSP +  + 0x000000C0 ]           ;0000000140001188 48 8D 8C 24 C0 00 00 00 
CALL 0x0000173B                                             ;0000000140001190 E8 3B 17 00 00 
MOVSS oword ptr SS : [ RSP +  + 0x60 ], XMM0                ;0000000140001195 F3 0F 11 44 24 60 
MOV RAX, qword ptr SS : [ RSP +  + 0x58 ]                   ;000000014000119B 48 8B 44 24 58 
MOVSS XMM0, oword ptr DS : [ RAX + 0x10 ]                   ;00000001400011A0 F3 0F 10 40 10 
SUBSS XMM0, oword ptr SS : [ RSP +  + 0x60 ]                ;00000001400011A5 F3 0F 5C 44 24 60 
DIVSS XMM0, oword ptr SS : [ RSP +  + 0x34 ]                ;00000001400011AB F3 0F 5E 44 24 34 
MOVSS oword ptr SS : [ RSP +  + 0x38 ], XMM0                ;00000001400011B1 F3 0F 11 44 24 38 
MOVSS XMM0, oword ptr SS : [ RSP +  + 0x38 ]                ;00000001400011B7 F3 0F 10 44 24 38 
COMISS XMM0, oword ptr SS : [ RSP +  + 0x50 ]               ;00000001400011BD 0F 2F 44 24 50 
JB 0x24                                                     ;00000001400011C2 72 24 
MOVSS XMM0, oword ptr SS : [ RSP +  + 0x20 ]                ;00000001400011C4 F3 0F 10 44 24 20 
COMISS XMM0, oword ptr SS : [ RSP +  + 0x38 ]               ;00000001400011CA 0F 2F 44 24 38 
JBE 0x17                                                    ;00000001400011CF 76 17 
MOVSS XMM0, oword ptr SS : [ RSP +  + 0x38 ]                ;00000001400011D1 F3 0F 10 44 24 38 
MOVSS oword ptr SS : [ RSP +  + 0x20 ], XMM0                ;00000001400011D7 F3 0F 11 44 24 20 
MOV RAX, qword ptr SS : [ RSP +  + 0x58 ]                   ;00000001400011DD 48 8B 44 24 58 
MOV EAX, dword ptr DS : [ RAX ]                             ;00000001400011E2 8B 00 
MOV dword ptr SS : [ RSP +  + 0x48 ], EAX                   ;00000001400011E4 89 44 24 48 
JMP 0xFFFFFEB1                                              ;00000001400011E8 E9 B1 FE FF FF 
MOV dword ptr SS : [ RSP +  + 0x28 ], 0x00000000            ;00000001400011ED C7 44 24 28 00 00 00 00 
JMP 0x0A                                                    ;00000001400011F5 EB 0A 
MOV EAX, dword ptr SS : [ RSP +  + 0x28 ]                   ;00000001400011F7 8B 44 24 28 
INC EAX                                                     ;00000001400011FB FF C0 
MOV dword ptr SS : [ RSP +  + 0x28 ], EAX                   ;00000001400011FD 89 44 24 28 
MOV RAX, qword ptr SS : [ RSP +  + 0x000001C8 ]             ;0000000140001201 48 8B 84 24 C8 01 00 00 
MOV EAX, dword ptr DS : [ RAX ]                             ;0000000140001209 8B 00 
CMP dword ptr SS : [ RSP +  + 0x28 ], EAX                   ;000000014000120B 39 44 24 28 
JAE 0x000002C0                                              ;000000014000120F 0F 83 C0 02 00 00 
MOV EAX, dword ptr SS : [ RSP +  + 0x28 ]                   ;0000000140001215 8B 44 24 28 
IMUL RAX, RAX, 0x14                                         ;0000000140001219 48 6B C0 14 
MOV RCX, qword ptr SS : [ RSP +  + 0x000001C8 ]             ;000000014000121D 48 8B 8C 24 C8 01 00 00 
ADD RAX, qword ptr DS : [ RCX + 0x08 ]                      ;0000000140001225 48 03 41 08 
MOV qword ptr SS : [ RSP +  + 0x78 ], RAX                   ;0000000140001229 48 89 44 24 78 
LEA RAX, invalid ptr SS : [ RSP +  + 0x000000D0 ]           ;000000014000122E 48 8D 84 24 D0 00 00 00 
MOV RCX, qword ptr SS : [ RSP +  + 0x78 ]                   ;0000000140001236 48 8B 4C 24 78 
MOV RDI, RAX                                                ;000000014000123B 48 8B F8 
LEA RSI, invalid ptr DS : [ RCX + 0x04 ]                    ;000000014000123E 48 8D 71 04 
MOV ECX, 0x0000000C                                         ;0000000140001242 B9 0C 00 00 00 
REP MOVSB                                                   ;0000000140001247 F3 A4 
LEA RAX, invalid ptr SS : [ RSP +  + 0x000000E0 ]           ;0000000140001249 48 8D 84 24 E0 00 00 00 
MOV RDI, RAX                                                ;0000000140001251 48 8B F8 
MOV RSI, qword ptr SS : [ RSP +  + 0x000001D0 ]             ;0000000140001254 48 8B B4 24 D0 01 00 00 
MOV ECX, 0x0000000C                                         ;000000014000125C B9 0C 00 00 00 
REP MOVSB                                                   ;0000000140001261 F3 A4 
LEA R8, invalid ptr SS : [ RSP +  + 0x000000D0 ]            ;0000000140001263 4C 8D 84 24 D0 00 00 00 
LEA RDX, invalid ptr SS : [ RSP +  + 0x000000E0 ]           ;000000014000126B 48 8D 94 24 E0 00 00 00 
LEA RCX, invalid ptr SS : [ RSP +  + 0x00000150 ]           ;0000000140001273 48 8D 8C 24 50 01 00 00 
CALL 0x00001410                                             ;000000014000127B E8 10 14 00 00 
LEA RCX, invalid ptr SS : [ RSP +  + 0x00000180 ]           ;0000000140001280 48 8D 8C 24 80 01 00 00 
MOV RDI, RCX                                                ;0000000140001288 48 8B F9 
MOV RSI, RAX                                                ;000000014000128B 48 8B F0 
MOV ECX, 0x0000000C                                         ;000000014000128E B9 0C 00 00 00 
REP MOVSB                                                   ;0000000140001293 F3 A4 
LEA RAX, invalid ptr SS : [ RSP +  + 0x00000160 ]           ;0000000140001295 48 8D 84 24 60 01 00 00 
LEA RCX, invalid ptr SS : [ RSP +  + 0x00000180 ]           ;000000014000129D 48 8D 8C 24 80 01 00 00 
MOV RDI, RAX                                                ;00000001400012A5 48 8B F8 
MOV RSI, RCX                                                ;00000001400012A8 48 8B F1 
MOV ECX, 0x0000000C                                         ;00000001400012AB B9 0C 00 00 00 
REP MOVSB                                                   ;00000001400012B0 F3 A4 
LEA RAX, invalid ptr SS : [ RSP +  + 0x000000F0 ]           ;00000001400012B2 48 8D 84 24 F0 00 00 00 
MOV RDI, RAX                                                ;00000001400012BA 48 8B F8 
MOV RSI, qword ptr SS : [ RSP +  + 0x000001D8 ]             ;00000001400012BD 48 8B B4 24 D8 01 00 00 
MOV ECX, 0x0000000C                                         ;00000001400012C5 B9 0C 00 00 00 
REP MOVSB                                                   ;00000001400012CA F3 A4 
LEA RAX, invalid ptr SS : [ RSP +  + 0x00000100 ]           ;00000001400012CC 48 8D 84 24 00 01 00 00 
MOV RDI, RAX                                                ;00000001400012D4 48 8B F8 
MOV RSI, qword ptr SS : [ RSP +  + 0x000001D8 ]             ;00000001400012D7 48 8B B4 24 D8 01 00 00 
MOV ECX, 0x0000000C                                         ;00000001400012DF B9 0C 00 00 00 
REP MOVSB                                                   ;00000001400012E4 F3 A4 
LEA RDX, invalid ptr SS : [ RSP +  + 0x000000F0 ]           ;00000001400012E6 48 8D 94 24 F0 00 00 00 
LEA RCX, invalid ptr SS : [ RSP +  + 0x00000100 ]           ;00000001400012EE 48 8D 8C 24 00 01 00 00 
CALL 0x000015D5                                             ;00000001400012F6 E8 D5 15 00 00 
MOVSS oword ptr SS : [ RSP +  + 0x40 ], XMM0                ;00000001400012FB F3 0F 11 44 24 40 
LEA RAX, invalid ptr SS : [ RSP +  + 0x00000110 ]           ;0000000140001301 48 8D 84 24 10 01 00 00 
MOV RDI, RAX                                                ;0000000140001309 48 8B F8 
MOV RSI, qword ptr SS : [ RSP +  + 0x000001D8 ]             ;000000014000130C 48 8B B4 24 D8 01 00 00 
MOV ECX, 0x0000000C                                         ;0000000140001314 B9 0C 00 00 00 
REP MOVSB                                                   ;0000000140001319 F3 A4 
LEA RAX, invalid ptr SS : [ RSP +  + 0x00000120 ]           ;000000014000131B 48 8D 84 24 20 01 00 00 
LEA RCX, invalid ptr SS : [ RSP +  + 0x00000160 ]           ;0000000140001323 48 8D 8C 24 60 01 00 00 
MOV RDI, RAX                                                ;000000014000132B 48 8B F8 
MOV RSI, RCX                                                ;000000014000132E 48 8B F1 
MOV ECX, 0x0000000C                                         ;0000000140001331 B9 0C 00 00 00 
REP MOVSB                                                   ;0000000140001336 F3 A4 
LEA RDX, invalid ptr SS : [ RSP +  + 0x00000110 ]           ;0000000140001338 48 8D 94 24 10 01 00 00 
LEA RCX, invalid ptr SS : [ RSP +  + 0x00000120 ]           ;0000000140001340 48 8D 8C 24 20 01 00 00 
CALL 0x00001583                                             ;0000000140001348 E8 83 15 00 00 
MOVSS XMM1, CS : [ RIP + 0x00043FE3 ]                       ;000000014000134D F3 0F 10 0D E3 3F 04 00 
MULSS XMM1, XMM0                                            ;0000000140001355 F3 0F 59 C8 
MOVAPS XMM0, XMM1                                           ;0000000140001359 0F 28 C1 
MOVSS oword ptr SS : [ RSP +  + 0x2C ], XMM0                ;000000014000135C F3 0F 11 44 24 2C 
LEA RAX, invalid ptr SS : [ RSP +  + 0x00000130 ]           ;0000000140001362 48 8D 84 24 30 01 00 00 
LEA RCX, invalid ptr SS : [ RSP +  + 0x00000160 ]           ;000000014000136A 48 8D 8C 24 60 01 00 00 
MOV RDI, RAX                                                ;0000000140001372 48 8B F8 
MOV RSI, RCX                                                ;0000000140001375 48 8B F1 
MOV ECX, 0x0000000C                                         ;0000000140001378 B9 0C 00 00 00 
REP MOVSB                                                   ;000000014000137D F3 A4 
LEA RAX, invalid ptr SS : [ RSP +  + 0x00000140 ]           ;000000014000137F 48 8D 84 24 40 01 00 00 
LEA RCX, invalid ptr SS : [ RSP +  + 0x00000160 ]           ;0000000140001387 48 8D 8C 24 60 01 00 00 
MOV RDI, RAX                                                ;000000014000138F 48 8B F8 
MOV RSI, RCX                                                ;0000000140001392 48 8B F1 
MOV ECX, 0x0000000C                                         ;0000000140001395 B9 0C 00 00 00 
REP MOVSB                                                   ;000000014000139A F3 A4 
LEA RDX, invalid ptr SS : [ RSP +  + 0x00000130 ]           ;000000014000139C 48 8D 94 24 30 01 00 00 
LEA RCX, invalid ptr SS : [ RSP +  + 0x00000140 ]           ;00000001400013A4 48 8D 8C 24 40 01 00 00 
CALL 0x0000151F                                             ;00000001400013AC E8 1F 15 00 00 
MOVSS oword ptr SS : [ RSP +  + 0x64 ], XMM0                ;00000001400013B1 F3 0F 11 44 24 64 
MOV RAX, qword ptr SS : [ RSP +  + 0x78 ]                   ;00000001400013B7 48 8B 44 24 78 
MOVSS XMM0, oword ptr DS : [ RAX + 0x10 ]                   ;00000001400013BC F3 0F 10 40 10 
CALL 0x0000170A                                             ;00000001400013C1 E8 0A 17 00 00 
MOVSS XMM1, oword ptr SS : [ RSP +  + 0x64 ]                ;00000001400013C6 F3 0F 10 4C 24 64 
SUBSS XMM1, XMM0                                            ;00000001400013CC F3 0F 5C C8 
MOVAPS XMM0, XMM1                                           ;00000001400013D0 0F 28 C1 
MOVSS oword ptr SS : [ RSP +  + 0x68 ], XMM0                ;00000001400013D3 F3 0F 11 44 24 68 
MOVSS XMM0, oword ptr SS : [ RSP +  + 0x2C ]                ;00000001400013D9 F3 0F 10 44 24 2C 
MULSS XMM0, oword ptr SS : [ RSP +  + 0x2C ]                ;00000001400013DF F3 0F 59 44 24 2C 
MOVSS XMM1, CS : [ RIP + 0x00043F5B ]                       ;00000001400013E5 F3 0F 10 0D 5B 3F 04 00 
MULSS XMM1, oword ptr SS : [ RSP +  + 0x40 ]                ;00000001400013ED F3 0F 59 4C 24 40 
MULSS XMM1, oword ptr SS : [ RSP +  + 0x68 ]                ;00000001400013F3 F3 0F 59 4C 24 68 
SUBSS XMM0, XMM1                                            ;00000001400013F9 F3 0F 5C C1 
MOVSS oword ptr SS : [ RSP +  + 0x3C ], XMM0                ;00000001400013FD F3 0F 11 44 24 3C 
MOVSS XMM0, oword ptr SS : [ RSP +  + 0x3C ]                ;0000000140001403 F3 0F 10 44 24 3C 
COMISS XMM0, CS : [ RIP + 0x00043F18 ]                      ;0000000140001409 0F 2F 05 18 3F 04 00 
JB 0x000000BA                                               ;0000000140001410 0F 82 BA 00 00 00 
MOVSS XMM0, oword ptr SS : [ RSP +  + 0x2C ]                ;0000000140001416 F3 0F 10 44 24 2C 
XORPS XMM0, CS : [ RIP + 0x00043F3D ]                       ;000000014000141C 0F 57 05 3D 3F 04 00 
MOVSS oword ptr SS : [ RSP +  + 0x6C ], XMM0                ;0000000140001423 F3 0F 11 44 24 6C 
MOVSS XMM0, oword ptr SS : [ RSP +  + 0x3C ]                ;0000000140001429 F3 0F 10 44 24 3C 
CALL 0x000016CC                                             ;000000014000142F E8 CC 16 00 00 
MOVSS XMM1, oword ptr SS : [ RSP +  + 0x6C ]                ;0000000140001434 F3 0F 10 4C 24 6C 
ADDSS XMM1, XMM0                                            ;000000014000143A F3 0F 58 C8 
MOVAPS XMM0, XMM1                                           ;000000014000143E 0F 28 C1 
MOVSS XMM1, CS : [ RIP + 0x00043EEF ]                       ;0000000140001441 F3 0F 10 0D EF 3E 04 00 
MULSS XMM1, oword ptr SS : [ RSP +  + 0x40 ]                ;0000000140001449 F3 0F 59 4C 24 40 
DIVSS XMM0, XMM1                                            ;000000014000144F F3 0F 5E C1 
MOVSS oword ptr SS : [ RSP +  + 0x00000080 ], XMM0          ;0000000140001453 F3 0F 11 84 24 80 00 00 00 
MOVSS XMM0, oword ptr SS : [ RSP +  + 0x2C ]                ;000000014000145C F3 0F 10 44 24 2C 
XORPS XMM0, CS : [ RIP + 0x00043EF7 ]                       ;0000000140001462 0F 57 05 F7 3E 04 00 
MOVSS oword ptr SS : [ RSP +  + 0x70 ], XMM0                ;0000000140001469 F3 0F 11 44 24 70 
MOVSS XMM0, oword ptr SS : [ RSP +  + 0x3C ]                ;000000014000146F F3 0F 10 44 24 3C 
CALL 0x00001686                                             ;0000000140001475 E8 86 16 00 00 
MOVSS XMM1, oword ptr SS : [ RSP +  + 0x70 ]                ;000000014000147A F3 0F 10 4C 24 70 
SUBSS XMM1, XMM0                                            ;0000000140001480 F3 0F 5C C8 
MOVAPS XMM0, XMM1                                           ;0000000140001484 0F 28 C1 
MOVSS XMM1, CS : [ RIP + 0x00043EA9 ]                       ;0000000140001487 F3 0F 10 0D A9 3E 04 00 
MULSS XMM1, oword ptr SS : [ RSP +  + 0x40 ]                ;000000014000148F F3 0F 59 4C 24 40 
DIVSS XMM0, XMM1                                            ;0000000140001495 F3 0F 5E C1 
MOVSS oword ptr SS : [ RSP +  + 0x44 ], XMM0                ;0000000140001499 F3 0F 11 44 24 44 
MOVSS XMM0, oword ptr SS : [ RSP +  + 0x44 ]                ;000000014000149F F3 0F 10 44 24 44 
COMISS XMM0, oword ptr SS : [ RSP +  + 0x50 ]               ;00000001400014A5 0F 2F 44 24 50 
JB 0x24                                                     ;00000001400014AA 72 24 
MOVSS XMM0, oword ptr SS : [ RSP +  + 0x20 ]                ;00000001400014AC F3 0F 10 44 24 20 
COMISS XMM0, oword ptr SS : [ RSP +  + 0x44 ]               ;00000001400014B2 0F 2F 44 24 44 
JBE 0x17                                                    ;00000001400014B7 76 17 
MOVSS XMM0, oword ptr SS : [ RSP +  + 0x44 ]                ;00000001400014B9 F3 0F 10 44 24 44 
MOVSS oword ptr SS : [ RSP +  + 0x20 ], XMM0                ;00000001400014BF F3 0F 11 44 24 20 
MOV RAX, qword ptr SS : [ RSP +  + 0x78 ]                   ;00000001400014C5 48 8B 44 24 78 
MOV EAX, dword ptr DS : [ RAX ]                             ;00000001400014CA 8B 00 
MOV dword ptr SS : [ RSP +  + 0x48 ], EAX                   ;00000001400014CC 89 44 24 48 
JMP 0xFFFFFD22                                              ;00000001400014D0 E9 22 FD FF FF 
MOVSS XMM0, oword ptr SS : [ RSP +  + 0x20 ]                ;00000001400014D5 F3 0F 10 44 24 20 
UCOMISS XMM0, CS : [ RIP + 0x00043E72 ]                     ;00000001400014DB 0F 2E 05 72 3E 04 00 
JMP 0xFFFFFB8A                                              ;00000001400014E2 E9 8A FB FF FF 
MOV EAX, dword ptr SS : [ RSP +  + 0x48 ]                   ;00000001400014E7 8B 44 24 48 
IMUL RAX, RAX, 0x10                                         ;00000001400014EB 48 6B C0 10 
MOV RCX, qword ptr SS : [ RSP +  + 0x000001C8 ]             ;00000001400014EF 48 8B 8C 24 C8 01 00 00 
MOV RCX, qword ptr DS : [ RCX + 0x28 ]                      ;00000001400014F7 48 8B 49 28 
LEA RDX, invalid ptr SS : [ RSP +  + 0x00000170 ]           ;00000001400014FB 48 8D 94 24 70 01 00 00 
MOV RDI, RDX                                                ;0000000140001503 48 8B FA 
LEA RSI, invalid ptr DS : [ RCX + RAX * 1 ]                 ;0000000140001506 48 8D 34 01 
MOV ECX, 0x00000010                                         ;000000014000150A B9 10 00 00 00 
REP MOVSB                                                   ;000000014000150F F3 A4 
LEA RAX, invalid ptr SS : [ RSP +  + 0x00000170 ]           ;0000000140001511 48 8D 84 24 70 01 00 00 
MOV RDI, qword ptr SS : [ RSP +  + 0x000001C0 ]             ;0000000140001519 48 8B BC 24 C0 01 00 00 
MOV RSI, RAX                                                ;0000000140001521 48 8B F0 
MOV ECX, 0x00000010                                         ;0000000140001524 B9 10 00 00 00 
REP MOVSB                                                   ;0000000140001529 F3 A4 
MOV RAX, qword ptr SS : [ RSP +  + 0x000001C0 ]             ;000000014000152B 48 8B 84 24 C0 01 00 00 
MOV RCX, qword ptr SS : [ RSP +  + 0x00000190 ]             ;0000000140001533 48 8B 8C 24 90 01 00 00 
XOR RCX, RSP                                                ;000000014000153B 48 33 CC 
CALL 0x0000190D                                             ;000000014000153E E8 0D 19 00 00 
ADD RSP, 0x000001A8                                         ;0000000140001543 48 81 C4 A8 01 00 00 
POP EDI                                                     ;000000014000154A 5F 
POP ESI                                                     ;000000014000154B 5E 
RETN                                                        ;000000014000154C C3 
INT 3                                                       ;000000014000154D CC 
INT 3                                                       ;000000014000154E CC 
INT 3                                                       ;000000014000154F CC 
INT 3                                                       ;0000000140001550 CC 
INT 3                                                       ;0000000140001551 CC 
INT 3                                                       ;0000000140001552 CC 
INT 3                                                       ;0000000140001553 CC 
INT 3                                                       ;0000000140001554 CC 
INT 3                                                       ;0000000140001555 CC 
INT 3                                                       ;0000000140001556 CC 
INT 3                                                       ;0000000140001557 CC 
INT 3                                                       ;0000000140001558 CC 
INT 3                                                       ;0000000140001559 CC 
INT 3                                                       ;000000014000155A CC 
INT 3                                                       ;000000014000155B CC 
INT 3                                                       ;000000014000155C CC 
INT 3                                                       ;000000014000155D CC 
INT 3                                                       ;000000014000155E CC 
INT 3                                                       ;000000014000155F CC 
MOV qword ptr SS : [ RSP +  + 0x10 ], RDX                   ;0000000140001560 48 89 54 24 10 
MOV dword ptr SS : [ RSP +  + 0x08 ], ECX                   ;0000000140001565 89 4C 24 08 
PUSH ESI                                                    ;0000000140001569 56 
PUSH EDI                                                    ;000000014000156A 57 
SUB RSP, 0x000006C8                                         ;000000014000156B 48 81 EC C8 06 00 00 
MOV RAX, CS : [ RIP + 0x00058A8F ]                          ;0000000140001572 48 8B 05 8F 8A 05 00 
XOR RAX, RSP                                                ;0000000140001579 48 33 C4 
MOV qword ptr SS : [ RSP +  + 0x000006B0 ], RAX             ;000000014000157C 48 89 84 24 B0 06 00 00 
MOVSD XMM0, CS : [ RIP + 0x00043DB4 ]                       ;0000000140001584 F2 0F 10 05 B4 3D 04 00 
MOVSD oword ptr SS : [ RSP +  + 0x00000230 ], XMM0          ;000000014000158C F2 0F 11 84 24 30 02 00 00 
LEA RCX, CS : [ RIP + 0x00043D64 ]                          ;0000000140001595 48 8D 0D 64 3D 04 00 
CALL 0x000016FF                                             ;000000014000159C E8 FF 16 00 00 
LEA RAX, invalid ptr SS : [ RSP +  + 0x40 ]                 ;00000001400015A1 48 8D 44 24 40 
MOV RDI, RAX                                                ;00000001400015A6 48 8B F8 
XOR EAX, EAX                                                ;00000001400015A9 33 C0 
MOV ECX, 0x00000018                                         ;00000001400015AB B9 18 00 00 00 
REP STOSB                                                   ;00000001400015B0 F3 AA 
MOV dword ptr SS : [ RSP +  + 0x40 ], 0x000003C0            ;00000001400015B2 C7 44 24 40 C0 03 00 00 
MOV dword ptr SS : [ RSP +  + 0x44 ], 0x0000021C            ;00000001400015BA C7 44 24 44 1C 02 00 00 
MOV EAX, dword ptr SS : [ RSP +  + 0x40 ]                   ;00000001400015C2 8B 44 24 40 
SAL EAX, 0x02                                               ;00000001400015C6 C1 E0 02 
MOV dword ptr SS : [ RSP +  + 0x48 ], EAX                   ;00000001400015C9 89 44 24 48 
MOV EAX, dword ptr SS : [ RSP +  + 0x40 ]                   ;00000001400015CD 8B 44 24 40 
SAL EAX, 0x02                                               ;00000001400015D1 C1 E0 02 
IMUL EAX, dword ptr SS : [ RSP +  + 0x44 ]                  ;00000001400015D4 0F AF 44 24 44 
MOV dword ptr SS : [ RSP +  + 0x38 ], EAX                   ;00000001400015D9 89 44 24 38 
MOV EAX, dword ptr SS : [ RSP +  + 0x38 ]                   ;00000001400015DD 8B 44 24 38 
MOV ECX, EAX                                                ;00000001400015E1 8B C8 
CALL 0x00014438                                             ;00000001400015E3 E8 38 44 01 00 
MOV qword ptr SS : [ RSP +  + 0x50 ], RAX                   ;00000001400015E8 48 89 44 24 50 
MOV EAX, dword ptr SS : [ RSP +  + 0x38 ]                   ;00000001400015ED 8B 44 24 38 
MOV qword ptr SS : [ RSP +  + 0x00000098 ], RAX             ;00000001400015F1 48 89 84 24 98 00 00 00 
MOV RDI, qword ptr SS : [ RSP +  + 0x50 ]                   ;00000001400015F9 48 8B 7C 24 50 
XOR EAX, EAX                                                ;00000001400015FE 33 C0 
MOV RCX, qword ptr SS : [ RSP +  + 0x00000098 ]             ;0000000140001600 48 8B 8C 24 98 00 00 00 
REP STOSB                                                   ;0000000140001608 F3 AA 
XORPS XMM0, XMM0                                            ;000000014000160A 0F 57 C0 
MOVSS oword ptr SS : [ RSP +  + 0x00000670 ], XMM0          ;000000014000160D F3 0F 11 84 24 70 06 00 00 
LEA RAX, invalid ptr SS : [ RSP +  + 0x00000674 ]           ;0000000140001616 48 8D 84 24 74 06 00 00 
MOV RDI, RAX                                                ;000000014000161E 48 8B F8 
XOR EAX, EAX                                                ;0000000140001621 33 C0 
MOV ECX, 0x0000003C                                         ;0000000140001623 B9 3C 00 00 00 
REP STOSB                                                   ;0000000140001628 F3 AA 
MOVSS XMM0, CS : [ RIP + 0x00043D02 ]                       ;000000014000162A F3 0F 10 05 02 3D 04 00 
MOVSS oword ptr SS : [ RSP +  + 0x20 ], XMM0                ;0000000140001632 F3 0F 11 44 24 20 
MOVSS XMM3, CS : [ RIP + 0x00043CF0 ]                       ;0000000140001638 F3 0F 10 1D F0 3C 04 00 
MOVSS XMM2, CS : [ RIP + 0x00043CE8 ]                       ;0000000140001640 F3 0F 10 15 E8 3C 04 00 
MOVSS XMM1, CS : [ RIP + 0x00043CE0 ]                       ;0000000140001648 F3 0F 10 0D E0 3C 04 00 
LEA RCX, invalid ptr SS : [ RSP +  + 0x00000358 ]           ;0000000140001650 48 8D 8C 24 58 03 00 00 
CALL 0x00001553                                             ;0000000140001658 E8 53 15 00 00 
LEA RCX, invalid ptr SS : [ RSP +  + 0x000005F0 ]           ;000000014000165D 48 8D 8C 24 F0 05 00 00 
MOV RDI, RCX                                                ;0000000140001665 48 8B F9 
MOV RSI, RAX                                                ;0000000140001668 48 8B F0 
MOV ECX, 0x00000010                                         ;000000014000166B B9 10 00 00 00 
REP MOVSB                                                   ;0000000140001670 F3 A4 
MOV EAX, 0x00000010                                         ;0000000140001672 B8 10 00 00 00 
IMUL RAX, RAX, 0x00                                         ;0000000140001677 48 6B C0 00 
LEA RCX, invalid ptr SS : [ RSP +  + 0x000005F0 ]           ;000000014000167B 48 8D 8C 24 F0 05 00 00 
LEA RDI, invalid ptr SS : [ RSP + RAX * 1 + 0x00000670 ]    ;0000000140001683 48 8D BC 04 70 06 00 00 
MOV RSI, RCX                                                ;000000014000168B 48 8B F1 
MOV ECX, 0x00000010                                         ;000000014000168E B9 10 00 00 00 
REP MOVSB                                                   ;0000000140001693 F3 A4 
MOVSS XMM0, CS : [ RIP + 0x00043C97 ]                       ;0000000140001695 F3 0F 10 05 97 3C 04 00 
MOVSS oword ptr SS : [ RSP +  + 0x20 ], XMM0                ;000000014000169D F3 0F 11 44 24 20 
XORPS XMM3, XMM3                                            ;00000001400016A3 0F 57 DB 
XORPS XMM2, XMM2                                            ;00000001400016A6 0F 57 D2 
MOVSS XMM1, CS : [ RIP + 0x00043C83 ]                       ;00000001400016A9 F3 0F 10 0D 83 3C 04 00 
LEA RCX, invalid ptr SS : [ RSP +  + 0x00000368 ]           ;00000001400016B1 48 8D 8C 24 68 03 00 00 
CALL 0x000014F2                                             ;00000001400016B9 E8 F2 14 00 00 
LEA RCX, invalid ptr SS : [ RSP +  + 0x000005E0 ]           ;00000001400016BE 48 8D 8C 24 E0 05 00 00 
MOV RDI, RCX                                                ;00000001400016C6 48 8B F9 
MOV RSI, RAX                                                ;00000001400016C9 48 8B F0 
MOV ECX, 0x00000010                                         ;00000001400016CC B9 10 00 00 00 
REP MOVSB                                                   ;00000001400016D1 F3 A4 
MOV EAX, 0x00000010                                         ;00000001400016D3 B8 10 00 00 00 
IMUL RAX, RAX, 0x01                                         ;00000001400016D8 48 6B C0 01 
LEA RCX, invalid ptr SS : [ RSP +  + 0x000005E0 ]           ;00000001400016DC 48 8D 8C 24 E0 05 00 00 
LEA RDI, invalid ptr SS : [ RSP + RAX * 1 + 0x00000670 ]    ;00000001400016E4 48 8D BC 04 70 06 00 00 
MOV RSI, RCX                                                ;00000001400016EC 48 8B F1 
MOV ECX, 0x00000010                                         ;00000001400016EF B9 10 00 00 00 
REP MOVSB                                                   ;00000001400016F4 F3 A4 
MOVSS XMM0, CS : [ RIP + 0x00043C36 ]                       ;00000001400016F6 F3 0F 10 05 36 3C 04 00 
MOVSS oword ptr SS : [ RSP +  + 0x20 ], XMM0                ;00000001400016FE F3 0F 11 44 24 20 
XORPS XMM3, XMM3                                            ;0000000140001704 0F 57 DB 
MOVSS XMM2, CS : [ RIP + 0x00043C25 ]                       ;0000000140001707 F3 0F 10 15 25 3C 04 00 
XORPS XMM1, XMM1                                            ;000000014000170F 0F 57 C9 
LEA RCX, invalid ptr SS : [ RSP +  + 0x00000378 ]           ;0000000140001712 48 8D 8C 24 78 03 00 00 
CALL 0x00001491                                             ;000000014000171A E8 91 14 00 00 
LEA RCX, invalid ptr SS : [ RSP +  + 0x00000610 ]           ;000000014000171F 48 8D 8C 24 10 06 00 00 
MOV RDI, RCX                                                ;0000000140001727 48 8B F9 
MOV RSI, RAX                                                ;000000014000172A 48 8B F0 
MOV ECX, 0x00000010                                         ;000000014000172D B9 10 00 00 00 
REP MOVSB                                                   ;0000000140001732 F3 A4 
MOV EAX, 0x00000010                                         ;0000000140001734 B8 10 00 00 00 
IMUL RAX, RAX, 0x02                                         ;0000000140001739 48 6B C0 02 
LEA RCX, invalid ptr SS : [ RSP +  + 0x00000610 ]           ;000000014000173D 48 8D 8C 24 10 06 00 00 
LEA RDI, invalid ptr SS : [ RSP + RAX * 1 + 0x00000670 ]    ;0000000140001745 48 8D BC 04 70 06 00 00 
MOV RSI, RCX                                                ;000000014000174D 48 8B F1 
MOV ECX, 0x00000010                                         ;0000000140001750 B9 10 00 00 00 
REP MOVSB                                                   ;0000000140001755 F3 A4 
MOVSS XMM0, CS : [ RIP + 0x00043BD5 ]                       ;0000000140001757 F3 0F 10 05 D5 3B 04 00 
MOVSS oword ptr SS : [ RSP +  + 0x20 ], XMM0                ;000000014000175F F3 0F 11 44 24 20 
MOVSS XMM3, CS : [ RIP + 0x00043BC7 ]                       ;0000000140001765 F3 0F 10 1D C7 3B 04 00 
XORPS XMM2, XMM2                                            ;000000014000176D 0F 57 D2 
XORPS XMM1, XMM1                                            ;0000000140001770 0F 57 C9 
LEA RCX, invalid ptr SS : [ RSP +  + 0x00000388 ]           ;0000000140001773 48 8D 8C 24 88 03 00 00 
CALL 0x00001430                                             ;000000014000177B E8 30 14 00 00 
LEA RCX, invalid ptr SS : [ RSP +  + 0x00000600 ]           ;0000000140001780 48 8D 8C 24 00 06 00 00 
MOV RDI, RCX                                                ;0000000140001788 48 8B F9 
MOV RSI, RAX                                                ;000000014000178B 48 8B F0 
MOV ECX, 0x00000010                                         ;000000014000178E B9 10 00 00 00 
REP MOVSB                                                   ;0000000140001793 F3 A4 
MOV EAX, 0x00000010                                         ;0000000140001795 B8 10 00 00 00 
IMUL RAX, RAX, 0x03                                         ;000000014000179A 48 6B C0 03 
LEA RCX, invalid ptr SS : [ RSP +  + 0x00000600 ]           ;000000014000179E 48 8D 8C 24 00 06 00 00 
LEA RDI, invalid ptr SS : [ RSP + RAX * 1 + 0x00000670 ]    ;00000001400017A6 48 8D BC 04 70 06 00 00 
MOV RSI, RCX                                                ;00000001400017AE 48 8B F1 
MOV ECX, 0x00000010                                         ;00000001400017B1 B9 10 00 00 00 
REP MOVSB                                                   ;00000001400017B6 F3 A4 
MOV dword ptr SS : [ RSP +  + 0x00000648 ], 0x00000000      ;00000001400017B8 C7 84 24 48 06 00 00 00 00 00 00 
LEA RAX, invalid ptr SS : [ RSP +  + 0x0000064C ]           ;00000001400017C3 48 8D 84 24 4C 06 00 00 
MOV RDI, RAX                                                ;00000001400017CB 48 8B F8 
XOR EAX, EAX                                                ;00000001400017CE 33 C0 
MOV ECX, 0x00000024                                         ;00000001400017D0 B9 24 00 00 00 
REP STOSB                                                   ;00000001400017D5 F3 AA 
MOV EAX, 0x00000014                                         ;00000001400017D7 B8 14 00 00 00 
IMUL RAX, RAX, 0x00                                         ;00000001400017DC 48 6B C0 00 
XORPS XMM0, XMM0                                            ;00000001400017E0 0F 57 C0 
MOVSS oword ptr SS : [ RSP + RAX * 1 + 0x00000658 ], XMM0   ;00000001400017E3 F3 0F 11 84 04 58 06 00 00 
XORPS XMM3, XMM3                                            ;00000001400017EC 0F 57 DB 
MOVSS XMM2, CS : [ RIP + 0x00043B3D ]                       ;00000001400017EF F3 0F 10 15 3D 3B 04 00 
XORPS XMM1, XMM1                                            ;00000001400017F7 0F 57 C9 
LEA RCX, invalid ptr SS : [ RSP +  + 0x00000298 ]           ;00000001400017FA 48 8D 8C 24 98 02 00 00 
CALL 0x00001329                                             ;0000000140001802 E8 29 13 00 00 
LEA RCX, invalid ptr SS : [ RSP +  + 0x000004A0 ]           ;0000000140001807 48 8D 8C 24 A0 04 00 00 
MOV RDI, RCX                                                ;000000014000180F 48 8B F9 
MOV RSI, RAX                                                ;0000000140001812 48 8B F0 
MOV ECX, 0x0000000C                                         ;0000000140001815 B9 0C 00 00 00 
REP MOVSB                                                   ;000000014000181A F3 A4 
MOV EAX, 0x00000014                                         ;000000014000181C B8 14 00 00 00 
IMUL RAX, RAX, 0x00                                         ;0000000140001821 48 6B C0 00 
LEA RCX, invalid ptr SS : [ RSP +  + 0x000004A0 ]           ;0000000140001825 48 8D 8C 24 A0 04 00 00 
LEA RDI, invalid ptr SS : [ RSP + RAX * 1 + 0x0000064C ]    ;000000014000182D 48 8D BC 04 4C 06 00 00 
MOV RSI, RCX                                                ;0000000140001835 48 8B F1 
MOV ECX, 0x0000000C                                         ;0000000140001838 B9 0C 00 00 00 
REP MOVSB                                                   ;000000014000183D F3 A4 
MOV EAX, 0x00000014                                         ;000000014000183F B8 14 00 00 00 
IMUL RAX, RAX, 0x00                                         ;0000000140001844 48 6B C0 00 
MOV dword ptr SS : [ RSP + RAX * 1 + 0x00000648 ], 0x00000001;0000000140001848 C7 84 04 48 06 00 00 01 00 00 00 
MOV EAX, 0x00000014                                         ;0000000140001853 B8 14 00 00 00 
IMUL RAX, RAX, 0x01                                         ;0000000140001858 48 6B C0 01 
MOVSS XMM0, CS : [ RIP + 0x00043AF8 ]                       ;000000014000185C F3 0F 10 05 F8 3A 04 00 
MOVSS oword ptr SS : [ RSP + RAX * 1 + 0x00000658 ], XMM0   ;0000000140001864 F3 0F 11 84 04 58 06 00 00 
XORPS XMM3, XMM3                                            ;000000014000186D 0F 57 DB 
XORPS XMM2, XMM2                                            ;0000000140001870 0F 57 D2 
MOVSS XMM1, CS : [ RIP + 0x00043ADD ]                       ;0000000140001873 F3 0F 10 0D DD 3A 04 00 
LEA RCX, invalid ptr SS : [ RSP +  + 0x00000338 ]           ;000000014000187B 48 8D 8C 24 38 03 00 00 
CALL 0x000012A8                                             ;0000000140001883 E8 A8 12 00 00 
LEA RCX, invalid ptr SS : [ RSP +  + 0x00000490 ]           ;0000000140001888 48 8D 8C 24 90 04 00 00 
MOV RDI, RCX                                                ;0000000140001890 48 8B F9 
MOV RSI, RAX                                                ;0000000140001893 48 8B F0 
MOV ECX, 0x0000000C                                         ;0000000140001896 B9 0C 00 00 00 
REP MOVSB                                                   ;000000014000189B F3 A4 
MOV EAX, 0x00000014                                         ;000000014000189D B8 14 00 00 00 
IMUL RAX, RAX, 0x01                                         ;00000001400018A2 48 6B C0 01 
LEA RCX, invalid ptr SS : [ RSP +  + 0x00000490 ]           ;00000001400018A6 48 8D 8C 24 90 04 00 00 
LEA RDI, invalid ptr SS : [ RSP + RAX * 1 + 0x0000064C ]    ;00000001400018AE 48 8D BC 04 4C 06 00 00 
MOV RSI, RCX                                                ;00000001400018B6 48 8B F1 
MOV ECX, 0x0000000C                                         ;00000001400018B9 B9 0C 00 00 00 
REP MOVSB                                                   ;00000001400018BE F3 A4 
MOV EAX, 0x00000014                                         ;00000001400018C0 B8 14 00 00 00 
IMUL RAX, RAX, 0x01                                         ;00000001400018C5 48 6B C0 01 
MOV dword ptr SS : [ RSP + RAX * 1 + 0x00000648 ], 0x00000002;00000001400018C9 C7 84 04 48 06 00 00 02 00 00 00 
MOV dword ptr SS : [ RSP +  + 0x00000630 ], 0x00000000      ;00000001400018D4 C7 84 24 30 06 00 00 00 00 00 00 
LEA RAX, invalid ptr SS : [ RSP +  + 0x00000634 ]           ;00000001400018DF 48 8D 84 24 34 06 00 00 
MOV RDI, RAX                                                ;00000001400018E7 48 8B F8 
XOR EAX, EAX                                                ;00000001400018EA 33 C0 
MOV ECX, 0x00000010                                         ;00000001400018EC B9 10 00 00 00 
REP STOSB                                                   ;00000001400018F1 F3 AA 
MOV EAX, 0x00000014                                         ;00000001400018F3 B8 14 00 00 00 
IMUL RAX, RAX, 0x00                                         ;00000001400018F8 48 6B C0 00 
MOVSS XMM0, CS : [ RIP + 0x00043A34 ]                       ;00000001400018FC F3 0F 10 05 34 3A 04 00 
MOVSS oword ptr SS : [ RSP + RAX * 1 + 0x00000640 ], XMM0   ;0000000140001904 F3 0F 11 84 04 40 06 00 00 
XORPS XMM3, XMM3                                            ;000000014000190D 0F 57 DB 
XORPS XMM2, XMM2                                            ;0000000140001910 0F 57 D2 
XORPS XMM1, XMM1                                            ;0000000140001913 0F 57 C9 
LEA RCX, invalid ptr SS : [ RSP +  + 0x00000288 ]           ;0000000140001916 48 8D 8C 24 88 02 00 00 
CALL 0x0000120D                                             ;000000014000191E E8 0D 12 00 00 
LEA RCX, invalid ptr SS : [ RSP +  + 0x00000480 ]           ;0000000140001923 48 8D 8C 24 80 04 00 00 
MOV RDI, RCX                                                ;000000014000192B 48 8B F9 
MOV RSI, RAX                                                ;000000014000192E 48 8B F0 
MOV ECX, 0x0000000C                                         ;0000000140001931 B9 0C 00 00 00 
REP MOVSB                                                   ;0000000140001936 F3 A4 
MOV EAX, 0x00000014                                         ;0000000140001938 B8 14 00 00 00 
IMUL RAX, RAX, 0x00                                         ;000000014000193D 48 6B C0 00 
LEA RCX, invalid ptr SS : [ RSP +  + 0x00000480 ]           ;0000000140001941 48 8D 8C 24 80 04 00 00 
LEA RDI, invalid ptr SS : [ RSP + RAX * 1 + 0x00000634 ]    ;0000000140001949 48 8D BC 04 34 06 00 00 
MOV RSI, RCX                                                ;0000000140001951 48 8B F1 
MOV ECX, 0x0000000C                                         ;0000000140001954 B9 0C 00 00 00 
REP MOVSB                                                   ;0000000140001959 F3 A4 
MOV EAX, 0x00000014                                         ;000000014000195B B8 14 00 00 00 
IMUL RAX, RAX, 0x00                                         ;0000000140001960 48 6B C0 00 
MOV dword ptr SS : [ RSP + RAX * 1 + 0x00000630 ], 0x00000003;0000000140001964 C7 84 04 30 06 00 00 03 00 00 00 
LEA RAX, invalid ptr SS : [ RSP +  + 0x00000170 ]           ;000000014000196F 48 8D 84 24 70 01 00 00 
MOV RDI, RAX                                                ;0000000140001977 48 8B F8 
XOR EAX, EAX                                                ;000000014000197A 33 C0 
MOV ECX, 0x00000030                                         ;000000014000197C B9 30 00 00 00 
REP STOSB                                                   ;0000000140001981 F3 AA 
MOV dword ptr SS : [ RSP +  + 0x00000180 ], 0x00000002      ;0000000140001983 C7 84 24 80 01 00 00 02 00 00 00 
LEA RAX, invalid ptr SS : [ RSP +  + 0x00000648 ]           ;000000014000198E 48 8D 84 24 48 06 00 00 
MOV qword ptr SS : [ RSP +  + 0x00000188 ], RAX             ;0000000140001996 48 89 84 24 88 01 00 00 
MOV dword ptr SS : [ RSP +  + 0x00000170 ], 0x00000001      ;000000014000199E C7 84 24 70 01 00 00 01 00 00 00 
LEA RAX, invalid ptr SS : [ RSP +  + 0x00000630 ]           ;00000001400019A9 48 8D 84 24 30 06 00 00 
MOV qword ptr SS : [ RSP +  + 0x00000178 ], RAX             ;00000001400019B1 48 89 84 24 78 01 00 00 
MOV dword ptr SS : [ RSP +  + 0x00000190 ], 0x00000004      ;00000001400019B9 C7 84 24 90 01 00 00 04 00 00 00 
LEA RAX, invalid ptr SS : [ RSP +  + 0x00000670 ]           ;00000001400019C4 48 8D 84 24 70 06 00 00 
MOV qword ptr SS : [ RSP +  + 0x00000198 ], RAX             ;00000001400019CC 48 89 84 24 98 01 00 00 
XORPS XMM0, XMM0                                            ;00000001400019D4 0F 57 C0 
MOVSS oword ptr SS : [ RSP +  + 0x000003B8 ], XMM0          ;00000001400019D7 F3 0F 11 84 24 B8 03 00 00 
MOVSS XMM0, CS : [ RIP + 0x0004394C ]                       ;00000001400019E0 F3 0F 10 05 4C 39 04 00 
MOVSS oword ptr SS : [ RSP +  + 0x000003BC ], XMM0          ;00000001400019E8 F3 0F 11 84 24 BC 03 00 00 
MOVSS XMM0, CS : [ RIP + 0x00043953 ]                       ;00000001400019F1 F3 0F 10 05 53 39 04 00 
MOVSS oword ptr SS : [ RSP +  + 0x000003C0 ], XMM0          ;00000001400019F9 F3 0F 11 84 24 C0 03 00 00 
LEA RAX, invalid ptr SS : [ RSP +  + 0x00000120 ]           ;0000000140001A02 48 8D 84 24 20 01 00 00 
LEA RCX, invalid ptr SS : [ RSP +  + 0x000003B8 ]           ;0000000140001A0A 48 8D 8C 24 B8 03 00 00 
MOV RDI, RAX                                                ;0000000140001A12 48 8B F8 
MOV RSI, RCX                                                ;0000000140001A15 48 8B F1 
MOV ECX, 0x0000000C                                         ;0000000140001A18 B9 0C 00 00 00 
REP MOVSB                                                   ;0000000140001A1D F3 A4 
LEA RDX, invalid ptr SS : [ RSP +  + 0x00000120 ]           ;0000000140001A1F 48 8D 94 24 20 01 00 00 
LEA RCX, invalid ptr SS : [ RSP +  + 0x00000278 ]           ;0000000140001A27 48 8D 8C 24 78 02 00 00 
CALL 0x00000FBC                                             ;0000000140001A2F E8 BC 0F 00 00 
LEA RCX, invalid ptr SS : [ RSP +  + 0x00000470 ]           ;0000000140001A34 48 8D 8C 24 70 04 00 00 
MOV RDI, RCX                                                ;0000000140001A3C 48 8B F9 
MOV RSI, RAX                                                ;0000000140001A3F 48 8B F0 
MOV ECX, 0x0000000C                                         ;0000000140001A42 B9 0C 00 00 00 
REP MOVSB                                                   ;0000000140001A47 F3 A4 
LEA RAX, invalid ptr SS : [ RSP +  + 0x000003C8 ]           ;0000000140001A49 48 8D 84 24 C8 03 00 00 
LEA RCX, invalid ptr SS : [ RSP +  + 0x00000470 ]           ;0000000140001A51 48 8D 8C 24 70 04 00 00 
MOV RDI, RAX                                                ;0000000140001A59 48 8B F8 
MOV RSI, RCX                                                ;0000000140001A5C 48 8B F1 
MOV ECX, 0x0000000C                                         ;0000000140001A5F B9 0C 00 00 00 
REP MOVSB                                                   ;0000000140001A64 F3 A4 
XORPS XMM3, XMM3                                            ;0000000140001A66 0F 57 DB 
MOVSS XMM2, CS : [ RIP + 0x000438C3 ]                       ;0000000140001A69 F3 0F 10 15 C3 38 04 00 
XORPS XMM1, XMM1                                            ;0000000140001A71 0F 57 C9 
LEA RCX, invalid ptr SS : [ RSP +  + 0x000002A8 ]           ;0000000140001A74 48 8D 8C 24 A8 02 00 00 
CALL 0x000010AF                                             ;0000000140001A7C E8 AF 10 00 00 
LEA RCX, invalid ptr SS : [ RSP +  + 0x00000460 ]           ;0000000140001A81 48 8D 8C 24 60 04 00 00 
MOV RDI, RCX                                                ;0000000140001A89 48 8B F9 
MOV RSI, RAX                                                ;0000000140001A8C 48 8B F0 
MOV ECX, 0x0000000C                                         ;0000000140001A8F B9 0C 00 00 00 
REP MOVSB                                                   ;0000000140001A94 F3 A4 
LEA RAX, invalid ptr SS : [ RSP +  + 0x00000150 ]           ;0000000140001A96 48 8D 84 24 50 01 00 00 
LEA RCX, invalid ptr SS : [ RSP +  + 0x000003C8 ]           ;0000000140001A9E 48 8D 8C 24 C8 03 00 00 
MOV RDI, RAX                                                ;0000000140001AA6 48 8B F8 
MOV RSI, RCX                                                ;0000000140001AA9 48 8B F1 
MOV ECX, 0x0000000C                                         ;0000000140001AAC B9 0C 00 00 00 
REP MOVSB                                                   ;0000000140001AB1 F3 A4 
LEA RAX, invalid ptr SS : [ RSP +  + 0x00000160 ]           ;0000000140001AB3 48 8D 84 24 60 01 00 00 
LEA RCX, invalid ptr SS : [ RSP +  + 0x00000460 ]           ;0000000140001ABB 48 8D 8C 24 60 04 00 00 
MOV RDI, RAX                                                ;0000000140001AC3 48 8B F8 
MOV RSI, RCX                                                ;0000000140001AC6 48 8B F1 
MOV ECX, 0x0000000C                                         ;0000000140001AC9 B9 0C 00 00 00 
REP MOVSB                                                   ;0000000140001ACE F3 A4 
LEA R8, invalid ptr SS : [ RSP +  + 0x00000150 ]            ;0000000140001AD0 4C 8D 84 24 50 01 00 00 
LEA RDX, invalid ptr SS : [ RSP +  + 0x00000160 ]           ;0000000140001AD8 48 8D 94 24 60 01 00 00 
LEA RCX, invalid ptr SS : [ RSP +  + 0x00000268 ]           ;0000000140001AE0 48 8D 8C 24 68 02 00 00 
CALL 0x00000CE3                                             ;0000000140001AE8 E8 E3 0C 00 00 
LEA RCX, invalid ptr SS : [ RSP +  + 0x00000450 ]           ;0000000140001AED 48 8D 8C 24 50 04 00 00 
MOV RDI, RCX                                                ;0000000140001AF5 48 8B F9 
MOV RSI, RAX                                                ;0000000140001AF8 48 8B F0 
MOV ECX, 0x0000000C                                         ;0000000140001AFB B9 0C 00 00 00 
REP MOVSB                                                   ;0000000140001B00 F3 A4 
LEA RAX, invalid ptr SS : [ RSP +  + 0x000001A0 ]           ;0000000140001B02 48 8D 84 24 A0 01 00 00 
LEA RCX, invalid ptr SS : [ RSP +  + 0x00000450 ]           ;0000000140001B0A 48 8D 8C 24 50 04 00 00 
MOV RDI, RAX                                                ;0000000140001B12 48 8B F8 
MOV RSI, RCX                                                ;0000000140001B15 48 8B F1 
MOV ECX, 0x0000000C                                         ;0000000140001B18 B9 0C 00 00 00 
REP MOVSB                                                   ;0000000140001B1D F3 A4 
LEA RDX, invalid ptr SS : [ RSP +  + 0x000001A0 ]           ;0000000140001B1F 48 8D 94 24 A0 01 00 00 
LEA RCX, invalid ptr SS : [ RSP +  + 0x00000258 ]           ;0000000140001B27 48 8D 8C 24 58 02 00 00 
CALL 0x00000EBC                                             ;0000000140001B2F E8 BC 0E 00 00 
LEA RCX, invalid ptr SS : [ RSP +  + 0x00000520 ]           ;0000000140001B34 48 8D 8C 24 20 05 00 00 
MOV RDI, RCX                                                ;0000000140001B3C 48 8B F9 
MOV RSI, RAX                                                ;0000000140001B3F 48 8B F0 
MOV ECX, 0x0000000C                                         ;0000000140001B42 B9 0C 00 00 00 
REP MOVSB                                                   ;0000000140001B47 F3 A4 
LEA RAX, invalid ptr SS : [ RSP +  + 0x00000440 ]           ;0000000140001B49 48 8D 84 24 40 04 00 00 
LEA RCX, invalid ptr SS : [ RSP +  + 0x00000520 ]           ;0000000140001B51 48 8D 8C 24 20 05 00 00 
MOV RDI, RAX                                                ;0000000140001B59 48 8B F8 
MOV RSI, RCX                                                ;0000000140001B5C 48 8B F1 
MOV ECX, 0x0000000C                                         ;0000000140001B5F B9 0C 00 00 00 
REP MOVSB                                                   ;0000000140001B64 F3 A4 
LEA RAX, invalid ptr SS : [ RSP +  + 0x000001B0 ]           ;0000000140001B66 48 8D 84 24 B0 01 00 00 
LEA RCX, invalid ptr SS : [ RSP +  + 0x00000440 ]           ;0000000140001B6E 48 8D 8C 24 40 04 00 00 
MOV RDI, RAX                                                ;0000000140001B76 48 8B F8 
MOV RSI, RCX                                                ;0000000140001B79 48 8B F1 
MOV ECX, 0x0000000C                                         ;0000000140001B7C B9 0C 00 00 00 
REP MOVSB                                                   ;0000000140001B81 F3 A4 
LEA RAX, invalid ptr SS : [ RSP +  + 0x00000130 ]           ;0000000140001B83 48 8D 84 24 30 01 00 00 
LEA RCX, invalid ptr SS : [ RSP +  + 0x000003C8 ]           ;0000000140001B8B 48 8D 8C 24 C8 03 00 00 
MOV RDI, RAX                                                ;0000000140001B93 48 8B F8 
MOV RSI, RCX                                                ;0000000140001B96 48 8B F1 
MOV ECX, 0x0000000C                                         ;0000000140001B99 B9 0C 00 00 00 
REP MOVSB                                                   ;0000000140001B9E F3 A4 
LEA R8, invalid ptr SS : [ RSP +  + 0x000001B0 ]            ;0000000140001BA0 4C 8D 84 24 B0 01 00 00 
LEA RDX, invalid ptr SS : [ RSP +  + 0x00000130 ]           ;0000000140001BA8 48 8D 94 24 30 01 00 00 
LEA RCX, invalid ptr SS : [ RSP +  + 0x00000248 ]           ;0000000140001BB0 48 8D 8C 24 48 02 00 00 
CALL 0x00000C13                                             ;0000000140001BB8 E8 13 0C 00 00 
LEA RCX, invalid ptr SS : [ RSP +  + 0x000005C0 ]           ;0000000140001BBD 48 8D 8C 24 C0 05 00 00 
MOV RDI, RCX                                                ;0000000140001BC5 48 8B F9 
MOV RSI, RAX                                                ;0000000140001BC8 48 8B F0 
MOV ECX, 0x0000000C                                         ;0000000140001BCB B9 0C 00 00 00 
REP MOVSB                                                   ;0000000140001BD0 F3 A4 
LEA RAX, invalid ptr SS : [ RSP +  + 0x000001D0 ]           ;0000000140001BD2 48 8D 84 24 D0 01 00 00 
LEA RCX, invalid ptr SS : [ RSP +  + 0x000005C0 ]           ;0000000140001BDA 48 8D 8C 24 C0 05 00 00 
MOV RDI, RAX                                                ;0000000140001BE2 48 8B F8 
MOV RSI, RCX                                                ;0000000140001BE5 48 8B F1 
MOV ECX, 0x0000000C                                         ;0000000140001BE8 B9 0C 00 00 00 
REP MOVSB                                                   ;0000000140001BED F3 A4 
LEA RDX, invalid ptr SS : [ RSP +  + 0x000001D0 ]           ;0000000140001BEF 48 8D 94 24 D0 01 00 00 
LEA RCX, invalid ptr SS : [ RSP +  + 0x00000238 ]           ;0000000140001BF7 48 8D 8C 24 38 02 00 00 
CALL 0x00000DEC                                             ;0000000140001BFF E8 EC 0D 00 00 
LEA RCX, invalid ptr SS : [ RSP +  + 0x000005B0 ]           ;0000000140001C04 48 8D 8C 24 B0 05 00 00 
MOV RDI, RCX                                                ;0000000140001C0C 48 8B F9 
MOV RSI, RAX                                                ;0000000140001C0F 48 8B F0 
MOV ECX, 0x0000000C                                         ;0000000140001C12 B9 0C 00 00 00 
REP MOVSB                                                   ;0000000140001C17 F3 A4 
LEA RAX, invalid ptr SS : [ RSP +  + 0x000005A0 ]           ;0000000140001C19 48 8D 84 24 A0 05 00 00 
LEA RCX, invalid ptr SS : [ RSP +  + 0x000005B0 ]           ;0000000140001C21 48 8D 8C 24 B0 05 00 00 
MOV RDI, RAX                                                ;0000000140001C29 48 8B F8 
MOV RSI, RCX                                                ;0000000140001C2C 48 8B F1 
MOV ECX, 0x0000000C                                         ;0000000140001C2F B9 0C 00 00 00 
REP MOVSB                                                   ;0000000140001C34 F3 A4 
MOV RAX, qword ptr SS : [ RSP +  + 0x50 ]                   ;0000000140001C36 48 8B 44 24 50 
MOV qword ptr SS : [ RSP +  + 0x00000090 ], RAX             ;0000000140001C3B 48 89 84 24 90 00 00 00 
MOVSS XMM0, CS : [ RIP + 0x000436E9 ]                       ;0000000140001C43 F3 0F 10 05 E9 36 04 00 
MOVSS oword ptr SS : [ RSP +  + 0x5C ], XMM0                ;0000000140001C4B F3 0F 11 44 24 5C 
MOVSS XMM0, CS : [ RIP + 0x000436DB ]                       ;0000000140001C51 F3 0F 10 05 DB 36 04 00 
MOVSS oword ptr SS : [ RSP +  + 0x58 ], XMM0                ;0000000140001C59 F3 0F 11 44 24 58 
MOV EAX, dword ptr SS : [ RSP +  + 0x44 ]                   ;0000000140001C5F 8B 44 24 44 
CMP dword ptr SS : [ RSP +  + 0x40 ], EAX                   ;0000000140001C63 39 44 24 40 
JLE 0x25                                                    ;0000000140001C67 7E 25 
CVTSI2SS XMM0, dword ptr SS : [ RSP +  + 0x44 ]             ;0000000140001C69 F3 0F 2A 44 24 44 
CVTSI2SS XMM1, dword ptr SS : [ RSP +  + 0x40 ]             ;0000000140001C6F F3 0F 2A 4C 24 40 
DIVSS XMM0, XMM1                                            ;0000000140001C75 F3 0F 5E C1 
MOVSS XMM1, oword ptr SS : [ RSP +  + 0x58 ]                ;0000000140001C79 F3 0F 10 4C 24 58 
MULSS XMM1, XMM0                                            ;0000000140001C7F F3 0F 59 C8 
MOVAPS XMM0, XMM1                                           ;0000000140001C83 0F 28 C1 
MOVSS oword ptr SS : [ RSP +  + 0x5C ], XMM0                ;0000000140001C86 F3 0F 11 44 24 5C 
JMP 0x23                                                    ;0000000140001C8C EB 23 
CVTSI2SS XMM0, dword ptr SS : [ RSP +  + 0x40 ]             ;0000000140001C8E F3 0F 2A 44 24 40 
CVTSI2SS XMM1, dword ptr SS : [ RSP +  + 0x44 ]             ;0000000140001C94 F3 0F 2A 4C 24 44 
DIVSS XMM0, XMM1                                            ;0000000140001C9A F3 0F 5E C1 
MOVSS XMM1, oword ptr SS : [ RSP +  + 0x5C ]                ;0000000140001C9E F3 0F 10 4C 24 5C 
MULSS XMM1, XMM0                                            ;0000000140001CA4 F3 0F 59 C8 
MOVAPS XMM0, XMM1                                           ;0000000140001CA8 0F 28 C1 
MOVSS oword ptr SS : [ RSP +  + 0x58 ], XMM0                ;0000000140001CAB F3 0F 11 44 24 58 
MOVSS XMM0, oword ptr SS : [ RSP +  + 0x58 ]                ;0000000140001CB1 F3 0F 10 44 24 58 
MULSS XMM0, CS : [ RIP + 0x00043671 ]                       ;0000000140001CB7 F3 0F 59 05 71 36 04 00 
MOVSS oword ptr SS : [ RSP +  + 0x6C ], XMM0                ;0000000140001CBF F3 0F 11 44 24 6C 
MOVSS XMM0, oword ptr SS : [ RSP +  + 0x5C ]                ;0000000140001CC5 F3 0F 10 44 24 5C 
MULSS XMM0, CS : [ RIP + 0x0004365D ]                       ;0000000140001CCB F3 0F 59 05 5D 36 04 00 
MOVSS oword ptr SS : [ RSP +  + 0x74 ], XMM0                ;0000000140001CD3 F3 0F 11 44 24 74 
LEA RAX, invalid ptr SS : [ RSP +  + 0x00000530 ]           ;0000000140001CD9 48 8D 84 24 30 05 00 00 
LEA RCX, invalid ptr SS : [ RSP +  + 0x000003B8 ]           ;0000000140001CE1 48 8D 8C 24 B8 03 00 00 
MOV RDI, RAX                                                ;0000000140001CE9 48 8B F8 
MOV RSI, RCX                                                ;0000000140001CEC 48 8B F1 
MOV ECX, 0x0000000C                                         ;0000000140001CEF B9 0C 00 00 00 
REP MOVSB                                                   ;0000000140001CF4 F3 A4 
MOV EAX, dword ptr SS : [ RSP +  + 0x44 ]                   ;0000000140001CF6 8B 44 24 44 
DEC EAX                                                     ;0000000140001CFA FF C8 
MOV dword ptr SS : [ RSP +  + 0x30 ], EAX                   ;0000000140001CFC 89 44 24 30 
JMP 0x0A                                                    ;0000000140001D00 EB 0A 
MOV EAX, dword ptr SS : [ RSP +  + 0x30 ]                   ;0000000140001D02 8B 44 24 30 
DEC EAX                                                     ;0000000140001D06 FF C8 
MOV dword ptr SS : [ RSP +  + 0x30 ], EAX                   ;0000000140001D08 89 44 24 30 
CMP dword ptr SS : [ RSP +  + 0x30 ], 0x00                  ;0000000140001D0C 83 7C 24 30 00 
JL 0x000006A0                                               ;0000000140001D11 0F 8C A0 06 00 00 
CVTSI2SS XMM0, dword ptr SS : [ RSP +  + 0x30 ]             ;0000000140001D17 F3 0F 2A 44 24 30 
CVTSI2SS XMM1, dword ptr SS : [ RSP +  + 0x44 ]             ;0000000140001D1D F3 0F 2A 4C 24 44 
SUBSS XMM1, CS : [ RIP + 0x00043609 ]                       ;0000000140001D23 F3 0F 5C 0D 09 36 04 00 
DIVSS XMM0, XMM1                                            ;0000000140001D2B F3 0F 5E C1 
MOVSS XMM1, CS : [ RIP + 0x00043601 ]                       ;0000000140001D2F F3 0F 10 0D 01 36 04 00 
MULSS XMM1, XMM0                                            ;0000000140001D37 F3 0F 59 C8 
MOVAPS XMM0, XMM1                                           ;0000000140001D3B 0F 28 C1 
SUBSS XMM0, CS : [ RIP + 0x000435EE ]                       ;0000000140001D3E F3 0F 5C 05 EE 35 04 00 
MOVSS oword ptr SS : [ RSP +  + 0x70 ], XMM0                ;0000000140001D46 F3 0F 11 44 24 70 
MOV dword ptr SS : [ RSP +  + 0x34 ], 0x00000000            ;0000000140001D4C C7 44 24 34 00 00 00 00 
JMP 0x0A                                                    ;0000000140001D54 EB 0A 
MOV EAX, dword ptr SS : [ RSP +  + 0x34 ]                   ;0000000140001D56 8B 44 24 34 
INC EAX                                                     ;0000000140001D5A FF C0 
MOV dword ptr SS : [ RSP +  + 0x34 ], EAX                   ;0000000140001D5C 89 44 24 34 
MOV EAX, dword ptr SS : [ RSP +  + 0x40 ]                   ;0000000140001D60 8B 44 24 40 
CMP dword ptr SS : [ RSP +  + 0x34 ], EAX                   ;0000000140001D64 39 44 24 34 
JGE 0x00000644                                              ;0000000140001D68 0F 8D 44 06 00 00 
CVTSI2SS XMM0, dword ptr SS : [ RSP +  + 0x34 ]             ;0000000140001D6E F3 0F 2A 44 24 34 
CVTSI2SS XMM1, dword ptr SS : [ RSP +  + 0x40 ]             ;0000000140001D74 F3 0F 2A 4C 24 40 
SUBSS XMM1, CS : [ RIP + 0x000435B2 ]                       ;0000000140001D7A F3 0F 5C 0D B2 35 04 00 
DIVSS XMM0, XMM1                                            ;0000000140001D82 F3 0F 5E C1 
MOVSS XMM1, CS : [ RIP + 0x000435AA ]                       ;0000000140001D86 F3 0F 10 0D AA 35 04 00 
MULSS XMM1, XMM0                                            ;0000000140001D8E F3 0F 59 C8 
MOVAPS XMM0, XMM1                                           ;0000000140001D92 0F 28 C1 
SUBSS XMM0, CS : [ RIP + 0x00043597 ]                       ;0000000140001D95 F3 0F 5C 05 97 35 04 00 
MOVSS oword ptr SS : [ RSP +  + 0x68 ], XMM0                ;0000000140001D9D F3 0F 11 44 24 68 
LEA RAX, invalid ptr SS : [ RSP +  + 0x000001F0 ]           ;0000000140001DA3 48 8D 84 24 F0 01 00 00 
LEA RCX, invalid ptr SS : [ RSP +  + 0x00000440 ]           ;0000000140001DAB 48 8D 8C 24 40 04 00 00 
MOV RDI, RAX                                                ;0000000140001DB3 48 8B F8 
MOV RSI, RCX                                                ;0000000140001DB6 48 8B F1 
MOV ECX, 0x0000000C                                         ;0000000140001DB9 B9 0C 00 00 00 
REP MOVSB                                                   ;0000000140001DBE F3 A4 
MOVSS XMM0, oword ptr SS : [ RSP +  + 0x68 ]                ;0000000140001DC0 F3 0F 10 44 24 68 
MULSS XMM0, oword ptr SS : [ RSP +  + 0x6C ]                ;0000000140001DC6 F3 0F 59 44 24 6C 
LEA R8, invalid ptr SS : [ RSP +  + 0x000001F0 ]            ;0000000140001DCC 4C 8D 84 24 F0 01 00 00 
MOVAPS XMM1, XMM0                                           ;0000000140001DD4 0F 28 C8 
LEA RCX, invalid ptr SS : [ RSP +  + 0x00000328 ]           ;0000000140001DD7 48 8D 8C 24 28 03 00 00 
CALL 0x0000075C                                             ;0000000140001DDF E8 5C 07 00 00 
LEA RCX, invalid ptr SS : [ RSP +  + 0x00000560 ]           ;0000000140001DE4 48 8D 8C 24 60 05 00 00 
MOV RDI, RCX                                                ;0000000140001DEC 48 8B F9 
MOV RSI, RAX                                                ;0000000140001DEF 48 8B F0 
MOV ECX, 0x0000000C                                         ;0000000140001DF2 B9 0C 00 00 00 
REP MOVSB                                                   ;0000000140001DF7 F3 A4 
LEA RAX, invalid ptr SS : [ RSP +  + 0x00000540 ]           ;0000000140001DF9 48 8D 84 24 40 05 00 00 
LEA RCX, invalid ptr SS : [ RSP +  + 0x00000560 ]           ;0000000140001E01 48 8D 8C 24 60 05 00 00 
MOV RDI, RAX                                                ;0000000140001E09 48 8B F8 
MOV RSI, RCX                                                ;0000000140001E0C 48 8B F1 
MOV ECX, 0x0000000C                                         ;0000000140001E0F B9 0C 00 00 00 
REP MOVSB                                                   ;0000000140001E14 F3 A4 
LEA RAX, invalid ptr SS : [ RSP +  + 0x00000220 ]           ;0000000140001E16 48 8D 84 24 20 02 00 00 
LEA RCX, invalid ptr SS : [ RSP +  + 0x000005A0 ]           ;0000000140001E1E 48 8D 8C 24 A0 05 00 00 
MOV RDI, RAX                                                ;0000000140001E26 48 8B F8 
MOV RSI, RCX                                                ;0000000140001E29 48 8B F1 
MOV ECX, 0x0000000C                                         ;0000000140001E2C B9 0C 00 00 00 
REP MOVSB                                                   ;0000000140001E31 F3 A4 
MOVSS XMM0, oword ptr SS : [ RSP +  + 0x70 ]                ;0000000140001E33 F3 0F 10 44 24 70 
MULSS XMM0, oword ptr SS : [ RSP +  + 0x74 ]                ;0000000140001E39 F3 0F 59 44 24 74 
LEA R8, invalid ptr SS : [ RSP +  + 0x00000220 ]            ;0000000140001E3F 4C 8D 84 24 20 02 00 00 
MOVAPS XMM1, XMM0                                           ;0000000140001E47 0F 28 C8 
LEA RCX, invalid ptr SS : [ RSP +  + 0x000002B8 ]           ;0000000140001E4A 48 8D 8C 24 B8 02 00 00 
CALL 0x000006E9                                             ;0000000140001E52 E8 E9 06 00 00 
LEA RCX, invalid ptr SS : [ RSP +  + 0x00000570 ]           ;0000000140001E57 48 8D 8C 24 70 05 00 00 
MOV RDI, RCX                                                ;0000000140001E5F 48 8B F9 
MOV RSI, RAX                                                ;0000000140001E62 48 8B F0 
MOV ECX, 0x0000000C                                         ;0000000140001E65 B9 0C 00 00 00 
REP MOVSB                                                   ;0000000140001E6A F3 A4 
LEA RAX, invalid ptr SS : [ RSP +  + 0x000004F0 ]           ;0000000140001E6C 48 8D 84 24 F0 04 00 00 
LEA RCX, invalid ptr SS : [ RSP +  + 0x00000570 ]           ;0000000140001E74 48 8D 8C 24 70 05 00 00 
MOV RDI, RAX                                                ;0000000140001E7C 48 8B F8 
MOV RSI, RCX                                                ;0000000140001E7F 48 8B F1 
MOV ECX, 0x0000000C                                         ;0000000140001E82 B9 0C 00 00 00 
REP MOVSB                                                   ;0000000140001E87 F3 A4 
LEA RAX, invalid ptr SS : [ RSP +  + 0x000000C0 ]           ;0000000140001E89 48 8D 84 24 C0 00 00 00 
LEA RCX, invalid ptr SS : [ RSP +  + 0x00000540 ]           ;0000000140001E91 48 8D 8C 24 40 05 00 00 
MOV RDI, RAX                                                ;0000000140001E99 48 8B F8 
MOV RSI, RCX                                                ;0000000140001E9C 48 8B F1 
MOV ECX, 0x0000000C                                         ;0000000140001E9F B9 0C 00 00 00 
REP MOVSB                                                   ;0000000140001EA4 F3 A4 
LEA RAX, invalid ptr SS : [ RSP +  + 0x000000D0 ]           ;0000000140001EA6 48 8D 84 24 D0 00 00 00 
LEA RCX, invalid ptr SS : [ RSP +  + 0x00000530 ]           ;0000000140001EAE 48 8D 8C 24 30 05 00 00 
MOV RDI, RAX                                                ;0000000140001EB6 48 8B F8 
MOV RSI, RCX                                                ;0000000140001EB9 48 8B F1 
MOV ECX, 0x0000000C                                         ;0000000140001EBC B9 0C 00 00 00 
REP MOVSB                                                   ;0000000140001EC1 F3 A4 
LEA R8, invalid ptr SS : [ RSP +  + 0x000000C0 ]            ;0000000140001EC3 4C 8D 84 24 C0 00 00 00 
LEA RDX, invalid ptr SS : [ RSP +  + 0x000000D0 ]           ;0000000140001ECB 48 8D 94 24 D0 00 00 00 
LEA RCX, invalid ptr SS : [ RSP +  + 0x000002C8 ]           ;0000000140001ED3 48 8D 8C 24 C8 02 00 00 
CALL 0x00000850                                             ;0000000140001EDB E8 50 08 00 00 
LEA RCX, invalid ptr SS : [ RSP +  + 0x000004D0 ]           ;0000000140001EE0 48 8D 8C 24 D0 04 00 00 
MOV RDI, RCX                                                ;0000000140001EE8 48 8B F9 
MOV RSI, RAX                                                ;0000000140001EEB 48 8B F0 
MOV ECX, 0x0000000C                                         ;0000000140001EEE B9 0C 00 00 00 
REP MOVSB                                                   ;0000000140001EF3 F3 A4 
LEA RAX, invalid ptr SS : [ RSP +  + 0x00000100 ]           ;0000000140001EF5 48 8D 84 24 00 01 00 00 
LEA RCX, invalid ptr SS : [ RSP +  + 0x000004F0 ]           ;0000000140001EFD 48 8D 8C 24 F0 04 00 00 
MOV RDI, RAX                                                ;0000000140001F05 48 8B F8 
MOV RSI, RCX                                                ;0000000140001F08 48 8B F1 
MOV ECX, 0x0000000C                                         ;0000000140001F0B B9 0C 00 00 00 
REP MOVSB                                                   ;0000000140001F10 F3 A4 
LEA RAX, invalid ptr SS : [ RSP +  + 0x00000110 ]           ;0000000140001F12 48 8D 84 24 10 01 00 00 
LEA RCX, invalid ptr SS : [ RSP +  + 0x000004D0 ]           ;0000000140001F1A 48 8D 8C 24 D0 04 00 00 
MOV RDI, RAX                                                ;0000000140001F22 48 8B F8 
MOV RSI, RCX                                                ;0000000140001F25 48 8B F1 
MOV ECX, 0x0000000C                                         ;0000000140001F28 B9 0C 00 00 00 
REP MOVSB                                                   ;0000000140001F2D F3 A4 
LEA R8, invalid ptr SS : [ RSP +  + 0x00000100 ]            ;0000000140001F2F 4C 8D 84 24 00 01 00 00 
LEA RDX, invalid ptr SS : [ RSP +  + 0x00000110 ]           ;0000000140001F37 48 8D 94 24 10 01 00 00 
LEA RCX, invalid ptr SS : [ RSP +  + 0x000002D8 ]           ;0000000140001F3F 48 8D 8C 24 D8 02 00 00 
CALL 0x000007E4                                             ;0000000140001F47 E8 E4 07 00 00 
LEA RCX, invalid ptr SS : [ RSP +  + 0x000004C0 ]           ;0000000140001F4C 48 8D 8C 24 C0 04 00 00 
MOV RDI, RCX                                                ;0000000140001F54 48 8B F9 
MOV RSI, RAX                                                ;0000000140001F57 48 8B F0 
MOV ECX, 0x0000000C                                         ;0000000140001F5A B9 0C 00 00 00 
REP MOVSB                                                   ;0000000140001F5F F3 A4 
LEA RAX, invalid ptr SS : [ RSP +  + 0x00000510 ]           ;0000000140001F61 48 8D 84 24 10 05 00 00 
LEA RCX, invalid ptr SS : [ RSP +  + 0x000004C0 ]           ;0000000140001F69 48 8D 8C 24 C0 04 00 00 
MOV RDI, RAX                                                ;0000000140001F71 48 8B F8 
MOV RSI, RCX                                                ;0000000140001F74 48 8B F1 
MOV ECX, 0x0000000C                                         ;0000000140001F77 B9 0C 00 00 00 
REP MOVSB                                                   ;0000000140001F7C F3 A4 
LEA RAX, invalid ptr SS : [ RSP +  + 0x00000200 ]           ;0000000140001F7E 48 8D 84 24 00 02 00 00 
LEA RCX, invalid ptr SS : [ RSP +  + 0x000003C8 ]           ;0000000140001F86 48 8D 8C 24 C8 03 00 00 
MOV RDI, RAX                                                ;0000000140001F8E 48 8B F8 
MOV RSI, RCX                                                ;0000000140001F91 48 8B F1 
MOV ECX, 0x0000000C                                         ;0000000140001F94 B9 0C 00 00 00 
REP MOVSB                                                   ;0000000140001F99 F3 A4 
MOVSS XMM2, CS : [ RIP + 0x00043391 ]                       ;0000000140001F9B F3 0F 10 15 91 33 04 00 
LEA RDX, invalid ptr SS : [ RSP +  + 0x00000200 ]           ;0000000140001FA3 48 8D 94 24 00 02 00 00 
LEA RCX, invalid ptr SS : [ RSP +  + 0x000002E8 ]           ;0000000140001FAB 48 8D 8C 24 E8 02 00 00 
CALL 0x00000628                                             ;0000000140001FB3 E8 28 06 00 00 
LEA RCX, invalid ptr SS : [ RSP +  + 0x000004B0 ]           ;0000000140001FB8 48 8D 8C 24 B0 04 00 00 
MOV RDI, RCX                                                ;0000000140001FC0 48 8B F9 
MOV RSI, RAX                                                ;0000000140001FC3 48 8B F0 
MOV ECX, 0x0000000C                                         ;0000000140001FC6 B9 0C 00 00 00 
REP MOVSB                                                   ;0000000140001FCB F3 A4 
LEA RAX, invalid ptr SS : [ RSP +  + 0x00000140 ]           ;0000000140001FCD 48 8D 84 24 40 01 00 00 
LEA RCX, invalid ptr SS : [ RSP +  + 0x000004B0 ]           ;0000000140001FD5 48 8D 8C 24 B0 04 00 00 
MOV RDI, RAX                                                ;0000000140001FDD 48 8B F8 
MOV RSI, RCX                                                ;0000000140001FE0 48 8B F1 
MOV ECX, 0x0000000C                                         ;0000000140001FE3 B9 0C 00 00 00 
REP MOVSB                                                   ;0000000140001FE8 F3 A4 
LEA RAX, invalid ptr SS : [ RSP +  + 0x000000F0 ]           ;0000000140001FEA 48 8D 84 24 F0 00 00 00 
LEA RCX, invalid ptr SS : [ RSP +  + 0x000003B8 ]           ;0000000140001FF2 48 8D 8C 24 B8 03 00 00 
MOV RDI, RAX                                                ;0000000140001FFA 48 8B F8 
MOV RSI, RCX                                                ;0000000140001FFD 48 8B F1 
MOV ECX, 0x0000000C                                         ;0000000140002000 B9 0C 00 00 00 
REP MOVSB                                                   ;0000000140002005 F3 A4 
LEA R8, invalid ptr SS : [ RSP +  + 0x00000140 ]            ;0000000140002007 4C 8D 84 24 40 01 00 00 
LEA RDX, invalid ptr SS : [ RSP +  + 0x000000F0 ]           ;000000014000200F 48 8D 94 24 F0 00 00 00 
LEA RCX, invalid ptr SS : [ RSP +  + 0x000002F8 ]           ;0000000140002017 48 8D 8C 24 F8 02 00 00 
CALL 0x0000070C                                             ;000000014000201F E8 0C 07 00 00 
LEA RCX, invalid ptr SS : [ RSP +  + 0x000004E0 ]           ;0000000140002024 48 8D 8C 24 E0 04 00 00 
MOV RDI, RCX                                                ;000000014000202C 48 8B F9 
MOV RSI, RAX                                                ;000000014000202F 48 8B F0 
MOV ECX, 0x0000000C                                         ;0000000140002032 B9 0C 00 00 00 
REP MOVSB                                                   ;0000000140002037 F3 A4 
LEA RAX, invalid ptr SS : [ RSP +  + 0x000003D8 ]           ;0000000140002039 48 8D 84 24 D8 03 00 00 
LEA RCX, invalid ptr SS : [ RSP +  + 0x000004E0 ]           ;0000000140002041 48 8D 8C 24 E0 04 00 00 
MOV RDI, RAX                                                ;0000000140002049 48 8B F8 
MOV RSI, RCX                                                ;000000014000204C 48 8B F1 
MOV ECX, 0x0000000C                                         ;000000014000204F B9 0C 00 00 00 
REP MOVSB                                                   ;0000000140002054 F3 A4 
LEA RAX, invalid ptr SS : [ RSP +  + 0x000000E0 ]           ;0000000140002056 48 8D 84 24 E0 00 00 00 
LEA RCX, invalid ptr SS : [ RSP +  + 0x000003D8 ]           ;000000014000205E 48 8D 8C 24 D8 03 00 00 
MOV RDI, RAX                                                ;0000000140002066 48 8B F8 
MOV RSI, RCX                                                ;0000000140002069 48 8B F1 
MOV ECX, 0x0000000C                                         ;000000014000206C B9 0C 00 00 00 
REP MOVSB                                                   ;0000000140002071 F3 A4 
LEA RDX, invalid ptr SS : [ RSP +  + 0x000000E0 ]           ;0000000140002073 48 8D 94 24 E0 00 00 00 
LEA RCX, invalid ptr SS : [ RSP +  + 0x00000308 ]           ;000000014000207B 48 8D 8C 24 08 03 00 00 
CALL 0x00000968                                             ;0000000140002083 E8 68 09 00 00 
LEA RCX, invalid ptr SS : [ RSP +  + 0x00000500 ]           ;0000000140002088 48 8D 8C 24 00 05 00 00 
MOV RDI, RCX                                                ;0000000140002090 48 8B F9 
MOV RSI, RAX                                                ;0000000140002093 48 8B F0 
MOV ECX, 0x0000000C                                         ;0000000140002096 B9 0C 00 00 00 
REP MOVSB                                                   ;000000014000209B F3 A4 
LEA RAX, invalid ptr SS : [ RSP +  + 0x00000620 ]           ;000000014000209D 48 8D 84 24 20 06 00 00 
LEA RCX, invalid ptr SS : [ RSP +  + 0x00000500 ]           ;00000001400020A5 48 8D 8C 24 00 05 00 00 
MOV RDI, RAX                                                ;00000001400020AD 48 8B F8 
MOV RSI, RCX                                                ;00000001400020B0 48 8B F1 
MOV ECX, 0x0000000C                                         ;00000001400020B3 B9 0C 00 00 00 
REP MOVSB                                                   ;00000001400020B8 F3 A4 
LEA RAX, invalid ptr SS : [ RSP +  + 0x000000B0 ]           ;00000001400020BA 48 8D 84 24 B0 00 00 00 
LEA RCX, invalid ptr SS : [ RSP +  + 0x000003D8 ]           ;00000001400020C2 48 8D 8C 24 D8 03 00 00 
MOV RDI, RAX                                                ;00000001400020CA 48 8B F8 
MOV RSI, RCX                                                ;00000001400020CD 48 8B F1 
MOV ECX, 0x0000000C                                         ;00000001400020D0 B9 0C 00 00 00 
REP MOVSB                                                   ;00000001400020D5 F3 A4 
LEA RAX, invalid ptr SS : [ RSP +  + 0x000000A0 ]           ;00000001400020D7 48 8D 84 24 A0 00 00 00 
LEA RCX, invalid ptr SS : [ RSP +  + 0x00000510 ]           ;00000001400020DF 48 8D 8C 24 10 05 00 00 
MOV RDI, RAX                                                ;00000001400020E7 48 8B F8 
MOV RSI, RCX                                                ;00000001400020EA 48 8B F1 
MOV ECX, 0x0000000C                                         ;00000001400020ED B9 0C 00 00 00 
REP MOVSB                                                   ;00000001400020F2 F3 A4 
LEA R8, invalid ptr SS : [ RSP +  + 0x000000B0 ]            ;00000001400020F4 4C 8D 84 24 B0 00 00 00 
LEA RDX, invalid ptr SS : [ RSP +  + 0x000000A0 ]           ;00000001400020FC 48 8D 94 24 A0 00 00 00 
LEA RCX, invalid ptr SS : [ RSP +  + 0x00000318 ]           ;0000000140002104 48 8D 8C 24 18 03 00 00 
CALL 0x0000057F                                             ;000000014000210C E8 7F 05 00 00 
LEA RCX, invalid ptr SS : [ RSP +  + 0x00000550 ]           ;0000000140002111 48 8D 8C 24 50 05 00 00 
MOV RDI, RCX                                                ;0000000140002119 48 8B F9 
MOV RSI, RAX                                                ;000000014000211C 48 8B F0 
MOV ECX, 0x0000000C                                         ;000000014000211F B9 0C 00 00 00 
REP MOVSB                                                   ;0000000140002124 F3 A4 
LEA RAX, invalid ptr SS : [ RSP +  + 0x000001C0 ]           ;0000000140002126 48 8D 84 24 C0 01 00 00 
LEA RCX, invalid ptr SS : [ RSP +  + 0x00000550 ]           ;000000014000212E 48 8D 8C 24 50 05 00 00 
MOV RDI, RAX                                                ;0000000140002136 48 8B F8 
MOV RSI, RCX                                                ;0000000140002139 48 8B F1 
MOV ECX, 0x0000000C                                         ;000000014000213C B9 0C 00 00 00 
REP MOVSB                                                   ;0000000140002141 F3 A4 
LEA RDX, invalid ptr SS : [ RSP +  + 0x000001C0 ]           ;0000000140002143 48 8D 94 24 C0 01 00 00 
LEA RCX, invalid ptr SS : [ RSP +  + 0x00000348 ]           ;000000014000214B 48 8D 8C 24 48 03 00 00 
CALL 0x00000898                                             ;0000000140002153 E8 98 08 00 00 
LEA RCX, invalid ptr SS : [ RSP +  + 0x00000580 ]           ;0000000140002158 48 8D 8C 24 80 05 00 00 
MOV RDI, RCX                                                ;0000000140002160 48 8B F9 
MOV RSI, RAX                                                ;0000000140002163 48 8B F0 
MOV ECX, 0x0000000C                                         ;0000000140002166 B9 0C 00 00 00 
REP MOVSB                                                   ;000000014000216B F3 A4 
LEA RAX, invalid ptr SS : [ RSP +  + 0x00000590 ]           ;000000014000216D 48 8D 84 24 90 05 00 00 
LEA RCX, invalid ptr SS : [ RSP +  + 0x00000580 ]           ;0000000140002175 48 8D 8C 24 80 05 00 00 
MOV RDI, RAX                                                ;000000014000217D 48 8B F8 
MOV RSI, RCX                                                ;0000000140002180 48 8B F1 
MOV ECX, 0x0000000C                                         ;0000000140002183 B9 0C 00 00 00 
REP MOVSB                                                   ;0000000140002188 F3 A4 
LEA RAX, invalid ptr SS : [ RSP +  + 0x00000210 ]           ;000000014000218A 48 8D 84 24 10 02 00 00 
LEA RCX, invalid ptr SS : [ RSP +  + 0x00000590 ]           ;0000000140002192 48 8D 8C 24 90 05 00 00 
MOV RDI, RAX                                                ;000000014000219A 48 8B F8 
MOV RSI, RCX                                                ;000000014000219D 48 8B F1 
MOV ECX, 0x0000000C                                         ;00000001400021A0 B9 0C 00 00 00 
REP MOVSB                                                   ;00000001400021A5 F3 A4 
LEA RAX, invalid ptr SS : [ RSP +  + 0x000001E0 ]           ;00000001400021A7 48 8D 84 24 E0 01 00 00 
LEA RCX, invalid ptr SS : [ RSP +  + 0x000003D8 ]           ;00000001400021AF 48 8D 8C 24 D8 03 00 00 
MOV RDI, RAX                                                ;00000001400021B7 48 8B F8 
MOV RSI, RCX                                                ;00000001400021BA 48 8B F1 
MOV ECX, 0x0000000C                                         ;00000001400021BD B9 0C 00 00 00 
REP MOVSB                                                   ;00000001400021C2 F3 A4 
LEA R9, invalid ptr SS : [ RSP +  + 0x00000210 ]            ;00000001400021C4 4C 8D 8C 24 10 02 00 00 
LEA R8, invalid ptr SS : [ RSP +  + 0x000001E0 ]            ;00000001400021CC 4C 8D 84 24 E0 01 00 00 
LEA RDX, invalid ptr SS : [ RSP +  + 0x00000170 ]           ;00000001400021D4 48 8D 94 24 70 01 00 00 
LEA RCX, invalid ptr SS : [ RSP +  + 0x00000398 ]           ;00000001400021DC 48 8D 8C 24 98 03 00 00 
CALL 0xFFFFEE17                                             ;00000001400021E4 E8 17 EE FF FF 
LEA RCX, invalid ptr SS : [ RSP +  + 0x000005D0 ]           ;00000001400021E9 48 8D 8C 24 D0 05 00 00 
MOV RDI, RCX                                                ;00000001400021F1 48 8B F9 
MOV RSI, RAX                                                ;00000001400021F4 48 8B F0 
MOV ECX, 0x00000010                                         ;00000001400021F7 B9 10 00 00 00 
REP MOVSB                                                   ;00000001400021FC F3 A4 
LEA RAX, invalid ptr SS : [ RSP +  + 0x000003A8 ]           ;00000001400021FE 48 8D 84 24 A8 03 00 00 
LEA RCX, invalid ptr SS : [ RSP +  + 0x000005D0 ]           ;0000000140002206 48 8D 8C 24 D0 05 00 00 
MOV RDI, RAX                                                ;000000014000220E 48 8B F8 
MOV RSI, RCX                                                ;0000000140002211 48 8B F1 
MOV ECX, 0x00000010                                         ;0000000140002214 B9 10 00 00 00 
REP MOVSB                                                   ;0000000140002219 F3 A4 
MOVSS XMM0, oword ptr SS : [ RSP +  + 0x000003B4 ]          ;000000014000221B F3 0F 10 84 24 B4 03 00 00 
COMISS XMM0, CS : [ RIP + 0x000430FD ]                      ;0000000140002224 0F 2F 05 FD 30 04 00 
JB 0x12                                                     ;000000014000222B 72 12 
MOVSS XMM0, CS : [ RIP + 0x000430FF ]                       ;000000014000222D F3 0F 10 05 FF 30 04 00 
COMISS XMM0, oword ptr SS : [ RSP +  + 0x000003B4 ]         ;0000000140002235 0F 2F 84 24 B4 03 00 00 
JAE 0x0B                                                    ;000000014000223D 73 0B 
MOV dword ptr DS : [  ], 0x00000000                         ;000000014000223F C7 04 25 00 00 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;0000000140002246 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;0000000140002248 00 00 
MOVSS XMM0, oword ptr SS : [ RSP +  + 0x000003A8 ]          ;000000014000224A F3 0F 10 84 24 A8 03 00 00 
COMISS XMM0, CS : [ RIP + 0x000430CE ]                      ;0000000140002253 0F 2F 05 CE 30 04 00 
JB 0x12                                                     ;000000014000225A 72 12 
MOVSS XMM0, CS : [ RIP + 0x000430D0 ]                       ;000000014000225C F3 0F 10 05 D0 30 04 00 
COMISS XMM0, oword ptr SS : [ RSP +  + 0x000003A8 ]         ;0000000140002264 0F 2F 84 24 A8 03 00 00 
JAE 0x0B                                                    ;000000014000226C 73 0B 
MOV dword ptr DS : [  ], 0x00000000                         ;000000014000226E C7 04 25 00 00 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;0000000140002275 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;0000000140002277 00 00 
MOVSS XMM0, oword ptr SS : [ RSP +  + 0x000003AC ]          ;0000000140002279 F3 0F 10 84 24 AC 03 00 00 
COMISS XMM0, CS : [ RIP + 0x0004309F ]                      ;0000000140002282 0F 2F 05 9F 30 04 00 
JB 0x12                                                     ;0000000140002289 72 12 
MOVSS XMM0, CS : [ RIP + 0x000430A1 ]                       ;000000014000228B F3 0F 10 05 A1 30 04 00 
COMISS XMM0, oword ptr SS : [ RSP +  + 0x000003AC ]         ;0000000140002293 0F 2F 84 24 AC 03 00 00 
JAE 0x0B                                                    ;000000014000229B 73 0B 
MOV dword ptr DS : [  ], 0x00000000                         ;000000014000229D C7 04 25 00 00 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;00000001400022A4 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;00000001400022A6 00 00 
MOVSS XMM0, oword ptr SS : [ RSP +  + 0x000003B0 ]          ;00000001400022A8 F3 0F 10 84 24 B0 03 00 00 
COMISS XMM0, CS : [ RIP + 0x00043070 ]                      ;00000001400022B1 0F 2F 05 70 30 04 00 
JB 0x12                                                     ;00000001400022B8 72 12 
MOVSS XMM0, CS : [ RIP + 0x00043072 ]                       ;00000001400022BA F3 0F 10 05 72 30 04 00 
COMISS XMM0, oword ptr SS : [ RSP +  + 0x000003B0 ]         ;00000001400022C2 0F 2F 84 24 B0 03 00 00 
JAE 0x0B                                                    ;00000001400022CA 73 0B 
MOV dword ptr DS : [  ], 0x00000000                         ;00000001400022CC C7 04 25 00 00 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;00000001400022D3 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;00000001400022D5 00 00 
MOVSS XMM0, CS : [ RIP + 0x00043071 ]                       ;00000001400022D7 F3 0F 10 05 71 30 04 00 
MULSS XMM0, oword ptr SS : [ RSP +  + 0x000003B4 ]          ;00000001400022DF F3 0F 59 84 24 B4 03 00 00 
MOVSS oword ptr SS : [ RSP +  + 0x78 ], XMM0                ;00000001400022E8 F3 0F 11 44 24 78 
MOVSS XMM0, CS : [ RIP + 0x0004305A ]                       ;00000001400022EE F3 0F 10 05 5A 30 04 00 
MULSS XMM0, oword ptr SS : [ RSP +  + 0x000003A8 ]          ;00000001400022F6 F3 0F 59 84 24 A8 03 00 00 
MOVSS oword ptr SS : [ RSP +  + 0x7C ], XMM0                ;00000001400022FF F3 0F 11 44 24 7C 
MOVSS XMM0, CS : [ RIP + 0x00043043 ]                       ;0000000140002305 F3 0F 10 05 43 30 04 00 
MULSS XMM0, oword ptr SS : [ RSP +  + 0x000003AC ]          ;000000014000230D F3 0F 59 84 24 AC 03 00 00 
MOVSS oword ptr SS : [ RSP +  + 0x00000080 ], XMM0          ;0000000140002316 F3 0F 11 84 24 80 00 00 00 
MOVSS XMM0, CS : [ RIP + 0x00043029 ]                       ;000000014000231F F3 0F 10 05 29 30 04 00 
MULSS XMM0, oword ptr SS : [ RSP +  + 0x000003B0 ]          ;0000000140002327 F3 0F 59 84 24 B0 03 00 00 
MOVSS oword ptr SS : [ RSP +  + 0x00000084 ], XMM0          ;0000000140002330 F3 0F 11 84 24 84 00 00 00 
CVTTSS2SI RAX, oword ptr SS : [ RSP +  + 0x78 ]             ;0000000140002339 F3 48 0F 2C 44 24 78 
AND EAX, 0x000000FF                                         ;0000000140002340 25 FF 00 00 00 
SAL EAX, 0x18                                               ;0000000140002345 C1 E0 18 
CVTTSS2SI RCX, oword ptr SS : [ RSP +  + 0x7C ]             ;0000000140002348 F3 48 0F 2C 4C 24 7C 
AND ECX, 0x000000FF                                         ;000000014000234F 81 E1 FF 00 00 00 
SAL ECX, 0x10                                               ;0000000140002355 C1 E1 10 
OR EAX, ECX                                                 ;0000000140002358 0B C1 
CVTTSS2SI RCX, oword ptr SS : [ RSP +  + 0x00000080 ]       ;000000014000235A F3 48 0F 2C 8C 24 80 00 00 00 
AND ECX, 0x000000FF                                         ;0000000140002364 81 E1 FF 00 00 00 
SAL ECX, 0x08                                               ;000000014000236A C1 E1 08 
OR EAX, ECX                                                 ;000000014000236D 0B C1 
CVTTSS2SI RCX, oword ptr SS : [ RSP +  + 0x00000084 ]       ;000000014000236F F3 48 0F 2C 8C 24 84 00 00 00 
AND ECX, 0x000000FF                                         ;0000000140002379 81 E1 FF 00 00 00 
OR EAX, ECX                                                 ;000000014000237F 0B C1 
MOV dword ptr SS : [ RSP +  + 0x00000088 ], EAX             ;0000000140002381 89 84 24 88 00 00 00 
MOV RAX, qword ptr SS : [ RSP +  + 0x00000090 ]             ;0000000140002388 48 8B 84 24 90 00 00 00 
MOV ECX, dword ptr SS : [ RSP +  + 0x00000088 ]             ;0000000140002390 8B 8C 24 88 00 00 00 
MOV dword ptr DS : [ RAX ], ECX                             ;0000000140002397 89 08 
MOV RAX, qword ptr SS : [ RSP +  + 0x00000090 ]             ;0000000140002399 48 8B 84 24 90 00 00 00 
ADD RAX, 0x04                                               ;00000001400023A1 48 83 C0 04 
MOV qword ptr SS : [ RSP +  + 0x00000090 ], RAX             ;00000001400023A5 48 89 84 24 90 00 00 00 
JMP 0xFFFFF9A4                                              ;00000001400023AD E9 A4 F9 FF FF 
JMP 0xFFFFF94B                                              ;00000001400023B2 E9 4B F9 FF FF 
LEA RDX, CS : [ RIP + 0x00042F52 ]                          ;00000001400023B7 48 8D 15 52 2F 04 00 
LEA RCX, CS : [ RIP + 0x00042F53 ]                          ;00000001400023BE 48 8D 0D 53 2F 04 00 
CALL 0x000081A6                                             ;00000001400023C5 E8 A6 81 00 00 
MOV qword ptr SS : [ RSP +  + 0x60 ], RAX                   ;00000001400023CA 48 89 44 24 60 
CMP qword ptr SS : [ RSP +  + 0x60 ], 0x00                  ;00000001400023CF 48 83 7C 24 60 00 
JZ 0x00000138                                               ;00000001400023D5 0F 84 38 01 00 00 
LEA RAX, invalid ptr SS : [ RSP +  + 0x000003F0 ]           ;00000001400023DB 48 8D 84 24 F0 03 00 00 
MOV RDI, RAX                                                ;00000001400023E3 48 8B F8 
XOR EAX, EAX                                                ;00000001400023E6 33 C0 
MOV ECX, 0x00000042                                         ;00000001400023E8 B9 42 00 00 00 
REP STOSB                                                   ;00000001400023ED F3 AA 
MOV EAX, 0x00004D42                                         ;00000001400023EF B8 42 4D 00 00 
MOV word ptr SS : [ RSP +  + 0x000003F0 ], AX               ;00000001400023F4 66 89 84 24 F0 03 00 00 
MOV EAX, dword ptr SS : [ RSP +  + 0x38 ]                   ;00000001400023FC 8B 44 24 38 
ADD RAX, 0x42                                               ;0000000140002400 48 83 C0 42 
MOV dword ptr SS : [ RSP +  + 0x000003F2 ], EAX             ;0000000140002404 89 84 24 F2 03 00 00 
XOR EAX, EAX                                                ;000000014000240B 33 C0 
MOV word ptr SS : [ RSP +  + 0x000003F6 ], AX               ;000000014000240D 66 89 84 24 F6 03 00 00 
XOR EAX, EAX                                                ;0000000140002415 33 C0 
MOV word ptr SS : [ RSP +  + 0x000003F8 ], AX               ;0000000140002417 66 89 84 24 F8 03 00 00 
MOV dword ptr SS : [ RSP +  + 0x000003FA ], 0x00000042      ;000000014000241F C7 84 24 FA 03 00 00 42 00 00 00 
MOV dword ptr SS : [ RSP +  + 0x000003FE ], 0x00000028      ;000000014000242A C7 84 24 FE 03 00 00 28 00 00 00 
MOV EAX, dword ptr SS : [ RSP +  + 0x40 ]                   ;0000000140002435 8B 44 24 40 
MOV dword ptr SS : [ RSP +  + 0x00000402 ], EAX             ;0000000140002439 89 84 24 02 04 00 00 
MOV EAX, dword ptr SS : [ RSP +  + 0x44 ]                   ;0000000140002440 8B 44 24 44 
NEG EAX                                                     ;0000000140002444 F7 D8 
MOV dword ptr SS : [ RSP +  + 0x00000406 ], EAX             ;0000000140002446 89 84 24 06 04 00 00 
MOV EAX, 0x00000001                                         ;000000014000244D B8 01 00 00 00 
MOV word ptr SS : [ RSP +  + 0x0000040A ], AX               ;0000000140002452 66 89 84 24 0A 04 00 00 
MOV EAX, 0x00000020                                         ;000000014000245A B8 20 00 00 00 
MOV word ptr SS : [ RSP +  + 0x0000040C ], AX               ;000000014000245F 66 89 84 24 0C 04 00 00 
MOV dword ptr SS : [ RSP +  + 0x0000040E ], 0x00000000      ;0000000140002467 C7 84 24 0E 04 00 00 00 00 00 00 
MOV EAX, dword ptr SS : [ RSP +  + 0x38 ]                   ;0000000140002472 8B 44 24 38 
MOV dword ptr SS : [ RSP +  + 0x00000412 ], EAX             ;0000000140002476 89 84 24 12 04 00 00 
MOV dword ptr SS : [ RSP +  + 0x00000416 ], 0x000003E8      ;000000014000247D C7 84 24 16 04 00 00 E8 03 00 00 
MOV dword ptr SS : [ RSP +  + 0x0000041A ], 0x000003E8      ;0000000140002488 C7 84 24 1A 04 00 00 E8 03 00 00 
MOV dword ptr SS : [ RSP +  + 0x0000041E ], 0x00000000      ;0000000140002493 C7 84 24 1E 04 00 00 00 00 00 00 
MOV dword ptr SS : [ RSP +  + 0x00000422 ], 0x00000000      ;000000014000249E C7 84 24 22 04 00 00 00 00 00 00 
MOV dword ptr SS : [ RSP +  + 0x00000426 ], 0x00FF0000      ;00000001400024A9 C7 84 24 26 04 00 00 00 00 FF 00 
MOV dword ptr SS : [ RSP +  + 0x0000042A ], 0x0000FF00      ;00000001400024B4 C7 84 24 2A 04 00 00 00 FF 00 00 
MOV dword ptr SS : [ RSP +  + 0x0000042E ], 0x000000FF      ;00000001400024BF C7 84 24 2E 04 00 00 FF 00 00 00 
MOV R9, qword ptr SS : [ RSP +  + 0x60 ]                    ;00000001400024CA 4C 8B 4C 24 60 
MOV R8D, 0x00000001                                         ;00000001400024CF 41 B8 01 00 00 00 
MOV EDX, 0x00000042                                         ;00000001400024D5 BA 42 00 00 00 
LEA RCX, invalid ptr SS : [ RSP +  + 0x000003F0 ]           ;00000001400024DA 48 8D 8C 24 F0 03 00 00 
CALL 0x00008AF9                                             ;00000001400024E2 E8 F9 8A 00 00 
MOV EAX, dword ptr SS : [ RSP +  + 0x40 ]                   ;00000001400024E7 8B 44 24 40 
IMUL EAX, dword ptr SS : [ RSP +  + 0x44 ]                  ;00000001400024EB 0F AF 44 24 44 
                                                            ;00000001400024F0 48 98 
MOV R9, qword ptr SS : [ RSP +  + 0x60 ]                    ;00000001400024F2 4C 8B 4C 24 60 
MOV R8, RAX                                                 ;00000001400024F7 4C 8B C0 
MOV EDX, 0x00000004                                         ;00000001400024FA BA 04 00 00 00 
MOV RCX, qword ptr SS : [ RSP +  + 0x50 ]                   ;00000001400024FF 48 8B 4C 24 50 
CALL 0x00008AD7                                             ;0000000140002504 E8 D7 8A 00 00 
MOV RCX, qword ptr SS : [ RSP +  + 0x60 ]                   ;0000000140002509 48 8B 4C 24 60 
CALL 0x00007BFD                                             ;000000014000250E E8 FD 7B 00 00 
MOV RCX, qword ptr SS : [ RSP +  + 0x50 ]                   ;0000000140002513 48 8B 4C 24 50 
CALL 0x000134D3                                             ;0000000140002518 E8 D3 34 01 00 
XOR EAX, EAX                                                ;000000014000251D 33 C0 
MOV RCX, qword ptr SS : [ RSP +  + 0x000006B0 ]             ;000000014000251F 48 8B 8C 24 B0 06 00 00 
XOR RCX, RSP                                                ;0000000140002527 48 33 CC 
CALL 0x00000921                                             ;000000014000252A E8 21 09 00 00 
ADD RSP, 0x000006C8                                         ;000000014000252F 48 81 C4 C8 06 00 00 
POP EDI                                                     ;0000000140002536 5F 
POP ESI                                                     ;0000000140002537 5E 
RETN                                                        ;0000000140002538 C3 
INT 3                                                       ;0000000140002539 CC 
INT 3                                                       ;000000014000253A CC 
INT 3                                                       ;000000014000253B CC 
INT 3                                                       ;000000014000253C CC 
INT 3                                                       ;000000014000253D CC 
INT 3                                                       ;000000014000253E CC 
INT 3                                                       ;000000014000253F CC 
MOV qword ptr SS : [ RSP +  + 0x18 ], R8                    ;0000000140002540 4C 89 44 24 18 
MOVSS oword ptr SS : [ RSP +  + 0x10 ], XMM1                ;0000000140002545 F3 0F 11 4C 24 10 
MOV qword ptr SS : [ RSP +  + 0x08 ], RCX                   ;000000014000254B 48 89 4C 24 08 
PUSH ESI                                                    ;0000000140002550 56 
PUSH EDI                                                    ;0000000140002551 57 
SUB RSP, 0x28                                               ;0000000140002552 48 83 EC 28 
MOV RAX, CS : [ RIP + 0x00057AAB ]                          ;0000000140002556 48 8B 05 AB 7A 05 00 
XOR RAX, RSP                                                ;000000014000255D 48 33 C4 
MOV qword ptr SS : [ RSP +  + 0x10 ], RAX                   ;0000000140002560 48 89 44 24 10 
MOV RAX, qword ptr SS : [ RSP +  + 0x50 ]                   ;0000000140002565 48 8B 44 24 50 
MOVSS XMM0, oword ptr SS : [ RSP +  + 0x48 ]                ;000000014000256A F3 0F 10 44 24 48 
MULSS XMM0, oword ptr DS : [ RAX ]                          ;0000000140002570 F3 0F 59 00 
MOVSS oword ptr SS : [ RSP +  ], XMM0                       ;0000000140002574 F3 0F 11 04 24 
MOV RAX, qword ptr SS : [ RSP +  + 0x50 ]                   ;0000000140002579 48 8B 44 24 50 
MOVSS XMM0, oword ptr SS : [ RSP +  + 0x48 ]                ;000000014000257E F3 0F 10 44 24 48 
MULSS XMM0, oword ptr DS : [ RAX + 0x04 ]                   ;0000000140002584 F3 0F 59 40 04 
MOVSS oword ptr SS : [ RSP +  + 0x04 ], XMM0                ;0000000140002589 F3 0F 11 44 24 04 
MOV RAX, qword ptr SS : [ RSP +  + 0x50 ]                   ;000000014000258F 48 8B 44 24 50 
MOVSS XMM0, oword ptr SS : [ RSP +  + 0x48 ]                ;0000000140002594 F3 0F 10 44 24 48 
MULSS XMM0, oword ptr DS : [ RAX + 0x08 ]                   ;000000014000259A F3 0F 59 40 08 
MOVSS oword ptr SS : [ RSP +  + 0x08 ], XMM0                ;000000014000259F F3 0F 11 44 24 08 
LEA RAX, invalid ptr SS : [ RSP +  ]                        ;00000001400025A5 48 8D 04 24 
MOV RDI, qword ptr SS : [ RSP +  + 0x40 ]                   ;00000001400025A9 48 8B 7C 24 40 
MOV RSI, RAX                                                ;00000001400025AE 48 8B F0 
MOV ECX, 0x0000000C                                         ;00000001400025B1 B9 0C 00 00 00 
REP MOVSB                                                   ;00000001400025B6 F3 A4 
MOV RAX, qword ptr SS : [ RSP +  + 0x40 ]                   ;00000001400025B8 48 8B 44 24 40 
MOV RCX, qword ptr SS : [ RSP +  + 0x10 ]                   ;00000001400025BD 48 8B 4C 24 10 
XOR RCX, RSP                                                ;00000001400025C2 48 33 CC 
CALL 0x00000886                                             ;00000001400025C5 E8 86 08 00 00 
ADD RSP, 0x28                                               ;00000001400025CA 48 83 C4 28 
POP EDI                                                     ;00000001400025CE 5F 
POP ESI                                                     ;00000001400025CF 5E 
RETN                                                        ;00000001400025D0 C3 
INT 3                                                       ;00000001400025D1 CC 
INT 3                                                       ;00000001400025D2 CC 
INT 3                                                       ;00000001400025D3 CC 
INT 3                                                       ;00000001400025D4 CC 
INT 3                                                       ;00000001400025D5 CC 
INT 3                                                       ;00000001400025D6 CC 
INT 3                                                       ;00000001400025D7 CC 
INT 3                                                       ;00000001400025D8 CC 
INT 3                                                       ;00000001400025D9 CC 
INT 3                                                       ;00000001400025DA CC 
INT 3                                                       ;00000001400025DB CC 
INT 3                                                       ;00000001400025DC CC 
INT 3                                                       ;00000001400025DD CC 
INT 3                                                       ;00000001400025DE CC 
INT 3                                                       ;00000001400025DF CC 
MOVSS oword ptr SS : [ RSP +  + 0x18 ], XMM2                ;00000001400025E0 F3 0F 11 54 24 18 
MOV qword ptr SS : [ RSP +  + 0x10 ], RDX                   ;00000001400025E6 48 89 54 24 10 
MOV qword ptr SS : [ RSP +  + 0x08 ], RCX                   ;00000001400025EB 48 89 4C 24 08 
PUSH ESI                                                    ;00000001400025F0 56 
PUSH EDI                                                    ;00000001400025F1 57 
SUB RSP, 0x78                                               ;00000001400025F2 48 83 EC 78 
MOV RAX, CS : [ RIP + 0x00057A0B ]                          ;00000001400025F6 48 8B 05 0B 7A 05 00 
XOR RAX, RSP                                                ;00000001400025FD 48 33 C4 
MOV qword ptr SS : [ RSP +  + 0x60 ], RAX                   ;0000000140002600 48 89 44 24 60 
LEA RAX, invalid ptr SS : [ RSP +  + 0x20 ]                 ;0000000140002605 48 8D 44 24 20 
MOV RDI, RAX                                                ;000000014000260A 48 8B F8 
MOV RSI, qword ptr SS : [ RSP +  + 0x00000098 ]             ;000000014000260D 48 8B B4 24 98 00 00 00 
MOV ECX, 0x0000000C                                         ;0000000140002615 B9 0C 00 00 00 
REP MOVSB                                                   ;000000014000261A F3 A4 
LEA R8, invalid ptr SS : [ RSP +  + 0x20 ]                  ;000000014000261C 4C 8D 44 24 20 
MOVSS XMM1, oword ptr SS : [ RSP +  + 0x000000A0 ]          ;0000000140002621 F3 0F 10 8C 24 A0 00 00 00 
LEA RCX, invalid ptr SS : [ RSP +  + 0x30 ]                 ;000000014000262A 48 8D 4C 24 30 
CALL 0xFFFFFF0C                                             ;000000014000262F E8 0C FF FF FF 
LEA RCX, invalid ptr SS : [ RSP +  + 0x40 ]                 ;0000000140002634 48 8D 4C 24 40 
MOV RDI, RCX                                                ;0000000140002639 48 8B F9 
MOV RSI, RAX                                                ;000000014000263C 48 8B F0 
MOV ECX, 0x0000000C                                         ;000000014000263F B9 0C 00 00 00 
REP MOVSB                                                   ;0000000140002644 F3 A4 
LEA RAX, invalid ptr SS : [ RSP +  + 0x50 ]                 ;0000000140002646 48 8D 44 24 50 
LEA RCX, invalid ptr SS : [ RSP +  + 0x40 ]                 ;000000014000264B 48 8D 4C 24 40 
MOV RDI, RAX                                                ;0000000140002650 48 8B F8 
MOV RSI, RCX                                                ;0000000140002653 48 8B F1 
MOV ECX, 0x0000000C                                         ;0000000140002656 B9 0C 00 00 00 
REP MOVSB                                                   ;000000014000265B F3 A4 
LEA RAX, invalid ptr SS : [ RSP +  + 0x50 ]                 ;000000014000265D 48 8D 44 24 50 
MOV RDI, qword ptr SS : [ RSP +  + 0x00000090 ]             ;0000000140002662 48 8B BC 24 90 00 00 00 
MOV RSI, RAX                                                ;000000014000266A 48 8B F0 
MOV ECX, 0x0000000C                                         ;000000014000266D B9 0C 00 00 00 
REP MOVSB                                                   ;0000000140002672 F3 A4 
MOV RAX, qword ptr SS : [ RSP +  + 0x00000090 ]             ;0000000140002674 48 8B 84 24 90 00 00 00 
MOV RCX, qword ptr SS : [ RSP +  + 0x60 ]                   ;000000014000267C 48 8B 4C 24 60 
XOR RCX, RSP                                                ;0000000140002681 48 33 CC 
CALL 0x000007C7                                             ;0000000140002684 E8 C7 07 00 00 
ADD RSP, 0x78                                               ;0000000140002689 48 83 C4 78 
POP EDI                                                     ;000000014000268D 5F 
POP ESI                                                     ;000000014000268E 5E 
RETN                                                        ;000000014000268F C3 
MOV qword ptr SS : [ RSP +  + 0x18 ], R8                    ;0000000140002690 4C 89 44 24 18 
MOV qword ptr SS : [ RSP +  + 0x10 ], RDX                   ;0000000140002695 48 89 54 24 10 
MOV qword ptr SS : [ RSP +  + 0x08 ], RCX                   ;000000014000269A 48 89 4C 24 08 
PUSH ESI                                                    ;000000014000269F 56 
PUSH EDI                                                    ;00000001400026A0 57 
SUB RSP, 0x28                                               ;00000001400026A1 48 83 EC 28 
MOV RAX, CS : [ RIP + 0x0005795C ]                          ;00000001400026A5 48 8B 05 5C 79 05 00 
XOR RAX, RSP                                                ;00000001400026AC 48 33 C4 
MOV qword ptr SS : [ RSP +  + 0x10 ], RAX                   ;00000001400026AF 48 89 44 24 10 
MOV RAX, qword ptr SS : [ RSP +  + 0x48 ]                   ;00000001400026B4 48 8B 44 24 48 
MOV RCX, qword ptr SS : [ RSP +  + 0x50 ]                   ;00000001400026B9 48 8B 4C 24 50 
MOVSS XMM0, oword ptr DS : [ RAX ]                          ;00000001400026BE F3 0F 10 00 
SUBSS XMM0, oword ptr DS : [ RCX ]                          ;00000001400026C2 F3 0F 5C 01 
MOVSS oword ptr SS : [ RSP +  ], XMM0                       ;00000001400026C6 F3 0F 11 04 24 
MOV RAX, qword ptr SS : [ RSP +  + 0x48 ]                   ;00000001400026CB 48 8B 44 24 48 
MOV RCX, qword ptr SS : [ RSP +  + 0x50 ]                   ;00000001400026D0 48 8B 4C 24 50 
MOVSS XMM0, oword ptr DS : [ RAX + 0x04 ]                   ;00000001400026D5 F3 0F 10 40 04 
SUBSS XMM0, oword ptr DS : [ RCX + 0x04 ]                   ;00000001400026DA F3 0F 5C 41 04 
MOVSS oword ptr SS : [ RSP +  + 0x04 ], XMM0                ;00000001400026DF F3 0F 11 44 24 04 
MOV RAX, qword ptr SS : [ RSP +  + 0x48 ]                   ;00000001400026E5 48 8B 44 24 48 
MOV RCX, qword ptr SS : [ RSP +  + 0x50 ]                   ;00000001400026EA 48 8B 4C 24 50 
MOVSS XMM0, oword ptr DS : [ RAX + 0x08 ]                   ;00000001400026EF F3 0F 10 40 08 
SUBSS XMM0, oword ptr DS : [ RCX + 0x08 ]                   ;00000001400026F4 F3 0F 5C 41 08 
MOVSS oword ptr SS : [ RSP +  + 0x08 ], XMM0                ;00000001400026F9 F3 0F 11 44 24 08 
LEA RAX, invalid ptr SS : [ RSP +  ]                        ;00000001400026FF 48 8D 04 24 
MOV RDI, qword ptr SS : [ RSP +  + 0x40 ]                   ;0000000140002703 48 8B 7C 24 40 
MOV RSI, RAX                                                ;0000000140002708 48 8B F0 
MOV ECX, 0x0000000C                                         ;000000014000270B B9 0C 00 00 00 
REP MOVSB                                                   ;0000000140002710 F3 A4 
MOV RAX, qword ptr SS : [ RSP +  + 0x40 ]                   ;0000000140002712 48 8B 44 24 40 
MOV RCX, qword ptr SS : [ RSP +  + 0x10 ]                   ;0000000140002717 48 8B 4C 24 10 
XOR RCX, RSP                                                ;000000014000271C 48 33 CC 
CALL 0x0000072C                                             ;000000014000271F E8 2C 07 00 00 
ADD RSP, 0x28                                               ;0000000140002724 48 83 C4 28 
POP EDI                                                     ;0000000140002728 5F 
POP ESI                                                     ;0000000140002729 5E 
RETN                                                        ;000000014000272A C3 
INT 3                                                       ;000000014000272B CC 
INT 3                                                       ;000000014000272C CC 
INT 3                                                       ;000000014000272D CC 
INT 3                                                       ;000000014000272E CC 
INT 3                                                       ;000000014000272F CC 
MOV qword ptr SS : [ RSP +  + 0x18 ], R8                    ;0000000140002730 4C 89 44 24 18 
MOV qword ptr SS : [ RSP +  + 0x10 ], RDX                   ;0000000140002735 48 89 54 24 10 
MOV qword ptr SS : [ RSP +  + 0x08 ], RCX                   ;000000014000273A 48 89 4C 24 08 
PUSH ESI                                                    ;000000014000273F 56 
PUSH EDI                                                    ;0000000140002740 57 
SUB RSP, 0x28                                               ;0000000140002741 48 83 EC 28 
MOV RAX, CS : [ RIP + 0x000578BC ]                          ;0000000140002745 48 8B 05 BC 78 05 00 
XOR RAX, RSP                                                ;000000014000274C 48 33 C4 
MOV qword ptr SS : [ RSP +  + 0x10 ], RAX                   ;000000014000274F 48 89 44 24 10 
MOV RAX, qword ptr SS : [ RSP +  + 0x48 ]                   ;0000000140002754 48 8B 44 24 48 
MOV RCX, qword ptr SS : [ RSP +  + 0x50 ]                   ;0000000140002759 48 8B 4C 24 50 
MOVSS XMM0, oword ptr DS : [ RAX ]                          ;000000014000275E F3 0F 10 00 
ADDSS XMM0, oword ptr DS : [ RCX ]                          ;0000000140002762 F3 0F 58 01 
MOVSS oword ptr SS : [ RSP +  ], XMM0                       ;0000000140002766 F3 0F 11 04 24 
MOV RAX, qword ptr SS : [ RSP +  + 0x48 ]                   ;000000014000276B 48 8B 44 24 48 
MOV RCX, qword ptr SS : [ RSP +  + 0x50 ]                   ;0000000140002770 48 8B 4C 24 50 
MOVSS XMM0, oword ptr DS : [ RAX + 0x04 ]                   ;0000000140002775 F3 0F 10 40 04 
ADDSS XMM0, oword ptr DS : [ RCX + 0x04 ]                   ;000000014000277A F3 0F 58 41 04 
MOVSS oword ptr SS : [ RSP +  + 0x04 ], XMM0                ;000000014000277F F3 0F 11 44 24 04 
MOV RAX, qword ptr SS : [ RSP +  + 0x48 ]                   ;0000000140002785 48 8B 44 24 48 
MOV RCX, qword ptr SS : [ RSP +  + 0x50 ]                   ;000000014000278A 48 8B 4C 24 50 
MOVSS XMM0, oword ptr DS : [ RAX + 0x08 ]                   ;000000014000278F F3 0F 10 40 08 
ADDSS XMM0, oword ptr DS : [ RCX + 0x08 ]                   ;0000000140002794 F3 0F 58 41 08 
MOVSS oword ptr SS : [ RSP +  + 0x08 ], XMM0                ;0000000140002799 F3 0F 11 44 24 08 
LEA RAX, invalid ptr SS : [ RSP +  ]                        ;000000014000279F 48 8D 04 24 
MOV RDI, qword ptr SS : [ RSP +  + 0x40 ]                   ;00000001400027A3 48 8B 7C 24 40 
MOV RSI, RAX                                                ;00000001400027A8 48 8B F0 
MOV ECX, 0x0000000C                                         ;00000001400027AB B9 0C 00 00 00 
REP MOVSB                                                   ;00000001400027B0 F3 A4 
MOV RAX, qword ptr SS : [ RSP +  + 0x40 ]                   ;00000001400027B2 48 8B 44 24 40 
MOV RCX, qword ptr SS : [ RSP +  + 0x10 ]                   ;00000001400027B7 48 8B 4C 24 10 
XOR RCX, RSP                                                ;00000001400027BC 48 33 CC 
CALL 0x0000068C                                             ;00000001400027BF E8 8C 06 00 00 
ADD RSP, 0x28                                               ;00000001400027C4 48 83 C4 28 
POP EDI                                                     ;00000001400027C8 5F 
POP ESI                                                     ;00000001400027C9 5E 
RETN                                                        ;00000001400027CA C3 
INT 3                                                       ;00000001400027CB CC 
INT 3                                                       ;00000001400027CC CC 
INT 3                                                       ;00000001400027CD CC 
INT 3                                                       ;00000001400027CE CC 
INT 3                                                       ;00000001400027CF CC 
MOV qword ptr SS : [ RSP +  + 0x18 ], R8                    ;00000001400027D0 4C 89 44 24 18 
MOV qword ptr SS : [ RSP +  + 0x10 ], RDX                   ;00000001400027D5 48 89 54 24 10 
MOV qword ptr SS : [ RSP +  + 0x08 ], RCX                   ;00000001400027DA 48 89 4C 24 08 
PUSH ESI                                                    ;00000001400027DF 56 
PUSH EDI                                                    ;00000001400027E0 57 
SUB RSP, 0x28                                               ;00000001400027E1 48 83 EC 28 
MOV RAX, CS : [ RIP + 0x0005781C ]                          ;00000001400027E5 48 8B 05 1C 78 05 00 
XOR RAX, RSP                                                ;00000001400027EC 48 33 C4 
MOV qword ptr SS : [ RSP +  + 0x10 ], RAX                   ;00000001400027EF 48 89 44 24 10 
LEA RAX, invalid ptr SS : [ RSP +  ]                        ;00000001400027F4 48 8D 04 24 
MOV RDI, RAX                                                ;00000001400027F8 48 8B F8 
XOR EAX, EAX                                                ;00000001400027FB 33 C0 
MOV ECX, 0x0000000C                                         ;00000001400027FD B9 0C 00 00 00 
REP STOSB                                                   ;0000000140002802 F3 AA 
MOV RAX, qword ptr SS : [ RSP +  + 0x48 ]                   ;0000000140002804 48 8B 44 24 48 
MOV RCX, qword ptr SS : [ RSP +  + 0x50 ]                   ;0000000140002809 48 8B 4C 24 50 
MOVSS XMM0, oword ptr DS : [ RAX + 0x04 ]                   ;000000014000280E F3 0F 10 40 04 
MULSS XMM0, oword ptr DS : [ RCX + 0x08 ]                   ;0000000140002813 F3 0F 59 41 08 
MOV RAX, qword ptr SS : [ RSP +  + 0x48 ]                   ;0000000140002818 48 8B 44 24 48 
MOV RCX, qword ptr SS : [ RSP +  + 0x50 ]                   ;000000014000281D 48 8B 4C 24 50 
MOVSS XMM1, oword ptr DS : [ RAX + 0x08 ]                   ;0000000140002822 F3 0F 10 48 08 
MULSS XMM1, oword ptr DS : [ RCX + 0x04 ]                   ;0000000140002827 F3 0F 59 49 04 
SUBSS XMM0, XMM1                                            ;000000014000282C F3 0F 5C C1 
MOVSS oword ptr SS : [ RSP +  ], XMM0                       ;0000000140002830 F3 0F 11 04 24 
MOV RAX, qword ptr SS : [ RSP +  + 0x48 ]                   ;0000000140002835 48 8B 44 24 48 
MOV RCX, qword ptr SS : [ RSP +  + 0x50 ]                   ;000000014000283A 48 8B 4C 24 50 
MOVSS XMM0, oword ptr DS : [ RAX + 0x08 ]                   ;000000014000283F F3 0F 10 40 08 
MULSS XMM0, oword ptr DS : [ RCX ]                          ;0000000140002844 F3 0F 59 01 
MOV RAX, qword ptr SS : [ RSP +  + 0x48 ]                   ;0000000140002848 48 8B 44 24 48 
MOV RCX, qword ptr SS : [ RSP +  + 0x50 ]                   ;000000014000284D 48 8B 4C 24 50 
MOVSS XMM1, oword ptr DS : [ RAX ]                          ;0000000140002852 F3 0F 10 08 
MULSS XMM1, oword ptr DS : [ RCX + 0x08 ]                   ;0000000140002856 F3 0F 59 49 08 
SUBSS XMM0, XMM1                                            ;000000014000285B F3 0F 5C C1 
MOVSS oword ptr SS : [ RSP +  + 0x04 ], XMM0                ;000000014000285F F3 0F 11 44 24 04 
MOV RAX, qword ptr SS : [ RSP +  + 0x48 ]                   ;0000000140002865 48 8B 44 24 48 
MOV RCX, qword ptr SS : [ RSP +  + 0x50 ]                   ;000000014000286A 48 8B 4C 24 50 
MOVSS XMM0, oword ptr DS : [ RAX ]                          ;000000014000286F F3 0F 10 00 
MULSS XMM0, oword ptr DS : [ RCX + 0x04 ]                   ;0000000140002873 F3 0F 59 41 04 
MOV RAX, qword ptr SS : [ RSP +  + 0x48 ]                   ;0000000140002878 48 8B 44 24 48 
MOV RCX, qword ptr SS : [ RSP +  + 0x50 ]                   ;000000014000287D 48 8B 4C 24 50 
MOVSS XMM1, oword ptr DS : [ RAX + 0x04 ]                   ;0000000140002882 F3 0F 10 48 04 
MULSS XMM1, oword ptr DS : [ RCX ]                          ;0000000140002887 F3 0F 59 09 
SUBSS XMM0, XMM1                                            ;000000014000288B F3 0F 5C C1 
MOVSS oword ptr SS : [ RSP +  + 0x08 ], XMM0                ;000000014000288F F3 0F 11 44 24 08 
LEA RAX, invalid ptr SS : [ RSP +  ]                        ;0000000140002895 48 8D 04 24 
MOV RDI, qword ptr SS : [ RSP +  + 0x40 ]                   ;0000000140002899 48 8B 7C 24 40 
MOV RSI, RAX                                                ;000000014000289E 48 8B F0 
MOV ECX, 0x0000000C                                         ;00000001400028A1 B9 0C 00 00 00 
REP MOVSB                                                   ;00000001400028A6 F3 A4 
MOV RAX, qword ptr SS : [ RSP +  + 0x40 ]                   ;00000001400028A8 48 8B 44 24 40 
MOV RCX, qword ptr SS : [ RSP +  + 0x10 ]                   ;00000001400028AD 48 8B 4C 24 10 
XOR RCX, RSP                                                ;00000001400028B2 48 33 CC 
CALL 0x00000596                                             ;00000001400028B5 E8 96 05 00 00 
ADD RSP, 0x28                                               ;00000001400028BA 48 83 C4 28 
POP EDI                                                     ;00000001400028BE 5F 
POP ESI                                                     ;00000001400028BF 5E 
RETN                                                        ;00000001400028C0 C3 
INT 3                                                       ;00000001400028C1 CC 
INT 3                                                       ;00000001400028C2 CC 
INT 3                                                       ;00000001400028C3 CC 
INT 3                                                       ;00000001400028C4 CC 
INT 3                                                       ;00000001400028C5 CC 
INT 3                                                       ;00000001400028C6 CC 
INT 3                                                       ;00000001400028C7 CC 
INT 3                                                       ;00000001400028C8 CC 
INT 3                                                       ;00000001400028C9 CC 
INT 3                                                       ;00000001400028CA CC 
INT 3                                                       ;00000001400028CB CC 
INT 3                                                       ;00000001400028CC CC 
INT 3                                                       ;00000001400028CD CC 
INT 3                                                       ;00000001400028CE CC 
INT 3                                                       ;00000001400028CF CC 
MOV qword ptr SS : [ RSP +  + 0x10 ], RDX                   ;00000001400028D0 48 89 54 24 10 
MOV qword ptr SS : [ RSP +  + 0x08 ], RCX                   ;00000001400028D5 48 89 4C 24 08 
SUB RSP, 0x18                                               ;00000001400028DA 48 83 EC 18 
XORPS XMM0, XMM0                                            ;00000001400028DE 0F 57 C0 
MOVSS oword ptr SS : [ RSP +  ], XMM0                       ;00000001400028E1 F3 0F 11 04 24 
MOV RAX, qword ptr SS : [ RSP +  + 0x20 ]                   ;00000001400028E6 48 8B 44 24 20 
MOV RCX, qword ptr SS : [ RSP +  + 0x28 ]                   ;00000001400028EB 48 8B 4C 24 28 
MOVSS XMM0, oword ptr DS : [ RAX ]                          ;00000001400028F0 F3 0F 10 00 
MULSS XMM0, oword ptr DS : [ RCX ]                          ;00000001400028F4 F3 0F 59 01 
MOV RAX, qword ptr SS : [ RSP +  + 0x20 ]                   ;00000001400028F8 48 8B 44 24 20 
MOV RCX, qword ptr SS : [ RSP +  + 0x28 ]                   ;00000001400028FD 48 8B 4C 24 28 
MOVSS XMM1, oword ptr DS : [ RAX + 0x04 ]                   ;0000000140002902 F3 0F 10 48 04 
MULSS XMM1, oword ptr DS : [ RCX + 0x04 ]                   ;0000000140002907 F3 0F 59 49 04 
ADDSS XMM0, XMM1                                            ;000000014000290C F3 0F 58 C1 
MOV RAX, qword ptr SS : [ RSP +  + 0x20 ]                   ;0000000140002910 48 8B 44 24 20 
MOV RCX, qword ptr SS : [ RSP +  + 0x28 ]                   ;0000000140002915 48 8B 4C 24 28 
MOVSS XMM1, oword ptr DS : [ RAX + 0x08 ]                   ;000000014000291A F3 0F 10 48 08 
MULSS XMM1, oword ptr DS : [ RCX + 0x08 ]                   ;000000014000291F F3 0F 59 49 08 
ADDSS XMM0, XMM1                                            ;0000000140002924 F3 0F 58 C1 
MOVSS oword ptr SS : [ RSP +  ], XMM0                       ;0000000140002928 F3 0F 11 04 24 
MOVSS XMM0, oword ptr SS : [ RSP +  ]                       ;000000014000292D F3 0F 10 04 24 
ADD RSP, 0x18                                               ;0000000140002932 48 83 C4 18 
RETN                                                        ;0000000140002936 C3 
INT 3                                                       ;0000000140002937 CC 
INT 3                                                       ;0000000140002938 CC 
INT 3                                                       ;0000000140002939 CC 
INT 3                                                       ;000000014000293A CC 
INT 3                                                       ;000000014000293B CC 
INT 3                                                       ;000000014000293C CC 
INT 3                                                       ;000000014000293D CC 
INT 3                                                       ;000000014000293E CC 
INT 3                                                       ;000000014000293F CC 
MOV qword ptr SS : [ RSP +  + 0x08 ], RCX                   ;0000000140002940 48 89 4C 24 08 
PUSH ESI                                                    ;0000000140002945 56 
PUSH EDI                                                    ;0000000140002946 57 
SUB RSP, 0x48                                               ;0000000140002947 48 83 EC 48 
LEA RAX, invalid ptr SS : [ RSP +  + 0x30 ]                 ;000000014000294B 48 8D 44 24 30 
MOV RDI, RAX                                                ;0000000140002950 48 8B F8 
MOV RSI, qword ptr SS : [ RSP +  + 0x60 ]                   ;0000000140002953 48 8B 74 24 60 
MOV ECX, 0x0000000C                                         ;0000000140002958 B9 0C 00 00 00 
REP MOVSB                                                   ;000000014000295D F3 A4 
LEA RCX, invalid ptr SS : [ RSP +  + 0x30 ]                 ;000000014000295F 48 8D 4C 24 30 
CALL 0x00000027                                             ;0000000140002964 E8 27 00 00 00 
CALL 0x00000192                                             ;0000000140002969 E8 92 01 00 00 
MOVSS oword ptr SS : [ RSP +  + 0x20 ], XMM0                ;000000014000296E F3 0F 11 44 24 20 
MOVSS XMM0, oword ptr SS : [ RSP +  + 0x20 ]                ;0000000140002974 F3 0F 10 44 24 20 
ADD RSP, 0x48                                               ;000000014000297A 48 83 C4 48 
POP EDI                                                     ;000000014000297E 5F 
POP ESI                                                     ;000000014000297F 5E 
RETN                                                        ;0000000140002980 C3 
INT 3                                                       ;0000000140002981 CC 
INT 3                                                       ;0000000140002982 CC 
INT 3                                                       ;0000000140002983 CC 
INT 3                                                       ;0000000140002984 CC 
INT 3                                                       ;0000000140002985 CC 
INT 3                                                       ;0000000140002986 CC 
INT 3                                                       ;0000000140002987 CC 
INT 3                                                       ;0000000140002988 CC 
INT 3                                                       ;0000000140002989 CC 
INT 3                                                       ;000000014000298A CC 
INT 3                                                       ;000000014000298B CC 
INT 3                                                       ;000000014000298C CC 
INT 3                                                       ;000000014000298D CC 
INT 3                                                       ;000000014000298E CC 
INT 3                                                       ;000000014000298F CC 
MOV qword ptr SS : [ RSP +  + 0x08 ], RCX                   ;0000000140002990 48 89 4C 24 08 
PUSH ESI                                                    ;0000000140002995 56 
PUSH EDI                                                    ;0000000140002996 57 
SUB RSP, 0x58                                               ;0000000140002997 48 83 EC 58 
LEA RAX, invalid ptr SS : [ RSP +  + 0x30 ]                 ;000000014000299B 48 8D 44 24 30 
MOV RDI, RAX                                                ;00000001400029A0 48 8B F8 
MOV RSI, qword ptr SS : [ RSP +  + 0x70 ]                   ;00000001400029A3 48 8B 74 24 70 
MOV ECX, 0x0000000C                                         ;00000001400029A8 B9 0C 00 00 00 
REP MOVSB                                                   ;00000001400029AD F3 A4 
LEA RAX, invalid ptr SS : [ RSP +  + 0x40 ]                 ;00000001400029AF 48 8D 44 24 40 
MOV RDI, RAX                                                ;00000001400029B4 48 8B F8 
MOV RSI, qword ptr SS : [ RSP +  + 0x70 ]                   ;00000001400029B7 48 8B 74 24 70 
MOV ECX, 0x0000000C                                         ;00000001400029BC B9 0C 00 00 00 
REP MOVSB                                                   ;00000001400029C1 F3 A4 
LEA RDX, invalid ptr SS : [ RSP +  + 0x30 ]                 ;00000001400029C3 48 8D 54 24 30 
LEA RCX, invalid ptr SS : [ RSP +  + 0x40 ]                 ;00000001400029C8 48 8D 4C 24 40 
CALL 0xFFFFFEFE                                             ;00000001400029CD E8 FE FE FF FF 
MOVSS oword ptr SS : [ RSP +  + 0x20 ], XMM0                ;00000001400029D2 F3 0F 11 44 24 20 
MOVSS XMM0, oword ptr SS : [ RSP +  + 0x20 ]                ;00000001400029D8 F3 0F 10 44 24 20 
ADD RSP, 0x58                                               ;00000001400029DE 48 83 C4 58 
POP EDI                                                     ;00000001400029E2 5F 
POP ESI                                                     ;00000001400029E3 5E 
RETN                                                        ;00000001400029E4 C3 
INT 3                                                       ;00000001400029E5 CC 
INT 3                                                       ;00000001400029E6 CC 
INT 3                                                       ;00000001400029E7 CC 
INT 3                                                       ;00000001400029E8 CC 
INT 3                                                       ;00000001400029E9 CC 
INT 3                                                       ;00000001400029EA CC 
INT 3                                                       ;00000001400029EB CC 
INT 3                                                       ;00000001400029EC CC 
INT 3                                                       ;00000001400029ED CC 
INT 3                                                       ;00000001400029EE CC 
INT 3                                                       ;00000001400029EF CC 
MOV qword ptr SS : [ RSP +  + 0x10 ], RDX                   ;00000001400029F0 48 89 54 24 10 
MOV qword ptr SS : [ RSP +  + 0x08 ], RCX                   ;00000001400029F5 48 89 4C 24 08 
PUSH ESI                                                    ;00000001400029FA 56 
PUSH EDI                                                    ;00000001400029FB 57 
SUB RSP, 0x00000088                                         ;00000001400029FC 48 81 EC 88 00 00 00 
MOV RAX, CS : [ RIP + 0x000575FE ]                          ;0000000140002A03 48 8B 05 FE 75 05 00 
XOR RAX, RSP                                                ;0000000140002A0A 48 33 C4 
MOV qword ptr SS : [ RSP +  + 0x70 ], RAX                   ;0000000140002A0D 48 89 44 24 70 
LEA RAX, invalid ptr SS : [ RSP +  + 0x20 ]                 ;0000000140002A12 48 8D 44 24 20 
MOV RDI, RAX                                                ;0000000140002A17 48 8B F8 
MOV RSI, qword ptr SS : [ RSP +  + 0x000000A8 ]             ;0000000140002A1A 48 8B B4 24 A8 00 00 00 
MOV ECX, 0x0000000C                                         ;0000000140002A22 B9 0C 00 00 00 
REP MOVSB                                                   ;0000000140002A27 F3 A4 
LEA RCX, invalid ptr SS : [ RSP +  + 0x20 ]                 ;0000000140002A29 48 8D 4C 24 20 
CALL 0xFFFFFF0D                                             ;0000000140002A2E E8 0D FF FF FF 
MOVSS XMM1, CS : [ RIP + 0x000428F9 ]                       ;0000000140002A33 F3 0F 10 0D F9 28 04 00 
DIVSS XMM1, XMM0                                            ;0000000140002A3B F3 0F 5E C8 
MOVAPS XMM0, XMM1                                           ;0000000140002A3F 0F 28 C1 
LEA RAX, invalid ptr SS : [ RSP +  + 0x30 ]                 ;0000000140002A42 48 8D 44 24 30 
MOV RDI, RAX                                                ;0000000140002A47 48 8B F8 
MOV RSI, qword ptr SS : [ RSP +  + 0x000000A8 ]             ;0000000140002A4A 48 8B B4 24 A8 00 00 00 
MOV ECX, 0x0000000C                                         ;0000000140002A52 B9 0C 00 00 00 
REP MOVSB                                                   ;0000000140002A57 F3 A4 
MOVAPS XMM2, XMM0                                           ;0000000140002A59 0F 28 D0 
LEA RDX, invalid ptr SS : [ RSP +  + 0x30 ]                 ;0000000140002A5C 48 8D 54 24 30 
LEA RCX, invalid ptr SS : [ RSP +  + 0x40 ]                 ;0000000140002A61 48 8D 4C 24 40 
CALL 0xFFFFFB75                                             ;0000000140002A66 E8 75 FB FF FF 
LEA RCX, invalid ptr SS : [ RSP +  + 0x50 ]                 ;0000000140002A6B 48 8D 4C 24 50 
MOV RDI, RCX                                                ;0000000140002A70 48 8B F9 
MOV RSI, RAX                                                ;0000000140002A73 48 8B F0 
MOV ECX, 0x0000000C                                         ;0000000140002A76 B9 0C 00 00 00 
REP MOVSB                                                   ;0000000140002A7B F3 A4 
LEA RAX, invalid ptr SS : [ RSP +  + 0x60 ]                 ;0000000140002A7D 48 8D 44 24 60 
LEA RCX, invalid ptr SS : [ RSP +  + 0x50 ]                 ;0000000140002A82 48 8D 4C 24 50 
MOV RDI, RAX                                                ;0000000140002A87 48 8B F8 
MOV RSI, RCX                                                ;0000000140002A8A 48 8B F1 
MOV ECX, 0x0000000C                                         ;0000000140002A8D B9 0C 00 00 00 
REP MOVSB                                                   ;0000000140002A92 F3 A4 
LEA RAX, invalid ptr SS : [ RSP +  + 0x60 ]                 ;0000000140002A94 48 8D 44 24 60 
MOV RDI, qword ptr SS : [ RSP +  + 0x000000A0 ]             ;0000000140002A99 48 8B BC 24 A0 00 00 00 
MOV RSI, RAX                                                ;0000000140002AA1 48 8B F0 
MOV ECX, 0x0000000C                                         ;0000000140002AA4 B9 0C 00 00 00 
REP MOVSB                                                   ;0000000140002AA9 F3 A4 
MOV RAX, qword ptr SS : [ RSP +  + 0x000000A0 ]             ;0000000140002AAB 48 8B 84 24 A0 00 00 00 
MOV RCX, qword ptr SS : [ RSP +  + 0x70 ]                   ;0000000140002AB3 48 8B 4C 24 70 
XOR RCX, RSP                                                ;0000000140002AB8 48 33 CC 
CALL 0x00000390                                             ;0000000140002ABB E8 90 03 00 00 
ADD RSP, 0x00000088                                         ;0000000140002AC0 48 81 C4 88 00 00 00 
POP EDI                                                     ;0000000140002AC7 5F 
POP ESI                                                     ;0000000140002AC8 5E 
RETN                                                        ;0000000140002AC9 C3 
INT 3                                                       ;0000000140002ACA CC 
INT 3                                                       ;0000000140002ACB CC 
INT 3                                                       ;0000000140002ACC CC 
INT 3                                                       ;0000000140002ACD CC 
INT 3                                                       ;0000000140002ACE CC 
INT 3                                                       ;0000000140002ACF CC 
MOVSS oword ptr SS : [ RSP +  + 0x08 ], XMM0                ;0000000140002AD0 F3 0F 11 44 24 08 
SUB RSP, 0x18                                               ;0000000140002AD6 48 83 EC 18 
MOVSS XMM0, oword ptr SS : [ RSP +  + 0x20 ]                ;0000000140002ADA F3 0F 10 44 24 20 
MULSS XMM0, oword ptr SS : [ RSP +  + 0x20 ]                ;0000000140002AE0 F3 0F 59 44 24 20 
MOVSS oword ptr SS : [ RSP +  ], XMM0                       ;0000000140002AE6 F3 0F 11 04 24 
MOVSS XMM0, oword ptr SS : [ RSP +  ]                       ;0000000140002AEB F3 0F 10 04 24 
ADD RSP, 0x18                                               ;0000000140002AF0 48 83 C4 18 
RETN                                                        ;0000000140002AF4 C3 
INT 3                                                       ;0000000140002AF5 CC 
INT 3                                                       ;0000000140002AF6 CC 
INT 3                                                       ;0000000140002AF7 CC 
INT 3                                                       ;0000000140002AF8 CC 
INT 3                                                       ;0000000140002AF9 CC 
INT 3                                                       ;0000000140002AFA CC 
INT 3                                                       ;0000000140002AFB CC 
INT 3                                                       ;0000000140002AFC CC 
INT 3                                                       ;0000000140002AFD CC 
INT 3                                                       ;0000000140002AFE CC 
INT 3                                                       ;0000000140002AFF CC 
MOVSS oword ptr SS : [ RSP +  + 0x08 ], XMM0                ;0000000140002B00 F3 0F 11 44 24 08 
SUB RSP, 0x38                                               ;0000000140002B06 48 83 EC 38 
MOVSS XMM0, oword ptr SS : [ RSP +  + 0x40 ]                ;0000000140002B0A F3 0F 10 44 24 40 
CALL 0x00012F3B                                             ;0000000140002B10 E8 3B 2F 01 00 
MOVSS oword ptr SS : [ RSP +  + 0x20 ], XMM0                ;0000000140002B15 F3 0F 11 44 24 20 
MOVSS XMM0, oword ptr SS : [ RSP +  + 0x20 ]                ;0000000140002B1B F3 0F 10 44 24 20 
ADD RSP, 0x38                                               ;0000000140002B21 48 83 C4 38 
RETN                                                        ;0000000140002B25 C3 
INT 3                                                       ;0000000140002B26 CC 
INT 3                                                       ;0000000140002B27 CC 
INT 3                                                       ;0000000140002B28 CC 
INT 3                                                       ;0000000140002B29 CC 
INT 3                                                       ;0000000140002B2A CC 
INT 3                                                       ;0000000140002B2B CC 
INT 3                                                       ;0000000140002B2C CC 
INT 3                                                       ;0000000140002B2D CC 
INT 3                                                       ;0000000140002B2E CC 
INT 3                                                       ;0000000140002B2F CC 
MOVSS oword ptr SS : [ RSP +  + 0x20 ], XMM3                ;0000000140002B30 F3 0F 11 5C 24 20 
MOVSS oword ptr SS : [ RSP +  + 0x18 ], XMM2                ;0000000140002B36 F3 0F 11 54 24 18 
MOVSS oword ptr SS : [ RSP +  + 0x10 ], XMM1                ;0000000140002B3C F3 0F 11 4C 24 10 
MOV qword ptr SS : [ RSP +  + 0x08 ], RCX                   ;0000000140002B42 48 89 4C 24 08 
PUSH ESI                                                    ;0000000140002B47 56 
PUSH EDI                                                    ;0000000140002B48 57 
SUB RSP, 0x28                                               ;0000000140002B49 48 83 EC 28 
MOV RAX, CS : [ RIP + 0x000574B4 ]                          ;0000000140002B4D 48 8B 05 B4 74 05 00 
XOR RAX, RSP                                                ;0000000140002B54 48 33 C4 
MOV qword ptr SS : [ RSP +  + 0x10 ], RAX                   ;0000000140002B57 48 89 44 24 10 
MOVSS XMM0, oword ptr SS : [ RSP +  + 0x48 ]                ;0000000140002B5C F3 0F 10 44 24 48 
MOVSS oword ptr SS : [ RSP +  ], XMM0                       ;0000000140002B62 F3 0F 11 04 24 
MOVSS XMM0, oword ptr SS : [ RSP +  + 0x50 ]                ;0000000140002B67 F3 0F 10 44 24 50 
MOVSS oword ptr SS : [ RSP +  + 0x04 ], XMM0                ;0000000140002B6D F3 0F 11 44 24 04 
MOVSS XMM0, oword ptr SS : [ RSP +  + 0x58 ]                ;0000000140002B73 F3 0F 10 44 24 58 
MOVSS oword ptr SS : [ RSP +  + 0x08 ], XMM0                ;0000000140002B79 F3 0F 11 44 24 08 
LEA RAX, invalid ptr SS : [ RSP +  ]                        ;0000000140002B7F 48 8D 04 24 
MOV RDI, qword ptr SS : [ RSP +  + 0x40 ]                   ;0000000140002B83 48 8B 7C 24 40 
MOV RSI, RAX                                                ;0000000140002B88 48 8B F0 
MOV ECX, 0x0000000C                                         ;0000000140002B8B B9 0C 00 00 00 
REP MOVSB                                                   ;0000000140002B90 F3 A4 
MOV RAX, qword ptr SS : [ RSP +  + 0x40 ]                   ;0000000140002B92 48 8B 44 24 40 
MOV RCX, qword ptr SS : [ RSP +  + 0x10 ]                   ;0000000140002B97 48 8B 4C 24 10 
XOR RCX, RSP                                                ;0000000140002B9C 48 33 CC 
CALL 0x000002AC                                             ;0000000140002B9F E8 AC 02 00 00 
ADD RSP, 0x28                                               ;0000000140002BA4 48 83 C4 28 
POP EDI                                                     ;0000000140002BA8 5F 
POP ESI                                                     ;0000000140002BA9 5E 
RETN                                                        ;0000000140002BAA C3 
INT 3                                                       ;0000000140002BAB CC 
INT 3                                                       ;0000000140002BAC CC 
INT 3                                                       ;0000000140002BAD CC 
INT 3                                                       ;0000000140002BAE CC 
INT 3                                                       ;0000000140002BAF CC 
MOVSS oword ptr SS : [ RSP +  + 0x20 ], XMM3                ;0000000140002BB0 F3 0F 11 5C 24 20 
MOVSS oword ptr SS : [ RSP +  + 0x18 ], XMM2                ;0000000140002BB6 F3 0F 11 54 24 18 
MOVSS oword ptr SS : [ RSP +  + 0x10 ], XMM1                ;0000000140002BBC F3 0F 11 4C 24 10 
MOV qword ptr SS : [ RSP +  + 0x08 ], RCX                   ;0000000140002BC2 48 89 4C 24 08 
PUSH ESI                                                    ;0000000140002BC7 56 
PUSH EDI                                                    ;0000000140002BC8 57 
SUB RSP, 0x28                                               ;0000000140002BC9 48 83 EC 28 
MOV RAX, CS : [ RIP + 0x00057434 ]                          ;0000000140002BCD 48 8B 05 34 74 05 00 
XOR RAX, RSP                                                ;0000000140002BD4 48 33 C4 
MOV qword ptr SS : [ RSP +  + 0x10 ], RAX                   ;0000000140002BD7 48 89 44 24 10 
MOVSS XMM0, oword ptr SS : [ RSP +  + 0x48 ]                ;0000000140002BDC F3 0F 10 44 24 48 
MOVSS oword ptr SS : [ RSP +  ], XMM0                       ;0000000140002BE2 F3 0F 11 04 24 
MOVSS XMM0, oword ptr SS : [ RSP +  + 0x50 ]                ;0000000140002BE7 F3 0F 10 44 24 50 
MOVSS oword ptr SS : [ RSP +  + 0x04 ], XMM0                ;0000000140002BED F3 0F 11 44 24 04 
MOVSS XMM0, oword ptr SS : [ RSP +  + 0x58 ]                ;0000000140002BF3 F3 0F 10 44 24 58 
MOVSS oword ptr SS : [ RSP +  + 0x08 ], XMM0                ;0000000140002BF9 F3 0F 11 44 24 08 
MOVSS XMM0, oword ptr SS : [ RSP +  + 0x60 ]                ;0000000140002BFF F3 0F 10 44 24 60 
MOVSS oword ptr SS : [ RSP +  + 0x0C ], XMM0                ;0000000140002C05 F3 0F 11 44 24 0C 
LEA RAX, invalid ptr SS : [ RSP +  ]                        ;0000000140002C0B 48 8D 04 24 
MOV RDI, qword ptr SS : [ RSP +  + 0x40 ]                   ;0000000140002C0F 48 8B 7C 24 40 
MOV RSI, RAX                                                ;0000000140002C14 48 8B F0 
MOV ECX, 0x00000010                                         ;0000000140002C17 B9 10 00 00 00 
REP MOVSB                                                   ;0000000140002C1C F3 A4 
MOV RAX, qword ptr SS : [ RSP +  + 0x40 ]                   ;0000000140002C1E 48 8B 44 24 40 
MOV RCX, qword ptr SS : [ RSP +  + 0x10 ]                   ;0000000140002C23 48 8B 4C 24 10 
XOR RCX, RSP                                                ;0000000140002C28 48 33 CC 
CALL 0x00000220                                             ;0000000140002C2B E8 20 02 00 00 
ADD RSP, 0x28                                               ;0000000140002C30 48 83 C4 28 
POP EDI                                                     ;0000000140002C34 5F 
POP ESI                                                     ;0000000140002C35 5E 
RETN                                                        ;0000000140002C36 C3 
INT 3                                                       ;0000000140002C37 CC 
INT 3                                                       ;0000000140002C38 CC 
INT 3                                                       ;0000000140002C39 CC 
INT 3                                                       ;0000000140002C3A CC 
INT 3                                                       ;0000000140002C3B CC 
INT 3                                                       ;0000000140002C3C CC 
INT 3                                                       ;0000000140002C3D CC 
INT 3                                                       ;0000000140002C3E CC 
INT 3                                                       ;0000000140002C3F CC 
LEA RAX, CS : [ RIP + 0x00057EA9 ]                          ;0000000140002C40 48 8D 05 A9 7E 05 00 
RETN                                                        ;0000000140002C47 C3 
INT 3                                                       ;0000000140002C48 CC 
INT 3                                                       ;0000000140002C49 CC 
INT 3                                                       ;0000000140002C4A CC 
INT 3                                                       ;0000000140002C4B CC 
INT 3                                                       ;0000000140002C4C CC 
INT 3                                                       ;0000000140002C4D CC 
INT 3                                                       ;0000000140002C4E CC 
INT 3                                                       ;0000000140002C4F CC 
MOV qword ptr SS : [ RSP +  + 0x20 ], R9                    ;0000000140002C50 4C 89 4C 24 20 
MOV qword ptr SS : [ RSP +  + 0x18 ], R8                    ;0000000140002C55 4C 89 44 24 18 
MOV qword ptr SS : [ RSP +  + 0x10 ], RDX                   ;0000000140002C5A 48 89 54 24 10 
MOV qword ptr SS : [ RSP +  + 0x08 ], RCX                   ;0000000140002C5F 48 89 4C 24 08 
SUB RSP, 0x38                                               ;0000000140002C64 48 83 EC 38 
CALL 0xFFFFFFD3                                             ;0000000140002C68 E8 D3 FF FF FF 
MOV RCX, qword ptr SS : [ RSP +  + 0x58 ]                   ;0000000140002C6D 48 8B 4C 24 58 
MOV qword ptr SS : [ RSP +  + 0x20 ], RCX                   ;0000000140002C72 48 89 4C 24 20 
MOV R9, qword ptr SS : [ RSP +  + 0x50 ]                    ;0000000140002C77 4C 8B 4C 24 50 
MOV R8, qword ptr SS : [ RSP +  + 0x48 ]                    ;0000000140002C7C 4C 8B 44 24 48 
MOV RDX, qword ptr SS : [ RSP +  + 0x40 ]                   ;0000000140002C81 48 8B 54 24 40 
MOV RCX, qword ptr DS : [ RAX ]                             ;0000000140002C86 48 8B 08 
CALL 0x00012C12                                             ;0000000140002C89 E8 12 2C 01 00 
ADD RSP, 0x38                                               ;0000000140002C8E 48 83 C4 38 
RETN                                                        ;0000000140002C92 C3 
INT 3                                                       ;0000000140002C93 CC 
INT 3                                                       ;0000000140002C94 CC 
INT 3                                                       ;0000000140002C95 CC 
INT 3                                                       ;0000000140002C96 CC 
INT 3                                                       ;0000000140002C97 CC 
INT 3                                                       ;0000000140002C98 CC 
INT 3                                                       ;0000000140002C99 CC 
INT 3                                                       ;0000000140002C9A CC 
INT 3                                                       ;0000000140002C9B CC 
INT 3                                                       ;0000000140002C9C CC 
INT 3                                                       ;0000000140002C9D CC 
INT 3                                                       ;0000000140002C9E CC 
INT 3                                                       ;0000000140002C9F CC 
MOV qword ptr SS : [ RSP +  + 0x08 ], RCX                   ;0000000140002CA0 48 89 4C 24 08 
MOV qword ptr SS : [ RSP +  + 0x10 ], RDX                   ;0000000140002CA5 48 89 54 24 10 
MOV qword ptr SS : [ RSP +  + 0x18 ], R8                    ;0000000140002CAA 4C 89 44 24 18 
MOV qword ptr SS : [ RSP +  + 0x20 ], R9                    ;0000000140002CAF 4C 89 4C 24 20 
SUB RSP, 0x38                                               ;0000000140002CB4 48 83 EC 38 
LEA RAX, invalid ptr SS : [ RSP +  + 0x48 ]                 ;0000000140002CB8 48 8D 44 24 48 
MOV qword ptr SS : [ RSP +  + 0x28 ], RAX                   ;0000000140002CBD 48 89 44 24 28 
MOV ECX, 0x00000001                                         ;0000000140002CC2 B9 01 00 00 00 
CALL 0x00007094                                             ;0000000140002CC7 E8 94 70 00 00 
MOV R9, qword ptr SS : [ RSP +  + 0x28 ]                    ;0000000140002CCC 4C 8B 4C 24 28 
XOR R8D, R8D                                                ;0000000140002CD1 45 33 C0 
MOV RDX, qword ptr SS : [ RSP +  + 0x40 ]                   ;0000000140002CD4 48 8B 54 24 40 
MOV RCX, RAX                                                ;0000000140002CD9 48 8B C8 
CALL 0xFFFFFF6F                                             ;0000000140002CDC E8 6F FF FF FF 
MOV dword ptr SS : [ RSP +  + 0x20 ], EAX                   ;0000000140002CE1 89 44 24 20 
MOV qword ptr SS : [ RSP +  + 0x28 ], 0x00000000            ;0000000140002CE5 48 C7 44 24 28 00 00 00 00 
MOV EAX, dword ptr SS : [ RSP +  + 0x20 ]                   ;0000000140002CEE 8B 44 24 20 
ADD RSP, 0x38                                               ;0000000140002CF2 48 83 C4 38 
RETN                                                        ;0000000140002CF6 C3 
INT 3                                                       ;0000000140002CF7 CC 
INT 3                                                       ;0000000140002CF8 CC 
INT 3                                                       ;0000000140002CF9 CC 
INT 3                                                       ;0000000140002CFA CC 
INT 3                                                       ;0000000140002CFB CC 
INT 3                                                       ;0000000140002CFC CC 
INT 3                                                       ;0000000140002CFD CC 
INT 3                                                       ;0000000140002CFE CC 
INT 3                                                       ;0000000140002CFF CC 
MOV qword ptr SS : [ RSP +  + 0x20 ], R9                    ;0000000140002D00 4C 89 4C 24 20 
MOV qword ptr SS : [ RSP +  + 0x18 ], R8                    ;0000000140002D05 4C 89 44 24 18 
MOV qword ptr SS : [ RSP +  + 0x10 ], RDX                   ;0000000140002D0A 48 89 54 24 10 
MOV qword ptr SS : [ RSP +  + 0x08 ], RCX                   ;0000000140002D0F 48 89 4C 24 08 
SUB RSP, 0x28                                               ;0000000140002D14 48 83 EC 28 
MOV RAX, qword ptr SS : [ RSP +  + 0x48 ]                   ;0000000140002D18 48 8B 44 24 48 
MOV R8, qword ptr DS : [ RAX + 0x38 ]                       ;0000000140002D1D 4C 8B 40 38 
MOV RDX, qword ptr SS : [ RSP +  + 0x48 ]                   ;0000000140002D21 48 8B 54 24 48 
MOV RCX, qword ptr SS : [ RSP +  + 0x38 ]                   ;0000000140002D26 48 8B 4C 24 38 
CALL 0x00000010                                             ;0000000140002D2B E8 10 00 00 00 
MOV EAX, 0x00000001                                         ;0000000140002D30 B8 01 00 00 00 
ADD RSP, 0x28                                               ;0000000140002D35 48 83 C4 28 
RETN                                                        ;0000000140002D39 C3 
INT 3                                                       ;0000000140002D3A CC 
INT 3                                                       ;0000000140002D3B CC 
INT 3                                                       ;0000000140002D3C CC 
INT 3                                                       ;0000000140002D3D CC 
INT 3                                                       ;0000000140002D3E CC 
INT 3                                                       ;0000000140002D3F CC 
MOV qword ptr SS : [ RSP +  + 0x18 ], R8                    ;0000000140002D40 4C 89 44 24 18 
MOV qword ptr SS : [ RSP +  + 0x10 ], RDX                   ;0000000140002D45 48 89 54 24 10 
MOV qword ptr SS : [ RSP +  + 0x08 ], RCX                   ;0000000140002D4A 48 89 4C 24 08 
SUB RSP, 0x58                                               ;0000000140002D4F 48 83 EC 58 
MOV RAX, qword ptr SS : [ RSP +  + 0x70 ]                   ;0000000140002D53 48 8B 44 24 70 
MOV EAX, dword ptr DS : [ RAX ]                             ;0000000140002D58 8B 00 
AND EAX, 0xF8                                               ;0000000140002D5A 83 E0 F8 
MOV dword ptr SS : [ RSP +  + 0x20 ], EAX                   ;0000000140002D5D 89 44 24 20 
MOV RAX, qword ptr SS : [ RSP +  + 0x60 ]                   ;0000000140002D61 48 8B 44 24 60 
MOV qword ptr SS : [ RSP +  + 0x38 ], RAX                   ;0000000140002D66 48 89 44 24 38 
MOV RAX, qword ptr SS : [ RSP +  + 0x70 ]                   ;0000000140002D6B 48 8B 44 24 70 
MOV EAX, dword ptr DS : [ RAX ]                             ;0000000140002D70 8B 00 
SHR EAX, 0x02                                               ;0000000140002D72 C1 E8 02 
AND EAX, 0x01                                               ;0000000140002D75 83 E0 01 
TEST EAX, EAX                                               ;0000000140002D78 85 C0 
JZ 0x29                                                     ;0000000140002D7A 74 29 
MOV RAX, qword ptr SS : [ RSP +  + 0x70 ]                   ;0000000140002D7C 48 8B 44 24 70 
MOVSXD RAX, dword ptr DS : [ RAX + 0x04 ]                   ;0000000140002D81 48 63 40 04 
MOV RCX, qword ptr SS : [ RSP +  + 0x60 ]                   ;0000000140002D85 48 8B 4C 24 60 
ADD RCX, RAX                                                ;0000000140002D8A 48 03 C8 
MOV RAX, RCX                                                ;0000000140002D8D 48 8B C1 
MOV RCX, qword ptr SS : [ RSP +  + 0x70 ]                   ;0000000140002D90 48 8B 4C 24 70 
MOV ECX, dword ptr DS : [ RCX + 0x08 ]                      ;0000000140002D95 8B 49 08 
NEG ECX                                                     ;0000000140002D98 F7 D9 
MOVSXD RCX, ECX                                             ;0000000140002D9A 48 63 C9 
AND RAX, RCX                                                ;0000000140002D9D 48 23 C1 
MOV qword ptr SS : [ RSP +  + 0x38 ], RAX                   ;0000000140002DA0 48 89 44 24 38 
MOVSXD RAX, dword ptr SS : [ RSP +  + 0x20 ]                ;0000000140002DA5 48 63 44 24 20 
MOV RCX, qword ptr SS : [ RSP +  + 0x38 ]                   ;0000000140002DAA 48 8B 4C 24 38 
MOV RAX, qword ptr DS : [ RCX + RAX * 1 ]                   ;0000000140002DAF 48 8B 04 01 
MOV qword ptr SS : [ RSP +  + 0x30 ], RAX                   ;0000000140002DB3 48 89 44 24 30 
MOV RAX, qword ptr SS : [ RSP +  + 0x68 ]                   ;0000000140002DB8 48 8B 44 24 68 
MOV RAX, qword ptr DS : [ RAX + 0x10 ]                      ;0000000140002DBD 48 8B 40 10 
MOV EAX, dword ptr DS : [ RAX + 0x08 ]                      ;0000000140002DC1 8B 40 08 
MOV RCX, qword ptr SS : [ RSP +  + 0x68 ]                   ;0000000140002DC4 48 8B 4C 24 68 
ADD RAX, qword ptr DS : [ RCX + 0x08 ]                      ;0000000140002DC9 48 03 41 08 
MOV qword ptr SS : [ RSP +  + 0x40 ], RAX                   ;0000000140002DCD 48 89 44 24 40 
MOV RAX, qword ptr SS : [ RSP +  + 0x60 ]                   ;0000000140002DD2 48 8B 44 24 60 
MOV qword ptr SS : [ RSP +  + 0x28 ], RAX                   ;0000000140002DD7 48 89 44 24 28 
MOV RAX, qword ptr SS : [ RSP +  + 0x40 ]                   ;0000000140002DDC 48 8B 44 24 40 
MOVZX EAX, byte ptr DS : [ RAX + 0x03 ]                     ;0000000140002DE1 0F B6 40 03 
AND AL, 0x0F                                                ;0000000140002DE5 24 0F 
MOVZX EAX, AL                                               ;0000000140002DE7 0F B6 C0 
TEST EAX, EAX                                               ;0000000140002DEA 85 C0 
JZ 0x26                                                     ;0000000140002DEC 74 26 
MOV RAX, qword ptr SS : [ RSP +  + 0x40 ]                   ;0000000140002DEE 48 8B 44 24 40 
MOVZX EAX, byte ptr DS : [ RAX + 0x03 ]                     ;0000000140002DF3 0F B6 40 03 
SHR AL, 0x04                                                ;0000000140002DF7 C0 E8 04 
AND AL, 0x0F                                                ;0000000140002DFA 24 0F 
MOVZX EAX, AL                                               ;0000000140002DFC 0F B6 C0 
IMUL EAX, EAX, 0x10                                         ;0000000140002DFF 6B C0 10 
                                                            ;0000000140002E02 48 98 
MOV RCX, qword ptr SS : [ RSP +  + 0x28 ]                   ;0000000140002E04 48 8B 4C 24 28 
ADD RCX, RAX                                                ;0000000140002E09 48 03 C8 
MOV RAX, RCX                                                ;0000000140002E0C 48 8B C1 
MOV qword ptr SS : [ RSP +  + 0x28 ], RAX                   ;0000000140002E0F 48 89 44 24 28 
MOV RAX, qword ptr SS : [ RSP +  + 0x28 ]                   ;0000000140002E14 48 8B 44 24 28 
MOV RCX, qword ptr SS : [ RSP +  + 0x30 ]                   ;0000000140002E19 48 8B 4C 24 30 
XOR RCX, RAX                                                ;0000000140002E1E 48 33 C8 
MOV RAX, RCX                                                ;0000000140002E21 48 8B C1 
MOV qword ptr SS : [ RSP +  + 0x30 ], RAX                   ;0000000140002E24 48 89 44 24 30 
MOV RCX, qword ptr SS : [ RSP +  + 0x30 ]                   ;0000000140002E29 48 8B 4C 24 30 
CALL 0x0000001D                                             ;0000000140002E2E E8 1D 00 00 00 
ADD RSP, 0x58                                               ;0000000140002E33 48 83 C4 58 
RETN                                                        ;0000000140002E37 C3 
INT 3                                                       ;0000000140002E38 CC 
INT 3                                                       ;0000000140002E39 CC 
INT 3                                                       ;0000000140002E3A CC 
INT 3                                                       ;0000000140002E3B CC 
INT 3                                                       ;0000000140002E3C CC 
INT 3                                                       ;0000000140002E3D CC 
INT 3                                                       ;0000000140002E3E CC 
INT 3                                                       ;0000000140002E3F CC 
INT 3                                                       ;0000000140002E40 CC 
INT 3                                                       ;0000000140002E41 CC 
INT 3                                                       ;0000000140002E42 CC 
INT 3                                                       ;0000000140002E43 CC 
INT 3                                                       ;0000000140002E44 CC 
INT 3                                                       ;0000000140002E45 CC 
NOP word ptr DS : [ RAX + RAX * 1 + 0x00000000 ]            ;0000000140002E46 66 66 0F 1F 84 00 00 00 00 00 
CMP RCX, CS : [ RIP + 0x000571B1 ]                          ;0000000140002E50 48 3B 0D B1 71 05 00 
JNZ 0x12                                                    ;0000000140002E57 F2 75 12 
ROL RCX, 0x10                                               ;0000000140002E5A 48 C1 C1 10 
TEST CX, 0xFFFF                                             ;0000000140002E5E 66 F7 C1 FF FF 
JNZ 0x02                                                    ;0000000140002E63 F2 75 02 
RETN                                                        ;0000000140002E66 F2 C3 
ROR RCX, 0x10                                               ;0000000140002E68 48 C1 C9 10 
JMP 0x000003DF                                              ;0000000140002E6C E9 DF 03 00 00 
INT 3                                                       ;0000000140002E71 CC 
INT 3                                                       ;0000000140002E72 CC 
INT 3                                                       ;0000000140002E73 CC 
INT 3                                                       ;0000000140002E74 CC 
INT 3                                                       ;0000000140002E75 CC 
INT 3                                                       ;0000000140002E76 CC 
INT 3                                                       ;0000000140002E77 CC 
INT 3                                                       ;0000000140002E78 CC 
INT 3                                                       ;0000000140002E79 CC 
INT 3                                                       ;0000000140002E7A CC 
INT 3                                                       ;0000000140002E7B CC 
INT 3                                                       ;0000000140002E7C CC 
INT 3                                                       ;0000000140002E7D CC 
INT 3                                                       ;0000000140002E7E CC 
INT 3                                                       ;0000000140002E7F CC 
SUB RSP, 0x28                                               ;0000000140002E80 48 83 EC 28 
CALL 0x00000317                                             ;0000000140002E84 E8 17 03 00 00 
CALL 0x00000352                                             ;0000000140002E89 E8 52 03 00 00 
CALL 0x0000032D                                             ;0000000140002E8E E8 2D 03 00 00 
MOV ECX, 0x00000001                                         ;0000000140002E93 B9 01 00 00 00 
CALL 0x00000983                                             ;0000000140002E98 E8 83 09 00 00 
MOVZX EAX, AL                                               ;0000000140002E9D 0F B6 C0 
TEST EAX, EAX                                               ;0000000140002EA0 85 C0 
JNZ 0x0A                                                    ;0000000140002EA2 75 0A 
MOV ECX, 0x00000007                                         ;0000000140002EA4 B9 07 00 00 00 
CALL 0x00000ED2                                             ;0000000140002EA9 E8 D2 0E 00 00 
CALL 0x000011CD                                             ;0000000140002EAE E8 CD 11 00 00 
LEA RCX, CS : [ RIP + 0x00001216 ]                          ;0000000140002EB3 48 8D 0D 16 12 00 00 
CALL 0x00000C01                                             ;0000000140002EBA E8 01 0C 00 00 
CALL 0x0000026C                                             ;0000000140002EBF E8 6C 02 00 00 
TEST EAX, EAX                                               ;0000000140002EC4 85 C0 
JZ 0x0A                                                     ;0000000140002EC6 74 0A 
MOV ECX, 0x00000007                                         ;0000000140002EC8 B9 07 00 00 00 
CALL 0x00000EAE                                             ;0000000140002ECD E8 AE 0E 00 00 
CALL 0x00000DA9                                             ;0000000140002ED2 E8 A9 0D 00 00 
CALL 0x00000E44                                             ;0000000140002ED7 E8 44 0E 00 00 
TEST EAX, EAX                                               ;0000000140002EDC 85 C0 
JZ 0x0C                                                     ;0000000140002EDE 74 0C 
LEA RCX, CS : [ RIP + 0x00000D59 ]                          ;0000000140002EE0 48 8D 0D 59 0D 00 00 
CALL 0x00013594                                             ;0000000140002EE7 E8 94 35 01 00 
CALL 0x00000DBF                                             ;0000000140002EEC E8 BF 0D 00 00 
CALL 0x00000DBA                                             ;0000000140002EF1 E8 BA 0D 00 00 
CALL 0x00000D65                                             ;0000000140002EF6 E8 65 0D 00 00 
MOV ECX, EAX                                                ;0000000140002EFB 8B C8 
CALL 0x000152FE                                             ;0000000140002EFD E8 FE 52 01 00 
CALL 0x00000D99                                             ;0000000140002F02 E8 99 0D 00 00 
MOVZX EAX, AL                                               ;0000000140002F07 0F B6 C0 
TEST EAX, EAX                                               ;0000000140002F0A 85 C0 
JZ 0x05                                                     ;0000000140002F0C 74 05 
CALL 0x0000023D                                             ;0000000140002F0E E8 3D 02 00 00 
CALL 0x00000D48                                             ;0000000140002F13 E8 48 0D 00 00 
CALL 0x00001003                                             ;0000000140002F18 E8 03 10 00 00 
TEST EAX, EAX                                               ;0000000140002F1D 85 C0 
JZ 0x0A                                                     ;0000000140002F1F 74 0A 
MOV ECX, 0x00000007                                         ;0000000140002F21 B9 07 00 00 00 
CALL 0x00000E55                                             ;0000000140002F26 E8 55 0E 00 00 
XOR EAX, EAX                                                ;0000000140002F2B 33 C0 
ADD RSP, 0x28                                               ;0000000140002F2D 48 83 C4 28 
RETN                                                        ;0000000140002F31 C3 
INT 3                                                       ;0000000140002F32 CC 
INT 3                                                       ;0000000140002F33 CC 
INT 3                                                       ;0000000140002F34 CC 
INT 3                                                       ;0000000140002F35 CC 
INT 3                                                       ;0000000140002F36 CC 
INT 3                                                       ;0000000140002F37 CC 
INT 3                                                       ;0000000140002F38 CC 
INT 3                                                       ;0000000140002F39 CC 
INT 3                                                       ;0000000140002F3A CC 
INT 3                                                       ;0000000140002F3B CC 
INT 3                                                       ;0000000140002F3C CC 
INT 3                                                       ;0000000140002F3D CC 
INT 3                                                       ;0000000140002F3E CC 
INT 3                                                       ;0000000140002F3F CC 
SUB RSP, 0x28                                               ;0000000140002F40 48 83 EC 28 
CALL 0x00000D87                                             ;0000000140002F44 E8 87 0D 00 00 
XOR EAX, EAX                                                ;0000000140002F49 33 C0 
ADD RSP, 0x28                                               ;0000000140002F4B 48 83 C4 28 
RETN                                                        ;0000000140002F4F C3 
SUB RSP, 0x28                                               ;0000000140002F50 48 83 EC 28 
CALL 0x00001087                                             ;0000000140002F54 E8 87 10 00 00 
CALL 0x00000D02                                             ;0000000140002F59 E8 02 0D 00 00 
MOV ECX, EAX                                                ;0000000140002F5E 8B C8 
CALL 0x0001541B                                             ;0000000140002F60 E8 1B 54 01 00 
ADD RSP, 0x28                                               ;0000000140002F65 48 83 C4 28 
RETN                                                        ;0000000140002F69 C3 
INT 3                                                       ;0000000140002F6A CC 
INT 3                                                       ;0000000140002F6B CC 
INT 3                                                       ;0000000140002F6C CC 
INT 3                                                       ;0000000140002F6D CC 
INT 3                                                       ;0000000140002F6E CC 
INT 3                                                       ;0000000140002F6F CC 
SUB RSP, 0x28                                               ;0000000140002F70 48 83 EC 28 
CALL 0x00000C47                                             ;0000000140002F74 E8 47 0C 00 00 
CALL 0x00000012                                             ;0000000140002F79 E8 12 00 00 00 
ADD RSP, 0x28                                               ;0000000140002F7E 48 83 C4 28 
RETN                                                        ;0000000140002F82 C3 
INT 3                                                       ;0000000140002F83 CC 
INT 3                                                       ;0000000140002F84 CC 
INT 3                                                       ;0000000140002F85 CC 
INT 3                                                       ;0000000140002F86 CC 
INT 3                                                       ;0000000140002F87 CC 
INT 3                                                       ;0000000140002F88 CC 
INT 3                                                       ;0000000140002F89 CC 
INT 3                                                       ;0000000140002F8A CC 
INT 3                                                       ;0000000140002F8B CC 
INT 3                                                       ;0000000140002F8C CC 
INT 3                                                       ;0000000140002F8D CC 
INT 3                                                       ;0000000140002F8E CC 
INT 3                                                       ;0000000140002F8F CC 
SUB RSP, 0x68                                               ;0000000140002F90 48 83 EC 68 
MOV ECX, 0x00000001                                         ;0000000140002F94 B9 01 00 00 00 
CALL 0x00000832                                             ;0000000140002F99 E8 32 08 00 00 
MOVZX EAX, AL                                               ;0000000140002F9E 0F B6 C0 
TEST EAX, EAX                                               ;0000000140002FA1 85 C0 
JNZ 0x0A                                                    ;0000000140002FA3 75 0A 
MOV ECX, 0x00000007                                         ;0000000140002FA5 B9 07 00 00 00 
CALL 0x00000DD1                                             ;0000000140002FAA E8 D1 0D 00 00 
MOV byte ptr SS : [ RSP +  + 0x20 ], 0x00                   ;0000000140002FAF C6 44 24 20 00 
CALL 0x000007A7                                             ;0000000140002FB4 E8 A7 07 00 00 
MOV byte ptr SS : [ RSP +  + 0x21 ], AL                     ;0000000140002FB9 88 44 24 21 
CMP CS : [ RIP + 0x000580AC ], 0x01                         ;0000000140002FBD 83 3D AC 80 05 00 01 
JNZ 0x0C                                                    ;0000000140002FC4 75 0C 
MOV ECX, 0x00000007                                         ;0000000140002FC6 B9 07 00 00 00 
CALL 0x00000DB0                                             ;0000000140002FCB E8 B0 0D 00 00 
JMP 0x58                                                    ;0000000140002FD0 EB 58 
CMP CS : [ RIP + 0x00058097 ], 0x00                         ;0000000140002FD2 83 3D 97 80 05 00 00 
JNZ 0x4A                                                    ;0000000140002FD9 75 4A 
MOV CS : [ RIP + 0x0005808B ], 0x00000001                   ;0000000140002FDB C7 05 8B 80 05 00 01 00 00 00 
LEA RDX, CS : [ RIP + 0x000422D4 ]                          ;0000000140002FE5 48 8D 15 D4 22 04 00 
LEA RCX, CS : [ RIP + 0x0004229D ]                          ;0000000140002FEC 48 8D 0D 9D 22 04 00 
CALL 0x00014448                                             ;0000000140002FF3 E8 48 44 01 00 
TEST EAX, EAX                                               ;0000000140002FF8 85 C0 
JZ 0x0A                                                     ;0000000140002FFA 74 0A 
MOV EAX, 0x000000FF                                         ;0000000140002FFC B8 FF 00 00 00 
JMP 0x00000123                                              ;0000000140003001 E9 23 01 00 00 
LEA RDX, CS : [ RIP + 0x0004227B ]                          ;0000000140003006 48 8D 15 7B 22 04 00 
LEA RCX, CS : [ RIP + 0x00042264 ]                          ;000000014000300D 48 8D 0D 64 22 04 00 
CALL 0x000143C7                                             ;0000000140003014 E8 C7 43 01 00 
MOV CS : [ RIP + 0x0005804D ], 0x00000002                   ;0000000140003019 C7 05 4D 80 05 00 02 00 00 00 
JMP 0x05                                                    ;0000000140003023 EB 05 
MOV byte ptr SS : [ RSP +  + 0x20 ], 0x01                   ;0000000140003025 C6 44 24 20 01 
MOVZX ECX, byte ptr SS : [ RSP +  + 0x21 ]                  ;000000014000302A 0F B6 4C 24 21 
CALL 0x0000098C                                             ;000000014000302F E8 8C 09 00 00 
CALL 0x00000D17                                             ;0000000140003034 E8 17 0D 00 00 
MOV qword ptr SS : [ RSP +  + 0x30 ], RAX                   ;0000000140003039 48 89 44 24 30 
MOV RAX, qword ptr SS : [ RSP +  + 0x30 ]                   ;000000014000303E 48 8B 44 24 30 
CMP qword ptr DS : [ RAX ], 0x00                            ;0000000140003043 48 83 38 00 
JZ 0x3D                                                     ;0000000140003047 74 3D 
MOV RCX, qword ptr SS : [ RSP +  + 0x30 ]                   ;0000000140003049 48 8B 4C 24 30 
CALL 0x000008DD                                             ;000000014000304E E8 DD 08 00 00 
MOVZX EAX, AL                                               ;0000000140003053 0F B6 C0 
TEST EAX, EAX                                               ;0000000140003056 85 C0 
JZ 0x2C                                                     ;0000000140003058 74 2C 
MOV RAX, qword ptr SS : [ RSP +  + 0x30 ]                   ;000000014000305A 48 8B 44 24 30 
MOV RAX, qword ptr DS : [ RAX ]                             ;000000014000305F 48 8B 00 
MOV qword ptr SS : [ RSP +  + 0x48 ], RAX                   ;0000000140003062 48 89 44 24 48 
MOV RAX, qword ptr SS : [ RSP +  + 0x48 ]                   ;0000000140003067 48 8B 44 24 48 
MOV qword ptr SS : [ RSP +  + 0x50 ], RAX                   ;000000014000306C 48 89 44 24 50 
XOR R8D, R8D                                                ;0000000140003071 45 33 C0 
MOV EDX, 0x00000002                                         ;0000000140003074 BA 02 00 00 00 
XOR ECX, ECX                                                ;0000000140003079 33 C9 
MOV RAX, qword ptr SS : [ RSP +  + 0x50 ]                   ;000000014000307B 48 8B 44 24 50 
CALL CS : [ RIP + 0x000421EA ]                              ;0000000140003080 FF 15 EA 21 04 00 
CALL 0x00000CD5                                             ;0000000140003086 E8 D5 0C 00 00 
MOV qword ptr SS : [ RSP +  + 0x38 ], RAX                   ;000000014000308B 48 89 44 24 38 
MOV RAX, qword ptr SS : [ RSP +  + 0x38 ]                   ;0000000140003090 48 8B 44 24 38 
CMP qword ptr DS : [ RAX ], 0x00                            ;0000000140003095 48 83 38 00 
JZ 0x1E                                                     ;0000000140003099 74 1E 
MOV RCX, qword ptr SS : [ RSP +  + 0x38 ]                   ;000000014000309B 48 8B 4C 24 38 
CALL 0x0000088B                                             ;00000001400030A0 E8 8B 08 00 00 
MOVZX EAX, AL                                               ;00000001400030A5 0F B6 C0 
TEST EAX, EAX                                               ;00000001400030A8 85 C0 
JZ 0x0D                                                     ;00000001400030AA 74 0D 
MOV RAX, qword ptr SS : [ RSP +  + 0x38 ]                   ;00000001400030AC 48 8B 44 24 38 
MOV RCX, qword ptr DS : [ RAX ]                             ;00000001400030B1 48 8B 08 
CALL 0x00014A47                                             ;00000001400030B4 E8 47 4A 01 00 
CALL 0x000000A2                                             ;00000001400030B9 E8 A2 00 00 00 
MOV dword ptr SS : [ RSP +  + 0x28 ], EAX                   ;00000001400030BE 89 44 24 28 
CALL 0x00000E69                                             ;00000001400030C2 E8 69 0E 00 00 
MOVZX EAX, AL                                               ;00000001400030C7 0F B6 C0 
TEST EAX, EAX                                               ;00000001400030CA 85 C0 
JNZ 0x09                                                    ;00000001400030CC 75 09 
MOV ECX, dword ptr SS : [ RSP +  + 0x28 ]                   ;00000001400030CE 8B 4C 24 28 
CALL 0x00014A79                                             ;00000001400030D2 E8 79 4A 01 00 
MOVZX EAX, byte ptr SS : [ RSP +  + 0x20 ]                  ;00000001400030D7 0F B6 44 24 20 
TEST EAX, EAX                                               ;00000001400030DC 85 C0 
JNZ 0x05                                                    ;00000001400030DE 75 05 
CALL 0x000149DB                                             ;00000001400030E0 E8 DB 49 01 00 
XOR EDX, EDX                                                ;00000001400030E5 33 D2 
MOV CL, 0x01                                                ;00000001400030E7 B1 01 
CALL 0x00000902                                             ;00000001400030E9 E8 02 09 00 00 
MOV EAX, dword ptr SS : [ RSP +  + 0x28 ]                   ;00000001400030EE 8B 44 24 28 
JMP 0x35                                                    ;00000001400030F2 EB 35 
MOV dword ptr SS : [ RSP +  + 0x24 ], EAX                   ;00000001400030F4 89 44 24 24 
MOV EAX, dword ptr SS : [ RSP +  + 0x24 ]                   ;00000001400030F8 8B 44 24 24 
MOV dword ptr SS : [ RSP +  + 0x2C ], EAX                   ;00000001400030FC 89 44 24 2C 
CALL 0x00000E2B                                             ;0000000140003100 E8 2B 0E 00 00 
MOVZX EAX, AL                                               ;0000000140003105 0F B6 C0 
TEST EAX, EAX                                               ;0000000140003108 85 C0 
JNZ 0x09                                                    ;000000014000310A 75 09 
MOV ECX, dword ptr SS : [ RSP +  + 0x2C ]                   ;000000014000310C 8B 4C 24 2C 
CALL 0x000149CB                                             ;0000000140003110 E8 CB 49 01 00 
MOVZX EAX, byte ptr SS : [ RSP +  + 0x20 ]                  ;0000000140003115 0F B6 44 24 20 
TEST EAX, EAX                                               ;000000014000311A 85 C0 
JNZ 0x05                                                    ;000000014000311C 75 05 
CALL 0x0001497D                                             ;000000014000311E E8 7D 49 01 00 
MOV EAX, dword ptr SS : [ RSP +  + 0x2C ]                   ;0000000140003123 8B 44 24 2C 
JMP 0x00                                                    ;0000000140003127 EB 00 
ADD RSP, 0x68                                               ;0000000140003129 48 83 C4 68 
RETN                                                        ;000000014000312D C3 
INT 3                                                       ;000000014000312E CC 
INT 3                                                       ;000000014000312F CC 
SUB RSP, 0x28                                               ;0000000140003130 48 83 EC 28 
CALL 0x00000B17                                             ;0000000140003134 E8 17 0B 00 00 
MOV ECX, EAX                                                ;0000000140003139 8B C8 
CALL 0x00013E30                                             ;000000014000313B E8 30 3E 01 00 
ADD RSP, 0x28                                               ;0000000140003140 48 83 C4 28 
RETN                                                        ;0000000140003144 C3 
INT 3                                                       ;0000000140003145 CC 
INT 3                                                       ;0000000140003146 CC 
INT 3                                                       ;0000000140003147 CC 
INT 3                                                       ;0000000140003148 CC 
INT 3                                                       ;0000000140003149 CC 
INT 3                                                       ;000000014000314A CC 
INT 3                                                       ;000000014000314B CC 
INT 3                                                       ;000000014000314C CC 
INT 3                                                       ;000000014000314D CC 
INT 3                                                       ;000000014000314E CC 
INT 3                                                       ;000000014000314F CC 
SUB RSP, 0x28                                               ;0000000140003150 48 83 EC 28 
CALL 0x00014277                                             ;0000000140003154 E8 77 42 01 00 
ADD RSP, 0x28                                               ;0000000140003159 48 83 C4 28 
RETN                                                        ;000000014000315D C3 
INT 3                                                       ;000000014000315E CC 
INT 3                                                       ;000000014000315F CC 
SUB RSP, 0x38                                               ;0000000140003160 48 83 EC 38 
CALL 0x00014217                                             ;0000000140003164 E8 17 42 01 00 
MOV qword ptr SS : [ RSP +  + 0x20 ], RAX                   ;0000000140003169 48 89 44 24 20 
CALL 0x00014EDD                                             ;000000014000316E E8 DD 4E 01 00 
MOV qword ptr SS : [ RSP +  + 0x28 ], RAX                   ;0000000140003173 48 89 44 24 28 
CALL 0x00014EC3                                             ;0000000140003178 E8 C3 4E 01 00 
MOV RCX, qword ptr SS : [ RSP +  + 0x20 ]                   ;000000014000317D 48 8B 4C 24 20 
MOV R8, RCX                                                 ;0000000140003182 4C 8B C1 
MOV RCX, qword ptr SS : [ RSP +  + 0x28 ]                   ;0000000140003185 48 8B 4C 24 28 
MOV RDX, qword ptr DS : [ RCX ]                             ;000000014000318A 48 8B 11 
MOV ECX, dword ptr DS : [ RAX ]                             ;000000014000318D 8B 08 
CALL 0xFFFFE3CC                                             ;000000014000318F E8 CC E3 FF FF 
ADD RSP, 0x38                                               ;0000000140003194 48 83 C4 38 
RETN                                                        ;0000000140003198 C3 
INT 3                                                       ;0000000140003199 CC 
INT 3                                                       ;000000014000319A CC 
INT 3                                                       ;000000014000319B CC 
INT 3                                                       ;000000014000319C CC 
INT 3                                                       ;000000014000319D CC 
INT 3                                                       ;000000014000319E CC 
INT 3                                                       ;000000014000319F CC 
SUB RSP, 0x28                                               ;00000001400031A0 48 83 EC 28 
MOV ECX, 0x00000001                                         ;00000001400031A4 B9 01 00 00 00 
CALL 0x000131A2                                             ;00000001400031A9 E8 A2 31 01 00 
ADD RSP, 0x28                                               ;00000001400031AE 48 83 C4 28 
RETN                                                        ;00000001400031B2 C3 
INT 3                                                       ;00000001400031B3 CC 
INT 3                                                       ;00000001400031B4 CC 
INT 3                                                       ;00000001400031B5 CC 
INT 3                                                       ;00000001400031B6 CC 
INT 3                                                       ;00000001400031B7 CC 
INT 3                                                       ;00000001400031B8 CC 
INT 3                                                       ;00000001400031B9 CC 
INT 3                                                       ;00000001400031BA CC 
INT 3                                                       ;00000001400031BB CC 
INT 3                                                       ;00000001400031BC CC 
INT 3                                                       ;00000001400031BD CC 
INT 3                                                       ;00000001400031BE CC 
INT 3                                                       ;00000001400031BF CC 
SUB RSP, 0x38                                               ;00000001400031C0 48 83 EC 38 
CALL 0x00000A97                                             ;00000001400031C4 E8 97 0A 00 00 
MOV dword ptr SS : [ RSP +  + 0x20 ], EAX                   ;00000001400031C9 89 44 24 20 
CALL 0x0001527E                                             ;00000001400031CD E8 7E 52 01 00 
MOV ECX, dword ptr SS : [ RSP +  + 0x20 ]                   ;00000001400031D2 8B 4C 24 20 
MOV dword ptr DS : [ RAX ], ECX                             ;00000001400031D6 89 08 
ADD RSP, 0x38                                               ;00000001400031D8 48 83 C4 38 
RETN                                                        ;00000001400031DC C3 
INT 3                                                       ;00000001400031DD CC 
INT 3                                                       ;00000001400031DE CC 
INT 3                                                       ;00000001400031DF CC 
SUB RSP, 0x28                                               ;00000001400031E0 48 83 EC 28 
CALL 0x00000A87                                             ;00000001400031E4 E8 87 0A 00 00 
MOV ECX, EAX                                                ;00000001400031E9 8B C8 
CALL 0x00014A70                                             ;00000001400031EB E8 70 4A 01 00 
ADD RSP, 0x28                                               ;00000001400031F0 48 83 C4 28 
RETN                                                        ;00000001400031F4 C3 
INT 3                                                       ;00000001400031F5 CC 
INT 3                                                       ;00000001400031F6 CC 
INT 3                                                       ;00000001400031F7 CC 
INT 3                                                       ;00000001400031F8 CC 
INT 3                                                       ;00000001400031F9 CC 
INT 3                                                       ;00000001400031FA CC 
INT 3                                                       ;00000001400031FB CC 
INT 3                                                       ;00000001400031FC CC 
INT 3                                                       ;00000001400031FD CC 
INT 3                                                       ;00000001400031FE CC 
INT 3                                                       ;00000001400031FF CC 
SUB RSP, 0x28                                               ;0000000140003200 48 83 EC 28 
CALL 0xFFFFFD67                                             ;0000000140003204 E8 67 FD FF FF 
ADD RSP, 0x28                                               ;0000000140003209 48 83 C4 28 
RETN                                                        ;000000014000320D C3 
INT 3                                                       ;000000014000320E CC 
INT 3                                                       ;000000014000320F CC 
MOV qword ptr SS : [ RSP +  + 0x08 ], RCX                   ;0000000140003210 48 89 4C 24 08 
SUB RSP, 0x28                                               ;0000000140003215 48 83 EC 28 
XOR ECX, ECX                                                ;0000000140003219 33 C9 
CALL CS : [ RIP + 0x00041DFF ]                              ;000000014000321B FF 15 FF 1D 04 00 
MOV RCX, qword ptr SS : [ RSP +  + 0x30 ]                   ;0000000140003221 48 8B 4C 24 30 
CALL CS : [ RIP + 0x00041DEC ]                              ;0000000140003226 FF 15 EC 1D 04 00 
CALL CS : [ RIP + 0x00041DF6 ]                              ;000000014000322C FF 15 F6 1D 04 00 
MOV EDX, 0xC0000409                                         ;0000000140003232 BA 09 04 00 C0 
MOV RCX, RAX                                                ;0000000140003237 48 8B C8 
CALL CS : [ RIP + 0x00041DF0 ]                              ;000000014000323A FF 15 F0 1D 04 00 
ADD RSP, 0x28                                               ;0000000140003240 48 83 C4 28 
RETN                                                        ;0000000140003244 C3 
INT 3                                                       ;0000000140003245 CC 
INT 3                                                       ;0000000140003246 CC 
INT 3                                                       ;0000000140003247 CC 
INT 3                                                       ;0000000140003248 CC 
INT 3                                                       ;0000000140003249 CC 
INT 3                                                       ;000000014000324A CC 
INT 3                                                       ;000000014000324B CC 
INT 3                                                       ;000000014000324C CC 
INT 3                                                       ;000000014000324D CC 
INT 3                                                       ;000000014000324E CC 
INT 3                                                       ;000000014000324F CC 
MOV qword ptr SS : [ RSP +  + 0x08 ], RCX                   ;0000000140003250 48 89 4C 24 08 
SUB RSP, 0x38                                               ;0000000140003255 48 83 EC 38 
MOV ECX, 0x00000017                                         ;0000000140003259 B9 17 00 00 00 
CALL 0x000012ED                                             ;000000014000325E E8 ED 12 00 00 
TEST EAX, EAX                                               ;0000000140003263 85 C0 
JZ 0x07                                                     ;0000000140003265 74 07 
MOV ECX, 0x00000002                                         ;0000000140003267 B9 02 00 00 00 
INT 0x29                                                    ;000000014000326C CD 29 
LEA RCX, CS : [ RIP + 0x0005792B ]                          ;000000014000326E 48 8D 0D 2B 79 05 00 
CALL 0x00000216                                             ;0000000140003275 E8 16 02 00 00 
MOV RAX, qword ptr SS : [ RSP +  + 0x38 ]                   ;000000014000327A 48 8B 44 24 38 
MOV CS : [ RIP + 0x00057A12 ], RAX                          ;000000014000327F 48 89 05 12 7A 05 00 
LEA RAX, invalid ptr SS : [ RSP +  + 0x38 ]                 ;0000000140003286 48 8D 44 24 38 
ADD RAX, 0x08                                               ;000000014000328B 48 83 C0 08 
MOV CS : [ RIP + 0x000579A2 ], RAX                          ;000000014000328F 48 89 05 A2 79 05 00 
MOV RAX, CS : [ RIP + 0x000579FB ]                          ;0000000140003296 48 8B 05 FB 79 05 00 
MOV CS : [ RIP + 0x0005786C ], RAX                          ;000000014000329D 48 89 05 6C 78 05 00 
MOV RAX, qword ptr SS : [ RSP +  + 0x40 ]                   ;00000001400032A4 48 8B 44 24 40 
MOV CS : [ RIP + 0x00057970 ], RAX                          ;00000001400032A9 48 89 05 70 79 05 00 
MOV CS : [ RIP + 0x00057846 ], 0xC0000409                   ;00000001400032B0 C7 05 46 78 05 00 09 04 00 C0 
MOV CS : [ RIP + 0x00057840 ], 0x00000001                   ;00000001400032BA C7 05 40 78 05 00 01 00 00 00 
MOV CS : [ RIP + 0x0005784A ], 0x00000001                   ;00000001400032C4 C7 05 4A 78 05 00 01 00 00 00 
MOV EAX, 0x00000008                                         ;00000001400032CE B8 08 00 00 00 
IMUL RAX, RAX, 0x00                                         ;00000001400032D3 48 6B C0 00 
LEA RCX, CS : [ RIP + 0x00057842 ]                          ;00000001400032D7 48 8D 0D 42 78 05 00 
MOV qword ptr DS : [ RCX + RAX * 1 ], 0x00000002            ;00000001400032DE 48 C7 04 01 02 00 00 00 
MOV EAX, 0x00000008                                         ;00000001400032E6 B8 08 00 00 00 
IMUL RAX, RAX, 0x00                                         ;00000001400032EB 48 6B C0 00 
MOV RCX, CS : [ RIP + 0x00056D12 ]                          ;00000001400032EF 48 8B 0D 12 6D 05 00 
MOV qword ptr SS : [ RSP + RAX * 1 + 0x20 ], RCX            ;00000001400032F6 48 89 4C 04 20 
MOV EAX, 0x00000008                                         ;00000001400032FB B8 08 00 00 00 
IMUL RAX, RAX, 0x01                                         ;0000000140003300 48 6B C0 01 
MOV RCX, CS : [ RIP + 0x00056CF5 ]                          ;0000000140003304 48 8B 0D F5 6C 05 00 
MOV qword ptr SS : [ RSP + RAX * 1 + 0x20 ], RCX            ;000000014000330B 48 89 4C 04 20 
LEA RCX, CS : [ RIP + 0x00042059 ]                          ;0000000140003310 48 8D 0D 59 20 04 00 
CALL 0xFFFFFEF4                                             ;0000000140003317 E8 F4 FE FF FF 
ADD RSP, 0x38                                               ;000000014000331C 48 83 C4 38 
RETN                                                        ;0000000140003320 C3 
INT 3                                                       ;0000000140003321 CC 
INT 3                                                       ;0000000140003322 CC 
INT 3                                                       ;0000000140003323 CC 
INT 3                                                       ;0000000140003324 CC 
INT 3                                                       ;0000000140003325 CC 
INT 3                                                       ;0000000140003326 CC 
INT 3                                                       ;0000000140003327 CC 
INT 3                                                       ;0000000140003328 CC 
INT 3                                                       ;0000000140003329 CC 
INT 3                                                       ;000000014000332A CC 
INT 3                                                       ;000000014000332B CC 
INT 3                                                       ;000000014000332C CC 
INT 3                                                       ;000000014000332D CC 
INT 3                                                       ;000000014000332E CC 
INT 3                                                       ;000000014000332F CC 
SUB RSP, 0x28                                               ;0000000140003330 48 83 EC 28 
MOV ECX, 0x00000008                                         ;0000000140003334 B9 08 00 00 00 
CALL 0x00000012                                             ;0000000140003339 E8 12 00 00 00 
ADD RSP, 0x28                                               ;000000014000333E 48 83 C4 28 
RETN                                                        ;0000000140003342 C3 
INT 3                                                       ;0000000140003343 CC 
INT 3                                                       ;0000000140003344 CC 
INT 3                                                       ;0000000140003345 CC 
INT 3                                                       ;0000000140003346 CC 
INT 3                                                       ;0000000140003347 CC 
INT 3                                                       ;0000000140003348 CC 
INT 3                                                       ;0000000140003349 CC 
INT 3                                                       ;000000014000334A CC 
INT 3                                                       ;000000014000334B CC 
INT 3                                                       ;000000014000334C CC 
INT 3                                                       ;000000014000334D CC 
INT 3                                                       ;000000014000334E CC 
INT 3                                                       ;000000014000334F CC 
MOV dword ptr SS : [ RSP +  + 0x08 ], ECX                   ;0000000140003350 89 4C 24 08 
SUB RSP, 0x28                                               ;0000000140003354 48 83 EC 28 
MOV ECX, 0x00000017                                         ;0000000140003358 B9 17 00 00 00 
CALL 0x000011EE                                             ;000000014000335D E8 EE 11 00 00 
TEST EAX, EAX                                               ;0000000140003362 85 C0 
JZ 0x08                                                     ;0000000140003364 74 08 
MOV EAX, dword ptr SS : [ RSP +  + 0x30 ]                   ;0000000140003366 8B 44 24 30 
MOV ECX, EAX                                                ;000000014000336A 8B C8 
INT 0x29                                                    ;000000014000336C CD 29 
LEA RCX, CS : [ RIP + 0x0005782B ]                          ;000000014000336E 48 8D 0D 2B 78 05 00 
CALL 0x00000076                                             ;0000000140003375 E8 76 00 00 00 
MOV RAX, qword ptr SS : [ RSP +  + 0x28 ]                   ;000000014000337A 48 8B 44 24 28 
MOV CS : [ RIP + 0x00057912 ], RAX                          ;000000014000337F 48 89 05 12 79 05 00 
LEA RAX, invalid ptr SS : [ RSP +  + 0x28 ]                 ;0000000140003386 48 8D 44 24 28 
ADD RAX, 0x08                                               ;000000014000338B 48 83 C0 08 
MOV CS : [ RIP + 0x000578A2 ], RAX                          ;000000014000338F 48 89 05 A2 78 05 00 
MOV RAX, CS : [ RIP + 0x000578FB ]                          ;0000000140003396 48 8B 05 FB 78 05 00 
MOV CS : [ RIP + 0x0005776C ], RAX                          ;000000014000339D 48 89 05 6C 77 05 00 
MOV CS : [ RIP + 0x00057752 ], 0xC0000409                   ;00000001400033A4 C7 05 52 77 05 00 09 04 00 C0 
MOV CS : [ RIP + 0x0005774C ], 0x00000001                   ;00000001400033AE C7 05 4C 77 05 00 01 00 00 00 
MOV CS : [ RIP + 0x00057756 ], 0x00000001                   ;00000001400033B8 C7 05 56 77 05 00 01 00 00 00 
MOV EAX, 0x00000008                                         ;00000001400033C2 B8 08 00 00 00 
IMUL RAX, RAX, 0x00                                         ;00000001400033C7 48 6B C0 00 
LEA RCX, CS : [ RIP + 0x0005774E ]                          ;00000001400033CB 48 8D 0D 4E 77 05 00 
MOV EDX, dword ptr SS : [ RSP +  + 0x30 ]                   ;00000001400033D2 8B 54 24 30 
MOV qword ptr DS : [ RCX + RAX * 1 ], RDX                   ;00000001400033D6 48 89 14 01 
LEA RCX, CS : [ RIP + 0x00041F8F ]                          ;00000001400033DA 48 8D 0D 8F 1F 04 00 
CALL 0xFFFFFE2A                                             ;00000001400033E1 E8 2A FE FF FF 
ADD RSP, 0x28                                               ;00000001400033E6 48 83 C4 28 
RETN                                                        ;00000001400033EA C3 
INT 3                                                       ;00000001400033EB CC 
INT 3                                                       ;00000001400033EC CC 
INT 3                                                       ;00000001400033ED CC 
INT 3                                                       ;00000001400033EE CC 
INT 3                                                       ;00000001400033EF CC 
MOV qword ptr SS : [ RSP +  + 0x08 ], RCX                   ;00000001400033F0 48 89 4C 24 08 
SUB RSP, 0x78                                               ;00000001400033F5 48 83 EC 78 
MOV RCX, qword ptr SS : [ RSP +  + 0x00000080 ]             ;00000001400033F9 48 8B 8C 24 80 00 00 00 
CALL CS : [ RIP + 0x00041BF9 ]                              ;0000000140003401 FF 15 F9 1B 04 00 
MOV RAX, qword ptr SS : [ RSP +  + 0x00000080 ]             ;0000000140003407 48 8B 84 24 80 00 00 00 
MOV RAX, qword ptr DS : [ RAX + 0x000000F8 ]                ;000000014000340F 48 8B 80 F8 00 00 00 
MOV qword ptr SS : [ RSP +  + 0x48 ], RAX                   ;0000000140003416 48 89 44 24 48 
XOR R8D, R8D                                                ;000000014000341B 45 33 C0 
LEA RDX, invalid ptr SS : [ RSP +  + 0x50 ]                 ;000000014000341E 48 8D 54 24 50 
MOV RCX, qword ptr SS : [ RSP +  + 0x48 ]                   ;0000000140003423 48 8B 4C 24 48 
CALL CS : [ RIP + 0x00041BDA ]                              ;0000000140003428 FF 15 DA 1B 04 00 
MOV qword ptr SS : [ RSP +  + 0x40 ], RAX                   ;000000014000342E 48 89 44 24 40 
CMP qword ptr SS : [ RSP +  + 0x40 ], 0x00                  ;0000000140003433 48 83 7C 24 40 00 
JZ 0x41                                                     ;0000000140003439 74 41 
MOV qword ptr SS : [ RSP +  + 0x38 ], 0x00000000            ;000000014000343B 48 C7 44 24 38 00 00 00 00 
LEA RAX, invalid ptr SS : [ RSP +  + 0x58 ]                 ;0000000140003444 48 8D 44 24 58 
MOV qword ptr SS : [ RSP +  + 0x30 ], RAX                   ;0000000140003449 48 89 44 24 30 
LEA RAX, invalid ptr SS : [ RSP +  + 0x60 ]                 ;000000014000344E 48 8D 44 24 60 
MOV qword ptr SS : [ RSP +  + 0x28 ], RAX                   ;0000000140003453 48 89 44 24 28 
MOV RAX, qword ptr SS : [ RSP +  + 0x00000080 ]             ;0000000140003458 48 8B 84 24 80 00 00 00 
MOV qword ptr SS : [ RSP +  + 0x20 ], RAX                   ;0000000140003460 48 89 44 24 20 
MOV R9, qword ptr SS : [ RSP +  + 0x40 ]                    ;0000000140003465 4C 8B 4C 24 40 
MOV R8, qword ptr SS : [ RSP +  + 0x48 ]                    ;000000014000346A 4C 8B 44 24 48 
MOV RDX, qword ptr SS : [ RSP +  + 0x50 ]                   ;000000014000346F 48 8B 54 24 50 
XOR ECX, ECX                                                ;0000000140003474 33 C9 
CALL CS : [ RIP + 0x00041B94 ]                              ;0000000140003476 FF 15 94 1B 04 00 
ADD RSP, 0x78                                               ;000000014000347C 48 83 C4 78 
RETN                                                        ;0000000140003480 C3 
INT 3                                                       ;0000000140003481 CC 
INT 3                                                       ;0000000140003482 CC 
INT 3                                                       ;0000000140003483 CC 
INT 3                                                       ;0000000140003484 CC 
INT 3                                                       ;0000000140003485 CC 
INT 3                                                       ;0000000140003486 CC 
INT 3                                                       ;0000000140003487 CC 
INT 3                                                       ;0000000140003488 CC 
INT 3                                                       ;0000000140003489 CC 
INT 3                                                       ;000000014000348A CC 
INT 3                                                       ;000000014000348B CC 
INT 3                                                       ;000000014000348C CC 
INT 3                                                       ;000000014000348D CC 
INT 3                                                       ;000000014000348E CC 
INT 3                                                       ;000000014000348F CC 
MOV qword ptr SS : [ RSP +  + 0x08 ], RCX                   ;0000000140003490 48 89 4C 24 08 
SUB RSP, 0x78                                               ;0000000140003495 48 83 EC 78 
MOV RCX, qword ptr SS : [ RSP +  + 0x00000080 ]             ;0000000140003499 48 8B 8C 24 80 00 00 00 
CALL CS : [ RIP + 0x00041B59 ]                              ;00000001400034A1 FF 15 59 1B 04 00 
MOV RAX, qword ptr SS : [ RSP +  + 0x00000080 ]             ;00000001400034A7 48 8B 84 24 80 00 00 00 
MOV RAX, qword ptr DS : [ RAX + 0x000000F8 ]                ;00000001400034AF 48 8B 80 F8 00 00 00 
MOV qword ptr SS : [ RSP +  + 0x50 ], RAX                   ;00000001400034B6 48 89 44 24 50 
MOV dword ptr SS : [ RSP +  + 0x40 ], 0x00000000            ;00000001400034BB C7 44 24 40 00 00 00 00 
JMP 0x0A                                                    ;00000001400034C3 EB 0A 
MOV EAX, dword ptr SS : [ RSP +  + 0x40 ]                   ;00000001400034C5 8B 44 24 40 
INC EAX                                                     ;00000001400034C9 FF C0 
MOV dword ptr SS : [ RSP +  + 0x40 ], EAX                   ;00000001400034CB 89 44 24 40 
CMP dword ptr SS : [ RSP +  + 0x40 ], 0x02                  ;00000001400034CF 83 7C 24 40 02 
JGE 0x67                                                    ;00000001400034D4 7D 67 
XOR R8D, R8D                                                ;00000001400034D6 45 33 C0 
LEA RDX, invalid ptr SS : [ RSP +  + 0x58 ]                 ;00000001400034D9 48 8D 54 24 58 
MOV RCX, qword ptr SS : [ RSP +  + 0x50 ]                   ;00000001400034DE 48 8B 4C 24 50 
CALL CS : [ RIP + 0x00041B1F ]                              ;00000001400034E3 FF 15 1F 1B 04 00 
MOV qword ptr SS : [ RSP +  + 0x48 ], RAX                   ;00000001400034E9 48 89 44 24 48 
CMP qword ptr SS : [ RSP +  + 0x48 ], 0x00                  ;00000001400034EE 48 83 7C 24 48 00 
JZ 0x43                                                     ;00000001400034F4 74 43 
MOV qword ptr SS : [ RSP +  + 0x38 ], 0x00000000            ;00000001400034F6 48 C7 44 24 38 00 00 00 00 
LEA RAX, invalid ptr SS : [ RSP +  + 0x60 ]                 ;00000001400034FF 48 8D 44 24 60 
MOV qword ptr SS : [ RSP +  + 0x30 ], RAX                   ;0000000140003504 48 89 44 24 30 
LEA RAX, invalid ptr SS : [ RSP +  + 0x68 ]                 ;0000000140003509 48 8D 44 24 68 
MOV qword ptr SS : [ RSP +  + 0x28 ], RAX                   ;000000014000350E 48 89 44 24 28 
MOV RAX, qword ptr SS : [ RSP +  + 0x00000080 ]             ;0000000140003513 48 8B 84 24 80 00 00 00 
MOV qword ptr SS : [ RSP +  + 0x20 ], RAX                   ;000000014000351B 48 89 44 24 20 
MOV R9, qword ptr SS : [ RSP +  + 0x48 ]                    ;0000000140003520 4C 8B 4C 24 48 
MOV R8, qword ptr SS : [ RSP +  + 0x50 ]                    ;0000000140003525 4C 8B 44 24 50 
MOV RDX, qword ptr SS : [ RSP +  + 0x58 ]                   ;000000014000352A 48 8B 54 24 58 
XOR ECX, ECX                                                ;000000014000352F 33 C9 
CALL CS : [ RIP + 0x00041AD9 ]                              ;0000000140003531 FF 15 D9 1A 04 00 
JMP 0x02                                                    ;0000000140003537 EB 02 
JMP 0x02                                                    ;0000000140003539 EB 02 
JMP 0x88                                                    ;000000014000353B EB 88 
ADD RSP, 0x78                                               ;000000014000353D 48 83 C4 78 
RETN                                                        ;0000000140003541 C3 
INT 3                                                       ;0000000140003542 CC 
INT 3                                                       ;0000000140003543 CC 
INT 3                                                       ;0000000140003544 CC 
INT 3                                                       ;0000000140003545 CC 
INT 3                                                       ;0000000140003546 CC 
INT 3                                                       ;0000000140003547 CC 
INT 3                                                       ;0000000140003548 CC 
INT 3                                                       ;0000000140003549 CC 
INT 3                                                       ;000000014000354A CC 
INT 3                                                       ;000000014000354B CC 
INT 3                                                       ;000000014000354C CC 
INT 3                                                       ;000000014000354D CC 
INT 3                                                       ;000000014000354E CC 
INT 3                                                       ;000000014000354F CC 
MOV qword ptr SS : [ RSP +  + 0x08 ], RCX                   ;0000000140003550 48 89 4C 24 08 
SUB RSP, 0x28                                               ;0000000140003555 48 83 EC 28 
XOR EDX, EDX                                                ;0000000140003559 33 D2 
MOV RAX, CS : [ RIP + 0x00056AA6 ]                          ;000000014000355B 48 8B 05 A6 6A 05 00 
MOV ECX, 0x00000040                                         ;0000000140003562 B9 40 00 00 00 
DIV RCX                                                     ;0000000140003567 48 F7 F1 
MOV RAX, RDX                                                ;000000014000356A 48 8B C2 
MOV RCX, CS : [ RIP + 0x00056A94 ]                          ;000000014000356D 48 8B 0D 94 6A 05 00 
MOV RDX, qword ptr SS : [ RSP +  + 0x30 ]                   ;0000000140003574 48 8B 54 24 30 
XOR RDX, RCX                                                ;0000000140003579 48 33 D1 
MOV RCX, RDX                                                ;000000014000357C 48 8B CA 
MOV EDX, EAX                                                ;000000014000357F 8B D0 
CALL 0x0000004A                                             ;0000000140003581 E8 4A 00 00 00 
ADD RSP, 0x28                                               ;0000000140003586 48 83 C4 28 
RETN                                                        ;000000014000358A C3 
INT 3                                                       ;000000014000358B CC 
INT 3                                                       ;000000014000358C CC 
INT 3                                                       ;000000014000358D CC 
INT 3                                                       ;000000014000358E CC 
INT 3                                                       ;000000014000358F CC 
MOV qword ptr SS : [ RSP +  + 0x08 ], RCX                   ;0000000140003590 48 89 4C 24 08 
SUB RSP, 0x28                                               ;0000000140003595 48 83 EC 28 
XOR EDX, EDX                                                ;0000000140003599 33 D2 
MOV RAX, CS : [ RIP + 0x00056A66 ]                          ;000000014000359B 48 8B 05 66 6A 05 00 
MOV ECX, 0x00000040                                         ;00000001400035A2 B9 40 00 00 00 
DIV RCX                                                     ;00000001400035A7 48 F7 F1 
MOV RAX, RDX                                                ;00000001400035AA 48 8B C2 
MOV ECX, 0x00000040                                         ;00000001400035AD B9 40 00 00 00 
SUB RCX, RAX                                                ;00000001400035B2 48 2B C8 
MOV RAX, RCX                                                ;00000001400035B5 48 8B C1 
MOV EDX, EAX                                                ;00000001400035B8 8B D0 
MOV RCX, qword ptr SS : [ RSP +  + 0x30 ]                   ;00000001400035BA 48 8B 4C 24 30 
CALL 0x0000000C                                             ;00000001400035BF E8 0C 00 00 00 
XOR RAX, CS : [ RIP + 0x00056A3D ]                          ;00000001400035C4 48 33 05 3D 6A 05 00 
ADD RSP, 0x28                                               ;00000001400035CB 48 83 C4 28 
RETN                                                        ;00000001400035CF C3 
MOV dword ptr SS : [ RSP +  + 0x10 ], EDX                   ;00000001400035D0 89 54 24 10 
MOV qword ptr SS : [ RSP +  + 0x08 ], RCX                   ;00000001400035D4 48 89 4C 24 08 
MOV EAX, dword ptr SS : [ RSP +  + 0x10 ]                   ;00000001400035D9 8B 44 24 10 
MOVZX ECX, AL                                               ;00000001400035DD 0F B6 C8 
MOV RAX, qword ptr SS : [ RSP +  + 0x08 ]                   ;00000001400035E0 48 8B 44 24 08 
ROR RAX, CL                                                 ;00000001400035E5 48 D3 C8 
RETN                                                        ;00000001400035E8 C3 
INT 3                                                       ;00000001400035E9 CC 
INT 3                                                       ;00000001400035EA CC 
INT 3                                                       ;00000001400035EB CC 
INT 3                                                       ;00000001400035EC CC 
INT 3                                                       ;00000001400035ED CC 
INT 3                                                       ;00000001400035EE CC 
INT 3                                                       ;00000001400035EF CC 
MOV qword ptr SS : [ RSP +  + 0x10 ], RDX                   ;00000001400035F0 48 89 54 24 10 
MOV qword ptr SS : [ RSP +  + 0x08 ], RCX                   ;00000001400035F5 48 89 4C 24 08 
SUB RSP, 0x38                                               ;00000001400035FA 48 83 EC 38 
MOV RAX, qword ptr SS : [ RSP +  + 0x40 ]                   ;00000001400035FE 48 8B 44 24 40 
MOV qword ptr SS : [ RSP +  + 0x10 ], RAX                   ;0000000140003603 48 89 44 24 10 
MOV RAX, qword ptr SS : [ RSP +  + 0x10 ]                   ;0000000140003608 48 8B 44 24 10 
MOVSXD RAX, dword ptr DS : [ RAX + 0x3C ]                   ;000000014000360D 48 63 40 3C 
MOV RCX, qword ptr SS : [ RSP +  + 0x10 ]                   ;0000000140003611 48 8B 4C 24 10 
ADD RCX, RAX                                                ;0000000140003616 48 03 C8 
MOV RAX, RCX                                                ;0000000140003619 48 8B C1 
MOV qword ptr SS : [ RSP +  + 0x20 ], RAX                   ;000000014000361C 48 89 44 24 20 
MOV RAX, qword ptr SS : [ RSP +  + 0x20 ]                   ;0000000140003621 48 8B 44 24 20 
MOV qword ptr SS : [ RSP +  + 0x08 ], RAX                   ;0000000140003626 48 89 44 24 08 
MOV RAX, qword ptr SS : [ RSP +  + 0x08 ]                   ;000000014000362B 48 8B 44 24 08 
MOVZX EAX, word ptr DS : [ RAX + 0x14 ]                     ;0000000140003630 0F B7 40 14 
MOV RCX, qword ptr SS : [ RSP +  + 0x08 ]                   ;0000000140003634 48 8B 4C 24 08 
LEA RAX, invalid ptr DS : [ RCX + RAX * 1 + 0x18 ]          ;0000000140003639 48 8D 44 01 18 
MOV qword ptr SS : [ RSP +  + 0x18 ], RAX                   ;000000014000363E 48 89 44 24 18 
MOV RAX, qword ptr SS : [ RSP +  + 0x08 ]                   ;0000000140003643 48 8B 44 24 08 
MOVZX EAX, word ptr DS : [ RAX + 0x06 ]                     ;0000000140003648 0F B7 40 06 
IMUL RAX, RAX, 0x28                                         ;000000014000364C 48 6B C0 28 
MOV RCX, qword ptr SS : [ RSP +  + 0x18 ]                   ;0000000140003650 48 8B 4C 24 18 
ADD RCX, RAX                                                ;0000000140003655 48 03 C8 
MOV RAX, RCX                                                ;0000000140003658 48 8B C1 
MOV qword ptr SS : [ RSP +  + 0x28 ], RAX                   ;000000014000365B 48 89 44 24 28 
MOV RAX, qword ptr SS : [ RSP +  + 0x18 ]                   ;0000000140003660 48 8B 44 24 18 
MOV qword ptr SS : [ RSP +  ], RAX                          ;0000000140003665 48 89 04 24 
JMP 0x0C                                                    ;0000000140003669 EB 0C 
MOV RAX, qword ptr SS : [ RSP +  ]                          ;000000014000366B 48 8B 04 24 
ADD RAX, 0x28                                               ;000000014000366F 48 83 C0 28 
MOV qword ptr SS : [ RSP +  ], RAX                          ;0000000140003673 48 89 04 24 
MOV RAX, qword ptr SS : [ RSP +  + 0x28 ]                   ;0000000140003677 48 8B 44 24 28 
CMP qword ptr SS : [ RSP +  ], RAX                          ;000000014000367C 48 39 04 24 
JZ 0x2D                                                     ;0000000140003680 74 2D 
MOV RAX, qword ptr SS : [ RSP +  ]                          ;0000000140003682 48 8B 04 24 
MOV EAX, dword ptr DS : [ RAX + 0x0C ]                      ;0000000140003686 8B 40 0C 
CMP qword ptr SS : [ RSP +  + 0x48 ], RAX                   ;0000000140003689 48 39 44 24 48 
JB 0x1D                                                     ;000000014000368E 72 1D 
MOV RAX, qword ptr SS : [ RSP +  ]                          ;0000000140003690 48 8B 04 24 
MOV EAX, dword ptr DS : [ RAX + 0x0C ]                      ;0000000140003694 8B 40 0C 
MOV RCX, qword ptr SS : [ RSP +  ]                          ;0000000140003697 48 8B 0C 24 
ADD EAX, dword ptr DS : [ RCX + 0x08 ]                      ;000000014000369B 03 41 08 
MOV EAX, EAX                                                ;000000014000369E 8B C0 
CMP qword ptr SS : [ RSP +  + 0x48 ], RAX                   ;00000001400036A0 48 39 44 24 48 
JAE 0x06                                                    ;00000001400036A5 73 06 
MOV RAX, qword ptr SS : [ RSP +  ]                          ;00000001400036A7 48 8B 04 24 
JMP 0x04                                                    ;00000001400036AB EB 04 
JMP 0xBC                                                    ;00000001400036AD EB BC 
XOR EAX, EAX                                                ;00000001400036AF 33 C0 
ADD RSP, 0x38                                               ;00000001400036B1 48 83 C4 38 
RETN                                                        ;00000001400036B5 C3 
INT 3                                                       ;00000001400036B6 CC 
INT 3                                                       ;00000001400036B7 CC 
INT 3                                                       ;00000001400036B8 CC 
INT 3                                                       ;00000001400036B9 CC 
INT 3                                                       ;00000001400036BA CC 
INT 3                                                       ;00000001400036BB CC 
INT 3                                                       ;00000001400036BC CC 
INT 3                                                       ;00000001400036BD CC 
INT 3                                                       ;00000001400036BE CC 
INT 3                                                       ;00000001400036BF CC 
MOV qword ptr SS : [ RSP +  + 0x08 ], RCX                   ;00000001400036C0 48 89 4C 24 08 
SUB RSP, 0x28                                               ;00000001400036C5 48 83 EC 28 
CMP qword ptr SS : [ RSP +  + 0x30 ], 0x00                  ;00000001400036C9 48 83 7C 24 30 00 
JNZ 0x04                                                    ;00000001400036CF 75 04 
XOR AL, AL                                                  ;00000001400036D1 32 C0 
JMP 0x70                                                    ;00000001400036D3 EB 70 
MOV RAX, qword ptr SS : [ RSP +  + 0x30 ]                   ;00000001400036D5 48 8B 44 24 30 
MOV qword ptr SS : [ RSP +  ], RAX                          ;00000001400036DA 48 89 04 24 
MOV RAX, qword ptr SS : [ RSP +  ]                          ;00000001400036DE 48 8B 04 24 
MOVZX EAX, word ptr DS : [ RAX ]                            ;00000001400036E2 0F B7 00 
CMP EAX, 0x00005A4D                                         ;00000001400036E5 3D 4D 5A 00 00 
JZ 0x04                                                     ;00000001400036EA 74 04 
XOR AL, AL                                                  ;00000001400036EC 32 C0 
JMP 0x55                                                    ;00000001400036EE EB 55 
MOV RAX, qword ptr SS : [ RSP +  ]                          ;00000001400036F0 48 8B 04 24 
MOVSXD RAX, dword ptr DS : [ RAX + 0x3C ]                   ;00000001400036F4 48 63 40 3C 
MOV RCX, qword ptr SS : [ RSP +  ]                          ;00000001400036F8 48 8B 0C 24 
ADD RCX, RAX                                                ;00000001400036FC 48 03 C8 
MOV RAX, RCX                                                ;00000001400036FF 48 8B C1 
MOV qword ptr SS : [ RSP +  + 0x10 ], RAX                   ;0000000140003702 48 89 44 24 10 
MOV RAX, qword ptr SS : [ RSP +  + 0x10 ]                   ;0000000140003707 48 8B 44 24 10 
MOV qword ptr SS : [ RSP +  + 0x08 ], RAX                   ;000000014000370C 48 89 44 24 08 
MOV RAX, qword ptr SS : [ RSP +  + 0x08 ]                   ;0000000140003711 48 8B 44 24 08 
CMP dword ptr DS : [ RAX ], 0x00004550                      ;0000000140003716 81 38 50 45 00 00 
JZ 0x04                                                     ;000000014000371C 74 04 
XOR AL, AL                                                  ;000000014000371E 32 C0 
JMP 0x23                                                    ;0000000140003720 EB 23 
MOV RAX, qword ptr SS : [ RSP +  + 0x08 ]                   ;0000000140003722 48 8B 44 24 08 
ADD RAX, 0x18                                               ;0000000140003727 48 83 C0 18 
MOV qword ptr SS : [ RSP +  + 0x18 ], RAX                   ;000000014000372B 48 89 44 24 18 
MOV RAX, qword ptr SS : [ RSP +  + 0x18 ]                   ;0000000140003730 48 8B 44 24 18 
MOVZX EAX, word ptr DS : [ RAX ]                            ;0000000140003735 0F B7 00 
CMP EAX, 0x0000020B                                         ;0000000140003738 3D 0B 02 00 00 
JZ 0x04                                                     ;000000014000373D 74 04 
XOR AL, AL                                                  ;000000014000373F 32 C0 
JMP 0x02                                                    ;0000000140003741 EB 02 
MOV AL, 0x01                                                ;0000000140003743 B0 01 
ADD RSP, 0x28                                               ;0000000140003745 48 83 C4 28 
RETN                                                        ;0000000140003749 C3 
INT 3                                                       ;000000014000374A CC 
INT 3                                                       ;000000014000374B CC 
INT 3                                                       ;000000014000374C CC 
INT 3                                                       ;000000014000374D CC 
INT 3                                                       ;000000014000374E CC 
INT 3                                                       ;000000014000374F CC 
MOV RAX, qword ptr GS : [  ]                                ;0000000140003750 65 48 8B 04 25 
XOR byte ptr DS : [ RAX ], AL                               ;0000000140003755 30 00 
ADD byte ptr DS : [ RAX ], AL                               ;0000000140003757 00 00 
RETN                                                        ;0000000140003759 C3 
INT 3                                                       ;000000014000375A CC 
INT 3                                                       ;000000014000375B CC 
INT 3                                                       ;000000014000375C CC 
INT 3                                                       ;000000014000375D CC 
INT 3                                                       ;000000014000375E CC 
INT 3                                                       ;000000014000375F CC 
SUB RSP, 0x48                                               ;0000000140003760 48 83 EC 48 
CALL 0x00000DB7                                             ;0000000140003764 E8 B7 0D 00 00 
TEST EAX, EAX                                               ;0000000140003769 85 C0 
JNZ 0x04                                                    ;000000014000376B 75 04 
XOR AL, AL                                                  ;000000014000376D 32 C0 
JMP 0x4C                                                    ;000000014000376F EB 4C 
CALL 0xFFFFFFDA                                             ;0000000140003771 E8 DA FF FF FF 
MOV RAX, qword ptr DS : [ RAX + 0x08 ]                      ;0000000140003776 48 8B 40 08 
MOV qword ptr SS : [ RSP +  + 0x28 ], RAX                   ;000000014000377A 48 89 44 24 28 
MOV RAX, qword ptr SS : [ RSP +  + 0x28 ]                   ;000000014000377F 48 8B 44 24 28 
MOV qword ptr SS : [ RSP +  + 0x30 ], RAX                   ;0000000140003784 48 89 44 24 30 
LEA RCX, CS : [ RIP + 0x000578E8 ]                          ;0000000140003789 48 8D 0D E8 78 05 00 
XOR EAX, EAX                                                ;0000000140003790 33 C0 
MOV RDX, qword ptr SS : [ RSP +  + 0x30 ]                   ;0000000140003792 48 8B 54 24 30 
LOCK CMPXCHG qword ptr DS : [ RCX ], RDX                    ;0000000140003797 F0 48 0F B1 11 
MOV qword ptr SS : [ RSP +  + 0x20 ], RAX                   ;000000014000379C 48 89 44 24 20 
CMP qword ptr SS : [ RSP +  + 0x20 ], 0x00                  ;00000001400037A1 48 83 7C 24 20 00 
JZ 0x12                                                     ;00000001400037A7 74 12 
MOV RAX, qword ptr SS : [ RSP +  + 0x20 ]                   ;00000001400037A9 48 8B 44 24 20 
CMP qword ptr SS : [ RSP +  + 0x28 ], RAX                   ;00000001400037AE 48 39 44 24 28 
JNZ 0x04                                                    ;00000001400037B3 75 04 
MOV AL, 0x01                                                ;00000001400037B5 B0 01 
JMP 0x04                                                    ;00000001400037B7 EB 04 
JMP 0xC4                                                    ;00000001400037B9 EB C4 
XOR AL, AL                                                  ;00000001400037BB 32 C0 
ADD RSP, 0x48                                               ;00000001400037BD 48 83 C4 48 
RETN                                                        ;00000001400037C1 C3 
INT 3                                                       ;00000001400037C2 CC 
INT 3                                                       ;00000001400037C3 CC 
INT 3                                                       ;00000001400037C4 CC 
INT 3                                                       ;00000001400037C5 CC 
INT 3                                                       ;00000001400037C6 CC 
INT 3                                                       ;00000001400037C7 CC 
INT 3                                                       ;00000001400037C8 CC 
INT 3                                                       ;00000001400037C9 CC 
INT 3                                                       ;00000001400037CA CC 
INT 3                                                       ;00000001400037CB CC 
INT 3                                                       ;00000001400037CC CC 
INT 3                                                       ;00000001400037CD CC 
INT 3                                                       ;00000001400037CE CC 
INT 3                                                       ;00000001400037CF CC 
MOV dword ptr SS : [ RSP +  + 0x08 ], ECX                   ;00000001400037D0 89 4C 24 08 
SUB RSP, 0x28                                               ;00000001400037D4 48 83 EC 28 
CMP dword ptr SS : [ RSP +  + 0x30 ], 0x00                  ;00000001400037D8 83 7C 24 30 00 
JNZ 0x07                                                    ;00000001400037DD 75 07 
MOV CS : [ RIP + 0x0005789A ], 0x01                         ;00000001400037DF C6 05 9A 78 05 00 01 
CALL 0x000009C5                                             ;00000001400037E6 E8 C5 09 00 00 
CALL 0x000011B0                                             ;00000001400037EB E8 B0 11 00 00 
MOVZX EAX, AL                                               ;00000001400037F0 0F B6 C0 
TEST EAX, EAX                                               ;00000001400037F3 85 C0 
JNZ 0x04                                                    ;00000001400037F5 75 04 
XOR AL, AL                                                  ;00000001400037F7 32 C0 
JMP 0x19                                                    ;00000001400037F9 EB 19 
CALL 0x000156A0                                             ;00000001400037FB E8 A0 56 01 00 
MOVZX EAX, AL                                               ;0000000140003800 0F B6 C0 
TEST EAX, EAX                                               ;0000000140003803 85 C0 
JNZ 0x0B                                                    ;0000000140003805 75 0B 
XOR ECX, ECX                                                ;0000000140003807 33 C9 
CALL 0x000011D2                                             ;0000000140003809 E8 D2 11 00 00 
XOR AL, AL                                                  ;000000014000380E 32 C0 
JMP 0x02                                                    ;0000000140003810 EB 02 
MOV AL, 0x01                                                ;0000000140003812 B0 01 
ADD RSP, 0x28                                               ;0000000140003814 48 83 C4 28 
RETN                                                        ;0000000140003818 C3 
INT 3                                                       ;0000000140003819 CC 
INT 3                                                       ;000000014000381A CC 
INT 3                                                       ;000000014000381B CC 
INT 3                                                       ;000000014000381C CC 
INT 3                                                       ;000000014000381D CC 
INT 3                                                       ;000000014000381E CC 
INT 3                                                       ;000000014000381F CC 
MOV dword ptr SS : [ RSP +  + 0x08 ], ECX                   ;0000000140003820 89 4C 24 08 
PUSH ESI                                                    ;0000000140003824 56 
PUSH EDI                                                    ;0000000140003825 57 
SUB RSP, 0x68                                               ;0000000140003826 48 83 EC 68 
MOVZX EAX, CS : [ RIP + 0x00057850 ]                        ;000000014000382A 0F B6 05 50 78 05 00 
TEST EAX, EAX                                               ;0000000140003831 85 C0 
JZ 0x07                                                     ;0000000140003833 74 07 
MOV AL, 0x01                                                ;0000000140003835 B0 01 
JMP 0x000000E9                                              ;0000000140003837 E9 E9 00 00 00 
CMP dword ptr SS : [ RSP +  + 0x00000080 ], 0x00            ;000000014000383C 83 BC 24 80 00 00 00 00 
JZ 0x14                                                     ;0000000140003844 74 14 
CMP dword ptr SS : [ RSP +  + 0x00000080 ], 0x01            ;0000000140003846 83 BC 24 80 00 00 00 01 
JZ 0x0A                                                     ;000000014000384E 74 0A 
MOV ECX, 0x00000005                                         ;0000000140003850 B9 05 00 00 00 
CALL 0x00000526                                             ;0000000140003855 E8 26 05 00 00 
CALL 0x00000CC1                                             ;000000014000385A E8 C1 0C 00 00 
TEST EAX, EAX                                               ;000000014000385F 85 C0 
JZ 0x3A                                                     ;0000000140003861 74 3A 
CMP dword ptr SS : [ RSP +  + 0x00000080 ], 0x00            ;0000000140003863 83 BC 24 80 00 00 00 00 
JNZ 0x30                                                    ;000000014000386B 75 30 
LEA RCX, CS : [ RIP + 0x00057814 ]                          ;000000014000386D 48 8D 0D 14 78 05 00 
CALL 0x000152C7                                             ;0000000140003874 E8 C7 52 01 00 
TEST EAX, EAX                                               ;0000000140003879 85 C0 
JZ 0x07                                                     ;000000014000387B 74 07 
XOR AL, AL                                                  ;000000014000387D 32 C0 
JMP 0x000000A1                                              ;000000014000387F E9 A1 00 00 00 
LEA RCX, CS : [ RIP + 0x00057815 ]                          ;0000000140003884 48 8D 0D 15 78 05 00 
CALL 0x000152B0                                             ;000000014000388B E8 B0 52 01 00 
TEST EAX, EAX                                               ;0000000140003890 85 C0 
JZ 0x07                                                     ;0000000140003892 74 07 
XOR AL, AL                                                  ;0000000140003894 32 C0 
JMP 0x0000008A                                              ;0000000140003896 E9 8A 00 00 00 
JMP 0x7F                                                    ;000000014000389B EB 7F 
MOV RCX, 0xFFFFFFFF                                         ;000000014000389D 48 C7 C1 FF FF FF FF 
CALL 0xFFFFFCE7                                             ;00000001400038A4 E8 E7 FC FF FF 
MOV qword ptr SS : [ RSP +  + 0x20 ], RAX                   ;00000001400038A9 48 89 44 24 20 
MOV RAX, qword ptr SS : [ RSP +  + 0x20 ]                   ;00000001400038AE 48 8B 44 24 20 
MOV qword ptr SS : [ RSP +  + 0x28 ], RAX                   ;00000001400038B3 48 89 44 24 28 
MOV RAX, qword ptr SS : [ RSP +  + 0x20 ]                   ;00000001400038B8 48 8B 44 24 20 
MOV qword ptr SS : [ RSP +  + 0x30 ], RAX                   ;00000001400038BD 48 89 44 24 30 
MOV RAX, qword ptr SS : [ RSP +  + 0x20 ]                   ;00000001400038C2 48 8B 44 24 20 
MOV qword ptr SS : [ RSP +  + 0x38 ], RAX                   ;00000001400038C7 48 89 44 24 38 
LEA RAX, CS : [ RIP + 0x000577B5 ]                          ;00000001400038CC 48 8D 05 B5 77 05 00 
LEA RCX, invalid ptr SS : [ RSP +  + 0x28 ]                 ;00000001400038D3 48 8D 4C 24 28 
MOV RDI, RAX                                                ;00000001400038D8 48 8B F8 
MOV RSI, RCX                                                ;00000001400038DB 48 8B F1 
MOV ECX, 0x00000018                                         ;00000001400038DE B9 18 00 00 00 
REP MOVSB                                                   ;00000001400038E3 F3 A4 
MOV RAX, qword ptr SS : [ RSP +  + 0x20 ]                   ;00000001400038E5 48 8B 44 24 20 
MOV qword ptr SS : [ RSP +  + 0x40 ], RAX                   ;00000001400038EA 48 89 44 24 40 
MOV RAX, qword ptr SS : [ RSP +  + 0x20 ]                   ;00000001400038EF 48 8B 44 24 20 
MOV qword ptr SS : [ RSP +  + 0x48 ], RAX                   ;00000001400038F4 48 89 44 24 48 
MOV RAX, qword ptr SS : [ RSP +  + 0x20 ]                   ;00000001400038F9 48 8B 44 24 20 
MOV qword ptr SS : [ RSP +  + 0x50 ], RAX                   ;00000001400038FE 48 89 44 24 50 
LEA RAX, CS : [ RIP + 0x00057796 ]                          ;0000000140003903 48 8D 05 96 77 05 00 
LEA RCX, invalid ptr SS : [ RSP +  + 0x40 ]                 ;000000014000390A 48 8D 4C 24 40 
MOV RDI, RAX                                                ;000000014000390F 48 8B F8 
MOV RSI, RCX                                                ;0000000140003912 48 8B F1 
MOV ECX, 0x00000018                                         ;0000000140003915 B9 18 00 00 00 
REP MOVSB                                                   ;000000014000391A F3 A4 
MOV CS : [ RIP + 0x0005775E ], 0x01                         ;000000014000391C C6 05 5E 77 05 00 01 
MOV AL, 0x01                                                ;0000000140003923 B0 01 
ADD RSP, 0x68                                               ;0000000140003925 48 83 C4 68 
POP EDI                                                     ;0000000140003929 5F 
POP ESI                                                     ;000000014000392A 5E 
RETN                                                        ;000000014000392B C3 
INT 3                                                       ;000000014000392C CC 
INT 3                                                       ;000000014000392D CC 
INT 3                                                       ;000000014000392E CC 
INT 3                                                       ;000000014000392F CC 
MOV qword ptr SS : [ RSP +  + 0x08 ], RCX                   ;0000000140003930 48 89 4C 24 08 
SUB RSP, 0x58                                               ;0000000140003935 48 83 EC 58 
MOV RAX, qword ptr SS : [ RSP +  + 0x60 ]                   ;0000000140003939 48 8B 44 24 60 
MOV qword ptr SS : [ RSP +  + 0x38 ], RAX                   ;000000014000393E 48 89 44 24 38 
LEA RAX, CS : [ RIP + 0xFFFFC6B6 ]                          ;0000000140003943 48 8D 05 B6 C6 FF FF 
MOV qword ptr SS : [ RSP +  + 0x28 ], RAX                   ;000000014000394A 48 89 44 24 28 
MOV RCX, qword ptr SS : [ RSP +  + 0x28 ]                   ;000000014000394F 48 8B 4C 24 28 
CALL 0xFFFFFD67                                             ;0000000140003954 E8 67 FD FF FF 
MOVZX EAX, AL                                               ;0000000140003959 0F B6 C0 
TEST EAX, EAX                                               ;000000014000395C 85 C0 
JNZ 0x04                                                    ;000000014000395E 75 04 
XOR AL, AL                                                  ;0000000140003960 32 C0 
JMP 0x52                                                    ;0000000140003962 EB 52 
MOV RAX, qword ptr SS : [ RSP +  + 0x28 ]                   ;0000000140003964 48 8B 44 24 28 
MOV RCX, qword ptr SS : [ RSP +  + 0x38 ]                   ;0000000140003969 48 8B 4C 24 38 
SUB RCX, RAX                                                ;000000014000396E 48 2B C8 
MOV RAX, RCX                                                ;0000000140003971 48 8B C1 
MOV qword ptr SS : [ RSP +  + 0x40 ], RAX                   ;0000000140003974 48 89 44 24 40 
MOV RDX, qword ptr SS : [ RSP +  + 0x40 ]                   ;0000000140003979 48 8B 54 24 40 
MOV RCX, qword ptr SS : [ RSP +  + 0x28 ]                   ;000000014000397E 48 8B 4C 24 28 
CALL 0xFFFFFC68                                             ;0000000140003983 E8 68 FC FF FF 
MOV qword ptr SS : [ RSP +  + 0x30 ], RAX                   ;0000000140003988 48 89 44 24 30 
CMP qword ptr SS : [ RSP +  + 0x30 ], 0x00                  ;000000014000398D 48 83 7C 24 30 00 
JNZ 0x04                                                    ;0000000140003993 75 04 
XOR AL, AL                                                  ;0000000140003995 32 C0 
JMP 0x1D                                                    ;0000000140003997 EB 1D 
MOV RAX, qword ptr SS : [ RSP +  + 0x30 ]                   ;0000000140003999 48 8B 44 24 30 
MOV EAX, dword ptr DS : [ RAX + 0x24 ]                      ;000000014000399E 8B 40 24 
AND EAX, 0x80000000                                         ;00000001400039A1 25 00 00 00 80 
TEST EAX, EAX                                               ;00000001400039A6 85 C0 
JZ 0x04                                                     ;00000001400039A8 74 04 
XOR AL, AL                                                  ;00000001400039AA 32 C0 
JMP 0x08                                                    ;00000001400039AC EB 08 
MOV AL, 0x01                                                ;00000001400039AE B0 01 
JMP 0x04                                                    ;00000001400039B0 EB 04 
XOR AL, AL                                                  ;00000001400039B2 32 C0 
JMP 0x00                                                    ;00000001400039B4 EB 00 
ADD RSP, 0x58                                               ;00000001400039B6 48 83 C4 58 
RETN                                                        ;00000001400039BA C3 
INT 3                                                       ;00000001400039BB CC 
INT 3                                                       ;00000001400039BC CC 
INT 3                                                       ;00000001400039BD CC 
INT 3                                                       ;00000001400039BE CC 
INT 3                                                       ;00000001400039BF CC 
MOV byte ptr SS : [ RSP +  + 0x08 ], CL                     ;00000001400039C0 88 4C 24 08 
SUB RSP, 0x28                                               ;00000001400039C4 48 83 EC 28 
CALL 0x00000B53                                             ;00000001400039C8 E8 53 0B 00 00 
TEST EAX, EAX                                               ;00000001400039CD 85 C0 
JNZ 0x02                                                    ;00000001400039CF 75 02 
JMP 0x17                                                    ;00000001400039D1 EB 17 
MOVZX EAX, byte ptr SS : [ RSP +  + 0x30 ]                  ;00000001400039D3 0F B6 44 24 30 
TEST EAX, EAX                                               ;00000001400039D8 85 C0 
JZ 0x02                                                     ;00000001400039DA 74 02 
JMP 0x0C                                                    ;00000001400039DC EB 0C 
XOR EAX, EAX                                                ;00000001400039DE 33 C0 
LEA RCX, CS : [ RIP + 0x00057691 ]                          ;00000001400039E0 48 8D 0D 91 76 05 00 
XCHG RAX, qword ptr DS : [ RCX ]                            ;00000001400039E7 48 87 01 
ADD RSP, 0x28                                               ;00000001400039EA 48 83 C4 28 
RETN                                                        ;00000001400039EE C3 
INT 3                                                       ;00000001400039EF CC 
MOV byte ptr SS : [ RSP +  + 0x10 ], DL                     ;00000001400039F0 88 54 24 10 
MOV byte ptr SS : [ RSP +  + 0x08 ], CL                     ;00000001400039F4 88 4C 24 08 
SUB RSP, 0x28                                               ;00000001400039F8 48 83 EC 28 
MOVZX EAX, CS : [ RIP + 0x0005767D ]                        ;00000001400039FC 0F B6 05 7D 76 05 00 
TEST EAX, EAX                                               ;0000000140003A03 85 C0 
JZ 0x0D                                                     ;0000000140003A05 74 0D 
MOVZX EAX, byte ptr SS : [ RSP +  + 0x38 ]                  ;0000000140003A07 0F B6 44 24 38 
TEST EAX, EAX                                               ;0000000140003A0C 85 C0 
JZ 0x04                                                     ;0000000140003A0E 74 04 
MOV AL, 0x01                                                ;0000000140003A10 B0 01 
JMP 0x16                                                    ;0000000140003A12 EB 16 
MOVZX ECX, byte ptr SS : [ RSP +  + 0x30 ]                  ;0000000140003A14 0F B6 4C 24 30 
CALL 0x000154B2                                             ;0000000140003A19 E8 B2 54 01 00 
MOVZX ECX, byte ptr SS : [ RSP +  + 0x30 ]                  ;0000000140003A1E 0F B6 4C 24 30 
CALL 0x00000FB8                                             ;0000000140003A23 E8 B8 0F 00 00 
MOV AL, 0x01                                                ;0000000140003A28 B0 01 
ADD RSP, 0x28                                               ;0000000140003A2A 48 83 C4 28 
RETN                                                        ;0000000140003A2E C3 
INT 3                                                       ;0000000140003A2F CC 
MOV qword ptr SS : [ RSP +  + 0x08 ], RCX                   ;0000000140003A30 48 89 4C 24 08 
SUB RSP, 0x48                                               ;0000000140003A35 48 83 EC 48 
MOV RCX, CS : [ RIP + 0x00057648 ]                          ;0000000140003A39 48 8B 0D 48 76 05 00 
CALL 0xFFFFFB0B                                             ;0000000140003A40 E8 0B FB FF FF 
MOV qword ptr SS : [ RSP +  + 0x30 ], RAX                   ;0000000140003A45 48 89 44 24 30 
CMP qword ptr SS : [ RSP +  + 0x30 ], 0xFF                  ;0000000140003A4A 48 83 7C 24 30 FF 
JNZ 0x2C                                                    ;0000000140003A50 75 2C 
MOV RCX, qword ptr SS : [ RSP +  + 0x50 ]                   ;0000000140003A52 48 8B 4C 24 50 
CALL 0x00015084                                             ;0000000140003A57 E8 84 50 01 00 
TEST EAX, EAX                                               ;0000000140003A5C 85 C0 
JNZ 0x0C                                                    ;0000000140003A5E 75 0C 
MOV RAX, qword ptr SS : [ RSP +  + 0x50 ]                   ;0000000140003A60 48 8B 44 24 50 
MOV qword ptr SS : [ RSP +  + 0x20 ], RAX                   ;0000000140003A65 48 89 44 24 20 
JMP 0x09                                                    ;0000000140003A6A EB 09 
MOV qword ptr SS : [ RSP +  + 0x20 ], 0x00000000            ;0000000140003A6C 48 C7 44 24 20 00 00 00 00 
MOV RAX, qword ptr SS : [ RSP +  + 0x20 ]                   ;0000000140003A75 48 8B 44 24 20 
JMP 0x31                                                    ;0000000140003A7A EB 31 
JMP 0x2F                                                    ;0000000140003A7C EB 2F 
MOV RDX, qword ptr SS : [ RSP +  + 0x50 ]                   ;0000000140003A7E 48 8B 54 24 50 
LEA RCX, CS : [ RIP + 0x000575FE ]                          ;0000000140003A83 48 8D 0D FE 75 05 00 
CALL 0x00015131                                             ;0000000140003A8A E8 31 51 01 00 
TEST EAX, EAX                                               ;0000000140003A8F 85 C0 
JNZ 0x0C                                                    ;0000000140003A91 75 0C 
MOV RAX, qword ptr SS : [ RSP +  + 0x50 ]                   ;0000000140003A93 48 8B 44 24 50 
MOV qword ptr SS : [ RSP +  + 0x28 ], RAX                   ;0000000140003A98 48 89 44 24 28 
JMP 0x09                                                    ;0000000140003A9D EB 09 
MOV qword ptr SS : [ RSP +  + 0x28 ], 0x00000000            ;0000000140003A9F 48 C7 44 24 28 00 00 00 00 
MOV RAX, qword ptr SS : [ RSP +  + 0x28 ]                   ;0000000140003AA8 48 8B 44 24 28 
ADD RSP, 0x48                                               ;0000000140003AAD 48 83 C4 48 
RETN                                                        ;0000000140003AB1 C3 
INT 3                                                       ;0000000140003AB2 CC 
INT 3                                                       ;0000000140003AB3 CC 
INT 3                                                       ;0000000140003AB4 CC 
INT 3                                                       ;0000000140003AB5 CC 
INT 3                                                       ;0000000140003AB6 CC 
INT 3                                                       ;0000000140003AB7 CC 
INT 3                                                       ;0000000140003AB8 CC 
INT 3                                                       ;0000000140003AB9 CC 
INT 3                                                       ;0000000140003ABA CC 
INT 3                                                       ;0000000140003ABB CC 
INT 3                                                       ;0000000140003ABC CC 
INT 3                                                       ;0000000140003ABD CC 
INT 3                                                       ;0000000140003ABE CC 
INT 3                                                       ;0000000140003ABF CC 
MOV qword ptr SS : [ RSP +  + 0x08 ], RCX                   ;0000000140003AC0 48 89 4C 24 08 
SUB RSP, 0x38                                               ;0000000140003AC5 48 83 EC 38 
MOV RCX, qword ptr SS : [ RSP +  + 0x40 ]                   ;0000000140003AC9 48 8B 4C 24 40 
CALL 0xFFFFFF5D                                             ;0000000140003ACE E8 5D FF FF FF 
TEST RAX, RAX                                               ;0000000140003AD3 48 85 C0 
JZ 0x0A                                                     ;0000000140003AD6 74 0A 
MOV dword ptr SS : [ RSP +  + 0x20 ], 0x00000000            ;0000000140003AD8 C7 44 24 20 00 00 00 00 
JMP 0x08                                                    ;0000000140003AE0 EB 08 
MOV dword ptr SS : [ RSP +  + 0x20 ], 0xFFFFFFFF            ;0000000140003AE2 C7 44 24 20 FF FF FF FF 
MOV EAX, dword ptr SS : [ RSP +  + 0x20 ]                   ;0000000140003AEA 8B 44 24 20 
ADD RSP, 0x38                                               ;0000000140003AEE 48 83 C4 38 
RETN                                                        ;0000000140003AF2 C3 
INT 3                                                       ;0000000140003AF3 CC 
INT 3                                                       ;0000000140003AF4 CC 
INT 3                                                       ;0000000140003AF5 CC 
INT 3                                                       ;0000000140003AF6 CC 
INT 3                                                       ;0000000140003AF7 CC 
INT 3                                                       ;0000000140003AF8 CC 
INT 3                                                       ;0000000140003AF9 CC 
INT 3                                                       ;0000000140003AFA CC 
INT 3                                                       ;0000000140003AFB CC 
INT 3                                                       ;0000000140003AFC CC 
INT 3                                                       ;0000000140003AFD CC 
INT 3                                                       ;0000000140003AFE CC 
INT 3                                                       ;0000000140003AFF CC 
PUSH RDI                                                    ;0000000140003B00 40 57 
SUB RSP, 0x40                                               ;0000000140003B02 48 83 EC 40 
LEA RAX, invalid ptr SS : [ RSP +  + 0x28 ]                 ;0000000140003B06 48 8D 44 24 28 
MOV RDI, RAX                                                ;0000000140003B0B 48 8B F8 
XOR EAX, EAX                                                ;0000000140003B0E 33 C0 
MOV ECX, 0x00000008                                         ;0000000140003B10 B9 08 00 00 00 
REP STOSB                                                   ;0000000140003B15 F3 AA 
LEA RCX, invalid ptr SS : [ RSP +  + 0x28 ]                 ;0000000140003B17 48 8D 4C 24 28 
CALL CS : [ RIP + 0x00041536 ]                              ;0000000140003B1C FF 15 36 15 04 00 
MOV RAX, qword ptr SS : [ RSP +  + 0x28 ]                   ;0000000140003B22 48 8B 44 24 28 
MOV qword ptr SS : [ RSP +  + 0x20 ], RAX                   ;0000000140003B27 48 89 44 24 20 
CALL CS : [ RIP + 0x0004151E ]                              ;0000000140003B2C FF 15 1E 15 04 00 
MOV EAX, EAX                                                ;0000000140003B32 8B C0 
MOV RCX, qword ptr SS : [ RSP +  + 0x20 ]                   ;0000000140003B34 48 8B 4C 24 20 
XOR RCX, RAX                                                ;0000000140003B39 48 33 C8 
MOV RAX, RCX                                                ;0000000140003B3C 48 8B C1 
MOV qword ptr SS : [ RSP +  + 0x20 ], RAX                   ;0000000140003B3F 48 89 44 24 20 
CALL CS : [ RIP + 0x000414FE ]                              ;0000000140003B44 FF 15 FE 14 04 00 
MOV EAX, EAX                                                ;0000000140003B4A 8B C0 
MOV RCX, qword ptr SS : [ RSP +  + 0x20 ]                   ;0000000140003B4C 48 8B 4C 24 20 
XOR RCX, RAX                                                ;0000000140003B51 48 33 C8 
MOV RAX, RCX                                                ;0000000140003B54 48 8B C1 
MOV qword ptr SS : [ RSP +  + 0x20 ], RAX                   ;0000000140003B57 48 89 44 24 20 
LEA RCX, invalid ptr SS : [ RSP +  + 0x30 ]                 ;0000000140003B5C 48 8D 4C 24 30 
CALL CS : [ RIP + 0x000414D9 ]                              ;0000000140003B61 FF 15 D9 14 04 00 
MOV EAX, dword ptr SS : [ RSP +  + 0x30 ]                   ;0000000140003B67 8B 44 24 30 
SAL RAX, 0x20                                               ;0000000140003B6B 48 C1 E0 20 
XOR RAX, qword ptr SS : [ RSP +  + 0x30 ]                   ;0000000140003B6F 48 33 44 24 30 
MOV RCX, qword ptr SS : [ RSP +  + 0x20 ]                   ;0000000140003B74 48 8B 4C 24 20 
XOR RCX, RAX                                                ;0000000140003B79 48 33 C8 
MOV RAX, RCX                                                ;0000000140003B7C 48 8B C1 
MOV qword ptr SS : [ RSP +  + 0x20 ], RAX                   ;0000000140003B7F 48 89 44 24 20 
LEA RAX, invalid ptr SS : [ RSP +  + 0x20 ]                 ;0000000140003B84 48 8D 44 24 20 
MOV RCX, qword ptr SS : [ RSP +  + 0x20 ]                   ;0000000140003B89 48 8B 4C 24 20 
XOR RCX, RAX                                                ;0000000140003B8E 48 33 C8 
MOV RAX, RCX                                                ;0000000140003B91 48 8B C1 
MOV qword ptr SS : [ RSP +  + 0x20 ], RAX                   ;0000000140003B94 48 89 44 24 20 
MOV RAX, 0x0000FFFFFFFFFFFF                                 ;0000000140003B99 48 B8 FF FF FF FF FF FF 00 00 
MOV RCX, qword ptr SS : [ RSP +  + 0x20 ]                   ;0000000140003BA3 48 8B 4C 24 20 
AND RCX, RAX                                                ;0000000140003BA8 48 23 C8 
MOV RAX, RCX                                                ;0000000140003BAB 48 8B C1 
MOV qword ptr SS : [ RSP +  + 0x20 ], RAX                   ;0000000140003BAE 48 89 44 24 20 
MOV RAX, qword ptr SS : [ RSP +  + 0x20 ]                   ;0000000140003BB3 48 8B 44 24 20 
ADD RSP, 0x40                                               ;0000000140003BB8 48 83 C4 40 
POP EDI                                                     ;0000000140003BBC 5F 
RETN                                                        ;0000000140003BBD C3 
INT 3                                                       ;0000000140003BBE CC 
INT 3                                                       ;0000000140003BBF CC 
SUB RSP, 0x38                                               ;0000000140003BC0 48 83 EC 38 
MOV RAX, 0x00002B992DDFA232                                 ;0000000140003BC4 48 B8 32 A2 DF 2D 99 2B 00 00 
CMP CS : [ RIP + 0x00056433 ], RAX                          ;0000000140003BCE 48 39 05 33 64 05 00 
JZ 0x13                                                     ;0000000140003BD5 74 13 
MOV RAX, CS : [ RIP + 0x0005642A ]                          ;0000000140003BD7 48 8B 05 2A 64 05 00 
NOT RAX                                                     ;0000000140003BDE 48 F7 D0 
MOV CS : [ RIP + 0x00056418 ], RAX                          ;0000000140003BE1 48 89 05 18 64 05 00 
JMP 0x45                                                    ;0000000140003BE8 EB 45 
CALL 0xFFFFFF11                                             ;0000000140003BEA E8 11 FF FF FF 
MOV qword ptr SS : [ RSP +  + 0x20 ], RAX                   ;0000000140003BEF 48 89 44 24 20 
MOV RAX, 0x00002B992DDFA232                                 ;0000000140003BF4 48 B8 32 A2 DF 2D 99 2B 00 00 
CMP qword ptr SS : [ RSP +  + 0x20 ], RAX                   ;0000000140003BFE 48 39 44 24 20 
JNZ 0x0F                                                    ;0000000140003C03 75 0F 
MOV RAX, 0x00002B992DDFA233                                 ;0000000140003C05 48 B8 33 A2 DF 2D 99 2B 00 00 
MOV qword ptr SS : [ RSP +  + 0x20 ], RAX                   ;0000000140003C0F 48 89 44 24 20 
MOV RAX, qword ptr SS : [ RSP +  + 0x20 ]                   ;0000000140003C14 48 8B 44 24 20 
MOV CS : [ RIP + 0x000563E8 ], RAX                          ;0000000140003C19 48 89 05 E8 63 05 00 
MOV RAX, qword ptr SS : [ RSP +  + 0x20 ]                   ;0000000140003C20 48 8B 44 24 20 
NOT RAX                                                     ;0000000140003C25 48 F7 D0 
MOV CS : [ RIP + 0x000563D1 ], RAX                          ;0000000140003C28 48 89 05 D1 63 05 00 
ADD RSP, 0x38                                               ;0000000140003C2F 48 83 C4 38 
RETN                                                        ;0000000140003C33 C3 
INT 3                                                       ;0000000140003C34 CC 
INT 3                                                       ;0000000140003C35 CC 
INT 3                                                       ;0000000140003C36 CC 
INT 3                                                       ;0000000140003C37 CC 
INT 3                                                       ;0000000140003C38 CC 
INT 3                                                       ;0000000140003C39 CC 
INT 3                                                       ;0000000140003C3A CC 
INT 3                                                       ;0000000140003C3B CC 
INT 3                                                       ;0000000140003C3C CC 
INT 3                                                       ;0000000140003C3D CC 
INT 3                                                       ;0000000140003C3E CC 
INT 3                                                       ;0000000140003C3F CC 
MOV qword ptr SS : [ RSP +  + 0x08 ], RCX                   ;0000000140003C40 48 89 4C 24 08 
XOR EAX, EAX                                                ;0000000140003C45 33 C0 
RETN                                                        ;0000000140003C47 C3 
INT 3                                                       ;0000000140003C48 CC 
INT 3                                                       ;0000000140003C49 CC 
INT 3                                                       ;0000000140003C4A CC 
INT 3                                                       ;0000000140003C4B CC 
INT 3                                                       ;0000000140003C4C CC 
INT 3                                                       ;0000000140003C4D CC 
INT 3                                                       ;0000000140003C4E CC 
INT 3                                                       ;0000000140003C4F CC 
MOV EAX, 0x00000001                                         ;0000000140003C50 B8 01 00 00 00 
RETN                                                        ;0000000140003C55 C3 
INT 3                                                       ;0000000140003C56 CC 
INT 3                                                       ;0000000140003C57 CC 
INT 3                                                       ;0000000140003C58 CC 
INT 3                                                       ;0000000140003C59 CC 
INT 3                                                       ;0000000140003C5A CC 
INT 3                                                       ;0000000140003C5B CC 
INT 3                                                       ;0000000140003C5C CC 
INT 3                                                       ;0000000140003C5D CC 
INT 3                                                       ;0000000140003C5E CC 
INT 3                                                       ;0000000140003C5F CC 
XOR EAX, EAX                                                ;0000000140003C60 33 C0 
RETN                                                        ;0000000140003C62 C3 
INT 3                                                       ;0000000140003C63 CC 
INT 3                                                       ;0000000140003C64 CC 
INT 3                                                       ;0000000140003C65 CC 
INT 3                                                       ;0000000140003C66 CC 
INT 3                                                       ;0000000140003C67 CC 
INT 3                                                       ;0000000140003C68 CC 
INT 3                                                       ;0000000140003C69 CC 
INT 3                                                       ;0000000140003C6A CC 
INT 3                                                       ;0000000140003C6B CC 
INT 3                                                       ;0000000140003C6C CC 
INT 3                                                       ;0000000140003C6D CC 
INT 3                                                       ;0000000140003C6E CC 
INT 3                                                       ;0000000140003C6F CC 
MOV EAX, 0x00004000                                         ;0000000140003C70 B8 00 40 00 00 
RETN                                                        ;0000000140003C75 C3 
INT 3                                                       ;0000000140003C76 CC 
INT 3                                                       ;0000000140003C77 CC 
INT 3                                                       ;0000000140003C78 CC 
INT 3                                                       ;0000000140003C79 CC 
INT 3                                                       ;0000000140003C7A CC 
INT 3                                                       ;0000000140003C7B CC 
INT 3                                                       ;0000000140003C7C CC 
INT 3                                                       ;0000000140003C7D CC 
INT 3                                                       ;0000000140003C7E CC 
INT 3                                                       ;0000000140003C7F CC 
SUB RSP, 0x28                                               ;0000000140003C80 48 83 EC 28 
LEA RCX, CS : [ RIP + 0x00057435 ]                          ;0000000140003C84 48 8D 0D 35 74 05 00 
CALL CS : [ RIP + 0x000413CF ]                              ;0000000140003C8B FF 15 CF 13 04 00 
ADD RSP, 0x28                                               ;0000000140003C91 48 83 C4 28 
RETN                                                        ;0000000140003C95 C3 
INT 3                                                       ;0000000140003C96 CC 
INT 3                                                       ;0000000140003C97 CC 
INT 3                                                       ;0000000140003C98 CC 
INT 3                                                       ;0000000140003C99 CC 
INT 3                                                       ;0000000140003C9A CC 
INT 3                                                       ;0000000140003C9B CC 
INT 3                                                       ;0000000140003C9C CC 
INT 3                                                       ;0000000140003C9D CC 
INT 3                                                       ;0000000140003C9E CC 
INT 3                                                       ;0000000140003C9F CC 
MOV AL, 0x01                                                ;0000000140003CA0 B0 01 
RETN                                                        ;0000000140003CA2 C3 
INT 3                                                       ;0000000140003CA3 CC 
INT 3                                                       ;0000000140003CA4 CC 
INT 3                                                       ;0000000140003CA5 CC 
INT 3                                                       ;0000000140003CA6 CC 
INT 3                                                       ;0000000140003CA7 CC 
INT 3                                                       ;0000000140003CA8 CC 
INT 3                                                       ;0000000140003CA9 CC 
INT 3                                                       ;0000000140003CAA CC 
INT 3                                                       ;0000000140003CAB CC 
INT 3                                                       ;0000000140003CAC CC 
INT 3                                                       ;0000000140003CAD CC 
INT 3                                                       ;0000000140003CAE CC 
INT 3                                                       ;0000000140003CAF CC 
RETN 0x0000                                                 ;0000000140003CB0 C2 00 00 
INT 3                                                       ;0000000140003CB3 CC 
INT 3                                                       ;0000000140003CB4 CC 
INT 3                                                       ;0000000140003CB5 CC 
INT 3                                                       ;0000000140003CB6 CC 
INT 3                                                       ;0000000140003CB7 CC 
INT 3                                                       ;0000000140003CB8 CC 
INT 3                                                       ;0000000140003CB9 CC 
INT 3                                                       ;0000000140003CBA CC 
INT 3                                                       ;0000000140003CBB CC 
INT 3                                                       ;0000000140003CBC CC 
INT 3                                                       ;0000000140003CBD CC 
INT 3                                                       ;0000000140003CBE CC 
INT 3                                                       ;0000000140003CBF CC 
LEA RAX, CS : [ RIP + 0x00057409 ]                          ;0000000140003CC0 48 8D 05 09 74 05 00 
RETN                                                        ;0000000140003CC7 C3 
INT 3                                                       ;0000000140003CC8 CC 
INT 3                                                       ;0000000140003CC9 CC 
INT 3                                                       ;0000000140003CCA CC 
INT 3                                                       ;0000000140003CCB CC 
INT 3                                                       ;0000000140003CCC CC 
INT 3                                                       ;0000000140003CCD CC 
INT 3                                                       ;0000000140003CCE CC 
INT 3                                                       ;0000000140003CCF CC 
SUB RSP, 0x38                                               ;0000000140003CD0 48 83 EC 38 
CALL 0xFFFFEF67                                             ;0000000140003CD4 E8 67 EF FF FF 
MOV qword ptr SS : [ RSP +  + 0x20 ], RAX                   ;0000000140003CD9 48 89 44 24 20 
MOV RAX, qword ptr SS : [ RSP +  + 0x20 ]                   ;0000000140003CDE 48 8B 44 24 20 
MOV RAX, qword ptr DS : [ RAX ]                             ;0000000140003CE3 48 8B 00 
OR RAX, 0x04                                                ;0000000140003CE6 48 83 C8 04 
MOV RCX, qword ptr SS : [ RSP +  + 0x20 ]                   ;0000000140003CEA 48 8B 4C 24 20 
MOV qword ptr DS : [ RCX ], RAX                             ;0000000140003CEF 48 89 01 
CALL 0xFFFFFFC9                                             ;0000000140003CF2 E8 C9 FF FF FF 
MOV qword ptr SS : [ RSP +  + 0x28 ], RAX                   ;0000000140003CF7 48 89 44 24 28 
MOV RAX, qword ptr SS : [ RSP +  + 0x28 ]                   ;0000000140003CFC 48 8B 44 24 28 
MOV RAX, qword ptr DS : [ RAX ]                             ;0000000140003D01 48 8B 00 
OR RAX, 0x02                                                ;0000000140003D04 48 83 C8 02 
MOV RCX, qword ptr SS : [ RSP +  + 0x28 ]                   ;0000000140003D08 48 8B 4C 24 28 
MOV qword ptr DS : [ RCX ], RAX                             ;0000000140003D0D 48 89 01 
ADD RSP, 0x38                                               ;0000000140003D10 48 83 C4 38 
RETN                                                        ;0000000140003D14 C3 
INT 3                                                       ;0000000140003D15 CC 
INT 3                                                       ;0000000140003D16 CC 
INT 3                                                       ;0000000140003D17 CC 
INT 3                                                       ;0000000140003D18 CC 
INT 3                                                       ;0000000140003D19 CC 
INT 3                                                       ;0000000140003D1A CC 
INT 3                                                       ;0000000140003D1B CC 
INT 3                                                       ;0000000140003D1C CC 
INT 3                                                       ;0000000140003D1D CC 
INT 3                                                       ;0000000140003D1E CC 
INT 3                                                       ;0000000140003D1F CC 
SUB RSP, 0x18                                               ;0000000140003D20 48 83 EC 18 
CMP CS : [ RIP + 0x000562ED ], 0x00                         ;0000000140003D24 83 3D ED 62 05 00 00 
JNZ 0x09                                                    ;0000000140003D2B 75 09 
MOV dword ptr SS : [ RSP +  ], 0x00000001                   ;0000000140003D2D C7 04 24 01 00 00 00 
JMP 0x07                                                    ;0000000140003D34 EB 07 
MOV dword ptr SS : [ RSP +  ], 0x00000000                   ;0000000140003D36 C7 04 24 00 00 00 00 
MOV EAX, dword ptr SS : [ RSP +  ]                          ;0000000140003D3D 8B 04 24 
ADD RSP, 0x18                                               ;0000000140003D40 48 83 C4 18 
RETN                                                        ;0000000140003D44 C3 
INT 3                                                       ;0000000140003D45 CC 
INT 3                                                       ;0000000140003D46 CC 
INT 3                                                       ;0000000140003D47 CC 
INT 3                                                       ;0000000140003D48 CC 
INT 3                                                       ;0000000140003D49 CC 
INT 3                                                       ;0000000140003D4A CC 
INT 3                                                       ;0000000140003D4B CC 
INT 3                                                       ;0000000140003D4C CC 
INT 3                                                       ;0000000140003D4D CC 
INT 3                                                       ;0000000140003D4E CC 
INT 3                                                       ;0000000140003D4F CC 
LEA RAX, CS : [ RIP + 0x00058629 ]                          ;0000000140003D50 48 8D 05 29 86 05 00 
RETN                                                        ;0000000140003D57 C3 
INT 3                                                       ;0000000140003D58 CC 
INT 3                                                       ;0000000140003D59 CC 
INT 3                                                       ;0000000140003D5A CC 
INT 3                                                       ;0000000140003D5B CC 
INT 3                                                       ;0000000140003D5C CC 
INT 3                                                       ;0000000140003D5D CC 
INT 3                                                       ;0000000140003D5E CC 
INT 3                                                       ;0000000140003D5F CC 
LEA RAX, CS : [ RIP + 0x00058611 ]                          ;0000000140003D60 48 8D 05 11 86 05 00 
RETN                                                        ;0000000140003D67 C3 
INT 3                                                       ;0000000140003D68 CC 
INT 3                                                       ;0000000140003D69 CC 
INT 3                                                       ;0000000140003D6A CC 
INT 3                                                       ;0000000140003D6B CC 
INT 3                                                       ;0000000140003D6C CC 
INT 3                                                       ;0000000140003D6D CC 
INT 3                                                       ;0000000140003D6E CC 
INT 3                                                       ;0000000140003D6F CC 
MOV dword ptr SS : [ RSP +  + 0x08 ], ECX                   ;0000000140003D70 89 4C 24 08 
MOV CS : [ RIP + 0x0005735A ], 0x00000000                   ;0000000140003D74 C7 05 5A 73 05 00 00 00 00 00 
RETN                                                        ;0000000140003D7E C3 
INT 3                                                       ;0000000140003D7F CC 
MOV dword ptr SS : [ RSP +  + 0x08 ], ECX                   ;0000000140003D80 89 4C 24 08 
PUSH EDI                                                    ;0000000140003D84 57 
SUB RSP, 0x000005F0                                         ;0000000140003D85 48 81 EC F0 05 00 00 
MOV ECX, 0x00000017                                         ;0000000140003D8C B9 17 00 00 00 
CALL 0x000007BA                                             ;0000000140003D91 E8 BA 07 00 00 
TEST EAX, EAX                                               ;0000000140003D96 85 C0 
JZ 0x0B                                                     ;0000000140003D98 74 0B 
MOV EAX, dword ptr SS : [ RSP +  + 0x00000600 ]             ;0000000140003D9A 8B 84 24 00 06 00 00 
MOV ECX, EAX                                                ;0000000140003DA1 8B C8 
INT 0x29                                                    ;0000000140003DA3 CD 29 
MOV ECX, 0x00000003                                         ;0000000140003DA5 B9 03 00 00 00 
CALL 0xFFFFFFC1                                             ;0000000140003DAA E8 C1 FF FF FF 
LEA RAX, invalid ptr SS : [ RSP +  + 0x00000120 ]           ;0000000140003DAF 48 8D 84 24 20 01 00 00 
MOV RDI, RAX                                                ;0000000140003DB7 48 8B F8 
XOR EAX, EAX                                                ;0000000140003DBA 33 C0 
MOV ECX, 0x000004D0                                         ;0000000140003DBC B9 D0 04 00 00 
REP STOSB                                                   ;0000000140003DC1 F3 AA 
LEA RCX, invalid ptr SS : [ RSP +  + 0x00000120 ]           ;0000000140003DC3 48 8D 8C 24 20 01 00 00 
CALL CS : [ RIP + 0x0004122F ]                              ;0000000140003DCB FF 15 2F 12 04 00 
MOV RAX, qword ptr SS : [ RSP +  + 0x00000218 ]             ;0000000140003DD1 48 8B 84 24 18 02 00 00 
MOV qword ptr SS : [ RSP +  + 0x50 ], RAX                   ;0000000140003DD9 48 89 44 24 50 
XOR R8D, R8D                                                ;0000000140003DDE 45 33 C0 
LEA RDX, invalid ptr SS : [ RSP +  + 0x58 ]                 ;0000000140003DE1 48 8D 54 24 58 
MOV RCX, qword ptr SS : [ RSP +  + 0x50 ]                   ;0000000140003DE6 48 8B 4C 24 50 
CALL CS : [ RIP + 0x00041217 ]                              ;0000000140003DEB FF 15 17 12 04 00 
MOV qword ptr SS : [ RSP +  + 0x48 ], RAX                   ;0000000140003DF1 48 89 44 24 48 
CMP qword ptr SS : [ RSP +  + 0x48 ], 0x00                  ;0000000140003DF6 48 83 7C 24 48 00 
JZ 0x41                                                     ;0000000140003DFC 74 41 
MOV qword ptr SS : [ RSP +  + 0x38 ], 0x00000000            ;0000000140003DFE 48 C7 44 24 38 00 00 00 00 
LEA RAX, invalid ptr SS : [ RSP +  + 0x70 ]                 ;0000000140003E07 48 8D 44 24 70 
MOV qword ptr SS : [ RSP +  + 0x30 ], RAX                   ;0000000140003E0C 48 89 44 24 30 
LEA RAX, invalid ptr SS : [ RSP +  + 0x78 ]                 ;0000000140003E11 48 8D 44 24 78 
MOV qword ptr SS : [ RSP +  + 0x28 ], RAX                   ;0000000140003E16 48 89 44 24 28 
LEA RAX, invalid ptr SS : [ RSP +  + 0x00000120 ]           ;0000000140003E1B 48 8D 84 24 20 01 00 00 
MOV qword ptr SS : [ RSP +  + 0x20 ], RAX                   ;0000000140003E23 48 89 44 24 20 
MOV R9, qword ptr SS : [ RSP +  + 0x48 ]                    ;0000000140003E28 4C 8B 4C 24 48 
MOV R8, qword ptr SS : [ RSP +  + 0x50 ]                    ;0000000140003E2D 4C 8B 44 24 50 
MOV RDX, qword ptr SS : [ RSP +  + 0x58 ]                   ;0000000140003E32 48 8B 54 24 58 
XOR ECX, ECX                                                ;0000000140003E37 33 C9 
CALL CS : [ RIP + 0x000411D1 ]                              ;0000000140003E39 FF 15 D1 11 04 00 
MOV RAX, qword ptr SS : [ RSP +  + 0x000005F8 ]             ;0000000140003E3F 48 8B 84 24 F8 05 00 00 
MOV qword ptr SS : [ RSP +  + 0x00000218 ], RAX             ;0000000140003E47 48 89 84 24 18 02 00 00 
LEA RAX, invalid ptr SS : [ RSP +  + 0x000005F8 ]           ;0000000140003E4F 48 8D 84 24 F8 05 00 00 
ADD RAX, 0x08                                               ;0000000140003E57 48 83 C0 08 
MOV qword ptr SS : [ RSP +  + 0x000001B8 ], RAX             ;0000000140003E5B 48 89 84 24 B8 01 00 00 
LEA RAX, invalid ptr SS : [ RSP +  + 0x00000080 ]           ;0000000140003E63 48 8D 84 24 80 00 00 00 
MOV RDI, RAX                                                ;0000000140003E6B 48 8B F8 
XOR EAX, EAX                                                ;0000000140003E6E 33 C0 
MOV ECX, 0x00000098                                         ;0000000140003E70 B9 98 00 00 00 
REP STOSB                                                   ;0000000140003E75 F3 AA 
MOV dword ptr SS : [ RSP +  + 0x00000080 ], 0x40000015      ;0000000140003E77 C7 84 24 80 00 00 00 15 00 00 40 
MOV dword ptr SS : [ RSP +  + 0x00000084 ], 0x00000001      ;0000000140003E82 C7 84 24 84 00 00 00 01 00 00 00 
MOV RAX, qword ptr SS : [ RSP +  + 0x000005F8 ]             ;0000000140003E8D 48 8B 84 24 F8 05 00 00 
MOV qword ptr SS : [ RSP +  + 0x00000090 ], RAX             ;0000000140003E95 48 89 84 24 90 00 00 00 
CALL CS : [ RIP + 0x000411C5 ]                              ;0000000140003E9D FF 15 C5 11 04 00 
CMP EAX, 0x01                                               ;0000000140003EA3 83 F8 01 
JNZ 0x07                                                    ;0000000140003EA6 75 07 
MOV byte ptr SS : [ RSP +  + 0x40 ], 0x01                   ;0000000140003EA8 C6 44 24 40 01 
JMP 0x05                                                    ;0000000140003EAD EB 05 
MOV byte ptr SS : [ RSP +  + 0x40 ], 0x00                   ;0000000140003EAF C6 44 24 40 00 
MOVZX EAX, byte ptr SS : [ RSP +  + 0x40 ]                  ;0000000140003EB4 0F B6 44 24 40 
MOV byte ptr SS : [ RSP +  + 0x41 ], AL                     ;0000000140003EB9 88 44 24 41 
LEA RAX, invalid ptr SS : [ RSP +  + 0x00000080 ]           ;0000000140003EBD 48 8D 84 24 80 00 00 00 
MOV qword ptr SS : [ RSP +  + 0x60 ], RAX                   ;0000000140003EC5 48 89 44 24 60 
LEA RAX, invalid ptr SS : [ RSP +  + 0x00000120 ]           ;0000000140003ECA 48 8D 84 24 20 01 00 00 
MOV qword ptr SS : [ RSP +  + 0x68 ], RAX                   ;0000000140003ED2 48 89 44 24 68 
XOR ECX, ECX                                                ;0000000140003ED7 33 C9 
CALL CS : [ RIP + 0x00041141 ]                              ;0000000140003ED9 FF 15 41 11 04 00 
LEA RCX, invalid ptr SS : [ RSP +  + 0x60 ]                 ;0000000140003EDF 48 8D 4C 24 60 
CALL CS : [ RIP + 0x0004112E ]                              ;0000000140003EE4 FF 15 2E 11 04 00 
MOV dword ptr SS : [ RSP +  + 0x44 ], EAX                   ;0000000140003EEA 89 44 24 44 
CMP dword ptr SS : [ RSP +  + 0x44 ], 0x00                  ;0000000140003EEE 83 7C 24 44 00 
JNZ 0x13                                                    ;0000000140003EF3 75 13 
MOVZX EAX, byte ptr SS : [ RSP +  + 0x41 ]                  ;0000000140003EF5 0F B6 44 24 41 
TEST EAX, EAX                                               ;0000000140003EFA 85 C0 
JNZ 0x0A                                                    ;0000000140003EFC 75 0A 
MOV ECX, 0x00000003                                         ;0000000140003EFE B9 03 00 00 00 
CALL 0xFFFFFE68                                             ;0000000140003F03 E8 68 FE FF FF 
ADD RSP, 0x000005F0                                         ;0000000140003F08 48 81 C4 F0 05 00 00 
POP EDI                                                     ;0000000140003F0F 5F 
RETN                                                        ;0000000140003F10 C3 
INT 3                                                       ;0000000140003F11 CC 
INT 3                                                       ;0000000140003F12 CC 
INT 3                                                       ;0000000140003F13 CC 
INT 3                                                       ;0000000140003F14 CC 
INT 3                                                       ;0000000140003F15 CC 
INT 3                                                       ;0000000140003F16 CC 
INT 3                                                       ;0000000140003F17 CC 
INT 3                                                       ;0000000140003F18 CC 
INT 3                                                       ;0000000140003F19 CC 
INT 3                                                       ;0000000140003F1A CC 
INT 3                                                       ;0000000140003F1B CC 
INT 3                                                       ;0000000140003F1C CC 
INT 3                                                       ;0000000140003F1D CC 
INT 3                                                       ;0000000140003F1E CC 
INT 3                                                       ;0000000140003F1F CC 
SUB RSP, 0x28                                               ;0000000140003F20 48 83 EC 28 
CALL 0xFFFFFD37                                             ;0000000140003F24 E8 37 FD FF FF 
ADD RSP, 0x28                                               ;0000000140003F29 48 83 C4 28 
RETN                                                        ;0000000140003F2D C3 
INT 3                                                       ;0000000140003F2E CC 
INT 3                                                       ;0000000140003F2F CC 
SUB RSP, 0x38                                               ;0000000140003F30 48 83 EC 38 
XOR ECX, ECX                                                ;0000000140003F34 33 C9 
CALL CS : [ RIP + 0x0004113C ]                              ;0000000140003F36 FF 15 3C 11 04 00 
MOV qword ptr SS : [ RSP +  + 0x20 ], RAX                   ;0000000140003F3C 48 89 44 24 20 
CMP qword ptr SS : [ RSP +  + 0x20 ], 0x00                  ;0000000140003F41 48 83 7C 24 20 00 
JNZ 0x07                                                    ;0000000140003F47 75 07 
XOR AL, AL                                                  ;0000000140003F49 32 C0 
JMP 0x00000081                                              ;0000000140003F4B E9 81 00 00 00 
MOV RAX, qword ptr SS : [ RSP +  + 0x20 ]                   ;0000000140003F50 48 8B 44 24 20 
MOVZX EAX, word ptr DS : [ RAX ]                            ;0000000140003F55 0F B7 00 
CMP EAX, 0x00005A4D                                         ;0000000140003F58 3D 4D 5A 00 00 
JZ 0x04                                                     ;0000000140003F5D 74 04 
XOR AL, AL                                                  ;0000000140003F5F 32 C0 
JMP 0x6E                                                    ;0000000140003F61 EB 6E 
MOV RAX, qword ptr SS : [ RSP +  + 0x20 ]                   ;0000000140003F63 48 8B 44 24 20 
MOVSXD RAX, dword ptr DS : [ RAX + 0x3C ]                   ;0000000140003F68 48 63 40 3C 
MOV RCX, qword ptr SS : [ RSP +  + 0x20 ]                   ;0000000140003F6C 48 8B 4C 24 20 
ADD RCX, RAX                                                ;0000000140003F71 48 03 C8 
MOV RAX, RCX                                                ;0000000140003F74 48 8B C1 
MOV qword ptr SS : [ RSP +  + 0x28 ], RAX                   ;0000000140003F77 48 89 44 24 28 
MOV RAX, qword ptr SS : [ RSP +  + 0x28 ]                   ;0000000140003F7C 48 8B 44 24 28 
CMP dword ptr DS : [ RAX ], 0x00004550                      ;0000000140003F81 81 38 50 45 00 00 
JZ 0x04                                                     ;0000000140003F87 74 04 
XOR AL, AL                                                  ;0000000140003F89 32 C0 
JMP 0x44                                                    ;0000000140003F8B EB 44 
MOV RAX, qword ptr SS : [ RSP +  + 0x28 ]                   ;0000000140003F8D 48 8B 44 24 28 
MOVZX EAX, word ptr DS : [ RAX + 0x18 ]                     ;0000000140003F92 0F B7 40 18 
CMP EAX, 0x0000020B                                         ;0000000140003F96 3D 0B 02 00 00 
JZ 0x04                                                     ;0000000140003F9B 74 04 
XOR AL, AL                                                  ;0000000140003F9D 32 C0 
JMP 0x30                                                    ;0000000140003F9F EB 30 
MOV RAX, qword ptr SS : [ RSP +  + 0x28 ]                   ;0000000140003FA1 48 8B 44 24 28 
CMP dword ptr DS : [ RAX + 0x00000084 ], 0x0E               ;0000000140003FA6 83 B8 84 00 00 00 0E 
JA 0x04                                                     ;0000000140003FAD 77 04 
XOR AL, AL                                                  ;0000000140003FAF 32 C0 
JMP 0x1E                                                    ;0000000140003FB1 EB 1E 
MOV EAX, 0x00000008                                         ;0000000140003FB3 B8 08 00 00 00 
IMUL RAX, RAX, 0x0E                                         ;0000000140003FB8 48 6B C0 0E 
MOV RCX, qword ptr SS : [ RSP +  + 0x28 ]                   ;0000000140003FBC 48 8B 4C 24 28 
CMP dword ptr DS : [ RCX + RAX * 1 + 0x00000088 ], 0x00     ;0000000140003FC1 83 BC 01 88 00 00 00 00 
JNZ 0x04                                                    ;0000000140003FC9 75 04 
XOR AL, AL                                                  ;0000000140003FCB 32 C0 
JMP 0x02                                                    ;0000000140003FCD EB 02 
MOV AL, 0x01                                                ;0000000140003FCF B0 01 
ADD RSP, 0x38                                               ;0000000140003FD1 48 83 C4 38 
RETN                                                        ;0000000140003FD5 C3 
INT 3                                                       ;0000000140003FD6 CC 
INT 3                                                       ;0000000140003FD7 CC 
INT 3                                                       ;0000000140003FD8 CC 
INT 3                                                       ;0000000140003FD9 CC 
INT 3                                                       ;0000000140003FDA CC 
INT 3                                                       ;0000000140003FDB CC 
INT 3                                                       ;0000000140003FDC CC 
INT 3                                                       ;0000000140003FDD CC 
INT 3                                                       ;0000000140003FDE CC 
INT 3                                                       ;0000000140003FDF CC 
SUB RSP, 0x28                                               ;0000000140003FE0 48 83 EC 28 
LEA RCX, CS : [ RIP + 0x00000015 ]                          ;0000000140003FE4 48 8D 0D 15 00 00 00 
CALL CS : [ RIP + 0x0004102F ]                              ;0000000140003FEB FF 15 2F 10 04 00 
ADD RSP, 0x28                                               ;0000000140003FF1 48 83 C4 28 
RETN                                                        ;0000000140003FF5 C3 
INT 3                                                       ;0000000140003FF6 CC 
INT 3                                                       ;0000000140003FF7 CC 
INT 3                                                       ;0000000140003FF8 CC 
INT 3                                                       ;0000000140003FF9 CC 
INT 3                                                       ;0000000140003FFA CC 
INT 3                                                       ;0000000140003FFB CC 
INT 3                                                       ;0000000140003FFC CC 
INT 3                                                       ;0000000140003FFD CC 
INT 3                                                       ;0000000140003FFE CC 
INT 3                                                       ;0000000140003FFF CC 
MOV qword ptr SS : [ RSP +  + 0x08 ], RCX                   ;0000000140004000 48 89 4C 24 08 
SUB RSP, 0x38                                               ;0000000140004005 48 83 EC 38 
MOV RAX, qword ptr SS : [ RSP +  + 0x40 ]                   ;0000000140004009 48 8B 44 24 40 
MOV RAX, qword ptr DS : [ RAX ]                             ;000000014000400E 48 8B 00 
MOV qword ptr SS : [ RSP +  + 0x20 ], RAX                   ;0000000140004011 48 89 44 24 20 
MOV RAX, qword ptr SS : [ RSP +  + 0x20 ]                   ;0000000140004016 48 8B 44 24 20 
CMP dword ptr DS : [ RAX ], 0xE06D7363                      ;000000014000401B 81 38 63 73 6D E0 
JNZ 0x48                                                    ;0000000140004021 75 48 
MOV RAX, qword ptr SS : [ RSP +  + 0x20 ]                   ;0000000140004023 48 8B 44 24 20 
CMP dword ptr DS : [ RAX + 0x18 ], 0x04                     ;0000000140004028 83 78 18 04 
JNZ 0x3D                                                    ;000000014000402C 75 3D 
MOV RAX, qword ptr SS : [ RSP +  + 0x20 ]                   ;000000014000402E 48 8B 44 24 20 
CMP dword ptr DS : [ RAX + 0x20 ], 0x19930520               ;0000000140004033 81 78 20 20 05 93 19 
JZ 0x2A                                                     ;000000014000403A 74 2A 
MOV RAX, qword ptr SS : [ RSP +  + 0x20 ]                   ;000000014000403C 48 8B 44 24 20 
CMP dword ptr DS : [ RAX + 0x20 ], 0x19930521               ;0000000140004041 81 78 20 21 05 93 19 
JZ 0x1C                                                     ;0000000140004048 74 1C 
MOV RAX, qword ptr SS : [ RSP +  + 0x20 ]                   ;000000014000404A 48 8B 44 24 20 
CMP dword ptr DS : [ RAX + 0x20 ], 0x19930522               ;000000014000404F 81 78 20 22 05 93 19 
JZ 0x0E                                                     ;0000000140004056 74 0E 
MOV RAX, qword ptr SS : [ RSP +  + 0x20 ]                   ;0000000140004058 48 8B 44 24 20 
CMP dword ptr DS : [ RAX + 0x20 ], 0x01994000               ;000000014000405D 81 78 20 00 40 99 01 
JNZ 0x05                                                    ;0000000140004064 75 05 
CALL 0x00014E95                                             ;0000000140004066 E8 95 4E 01 00 
XOR EAX, EAX                                                ;000000014000406B 33 C0 
ADD RSP, 0x38                                               ;000000014000406D 48 83 C4 38 
RETN                                                        ;0000000140004071 C3 
INT 3                                                       ;0000000140004072 CC 
INT 3                                                       ;0000000140004073 CC 
INT 3                                                       ;0000000140004074 CC 
INT 3                                                       ;0000000140004075 CC 
INT 3                                                       ;0000000140004076 CC 
INT 3                                                       ;0000000140004077 CC 
INT 3                                                       ;0000000140004078 CC 
INT 3                                                       ;0000000140004079 CC 
INT 3                                                       ;000000014000407A CC 
INT 3                                                       ;000000014000407B CC 
INT 3                                                       ;000000014000407C CC 
INT 3                                                       ;000000014000407D CC 
INT 3                                                       ;000000014000407E CC 
INT 3                                                       ;000000014000407F CC 
MOV qword ptr SS : [ RSP +  + 0x08 ], RBX                   ;0000000140004080 48 89 5C 24 08 
PUSH EDI                                                    ;0000000140004085 57 
SUB RSP, 0x20                                               ;0000000140004086 48 83 EC 20 
LEA RBX, CS : [ RIP + 0x00053977 ]                          ;000000014000408A 48 8D 1D 77 39 05 00 
LEA RDI, CS : [ RIP + 0x00053970 ]                          ;0000000140004091 48 8D 3D 70 39 05 00 
CMP RBX, RDI                                                ;0000000140004098 48 3B DF 
JAE 0x1A                                                    ;000000014000409B 73 1A 
NOP dword ptr DS : [ RAX ]                                  ;000000014000409D 0F 1F 00 
MOV RAX, qword ptr DS : [ RBX ]                             ;00000001400040A0 48 8B 03 
TEST RAX, RAX                                               ;00000001400040A3 48 85 C0 
JZ 0x06                                                     ;00000001400040A6 74 06 
CALL CS : [ RIP + 0x000411C2 ]                              ;00000001400040A8 FF 15 C2 11 04 00 
ADD RBX, 0x08                                               ;00000001400040AE 48 83 C3 08 
CMP RBX, RDI                                                ;00000001400040B2 48 3B DF 
JB 0xE9                                                     ;00000001400040B5 72 E9 
MOV RBX, qword ptr SS : [ RSP +  + 0x30 ]                   ;00000001400040B7 48 8B 5C 24 30 
ADD RSP, 0x20                                               ;00000001400040BC 48 83 C4 20 
POP EDI                                                     ;00000001400040C0 5F 
RETN                                                        ;00000001400040C1 C3 
INT 3                                                       ;00000001400040C2 CC 
INT 3                                                       ;00000001400040C3 CC 
INT 3                                                       ;00000001400040C4 CC 
INT 3                                                       ;00000001400040C5 CC 
INT 3                                                       ;00000001400040C6 CC 
INT 3                                                       ;00000001400040C7 CC 
INT 3                                                       ;00000001400040C8 CC 
INT 3                                                       ;00000001400040C9 CC 
INT 3                                                       ;00000001400040CA CC 
INT 3                                                       ;00000001400040CB CC 
INT 3                                                       ;00000001400040CC CC 
INT 3                                                       ;00000001400040CD CC 
INT 3                                                       ;00000001400040CE CC 
INT 3                                                       ;00000001400040CF CC 
MOV qword ptr SS : [ RSP +  + 0x08 ], RBX                   ;00000001400040D0 48 89 5C 24 08 
PUSH EDI                                                    ;00000001400040D5 57 
SUB RSP, 0x20                                               ;00000001400040D6 48 83 EC 20 
LEA RBX, CS : [ RIP + 0x00053937 ]                          ;00000001400040DA 48 8D 1D 37 39 05 00 
LEA RDI, CS : [ RIP + 0x00053930 ]                          ;00000001400040E1 48 8D 3D 30 39 05 00 
CMP RBX, RDI                                                ;00000001400040E8 48 3B DF 
JAE 0x1A                                                    ;00000001400040EB 73 1A 
NOP dword ptr DS : [ RAX ]                                  ;00000001400040ED 0F 1F 00 
MOV RAX, qword ptr DS : [ RBX ]                             ;00000001400040F0 48 8B 03 
TEST RAX, RAX                                               ;00000001400040F3 48 85 C0 
JZ 0x06                                                     ;00000001400040F6 74 06 
CALL CS : [ RIP + 0x00041172 ]                              ;00000001400040F8 FF 15 72 11 04 00 
ADD RBX, 0x08                                               ;00000001400040FE 48 83 C3 08 
CMP RBX, RDI                                                ;0000000140004102 48 3B DF 
JB 0xE9                                                     ;0000000140004105 72 E9 
MOV RBX, qword ptr SS : [ RSP +  + 0x30 ]                   ;0000000140004107 48 8B 5C 24 30 
ADD RSP, 0x20                                               ;000000014000410C 48 83 C4 20 
POP EDI                                                     ;0000000140004110 5F 
RETN                                                        ;0000000140004111 C3 
INT 3                                                       ;0000000140004112 CC 
INT 3                                                       ;0000000140004113 CC 
INT 3                                                       ;0000000140004114 CC 
INT 3                                                       ;0000000140004115 CC 
INT 3                                                       ;0000000140004116 CC 
INT 3                                                       ;0000000140004117 CC 
INT 3                                                       ;0000000140004118 CC 
INT 3                                                       ;0000000140004119 CC 
INT 3                                                       ;000000014000411A CC 
INT 3                                                       ;000000014000411B CC 
INT 3                                                       ;000000014000411C CC 
INT 3                                                       ;000000014000411D CC 
INT 3                                                       ;000000014000411E CC 
INT 3                                                       ;000000014000411F CC 
MOV qword ptr SS : [ RSP +  + 0x08 ], RCX                   ;0000000140004120 48 89 4C 24 08 
RETN                                                        ;0000000140004125 C3 
INT 3                                                       ;0000000140004126 CC 
INT 3                                                       ;0000000140004127 CC 
INT 3                                                       ;0000000140004128 CC 
INT 3                                                       ;0000000140004129 CC 
INT 3                                                       ;000000014000412A CC 
INT 3                                                       ;000000014000412B CC 
INT 3                                                       ;000000014000412C CC 
INT 3                                                       ;000000014000412D CC 
INT 3                                                       ;000000014000412E CC 
INT 3                                                       ;000000014000412F CC 
MOV qword ptr SS : [ RSP +  + 0x08 ], RCX                   ;0000000140004130 48 89 4C 24 08 
SUB RSP, 0x18                                               ;0000000140004135 48 83 EC 18 
MOV RAX, qword ptr SS : [ RSP +  + 0x20 ]                   ;0000000140004139 48 8B 44 24 20 
MOV RAX, qword ptr DS : [ RAX ]                             ;000000014000413E 48 8B 00 
MOV qword ptr SS : [ RSP +  ], RAX                          ;0000000140004141 48 89 04 24 
MOV RAX, qword ptr SS : [ RSP +  ]                          ;0000000140004145 48 8B 04 24 
ADD RSP, 0x18                                               ;0000000140004149 48 83 C4 18 
RETN                                                        ;000000014000414D C3 
INT 3                                                       ;000000014000414E CC 
INT 3                                                       ;000000014000414F CC 
MOV qword ptr SS : [ RSP +  + 0x08 ], RCX                   ;0000000140004150 48 89 4C 24 08 
SUB RSP, 0x28                                               ;0000000140004155 48 83 EC 28 
MOV RCX, qword ptr SS : [ RSP +  + 0x30 ]                   ;0000000140004159 48 8B 4C 24 30 
CALL 0xFFFFFFCD                                             ;000000014000415E E8 CD FF FF FF 
ADD RSP, 0x28                                               ;0000000140004163 48 83 C4 28 
RETN                                                        ;0000000140004167 C3 
INT 3                                                       ;0000000140004168 CC 
INT 3                                                       ;0000000140004169 CC 
INT 3                                                       ;000000014000416A CC 
INT 3                                                       ;000000014000416B CC 
INT 3                                                       ;000000014000416C CC 
INT 3                                                       ;000000014000416D CC 
INT 3                                                       ;000000014000416E CC 
INT 3                                                       ;000000014000416F CC 
SUB RSP, 0x38                                               ;0000000140004170 48 83 EC 38 
LEA RCX, CS : [ RIP + 0x000410ED ]                          ;0000000140004174 48 8D 0D ED 10 04 00 
CALL 0xFFFFFFD0                                             ;000000014000417B E8 D0 FF FF FF 
LEA RCX, CS : [ RIP + 0xFFFFFF99 ]                          ;0000000140004180 48 8D 0D 99 FF FF FF 
CMP RAX, RCX                                                ;0000000140004187 48 3B C1 
JZ 0x0A                                                     ;000000014000418A 74 0A 
MOV dword ptr SS : [ RSP +  + 0x20 ], 0x00000001            ;000000014000418C C7 44 24 20 01 00 00 00 
JMP 0x08                                                    ;0000000140004194 EB 08 
MOV dword ptr SS : [ RSP +  + 0x20 ], 0x00000000            ;0000000140004196 C7 44 24 20 00 00 00 00 
MOV EAX, dword ptr SS : [ RSP +  + 0x20 ]                   ;000000014000419E 8B 44 24 20 
ADD RSP, 0x38                                               ;00000001400041A2 48 83 C4 38 
RETN                                                        ;00000001400041A6 C3 
INT 3                                                       ;00000001400041A7 CC 
INT 3                                                       ;00000001400041A8 CC 
INT 3                                                       ;00000001400041A9 CC 
INT 3                                                       ;00000001400041AA CC 
INT 3                                                       ;00000001400041AB CC 
INT 3                                                       ;00000001400041AC CC 
INT 3                                                       ;00000001400041AD CC 
INT 3                                                       ;00000001400041AE CC 
INT 3                                                       ;00000001400041AF CC 
PUSH RBX                                                    ;00000001400041B0 40 53 
SUB RSP, 0x50                                               ;00000001400041B2 48 83 EC 50 
MOV RAX, CS : [ RIP + 0x00055E4B ]                          ;00000001400041B6 48 8B 05 4B 5E 05 00 
XOR RAX, RSP                                                ;00000001400041BD 48 33 C4 
MOV qword ptr SS : [ RSP +  + 0x40 ], RAX                   ;00000001400041C0 48 89 44 24 40 
MOV dword ptr SS : [ RSP +  + 0x30 ], 0x00000000            ;00000001400041C5 C7 44 24 30 00 00 00 00 
MOV dword ptr SS : [ RSP +  + 0x34 ], 0x00000000            ;00000001400041CD C7 44 24 34 00 00 00 00 
MOV dword ptr SS : [ RSP +  + 0x38 ], 0x00000000            ;00000001400041D5 C7 44 24 38 00 00 00 00 
MOV CS : [ RIP + 0x00055E3D ], 0x00000002                   ;00000001400041DD C7 05 3D 5E 05 00 02 00 00 00 
MOV CS : [ RIP + 0x00055E2F ], 0x00000001                   ;00000001400041E7 C7 05 2F 5E 05 00 01 00 00 00 
XOR EAX, EAX                                                ;00000001400041F1 33 C0 
XOR ECX, ECX                                                ;00000001400041F3 33 C9 
CPUID                                                       ;00000001400041F5 0F A2 
LEA R8, invalid ptr SS : [ RSP +  + 0x20 ]                  ;00000001400041F7 4C 8D 44 24 20 
MOV dword ptr DS : [ R8 ], EAX                              ;00000001400041FC 41 89 00 
MOV dword ptr DS : [ R8 + 0x04 ], EBX                       ;00000001400041FF 41 89 58 04 
MOV dword ptr DS : [ R8 + 0x08 ], ECX                       ;0000000140004203 41 89 48 08 
MOV dword ptr DS : [ R8 + 0x0C ], EDX                       ;0000000140004207 41 89 50 0C 
MOV EAX, 0x00000004                                         ;000000014000420B B8 04 00 00 00 
IMUL RAX, RAX, 0x00                                         ;0000000140004210 48 6B C0 00 
MOV EAX, dword ptr SS : [ RSP + RAX * 1 + 0x20 ]            ;0000000140004214 8B 44 04 20 
MOV dword ptr SS : [ RSP +  + 0x10 ], EAX                   ;0000000140004218 89 44 24 10 
MOV EAX, 0x00000004                                         ;000000014000421C B8 04 00 00 00 
IMUL RAX, RAX, 0x01                                         ;0000000140004221 48 6B C0 01 
MOV EAX, dword ptr SS : [ RSP + RAX * 1 + 0x20 ]            ;0000000140004225 8B 44 04 20 
XOR EAX, 0x756E6547                                         ;0000000140004229 35 47 65 6E 75 
MOV ECX, 0x00000004                                         ;000000014000422E B9 04 00 00 00 
IMUL RCX, RCX, 0x03                                         ;0000000140004233 48 6B C9 03 
MOV ECX, dword ptr SS : [ RSP + RCX * 1 + 0x20 ]            ;0000000140004237 8B 4C 0C 20 
XOR ECX, 0x49656E69                                         ;000000014000423B 81 F1 69 6E 65 49 
OR EAX, ECX                                                 ;0000000140004241 0B C1 
MOV ECX, 0x00000004                                         ;0000000140004243 B9 04 00 00 00 
IMUL RCX, RCX, 0x02                                         ;0000000140004248 48 6B C9 02 
MOV ECX, dword ptr SS : [ RSP + RCX * 1 + 0x20 ]            ;000000014000424C 8B 4C 0C 20 
XOR ECX, 0x6C65746E                                         ;0000000140004250 81 F1 6E 74 65 6C 
OR EAX, ECX                                                 ;0000000140004256 0B C1 
TEST EAX, EAX                                               ;0000000140004258 85 C0 
JNZ 0x0A                                                    ;000000014000425A 75 0A 
MOV dword ptr SS : [ RSP +  + 0x08 ], 0x00000001            ;000000014000425C C7 44 24 08 01 00 00 00 
JMP 0x08                                                    ;0000000140004264 EB 08 
MOV dword ptr SS : [ RSP +  + 0x08 ], 0x00000000            ;0000000140004266 C7 44 24 08 00 00 00 00 
MOVZX EAX, byte ptr SS : [ RSP +  + 0x08 ]                  ;000000014000426E 0F B6 44 24 08 
MOV byte ptr SS : [ RSP +  ], AL                            ;0000000140004273 88 04 24 
MOV EAX, 0x00000004                                         ;0000000140004276 B8 04 00 00 00 
IMUL RAX, RAX, 0x01                                         ;000000014000427B 48 6B C0 01 
MOV EAX, dword ptr SS : [ RSP + RAX * 1 + 0x20 ]            ;000000014000427F 8B 44 04 20 
XOR EAX, 0x68747541                                         ;0000000140004283 35 41 75 74 68 
MOV ECX, 0x00000004                                         ;0000000140004288 B9 04 00 00 00 
IMUL RCX, RCX, 0x03                                         ;000000014000428D 48 6B C9 03 
MOV ECX, dword ptr SS : [ RSP + RCX * 1 + 0x20 ]            ;0000000140004291 8B 4C 0C 20 
XOR ECX, 0x69746E65                                         ;0000000140004295 81 F1 65 6E 74 69 
OR EAX, ECX                                                 ;000000014000429B 0B C1 
MOV ECX, 0x00000004                                         ;000000014000429D B9 04 00 00 00 
IMUL RCX, RCX, 0x02                                         ;00000001400042A2 48 6B C9 02 
MOV ECX, dword ptr SS : [ RSP + RCX * 1 + 0x20 ]            ;00000001400042A6 8B 4C 0C 20 
XOR ECX, 0x444D4163                                         ;00000001400042AA 81 F1 63 41 4D 44 
OR EAX, ECX                                                 ;00000001400042B0 0B C1 
TEST EAX, EAX                                               ;00000001400042B2 85 C0 
JNZ 0x0A                                                    ;00000001400042B4 75 0A 
MOV dword ptr SS : [ RSP +  + 0x0C ], 0x00000001            ;00000001400042B6 C7 44 24 0C 01 00 00 00 
JMP 0x08                                                    ;00000001400042BE EB 08 
MOV dword ptr SS : [ RSP +  + 0x0C ], 0x00000000            ;00000001400042C0 C7 44 24 0C 00 00 00 00 
MOVZX EAX, byte ptr SS : [ RSP +  + 0x0C ]                  ;00000001400042C8 0F B6 44 24 0C 
MOV byte ptr SS : [ RSP +  + 0x01 ], AL                     ;00000001400042CD 88 44 24 01 
MOV EAX, 0x00000001                                         ;00000001400042D1 B8 01 00 00 00 
XOR ECX, ECX                                                ;00000001400042D6 33 C9 
CPUID                                                       ;00000001400042D8 0F A2 
LEA R8, invalid ptr SS : [ RSP +  + 0x20 ]                  ;00000001400042DA 4C 8D 44 24 20 
MOV dword ptr DS : [ R8 ], EAX                              ;00000001400042DF 41 89 00 
MOV dword ptr DS : [ R8 + 0x04 ], EBX                       ;00000001400042E2 41 89 58 04 
MOV dword ptr DS : [ R8 + 0x08 ], ECX                       ;00000001400042E6 41 89 48 08 
MOV dword ptr DS : [ R8 + 0x0C ], EDX                       ;00000001400042EA 41 89 50 0C 
MOV EAX, 0x00000004                                         ;00000001400042EE B8 04 00 00 00 
IMUL RAX, RAX, 0x00                                         ;00000001400042F3 48 6B C0 00 
MOV EAX, dword ptr SS : [ RSP + RAX * 1 + 0x20 ]            ;00000001400042F7 8B 44 04 20 
MOV dword ptr SS : [ RSP +  + 0x04 ], EAX                   ;00000001400042FB 89 44 24 04 
MOVZX EAX, byte ptr SS : [ RSP +  ]                         ;00000001400042FF 0F B6 04 24 
TEST EAX, EAX                                               ;0000000140004303 85 C0 
JZ 0x7A                                                     ;0000000140004305 74 7A 
MOV CS : [ RIP + 0x00055D16 ], 0xFFFFFFFF                   ;0000000140004307 48 C7 05 16 5D 05 00 FF FF FF FF 
MOV EAX, dword ptr SS : [ RSP +  + 0x04 ]                   ;0000000140004312 8B 44 24 04 
AND EAX, 0x0FFF3FF0                                         ;0000000140004316 25 F0 3F FF 0F 
CMP EAX, 0x000106C0                                         ;000000014000431B 3D C0 06 01 00 
JZ 0x50                                                     ;0000000140004320 74 50 
MOV EAX, dword ptr SS : [ RSP +  + 0x04 ]                   ;0000000140004322 8B 44 24 04 
AND EAX, 0x0FFF3FF0                                         ;0000000140004326 25 F0 3F FF 0F 
CMP EAX, 0x00020660                                         ;000000014000432B 3D 60 06 02 00 
JZ 0x40                                                     ;0000000140004330 74 40 
MOV EAX, dword ptr SS : [ RSP +  + 0x04 ]                   ;0000000140004332 8B 44 24 04 
AND EAX, 0x0FFF3FF0                                         ;0000000140004336 25 F0 3F FF 0F 
CMP EAX, 0x00020670                                         ;000000014000433B 3D 70 06 02 00 
JZ 0x30                                                     ;0000000140004340 74 30 
MOV EAX, dword ptr SS : [ RSP +  + 0x04 ]                   ;0000000140004342 8B 44 24 04 
AND EAX, 0x0FFF3FF0                                         ;0000000140004346 25 F0 3F FF 0F 
CMP EAX, 0x00030650                                         ;000000014000434B 3D 50 06 03 00 
JZ 0x20                                                     ;0000000140004350 74 20 
MOV EAX, dword ptr SS : [ RSP +  + 0x04 ]                   ;0000000140004352 8B 44 24 04 
AND EAX, 0x0FFF3FF0                                         ;0000000140004356 25 F0 3F FF 0F 
CMP EAX, 0x00030660                                         ;000000014000435B 3D 60 06 03 00 
JZ 0x10                                                     ;0000000140004360 74 10 
MOV EAX, dword ptr SS : [ RSP +  + 0x04 ]                   ;0000000140004362 8B 44 24 04 
AND EAX, 0x0FFF3FF0                                         ;0000000140004366 25 F0 3F FF 0F 
CMP EAX, 0x00030670                                         ;000000014000436B 3D 70 06 03 00 
JNZ 0x0F                                                    ;0000000140004370 75 0F 
MOV EAX, CS : [ RIP + 0x00056D64 ]                          ;0000000140004372 8B 05 64 6D 05 00 
OR EAX, 0x01                                                ;0000000140004378 83 C8 01 
MOV CS : [ RIP + 0x00056D5B ], EAX                          ;000000014000437B 89 05 5B 6D 05 00 
MOVZX EAX, byte ptr SS : [ RSP +  + 0x01 ]                  ;0000000140004381 0F B6 44 24 01 
TEST EAX, EAX                                               ;0000000140004386 85 C0 
JZ 0x1F                                                     ;0000000140004388 74 1F 
MOV EAX, dword ptr SS : [ RSP +  + 0x04 ]                   ;000000014000438A 8B 44 24 04 
AND EAX, 0x0FF00F00                                         ;000000014000438E 25 00 0F F0 0F 
CMP EAX, 0x00601100                                         ;0000000140004393 3D 00 11 60 00 
JL 0x0F                                                     ;0000000140004398 7C 0F 
MOV EAX, CS : [ RIP + 0x00056D3C ]                          ;000000014000439A 8B 05 3C 6D 05 00 
OR EAX, 0x04                                                ;00000001400043A0 83 C8 04 
MOV CS : [ RIP + 0x00056D33 ], EAX                          ;00000001400043A3 89 05 33 6D 05 00 
MOV EAX, 0x00000004                                         ;00000001400043A9 B8 04 00 00 00 
IMUL RAX, RAX, 0x03                                         ;00000001400043AE 48 6B C0 03 
MOV ECX, 0x00000004                                         ;00000001400043B2 B9 04 00 00 00 
IMUL RCX, RCX, 0x00                                         ;00000001400043B7 48 6B C9 00 
MOV EAX, dword ptr SS : [ RSP + RAX * 1 + 0x20 ]            ;00000001400043BB 8B 44 04 20 
MOV dword ptr SS : [ RSP + RCX * 1 + 0x30 ], EAX            ;00000001400043BF 89 44 0C 30 
MOV EAX, 0x00000004                                         ;00000001400043C3 B8 04 00 00 00 
IMUL RAX, RAX, 0x02                                         ;00000001400043C8 48 6B C0 02 
MOV ECX, 0x00000004                                         ;00000001400043CC B9 04 00 00 00 
IMUL RCX, RCX, 0x01                                         ;00000001400043D1 48 6B C9 01 
MOV EAX, dword ptr SS : [ RSP + RAX * 1 + 0x20 ]            ;00000001400043D5 8B 44 04 20 
MOV dword ptr SS : [ RSP + RCX * 1 + 0x30 ], EAX            ;00000001400043D9 89 44 0C 30 
CMP dword ptr SS : [ RSP +  + 0x10 ], 0x07                  ;00000001400043DD 83 7C 24 10 07 
JL 0x5C                                                     ;00000001400043E2 7C 5C 
MOV EAX, 0x00000007                                         ;00000001400043E4 B8 07 00 00 00 
XOR ECX, ECX                                                ;00000001400043E9 33 C9 
CPUID                                                       ;00000001400043EB 0F A2 
LEA R8, invalid ptr SS : [ RSP +  + 0x20 ]                  ;00000001400043ED 4C 8D 44 24 20 
MOV dword ptr DS : [ R8 ], EAX                              ;00000001400043F2 41 89 00 
MOV dword ptr DS : [ R8 + 0x04 ], EBX                       ;00000001400043F5 41 89 58 04 
MOV dword ptr DS : [ R8 + 0x08 ], ECX                       ;00000001400043F9 41 89 48 08 
MOV dword ptr DS : [ R8 + 0x0C ], EDX                       ;00000001400043FD 41 89 50 0C 
MOV EAX, 0x00000004                                         ;0000000140004401 B8 04 00 00 00 
IMUL RAX, RAX, 0x01                                         ;0000000140004406 48 6B C0 01 
MOV ECX, 0x00000004                                         ;000000014000440A B9 04 00 00 00 
IMUL RCX, RCX, 0x02                                         ;000000014000440F 48 6B C9 02 
MOV EAX, dword ptr SS : [ RSP + RAX * 1 + 0x20 ]            ;0000000140004413 8B 44 04 20 
MOV dword ptr SS : [ RSP + RCX * 1 + 0x30 ], EAX            ;0000000140004417 89 44 0C 30 
MOV EAX, 0x00000004                                         ;000000014000441B B8 04 00 00 00 
IMUL RAX, RAX, 0x01                                         ;0000000140004420 48 6B C0 01 
MOV EAX, dword ptr SS : [ RSP + RAX * 1 + 0x20 ]            ;0000000140004424 8B 44 04 20 
AND EAX, 0x00000200                                         ;0000000140004428 25 00 02 00 00 
TEST EAX, EAX                                               ;000000014000442D 85 C0 
JZ 0x0F                                                     ;000000014000442F 74 0F 
MOV EAX, CS : [ RIP + 0x00056CA5 ]                          ;0000000140004431 8B 05 A5 6C 05 00 
OR EAX, 0x02                                                ;0000000140004437 83 C8 02 
MOV CS : [ RIP + 0x00056C9C ], EAX                          ;000000014000443A 89 05 9C 6C 05 00 
MOV EAX, 0x00000004                                         ;0000000140004440 B8 04 00 00 00 
IMUL RAX, RAX, 0x01                                         ;0000000140004445 48 6B C0 01 
MOV EAX, dword ptr SS : [ RSP + RAX * 1 + 0x30 ]            ;0000000140004449 8B 44 04 30 
AND EAX, 0x00100000                                         ;000000014000444D 25 00 00 10 00 
TEST EAX, EAX                                               ;0000000140004452 85 C0 
JZ 0x000000AE                                               ;0000000140004454 0F 84 AE 00 00 00 
MOV CS : [ RIP + 0x00055BBC ], 0x00000002                   ;000000014000445A C7 05 BC 5B 05 00 02 00 00 00 
MOV EAX, CS : [ RIP + 0x00055BBA ]                          ;0000000140004464 8B 05 BA 5B 05 00 
OR EAX, 0x04                                                ;000000014000446A 83 C8 04 
MOV CS : [ RIP + 0x00055BB1 ], EAX                          ;000000014000446D 89 05 B1 5B 05 00 
MOV EAX, 0x00000004                                         ;0000000140004473 B8 04 00 00 00 
IMUL RAX, RAX, 0x01                                         ;0000000140004478 48 6B C0 01 
MOV EAX, dword ptr SS : [ RSP + RAX * 1 + 0x30 ]            ;000000014000447C 8B 44 04 30 
AND EAX, 0x08000000                                         ;0000000140004480 25 00 00 00 08 
TEST EAX, EAX                                               ;0000000140004485 85 C0 
JZ 0x7F                                                     ;0000000140004487 74 7F 
MOV EAX, 0x00000004                                         ;0000000140004489 B8 04 00 00 00 
IMUL RAX, RAX, 0x01                                         ;000000014000448E 48 6B C0 01 
MOV EAX, dword ptr SS : [ RSP + RAX * 1 + 0x30 ]            ;0000000140004492 8B 44 04 30 
AND EAX, 0x10000000                                         ;0000000140004496 25 00 00 00 10 
TEST EAX, EAX                                               ;000000014000449B 85 C0 
JZ 0x69                                                     ;000000014000449D 74 69 
XOR ECX, ECX                                                ;000000014000449F 33 C9 
XGETBV                                                      ;00000001400044A1 0F 01 D0 
SAL RDX, 0x20                                               ;00000001400044A4 48 C1 E2 20 
OR RDX, RAX                                                 ;00000001400044A8 48 0B D0 
MOV RAX, RDX                                                ;00000001400044AB 48 8B C2 
MOV qword ptr SS : [ RSP +  + 0x18 ], RAX                   ;00000001400044AE 48 89 44 24 18 
MOV RAX, qword ptr SS : [ RSP +  + 0x18 ]                   ;00000001400044B3 48 8B 44 24 18 
AND RAX, 0x06                                               ;00000001400044B8 48 83 E0 06 
CMP RAX, 0x06                                               ;00000001400044BC 48 83 F8 06 
JNZ 0x46                                                    ;00000001400044C0 75 46 
MOV CS : [ RIP + 0x00055B54 ], 0x00000003                   ;00000001400044C2 C7 05 54 5B 05 00 03 00 00 00 
MOV EAX, CS : [ RIP + 0x00055B52 ]                          ;00000001400044CC 8B 05 52 5B 05 00 
OR EAX, 0x08                                                ;00000001400044D2 83 C8 08 
MOV CS : [ RIP + 0x00055B49 ], EAX                          ;00000001400044D5 89 05 49 5B 05 00 
MOV EAX, 0x00000004                                         ;00000001400044DB B8 04 00 00 00 
IMUL RAX, RAX, 0x02                                         ;00000001400044E0 48 6B C0 02 
MOV EAX, dword ptr SS : [ RSP + RAX * 1 + 0x30 ]            ;00000001400044E4 8B 44 04 30 
AND EAX, 0x20                                               ;00000001400044E8 83 E0 20 
TEST EAX, EAX                                               ;00000001400044EB 85 C0 
JZ 0x19                                                     ;00000001400044ED 74 19 
MOV CS : [ RIP + 0x00055B27 ], 0x00000005                   ;00000001400044EF C7 05 27 5B 05 00 05 00 00 00 
MOV EAX, CS : [ RIP + 0x00055B25 ]                          ;00000001400044F9 8B 05 25 5B 05 00 
OR EAX, 0x20                                                ;00000001400044FF 83 C8 20 
MOV CS : [ RIP + 0x00055B1C ], EAX                          ;0000000140004502 89 05 1C 5B 05 00 
XOR EAX, EAX                                                ;0000000140004508 33 C0 
MOV RCX, qword ptr SS : [ RSP +  + 0x40 ]                   ;000000014000450A 48 8B 4C 24 40 
XOR RCX, RSP                                                ;000000014000450F 48 33 CC 
CALL 0xFFFFE939                                             ;0000000140004512 E8 39 E9 FF FF 
ADD RSP, 0x50                                               ;0000000140004517 48 83 C4 50 
POP EBX                                                     ;000000014000451B 5B 
RETN                                                        ;000000014000451C C3 
INT 3                                                       ;000000014000451D CC 
INT 3                                                       ;000000014000451E CC 
INT 3                                                       ;000000014000451F CC 
SUB RSP, 0x18                                               ;0000000140004520 48 83 EC 18 
CMP CS : [ RIP + 0x00057E45 ], 0x00                         ;0000000140004524 83 3D 45 7E 05 00 00 
JZ 0x09                                                     ;000000014000452B 74 09 
MOV dword ptr SS : [ RSP +  ], 0x00000001                   ;000000014000452D C7 04 24 01 00 00 00 
JMP 0x07                                                    ;0000000140004534 EB 07 
MOV dword ptr SS : [ RSP +  ], 0x00000000                   ;0000000140004536 C7 04 24 00 00 00 00 
MOV EAX, dword ptr SS : [ RSP +  ]                          ;000000014000453D 8B 04 24 
ADD RSP, 0x18                                               ;0000000140004540 48 83 C4 18 
RETN                                                        ;0000000140004544 C3 
INT 3                                                       ;0000000140004545 CC 
INT 3                                                       ;0000000140004546 CC 
INT 3                                                       ;0000000140004547 CC 
INT 3                                                       ;0000000140004548 CC 
INT 3                                                       ;0000000140004549 CC 
INT 3                                                       ;000000014000454A CC 
INT 3                                                       ;000000014000454B CC 
INT 3                                                       ;000000014000454C CC 
INT 3                                                       ;000000014000454D CC 
INT 3                                                       ;000000014000454E CC 
INT 3                                                       ;000000014000454F CC 
JMP CS : [ RIP + 0x00040AE2 ]                               ;0000000140004550 FF 25 E2 0A 04 00 
INT 3                                                       ;0000000140004556 CC 
INT 3                                                       ;0000000140004557 CC 
INT 3                                                       ;0000000140004558 CC 
INT 3                                                       ;0000000140004559 CC 
INT 3                                                       ;000000014000455A CC 
INT 3                                                       ;000000014000455B CC 
INT 3                                                       ;000000014000455C CC 
INT 3                                                       ;000000014000455D CC 
INT 3                                                       ;000000014000455E CC 
INT 3                                                       ;000000014000455F CC 
MOV qword ptr SS : [ RSP +  + 0x20 ], R9                    ;0000000140004560 4C 89 4C 24 20 
MOV qword ptr SS : [ RSP +  + 0x18 ], R8                    ;0000000140004565 4C 89 44 24 18 
MOV qword ptr SS : [ RSP +  + 0x10 ], RDX                   ;000000014000456A 48 89 54 24 10 
MOV qword ptr SS : [ RSP +  + 0x08 ], RCX                   ;000000014000456F 48 89 4C 24 08 
SUB RSP, 0x00000098                                         ;0000000140004574 48 81 EC 98 00 00 00 
MOV RCX, qword ptr SS : [ RSP +  + 0x000000B0 ]             ;000000014000457B 48 8B 8C 24 B0 00 00 00 
CALL 0x00000618                                             ;0000000140004583 E8 18 06 00 00 
MOV RAX, qword ptr SS : [ RSP +  + 0x000000B8 ]             ;0000000140004588 48 8B 84 24 B8 00 00 00 
MOV RAX, qword ptr DS : [ RAX + 0x08 ]                      ;0000000140004590 48 8B 40 08 
MOV qword ptr SS : [ RSP +  + 0x48 ], RAX                   ;0000000140004594 48 89 44 24 48 
MOV RAX, qword ptr SS : [ RSP +  + 0x000000B8 ]             ;0000000140004599 48 8B 84 24 B8 00 00 00 
MOV RCX, qword ptr SS : [ RSP +  + 0x48 ]                   ;00000001400045A1 48 8B 4C 24 48 
MOV RAX, qword ptr DS : [ RAX ]                             ;00000001400045A6 48 8B 00 
SUB RAX, RCX                                                ;00000001400045A9 48 2B C1 
MOV qword ptr SS : [ RSP +  + 0x50 ], RAX                   ;00000001400045AC 48 89 44 24 50 
MOV RAX, qword ptr SS : [ RSP +  + 0x000000B8 ]             ;00000001400045B1 48 8B 84 24 B8 00 00 00 
MOV RAX, qword ptr DS : [ RAX + 0x38 ]                      ;00000001400045B9 48 8B 40 38 
MOV qword ptr SS : [ RSP +  + 0x38 ], RAX                   ;00000001400045BD 48 89 44 24 38 
MOV RAX, qword ptr SS : [ RSP +  + 0x000000A0 ]             ;00000001400045C2 48 8B 84 24 A0 00 00 00 
MOV EAX, dword ptr DS : [ RAX + 0x04 ]                      ;00000001400045CA 8B 40 04 
AND EAX, 0x66                                               ;00000001400045CD 83 E0 66 
TEST EAX, EAX                                               ;00000001400045D0 85 C0 
JNZ 0x000001E8                                              ;00000001400045D2 0F 85 E8 01 00 00 
MOV RAX, qword ptr SS : [ RSP +  + 0x000000A0 ]             ;00000001400045D8 48 8B 84 24 A0 00 00 00 
MOV qword ptr SS : [ RSP +  + 0x78 ], RAX                   ;00000001400045E0 48 89 44 24 78 
MOV RAX, qword ptr SS : [ RSP +  + 0x000000B0 ]             ;00000001400045E5 48 8B 84 24 B0 00 00 00 
MOV qword ptr SS : [ RSP +  + 0x00000080 ], RAX             ;00000001400045ED 48 89 84 24 80 00 00 00 
MOV RAX, qword ptr SS : [ RSP +  + 0x000000B8 ]             ;00000001400045F5 48 8B 84 24 B8 00 00 00 
MOV EAX, dword ptr DS : [ RAX + 0x48 ]                      ;00000001400045FD 8B 40 48 
MOV dword ptr SS : [ RSP +  + 0x30 ], EAX                   ;0000000140004600 89 44 24 30 
JMP 0x0A                                                    ;0000000140004604 EB 0A 
MOV EAX, dword ptr SS : [ RSP +  + 0x30 ]                   ;0000000140004606 8B 44 24 30 
INC EAX                                                     ;000000014000460A FF C0 
MOV dword ptr SS : [ RSP +  + 0x30 ], EAX                   ;000000014000460C 89 44 24 30 
MOV RAX, qword ptr SS : [ RSP +  + 0x38 ]                   ;0000000140004610 48 8B 44 24 38 
MOV EAX, dword ptr DS : [ RAX ]                             ;0000000140004615 8B 00 
CMP dword ptr SS : [ RSP +  + 0x30 ], EAX                   ;0000000140004617 39 44 24 30 
JAE 0x0000019A                                              ;000000014000461B 0F 83 9A 01 00 00 
MOV EAX, dword ptr SS : [ RSP +  + 0x30 ]                   ;0000000140004621 8B 44 24 30 
IMUL RAX, RAX, 0x10                                         ;0000000140004625 48 6B C0 10 
MOV RCX, qword ptr SS : [ RSP +  + 0x38 ]                   ;0000000140004629 48 8B 4C 24 38 
MOV EAX, dword ptr DS : [ RCX + RAX * 1 + 0x04 ]            ;000000014000462E 8B 44 01 04 
CMP qword ptr SS : [ RSP +  + 0x50 ], RAX                   ;0000000140004632 48 39 44 24 50 
JB 0x00000179                                               ;0000000140004637 0F 82 79 01 00 00 
MOV EAX, dword ptr SS : [ RSP +  + 0x30 ]                   ;000000014000463D 8B 44 24 30 
IMUL RAX, RAX, 0x10                                         ;0000000140004641 48 6B C0 10 
MOV RCX, qword ptr SS : [ RSP +  + 0x38 ]                   ;0000000140004645 48 8B 4C 24 38 
MOV EAX, dword ptr DS : [ RCX + RAX * 1 + 0x08 ]            ;000000014000464A 8B 44 01 08 
CMP qword ptr SS : [ RSP +  + 0x50 ], RAX                   ;000000014000464E 48 39 44 24 50 
JAE 0x0000015D                                              ;0000000140004653 0F 83 5D 01 00 00 
MOV EAX, dword ptr SS : [ RSP +  + 0x30 ]                   ;0000000140004659 8B 44 24 30 
IMUL RAX, RAX, 0x10                                         ;000000014000465D 48 6B C0 10 
MOV RCX, qword ptr SS : [ RSP +  + 0x38 ]                   ;0000000140004661 48 8B 4C 24 38 
CMP dword ptr DS : [ RCX + RAX * 1 + 0x10 ], 0x00           ;0000000140004666 83 7C 01 10 00 
JZ 0x00000145                                               ;000000014000466B 0F 84 45 01 00 00 
MOV EAX, dword ptr SS : [ RSP +  + 0x30 ]                   ;0000000140004671 8B 44 24 30 
IMUL RAX, RAX, 0x10                                         ;0000000140004675 48 6B C0 10 
MOV RCX, qword ptr SS : [ RSP +  + 0x38 ]                   ;0000000140004679 48 8B 4C 24 38 
CMP dword ptr DS : [ RCX + RAX * 1 + 0x0C ], 0x01           ;000000014000467E 83 7C 01 0C 01 
JNZ 0x0A                                                    ;0000000140004683 75 0A 
MOV dword ptr SS : [ RSP +  + 0x44 ], 0x00000001            ;0000000140004685 C7 44 24 44 01 00 00 00 
JMP 0x30                                                    ;000000014000468D EB 30 
MOV EAX, dword ptr SS : [ RSP +  + 0x30 ]                   ;000000014000468F 8B 44 24 30 
IMUL RAX, RAX, 0x10                                         ;0000000140004693 48 6B C0 10 
MOV RCX, qword ptr SS : [ RSP +  + 0x38 ]                   ;0000000140004697 48 8B 4C 24 38 
MOV EAX, dword ptr DS : [ RCX + RAX * 1 + 0x0C ]            ;000000014000469C 8B 44 01 0C 
ADD RAX, qword ptr SS : [ RSP +  + 0x48 ]                   ;00000001400046A0 48 03 44 24 48 
MOV qword ptr SS : [ RSP +  + 0x60 ], RAX                   ;00000001400046A5 48 89 44 24 60 
MOV RDX, qword ptr SS : [ RSP +  + 0x000000A8 ]             ;00000001400046AA 48 8B 94 24 A8 00 00 00 
LEA RCX, invalid ptr SS : [ RSP +  + 0x78 ]                 ;00000001400046B2 48 8D 4C 24 78 
CALL qword ptr SS : [ RSP +  + 0x60 ]                       ;00000001400046B7 FF 54 24 60 
MOV dword ptr SS : [ RSP +  + 0x44 ], EAX                   ;00000001400046BB 89 44 24 44 
CMP dword ptr SS : [ RSP +  + 0x44 ], 0x00                  ;00000001400046BF 83 7C 24 44 00 
JGE 0x0C                                                    ;00000001400046C4 7D 0C 
XOR EAX, EAX                                                ;00000001400046C6 33 C0 
JMP 0x000002C4                                              ;00000001400046C8 E9 C4 02 00 00 
JMP 0x000000E4                                              ;00000001400046CD E9 E4 00 00 00 
CMP dword ptr SS : [ RSP +  + 0x44 ], 0x00                  ;00000001400046D2 83 7C 24 44 00 
JLE 0x000000D9                                              ;00000001400046D7 0F 8E D9 00 00 00 
MOV RAX, qword ptr SS : [ RSP +  + 0x000000A0 ]             ;00000001400046DD 48 8B 84 24 A0 00 00 00 
CMP dword ptr DS : [ RAX ], 0xE06D7363                      ;00000001400046E5 81 38 63 73 6D E0 
JNZ 0x2D                                                    ;00000001400046EB 75 2D 
CMP CS : [ RIP + 0x00040C8B ], 0x00                         ;00000001400046ED 48 83 3D 8B 0C 04 00 00 
JZ 0x23                                                     ;00000001400046F5 74 23 
LEA RCX, CS : [ RIP + 0x00040C82 ]                          ;00000001400046F7 48 8D 0D 82 0C 04 00 
CALL 0x0003EE2D                                             ;00000001400046FE E8 2D EE 03 00 
TEST EAX, EAX                                               ;0000000140004703 85 C0 
JZ 0x13                                                     ;0000000140004705 74 13 
MOV EDX, 0x00000001                                         ;0000000140004707 BA 01 00 00 00 
MOV RCX, qword ptr SS : [ RSP +  + 0x000000A0 ]             ;000000014000470C 48 8B 8C 24 A0 00 00 00 
CALL CS : [ RIP + 0x00040C66 ]                              ;0000000140004714 FF 15 66 0C 04 00 
MOV EAX, dword ptr SS : [ RSP +  + 0x30 ]                   ;000000014000471A 8B 44 24 30 
IMUL RAX, RAX, 0x10                                         ;000000014000471E 48 6B C0 10 
MOV RCX, qword ptr SS : [ RSP +  + 0x38 ]                   ;0000000140004722 48 8B 4C 24 38 
MOV EAX, dword ptr DS : [ RCX + RAX * 1 + 0x10 ]            ;0000000140004727 8B 44 01 10 
MOV RCX, qword ptr SS : [ RSP +  + 0x48 ]                   ;000000014000472B 48 8B 4C 24 48 
ADD RCX, RAX                                                ;0000000140004730 48 03 C8 
MOV RAX, RCX                                                ;0000000140004733 48 8B C1 
MOV qword ptr SS : [ RSP +  + 0x68 ], RAX                   ;0000000140004736 48 89 44 24 68 
MOV R8D, 0x00000001                                         ;000000014000473B 41 B8 01 00 00 00 
MOV RDX, qword ptr SS : [ RSP +  + 0x000000A8 ]             ;0000000140004741 48 8B 94 24 A8 00 00 00 
MOV RCX, qword ptr SS : [ RSP +  + 0x68 ]                   ;0000000140004749 48 8B 4C 24 68 
CALL 0x0000040D                                             ;000000014000474E E8 0D 04 00 00 
MOV RAX, qword ptr SS : [ RSP +  + 0x000000A0 ]             ;0000000140004753 48 8B 84 24 A0 00 00 00 
MOV EAX, dword ptr DS : [ RAX ]                             ;000000014000475B 8B 00 
MOV ECX, dword ptr SS : [ RSP +  + 0x30 ]                   ;000000014000475D 8B 4C 24 30 
IMUL RCX, RCX, 0x10                                         ;0000000140004761 48 6B C9 10 
MOV RDX, qword ptr SS : [ RSP +  + 0x38 ]                   ;0000000140004765 48 8B 54 24 38 
MOV ECX, dword ptr DS : [ RDX + RCX * 1 + 0x10 ]            ;000000014000476A 8B 4C 0A 10 
ADD RCX, qword ptr SS : [ RSP +  + 0x48 ]                   ;000000014000476E 48 03 4C 24 48 
MOV RDX, qword ptr SS : [ RSP +  + 0x000000B8 ]             ;0000000140004773 48 8B 94 24 B8 00 00 00 
MOV RDX, qword ptr DS : [ RDX + 0x40 ]                      ;000000014000477B 48 8B 52 40 
MOV qword ptr SS : [ RSP +  + 0x28 ], RDX                   ;000000014000477F 48 89 54 24 28 
MOV RDX, qword ptr SS : [ RSP +  + 0x000000B8 ]             ;0000000140004784 48 8B 94 24 B8 00 00 00 
MOV RDX, qword ptr DS : [ RDX + 0x28 ]                      ;000000014000478C 48 8B 52 28 
MOV qword ptr SS : [ RSP +  + 0x20 ], RDX                   ;0000000140004790 48 89 54 24 20 
MOV R9D, EAX                                                ;0000000140004795 44 8B C8 
MOV R8, qword ptr SS : [ RSP +  + 0x000000A0 ]              ;0000000140004798 4C 8B 84 24 A0 00 00 00 
MOV RDX, RCX                                                ;00000001400047A0 48 8B D1 
MOV RCX, qword ptr SS : [ RSP +  + 0x000000A8 ]             ;00000001400047A3 48 8B 8C 24 A8 00 00 00 
CALL CS : [ RIP + 0x000408D7 ]                              ;00000001400047AB FF 15 D7 08 04 00 
CALL 0x000003DA                                             ;00000001400047B1 E8 DA 03 00 00 
JMP 0xFFFFFE4B                                              ;00000001400047B6 E9 4B FE FF FF 
JMP 0x000001CC                                              ;00000001400047BB E9 CC 01 00 00 
MOV RAX, qword ptr SS : [ RSP +  + 0x000000B8 ]             ;00000001400047C0 48 8B 84 24 B8 00 00 00 
MOV RCX, qword ptr SS : [ RSP +  + 0x48 ]                   ;00000001400047C8 48 8B 4C 24 48 
MOV RAX, qword ptr DS : [ RAX + 0x20 ]                      ;00000001400047CD 48 8B 40 20 
SUB RAX, RCX                                                ;00000001400047D1 48 2B C1 
MOV qword ptr SS : [ RSP +  + 0x58 ], RAX                   ;00000001400047D4 48 89 44 24 58 
MOV RAX, qword ptr SS : [ RSP +  + 0x000000B8 ]             ;00000001400047D9 48 8B 84 24 B8 00 00 00 
MOV EAX, dword ptr DS : [ RAX + 0x48 ]                      ;00000001400047E1 8B 40 48 
MOV dword ptr SS : [ RSP +  + 0x30 ], EAX                   ;00000001400047E4 89 44 24 30 
JMP 0x0A                                                    ;00000001400047E8 EB 0A 
MOV EAX, dword ptr SS : [ RSP +  + 0x30 ]                   ;00000001400047EA 8B 44 24 30 
INC EAX                                                     ;00000001400047EE FF C0 
MOV dword ptr SS : [ RSP +  + 0x30 ], EAX                   ;00000001400047F0 89 44 24 30 
MOV RAX, qword ptr SS : [ RSP +  + 0x38 ]                   ;00000001400047F4 48 8B 44 24 38 
MOV EAX, dword ptr DS : [ RAX ]                             ;00000001400047F9 8B 00 
CMP dword ptr SS : [ RSP +  + 0x30 ], EAX                   ;00000001400047FB 39 44 24 30 
JAE 0x00000187                                              ;00000001400047FF 0F 83 87 01 00 00 
MOV EAX, dword ptr SS : [ RSP +  + 0x30 ]                   ;0000000140004805 8B 44 24 30 
IMUL RAX, RAX, 0x10                                         ;0000000140004809 48 6B C0 10 
MOV RCX, qword ptr SS : [ RSP +  + 0x38 ]                   ;000000014000480D 48 8B 4C 24 38 
MOV EAX, dword ptr DS : [ RCX + RAX * 1 + 0x04 ]            ;0000000140004812 8B 44 01 04 
CMP qword ptr SS : [ RSP +  + 0x50 ], RAX                   ;0000000140004816 48 39 44 24 50 
JB 0x00000166                                               ;000000014000481B 0F 82 66 01 00 00 
MOV EAX, dword ptr SS : [ RSP +  + 0x30 ]                   ;0000000140004821 8B 44 24 30 
IMUL RAX, RAX, 0x10                                         ;0000000140004825 48 6B C0 10 
MOV RCX, qword ptr SS : [ RSP +  + 0x38 ]                   ;0000000140004829 48 8B 4C 24 38 
MOV EAX, dword ptr DS : [ RCX + RAX * 1 + 0x08 ]            ;000000014000482E 8B 44 01 08 
CMP qword ptr SS : [ RSP +  + 0x50 ], RAX                   ;0000000140004832 48 39 44 24 50 
JAE 0x0000014A                                              ;0000000140004837 0F 83 4A 01 00 00 
MOV RAX, qword ptr SS : [ RSP +  + 0x000000A0 ]             ;000000014000483D 48 8B 84 24 A0 00 00 00 
MOV EAX, dword ptr DS : [ RAX + 0x04 ]                      ;0000000140004845 8B 40 04 
AND EAX, 0x20                                               ;0000000140004848 83 E0 20 
TEST EAX, EAX                                               ;000000014000484B 85 C0 
JZ 0x000000B8                                               ;000000014000484D 0F 84 B8 00 00 00 
MOV dword ptr SS : [ RSP +  + 0x40 ], 0x00000000            ;0000000140004853 C7 44 24 40 00 00 00 00 
JMP 0x0A                                                    ;000000014000485B EB 0A 
MOV EAX, dword ptr SS : [ RSP +  + 0x40 ]                   ;000000014000485D 8B 44 24 40 
INC EAX                                                     ;0000000140004861 FF C0 
MOV dword ptr SS : [ RSP +  + 0x40 ], EAX                   ;0000000140004863 89 44 24 40 
MOV RAX, qword ptr SS : [ RSP +  + 0x38 ]                   ;0000000140004867 48 8B 44 24 38 
MOV EAX, dword ptr DS : [ RAX ]                             ;000000014000486C 8B 00 
CMP dword ptr SS : [ RSP +  + 0x40 ], EAX                   ;000000014000486E 39 44 24 40 
JAE 0x00000081                                              ;0000000140004872 0F 83 81 00 00 00 
MOV EAX, dword ptr SS : [ RSP +  + 0x40 ]                   ;0000000140004878 8B 44 24 40 
IMUL RAX, RAX, 0x10                                         ;000000014000487C 48 6B C0 10 
MOV RCX, qword ptr SS : [ RSP +  + 0x38 ]                   ;0000000140004880 48 8B 4C 24 38 
MOV EAX, dword ptr DS : [ RCX + RAX * 1 + 0x04 ]            ;0000000140004885 8B 44 01 04 
CMP qword ptr SS : [ RSP +  + 0x58 ], RAX                   ;0000000140004889 48 39 44 24 58 
JB 0x64                                                     ;000000014000488E 72 64 
MOV EAX, dword ptr SS : [ RSP +  + 0x40 ]                   ;0000000140004890 8B 44 24 40 
IMUL RAX, RAX, 0x10                                         ;0000000140004894 48 6B C0 10 
MOV RCX, qword ptr SS : [ RSP +  + 0x38 ]                   ;0000000140004898 48 8B 4C 24 38 
MOV EAX, dword ptr DS : [ RCX + RAX * 1 + 0x08 ]            ;000000014000489D 8B 44 01 08 
CMP qword ptr SS : [ RSP +  + 0x58 ], RAX                   ;00000001400048A1 48 39 44 24 58 
JAE 0x4C                                                    ;00000001400048A6 73 4C 
MOV EAX, dword ptr SS : [ RSP +  + 0x40 ]                   ;00000001400048A8 8B 44 24 40 
IMUL RAX, RAX, 0x10                                         ;00000001400048AC 48 6B C0 10 
MOV ECX, dword ptr SS : [ RSP +  + 0x30 ]                   ;00000001400048B0 8B 4C 24 30 
IMUL RCX, RCX, 0x10                                         ;00000001400048B4 48 6B C9 10 
MOV RDX, qword ptr SS : [ RSP +  + 0x38 ]                   ;00000001400048B8 48 8B 54 24 38 
MOV R8, qword ptr SS : [ RSP +  + 0x38 ]                    ;00000001400048BD 4C 8B 44 24 38 
MOV ECX, dword ptr DS : [ R8 + RCX * 1 + 0x10 ]             ;00000001400048C2 41 8B 4C 08 10 
CMP dword ptr DS : [ RDX + RAX * 1 + 0x10 ], ECX            ;00000001400048C7 39 4C 02 10 
JNZ 0x27                                                    ;00000001400048CB 75 27 
MOV EAX, dword ptr SS : [ RSP +  + 0x40 ]                   ;00000001400048CD 8B 44 24 40 
IMUL RAX, RAX, 0x10                                         ;00000001400048D1 48 6B C0 10 
MOV ECX, dword ptr SS : [ RSP +  + 0x30 ]                   ;00000001400048D5 8B 4C 24 30 
IMUL RCX, RCX, 0x10                                         ;00000001400048D9 48 6B C9 10 
MOV RDX, qword ptr SS : [ RSP +  + 0x38 ]                   ;00000001400048DD 48 8B 54 24 38 
MOV R8, qword ptr SS : [ RSP +  + 0x38 ]                    ;00000001400048E2 4C 8B 44 24 38 
MOV ECX, dword ptr DS : [ R8 + RCX * 1 + 0x0C ]             ;00000001400048E7 41 8B 4C 08 0C 
CMP dword ptr DS : [ RDX + RAX * 1 + 0x0C ], ECX            ;00000001400048EC 39 4C 02 0C 
JNZ 0x02                                                    ;00000001400048F0 75 02 
JMP 0x05                                                    ;00000001400048F2 EB 05 
JMP 0xFFFFFF64                                              ;00000001400048F4 E9 64 FF FF FF 
MOV RAX, qword ptr SS : [ RSP +  + 0x38 ]                   ;00000001400048F9 48 8B 44 24 38 
MOV EAX, dword ptr DS : [ RAX ]                             ;00000001400048FE 8B 00 
CMP dword ptr SS : [ RSP +  + 0x40 ], EAX                   ;0000000140004900 39 44 24 40 
JZ 0x05                                                     ;0000000140004904 74 05 
JMP 0x00000081                                              ;0000000140004906 E9 81 00 00 00 
MOV EAX, dword ptr SS : [ RSP +  + 0x30 ]                   ;000000014000490B 8B 44 24 30 
IMUL RAX, RAX, 0x10                                         ;000000014000490F 48 6B C0 10 
MOV RCX, qword ptr SS : [ RSP +  + 0x38 ]                   ;0000000140004913 48 8B 4C 24 38 
CMP dword ptr DS : [ RCX + RAX * 1 + 0x10 ], 0x00           ;0000000140004918 83 7C 01 10 00 
JZ 0x2E                                                     ;000000014000491D 74 2E 
MOV EAX, dword ptr SS : [ RSP +  + 0x30 ]                   ;000000014000491F 8B 44 24 30 
IMUL RAX, RAX, 0x10                                         ;0000000140004923 48 6B C0 10 
MOV RCX, qword ptr SS : [ RSP +  + 0x38 ]                   ;0000000140004927 48 8B 4C 24 38 
MOV EAX, dword ptr DS : [ RCX + RAX * 1 + 0x10 ]            ;000000014000492C 8B 44 01 10 
CMP qword ptr SS : [ RSP +  + 0x58 ], RAX                   ;0000000140004930 48 39 44 24 58 
JNZ 0x14                                                    ;0000000140004935 75 14 
MOV RAX, qword ptr SS : [ RSP +  + 0x000000A0 ]             ;0000000140004937 48 8B 84 24 A0 00 00 00 
MOV EAX, dword ptr DS : [ RAX + 0x04 ]                      ;000000014000493F 8B 40 04 
AND EAX, 0x20                                               ;0000000140004942 83 E0 20 
TEST EAX, EAX                                               ;0000000140004945 85 C0 
JZ 0x02                                                     ;0000000140004947 74 02 
JMP 0x41                                                    ;0000000140004949 EB 41 
JMP 0x3A                                                    ;000000014000494B EB 3A 
MOV EAX, dword ptr SS : [ RSP +  + 0x30 ]                   ;000000014000494D 8B 44 24 30 
INC EAX                                                     ;0000000140004951 FF C0 
MOV RCX, qword ptr SS : [ RSP +  + 0x000000B8 ]             ;0000000140004953 48 8B 8C 24 B8 00 00 00 
MOV dword ptr DS : [ RCX + 0x48 ], EAX                      ;000000014000495B 89 41 48 
MOV EAX, dword ptr SS : [ RSP +  + 0x30 ]                   ;000000014000495E 8B 44 24 30 
IMUL RAX, RAX, 0x10                                         ;0000000140004962 48 6B C0 10 
MOV RCX, qword ptr SS : [ RSP +  + 0x38 ]                   ;0000000140004966 48 8B 4C 24 38 
MOV EAX, dword ptr DS : [ RCX + RAX * 1 + 0x0C ]            ;000000014000496B 8B 44 01 0C 
ADD RAX, qword ptr SS : [ RSP +  + 0x48 ]                   ;000000014000496F 48 03 44 24 48 
MOV qword ptr SS : [ RSP +  + 0x70 ], RAX                   ;0000000140004974 48 89 44 24 70 
MOV RDX, qword ptr SS : [ RSP +  + 0x000000A8 ]             ;0000000140004979 48 8B 94 24 A8 00 00 00 
MOV CL, 0x01                                                ;0000000140004981 B1 01 
CALL qword ptr SS : [ RSP +  + 0x70 ]                       ;0000000140004983 FF 54 24 70 
JMP 0xFFFFFE5E                                              ;0000000140004987 E9 5E FE FF FF 
MOV EAX, 0x00000001                                         ;000000014000498C B8 01 00 00 00 
ADD RSP, 0x00000098                                         ;0000000140004991 48 81 C4 98 00 00 00 
RETN                                                        ;0000000140004998 C3 
INT 3                                                       ;0000000140004999 CC 
INT 3                                                       ;000000014000499A CC 
INT 3                                                       ;000000014000499B CC 
INT 3                                                       ;000000014000499C CC 
INT 3                                                       ;000000014000499D CC 
INT 3                                                       ;000000014000499E CC 
INT 3                                                       ;000000014000499F CC 
SUB RSP, 0x28                                               ;00000001400049A0 48 83 EC 28 
CALL 0xFFFFF307                                             ;00000001400049A4 E8 07 F3 FF FF 
CALL 0x00001172                                             ;00000001400049A9 E8 72 11 00 00 
CALL 0x0000104D                                             ;00000001400049AE E8 4D 10 00 00 
CALL 0x00000828                                             ;00000001400049B3 E8 28 08 00 00 
MOVZX EAX, AL                                               ;00000001400049B8 0F B6 C0 
TEST EAX, EAX                                               ;00000001400049BB 85 C0 
JNZ 0x04                                                    ;00000001400049BD 75 04 
XOR AL, AL                                                  ;00000001400049BF 32 C0 
JMP 0x17                                                    ;00000001400049C1 EB 17 
CALL 0x00000798                                             ;00000001400049C3 E8 98 07 00 00 
MOVZX EAX, AL                                               ;00000001400049C8 0F B6 C0 
TEST EAX, EAX                                               ;00000001400049CB 85 C0 
JNZ 0x09                                                    ;00000001400049CD 75 09 
CALL 0x0000087C                                             ;00000001400049CF E8 7C 08 00 00 
XOR AL, AL                                                  ;00000001400049D4 32 C0 
JMP 0x02                                                    ;00000001400049D6 EB 02 
MOV AL, 0x01                                                ;00000001400049D8 B0 01 
ADD RSP, 0x28                                               ;00000001400049DA 48 83 C4 28 
RETN                                                        ;00000001400049DE C3 
INT 3                                                       ;00000001400049DF CC 
MOV byte ptr SS : [ RSP +  + 0x08 ], CL                     ;00000001400049E0 88 4C 24 08 
SUB RSP, 0x28                                               ;00000001400049E4 48 83 EC 28 
CALL 0x000007C3                                             ;00000001400049E8 E8 C3 07 00 00 
CALL 0x0000085E                                             ;00000001400049ED E8 5E 08 00 00 
MOVZX ECX, byte ptr SS : [ RSP +  + 0x30 ]                  ;00000001400049F2 0F B6 4C 24 30 
CALL 0x00001084                                             ;00000001400049F7 E8 84 10 00 00 
MOV AL, 0x01                                                ;00000001400049FC B0 01 
ADD RSP, 0x28                                               ;00000001400049FE 48 83 C4 28 
RETN                                                        ;0000000140004A02 C3 
INT 3                                                       ;0000000140004A03 CC 
INT 3                                                       ;0000000140004A04 CC 
INT 3                                                       ;0000000140004A05 CC 
INT 3                                                       ;0000000140004A06 CC 
INT 3                                                       ;0000000140004A07 CC 
INT 3                                                       ;0000000140004A08 CC 
INT 3                                                       ;0000000140004A09 CC 
INT 3                                                       ;0000000140004A0A CC 
INT 3                                                       ;0000000140004A0B CC 
INT 3                                                       ;0000000140004A0C CC 
INT 3                                                       ;0000000140004A0D CC 
INT 3                                                       ;0000000140004A0E CC 
INT 3                                                       ;0000000140004A0F CC 
MOV qword ptr SS : [ RSP +  + 0x10 ], RDX                   ;0000000140004A10 48 89 54 24 10 
MOV qword ptr SS : [ RSP +  + 0x08 ], RCX                   ;0000000140004A15 48 89 4C 24 08 
SUB RSP, 0x28                                               ;0000000140004A1A 48 83 EC 28 
MOV EDX, 0x00000002                                         ;0000000140004A1E BA 02 00 00 00 
MOV RCX, qword ptr SS : [ RSP +  + 0x38 ]                   ;0000000140004A23 48 8B 4C 24 38 
CALL 0x00016D13                                             ;0000000140004A28 E8 13 6D 01 00 
ADD RSP, 0x28                                               ;0000000140004A2D 48 83 C4 28 
RETN                                                        ;0000000140004A31 C3 
INT 3                                                       ;0000000140004A32 CC 
INT 3                                                       ;0000000140004A33 CC 
INT 3                                                       ;0000000140004A34 CC 
INT 3                                                       ;0000000140004A35 CC 
INT 3                                                       ;0000000140004A36 CC 
INT 3                                                       ;0000000140004A37 CC 
INT 3                                                       ;0000000140004A38 CC 
INT 3                                                       ;0000000140004A39 CC 
INT 3                                                       ;0000000140004A3A CC 
INT 3                                                       ;0000000140004A3B CC 
INT 3                                                       ;0000000140004A3C CC 
INT 3                                                       ;0000000140004A3D CC 
INT 3                                                       ;0000000140004A3E CC 
INT 3                                                       ;0000000140004A3F CC 
MOV qword ptr SS : [ RSP +  + 0x10 ], RDX                   ;0000000140004A40 48 89 54 24 10 
MOV qword ptr SS : [ RSP +  + 0x08 ], RCX                   ;0000000140004A45 48 89 4C 24 08 
MOV RAX, qword ptr SS : [ RSP +  + 0x08 ]                   ;0000000140004A4A 48 8B 44 24 08 
MOV RCX, qword ptr SS : [ RSP +  + 0x10 ]                   ;0000000140004A4F 48 8B 4C 24 10 
MOV qword ptr DS : [ RAX ], RCX                             ;0000000140004A54 48 89 08 
MOV RAX, qword ptr SS : [ RSP +  + 0x08 ]                   ;0000000140004A57 48 8B 44 24 08 
RETN                                                        ;0000000140004A5C C3 
INT 3                                                       ;0000000140004A5D CC 
INT 3                                                       ;0000000140004A5E CC 
INT 3                                                       ;0000000140004A5F CC 
MOV qword ptr SS : [ RSP +  + 0x08 ], RCX                   ;0000000140004A60 48 89 4C 24 08 
SUB RSP, 0x28                                               ;0000000140004A65 48 83 EC 28 
MOV RCX, qword ptr SS : [ RSP +  + 0x30 ]                   ;0000000140004A69 48 8B 4C 24 30 
CALL 0x0000006D                                             ;0000000140004A6E E8 6D 00 00 00 
ADD RSP, 0x28                                               ;0000000140004A73 48 83 C4 28 
RETN                                                        ;0000000140004A77 C3 
INT 3                                                       ;0000000140004A78 CC 
INT 3                                                       ;0000000140004A79 CC 
INT 3                                                       ;0000000140004A7A CC 
INT 3                                                       ;0000000140004A7B CC 
INT 3                                                       ;0000000140004A7C CC 
INT 3                                                       ;0000000140004A7D CC 
INT 3                                                       ;0000000140004A7E CC 
INT 3                                                       ;0000000140004A7F CC 
MOV qword ptr SS : [ RSP +  + 0x08 ], RCX                   ;0000000140004A80 48 89 4C 24 08 
SUB RSP, 0x28                                               ;0000000140004A85 48 83 EC 28 
MOV RCX, qword ptr SS : [ RSP +  + 0x30 ]                   ;0000000140004A89 48 8B 4C 24 30 
CALL 0x0000001D                                             ;0000000140004A8E E8 1D 00 00 00 
ADD RSP, 0x28                                               ;0000000140004A93 48 83 C4 28 
RETN                                                        ;0000000140004A97 C3 
INT 3                                                       ;0000000140004A98 CC 
INT 3                                                       ;0000000140004A99 CC 
INT 3                                                       ;0000000140004A9A CC 
INT 3                                                       ;0000000140004A9B CC 
INT 3                                                       ;0000000140004A9C CC 
INT 3                                                       ;0000000140004A9D CC 
INT 3                                                       ;0000000140004A9E CC 
INT 3                                                       ;0000000140004A9F CC 
MOV qword ptr SS : [ RSP +  + 0x08 ], RCX                   ;0000000140004AA0 48 89 4C 24 08 
MOV RAX, qword ptr SS : [ RSP +  + 0x08 ]                   ;0000000140004AA5 48 8B 44 24 08 
MOV RAX, qword ptr DS : [ RAX ]                             ;0000000140004AAA 48 8B 00 
RETN                                                        ;0000000140004AAD C3 
INT 3                                                       ;0000000140004AAE CC 
INT 3                                                       ;0000000140004AAF CC 
MOV qword ptr SS : [ RSP +  + 0x08 ], RCX                   ;0000000140004AB0 48 89 4C 24 08 
SUB RSP, 0x18                                               ;0000000140004AB5 48 83 EC 18 
MOV RAX, qword ptr SS : [ RSP +  + 0x20 ]                   ;0000000140004AB9 48 8B 44 24 20 
CMP qword ptr DS : [ RAX ], 0x00                            ;0000000140004ABE 48 83 38 00 
JZ 0x09                                                     ;0000000140004AC2 74 09 
MOV dword ptr SS : [ RSP +  ], 0x00000001                   ;0000000140004AC4 C7 04 24 01 00 00 00 
JMP 0x07                                                    ;0000000140004ACB EB 07 
MOV dword ptr SS : [ RSP +  ], 0x00000000                   ;0000000140004ACD C7 04 24 00 00 00 00 
MOVZX EAX, byte ptr SS : [ RSP +  ]                         ;0000000140004AD4 0F B6 04 24 
ADD RSP, 0x18                                               ;0000000140004AD8 48 83 C4 18 
RETN                                                        ;0000000140004ADC C3 
INT 3                                                       ;0000000140004ADD CC 
INT 3                                                       ;0000000140004ADE CC 
INT 3                                                       ;0000000140004ADF CC 
MOV qword ptr SS : [ RSP +  + 0x08 ], RCX                   ;0000000140004AE0 48 89 4C 24 08 
SUB RSP, 0x38                                               ;0000000140004AE5 48 83 EC 38 
MOV RAX, qword ptr SS : [ RSP +  + 0x40 ]                   ;0000000140004AE9 48 8B 44 24 40 
MOV RDX, qword ptr DS : [ RAX ]                             ;0000000140004AEE 48 8B 10 
LEA RCX, invalid ptr SS : [ RSP +  + 0x20 ]                 ;0000000140004AF1 48 8D 4C 24 20 
CALL 0xFFFFFF15                                             ;0000000140004AF6 E8 15 FF FF FF 
MOV RAX, qword ptr SS : [ RSP +  + 0x40 ]                   ;0000000140004AFB 48 8B 44 24 40 
MOV qword ptr DS : [ RAX ], 0x00000000                      ;0000000140004B00 48 C7 00 00 00 00 00 
ADD RSP, 0x38                                               ;0000000140004B07 48 83 C4 38 
RETN                                                        ;0000000140004B0B C3 
INT 3                                                       ;0000000140004B0C CC 
INT 3                                                       ;0000000140004B0D CC 
INT 3                                                       ;0000000140004B0E CC 
INT 3                                                       ;0000000140004B0F CC 
MOV qword ptr SS : [ RSP +  + 0x10 ], RDX                   ;0000000140004B10 48 89 54 24 10 
MOV qword ptr SS : [ RSP +  + 0x08 ], RCX                   ;0000000140004B15 48 89 4C 24 08 
SUB RSP, 0x28                                               ;0000000140004B1A 48 83 EC 28 
MOV RAX, qword ptr SS : [ RSP +  + 0x38 ]                   ;0000000140004B1E 48 8B 44 24 38 
CMP qword ptr SS : [ RSP +  + 0x30 ], RAX                   ;0000000140004B23 48 39 44 24 30 
JNZ 0x04                                                    ;0000000140004B28 75 04 
XOR EAX, EAX                                                ;0000000140004B2A 33 C0 
JMP 0x1A                                                    ;0000000140004B2C EB 1A 
MOV RAX, qword ptr SS : [ RSP +  + 0x38 ]                   ;0000000140004B2E 48 8B 44 24 38 
ADD RAX, 0x09                                               ;0000000140004B33 48 83 C0 09 
MOV RCX, qword ptr SS : [ RSP +  + 0x30 ]                   ;0000000140004B37 48 8B 4C 24 30 
ADD RCX, 0x09                                               ;0000000140004B3C 48 83 C1 09 
MOV RDX, RAX                                                ;0000000140004B40 48 8B D0 
CALL 0x00017588                                             ;0000000140004B43 E8 88 75 01 00 
ADD RSP, 0x28                                               ;0000000140004B48 48 83 C4 28 
RETN                                                        ;0000000140004B4C C3 
INT 3                                                       ;0000000140004B4D CC 
INT 3                                                       ;0000000140004B4E CC 
INT 3                                                       ;0000000140004B4F CC 
INT 3                                                       ;0000000140004B50 CC 
INT 3                                                       ;0000000140004B51 CC 
INT 3                                                       ;0000000140004B52 CC 
INT 3                                                       ;0000000140004B53 CC 
INT 3                                                       ;0000000140004B54 CC 
INT 3                                                       ;0000000140004B55 CC 
NOP word ptr DS : [ RAX + RAX * 1 + 0x00000000 ]            ;0000000140004B56 66 66 0F 1F 84 00 00 00 00 00 
MOV qword ptr SS : [ RSP +  + 0x08 ], RCX                   ;0000000140004B60 48 89 4C 24 08 
MOV qword ptr SS : [ RSP +  + 0x18 ], RDX                   ;0000000140004B65 48 89 54 24 18 
MOV dword ptr SS : [ RSP +  + 0x10 ], R8D                   ;0000000140004B6A 44 89 44 24 10 
MOV R9, 0x19930520                                          ;0000000140004B6F 49 C7 C1 20 05 93 19 
JMP 0x08                                                    ;0000000140004B76 EB 08 
INT 3                                                       ;0000000140004B78 CC 
INT 3                                                       ;0000000140004B79 CC 
INT 3                                                       ;0000000140004B7A CC 
INT 3                                                       ;0000000140004B7B CC 
INT 3                                                       ;0000000140004B7C CC 
INT 3                                                       ;0000000140004B7D CC 
NOP                                                         ;0000000140004B7E 66 90 
RETN                                                        ;0000000140004B80 C3 
INT 3                                                       ;0000000140004B81 CC 
INT 3                                                       ;0000000140004B82 CC 
INT 3                                                       ;0000000140004B83 CC 
INT 3                                                       ;0000000140004B84 CC 
INT 3                                                       ;0000000140004B85 CC 
INT 3                                                       ;0000000140004B86 CC 
NOP word ptr DS : [ RAX + RAX * 1 + 0x00000000 ]            ;0000000140004B87 66 0F 1F 84 00 00 00 00 00 
RETN                                                        ;0000000140004B90 C3 
INT 3                                                       ;0000000140004B91 CC 
INT 3                                                       ;0000000140004B92 CC 
INT 3                                                       ;0000000140004B93 CC 
INT 3                                                       ;0000000140004B94 CC 
INT 3                                                       ;0000000140004B95 CC 
INT 3                                                       ;0000000140004B96 CC 
INT 3                                                       ;0000000140004B97 CC 
INT 3                                                       ;0000000140004B98 CC 
INT 3                                                       ;0000000140004B99 CC 
INT 3                                                       ;0000000140004B9A CC 
INT 3                                                       ;0000000140004B9B CC 
INT 3                                                       ;0000000140004B9C CC 
INT 3                                                       ;0000000140004B9D CC 
INT 3                                                       ;0000000140004B9E CC 
INT 3                                                       ;0000000140004B9F CC 
MOV qword ptr SS : [ RSP +  + 0x08 ], RCX                   ;0000000140004BA0 48 89 4C 24 08 
SUB RSP, 0x38                                               ;0000000140004BA5 48 83 EC 38 
CALL 0xFFFFF5C2                                             ;0000000140004BA9 E8 C2 F5 FF FF 
TEST EAX, EAX                                               ;0000000140004BAE 85 C0 
JZ 0x42                                                     ;0000000140004BB0 74 42 
CALL 0xFFFFEB99                                             ;0000000140004BB2 E8 99 EB FF FF 
MOV qword ptr SS : [ RSP +  + 0x20 ], RAX                   ;0000000140004BB7 48 89 44 24 20 
MOV RAX, qword ptr SS : [ RSP +  + 0x40 ]                   ;0000000140004BBC 48 8B 44 24 40 
MOV RAX, qword ptr DS : [ RAX + 0x00000098 ]                ;0000000140004BC1 48 8B 80 98 00 00 00 
MOV qword ptr SS : [ RSP +  + 0x28 ], RAX                   ;0000000140004BC8 48 89 44 24 28 
MOV RAX, qword ptr SS : [ RSP +  + 0x20 ]                   ;0000000140004BCD 48 8B 44 24 20 
MOV RAX, qword ptr DS : [ RAX + 0x10 ]                      ;0000000140004BD2 48 8B 40 10 
CMP qword ptr SS : [ RSP +  + 0x28 ], RAX                   ;0000000140004BD6 48 39 44 24 28 
JB 0x10                                                     ;0000000140004BDB 72 10 
MOV RAX, qword ptr SS : [ RSP +  + 0x20 ]                   ;0000000140004BDD 48 8B 44 24 20 
MOV RAX, qword ptr DS : [ RAX + 0x08 ]                      ;0000000140004BE2 48 8B 40 08 
CMP qword ptr SS : [ RSP +  + 0x28 ], RAX                   ;0000000140004BE6 48 39 44 24 28 
JBE 0x07                                                    ;0000000140004BEB 76 07 
MOV ECX, 0x0000000D                                         ;0000000140004BED B9 0D 00 00 00 
INT 0x29                                                    ;0000000140004BF2 CD 29 
ADD RSP, 0x38                                               ;0000000140004BF4 48 83 C4 38 
RETN                                                        ;0000000140004BF8 C3 
INT 3                                                       ;0000000140004BF9 CC 
INT 3                                                       ;0000000140004BFA CC 
INT 3                                                       ;0000000140004BFB CC 
INT 3                                                       ;0000000140004BFC CC 
INT 3                                                       ;0000000140004BFD CC 
INT 3                                                       ;0000000140004BFE CC 
INT 3                                                       ;0000000140004BFF CC 
MOV byte ptr SS : [ RSP +  + 0x10 ], DL                     ;0000000140004C00 88 54 24 10 
MOV qword ptr SS : [ RSP +  + 0x08 ], RCX                   ;0000000140004C04 48 89 4C 24 08 
SUB RSP, 0x48                                               ;0000000140004C09 48 83 EC 48 
CMP qword ptr SS : [ RSP +  + 0x50 ], 0x00                  ;0000000140004C0D 48 83 7C 24 50 00 
JZ 0x42                                                     ;0000000140004C13 74 42 
MOV RAX, qword ptr SS : [ RSP +  + 0x50 ]                   ;0000000140004C15 48 8B 44 24 50 
CMP dword ptr DS : [ RAX ], 0xE06D7363                      ;0000000140004C1A 81 38 63 73 6D E0 
JNZ 0x35                                                    ;0000000140004C20 75 35 
MOV RAX, qword ptr SS : [ RSP +  + 0x50 ]                   ;0000000140004C22 48 8B 44 24 50 
CMP dword ptr DS : [ RAX + 0x18 ], 0x04                     ;0000000140004C27 83 78 18 04 
JNZ 0x2A                                                    ;0000000140004C2B 75 2A 
MOV RAX, qword ptr SS : [ RSP +  + 0x50 ]                   ;0000000140004C2D 48 8B 44 24 50 
CMP dword ptr DS : [ RAX + 0x20 ], 0x19930520               ;0000000140004C32 81 78 20 20 05 93 19 
JZ 0x21                                                     ;0000000140004C39 74 21 
MOV RAX, qword ptr SS : [ RSP +  + 0x50 ]                   ;0000000140004C3B 48 8B 44 24 50 
CMP dword ptr DS : [ RAX + 0x20 ], 0x19930521               ;0000000140004C40 81 78 20 21 05 93 19 
JZ 0x13                                                     ;0000000140004C47 74 13 
MOV RAX, qword ptr SS : [ RSP +  + 0x50 ]                   ;0000000140004C49 48 8B 44 24 50 
CMP dword ptr DS : [ RAX + 0x20 ], 0x19930522               ;0000000140004C4E 81 78 20 22 05 93 19 
JZ 0x05                                                     ;0000000140004C55 74 05 
JMP 0x0000009C                                              ;0000000140004C57 E9 9C 00 00 00 
MOV RAX, qword ptr SS : [ RSP +  + 0x50 ]                   ;0000000140004C5C 48 8B 44 24 50 
CMP qword ptr DS : [ RAX + 0x30 ], 0x00                     ;0000000140004C61 48 83 78 30 00 
JZ 0x0000008C                                               ;0000000140004C66 0F 84 8C 00 00 00 
MOV RAX, qword ptr SS : [ RSP +  + 0x50 ]                   ;0000000140004C6C 48 8B 44 24 50 
MOV RAX, qword ptr DS : [ RAX + 0x30 ]                      ;0000000140004C71 48 8B 40 30 
CMP dword ptr DS : [ RAX + 0x04 ], 0x00                     ;0000000140004C75 83 78 04 00 
JZ 0x31                                                     ;0000000140004C79 74 31 
MOV RAX, qword ptr SS : [ RSP +  + 0x50 ]                   ;0000000140004C7B 48 8B 44 24 50 
MOV RAX, qword ptr DS : [ RAX + 0x30 ]                      ;0000000140004C80 48 8B 40 30 
MOVSXD RAX, dword ptr DS : [ RAX + 0x04 ]                   ;0000000140004C84 48 63 40 04 
MOV RCX, qword ptr SS : [ RSP +  + 0x50 ]                   ;0000000140004C88 48 8B 4C 24 50 
ADD RAX, qword ptr DS : [ RCX + 0x38 ]                      ;0000000140004C8D 48 03 41 38 
MOV RDX, RAX                                                ;0000000140004C91 48 8B D0 
MOV RAX, qword ptr SS : [ RSP +  + 0x50 ]                   ;0000000140004C94 48 8B 44 24 50 
MOV RCX, qword ptr DS : [ RAX + 0x28 ]                      ;0000000140004C99 48 8B 48 28 
CALL 0x0000005E                                             ;0000000140004C9D E8 5E 00 00 00 
JMP 0x06                                                    ;0000000140004CA2 EB 06 
CALL 0x00014257                                             ;0000000140004CA4 E8 57 42 01 00 
NOP                                                         ;0000000140004CA9 90 
JMP 0x4C                                                    ;0000000140004CAA EB 4C 
MOV RAX, qword ptr SS : [ RSP +  + 0x50 ]                   ;0000000140004CAC 48 8B 44 24 50 
MOV RAX, qword ptr DS : [ RAX + 0x30 ]                      ;0000000140004CB1 48 8B 40 30 
MOV EAX, dword ptr DS : [ RAX ]                             ;0000000140004CB5 8B 00 
AND EAX, 0x10                                               ;0000000140004CB7 83 E0 10 
TEST EAX, EAX                                               ;0000000140004CBA 85 C0 
JZ 0x3A                                                     ;0000000140004CBC 74 3A 
MOV RAX, qword ptr SS : [ RSP +  + 0x50 ]                   ;0000000140004CBE 48 8B 44 24 50 
MOV RAX, qword ptr DS : [ RAX + 0x28 ]                      ;0000000140004CC3 48 8B 40 28 
MOV RAX, qword ptr DS : [ RAX ]                             ;0000000140004CC7 48 8B 00 
MOV qword ptr SS : [ RSP +  + 0x28 ], RAX                   ;0000000140004CCA 48 89 44 24 28 
CMP qword ptr SS : [ RSP +  + 0x28 ], 0x00                  ;0000000140004CCF 48 83 7C 24 28 00 
JZ 0x21                                                     ;0000000140004CD5 74 21 
MOV RAX, qword ptr SS : [ RSP +  + 0x28 ]                   ;0000000140004CD7 48 8B 44 24 28 
MOV RAX, qword ptr DS : [ RAX ]                             ;0000000140004CDC 48 8B 00 
MOV RAX, qword ptr DS : [ RAX + 0x10 ]                      ;0000000140004CDF 48 8B 40 10 
MOV qword ptr SS : [ RSP +  + 0x30 ], RAX                   ;0000000140004CE3 48 89 44 24 30 
MOV RCX, qword ptr SS : [ RSP +  + 0x28 ]                   ;0000000140004CE8 48 8B 4C 24 28 
MOV RAX, qword ptr SS : [ RSP +  + 0x30 ]                   ;0000000140004CED 48 8B 44 24 30 
CALL CS : [ RIP + 0x00040578 ]                              ;0000000140004CF2 FF 15 78 05 04 00 
ADD RSP, 0x48                                               ;0000000140004CF8 48 83 C4 48 
RETN                                                        ;0000000140004CFC C3 
INT 3                                                       ;0000000140004CFD CC 
INT 3                                                       ;0000000140004CFE CC 
INT 3                                                       ;0000000140004CFF CC 
MOV qword ptr SS : [ RSP +  + 0x10 ], RDX                   ;0000000140004D00 48 89 54 24 10 
MOV qword ptr SS : [ RSP +  + 0x08 ], RCX                   ;0000000140004D05 48 89 4C 24 08 
SUB RSP, 0x38                                               ;0000000140004D0A 48 83 EC 38 
MOV RAX, qword ptr SS : [ RSP +  + 0x48 ]                   ;0000000140004D0E 48 8B 44 24 48 
MOV qword ptr SS : [ RSP +  + 0x20 ], RAX                   ;0000000140004D13 48 89 44 24 20 
MOV RCX, qword ptr SS : [ RSP +  + 0x40 ]                   ;0000000140004D18 48 8B 4C 24 40 
CALL qword ptr SS : [ RSP +  + 0x20 ]                       ;0000000140004D1D FF 54 24 20 
ADD RSP, 0x38                                               ;0000000140004D21 48 83 C4 38 
RETN                                                        ;0000000140004D25 C3 
INT 3                                                       ;0000000140004D26 CC 
INT 3                                                       ;0000000140004D27 CC 
INT 3                                                       ;0000000140004D28 CC 
INT 3                                                       ;0000000140004D29 CC 
INT 3                                                       ;0000000140004D2A CC 
INT 3                                                       ;0000000140004D2B CC 
INT 3                                                       ;0000000140004D2C CC 
INT 3                                                       ;0000000140004D2D CC 
INT 3                                                       ;0000000140004D2E CC 
INT 3                                                       ;0000000140004D2F CC 
MOV qword ptr SS : [ RSP +  + 0x08 ], RCX                   ;0000000140004D30 48 89 4C 24 08 
SUB RSP, 0x38                                               ;0000000140004D35 48 83 EC 38 
CALL 0x00000252                                             ;0000000140004D39 E8 52 02 00 00 
MOV RAX, qword ptr DS : [ RAX + 0x58 ]                      ;0000000140004D3E 48 8B 40 58 
MOV qword ptr SS : [ RSP +  + 0x20 ], RAX                   ;0000000140004D42 48 89 44 24 20 
JMP 0x0E                                                    ;0000000140004D47 EB 0E 
MOV RAX, qword ptr SS : [ RSP +  + 0x20 ]                   ;0000000140004D49 48 8B 44 24 20 
MOV RAX, qword ptr DS : [ RAX + 0x08 ]                      ;0000000140004D4E 48 8B 40 08 
MOV qword ptr SS : [ RSP +  + 0x20 ], RAX                   ;0000000140004D52 48 89 44 24 20 
CMP qword ptr SS : [ RSP +  + 0x20 ], 0x00                  ;0000000140004D57 48 83 7C 24 20 00 
JZ 0x15                                                     ;0000000140004D5D 74 15 
MOV RAX, qword ptr SS : [ RSP +  + 0x20 ]                   ;0000000140004D5F 48 8B 44 24 20 
MOV RCX, qword ptr SS : [ RSP +  + 0x40 ]                   ;0000000140004D64 48 8B 4C 24 40 
CMP qword ptr DS : [ RAX ], RCX                             ;0000000140004D69 48 39 08 
JNZ 0x04                                                    ;0000000140004D6C 75 04 
XOR EAX, EAX                                                ;0000000140004D6E 33 C0 
JMP 0x07                                                    ;0000000140004D70 EB 07 
JMP 0xD5                                                    ;0000000140004D72 EB D5 
MOV EAX, 0x00000001                                         ;0000000140004D74 B8 01 00 00 00 
ADD RSP, 0x38                                               ;0000000140004D79 48 83 C4 38 
RETN                                                        ;0000000140004D7D C3 
INT 3                                                       ;0000000140004D7E CC 
INT 3                                                       ;0000000140004D7F CC 
MOV qword ptr SS : [ RSP +  + 0x10 ], RDX                   ;0000000140004D80 48 89 54 24 10 
MOV qword ptr SS : [ RSP +  + 0x08 ], RCX                   ;0000000140004D85 48 89 4C 24 08 
SUB RSP, 0x18                                               ;0000000140004D8A 48 83 EC 18 
MOV RAX, qword ptr SS : [ RSP +  + 0x28 ]                   ;0000000140004D8E 48 8B 44 24 28 
MOVSXD RAX, dword ptr DS : [ RAX ]                          ;0000000140004D93 48 63 00 
MOV RCX, qword ptr SS : [ RSP +  + 0x20 ]                   ;0000000140004D96 48 8B 4C 24 20 
ADD RCX, RAX                                                ;0000000140004D9B 48 03 C8 
MOV RAX, RCX                                                ;0000000140004D9E 48 8B C1 
MOV qword ptr SS : [ RSP +  ], RAX                          ;0000000140004DA1 48 89 04 24 
MOV RAX, qword ptr SS : [ RSP +  + 0x28 ]                   ;0000000140004DA5 48 8B 44 24 28 
CMP dword ptr DS : [ RAX + 0x04 ], 0x00                     ;0000000140004DAA 83 78 04 00 
JL 0x44                                                     ;0000000140004DAE 7C 44 
MOV RAX, qword ptr SS : [ RSP +  + 0x28 ]                   ;0000000140004DB0 48 8B 44 24 28 
MOVSXD RAX, dword ptr DS : [ RAX + 0x04 ]                   ;0000000140004DB5 48 63 40 04 
MOV RCX, qword ptr SS : [ RSP +  + 0x28 ]                   ;0000000140004DB9 48 8B 4C 24 28 
MOVSXD RCX, dword ptr DS : [ RCX + 0x08 ]                   ;0000000140004DBE 48 63 49 08 
MOV RDX, qword ptr SS : [ RSP +  + 0x20 ]                   ;0000000140004DC2 48 8B 54 24 20 
MOV RAX, qword ptr DS : [ RDX + RAX * 1 ]                   ;0000000140004DC7 48 8B 04 02 
MOVSXD RAX, dword ptr DS : [ RAX + RCX * 1 ]                ;0000000140004DCB 48 63 04 08 
MOV RCX, qword ptr SS : [ RSP +  ]                          ;0000000140004DCF 48 8B 0C 24 
ADD RCX, RAX                                                ;0000000140004DD3 48 03 C8 
MOV RAX, RCX                                                ;0000000140004DD6 48 8B C1 
MOV qword ptr SS : [ RSP +  ], RAX                          ;0000000140004DD9 48 89 04 24 
MOV RAX, qword ptr SS : [ RSP +  + 0x28 ]                   ;0000000140004DDD 48 8B 44 24 28 
MOVSXD RAX, dword ptr DS : [ RAX + 0x04 ]                   ;0000000140004DE2 48 63 40 04 
MOV RCX, qword ptr SS : [ RSP +  ]                          ;0000000140004DE6 48 8B 0C 24 
ADD RCX, RAX                                                ;0000000140004DEA 48 03 C8 
MOV RAX, RCX                                                ;0000000140004DED 48 8B C1 
MOV qword ptr SS : [ RSP +  ], RAX                          ;0000000140004DF0 48 89 04 24 
MOV RAX, qword ptr SS : [ RSP +  ]                          ;0000000140004DF4 48 8B 04 24 
ADD RSP, 0x18                                               ;0000000140004DF8 48 83 C4 18 
RETN                                                        ;0000000140004DFC C3 
INT 3                                                       ;0000000140004DFD CC 
INT 3                                                       ;0000000140004DFE CC 
INT 3                                                       ;0000000140004DFF CC 
MOV qword ptr SS : [ RSP +  + 0x08 ], RCX                   ;0000000140004E00 48 89 4C 24 08 
SUB RSP, 0x48                                               ;0000000140004E05 48 83 EC 48 
MOV RAX, qword ptr SS : [ RSP +  + 0x50 ]                   ;0000000140004E09 48 8B 44 24 50 
MOV RAX, qword ptr DS : [ RAX ]                             ;0000000140004E0E 48 8B 00 
MOV qword ptr SS : [ RSP +  + 0x30 ], RAX                   ;0000000140004E11 48 89 44 24 30 
MOV RAX, qword ptr SS : [ RSP +  + 0x30 ]                   ;0000000140004E16 48 8B 44 24 30 
MOV EAX, dword ptr DS : [ RAX ]                             ;0000000140004E1B 8B 00 
MOV dword ptr SS : [ RSP +  + 0x20 ], EAX                   ;0000000140004E1D 89 44 24 20 
CMP dword ptr SS : [ RSP +  + 0x20 ], 0xE0434352            ;0000000140004E21 81 7C 24 20 52 43 43 E0 
JZ 0x27                                                     ;0000000140004E29 74 27 
CMP dword ptr SS : [ RSP +  + 0x20 ], 0xE0434F4D            ;0000000140004E2B 81 7C 24 20 4D 4F 43 E0 
JZ 0x1D                                                     ;0000000140004E33 74 1D 
CMP dword ptr SS : [ RSP +  + 0x20 ], 0xE06D7363            ;0000000140004E35 81 7C 24 20 63 73 6D E0 
JZ 0x02                                                     ;0000000140004E3D 74 02 
JMP 0x3E                                                    ;0000000140004E3F EB 3E 
CALL 0x0000014A                                             ;0000000140004E41 E8 4A 01 00 00 
MOV dword ptr DS : [ RAX + 0x30 ], 0x00000000               ;0000000140004E46 C7 40 30 00 00 00 00 
CALL 0x000140AE                                             ;0000000140004E4D E8 AE 40 01 00 
CALL 0x00000139                                             ;0000000140004E52 E8 39 01 00 00 
CMP dword ptr DS : [ RAX + 0x30 ], 0x00                     ;0000000140004E57 83 78 30 00 
JLE 0x1E                                                    ;0000000140004E5B 7E 1E 
CALL 0x0000012E                                             ;0000000140004E5D E8 2E 01 00 00 
ADD RAX, 0x30                                               ;0000000140004E62 48 83 C0 30 
MOV qword ptr SS : [ RSP +  + 0x28 ], RAX                   ;0000000140004E66 48 89 44 24 28 
MOV RAX, qword ptr SS : [ RSP +  + 0x28 ]                   ;0000000140004E6B 48 8B 44 24 28 
MOV EAX, dword ptr DS : [ RAX ]                             ;0000000140004E70 8B 00 
DEC EAX                                                     ;0000000140004E72 FF C8 
MOV RCX, qword ptr SS : [ RSP +  + 0x28 ]                   ;0000000140004E74 48 8B 4C 24 28 
MOV dword ptr DS : [ RCX ], EAX                             ;0000000140004E79 89 01 
XOR EAX, EAX                                                ;0000000140004E7B 33 C0 
JMP 0x02                                                    ;0000000140004E7D EB 02 
XOR EAX, EAX                                                ;0000000140004E7F 33 C0 
ADD RSP, 0x48                                               ;0000000140004E81 48 83 C4 48 
RETN                                                        ;0000000140004E85 C3 
INT 3                                                       ;0000000140004E86 CC 
INT 3                                                       ;0000000140004E87 CC 
INT 3                                                       ;0000000140004E88 CC 
INT 3                                                       ;0000000140004E89 CC 
INT 3                                                       ;0000000140004E8A CC 
INT 3                                                       ;0000000140004E8B CC 
INT 3                                                       ;0000000140004E8C CC 
INT 3                                                       ;0000000140004E8D CC 
INT 3                                                       ;0000000140004E8E CC 
INT 3                                                       ;0000000140004E8F CC 
MOV qword ptr SS : [ RSP +  + 0x08 ], RCX                   ;0000000140004E90 48 89 4C 24 08 
SUB RSP, 0x28                                               ;0000000140004E95 48 83 EC 28 
CALL CS : [ RIP + 0x000401F1 ]                              ;0000000140004E99 FF 15 F1 01 04 00 
MOV RCX, qword ptr SS : [ RSP +  + 0x30 ]                   ;0000000140004E9F 48 8B 4C 24 30 
MOV dword ptr DS : [ RCX ], EAX                             ;0000000140004EA4 89 01 
MOV RAX, qword ptr SS : [ RSP +  + 0x30 ]                   ;0000000140004EA6 48 8B 44 24 30 
ADD RSP, 0x28                                               ;0000000140004EAB 48 83 C4 28 
RETN                                                        ;0000000140004EAF C3 
MOV qword ptr SS : [ RSP +  + 0x08 ], RCX                   ;0000000140004EB0 48 89 4C 24 08 
SUB RSP, 0x28                                               ;0000000140004EB5 48 83 EC 28 
MOV RAX, qword ptr SS : [ RSP +  + 0x30 ]                   ;0000000140004EB9 48 8B 44 24 30 
MOV ECX, dword ptr DS : [ RAX ]                             ;0000000140004EBE 8B 08 
CALL CS : [ RIP + 0x000401D2 ]                              ;0000000140004EC0 FF 15 D2 01 04 00 
ADD RSP, 0x28                                               ;0000000140004EC6 48 83 C4 28 
RETN                                                        ;0000000140004ECA C3 
INT 3                                                       ;0000000140004ECB CC 
INT 3                                                       ;0000000140004ECC CC 
INT 3                                                       ;0000000140004ECD CC 
INT 3                                                       ;0000000140004ECE CC 
INT 3                                                       ;0000000140004ECF CC 
MOV qword ptr SS : [ RSP +  + 0x08 ], RCX                   ;0000000140004ED0 48 89 4C 24 08 
SUB RSP, 0x18                                               ;0000000140004ED5 48 83 EC 18 
MOV RAX, qword ptr SS : [ RSP +  + 0x20 ]                   ;0000000140004ED9 48 8B 44 24 20 
MOV RAX, qword ptr DS : [ RAX ]                             ;0000000140004EDE 48 8B 00 
MOV qword ptr SS : [ RSP +  ], RAX                          ;0000000140004EE1 48 89 04 24 
MOV RAX, qword ptr SS : [ RSP +  + 0x20 ]                   ;0000000140004EE5 48 8B 44 24 20 
MOV qword ptr DS : [ RAX ], 0x00000000                      ;0000000140004EEA 48 C7 00 00 00 00 00 
MOV RAX, qword ptr SS : [ RSP +  ]                          ;0000000140004EF1 48 8B 04 24 
ADD RSP, 0x18                                               ;0000000140004EF5 48 83 C4 18 
RETN                                                        ;0000000140004EF9 C3 
INT 3                                                       ;0000000140004EFA CC 
INT 3                                                       ;0000000140004EFB CC 
INT 3                                                       ;0000000140004EFC CC 
INT 3                                                       ;0000000140004EFD CC 
INT 3                                                       ;0000000140004EFE CC 
INT 3                                                       ;0000000140004EFF CC 
MOV qword ptr SS : [ RSP +  + 0x08 ], RCX                   ;0000000140004F00 48 89 4C 24 08 
SUB RSP, 0x28                                               ;0000000140004F05 48 83 EC 28 
MOV RDX, qword ptr SS : [ RSP +  + 0x30 ]                   ;0000000140004F09 48 8B 54 24 30 
MOV ECX, CS : [ RIP + 0x0005511C ]                          ;0000000140004F0E 8B 0D 1C 51 05 00 
CALL 0x00000A27                                             ;0000000140004F14 E8 27 0A 00 00 
TEST EAX, EAX                                               ;0000000140004F19 85 C0 
JNZ 0x04                                                    ;0000000140004F1B 75 04 
XOR AL, AL                                                  ;0000000140004F1D 32 C0 
JMP 0x1E                                                    ;0000000140004F1F EB 1E 
MOV RAX, qword ptr SS : [ RSP +  + 0x30 ]                   ;0000000140004F21 48 8B 44 24 30 
MOV dword ptr DS : [ RAX + 0x78 ], 0xFFFFFFFE               ;0000000140004F26 C7 40 78 FE FF FF FF 
MOV RAX, qword ptr SS : [ RSP +  + 0x30 ]                   ;0000000140004F2D 48 8B 44 24 30 
MOV qword ptr DS : [ RAX + 0x00000080 ], 0xFFFFFFFE         ;0000000140004F32 48 C7 80 80 00 00 00 FE FF FF FF 
MOV AL, 0x01                                                ;0000000140004F3D B0 01 
ADD RSP, 0x28                                               ;0000000140004F3F 48 83 C4 28 
RETN                                                        ;0000000140004F43 C3 
INT 3                                                       ;0000000140004F44 CC 
INT 3                                                       ;0000000140004F45 CC 
INT 3                                                       ;0000000140004F46 CC 
INT 3                                                       ;0000000140004F47 CC 
INT 3                                                       ;0000000140004F48 CC 
INT 3                                                       ;0000000140004F49 CC 
INT 3                                                       ;0000000140004F4A CC 
INT 3                                                       ;0000000140004F4B CC 
INT 3                                                       ;0000000140004F4C CC 
INT 3                                                       ;0000000140004F4D CC 
INT 3                                                       ;0000000140004F4E CC 
INT 3                                                       ;0000000140004F4F CC 
MOV qword ptr SS : [ RSP +  + 0x08 ], RCX                   ;0000000140004F50 48 89 4C 24 08 
SUB RSP, 0x28                                               ;0000000140004F55 48 83 EC 28 
CMP qword ptr SS : [ RSP +  + 0x30 ], 0x00                  ;0000000140004F59 48 83 7C 24 30 00 
JZ 0x0E                                                     ;0000000140004F5F 74 0E 
LEA RAX, CS : [ RIP + 0x00056188 ]                          ;0000000140004F61 48 8D 05 88 61 05 00 
CMP qword ptr SS : [ RSP +  + 0x30 ], RAX                   ;0000000140004F68 48 39 44 24 30 
JNZ 0x02                                                    ;0000000140004F6D 75 02 
JMP 0x0F                                                    ;0000000140004F6F EB 0F 
MOV EDX, 0x00000002                                         ;0000000140004F71 BA 02 00 00 00 
MOV RCX, qword ptr SS : [ RSP +  + 0x30 ]                   ;0000000140004F76 48 8B 4C 24 30 
CALL 0x000167C0                                             ;0000000140004F7B E8 C0 67 01 00 
ADD RSP, 0x28                                               ;0000000140004F80 48 83 C4 28 
RETN                                                        ;0000000140004F84 C3 
INT 3                                                       ;0000000140004F85 CC 
INT 3                                                       ;0000000140004F86 CC 
INT 3                                                       ;0000000140004F87 CC 
INT 3                                                       ;0000000140004F88 CC 
INT 3                                                       ;0000000140004F89 CC 
INT 3                                                       ;0000000140004F8A CC 
INT 3                                                       ;0000000140004F8B CC 
INT 3                                                       ;0000000140004F8C CC 
INT 3                                                       ;0000000140004F8D CC 
INT 3                                                       ;0000000140004F8E CC 
INT 3                                                       ;0000000140004F8F CC 
SUB RSP, 0x38                                               ;0000000140004F90 48 83 EC 38 
CALL 0x00000027                                             ;0000000140004F94 E8 27 00 00 00 
MOV qword ptr SS : [ RSP +  + 0x20 ], RAX                   ;0000000140004F99 48 89 44 24 20 
CMP qword ptr SS : [ RSP +  + 0x20 ], 0x00                  ;0000000140004F9E 48 83 7C 24 20 00 
JNZ 0x05                                                    ;0000000140004FA4 75 05 
CALL 0x00017255                                             ;0000000140004FA6 E8 55 72 01 00 
MOV RAX, qword ptr SS : [ RSP +  + 0x20 ]                   ;0000000140004FAB 48 8B 44 24 20 
ADD RSP, 0x38                                               ;0000000140004FB0 48 83 C4 38 
RETN                                                        ;0000000140004FB4 C3 
INT 3                                                       ;0000000140004FB5 CC 
INT 3                                                       ;0000000140004FB6 CC 
INT 3                                                       ;0000000140004FB7 CC 
INT 3                                                       ;0000000140004FB8 CC 
INT 3                                                       ;0000000140004FB9 CC 
INT 3                                                       ;0000000140004FBA CC 
INT 3                                                       ;0000000140004FBB CC 
INT 3                                                       ;0000000140004FBC CC 
INT 3                                                       ;0000000140004FBD CC 
INT 3                                                       ;0000000140004FBE CC 
INT 3                                                       ;0000000140004FBF CC 
SUB RSP, 0x00000088                                         ;0000000140004FC0 48 81 EC 88 00 00 00 
CMP CS : [ RIP + 0x00055062 ], 0xFF                         ;0000000140004FC7 83 3D 62 50 05 00 FF 
JNZ 0x07                                                    ;0000000140004FCE 75 07 
XOR EAX, EAX                                                ;0000000140004FD0 33 C0 
JMP 0x0000017F                                              ;0000000140004FD2 E9 7F 01 00 00 
LEA RCX, invalid ptr SS : [ RSP +  + 0x30 ]                 ;0000000140004FD7 48 8D 4C 24 30 
CALL 0xFFFFFEAF                                             ;0000000140004FDC E8 AF FE FF FF 
MOV ECX, CS : [ RIP + 0x00055049 ]                          ;0000000140004FE1 8B 0D 49 50 05 00 
CALL 0x00000904                                             ;0000000140004FE7 E8 04 09 00 00 
MOV qword ptr SS : [ RSP +  + 0x40 ], RAX                   ;0000000140004FEC 48 89 44 24 40 
CMP qword ptr SS : [ RSP +  + 0x40 ], 0xFF                  ;0000000140004FF1 48 83 7C 24 40 FF 
JNZ 0x1F                                                    ;0000000140004FF7 75 1F 
MOV qword ptr SS : [ RSP +  + 0x48 ], 0x00000000            ;0000000140004FF9 48 C7 44 24 48 00 00 00 00 
LEA RCX, invalid ptr SS : [ RSP +  + 0x30 ]                 ;0000000140005002 48 8D 4C 24 30 
CALL 0xFFFFFEA4                                             ;0000000140005007 E8 A4 FE FF FF 
MOV RAX, qword ptr SS : [ RSP +  + 0x48 ]                   ;000000014000500C 48 8B 44 24 48 
JMP 0x00000140                                              ;0000000140005011 E9 40 01 00 00 
JMP 0x26                                                    ;0000000140005016 EB 26 
CMP qword ptr SS : [ RSP +  + 0x40 ], 0x00                  ;0000000140005018 48 83 7C 24 40 00 
JZ 0x1E                                                     ;000000014000501E 74 1E 
MOV RAX, qword ptr SS : [ RSP +  + 0x40 ]                   ;0000000140005020 48 8B 44 24 40 
MOV qword ptr SS : [ RSP +  + 0x50 ], RAX                   ;0000000140005025 48 89 44 24 50 
LEA RCX, invalid ptr SS : [ RSP +  + 0x30 ]                 ;000000014000502A 48 8D 4C 24 30 
CALL 0xFFFFFE7C                                             ;000000014000502F E8 7C FE FF FF 
MOV RAX, qword ptr SS : [ RSP +  + 0x50 ]                   ;0000000140005034 48 8B 44 24 50 
JMP 0x00000118                                              ;0000000140005039 E9 18 01 00 00 
MOV RDX, 0xFFFFFFFF                                         ;000000014000503E 48 C7 C2 FF FF FF FF 
MOV ECX, CS : [ RIP + 0x00054FE5 ]                          ;0000000140005045 8B 0D E5 4F 05 00 
CALL 0x000008F0                                             ;000000014000504B E8 F0 08 00 00 
TEST EAX, EAX                                               ;0000000140005050 85 C0 
JNZ 0x1D                                                    ;0000000140005052 75 1D 
MOV qword ptr SS : [ RSP +  + 0x58 ], 0x00000000            ;0000000140005054 48 C7 44 24 58 00 00 00 00 
LEA RCX, invalid ptr SS : [ RSP +  + 0x30 ]                 ;000000014000505D 48 8D 4C 24 30 
CALL 0xFFFFFE49                                             ;0000000140005062 E8 49 FE FF FF 
MOV RAX, qword ptr SS : [ RSP +  + 0x58 ]                   ;0000000140005067 48 8B 44 24 58 
JMP 0x000000E5                                              ;000000014000506C E9 E5 00 00 00 
MOV dword ptr SS : [ RSP +  + 0x20 ], 0x00000082            ;0000000140005071 C7 44 24 20 82 00 00 00 
LEA R9, CS : [ RIP + 0x00040308 ]                           ;0000000140005079 4C 8D 0D 08 03 04 00 
MOV R8D, 0x00000002                                         ;0000000140005080 41 B8 02 00 00 00 
MOV EDX, 0x00000090                                         ;0000000140005086 BA 90 00 00 00 
MOV ECX, 0x00000001                                         ;000000014000508B B9 01 00 00 00 
CALL 0x000165DB                                             ;0000000140005090 E8 DB 65 01 00 
MOV RDX, RAX                                                ;0000000140005095 48 8B D0 
LEA RCX, invalid ptr SS : [ RSP +  + 0x38 ]                 ;0000000140005098 48 8D 4C 24 38 
CALL 0xFFFFF99E                                             ;000000014000509D E8 9E F9 FF FF 
LEA RCX, invalid ptr SS : [ RSP +  + 0x38 ]                 ;00000001400050A2 48 8D 4C 24 38 
CALL 0xFFFFF9D4                                             ;00000001400050A7 E8 D4 F9 FF FF 
MOVZX EAX, AL                                               ;00000001400050AC 0F B6 C0 
TEST EAX, EAX                                               ;00000001400050AF 85 C0 
JNZ 0x31                                                    ;00000001400050B1 75 31 
XOR EDX, EDX                                                ;00000001400050B3 33 D2 
MOV ECX, CS : [ RIP + 0x00054F75 ]                          ;00000001400050B5 8B 0D 75 4F 05 00 
CALL 0x00000880                                             ;00000001400050BB E8 80 08 00 00 
MOV qword ptr SS : [ RSP +  + 0x60 ], 0x00000000            ;00000001400050C0 48 C7 44 24 60 00 00 00 00 
LEA RCX, invalid ptr SS : [ RSP +  + 0x38 ]                 ;00000001400050C9 48 8D 4C 24 38 
CALL 0xFFFFF98D                                             ;00000001400050CE E8 8D F9 FF FF 
LEA RCX, invalid ptr SS : [ RSP +  + 0x30 ]                 ;00000001400050D3 48 8D 4C 24 30 
CALL 0xFFFFFDD3                                             ;00000001400050D8 E8 D3 FD FF FF 
MOV RAX, qword ptr SS : [ RSP +  + 0x60 ]                   ;00000001400050DD 48 8B 44 24 60 
JMP 0x72                                                    ;00000001400050E2 EB 72 
LEA RCX, invalid ptr SS : [ RSP +  + 0x38 ]                 ;00000001400050E4 48 8D 4C 24 38 
CALL 0xFFFFF9B2                                             ;00000001400050E9 E8 B2 F9 FF FF 
MOV RCX, RAX                                                ;00000001400050EE 48 8B C8 
CALL 0xFFFFFE0A                                             ;00000001400050F1 E8 0A FE FF FF 
MOVZX EAX, AL                                               ;00000001400050F6 0F B6 C0 
TEST EAX, EAX                                               ;00000001400050F9 85 C0 
JNZ 0x31                                                    ;00000001400050FB 75 31 
XOR EDX, EDX                                                ;00000001400050FD 33 D2 
MOV ECX, CS : [ RIP + 0x00054F2B ]                          ;00000001400050FF 8B 0D 2B 4F 05 00 
CALL 0x00000836                                             ;0000000140005105 E8 36 08 00 00 
MOV qword ptr SS : [ RSP +  + 0x68 ], 0x00000000            ;000000014000510A 48 C7 44 24 68 00 00 00 00 
LEA RCX, invalid ptr SS : [ RSP +  + 0x38 ]                 ;0000000140005113 48 8D 4C 24 38 
CALL 0xFFFFF943                                             ;0000000140005118 E8 43 F9 FF FF 
LEA RCX, invalid ptr SS : [ RSP +  + 0x30 ]                 ;000000014000511D 48 8D 4C 24 30 
CALL 0xFFFFFD89                                             ;0000000140005122 E8 89 FD FF FF 
MOV RAX, qword ptr SS : [ RSP +  + 0x68 ]                   ;0000000140005127 48 8B 44 24 68 
JMP 0x28                                                    ;000000014000512C EB 28 
LEA RCX, invalid ptr SS : [ RSP +  + 0x38 ]                 ;000000014000512E 48 8D 4C 24 38 
CALL 0xFFFFFD98                                             ;0000000140005133 E8 98 FD FF FF 
MOV qword ptr SS : [ RSP +  + 0x70 ], RAX                   ;0000000140005138 48 89 44 24 70 
LEA RCX, invalid ptr SS : [ RSP +  + 0x38 ]                 ;000000014000513D 48 8D 4C 24 38 
CALL 0xFFFFF919                                             ;0000000140005142 E8 19 F9 FF FF 
LEA RCX, invalid ptr SS : [ RSP +  + 0x30 ]                 ;0000000140005147 48 8D 4C 24 30 
CALL 0xFFFFFD5F                                             ;000000014000514C E8 5F FD FF FF 
MOV RAX, qword ptr SS : [ RSP +  + 0x70 ]                   ;0000000140005151 48 8B 44 24 70 
ADD RSP, 0x00000088                                         ;0000000140005156 48 81 C4 88 00 00 00 
RETN                                                        ;000000014000515D C3 
INT 3                                                       ;000000014000515E CC 
INT 3                                                       ;000000014000515F CC 
SUB RSP, 0x28                                               ;0000000140005160 48 83 EC 28 
LEA RCX, CS : [ RIP + 0xFFFFFDE5 ]                          ;0000000140005164 48 8D 0D E5 FD FF FF 
CALL 0x000006E0                                             ;000000014000516B E8 E0 06 00 00 
MOV CS : [ RIP + 0x00054EBA ], EAX                          ;0000000140005170 89 05 BA 4E 05 00 
CMP CS : [ RIP + 0x00054EB3 ], 0xFF                         ;0000000140005176 83 3D B3 4E 05 00 FF 
JNZ 0x04                                                    ;000000014000517D 75 04 
XOR AL, AL                                                  ;000000014000517F 32 C0 
JMP 0x1E                                                    ;0000000140005181 EB 1E 
LEA RCX, CS : [ RIP + 0x00055F66 ]                          ;0000000140005183 48 8D 0D 66 5F 05 00 
CALL 0xFFFFFD71                                             ;000000014000518A E8 71 FD FF FF 
MOVZX EAX, AL                                               ;000000014000518F 0F B6 C0 
TEST EAX, EAX                                               ;0000000140005192 85 C0 
JNZ 0x09                                                    ;0000000140005194 75 09 
CALL 0x00000015                                             ;0000000140005196 E8 15 00 00 00 
XOR AL, AL                                                  ;000000014000519B 32 C0 
JMP 0x02                                                    ;000000014000519D EB 02 
MOV AL, 0x01                                                ;000000014000519F B0 01 
ADD RSP, 0x28                                               ;00000001400051A1 48 83 C4 28 
RETN                                                        ;00000001400051A5 C3 
INT 3                                                       ;00000001400051A6 CC 
INT 3                                                       ;00000001400051A7 CC 
INT 3                                                       ;00000001400051A8 CC 
INT 3                                                       ;00000001400051A9 CC 
INT 3                                                       ;00000001400051AA CC 
INT 3                                                       ;00000001400051AB CC 
INT 3                                                       ;00000001400051AC CC 
INT 3                                                       ;00000001400051AD CC 
INT 3                                                       ;00000001400051AE CC 
INT 3                                                       ;00000001400051AF CC 
SUB RSP, 0x28                                               ;00000001400051B0 48 83 EC 28 
CMP CS : [ RIP + 0x00054E75 ], 0xFF                         ;00000001400051B4 83 3D 75 4E 05 00 FF 
JZ 0x15                                                     ;00000001400051BB 74 15 
MOV ECX, CS : [ RIP + 0x00054E6D ]                          ;00000001400051BD 8B 0D 6D 4E 05 00 
CALL 0x000006D8                                             ;00000001400051C3 E8 D8 06 00 00 
MOV CS : [ RIP + 0x00054E5E ], 0xFFFFFFFF                   ;00000001400051C8 C7 05 5E 4E 05 00 FF FF FF FF 
MOV AL, 0x01                                                ;00000001400051D2 B0 01 
ADD RSP, 0x28                                               ;00000001400051D4 48 83 C4 28 
RETN                                                        ;00000001400051D8 C3 
INT 3                                                       ;00000001400051D9 CC 
INT 3                                                       ;00000001400051DA CC 
INT 3                                                       ;00000001400051DB CC 
INT 3                                                       ;00000001400051DC CC 
INT 3                                                       ;00000001400051DD CC 
INT 3                                                       ;00000001400051DE CC 
INT 3                                                       ;00000001400051DF CC 
SUB RSP, 0x38                                               ;00000001400051E0 48 83 EC 38 
MOV dword ptr SS : [ RSP +  + 0x20 ], 0x00000000            ;00000001400051E4 C7 44 24 20 00 00 00 00 
JMP 0x0A                                                    ;00000001400051EC EB 0A 
MOV EAX, dword ptr SS : [ RSP +  + 0x20 ]                   ;00000001400051EE 8B 44 24 20 
INC EAX                                                     ;00000001400051F2 FF C0 
MOV dword ptr SS : [ RSP +  + 0x20 ], EAX                   ;00000001400051F4 89 44 24 20 
CMP dword ptr SS : [ RSP +  + 0x20 ], 0x01                  ;00000001400051F8 83 7C 24 20 01 
JAE 0x42                                                    ;00000001400051FD 73 42 
MOV EAX, dword ptr SS : [ RSP +  + 0x20 ]                   ;00000001400051FF 8B 44 24 20 
IMUL RAX, RAX, 0x28                                         ;0000000140005203 48 6B C0 28 
LEA RCX, CS : [ RIP + 0x00055F72 ]                          ;0000000140005207 48 8D 0D 72 5F 05 00 
ADD RCX, RAX                                                ;000000014000520E 48 03 C8 
MOV RAX, RCX                                                ;0000000140005211 48 8B C1 
XOR R8D, R8D                                                ;0000000140005214 45 33 C0 
MOV EDX, 0x00000FA0                                         ;0000000140005217 BA A0 0F 00 00 
MOV RCX, RAX                                                ;000000014000521C 48 8B C8 
CALL 0x0000077C                                             ;000000014000521F E8 7C 07 00 00 
TEST EAX, EAX                                               ;0000000140005224 85 C0 
JNZ 0x09                                                    ;0000000140005226 75 09 
CALL 0x00000023                                             ;0000000140005228 E8 23 00 00 00 
XOR AL, AL                                                  ;000000014000522D 32 C0 
JMP 0x12                                                    ;000000014000522F EB 12 
MOV EAX, CS : [ RIP + 0x00055F71 ]                          ;0000000140005231 8B 05 71 5F 05 00 
INC EAX                                                     ;0000000140005237 FF C0 
MOV CS : [ RIP + 0x00055F69 ], EAX                          ;0000000140005239 89 05 69 5F 05 00 
JMP 0xAD                                                    ;000000014000523F EB AD 
MOV AL, 0x01                                                ;0000000140005241 B0 01 
ADD RSP, 0x38                                               ;0000000140005243 48 83 C4 38 
RETN                                                        ;0000000140005247 C3 
INT 3                                                       ;0000000140005248 CC 
INT 3                                                       ;0000000140005249 CC 
INT 3                                                       ;000000014000524A CC 
INT 3                                                       ;000000014000524B CC 
INT 3                                                       ;000000014000524C CC 
INT 3                                                       ;000000014000524D CC 
INT 3                                                       ;000000014000524E CC 
INT 3                                                       ;000000014000524F CC 
SUB RSP, 0x38                                               ;0000000140005250 48 83 EC 38 
MOV EAX, CS : [ RIP + 0x00055F4E ]                          ;0000000140005254 8B 05 4E 5F 05 00 
MOV dword ptr SS : [ RSP +  + 0x20 ], EAX                   ;000000014000525A 89 44 24 20 
JMP 0x0A                                                    ;000000014000525E EB 0A 
MOV EAX, dword ptr SS : [ RSP +  + 0x20 ]                   ;0000000140005260 8B 44 24 20 
DEC EAX                                                     ;0000000140005264 FF C8 
MOV dword ptr SS : [ RSP +  + 0x20 ], EAX                   ;0000000140005266 89 44 24 20 
CMP dword ptr SS : [ RSP +  + 0x20 ], 0x00                  ;000000014000526A 83 7C 24 20 00 
JBE 0x32                                                    ;000000014000526F 76 32 
MOV EAX, dword ptr SS : [ RSP +  + 0x20 ]                   ;0000000140005271 8B 44 24 20 
DEC EAX                                                     ;0000000140005275 FF C8 
MOV EAX, EAX                                                ;0000000140005277 8B C0 
IMUL RAX, RAX, 0x28                                         ;0000000140005279 48 6B C0 28 
LEA RCX, CS : [ RIP + 0x00055EFC ]                          ;000000014000527D 48 8D 0D FC 5E 05 00 
ADD RCX, RAX                                                ;0000000140005284 48 03 C8 
MOV RAX, RCX                                                ;0000000140005287 48 8B C1 
MOV RCX, RAX                                                ;000000014000528A 48 8B C8 
CALL CS : [ RIP + 0x0003FE1D ]                              ;000000014000528D FF 15 1D FE 03 00 
MOV EAX, CS : [ RIP + 0x00055F0F ]                          ;0000000140005293 8B 05 0F 5F 05 00 
DEC EAX                                                     ;0000000140005299 FF C8 
MOV CS : [ RIP + 0x00055F07 ], EAX                          ;000000014000529B 89 05 07 5F 05 00 
JMP 0xBD                                                    ;00000001400052A1 EB BD 
MOV AL, 0x01                                                ;00000001400052A3 B0 01 
ADD RSP, 0x38                                               ;00000001400052A5 48 83 C4 38 
RETN                                                        ;00000001400052A9 C3 
INT 3                                                       ;00000001400052AA CC 
INT 3                                                       ;00000001400052AB CC 
INT 3                                                       ;00000001400052AC CC 
INT 3                                                       ;00000001400052AD CC 
INT 3                                                       ;00000001400052AE CC 
INT 3                                                       ;00000001400052AF CC 
MOV qword ptr SS : [ RSP +  + 0x08 ], RCX                   ;00000001400052B0 48 89 4C 24 08 
SUB RSP, 0x28                                               ;00000001400052B5 48 83 EC 28 
XOR ECX, ECX                                                ;00000001400052B9 33 C9 
CALL 0xFFFFE2D0                                             ;00000001400052BB E8 D0 E2 FF FF 
ADD RSP, 0x28                                               ;00000001400052C0 48 83 C4 28 
RETN                                                        ;00000001400052C4 C3 
INT 3                                                       ;00000001400052C5 CC 
INT 3                                                       ;00000001400052C6 CC 
INT 3                                                       ;00000001400052C7 CC 
INT 3                                                       ;00000001400052C8 CC 
INT 3                                                       ;00000001400052C9 CC 
INT 3                                                       ;00000001400052CA CC 
INT 3                                                       ;00000001400052CB CC 
INT 3                                                       ;00000001400052CC CC 
INT 3                                                       ;00000001400052CD CC 
INT 3                                                       ;00000001400052CE CC 
INT 3                                                       ;00000001400052CF CC 
MOV qword ptr SS : [ RSP +  + 0x10 ], RDX                   ;00000001400052D0 48 89 54 24 10 
MOV qword ptr SS : [ RSP +  + 0x08 ], RCX                   ;00000001400052D5 48 89 4C 24 08 
MOV RAX, qword ptr SS : [ RSP +  + 0x10 ]                   ;00000001400052DA 48 8B 44 24 10 
MOV RCX, qword ptr SS : [ RSP +  + 0x08 ]                   ;00000001400052DF 48 8B 4C 24 08 
XCHG RAX, qword ptr DS : [ RCX ]                            ;00000001400052E4 48 87 01 
RETN                                                        ;00000001400052E7 C3 
INT 3                                                       ;00000001400052E8 CC 
INT 3                                                       ;00000001400052E9 CC 
INT 3                                                       ;00000001400052EA CC 
INT 3                                                       ;00000001400052EB CC 
INT 3                                                       ;00000001400052EC CC 
INT 3                                                       ;00000001400052ED CC 
INT 3                                                       ;00000001400052EE CC 
INT 3                                                       ;00000001400052EF CC 
MOV qword ptr SS : [ RSP +  + 0x08 ], RCX                   ;00000001400052F0 48 89 4C 24 08 
SUB RSP, 0x18                                               ;00000001400052F5 48 83 EC 18 
MOVZX EAX, byte ptr SS : [ RSP +  ]                         ;00000001400052F9 0F B6 04 24 
ADD RSP, 0x18                                               ;00000001400052FD 48 83 C4 18 
RETN                                                        ;0000000140005301 C3 
INT 3                                                       ;0000000140005302 CC 
INT 3                                                       ;0000000140005303 CC 
INT 3                                                       ;0000000140005304 CC 
INT 3                                                       ;0000000140005305 CC 
INT 3                                                       ;0000000140005306 CC 
INT 3                                                       ;0000000140005307 CC 
INT 3                                                       ;0000000140005308 CC 
INT 3                                                       ;0000000140005309 CC 
INT 3                                                       ;000000014000530A CC 
INT 3                                                       ;000000014000530B CC 
INT 3                                                       ;000000014000530C CC 
INT 3                                                       ;000000014000530D CC 
INT 3                                                       ;000000014000530E CC 
INT 3                                                       ;000000014000530F CC 
MOV RAX, 0xFFFFFFFF                                         ;0000000140005310 48 C7 C0 FF FF FF FF 
RETN                                                        ;0000000140005317 C3 
INT 3                                                       ;0000000140005318 CC 
INT 3                                                       ;0000000140005319 CC 
INT 3                                                       ;000000014000531A CC 
INT 3                                                       ;000000014000531B CC 
INT 3                                                       ;000000014000531C CC 
INT 3                                                       ;000000014000531D CC 
INT 3                                                       ;000000014000531E CC 
INT 3                                                       ;000000014000531F CC 
SUB RSP, 0x28                                               ;0000000140005320 48 83 EC 28 
LEA RAX, CS : [ RIP + 0x00040305 ]                          ;0000000140005324 48 8D 05 05 03 04 00 
ADD RAX, 0x08                                               ;000000014000532B 48 83 C0 08 
MOV R9, RAX                                                 ;000000014000532F 4C 8B C8 
LEA R8, CS : [ RIP + 0x000402F7 ]                           ;0000000140005332 4C 8D 05 F7 02 04 00 
LEA RDX, CS : [ RIP + 0x000402F8 ]                          ;0000000140005339 48 8D 15 F8 02 04 00 
XOR ECX, ECX                                                ;0000000140005340 33 C9 
CALL 0x00000129                                             ;0000000140005342 E8 29 01 00 00 
ADD RSP, 0x28                                               ;0000000140005347 48 83 C4 28 
RETN                                                        ;000000014000534B C3 
INT 3                                                       ;000000014000534C CC 
INT 3                                                       ;000000014000534D CC 
INT 3                                                       ;000000014000534E CC 
INT 3                                                       ;000000014000534F CC 
SUB RSP, 0x28                                               ;0000000140005350 48 83 EC 28 
LEA RAX, CS : [ RIP + 0x000402ED ]                          ;0000000140005354 48 8D 05 ED 02 04 00 
ADD RAX, 0x08                                               ;000000014000535B 48 83 C0 08 
MOV R9, RAX                                                 ;000000014000535F 4C 8B C8 
LEA R8, CS : [ RIP + 0x000402DF ]                           ;0000000140005362 4C 8D 05 DF 02 04 00 
LEA RDX, CS : [ RIP + 0x000402E0 ]                          ;0000000140005369 48 8D 15 E0 02 04 00 
MOV ECX, 0x00000001                                         ;0000000140005370 B9 01 00 00 00 
CALL 0x000000F6                                             ;0000000140005375 E8 F6 00 00 00 
ADD RSP, 0x28                                               ;000000014000537A 48 83 C4 28 
RETN                                                        ;000000014000537E C3 
INT 3                                                       ;000000014000537F CC 
SUB RSP, 0x28                                               ;0000000140005380 48 83 EC 28 
LEA RAX, CS : [ RIP + 0x000402CD ]                          ;0000000140005384 48 8D 05 CD 02 04 00 
ADD RAX, 0x08                                               ;000000014000538B 48 83 C0 08 
MOV R9, RAX                                                 ;000000014000538F 4C 8B C8 
LEA R8, CS : [ RIP + 0x000402BF ]                           ;0000000140005392 4C 8D 05 BF 02 04 00 
LEA RDX, CS : [ RIP + 0x000402C0 ]                          ;0000000140005399 48 8D 15 C0 02 04 00 
MOV ECX, 0x00000002                                         ;00000001400053A0 B9 02 00 00 00 
CALL 0x000000C6                                             ;00000001400053A5 E8 C6 00 00 00 
ADD RSP, 0x28                                               ;00000001400053AA 48 83 C4 28 
RETN                                                        ;00000001400053AE C3 
INT 3                                                       ;00000001400053AF CC 
SUB RSP, 0x28                                               ;00000001400053B0 48 83 EC 28 
LEA RAX, CS : [ RIP + 0x000402B5 ]                          ;00000001400053B4 48 8D 05 B5 02 04 00 
ADD RAX, 0x08                                               ;00000001400053BB 48 83 C0 08 
MOV R9, RAX                                                 ;00000001400053BF 4C 8B C8 
LEA R8, CS : [ RIP + 0x000402A7 ]                           ;00000001400053C2 4C 8D 05 A7 02 04 00 
LEA RDX, CS : [ RIP + 0x000402A8 ]                          ;00000001400053C9 48 8D 15 A8 02 04 00 
MOV ECX, 0x00000003                                         ;00000001400053D0 B9 03 00 00 00 
CALL 0x00000096                                             ;00000001400053D5 E8 96 00 00 00 
ADD RSP, 0x28                                               ;00000001400053DA 48 83 C4 28 
RETN                                                        ;00000001400053DE C3 
INT 3                                                       ;00000001400053DF CC 
SUB RSP, 0x28                                               ;00000001400053E0 48 83 EC 28 
LEA RAX, CS : [ RIP + 0x0004029D ]                          ;00000001400053E4 48 8D 05 9D 02 04 00 
ADD RAX, 0x08                                               ;00000001400053EB 48 83 C0 08 
MOV R9, RAX                                                 ;00000001400053EF 4C 8B C8 
LEA R8, CS : [ RIP + 0x0004028F ]                           ;00000001400053F2 4C 8D 05 8F 02 04 00 
LEA RDX, CS : [ RIP + 0x00040290 ]                          ;00000001400053F9 48 8D 15 90 02 04 00 
MOV ECX, 0x00000004                                         ;0000000140005400 B9 04 00 00 00 
CALL 0x00000066                                             ;0000000140005405 E8 66 00 00 00 
ADD RSP, 0x28                                               ;000000014000540A 48 83 C4 28 
RETN                                                        ;000000014000540E C3 
INT 3                                                       ;000000014000540F CC 
MOV qword ptr SS : [ RSP +  + 0x10 ], RDX                   ;0000000140005410 48 89 54 24 10 
MOV qword ptr SS : [ RSP +  + 0x08 ], RCX                   ;0000000140005415 48 89 4C 24 08 
SUB RSP, 0x38                                               ;000000014000541A 48 83 EC 38 
MOV RAX, qword ptr SS : [ RSP +  + 0x40 ]                   ;000000014000541E 48 8B 44 24 40 
MOV qword ptr SS : [ RSP +  + 0x20 ], RAX                   ;0000000140005423 48 89 44 24 20 
JMP 0x0E                                                    ;0000000140005428 EB 0E 
MOV RAX, qword ptr SS : [ RSP +  + 0x20 ]                   ;000000014000542A 48 8B 44 24 20 
ADD RAX, 0x04                                               ;000000014000542F 48 83 C0 04 
MOV qword ptr SS : [ RSP +  + 0x20 ], RAX                   ;0000000140005433 48 89 44 24 20 
MOV RAX, qword ptr SS : [ RSP +  + 0x48 ]                   ;0000000140005438 48 8B 44 24 48 
CMP qword ptr SS : [ RSP +  + 0x20 ], RAX                   ;000000014000543D 48 39 44 24 20 
JZ 0x22                                                     ;0000000140005442 74 22 
MOV RAX, qword ptr SS : [ RSP +  + 0x20 ]                   ;0000000140005444 48 8B 44 24 20 
MOV ECX, dword ptr DS : [ RAX ]                             ;0000000140005449 8B 08 
CALL 0x000001C0                                             ;000000014000544B E8 C0 01 00 00 
MOV qword ptr SS : [ RSP +  + 0x28 ], RAX                   ;0000000140005450 48 89 44 24 28 
CMP qword ptr SS : [ RSP +  + 0x28 ], 0x00                  ;0000000140005455 48 83 7C 24 28 00 
JZ 0x07                                                     ;000000014000545B 74 07 
MOV RAX, qword ptr SS : [ RSP +  + 0x28 ]                   ;000000014000545D 48 8B 44 24 28 
JMP 0x04                                                    ;0000000140005462 EB 04 
JMP 0xC4                                                    ;0000000140005464 EB C4 
XOR EAX, EAX                                                ;0000000140005466 33 C0 
ADD RSP, 0x38                                               ;0000000140005468 48 83 C4 38 
RETN                                                        ;000000014000546C C3 
INT 3                                                       ;000000014000546D CC 
INT 3                                                       ;000000014000546E CC 
INT 3                                                       ;000000014000546F CC 
MOV qword ptr SS : [ RSP +  + 0x20 ], R9                    ;0000000140005470 4C 89 4C 24 20 
MOV qword ptr SS : [ RSP +  + 0x18 ], R8                    ;0000000140005475 4C 89 44 24 18 
MOV qword ptr SS : [ RSP +  + 0x10 ], RDX                   ;000000014000547A 48 89 54 24 10 
MOV dword ptr SS : [ RSP +  + 0x08 ], ECX                   ;000000014000547F 89 4C 24 08 
SUB RSP, 0x58                                               ;0000000140005483 48 83 EC 58 
MOV EAX, dword ptr SS : [ RSP +  + 0x60 ]                   ;0000000140005487 8B 44 24 60 
LEA RCX, CS : [ RIP + 0x00055D36 ]                          ;000000014000548B 48 8D 0D 36 5D 05 00 
LEA RAX, invalid ptr DS : [ RCX + RAX * 8 ]                 ;0000000140005492 48 8D 04 C1 
MOV RCX, RAX                                                ;0000000140005496 48 8B C8 
CALL 0xFFFFECB2                                             ;0000000140005499 E8 B2 EC FF FF 
MOV RCX, RAX                                                ;000000014000549E 48 8B C8 
CALL 0xFFFFE0AA                                             ;00000001400054A1 E8 AA E0 FF FF 
MOV qword ptr SS : [ RSP +  + 0x38 ], RAX                   ;00000001400054A6 48 89 44 24 38 
CALL 0xFFFFFE60                                             ;00000001400054AB E8 60 FE FF FF 
CMP qword ptr SS : [ RSP +  + 0x38 ], RAX                   ;00000001400054B0 48 39 44 24 38 
JNZ 0x07                                                    ;00000001400054B5 75 07 
XOR EAX, EAX                                                ;00000001400054B7 33 C0 
JMP 0x0000013E                                              ;00000001400054B9 E9 3E 01 00 00 
CMP qword ptr SS : [ RSP +  + 0x38 ], 0x00                  ;00000001400054BE 48 83 7C 24 38 00 
JZ 0x0A                                                     ;00000001400054C4 74 0A 
MOV RAX, qword ptr SS : [ RSP +  + 0x38 ]                   ;00000001400054C6 48 8B 44 24 38 
JMP 0x0000012C                                              ;00000001400054CB E9 2C 01 00 00 
MOV R8, qword ptr SS : [ RSP +  + 0x78 ]                    ;00000001400054D0 4C 8B 44 24 78 
MOV RDX, qword ptr SS : [ RSP +  + 0x70 ]                   ;00000001400054D5 48 8B 54 24 70 
MOV RCX, qword ptr SS : [ RSP +  + 0x68 ]                   ;00000001400054DA 48 8B 4C 24 68 
CALL 0x0000028C                                             ;00000001400054DF E8 8C 02 00 00 
MOV qword ptr SS : [ RSP +  + 0x30 ], RAX                   ;00000001400054E4 48 89 44 24 30 
CMP qword ptr SS : [ RSP +  + 0x30 ], 0x00                  ;00000001400054E9 48 83 7C 24 30 00 
JNZ 0x00000086                                              ;00000001400054EF 0F 85 86 00 00 00 
CALL 0xFFFFFE16                                             ;00000001400054F5 E8 16 FE FF FF 
MOV RCX, RAX                                                ;00000001400054FA 48 8B C8 
CALL 0xFFFFE08E                                             ;00000001400054FD E8 8E E0 FF FF 
MOV ECX, dword ptr SS : [ RSP +  + 0x60 ]                   ;0000000140005502 8B 4C 24 60 
LEA RDX, CS : [ RIP + 0x00055CBB ]                          ;0000000140005506 48 8D 15 BB 5C 05 00 
LEA RCX, invalid ptr DS : [ RDX + RCX * 8 ]                 ;000000014000550D 48 8D 0C CA 
MOV RDX, RAX                                                ;0000000140005511 48 8B D0 
CALL 0xFFFFFDB7                                             ;0000000140005514 E8 B7 FD FF FF 
MOV RCX, RAX                                                ;0000000140005519 48 8B C8 
CALL 0xFFFFE02F                                             ;000000014000551C E8 2F E0 FF FF 
MOV qword ptr SS : [ RSP +  + 0x40 ], RAX                   ;0000000140005521 48 89 44 24 40 
CMP qword ptr SS : [ RSP +  + 0x40 ], 0x00                  ;0000000140005526 48 83 7C 24 40 00 
JZ 0x46                                                     ;000000014000552C 74 46 
CALL 0xFFFFFDDD                                             ;000000014000552E E8 DD FD FF FF 
CMP qword ptr SS : [ RSP +  + 0x40 ], RAX                   ;0000000140005533 48 39 44 24 40 
JZ 0x3A                                                     ;0000000140005538 74 3A 
LEA RAX, CS : [ RIP + 0x0004006F ]                          ;000000014000553A 48 8D 05 6F 00 04 00 
MOV qword ptr SS : [ RSP +  + 0x28 ], RAX                   ;0000000140005541 48 89 44 24 28 
LEA RAX, CS : [ RIP + 0x0003FF2B ]                          ;0000000140005546 48 8D 05 2B FF 03 00 
MOV qword ptr SS : [ RSP +  + 0x20 ], RAX                   ;000000014000554D 48 89 44 24 20 
XOR R9D, R9D                                                ;0000000140005552 45 33 C9 
MOV R8D, 0x00000109                                         ;0000000140005555 41 B8 09 01 00 00 
LEA RDX, CS : [ RIP + 0x0003FF8E ]                          ;000000014000555B 48 8D 15 8E FF 03 00 
MOV ECX, 0x00000002                                         ;0000000140005562 B9 02 00 00 00 
CALL 0x00017CC4                                             ;0000000140005567 E8 C4 7C 01 00 
CMP EAX, 0x01                                               ;000000014000556C 83 F8 01 
JNZ 0x03                                                    ;000000014000556F 75 03 
INT 3                                                       ;0000000140005571 CC 
XOR EAX, EAX                                                ;0000000140005572 33 C0 
XOR EAX, EAX                                                ;0000000140005574 33 C0 
JMP 0x00000081                                              ;0000000140005576 E9 81 00 00 00 
MOV RCX, qword ptr SS : [ RSP +  + 0x30 ]                   ;000000014000557B 48 8B 4C 24 30 
CALL 0xFFFFE00B                                             ;0000000140005580 E8 0B E0 FF FF 
MOV ECX, dword ptr SS : [ RSP +  + 0x60 ]                   ;0000000140005585 8B 4C 24 60 
LEA RDX, CS : [ RIP + 0x00055C38 ]                          ;0000000140005589 48 8D 15 38 5C 05 00 
LEA RCX, invalid ptr DS : [ RDX + RCX * 8 ]                 ;0000000140005590 48 8D 0C CA 
MOV RDX, RAX                                                ;0000000140005594 48 8B D0 
CALL 0xFFFFFD34                                             ;0000000140005597 E8 34 FD FF FF 
MOV RCX, RAX                                                ;000000014000559C 48 8B C8 
CALL 0xFFFFDFAC                                             ;000000014000559F E8 AC DF FF FF 
MOV qword ptr SS : [ RSP +  + 0x48 ], RAX                   ;00000001400055A4 48 89 44 24 48 
CMP qword ptr SS : [ RSP +  + 0x48 ], 0x00                  ;00000001400055A9 48 83 7C 24 48 00 
JZ 0x46                                                     ;00000001400055AF 74 46 
MOV RAX, qword ptr SS : [ RSP +  + 0x30 ]                   ;00000001400055B1 48 8B 44 24 30 
CMP qword ptr SS : [ RSP +  + 0x48 ], RAX                   ;00000001400055B6 48 39 44 24 48 
JZ 0x3A                                                     ;00000001400055BB 74 3A 
LEA RAX, CS : [ RIP + 0x00040044 ]                          ;00000001400055BD 48 8D 05 44 00 04 00 
MOV qword ptr SS : [ RSP +  + 0x28 ], RAX                   ;00000001400055C4 48 89 44 24 28 
LEA RAX, CS : [ RIP + 0x0003FEA8 ]                          ;00000001400055C9 48 8D 05 A8 FE 03 00 
MOV qword ptr SS : [ RSP +  + 0x20 ], RAX                   ;00000001400055D0 48 89 44 24 20 
XOR R9D, R9D                                                ;00000001400055D5 45 33 C9 
MOV R8D, 0x0000011B                                         ;00000001400055D8 41 B8 1B 01 00 00 
LEA RDX, CS : [ RIP + 0x0003FF0B ]                          ;00000001400055DE 48 8D 15 0B FF 03 00 
MOV ECX, 0x00000002                                         ;00000001400055E5 B9 02 00 00 00 
CALL 0x00017C41                                             ;00000001400055EA E8 41 7C 01 00 
CMP EAX, 0x01                                               ;00000001400055EF 83 F8 01 
JNZ 0x03                                                    ;00000001400055F2 75 03 
INT 3                                                       ;00000001400055F4 CC 
XOR EAX, EAX                                                ;00000001400055F5 33 C0 
MOV RAX, qword ptr SS : [ RSP +  + 0x30 ]                   ;00000001400055F7 48 8B 44 24 30 
ADD RSP, 0x58                                               ;00000001400055FC 48 83 C4 58 
RETN                                                        ;0000000140005600 C3 
INT 3                                                       ;0000000140005601 CC 
INT 3                                                       ;0000000140005602 CC 
INT 3                                                       ;0000000140005603 CC 
INT 3                                                       ;0000000140005604 CC 
INT 3                                                       ;0000000140005605 CC 
INT 3                                                       ;0000000140005606 CC 
INT 3                                                       ;0000000140005607 CC 
INT 3                                                       ;0000000140005608 CC 
INT 3                                                       ;0000000140005609 CC 
INT 3                                                       ;000000014000560A CC 
INT 3                                                       ;000000014000560B CC 
INT 3                                                       ;000000014000560C CC 
INT 3                                                       ;000000014000560D CC 
INT 3                                                       ;000000014000560E CC 
INT 3                                                       ;000000014000560F CC 
MOV dword ptr SS : [ RSP +  + 0x08 ], ECX                   ;0000000140005610 89 4C 24 08 
SUB RSP, 0x58                                               ;0000000140005614 48 83 EC 58 
MOV EAX, dword ptr SS : [ RSP +  + 0x60 ]                   ;0000000140005618 8B 44 24 60 
LEA RCX, CS : [ RIP + 0x00055B8D ]                          ;000000014000561C 48 8D 0D 8D 5B 05 00 
LEA RAX, invalid ptr DS : [ RCX + RAX * 8 ]                 ;0000000140005623 48 8D 04 C1 
MOV RCX, RAX                                                ;0000000140005627 48 8B C8 
CALL 0xFFFFEB21                                             ;000000014000562A E8 21 EB FF FF 
MOV qword ptr SS : [ RSP +  + 0x38 ], RAX                   ;000000014000562F 48 89 44 24 38 
CMP qword ptr SS : [ RSP +  + 0x38 ], 0x00                  ;0000000140005634 48 83 7C 24 38 00 
JZ 0x19                                                     ;000000014000563A 74 19 
CMP qword ptr SS : [ RSP +  + 0x38 ], 0xFF                  ;000000014000563C 48 83 7C 24 38 FF 
JNZ 0x07                                                    ;0000000140005642 75 07 
XOR EAX, EAX                                                ;0000000140005644 33 C0 
JMP 0x0000011B                                              ;0000000140005646 E9 1B 01 00 00 
MOV RAX, qword ptr SS : [ RSP +  + 0x38 ]                   ;000000014000564B 48 8B 44 24 38 
JMP 0x00000111                                              ;0000000140005650 E9 11 01 00 00 
MOV EAX, dword ptr SS : [ RSP +  + 0x60 ]                   ;0000000140005655 8B 44 24 60 
LEA RCX, CS : [ RIP + 0x0003FD68 ]                          ;0000000140005659 48 8D 0D 68 FD 03 00 
MOV RCX, qword ptr DS : [ RCX + RAX * 8 ]                   ;0000000140005660 48 8B 0C C1 
CALL 0x00000157                                             ;0000000140005664 E8 57 01 00 00 
MOV qword ptr SS : [ RSP +  + 0x30 ], RAX                   ;0000000140005669 48 89 44 24 30 
CMP qword ptr SS : [ RSP +  + 0x30 ], 0x00                  ;000000014000566E 48 83 7C 24 30 00 
JNZ 0x71                                                    ;0000000140005674 75 71 
MOV EAX, dword ptr SS : [ RSP +  + 0x60 ]                   ;0000000140005676 8B 44 24 60 
LEA RCX, CS : [ RIP + 0x00055B2F ]                          ;000000014000567A 48 8D 0D 2F 5B 05 00 
LEA RAX, invalid ptr DS : [ RCX + RAX * 8 ]                 ;0000000140005681 48 8D 04 C1 
MOV RDX, 0xFFFFFFFF                                         ;0000000140005685 48 C7 C2 FF FF FF FF 
MOV RCX, RAX                                                ;000000014000568C 48 8B C8 
CALL 0xFFFFFC3C                                             ;000000014000568F E8 3C FC FF FF 
MOV qword ptr SS : [ RSP +  + 0x40 ], RAX                   ;0000000140005694 48 89 44 24 40 
CMP qword ptr SS : [ RSP +  + 0x40 ], 0x00                  ;0000000140005699 48 83 7C 24 40 00 
JZ 0x42                                                     ;000000014000569F 74 42 
CMP qword ptr SS : [ RSP +  + 0x40 ], 0xFF                  ;00000001400056A1 48 83 7C 24 40 FF 
JZ 0x3A                                                     ;00000001400056A7 74 3A 
LEA RAX, CS : [ RIP + 0x0003FDF0 ]                          ;00000001400056A9 48 8D 05 F0 FD 03 00 
MOV qword ptr SS : [ RSP +  + 0x28 ], RAX                   ;00000001400056B0 48 89 44 24 28 
LEA RAX, CS : [ RIP + 0x0003FDBC ]                          ;00000001400056B5 48 8D 05 BC FD 03 00 
MOV qword ptr SS : [ RSP +  + 0x20 ], RAX                   ;00000001400056BC 48 89 44 24 20 
XOR R9D, R9D                                                ;00000001400056C1 45 33 C9 
MOV R8D, 0x000000AC                                         ;00000001400056C4 41 B8 AC 00 00 00 
LEA RDX, CS : [ RIP + 0x0003FE1F ]                          ;00000001400056CA 48 8D 15 1F FE 03 00 
MOV ECX, 0x00000002                                         ;00000001400056D1 B9 02 00 00 00 
CALL 0x00017B55                                             ;00000001400056D6 E8 55 7B 01 00 
CMP EAX, 0x01                                               ;00000001400056DB 83 F8 01 
JNZ 0x03                                                    ;00000001400056DE 75 03 
INT 3                                                       ;00000001400056E0 CC 
XOR EAX, EAX                                                ;00000001400056E1 33 C0 
XOR EAX, EAX                                                ;00000001400056E3 33 C0 
JMP 0x7F                                                    ;00000001400056E5 EB 7F 
MOV EAX, dword ptr SS : [ RSP +  + 0x60 ]                   ;00000001400056E7 8B 44 24 60 
LEA RCX, CS : [ RIP + 0x00055ABE ]                          ;00000001400056EB 48 8D 0D BE 5A 05 00 
LEA RAX, invalid ptr DS : [ RCX + RAX * 8 ]                 ;00000001400056F2 48 8D 04 C1 
MOV RDX, qword ptr SS : [ RSP +  + 0x30 ]                   ;00000001400056F6 48 8B 54 24 30 
MOV RCX, RAX                                                ;00000001400056FB 48 8B C8 
CALL 0xFFFFFBCD                                             ;00000001400056FE E8 CD FB FF FF 
MOV qword ptr SS : [ RSP +  + 0x48 ], RAX                   ;0000000140005703 48 89 44 24 48 
CMP qword ptr SS : [ RSP +  + 0x48 ], 0x00                  ;0000000140005708 48 83 7C 24 48 00 
JZ 0x51                                                     ;000000014000570E 74 51 
MOV RAX, qword ptr SS : [ RSP +  + 0x30 ]                   ;0000000140005710 48 8B 44 24 30 
CMP qword ptr SS : [ RSP +  + 0x48 ], RAX                   ;0000000140005715 48 39 44 24 48 
JZ 0x3A                                                     ;000000014000571A 74 3A 
LEA RAX, CS : [ RIP + 0x0003FE4D ]                          ;000000014000571C 48 8D 05 4D FE 03 00 
MOV qword ptr SS : [ RSP +  + 0x28 ], RAX                   ;0000000140005723 48 89 44 24 28 
LEA RAX, CS : [ RIP + 0x0003FD49 ]                          ;0000000140005728 48 8D 05 49 FD 03 00 
MOV qword ptr SS : [ RSP +  + 0x20 ], RAX                   ;000000014000572F 48 89 44 24 20 
XOR R9D, R9D                                                ;0000000140005734 45 33 C9 
MOV R8D, 0x000000B8                                         ;0000000140005737 41 B8 B8 00 00 00 
LEA RDX, CS : [ RIP + 0x0003FDAC ]                          ;000000014000573D 48 8D 15 AC FD 03 00 
MOV ECX, 0x00000002                                         ;0000000140005744 B9 02 00 00 00 
CALL 0x00017AE2                                             ;0000000140005749 E8 E2 7A 01 00 
CMP EAX, 0x01                                               ;000000014000574E 83 F8 01 
JNZ 0x03                                                    ;0000000140005751 75 03 
INT 3                                                       ;0000000140005753 CC 
XOR EAX, EAX                                                ;0000000140005754 33 C0 
MOV RCX, qword ptr SS : [ RSP +  + 0x30 ]                   ;0000000140005756 48 8B 4C 24 30 
CALL CS : [ RIP + 0x0003F97F ]                              ;000000014000575B FF 15 7F F9 03 00 
MOV RAX, qword ptr SS : [ RSP +  + 0x30 ]                   ;0000000140005761 48 8B 44 24 30 
ADD RSP, 0x58                                               ;0000000140005766 48 83 C4 58 
RETN                                                        ;000000014000576A C3 
INT 3                                                       ;000000014000576B CC 
INT 3                                                       ;000000014000576C CC 
INT 3                                                       ;000000014000576D CC 
INT 3                                                       ;000000014000576E CC 
INT 3                                                       ;000000014000576F CC 
MOV qword ptr SS : [ RSP +  + 0x18 ], R8                    ;0000000140005770 4C 89 44 24 18 
MOV qword ptr SS : [ RSP +  + 0x10 ], RDX                   ;0000000140005775 48 89 54 24 10 
MOV qword ptr SS : [ RSP +  + 0x08 ], RCX                   ;000000014000577A 48 89 4C 24 08 
SUB RSP, 0x38                                               ;000000014000577F 48 83 EC 38 
MOV RDX, qword ptr SS : [ RSP +  + 0x50 ]                   ;0000000140005783 48 8B 54 24 50 
MOV RCX, qword ptr SS : [ RSP +  + 0x48 ]                   ;0000000140005788 48 8B 4C 24 48 
CALL 0xFFFFFC7E                                             ;000000014000578D E8 7E FC FF FF 
MOV qword ptr SS : [ RSP +  + 0x20 ], RAX                   ;0000000140005792 48 89 44 24 20 
CMP qword ptr SS : [ RSP +  + 0x20 ], 0x00                  ;0000000140005797 48 83 7C 24 20 00 
JNZ 0x04                                                    ;000000014000579D 75 04 
XOR EAX, EAX                                                ;000000014000579F 33 C0 
JMP 0x10                                                    ;00000001400057A1 EB 10 
MOV RDX, qword ptr SS : [ RSP +  + 0x40 ]                   ;00000001400057A3 48 8B 54 24 40 
MOV RCX, qword ptr SS : [ RSP +  + 0x20 ]                   ;00000001400057A8 48 8B 4C 24 20 
CALL CS : [ RIP + 0x0003F935 ]                              ;00000001400057AD FF 15 35 F9 03 00 
ADD RSP, 0x38                                               ;00000001400057B3 48 83 C4 38 
RETN                                                        ;00000001400057B7 C3 
INT 3                                                       ;00000001400057B8 CC 
INT 3                                                       ;00000001400057B9 CC 
INT 3                                                       ;00000001400057BA CC 
INT 3                                                       ;00000001400057BB CC 
INT 3                                                       ;00000001400057BC CC 
INT 3                                                       ;00000001400057BD CC 
INT 3                                                       ;00000001400057BE CC 
INT 3                                                       ;00000001400057BF CC 
MOV qword ptr SS : [ RSP +  + 0x08 ], RCX                   ;00000001400057C0 48 89 4C 24 08 
SUB RSP, 0x38                                               ;00000001400057C5 48 83 EC 38 
MOV R8D, 0x00000800                                         ;00000001400057C9 41 B8 00 08 00 00 
XOR EDX, EDX                                                ;00000001400057CF 33 D2 
MOV RCX, qword ptr SS : [ RSP +  + 0x40 ]                   ;00000001400057D1 48 8B 4C 24 40 
CALL CS : [ RIP + 0x0003F914 ]                              ;00000001400057D6 FF 15 14 F9 03 00 
MOV qword ptr SS : [ RSP +  + 0x20 ], RAX                   ;00000001400057DC 48 89 44 24 20 
CMP qword ptr SS : [ RSP +  + 0x20 ], 0x00                  ;00000001400057E1 48 83 7C 24 20 00 
JZ 0x07                                                     ;00000001400057E7 74 07 
MOV RAX, qword ptr SS : [ RSP +  + 0x20 ]                   ;00000001400057E9 48 8B 44 24 20 
JMP 0x55                                                    ;00000001400057EE EB 55 
CALL CS : [ RIP + 0x0003F89A ]                              ;00000001400057F0 FF 15 9A F8 03 00 
CMP EAX, 0x57                                               ;00000001400057F6 83 F8 57 
JNZ 0x48                                                    ;00000001400057F9 75 48 
MOV R8D, 0x00000007                                         ;00000001400057FB 41 B8 07 00 00 00 
LEA RDX, CS : [ RIP + 0x0003FC78 ]                          ;0000000140005801 48 8D 15 78 FC 03 00 
MOV RCX, qword ptr SS : [ RSP +  + 0x40 ]                   ;0000000140005808 48 8B 4C 24 40 
CALL 0x00017C2E                                             ;000000014000580D E8 2E 7C 01 00 
TEST EAX, EAX                                               ;0000000140005812 85 C0 
JZ 0x2D                                                     ;0000000140005814 74 2D 
MOV R8D, 0x00000007                                         ;0000000140005816 41 B8 07 00 00 00 
LEA RDX, CS : [ RIP + 0x0003FC6D ]                          ;000000014000581C 48 8D 15 6D FC 03 00 
MOV RCX, qword ptr SS : [ RSP +  + 0x40 ]                   ;0000000140005823 48 8B 4C 24 40 
CALL 0x00017C13                                             ;0000000140005828 E8 13 7C 01 00 
TEST EAX, EAX                                               ;000000014000582D 85 C0 
JZ 0x12                                                     ;000000014000582F 74 12 
XOR R8D, R8D                                                ;0000000140005831 45 33 C0 
XOR EDX, EDX                                                ;0000000140005834 33 D2 
MOV RCX, qword ptr SS : [ RSP +  + 0x40 ]                   ;0000000140005836 48 8B 4C 24 40 
CALL CS : [ RIP + 0x0003F8AF ]                              ;000000014000583B FF 15 AF F8 03 00 
JMP 0x02                                                    ;0000000140005841 EB 02 
XOR EAX, EAX                                                ;0000000140005843 33 C0 
ADD RSP, 0x38                                               ;0000000140005845 48 83 C4 38 
RETN                                                        ;0000000140005849 C3 
INT 3                                                       ;000000014000584A CC 
INT 3                                                       ;000000014000584B CC 
INT 3                                                       ;000000014000584C CC 
INT 3                                                       ;000000014000584D CC 
INT 3                                                       ;000000014000584E CC 
INT 3                                                       ;000000014000584F CC 
MOV qword ptr SS : [ RSP +  + 0x08 ], RCX                   ;0000000140005850 48 89 4C 24 08 
SUB RSP, 0x38                                               ;0000000140005855 48 83 EC 38 
CALL 0xFFFFFAC2                                             ;0000000140005859 E8 C2 FA FF FF 
MOV qword ptr SS : [ RSP +  + 0x20 ], RAX                   ;000000014000585E 48 89 44 24 20 
CMP qword ptr SS : [ RSP +  + 0x20 ], 0x00                  ;0000000140005863 48 83 7C 24 20 00 
JZ 0x1C                                                     ;0000000140005869 74 1C 
MOV RAX, qword ptr SS : [ RSP +  + 0x20 ]                   ;000000014000586B 48 8B 44 24 20 
MOV qword ptr SS : [ RSP +  + 0x28 ], RAX                   ;0000000140005870 48 89 44 24 28 
MOV RCX, qword ptr SS : [ RSP +  + 0x40 ]                   ;0000000140005875 48 8B 4C 24 40 
MOV RAX, qword ptr SS : [ RSP +  + 0x28 ]                   ;000000014000587A 48 8B 44 24 28 
CALL CS : [ RIP + 0x0003F9EB ]                              ;000000014000587F FF 15 EB F9 03 00 
JMP 0x06                                                    ;0000000140005885 EB 06 
CALL CS : [ RIP + 0x0003F833 ]                              ;0000000140005887 FF 15 33 F8 03 00 
ADD RSP, 0x38                                               ;000000014000588D 48 83 C4 38 
RETN                                                        ;0000000140005891 C3 
INT 3                                                       ;0000000140005892 CC 
INT 3                                                       ;0000000140005893 CC 
INT 3                                                       ;0000000140005894 CC 
INT 3                                                       ;0000000140005895 CC 
INT 3                                                       ;0000000140005896 CC 
INT 3                                                       ;0000000140005897 CC 
INT 3                                                       ;0000000140005898 CC 
INT 3                                                       ;0000000140005899 CC 
INT 3                                                       ;000000014000589A CC 
INT 3                                                       ;000000014000589B CC 
INT 3                                                       ;000000014000589C CC 
INT 3                                                       ;000000014000589D CC 
INT 3                                                       ;000000014000589E CC 
INT 3                                                       ;000000014000589F CC 
MOV dword ptr SS : [ RSP +  + 0x08 ], ECX                   ;00000001400058A0 89 4C 24 08 
SUB RSP, 0x38                                               ;00000001400058A4 48 83 EC 38 
CALL 0xFFFFFAA3                                             ;00000001400058A8 E8 A3 FA FF FF 
MOV qword ptr SS : [ RSP +  + 0x20 ], RAX                   ;00000001400058AD 48 89 44 24 20 
CMP qword ptr SS : [ RSP +  + 0x20 ], 0x00                  ;00000001400058B2 48 83 7C 24 20 00 
JZ 0x1B                                                     ;00000001400058B8 74 1B 
MOV RAX, qword ptr SS : [ RSP +  + 0x20 ]                   ;00000001400058BA 48 8B 44 24 20 
MOV qword ptr SS : [ RSP +  + 0x28 ], RAX                   ;00000001400058BF 48 89 44 24 28 
MOV ECX, dword ptr SS : [ RSP +  + 0x40 ]                   ;00000001400058C4 8B 4C 24 40 
MOV RAX, qword ptr SS : [ RSP +  + 0x28 ]                   ;00000001400058C8 48 8B 44 24 28 
CALL CS : [ RIP + 0x0003F99D ]                              ;00000001400058CD FF 15 9D F9 03 00 
JMP 0x0A                                                    ;00000001400058D3 EB 0A 
MOV ECX, dword ptr SS : [ RSP +  + 0x40 ]                   ;00000001400058D5 8B 4C 24 40 
CALL CS : [ RIP + 0x0003F7F9 ]                              ;00000001400058D9 FF 15 F9 F7 03 00 
ADD RSP, 0x38                                               ;00000001400058DF 48 83 C4 38 
RETN                                                        ;00000001400058E3 C3 
INT 3                                                       ;00000001400058E4 CC 
INT 3                                                       ;00000001400058E5 CC 
INT 3                                                       ;00000001400058E6 CC 
INT 3                                                       ;00000001400058E7 CC 
INT 3                                                       ;00000001400058E8 CC 
INT 3                                                       ;00000001400058E9 CC 
INT 3                                                       ;00000001400058EA CC 
INT 3                                                       ;00000001400058EB CC 
INT 3                                                       ;00000001400058EC CC 
INT 3                                                       ;00000001400058ED CC 
INT 3                                                       ;00000001400058EE CC 
INT 3                                                       ;00000001400058EF CC 
MOV dword ptr SS : [ RSP +  + 0x08 ], ECX                   ;00000001400058F0 89 4C 24 08 
SUB RSP, 0x38                                               ;00000001400058F4 48 83 EC 38 
CALL 0xFFFFFA83                                             ;00000001400058F8 E8 83 FA FF FF 
MOV qword ptr SS : [ RSP +  + 0x20 ], RAX                   ;00000001400058FD 48 89 44 24 20 
CMP qword ptr SS : [ RSP +  + 0x20 ], 0x00                  ;0000000140005902 48 83 7C 24 20 00 
JZ 0x1B                                                     ;0000000140005908 74 1B 
MOV RAX, qword ptr SS : [ RSP +  + 0x20 ]                   ;000000014000590A 48 8B 44 24 20 
MOV qword ptr SS : [ RSP +  + 0x28 ], RAX                   ;000000014000590F 48 89 44 24 28 
MOV ECX, dword ptr SS : [ RSP +  + 0x40 ]                   ;0000000140005914 8B 4C 24 40 
MOV RAX, qword ptr SS : [ RSP +  + 0x28 ]                   ;0000000140005918 48 8B 44 24 28 
CALL CS : [ RIP + 0x0003F94D ]                              ;000000014000591D FF 15 4D F9 03 00 
JMP 0x0A                                                    ;0000000140005923 EB 0A 
MOV ECX, dword ptr SS : [ RSP +  + 0x40 ]                   ;0000000140005925 8B 4C 24 40 
CALL CS : [ RIP + 0x0003F799 ]                              ;0000000140005929 FF 15 99 F7 03 00 
ADD RSP, 0x38                                               ;000000014000592F 48 83 C4 38 
RETN                                                        ;0000000140005933 C3 
INT 3                                                       ;0000000140005934 CC 
INT 3                                                       ;0000000140005935 CC 
INT 3                                                       ;0000000140005936 CC 
INT 3                                                       ;0000000140005937 CC 
INT 3                                                       ;0000000140005938 CC 
INT 3                                                       ;0000000140005939 CC 
INT 3                                                       ;000000014000593A CC 
INT 3                                                       ;000000014000593B CC 
INT 3                                                       ;000000014000593C CC 
INT 3                                                       ;000000014000593D CC 
INT 3                                                       ;000000014000593E CC 
INT 3                                                       ;000000014000593F CC 
MOV qword ptr SS : [ RSP +  + 0x10 ], RDX                   ;0000000140005940 48 89 54 24 10 
MOV dword ptr SS : [ RSP +  + 0x08 ], ECX                   ;0000000140005945 89 4C 24 08 
SUB RSP, 0x38                                               ;0000000140005949 48 83 EC 38 
CALL 0xFFFFFA5E                                             ;000000014000594D E8 5E FA FF FF 
MOV qword ptr SS : [ RSP +  + 0x20 ], RAX                   ;0000000140005952 48 89 44 24 20 
CMP qword ptr SS : [ RSP +  + 0x20 ], 0x00                  ;0000000140005957 48 83 7C 24 20 00 
JZ 0x20                                                     ;000000014000595D 74 20 
MOV RAX, qword ptr SS : [ RSP +  + 0x20 ]                   ;000000014000595F 48 8B 44 24 20 
MOV qword ptr SS : [ RSP +  + 0x28 ], RAX                   ;0000000140005964 48 89 44 24 28 
MOV RDX, qword ptr SS : [ RSP +  + 0x48 ]                   ;0000000140005969 48 8B 54 24 48 
MOV ECX, dword ptr SS : [ RSP +  + 0x40 ]                   ;000000014000596E 8B 4C 24 40 
MOV RAX, qword ptr SS : [ RSP +  + 0x28 ]                   ;0000000140005972 48 8B 44 24 28 
CALL CS : [ RIP + 0x0003F8F3 ]                              ;0000000140005977 FF 15 F3 F8 03 00 
JMP 0x0F                                                    ;000000014000597D EB 0F 
MOV RDX, qword ptr SS : [ RSP +  + 0x48 ]                   ;000000014000597F 48 8B 54 24 48 
MOV ECX, dword ptr SS : [ RSP +  + 0x40 ]                   ;0000000140005984 8B 4C 24 40 
CALL CS : [ RIP + 0x0003F742 ]                              ;0000000140005988 FF 15 42 F7 03 00 
ADD RSP, 0x38                                               ;000000014000598E 48 83 C4 38 
RETN                                                        ;0000000140005992 C3 
INT 3                                                       ;0000000140005993 CC 
INT 3                                                       ;0000000140005994 CC 
INT 3                                                       ;0000000140005995 CC 
INT 3                                                       ;0000000140005996 CC 
INT 3                                                       ;0000000140005997 CC 
INT 3                                                       ;0000000140005998 CC 
INT 3                                                       ;0000000140005999 CC 
INT 3                                                       ;000000014000599A CC 
INT 3                                                       ;000000014000599B CC 
INT 3                                                       ;000000014000599C CC 
INT 3                                                       ;000000014000599D CC 
INT 3                                                       ;000000014000599E CC 
INT 3                                                       ;000000014000599F CC 
MOV dword ptr SS : [ RSP +  + 0x18 ], R8D                   ;00000001400059A0 44 89 44 24 18 
MOV dword ptr SS : [ RSP +  + 0x10 ], EDX                   ;00000001400059A5 89 54 24 10 
MOV qword ptr SS : [ RSP +  + 0x08 ], RCX                   ;00000001400059A9 48 89 4C 24 08 
SUB RSP, 0x38                                               ;00000001400059AE 48 83 EC 38 
CALL 0xFFFFFA29                                             ;00000001400059B2 E8 29 FA FF FF 
MOV qword ptr SS : [ RSP +  + 0x20 ], RAX                   ;00000001400059B7 48 89 44 24 20 
CMP qword ptr SS : [ RSP +  + 0x20 ], 0x00                  ;00000001400059BC 48 83 7C 24 20 00 
JZ 0x25                                                     ;00000001400059C2 74 25 
MOV RAX, qword ptr SS : [ RSP +  + 0x20 ]                   ;00000001400059C4 48 8B 44 24 20 
MOV qword ptr SS : [ RSP +  + 0x28 ], RAX                   ;00000001400059C9 48 89 44 24 28 
MOV R8D, dword ptr SS : [ RSP +  + 0x50 ]                   ;00000001400059CE 44 8B 44 24 50 
MOV EDX, dword ptr SS : [ RSP +  + 0x48 ]                   ;00000001400059D3 8B 54 24 48 
MOV RCX, qword ptr SS : [ RSP +  + 0x40 ]                   ;00000001400059D7 48 8B 4C 24 40 
MOV RAX, qword ptr SS : [ RSP +  + 0x28 ]                   ;00000001400059DC 48 8B 44 24 28 
CALL CS : [ RIP + 0x0003F889 ]                              ;00000001400059E1 FF 15 89 F8 03 00 
JMP 0x0F                                                    ;00000001400059E7 EB 0F 
MOV EDX, dword ptr SS : [ RSP +  + 0x48 ]                   ;00000001400059E9 8B 54 24 48 
MOV RCX, qword ptr SS : [ RSP +  + 0x40 ]                   ;00000001400059ED 48 8B 4C 24 40 
CALL CS : [ RIP + 0x0003F6C0 ]                              ;00000001400059F2 FF 15 C0 F6 03 00 
ADD RSP, 0x38                                               ;00000001400059F8 48 83 C4 38 
RETN                                                        ;00000001400059FC C3 
INT 3                                                       ;00000001400059FD CC 
INT 3                                                       ;00000001400059FE CC 
INT 3                                                       ;00000001400059FF CC 
SUB RSP, 0x58                                               ;0000000140005A00 48 83 EC 58 
XOR ECX, ECX                                                ;0000000140005A04 33 C9 
CALL 0xFFFFF8E5                                             ;0000000140005A06 E8 E5 F8 FF FF 
MOV byte ptr SS : [ RSP +  + 0x20 ], AL                     ;0000000140005A0B 88 44 24 20 
LEA RCX, invalid ptr SS : [ RSP +  + 0x20 ]                 ;0000000140005A0F 48 8D 4C 24 20 
CALL 0xFFFFF897                                             ;0000000140005A14 E8 97 F8 FF FF 
MOV qword ptr SS : [ RSP +  + 0x48 ], RAX                   ;0000000140005A19 48 89 44 24 48 
LEA RAX, CS : [ RIP + 0x000557A3 ]                          ;0000000140005A1E 48 8D 05 A3 57 05 00 
MOV qword ptr SS : [ RSP +  + 0x30 ], RAX                   ;0000000140005A25 48 89 44 24 30 
MOV RAX, qword ptr SS : [ RSP +  + 0x30 ]                   ;0000000140005A2A 48 8B 44 24 30 
MOV qword ptr SS : [ RSP +  + 0x28 ], RAX                   ;0000000140005A2F 48 89 44 24 28 
MOV RAX, qword ptr SS : [ RSP +  + 0x30 ]                   ;0000000140005A34 48 8B 44 24 30 
ADD RAX, 0x28                                               ;0000000140005A39 48 83 C0 28 
MOV qword ptr SS : [ RSP +  + 0x38 ], RAX                   ;0000000140005A3D 48 89 44 24 38 
JMP 0x0E                                                    ;0000000140005A42 EB 0E 
MOV RAX, qword ptr SS : [ RSP +  + 0x28 ]                   ;0000000140005A44 48 8B 44 24 28 
ADD RAX, 0x08                                               ;0000000140005A49 48 83 C0 08 
MOV qword ptr SS : [ RSP +  + 0x28 ], RAX                   ;0000000140005A4D 48 89 44 24 28 
MOV RAX, qword ptr SS : [ RSP +  + 0x38 ]                   ;0000000140005A52 48 8B 44 24 38 
CMP qword ptr SS : [ RSP +  + 0x28 ], RAX                   ;0000000140005A57 48 39 44 24 28 
JZ 0x19                                                     ;0000000140005A5C 74 19 
MOV RAX, qword ptr SS : [ RSP +  + 0x28 ]                   ;0000000140005A5E 48 8B 44 24 28 
MOV qword ptr SS : [ RSP +  + 0x40 ], RAX                   ;0000000140005A63 48 89 44 24 40 
MOV RAX, qword ptr SS : [ RSP +  + 0x40 ]                   ;0000000140005A68 48 8B 44 24 40 
MOV RCX, qword ptr SS : [ RSP +  + 0x48 ]                   ;0000000140005A6D 48 8B 4C 24 48 
MOV qword ptr DS : [ RAX ], RCX                             ;0000000140005A72 48 89 08 
JMP 0xCD                                                    ;0000000140005A75 EB CD 
ADD RSP, 0x58                                               ;0000000140005A77 48 83 C4 58 
RETN                                                        ;0000000140005A7B C3 
INT 3                                                       ;0000000140005A7C CC 
INT 3                                                       ;0000000140005A7D CC 
INT 3                                                       ;0000000140005A7E CC 
INT 3                                                       ;0000000140005A7F CC 
MOV byte ptr SS : [ RSP +  + 0x08 ], CL                     ;0000000140005A80 88 4C 24 08 
SUB RSP, 0x48                                               ;0000000140005A84 48 83 EC 48 
MOVZX EAX, byte ptr SS : [ RSP +  + 0x50 ]                  ;0000000140005A88 0F B6 44 24 50 
TEST EAX, EAX                                               ;0000000140005A8D 85 C0 
JZ 0x02                                                     ;0000000140005A8F 74 02 
JMP 0x7C                                                    ;0000000140005A91 EB 7C 
LEA RAX, CS : [ RIP + 0x00055716 ]                          ;0000000140005A93 48 8D 05 16 57 05 00 
MOV qword ptr SS : [ RSP +  + 0x30 ], RAX                   ;0000000140005A9A 48 89 44 24 30 
MOV RAX, qword ptr SS : [ RSP +  + 0x30 ]                   ;0000000140005A9F 48 8B 44 24 30 
MOV qword ptr SS : [ RSP +  + 0x20 ], RAX                   ;0000000140005AA4 48 89 44 24 20 
MOV RAX, qword ptr SS : [ RSP +  + 0x30 ]                   ;0000000140005AA9 48 8B 44 24 30 
ADD RAX, 0x18                                               ;0000000140005AAE 48 83 C0 18 
MOV qword ptr SS : [ RSP +  + 0x38 ], RAX                   ;0000000140005AB2 48 89 44 24 38 
JMP 0x0E                                                    ;0000000140005AB7 EB 0E 
MOV RAX, qword ptr SS : [ RSP +  + 0x20 ]                   ;0000000140005AB9 48 8B 44 24 20 
ADD RAX, 0x08                                               ;0000000140005ABE 48 83 C0 08 
MOV qword ptr SS : [ RSP +  + 0x20 ], RAX                   ;0000000140005AC2 48 89 44 24 20 
MOV RAX, qword ptr SS : [ RSP +  + 0x38 ]                   ;0000000140005AC7 48 8B 44 24 38 
CMP qword ptr SS : [ RSP +  + 0x20 ], RAX                   ;0000000140005ACC 48 39 44 24 20 
JZ 0x3C                                                     ;0000000140005AD1 74 3C 
MOV RAX, qword ptr SS : [ RSP +  + 0x20 ]                   ;0000000140005AD3 48 8B 44 24 20 
MOV qword ptr SS : [ RSP +  + 0x28 ], RAX                   ;0000000140005AD8 48 89 44 24 28 
MOV RAX, qword ptr SS : [ RSP +  + 0x28 ]                   ;0000000140005ADD 48 8B 44 24 28 
CMP qword ptr DS : [ RAX ], 0x00                            ;0000000140005AE2 48 83 38 00 
JZ 0x25                                                     ;0000000140005AE6 74 25 
MOV RAX, qword ptr SS : [ RSP +  + 0x28 ]                   ;0000000140005AE8 48 8B 44 24 28 
CMP qword ptr DS : [ RAX ], 0xFF                            ;0000000140005AED 48 83 38 FF 
JZ 0x0E                                                     ;0000000140005AF1 74 0E 
MOV RAX, qword ptr SS : [ RSP +  + 0x28 ]                   ;0000000140005AF3 48 8B 44 24 28 
MOV RCX, qword ptr DS : [ RAX ]                             ;0000000140005AF8 48 8B 08 
CALL CS : [ RIP + 0x0003F5DF ]                              ;0000000140005AFB FF 15 DF F5 03 00 
MOV RAX, qword ptr SS : [ RSP +  + 0x28 ]                   ;0000000140005B01 48 8B 44 24 28 
MOV qword ptr DS : [ RAX ], 0x00000000                      ;0000000140005B06 48 C7 00 00 00 00 00 
JMP 0xAA                                                    ;0000000140005B0D EB AA 
ADD RSP, 0x48                                               ;0000000140005B0F 48 83 C4 48 
RETN                                                        ;0000000140005B13 C3 
INT 3                                                       ;0000000140005B14 CC 
INT 3                                                       ;0000000140005B15 CC 
INT 3                                                       ;0000000140005B16 CC 
INT 3                                                       ;0000000140005B17 CC 
INT 3                                                       ;0000000140005B18 CC 
INT 3                                                       ;0000000140005B19 CC 
INT 3                                                       ;0000000140005B1A CC 
INT 3                                                       ;0000000140005B1B CC 
INT 3                                                       ;0000000140005B1C CC 
INT 3                                                       ;0000000140005B1D CC 
INT 3                                                       ;0000000140005B1E CC 
INT 3                                                       ;0000000140005B1F CC 
SUB RSP, 0x38                                               ;0000000140005B20 48 83 EC 38 
XOR ECX, ECX                                                ;0000000140005B24 33 C9 
CALL 0xFFFFF7C5                                             ;0000000140005B26 E8 C5 F7 FF FF 
MOV byte ptr SS : [ RSP +  + 0x20 ], AL                     ;0000000140005B2B 88 44 24 20 
LEA RCX, invalid ptr SS : [ RSP +  + 0x20 ]                 ;0000000140005B2F 48 8D 4C 24 20 
CALL 0xFFFFF777                                             ;0000000140005B34 E8 77 F7 FF FF 
MOV CS : [ RIP + 0x000556B0 ], RAX                          ;0000000140005B39 48 89 05 B0 56 05 00 
ADD RSP, 0x38                                               ;0000000140005B40 48 83 C4 38 
RETN                                                        ;0000000140005B44 C3 
INT 3                                                       ;0000000140005B45 CC 
INT 3                                                       ;0000000140005B46 CC 
INT 3                                                       ;0000000140005B47 CC 
INT 3                                                       ;0000000140005B48 CC 
INT 3                                                       ;0000000140005B49 CC 
INT 3                                                       ;0000000140005B4A CC 
INT 3                                                       ;0000000140005B4B CC 
INT 3                                                       ;0000000140005B4C CC 
INT 3                                                       ;0000000140005B4D CC 
INT 3                                                       ;0000000140005B4E CC 
INT 3                                                       ;0000000140005B4F CC 
MOV qword ptr SS : [ RSP +  + 0x20 ], R9                    ;0000000140005B50 4C 89 4C 24 20 
MOV qword ptr SS : [ RSP +  + 0x18 ], R8                    ;0000000140005B55 4C 89 44 24 18 
MOV qword ptr SS : [ RSP +  + 0x10 ], RDX                   ;0000000140005B5A 48 89 54 24 10 
MOV qword ptr SS : [ RSP +  + 0x08 ], RCX                   ;0000000140005B5F 48 89 4C 24 08 
SUB RSP, 0x48                                               ;0000000140005B64 48 83 EC 48 
CALL 0xFFFFD0D3                                             ;0000000140005B68 E8 D3 D0 FF FF 
MOV RCX, qword ptr SS : [ RSP +  + 0x70 ]                   ;0000000140005B6D 48 8B 4C 24 70 
MOV qword ptr SS : [ RSP +  + 0x28 ], RCX                   ;0000000140005B72 48 89 4C 24 28 
MOV RCX, qword ptr SS : [ RSP +  + 0x68 ]                   ;0000000140005B77 48 8B 4C 24 68 
MOV qword ptr SS : [ RSP +  + 0x20 ], RCX                   ;0000000140005B7C 48 89 4C 24 20 
MOV R9, qword ptr SS : [ RSP +  + 0x60 ]                    ;0000000140005B81 4C 8B 4C 24 60 
MOV R8, qword ptr SS : [ RSP +  + 0x58 ]                    ;0000000140005B86 4C 8B 44 24 58 
MOV RDX, qword ptr SS : [ RSP +  + 0x50 ]                   ;0000000140005B8B 48 8B 54 24 50 
MOV RCX, qword ptr DS : [ RAX ]                             ;0000000140005B90 48 8B 08 
CALL 0x0000FE08                                             ;0000000140005B93 E8 08 FE 00 00 
MOV dword ptr SS : [ RSP +  + 0x30 ], EAX                   ;0000000140005B98 89 44 24 30 
CMP dword ptr SS : [ RSP +  + 0x30 ], 0x00                  ;0000000140005B9C 83 7C 24 30 00 
JGE 0x0A                                                    ;0000000140005BA1 7D 0A 
MOV dword ptr SS : [ RSP +  + 0x34 ], 0xFFFFFFFF            ;0000000140005BA3 C7 44 24 34 FF FF FF FF 
JMP 0x08                                                    ;0000000140005BAB EB 08 
MOV EAX, dword ptr SS : [ RSP +  + 0x30 ]                   ;0000000140005BAD 8B 44 24 30 
MOV dword ptr SS : [ RSP +  + 0x34 ], EAX                   ;0000000140005BB1 89 44 24 34 
MOV EAX, dword ptr SS : [ RSP +  + 0x34 ]                   ;0000000140005BB5 8B 44 24 34 
ADD RSP, 0x48                                               ;0000000140005BB9 48 83 C4 48 
RETN                                                        ;0000000140005BBD C3 
INT 3                                                       ;0000000140005BBE CC 
INT 3                                                       ;0000000140005BBF CC 
MOV qword ptr SS : [ RSP +  + 0x18 ], R8                    ;0000000140005BC0 4C 89 44 24 18 
MOV qword ptr SS : [ RSP +  + 0x10 ], RDX                   ;0000000140005BC5 48 89 54 24 10 
MOV qword ptr SS : [ RSP +  + 0x08 ], RCX                   ;0000000140005BCA 48 89 4C 24 08 
MOV qword ptr SS : [ RSP +  + 0x20 ], R9                    ;0000000140005BCF 4C 89 4C 24 20 
SUB RSP, 0x48                                               ;0000000140005BD4 48 83 EC 48 
LEA RAX, invalid ptr SS : [ RSP +  + 0x68 ]                 ;0000000140005BD8 48 8D 44 24 68 
MOV qword ptr SS : [ RSP +  + 0x38 ], RAX                   ;0000000140005BDD 48 89 44 24 38 
MOV RAX, qword ptr SS : [ RSP +  + 0x38 ]                   ;0000000140005BE2 48 8B 44 24 38 
MOV qword ptr SS : [ RSP +  + 0x20 ], RAX                   ;0000000140005BE7 48 89 44 24 20 
XOR R9D, R9D                                                ;0000000140005BEC 45 33 C9 
MOV R8, qword ptr SS : [ RSP +  + 0x60 ]                    ;0000000140005BEF 4C 8B 44 24 60 
MOV RDX, qword ptr SS : [ RSP +  + 0x58 ]                   ;0000000140005BF4 48 8B 54 24 58 
MOV RCX, qword ptr SS : [ RSP +  + 0x50 ]                   ;0000000140005BF9 48 8B 4C 24 50 
CALL 0xFFFFFF4D                                             ;0000000140005BFE E8 4D FF FF FF 
MOV dword ptr SS : [ RSP +  + 0x30 ], EAX                   ;0000000140005C03 89 44 24 30 
MOV qword ptr SS : [ RSP +  + 0x38 ], 0x00000000            ;0000000140005C07 48 C7 44 24 38 00 00 00 00 
MOV EAX, dword ptr SS : [ RSP +  + 0x30 ]                   ;0000000140005C10 8B 44 24 30 
ADD RSP, 0x48                                               ;0000000140005C14 48 83 C4 48 
RETN                                                        ;0000000140005C18 C3 
INT 3                                                       ;0000000140005C19 CC 
INT 3                                                       ;0000000140005C1A CC 
INT 3                                                       ;0000000140005C1B CC 
INT 3                                                       ;0000000140005C1C CC 
INT 3                                                       ;0000000140005C1D CC 
INT 3                                                       ;0000000140005C1E CC 
INT 3                                                       ;0000000140005C1F CC 
INT 3                                                       ;0000000140005C20 CC 
INT 3                                                       ;0000000140005C21 CC 
INT 3                                                       ;0000000140005C22 CC 
INT 3                                                       ;0000000140005C23 CC 
INT 3                                                       ;0000000140005C24 CC 
INT 3                                                       ;0000000140005C25 CC 
NOP word ptr DS : [ RAX + RAX * 1 + 0x00000000 ]            ;0000000140005C26 66 66 0F 1F 84 00 00 00 00 00 
PUSH EDI                                                    ;0000000140005C30 57 
PUSH ESI                                                    ;0000000140005C31 56 
MOV RAX, R11                                                ;0000000140005C32 49 8B C3 
MOV RDI, RCX                                                ;0000000140005C35 48 8B F9 
MOV RCX, R8                                                 ;0000000140005C38 49 8B C8 
MOV RSI, R10                                                ;0000000140005C3B 49 8B F2 
REP MOVSB                                                   ;0000000140005C3E F3 A4 
POP ESI                                                     ;0000000140005C40 5E 
POP EDI                                                     ;0000000140005C41 5F 
RETN                                                        ;0000000140005C42 C3 
INT 3                                                       ;0000000140005C43 CC 
INT 3                                                       ;0000000140005C44 CC 
INT 3                                                       ;0000000140005C45 CC 
INT 3                                                       ;0000000140005C46 CC 
INT 3                                                       ;0000000140005C47 CC 
INT 3                                                       ;0000000140005C48 CC 
NOP dword ptr DS : [ RAX + 0x00000000 ]                     ;0000000140005C49 0F 1F 80 00 00 00 00 
MOV R11, RCX                                                ;0000000140005C50 4C 8B D9 
MOV R10, RDX                                                ;0000000140005C53 4C 8B D2 
CMP R8, 0x10                                                ;0000000140005C56 49 83 F8 10 
JBE 0x64                                                    ;0000000140005C5A 76 64 
CMP R8, 0x20                                                ;0000000140005C5C 49 83 F8 20 
JBE 0x3E                                                    ;0000000140005C60 76 3E 
SUB RDX, RCX                                                ;0000000140005C62 48 2B D1 
JAE 0x0D                                                    ;0000000140005C65 73 0D 
LEA RAX, invalid ptr DS : [ R8 + R10 * 1 ]                  ;0000000140005C67 4B 8D 04 10 
CMP RCX, RAX                                                ;0000000140005C6B 48 3B C8 
JB 0x0000033C                                               ;0000000140005C6E 0F 82 3C 03 00 00 
CMP R8, 0x00000080                                          ;0000000140005C74 49 81 F8 80 00 00 00 
JBE 0x0000025F                                              ;0000000140005C7B 0F 86 5F 02 00 00 
BT CS : [ RIP + 0x00055453 ], 0x01                          ;0000000140005C81 0F BA 25 53 54 05 00 01 
JAE 0x000001A1                                              ;0000000140005C89 0F 83 A1 01 00 00 
JMP 0x9F                                                    ;0000000140005C8F EB 9F 
NOP word ptr DS : [ RAX + RAX * 1 + 0x00000000 ]            ;0000000140005C91 66 66 66 66 66 66 66 0F 1F 84 00 00 00 00 00 
MOVUPS XMM0, oword ptr DS : [ RDX ]                         ;0000000140005CA0 0F 10 02 
MOVUPS XMM1, oword ptr DS : [ RDX + R8 * 1 + 0xF0 ]         ;0000000140005CA3 42 0F 10 4C 02 F0 
MOVUPS oword ptr DS : [ RCX ], XMM0                         ;0000000140005CA9 0F 11 01 
MOVUPS oword ptr DS : [ RCX + R8 * 1 + 0xF0 ], XMM1         ;0000000140005CAC 42 0F 11 4C 01 F0 
MOV RAX, RCX                                                ;0000000140005CB2 48 8B C1 
RETN                                                        ;0000000140005CB5 C3 
NOP word ptr DS : [ RAX + RAX * 1 + 0x00000000 ]            ;0000000140005CB6 66 66 0F 1F 84 00 00 00 00 00 
MOV RAX, RCX                                                ;0000000140005CC0 48 8B C1 
LEA R9, CS : [ RIP + 0xFFFFA336 ]                           ;0000000140005CC3 4C 8D 0D 36 A3 FF FF 
MOV ECX, dword ptr DS : [ R9 + R8 * 4 + 0x00005CD7 ]        ;0000000140005CCA 43 8B 8C 81 D7 5C 00 00 
ADD RCX, R9                                                 ;0000000140005CD2 49 03 C9 
JMP RCX                                                     ;0000000140005CD5 FF E1 
AND byte ptr DS : [ RBP + 0x00 ], BL                        ;0000000140005CD7 20 5D 00 
ADD byte ptr DS : [ RDI ], BH                               ;0000000140005CDA 00 3F 
POP EBP                                                     ;0000000140005CDC 5D 
ADD byte ptr DS : [ RAX ], AL                               ;0000000140005CDD 00 00 
AND dword ptr DS : [ RBP + 0x00 ], EBX                      ;0000000140005CDF 21 5D 00 
ADD byte ptr DS : [ RDI ], CH                               ;0000000140005CE2 00 2F 
POP EBP                                                     ;0000000140005CE4 5D 
ADD byte ptr DS : [ RAX ], AL                               ;0000000140005CE5 00 00 
PUSH 0x7000005D                                             ;0000000140005CE7 68 5D 00 00 70 
POP EBP                                                     ;0000000140005CEC 5D 
ADD byte ptr DS : [ RAX ], AL                               ;0000000140005CED 00 00 
SBB byte ptr DS : [ RBP + 0x00 ], 0x00                      ;0000000140005CEF 80 5D 00 00 
NOP                                                         ;0000000140005CF3 90 
POP EBP                                                     ;0000000140005CF4 5D 
ADD byte ptr DS : [ RAX ], AL                               ;0000000140005CF5 00 00 
SUB byte ptr DS : [ RBP + 0x00 ], BL                        ;0000000140005CF7 28 5D 00 
ADD AL, AL                                                  ;0000000140005CFA 00 C0 
POP EBP                                                     ;0000000140005CFC 5D 
ADD byte ptr DS : [ RAX ], AL                               ;0000000140005CFD 00 00 
RCR byte ptr DS : [ RBP + 0x00 ], 1                         ;0000000140005CFF D0 5D 00 
ADD byte ptr DS : [ RAX + 0x5D ], DL                        ;0000000140005D02 00 50 5D 
ADD byte ptr DS : [ RAX ], AL                               ;0000000140005D05 00 00 
LOOPNZ 0x5D                                                 ;0000000140005D07 E0 5D 
ADD byte ptr DS : [ RAX ], AL                               ;0000000140005D09 00 00 
TEST AL, 0x5D                                               ;0000000140005D0B A8 5D 
ADD byte ptr DS : [ RAX ], AL                               ;0000000140005D0D 00 00 
