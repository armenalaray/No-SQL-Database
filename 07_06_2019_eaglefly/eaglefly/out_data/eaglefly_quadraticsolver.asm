-64
FLDCW CS : [ RIP + 0x0000200E ]                             ;0000000140001000 D9 2D 0E 20 00 00 
FLD1                                                        ;0000000140001006 D9 E8 
FLD1                                                        ;0000000140001008 D9 E8 
FADDP                                                       ;000000014000100A DE C1 
FMUL CS : [ RIP + 0x00001FEE ]                              ;000000014000100C D8 0D EE 1F 00 00 
FLD ST(0)                                                   ;0000000140001012 D9 C0 
FADD ST0, ST(0)                                             ;0000000140001014 D8 C0 
FMUL CS : [ RIP + 0x00001FEC ]                              ;0000000140001016 D8 0D EC 1F 00 00 
FLD CS : [ RIP + 0x00001FE2 ]                               ;000000014000101C D9 05 E2 1F 00 00 
FMUL ST0, ST(0)                                             ;0000000140001022 D8 C8 
FSUB ST0, ST(1)                                             ;0000000140001024 D8 E1 
FCOM CS : [ RIP + 0x00001FEA ]                              ;0000000140001026 DC 15 EA 1F 00 00 
FWAIT                                                       ;000000014000102C 9B 
FNSTSW AX                                                   ;000000014000102D DF E0 
SAHF                                                        ;000000014000102F 9E 
JA 0x01                                                     ;0000000140001030 77 01 
RETN                                                        ;0000000140001032 C3 
FSQRT                                                       ;0000000140001033 D9 FA 
FLD CS : [ RIP + 0x00001FC9 ]                               ;0000000140001035 D9 05 C9 1F 00 00 
FCHS                                                        ;000000014000103B D9 E0 
FADD ST0, ST(1)                                             ;000000014000103D D8 C1 
FDIV ST0, ST(3)                                             ;000000014000103F D8 F3 
FSTP CS : [ RIP + 0x00001FC5 ]                              ;0000000140001041 D9 1D C5 1F 00 00 
FLD CS : [ RIP + 0x00001FB7 ]                               ;0000000140001047 D9 05 B7 1F 00 00 
FCHS                                                        ;000000014000104D D9 E0 
FSUB ST0, ST(1)                                             ;000000014000104F D8 E1 
FDIV ST0, ST(3)                                             ;0000000140001051 D8 F3 
FSTP CS : [ RIP + 0x00001FB7 ]                              ;0000000140001053 D9 1D B7 1F 00 00 
RETN                                                        ;0000000140001059 C3 
ADD byte ptr DS : [ RAX ], AL                               ;000000014000105A 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;000000014000105C 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;000000014000105E 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;0000000140001060 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;0000000140001062 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;0000000140001064 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;0000000140001066 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;0000000140001068 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;000000014000106A 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;000000014000106C 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;000000014000106E 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;0000000140001070 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;0000000140001072 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;0000000140001074 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;0000000140001076 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;0000000140001078 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;000000014000107A 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;000000014000107C 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;000000014000107E 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;0000000140001080 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;0000000140001082 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;0000000140001084 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;0000000140001086 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;0000000140001088 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;000000014000108A 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;000000014000108C 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;000000014000108E 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;0000000140001090 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;0000000140001092 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;0000000140001094 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;0000000140001096 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;0000000140001098 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;000000014000109A 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;000000014000109C 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;000000014000109E 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;00000001400010A0 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;00000001400010A2 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;00000001400010A4 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;00000001400010A6 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;00000001400010A8 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;00000001400010AA 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;00000001400010AC 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;00000001400010AE 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;00000001400010B0 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;00000001400010B2 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;00000001400010B4 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;00000001400010B6 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;00000001400010B8 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;00000001400010BA 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;00000001400010BC 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;00000001400010BE 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;00000001400010C0 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;00000001400010C2 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;00000001400010C4 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;00000001400010C6 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;00000001400010C8 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;00000001400010CA 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;00000001400010CC 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;00000001400010CE 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;00000001400010D0 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;00000001400010D2 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;00000001400010D4 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;00000001400010D6 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;00000001400010D8 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;00000001400010DA 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;00000001400010DC 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;00000001400010DE 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;00000001400010E0 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;00000001400010E2 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;00000001400010E4 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;00000001400010E6 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;00000001400010E8 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;00000001400010EA 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;00000001400010EC 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;00000001400010EE 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;00000001400010F0 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;00000001400010F2 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;00000001400010F4 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;00000001400010F6 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;00000001400010F8 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;00000001400010FA 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;00000001400010FC 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;00000001400010FE 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;0000000140001100 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;0000000140001102 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;0000000140001104 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;0000000140001106 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;0000000140001108 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;000000014000110A 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;000000014000110C 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;000000014000110E 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;0000000140001110 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;0000000140001112 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;0000000140001114 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;0000000140001116 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;0000000140001118 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;000000014000111A 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;000000014000111C 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;000000014000111E 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;0000000140001120 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;0000000140001122 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;0000000140001124 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;0000000140001126 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;0000000140001128 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;000000014000112A 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;000000014000112C 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;000000014000112E 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;0000000140001130 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;0000000140001132 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;0000000140001134 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;0000000140001136 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;0000000140001138 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;000000014000113A 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;000000014000113C 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;000000014000113E 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;0000000140001140 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;0000000140001142 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;0000000140001144 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;0000000140001146 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;0000000140001148 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;000000014000114A 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;000000014000114C 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;000000014000114E 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;0000000140001150 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;0000000140001152 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;0000000140001154 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;0000000140001156 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;0000000140001158 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;000000014000115A 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;000000014000115C 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;000000014000115E 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;0000000140001160 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;0000000140001162 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;0000000140001164 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;0000000140001166 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;0000000140001168 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;000000014000116A 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;000000014000116C 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;000000014000116E 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;0000000140001170 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;0000000140001172 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;0000000140001174 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;0000000140001176 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;0000000140001178 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;000000014000117A 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;000000014000117C 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;000000014000117E 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;0000000140001180 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;0000000140001182 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;0000000140001184 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;0000000140001186 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;0000000140001188 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;000000014000118A 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;000000014000118C 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;000000014000118E 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;0000000140001190 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;0000000140001192 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;0000000140001194 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;0000000140001196 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;0000000140001198 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;000000014000119A 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;000000014000119C 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;000000014000119E 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;00000001400011A0 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;00000001400011A2 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;00000001400011A4 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;00000001400011A6 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;00000001400011A8 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;00000001400011AA 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;00000001400011AC 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;00000001400011AE 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;00000001400011B0 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;00000001400011B2 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;00000001400011B4 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;00000001400011B6 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;00000001400011B8 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;00000001400011BA 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;00000001400011BC 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;00000001400011BE 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;00000001400011C0 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;00000001400011C2 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;00000001400011C4 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;00000001400011C6 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;00000001400011C8 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;00000001400011CA 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;00000001400011CC 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;00000001400011CE 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;00000001400011D0 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;00000001400011D2 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;00000001400011D4 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;00000001400011D6 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;00000001400011D8 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;00000001400011DA 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;00000001400011DC 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;00000001400011DE 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;00000001400011E0 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;00000001400011E2 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;00000001400011E4 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;00000001400011E6 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;00000001400011E8 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;00000001400011EA 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;00000001400011EC 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;00000001400011EE 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;00000001400011F0 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;00000001400011F2 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;00000001400011F4 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;00000001400011F6 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;00000001400011F8 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;00000001400011FA 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;00000001400011FC 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;00000001400011FE 00 00 
ADD byte ptr DS : [ RAX ], AL                               ;0000000140001200 00 00 
