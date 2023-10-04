//////////////////////////////////////////////////////
//
//Author: Alejandro Armenta 
//Date: 2019
//File: eaglefly_decoder.cpp
//Company: 
//
//All rights reserved.
//
//////////////////////////////////////////////////////

/*

NOTE(Alex): eaglefly_disasm___.h
//NOTE(Alex): EagleFly Disasm
Platform independednt disassembler 


IMPORTANT(Alex): Intel Instruction Format Manual Pages

- Effective Operand Size and Address Size Attributes                           83
- Programming with General purpose Instructions                               169
- Instruction Set Reference Index                                             478
- Instruction Format (General) 16/32-bit MODRM and 32-bit SIB tables          505
- Instruction Set Reference A-L                                               573
- Appendix A Opcode Map                                                      2497
- Appendix B Instruction formats en encodings                                2527
- Instructions Index                                                          479
- EFLAGS condition codes table                                                417

- TODO(Alex): x87 FPU reading                                                 198 
- MS MASM 6.0 Programmer’s Guide                                        5.1.3.2  String Instructions
Windows Internals - Terminal Services and multiple sessions
Programming the windows driver model                                    2.2.3 Legacy Devices 
Instruction set summary

-General purpose
    -x87 FPU
    -x87 FPU and SIMD state management
    -Intel® MMX technology
    -SSE extensions
    -SSE2 extensions
    -SSE3 extensions
    -SSSE3 extensions
    -SSE4 extensions
    -AESNI and PCLMULQDQ
    -Intel® AVX extensions
    -F16C, RDRAND, RDSEED, FS/GS base access
    -FMA extensions
    -Intel® AVX2 extensions
    -Intel® Transactional Synchronization extensions
    -System instructions
    -IA-32e mode: 64-bit mode instructions
    -VMX instructions
    -SMX instructions
    -ADCX and ADOX
    -Intel® Memory Protection Extensions
    -Intel® Security Guard Extensions
    
    Sesgment register defaults:
    Register Used  ,  Segment Used  ,    Default selection rules
    CS             ,   Code Segmet  ,    All instruction fetches
    SS             ,   Stack Segmet  ,   All stack pushes an pops, any memory reference that uses the ESP or EBP register as a base register.
    DS             ,   Data Segment  ,   All data references, except when relative to stack or string destination.
    ES             ,   Data Segment pointed to with the ES register  ,   Destination of string instructions
    
    
    F0 lock prefix
    F2 REP / REPNE / REPNZ / SSE2 prefix Scalar double precision prefix
    66 Operand Size override prefix / precision size override prefix (sse2)
    F3 REP / REPZ / REPE / SSE1 prefix Scalar single precision prefix  
    67 Address size override prefix 
    0F 
	
/////////////////////////////////////////////////////////////////////////////
Binary Analysis

What's data and what's code?
What's the purpose and structure of data?
Making binary patching -keep functions the same size so that you dont modify other sections' code.

data vs code
-dense ISA - most opcode values are occupied therefore you cannot use it to identify 
-the instruction set is variable length - you dont where does the next code or data piece will start
-memory unaligned accessess - therefore identifying data by its sections is not possible
-if you have symbol information access then you know where each function is! and how it is called how nice isnt it?
but that's not the normal case so probably leave as an option.

/////////////////////////////////////////////////////////////////////////////    

    NOTE(Alex): Opcode ID's layout
    
    when instruction operands must be memory operands, per example FISTP <Mqi> the opcode id will look like something like this
    
    0xDF mod 7 rm
    
    later on using the grammar we assert that mod < 3 so that we make sure is a valid instruction, if not we treat it as data.
    
    Instruction Prefixes:
	
CHECKED (16,32,64 modes) 
Repeat prefixes REP/REPNE are used with: 
MOVS, 
SCAS, 
LODS,
STOS, 
CMPS, 
INS,
OUTS


LOCK prefix used with these insruction only when dest operand is a memory operand: 
ADD, 
ADC,
AND,
BTC,  
BTR,
BTS, 
CMPXCHG, 
CMPXCHG8B,
CMPXCHG16B, 
DEC, 
INC, 
NEG, 
NOT, 
OR, 
SBB, 
SUB, 
XOR, 
XADD, 
XCHG



Branch hint prefixes (2EH, 3EH)
only with conditional branch instructions (Jcc).

Control transfer instructions:

reltaive address - is an offset with respect to the address of the EIP register.
The destination address a near pointer is formed by adding the displacement to the address in the EIP register.
Jumps can be forward or backward.

Absolute address is an offset from address 0 of a segment. two ways:

-an address in a GPR - near pointer, which is copied into the EIP register.
-an address specified using the standard addressing modes of the processor. here the address can be a near pointer or a far pointer
-  If far pointer: 
-     segment selector -> CS
-     offset -> EIP

-  If near pointer:
-     offset -> EIP

unconditional - near transfer or far transfer

JMP - the transfer is one way, no return instruction pointer is saved - 
the address can be a relative address or an absolute address.
In protected mode the JMP instruction also allows jumps to a call gate, a task gate, and a task state segment.

CALL - 
RET n - the n values removed from the stack are removed after the Return IP Value is loaded back on RIP. 

INT - the contents of the EFLAGS register are stored on the stack along with the return instruction pointer before servicing the interrupt
IRET - similar to RET except that also pops EFLAGS from the stack to the EFLAGS register.

conditional -

Jcc - relative address - doesnt allow far transfers.
JCXZ - test the rCX register

LOOP - decrement RCX register then Compare if equal to zero 

JECXZ after_loop
begin_loop:

;some code

LOOP begin_loop
after_loop:

software interrupts


THINGS TO DO:

Fast structure look up! 
- structure identification
0: kd> dt nt!_KINTERRUPT
   +0x000 Type             : Int2B
   +0x002 Size             : Int2B
   +0x008 InterruptListEntry : _LIST_ENTRY
          0: kd> dt nt!_LIST_ENTRY
          +0x000 Flink            : Ptr64 _LIST_ENTRY
          +0x008 Blink            : Ptr64 _LIST_ENTRY
		  
   +0x018 ServiceRoutine   : Ptr64     unsigned char 
   +0x020 MessageServiceRoutine : Ptr64     unsigned char 
   +0x028 MessageIndex     : Uint4B
   +0x030 ServiceContext   : Ptr64 Void
   +0x038 SpinLock         : Uint8B
   +0x040 TickCount        : Uint4B
   +0x048 ActualLock       : Ptr64 Uint8B
   +0x050 DispatchAddress  : Ptr64     void 
   +0x058 Vector           : Uint4B
   +0x05c Irql             : UChar
   +0x05d SynchronizeIrql  : UChar
   +0x05e FloatingSave     : UChar
   +0x05f Connected        : UChar
   +0x060 Number           : Uint4B
   +0x064 ShareVector      : UChar
   +0x065 EmulateActiveBoth : UChar
   +0x066 ActiveCount      : Uint2B
   +0x068 InternalState    : Int4B
   +0x06c Mode             : _KINTERRUPT_MODE
          0: kd> dt nt!_KINTERRUPT_MODE
          LevelSensitive = 0n0
          Latched = 0n1
		  
		  
   +0x070 Polarity         : _KINTERRUPT_POLARITY
      0: kd> dt nt!_KINTERRUPT_POLARITY
      InterruptPolarityUnknown = 0n0
      InterruptActiveHigh = 0n1
      InterruptRisingEdge = 0n1
      InterruptActiveLow = 0n2
      InterruptFallingEdge = 0n2
      InterruptActiveBoth = 0n3
      InterruptActiveBothTriggerLow = 0n3
      InterruptActiveBothTriggerHigh = 0n4
	  
   +0x074 ServiceCount     : Uint4B
   +0x078 DispatchCount    : Uint4B
   +0x080 PassiveEvent     : Ptr64 _KEVENT
   0: kd> dt nt!_KEVENT
      +0x000 Header           : _DISPATCHER_HEADER
	  
   +0x088 TrapFrame        : Ptr64 _KTRAP_FRAME
      0: kd> dt nt!_KTRAP_FRAME
         +0x000 P1Home           : Uint8B
         +0x008 P2Home           : Uint8B
         +0x010 P3Home           : Uint8B
         +0x018 P4Home           : Uint8B
         +0x020 P5               : Uint8B
         +0x028 PreviousMode     : Char
         +0x029 PreviousIrql     : UChar
         +0x02a FaultIndicator   : UChar
         +0x02b ExceptionActive  : UChar
         +0x02c MxCsr            : Uint4B
         +0x030 Rax              : Uint8B
         +0x038 Rcx              : Uint8B
         +0x040 Rdx              : Uint8B
         +0x048 R8               : Uint8B
         +0x050 R9               : Uint8B
         +0x058 R10              : Uint8B
         +0x060 R11              : Uint8B
         +0x068 GsBase           : Uint8B
         +0x068 GsSwap           : Uint8B
         +0x070 Xmm0             : _M128A
         +0x080 Xmm1             : _M128A
         +0x090 Xmm2             : _M128A
         +0x0a0 Xmm3             : _M128A
         +0x0b0 Xmm4             : _M128A
         +0x0c0 Xmm5             : _M128A
         +0x0d0 FaultAddress     : Uint8B
         +0x0d0 ContextRecord    : Uint8B
         +0x0d0 TimeStampCKCL    : Uint8B
         +0x0d8 Dr0              : Uint8B
         +0x0e0 Dr1              : Uint8B
         +0x0e8 Dr2              : Uint8B
         +0x0f0 Dr3              : Uint8B
         +0x0f8 Dr6              : Uint8B
         +0x100 Dr7              : Uint8B
         +0x108 DebugControl     : Uint8B
         +0x110 LastBranchToRip  : Uint8B
         +0x118 LastBranchFromRip : Uint8B
         +0x120 LastExceptionToRip : Uint8B
         +0x128 LastExceptionFromRip : Uint8B
         +0x130 SegDs            : Uint2B
         +0x132 SegEs            : Uint2B
         +0x134 SegFs            : Uint2B
         +0x136 SegGs            : Uint2B
         +0x138 TrapFrame        : Uint8B
         +0x140 Rbx              : Uint8B
         +0x148 Rdi              : Uint8B
         +0x150 Rsi              : Uint8B
         +0x158 Rbp              : Uint8B
         +0x160 ErrorCode        : Uint8B
         +0x160 ExceptionFrame   : Uint8B
         +0x160 TimeStampKlog    : Uint8B
         +0x168 Rip              : Uint8B
         +0x170 SegCs            : Uint2B
         +0x172 Fill0            : UChar
         +0x173 Logging          : UChar
         +0x174 Fill1            : [2] Uint2B
         +0x178 EFlags           : Uint4B
         +0x17c Fill2            : Uint4B
         +0x180 Rsp              : Uint8B
         +0x188 SegSs            : Uint2B
         +0x18a Fill3            : Uint2B
         +0x18c Fill4            : Uint4B
		 
   +0x090 DisconnectData   : Ptr64 Void
   +0x098 ServiceThread    : Ptr64 _KTHREAD
0: kd> dt nt!_KTHREAD
   +0x000 Header           : _DISPATCHER_HEADER
   +0x018 SListFaultAddress : Ptr64 Void
   +0x020 QuantumTarget    : Uint8B
   +0x028 InitialStack     : Ptr64 Void
   +0x030 StackLimit       : Ptr64 Void
   +0x038 StackBase        : Ptr64 Void
   +0x040 ThreadLock       : Uint8B
   +0x048 CycleTime        : Uint8B
   +0x050 CurrentRunTime   : Uint4B
   +0x054 ExpectedRunTime  : Uint4B
   +0x058 KernelStack      : Ptr64 Void
   +0x060 StateSaveArea    : Ptr64 _XSAVE_FORMAT
   +0x068 SchedulingGroup  : Ptr64 _KSCHEDULING_GROUP
   +0x070 WaitRegister     : _KWAIT_STATUS_REGISTER
   +0x071 Running          : UChar
   +0x072 Alerted          : [2] UChar
   +0x074 AutoBoostActive  : Pos 0, 1 Bit
   +0x074 ReadyTransition  : Pos 1, 1 Bit
   +0x074 WaitNext         : Pos 2, 1 Bit
   +0x074 SystemAffinityActive : Pos 3, 1 Bit
   +0x074 Alertable        : Pos 4, 1 Bit
   +0x074 UserStackWalkActive : Pos 5, 1 Bit
   +0x074 ApcInterruptRequest : Pos 6, 1 Bit
   +0x074 QuantumEndMigrate : Pos 7, 1 Bit
   +0x074 UmsDirectedSwitchEnable : Pos 8, 1 Bit
   +0x074 TimerActive      : Pos 9, 1 Bit
   +0x074 SystemThread     : Pos 10, 1 Bit
   +0x074 ProcessDetachActive : Pos 11, 1 Bit
   +0x074 CalloutActive    : Pos 12, 1 Bit
   +0x074 ScbReadyQueue    : Pos 13, 1 Bit
   +0x074 ApcQueueable     : Pos 14, 1 Bit
   +0x074 ReservedStackInUse : Pos 15, 1 Bit
   +0x074 UmsPerformingSyscall : Pos 16, 1 Bit
   +0x074 TimerSuspended   : Pos 17, 1 Bit
   +0x074 SuspendedWaitMode : Pos 18, 1 Bit
   +0x074 SuspendSchedulerApcWait : Pos 19, 1 Bit
   +0x074 Reserved         : Pos 20, 12 Bits
   +0x074 MiscFlags        : Int4B
   +0x078 AutoAlignment    : Pos 0, 1 Bit
   +0x078 DisableBoost     : Pos 1, 1 Bit
   +0x078 ThreadFlagsSpare0 : Pos 2, 1 Bit
   +0x078 AlertedByThreadId : Pos 3, 1 Bit
   +0x078 QuantumDonation  : Pos 4, 1 Bit
   +0x078 EnableStackSwap  : Pos 5, 1 Bit
   +0x078 GuiThread        : Pos 6, 1 Bit
   +0x078 DisableQuantum   : Pos 7, 1 Bit
   +0x078 ChargeOnlySchedulingGroup : Pos 8, 1 Bit
   +0x078 DeferPreemption  : Pos 9, 1 Bit
   +0x078 QueueDeferPreemption : Pos 10, 1 Bit
   +0x078 ForceDeferSchedule : Pos 11, 1 Bit
   +0x078 SharedReadyQueueAffinity : Pos 12, 1 Bit
   +0x078 FreezeCount      : Pos 13, 1 Bit
   +0x078 TerminationApcRequest : Pos 14, 1 Bit
   +0x078 AutoBoostEntriesExhausted : Pos 15, 1 Bit
   +0x078 KernelStackResident : Pos 16, 1 Bit
   +0x078 CommitFailTerminateRequest : Pos 17, 1 Bit
   +0x078 ProcessStackCountDecremented : Pos 18, 1 Bit
   +0x078 ThreadFlagsSpare : Pos 19, 5 Bits
   +0x078 EtwStackTraceApcInserted : Pos 24, 8 Bits
   +0x078 ThreadFlags      : Int4B
   +0x07c Tag              : UChar
   +0x07d SystemHeteroCpuPolicy : UChar
   +0x07e UserHeteroCpuPolicy : Pos 0, 7 Bits
   +0x07e ExplicitSystemHeteroCpuPolicy : Pos 7, 1 Bit
   +0x07f Spare0           : UChar
   +0x080 SystemCallNumber : Uint4B
   +0x084 Spare10          : Uint4B
   +0x088 FirstArgument    : Ptr64 Void
   +0x090 TrapFrame        : Ptr64 _KTRAP_FRAME
   +0x098 ApcState         : _KAPC_STATE
   +0x098 ApcStateFill     : [43] UChar
   +0x0c3 Priority         : Char
   +0x0c4 UserIdealProcessor : Uint4B
   +0x0c8 WaitStatus       : Int8B
   +0x0d0 WaitBlockList    : Ptr64 _KWAIT_BLOCK
   +0x0d8 WaitListEntry    : _LIST_ENTRY
   +0x0d8 SwapListEntry    : _SINGLE_LIST_ENTRY
   +0x0e8 Queue            : Ptr64 _DISPATCHER_HEADER
   +0x0f0 Teb              : Ptr64 Void
   +0x0f8 RelativeTimerBias : Uint8B
   +0x100 Timer            : _KTIMER
   +0x140 WaitBlock        : [4] _KWAIT_BLOCK
   +0x140 WaitBlockFill4   : [20] UChar
   +0x154 ContextSwitches  : Uint4B
   +0x140 WaitBlockFill5   : [68] UChar
   +0x184 State            : UChar
   +0x185 Spare13          : Char
   +0x186 WaitIrql         : UChar
   +0x187 WaitMode         : Char
   +0x140 WaitBlockFill6   : [116] UChar
   +0x1b4 WaitTime         : Uint4B
   +0x140 WaitBlockFill7   : [164] UChar
   +0x1e4 KernelApcDisable : Int2B
   +0x1e6 SpecialApcDisable : Int2B
   +0x1e4 CombinedApcDisable : Uint4B
   +0x140 WaitBlockFill8   : [40] UChar
   +0x168 ThreadCounters   : Ptr64 _KTHREAD_COUNTERS
   +0x140 WaitBlockFill9   : [88] UChar
   +0x198 XStateSave       : Ptr64 _XSTATE_SAVE
   +0x140 WaitBlockFill10  : [136] UChar
   +0x1c8 Win32Thread      : Ptr64 Void
   +0x140 WaitBlockFill11  : [176] UChar
   +0x1f0 Ucb              : Ptr64 _UMS_CONTROL_BLOCK
   +0x1f8 Uch              : Ptr64 _KUMS_CONTEXT_HEADER
   +0x200 TebMappedLowVa   : Ptr64 Void
   +0x208 QueueListEntry   : _LIST_ENTRY
   +0x218 NextProcessor    : Uint4B
   +0x218 NextProcessorNumber : Pos 0, 31 Bits
   +0x218 SharedReadyQueue : Pos 31, 1 Bit
   +0x21c QueuePriority    : Int4B
   +0x220 Process          : Ptr64 _KPROCESS
   +0x228 UserAffinity     : _GROUP_AFFINITY
   +0x228 UserAffinityFill : [10] UChar
   +0x232 PreviousMode     : Char
   +0x233 BasePriority     : Char
   +0x234 PriorityDecrement : Char
   +0x234 ForegroundBoost  : Pos 0, 4 Bits
   +0x234 UnusualBoost     : Pos 4, 4 Bits
   +0x235 Preempted        : UChar
   +0x236 AdjustReason     : UChar
   +0x237 AdjustIncrement  : Char
   +0x238 AffinityVersion  : Uint8B
   +0x240 Affinity         : _GROUP_AFFINITY
   +0x240 AffinityFill     : [10] UChar
   +0x24a ApcStateIndex    : UChar
   +0x24b WaitBlockCount   : UChar
   +0x24c IdealProcessor   : Uint4B
   +0x250 NpxState         : Uint8B
   +0x258 SavedApcState    : _KAPC_STATE
   +0x258 SavedApcStateFill : [43] UChar
   +0x283 WaitReason       : UChar
   +0x284 SuspendCount     : Char
   +0x285 Saturation       : Char
   +0x286 SListFaultCount  : Uint2B
   +0x288 SchedulerApc     : _KAPC
   +0x288 SchedulerApcFill0 : [1] UChar
   +0x289 ResourceIndex    : UChar
   +0x288 SchedulerApcFill1 : [3] UChar
   +0x28b QuantumReset     : UChar
   +0x288 SchedulerApcFill2 : [4] UChar
   +0x28c KernelTime       : Uint4B
   +0x288 SchedulerApcFill3 : [64] UChar
   +0x2c8 WaitPrcb         : Ptr64 _KPRCB
   +0x288 SchedulerApcFill4 : [72] UChar
   +0x2d0 LegoData         : Ptr64 Void
   +0x288 SchedulerApcFill5 : [83] UChar
   +0x2db CallbackNestingLevel : UChar
   +0x2dc UserTime         : Uint4B
   +0x2e0 SuspendEvent     : _KEVENT
   +0x2f8 ThreadListEntry  : _LIST_ENTRY
   +0x308 MutantListHead   : _LIST_ENTRY
   +0x318 AbEntrySummary   : UChar
   +0x319 AbWaitEntryCount : UChar
   +0x31a Spare20          : Uint2B
   +0x31c SecureThreadCookie : Uint4B
   +0x320 LockEntries      : [6] _KLOCK_ENTRY
   +0x560 PropagateBoostsEntry : _SINGLE_LIST_ENTRY
   +0x568 IoSelfBoostsEntry : _SINGLE_LIST_ENTRY
   +0x570 PriorityFloorCounts : [16] UChar
   +0x580 PriorityFloorSummary : Uint4B
   +0x584 AbCompletedIoBoostCount : Int4B
   +0x588 KeReferenceCount : Int2B
   +0x58a AbOrphanedEntrySummary : UChar
   +0x58b AbOwnedEntryCount : UChar
   +0x58c ForegroundLossTime : Uint4B
   +0x590 GlobalForegroundListEntry : _LIST_ENTRY
   +0x590 ForegroundDpcStackListEntry : _SINGLE_LIST_ENTRY
   +0x598 InGlobalForegroundList : Uint8B
   +0x5a0 ReadOperationCount : Int8B
   +0x5a8 WriteOperationCount : Int8B
   +0x5b0 OtherOperationCount : Int8B
   +0x5b8 ReadTransferCount : Int8B
   +0x5c0 WriteTransferCount : Int8B
   +0x5c8 OtherTransferCount : Int8B
   +0x5d0 QueuedScb        : Ptr64 _KSCB
   
   +0x0a0 ConnectionData   : Ptr64 _INTERRUPT_CONNECTION_DATA
        0: kd> dt nt!_INTERRUPT_CONNECTION_DATA
        +0x000 Count            : Uint4B
        +0x008 Vectors          : [1] _INTERRUPT_VECTOR_DATA
		
   +0x0a8 IntTrackEntry    : Ptr64 Void
   +0x0b0 IsrDpcStats      : _ISRDPCSTATS
         0: kd> dt nt!_ISRDPCSTATS
            +0x000 IsrTime          : Uint8B
            +0x008 IsrTimeStart     : Uint8B
            +0x010 IsrCount         : Uint8B
            +0x018 DpcTime          : Uint8B
            +0x020 DpcTimeStart     : Uint8B
            +0x028 DpcCount         : Uint8B
            +0x030 IsrActive        : UChar
            +0x031 Reserved         : [15] UChar
			
   +0x0f0 RedirectObject   : Ptr64 Void
   +0x0f8 Padding          : [8] UChar
   
   
- structure tree layout - note when there is cycle dependency as in DOUBLY LINKED LISTS stop on the 2nd iteration
OR you can put a level of recursion as a specifier for the structure search.





PE32 exec/PE32+ exec/DLL static (shared)/DLL dynamic (shared)/COFF/LIB/ File size limit - 2 gigabytes

DLL (shared) dependency resolver - so i can resolve all dependencies and disasm all of them if the user wants!

Data resolver - Identify data and code ? how to do it, etc. globals, statics, unitialized variables, TLS, DLL pointer tables, INIT pointer tables, FINIT pointer tables, 
Type resolver - what type the data is???
-
----> for obj - probably not so difficult - debug symbol information and symbol tables.


BaseOfData - what is that? and what does it represent for asm file? - Data resolver
BaseOfCode - what is that? and what does it represent for asm file?
ImageBase - what is that? and what does it represent for asm file?
SectionAlignment - LinkerFlag
FileAlignment - LinkerFlag

SizeOfStackReserve - CompilerFlag/LinkerFlag
SizeOfStackCommit - CompilerFlag/LinkerFlag
SizeOfHeapReserve - CompilerFlag/LinkerFlag
SizeOfHeapCommit - CompilerFlag/LinkerFlag
LoaderFlags - what is that? and what does it represent for asm file?
NumberOfRvaAndSizes - what is that? and what does it represent for asm file?

-----------------------------------------------------------------------------

symbol table - Data resolver - i dont have in exe files!!

Import table - DLL resolver.
Export table - DLL resolver.

Resource table - what is that? and what does it represent for asm file?
Exception table - what is that? and what does it represent for asm file?
Certificate tabel - what is that? and what does it represent for asm file?

Base Relocation table - Loader - most of the time this should be null?
Debug - Symbol info - useful? - PDB symbol data

Arquitecture data - what is that? and what does it represent for asm file?

Global Ptr - DLL resolver.

TLS table - what is that? and what does it represent for asm file?
LoadConfigTable - what is that? and what does it represent for asm file?
BoundImport - what is that? and what does it represent for asm file?
ImportAddressTable - what is that? and what does it represent for asm file?
DelayImportDescriptor - what is that? and what does it represent for asm file?
CLRRuntimeHeader - what is that? and what does it represent for asm file?

-----------------------------------------------------------------------------


Load PDB symbol data, if any?


Make a space overlapping validator for the instruction tables - make sure that there´s no two instructions with the same opcode space 


how to solve the multiple file disassembly? multothreading - one thread per file.

Make an instruction binary tester!
- At the beginning it could be just a random instruction tester, following the tables specifications, so that every time it sees a new entry 
it generates a random instruction to test.

Platform organization

- Make macros for separating 32 bit mode code and 64 bit mode code - in that way , later on,  i can make optimizations for both systems independently!


Decoder system.

- Add stack-address width option in 32 - bit mode so tht it can be 16 bit / 32 -bit 

Instructions that use the stack implcitly (such as PUSH and POP instructions) have two address size attributes eaxh of either 16 or 32 bits. This is because they always have the implicit address of the top of the stack, and they may also have an explicit memory address(for example, PUSH Array1[EBX]).
The address size attribute of the top of the stack determines wether sp or ESP is used for the stack access. Stack operations with an address-size attribute of 16 use the 16-bit SP stack pointer register and can use a


- Make file buffered I/O abstraction system, follow Fabien Giesen's idea of having a producer and a consumer streaming system!
 - As well, have file I/O  error handling , that could be supported by the streaming system
- Virtual memory system for handling big files!
- Code optimization for instruction matching system - solutions - prefetching bits , have a lookup table as before that jumps you strainght on to the instruction?
- Buffered Bit reader system - that eventually will serve as the consumer in file I/O system!
- Complete decoder with all instruction sets!

- Multi-platform (Windows, Mac, Linux)
- address evaluator, and miscellaneus stuff.
- console commands 
- PE/COFF parser (Follow Fabien Giesen's idea for layered IO) 


Formatter system:


- generate references,

So the problem with generating asm files is that the program doesnt need to know what kind of data type it is! it will only use it and that's it, that's a work for the compiler, 
so you take the problem out of the processor and you put it on the compiler / assembler!

he doesnt need to know what type it is, he just executes instructions on data in a biased way!
so regenerating data types from hidden usage forms of the data is the only way to know, how exactly the data is used and in that way INFER what data type we are talking about!

so its an inference system. by seeing how the data is used imply what it is!


- discover stack variables,
- divide data and code,
- segmentation of each function, etc.
- 

- different Assembler formats 

look at CSAM Code Scanning and Analysis Manager Patch Manager and the (PATM), which can replace it at runtime.

SPECIAL ASPECTS:

-We have defined two important concepts user space, and developer space:

on developer space we want to assert as much as we can, so we can debug and find errors in code.
on user space we want to handle those erros in a specific way, so that we let the user get it wrong but the program wont crash!

----------------------------------------------------------------------------------
decoder user space - opcode stream buffer

possible errors:

invalid opcodes for operating mode - HANDLE - treat it as data
invalid operating mode - HANDLE - output not valid operating mode - exit
buffer not present - HANDLE - output buffer not present - exit

----------------------------------------------------------------------------------
PE parser user space - exe, dll, obj, file

possible errors:

//TODO(Alex): Possible errors

----------------------------------------------------------------------------------

the file access is going to be divided into processor modes, but how can we handle mixed buffers?, so that
we have a nice thing because, in the way we have it we divided de decoder system from the PE parser, so that we
can reconfigure the decoder for different code sections inside the PE32 file, 

opcode id 0x26 mode=e null segment override


File system:

4297576 file size - worst case scenario, think on how to compress data and or to make encoding streaming on demand!


TYPOS:

Rotate 8 bits r/m16 right imm8 times. pag. 1646
This instruction can be used with a LOCK prefix to allow the it to be executed atomically. Pag 633

The CALL (call procedure) and RET (return from procedure) (should be ICALL and IRET) instructions allow a jump from one procedure to
another and a subsequent return to the calling procedure. EFLAGS register contents are automatically stored on
the stack along with the return instruction pointer when the processor services an interrupt. Pag. 186



*/

#include <Windows.h>
#include "stdio.h"

#include "eaglefly_platform.h"
#include "eaglefly_decoder.h"

#include "eaglefly_string.cpp"
#include "eaglefly_bits.cpp"
#include "eaglefly_tables.cpp"

#include "eaglefly_pe_parser.cpp"


internal void * 
Win32AllocateMemory(memory_index Size)
{
    void * Result = 0;
    //TODO(Alex): Alignment?
    if(Size)
    {
        Result = VirtualAlloc(0, Size, MEM_RESERVE|MEM_COMMIT, PAGE_READWRITE); 
    }
    
    return Result;
}

internal void
Win32DeallocateMemory(void * Memory)
{
    if(Memory)
    {
        VirtualFree(Memory, 0, MEM_RELEASE);
    }
}


DEBUG_READ_ENTIRE_FILE(Debug_Win32ReadEntireFile)
{
    debug_file_content Result = {};
    HANDLE Handle = CreateFileA(FileName,
                                GENERIC_READ,
                                FILE_SHARE_READ,
                                0,
                                OPEN_EXISTING,
                                FILE_ATTRIBUTE_NORMAL,
                                0);
    if(Handle)
    {
        LARGE_INTEGER U64Size = {};
        if(GetFileSizeEx(Handle, &U64Size))
        {
            u32 U32Size = SafeTruncateU64ToU32(U64Size.QuadPart);
            DWORD BytesRead = 0;
            
            void * Content = Win32AllocateMemory(U32Size);
            if(ReadFile(Handle, Content, U32Size, &BytesRead,0) && 
               (BytesRead == U32Size))
            {
                Result.Content = Content;
                Result.Size = U32Size;
            }
            else
            {
                Win32DeallocateMemory(Content);
            }
        }
        else
        {
            //TODO(Alex): logging
        }
        
        CloseHandle(Handle);
    }
    else
    {
        //TODO(Alex): Check if ERROR_FILE_NOT_FOUND 
    }
    
    return Result;
}


internal void
win32_WriteFile(HANDLE STDOutHandle, void * Buffer, u32 Count)
{
    u32 TokenCharsWritten = 0;
    WriteFile(STDOutHandle, (void*)Buffer, Count, (LPDWORD)&TokenCharsWritten,0);
}

internal void
EagleflyWriteFile(disasm_state * State, void * Buffer, memory_index Count)
{
    win32_WriteFile(State->STDOutHandle, Buffer, SafeTruncateU64ToU32(Count));
}



//NOTE(Alex): x86_64 functions

/*
J - The instruction contains a relative offset to be added to the instruction pointer register (for example, JMP
                                                                                                (0E9), LOOP).
M - The ModR/M byte may refer only to memory (for example, BOUND, LES, LDS, LSS, LFS, LGS,
                                              CMPXCHG8B).
                                              
b - Byte, regardless of operand-size attribute.
z - Word for 16-bit operand-size or doubleword for 32 or 64-bit operand-size.

//NOTE(Alex): All possible assembly formats checked -- AssemblyChecked  


//NOTE(Alex): Specify for each instruction what instruction group it refers to 
so that we can know if certain prefixes are used as mandatory prefixes or not

-General purpose
-x87 FPU
-x87 FPU and SIMD state management
-Intel® MMX technology
-SSE extensions
-SSE2 extensions
-SSE3 extensions
-SSSE3 extensions
-SSE4 extensions
-AESNI and PCLMULQDQ
-Intel® AVX extensions
-F16C, RDRAND, RDSEED, FS/GS base access
-FMA extensions
-Intel® AVX2 extensions
-Intel® Transactional Synchronization extensions
-System instructions
-IA-32e mode: 64-bit mode instructions
-VMX instructions
-SMX instructions
-ADCX and ADOX
-Intel® Memory Protection Extensions
-Intel® Security Guard Extensions
*/


//NOTE(Alex): Disassembler functions 

//NOTE(Alex): f64 - The operand size is forced to a 64-bit operand size when in 64-bit mode (prefixes that change operand size are ignored for this instruction in 64-bit mode).
inline u32 
DF64(disasm_state * State, u32 DefaultOperandSize) 
{
	processor_mode ProcessorMode = State->ProcessorMode;
    u32 Result;
    
    if (ProcessorMode == ProcessorMode_64bit)
    {
        Result = operandsize_64;
    }
    else 
    {
        Result = DefaultOperandSize;
    }
    
    return Result;
}

//NOTE(Alex): i64 - The instruction is invalid or not encodable in 64-bit mode. 40 through 4F (single-byte INC and DEC) are REX prefix combinations when in 64-bit mode (use FE/FF Grp 4 and 5 for INC and DEC).
inline b32 
i64(processor_mode ProcessorMode)
{
    if (ProcessorMode == ProcessorMode_64bit) 
    { 
        return false;
    }
    else 
    {
        return true;
    }
}


//------------------------------------------------------

//N.S. — Indicates an instruction syntax that requires an address override prefix in 64-bit mode and is not supported. Using an address override prefix in 64-bit mode may result in model-specific execution behavior.
inline b32 
NS(disasm_state * State, b32 AddressSizeOverridePrefixPresent)
{
	processor_mode ProcessorMode= State->ProcessorMode;
    if(ProcessorMode == ProcessorMode_64bit && AddressSizeOverridePrefixPresent)
    {
        return false;
    }
    else
    {
        return true;
    }
}

//N.E. — Indicates an instruction syntax is not encodable in 64-bit mode (it may represent part of a sequence of valid instructions in other modes).
//func NE()



//NOTE(Alex): the 66H, F2H, F3H prefixes are mandatory for opcode extensions SSE/SSE2/SSE3/SSSE3 SIMD instructions

//Normally in a function prototype you have a well matched type system for protection.

internal void 
DefaultSizeAttributesForProcessorModes(processor_mode ProcessorMode, u32 BFlag,  u32 * out_DefaultOperandSize, u32 * out_DefaultAddressSize, u32 * out_DefaultStackAddressSize)
{
    if (ProcessorMode == ProcessorMode_64bit)
    {
        *out_DefaultAddressSize = addresssize_64;
        *out_DefaultOperandSize = operandsize_32;
        *out_DefaultStackAddressSize = addresssize_64;
    }
    
    else
    {
        if (ProcessorMode == ProcessorMode_32bit)
        {
            *out_DefaultOperandSize = operandsize_32;
            *out_DefaultAddressSize = addresssize_32;
        }
        
        else if (ProcessorMode == ProcessorMode_16bit)
        {
            *out_DefaultOperandSize = operandsize_16;
            *out_DefaultAddressSize = addresssize_16;
        }
        
        
        if(BFlag == 1)
        {
            *out_DefaultStackAddressSize = addresssize_32;
        }
        else
        {
            *out_DefaultStackAddressSize = addresssize_16;
        }
    }
    
}


internal u32 
GetEffAddressSize(processor_mode ProcessorMode, u32 DefaultAddressSize, instruction_context * ctx)
{
	b32 AddressSizeOverridePrefixPresent = ctx->AddressSizeOverridePrefixPresent;
    u32 EffAddressSize = addresssize_Invalid;
    
    if (DefaultAddressSize == addresssize_64)
    {
        if (AddressSizeOverridePrefixPresent)
        {
            EffAddressSize = addresssize_32; 
        }
        else 
        {
            EffAddressSize = addresssize_64;
        }
    }
    else if (DefaultAddressSize == addresssize_32)
    {
        if (AddressSizeOverridePrefixPresent)
        {
            EffAddressSize = addresssize_16; 
        }
        else 
        {
            EffAddressSize = addresssize_32;
        }
    }
    else if (DefaultAddressSize == addresssize_16)
    {
        if (AddressSizeOverridePrefixPresent)
        {
            EffAddressSize = addresssize_32;
        }
        else 
        {
            EffAddressSize = addresssize_16;
        }
    }
    
    Assert(EffAddressSize != addresssize_Invalid);
    return EffAddressSize;
}


internal u32 
GetEffOperandSize(processor_mode ProcessorMode, u32  DefaultOperandSize, instruction_context * ctx)
{
	bits rex = ctx->rex;
	b32 OperandSizeOverridePrefixPresent = ctx->OperandSizeOverridePrefixPresent;
	
    u32 EffOperandSize = operandsize_Invalid;
	
    if (ProcessorMode == ProcessorMode_64bit)
    {
        if (DefaultOperandSize == operandsize_32)
        {
            if (TestBit(rex, 3))
            {
                EffOperandSize = operandsize_64;
            }
            else if (OperandSizeOverridePrefixPresent)
            {
                EffOperandSize = operandsize_16;
            }
            else 
            {
                EffOperandSize = operandsize_32;
            }
        }
        else if (DefaultOperandSize == operandsize_64)
        {
            if (OperandSizeOverridePrefixPresent)
            {
                if (TestBit(rex, 3))
                {
                    EffOperandSize = operandsize_64;
                }
                else 
                {
                    EffOperandSize = operandsize_16;
                }
            }
            else 
            {
                EffOperandSize = operandsize_64;
            }
        }
    }
    else 
    {
        Assert((ProcessorMode == ProcessorMode_16bit) || (ProcessorMode == ProcessorMode_32bit));
        
        if (DefaultOperandSize == operandsize_32)
        {
            if (OperandSizeOverridePrefixPresent)
            {
                EffOperandSize = operandsize_16;
            }
            else
            {
                EffOperandSize = operandsize_32;
            }
        }
        else if (DefaultOperandSize == operandsize_16)
        {
            if (OperandSizeOverridePrefixPresent)
            {
                EffOperandSize = operandsize_32;
            }
            else
            {
                EffOperandSize = operandsize_16;
            }
        }
    }
    
    Assert(EffOperandSize != operandsize_Invalid);
    return EffOperandSize;	 
}


inline b32
MandatoryPrefixPresent(uint8_t CByte)
{
    b32 Result = 0;
    if(CByte)
    {
        Result = ((CByte == 0x66) || 
                  (CByte == 0xF2) || 
                  (CByte == 0xF3)
                  );
    }
    return Result;
}

inline b32
REXPresent(processor_mode ProcessorMode, u64 Value)
{
    b32 Result = false;
    
    if(ProcessorMode == ProcessorMode_64bit)
    {
        Result  = ((Value >= 0x40) && (Value <= 0x4F));
    }
    
    return Result;
}


inline b32 ByteIsPrefix(u64 Value)
{
    b32 Result = false;
    Result = (
        //First group
        (Value == LockPrefix) ||
        (Value == REPNE_REPNZ) ||
        (Value == REP_REPE) ||
        (Value == BND) ||
        
        //Second group
        (Value == CSOverride) ||
        (Value == SSOverride) ||
        (Value == DSOverride) ||
        (Value == ESOverride) ||
        (Value == FSOverride) ||
        (Value == GSOverride) ||
        (Value == CSOverride) ||
        (Value == CSOverride) ||
        
        (Value == BranchNotTaken) ||
        (Value == Branchtaken) ||
        
        
        //Third group
        (Value == OperandSizeOverridePrefix) ||
        
        //Fourth group
        (Value == AddressSizeOverridePrefix)
        
        );
    
    return Result;
}


internal void 
append_bitfield_crs(char * out_Buffer, u32 * out_Count, u32 Size, u32 Value)
{
    
	switch (Value)
	{
		case 0B000: { Append(out_Buffer, out_Count, Size, "CR0", StringLength("CR0")); }break;
		case 0B001: { InvalidCase(); }break;
		case 0B010: { Append(out_Buffer, out_Count, Size, "CR2", StringLength("CR2")); }break;
		case 0B011: { Append(out_Buffer, out_Count, Size, "CR3", StringLength("CR3")); }break;
		case 0B100: { Append(out_Buffer, out_Count, Size, "CR4", StringLength("CR4")); }break;
		case 0B101: { InvalidCase(); }break;
		case 0B110: { InvalidCase(); }break;
		case 0B111: { InvalidCase(); }break;
		
	}
	
}
inline void
append_bitfield_crs(string * out_string, u32 Value)
{
	append_bitfield_crs(out_string->buffer, &out_string->count, out_string->mem_size, Value);
}


//References to debug registers DR4 and DR5 cause an undefined opcode (#UD) exception to be generated when CR4.DE[bit 3] (Debugging Extensions) set; when clear, processor aliases references to registers DR4 and DR5 to DR6 and DR7 for compatibility with software written to run on earlier IA-32 processors.
internal void 
append_bitfield_drs(char * out_Buffer, u32 * out_Count, u32 Size, u32 Value)
{
	switch (Value)
	{
		case 0B000: { Append(out_Buffer, out_Count, Size, "DR0", StringLength("DR0")); }break;
		case 0B001: { Append(out_Buffer, out_Count, Size, "DR1", StringLength("DR1")); }break;
		case 0B010: { Append(out_Buffer, out_Count, Size, "DR2", StringLength("DR2")); }break;
		case 0B011: { Append(out_Buffer, out_Count, Size, "DR3", StringLength("DR3")); }break;
		case 0B100: { InvalidCase(); }break;
		case 0B101: { InvalidCase(); }break;
		case 0B110: { Append(out_Buffer, out_Count, Size, "DR6", StringLength("DR6")); }break;
		case 0B111: { Append(out_Buffer, out_Count, Size, "DR7", StringLength("DR7")); }break;
	}
}

inline void 
append_bitfield_drs(string * out_string, u32 Value)
{
	append_bitfield_drs(out_string->buffer, &out_string->count, out_string->mem_size, Value);
}

char * sreg2(bits sreg2)
{
    char * Result = 0;
    
    switch (sreg2.value)
    {
        case 0B00: { Result = "ES"; }break; 
        case 0B01: { Result = "CS"; }break;
        case 0B10: { Result = "SS"; }break;
        case 0B11: { Result = "DS"; }break;
    }
    
    return Result;
}

char * sreg3(bits sreg3)
{
    char * Result = 0;
    switch (sreg3.value)
    {
        case 0B000: { Result = "ES"; }break;
        case 0B001: { Result = "CS"; }break;
        case 0B010: { Result = "SS"; }break;
        case 0B011: { Result = "DS"; }break;
        case 0B100: { Result = "FS"; }break;
        case 0B101: { Result = "GS"; }break;
        case 0B110: { InvalidCase(); }break;
        case 0B111: { InvalidCase(); }break;
    }
    
    return Result;
}


#if 0
internal void 
append_mem_operand_size_kw_masm(char * out_Buffer, u32 * out_BufferCount, u32 BufferSize, eff_operand_size EffOperandSize)
{
	read_mem_operand_size_kw_masm(State, EffOperandSize, out_string);
}

inline void 
append_mem_operand_size_kw_masm(string * out_string, eff_operand_size EffOperandSize)
{
	append_mem_operand_size_kw_masm(out_string->buffer, &out_string->count, out_string->mem_size, EffOperandSize);
}
#endif

void reg8(bits rex, bits reg, char * out_Buffer, u32 BufferSize, b32 IsRegField)
{
    if(rex.value)
    {
        if((IsRegField) ? TestBit(rex, 2) : TestBit(rex,0))
        {
            switch(reg.value)
            {
                case 0B000: { _snprintf_s(out_Buffer, BufferSize, BufferSize, "R8B"); }break;
                case 0B001: { _snprintf_s(out_Buffer, BufferSize, BufferSize, "R9B"); }break;
                case 0B010: { _snprintf_s(out_Buffer, BufferSize, BufferSize, "R10B"); }break;
                case 0B011: { _snprintf_s(out_Buffer, BufferSize, BufferSize, "R11B"); }break;
                case 0B100: { _snprintf_s(out_Buffer, BufferSize, BufferSize, "R12B"); }break;
                case 0B101: { _snprintf_s(out_Buffer, BufferSize, BufferSize, "R13B"); }break;
                case 0B110: { _snprintf_s(out_Buffer, BufferSize, BufferSize, "R14B"); }break;
                case 0B111: { _snprintf_s(out_Buffer, BufferSize, BufferSize, "R15B"); }break;
            }
        }
        else 
        {
            switch(reg.value)
            {
                case 0B000: { _snprintf_s(out_Buffer, BufferSize, BufferSize, "AL"); }break;
                case 0B001: { _snprintf_s(out_Buffer, BufferSize, BufferSize, "CL"); }break;
                case 0B010: { _snprintf_s(out_Buffer, BufferSize, BufferSize, "DL"); }break;
                case 0B011: { _snprintf_s(out_Buffer, BufferSize, BufferSize, "BL"); }break;
                case 0B100: { _snprintf_s(out_Buffer, BufferSize, BufferSize, "SPL"); }break;
                case 0B101: { _snprintf_s(out_Buffer, BufferSize, BufferSize, "BPL"); }break;
                case 0B110: { _snprintf_s(out_Buffer, BufferSize, BufferSize, "SIL"); }break;
                case 0B111: { _snprintf_s(out_Buffer, BufferSize, BufferSize, "DIL"); }break;
            }
        }
    }
    else
    {
        switch(reg.value)
        {
            case 0B000: { _snprintf_s(out_Buffer, BufferSize, BufferSize, "AL"); }break;
            case 0B001: { _snprintf_s(out_Buffer, BufferSize, BufferSize, "CL"); }break;
            case 0B010: { _snprintf_s(out_Buffer, BufferSize, BufferSize, "DL"); }break;
            case 0B011: { _snprintf_s(out_Buffer, BufferSize, BufferSize, "BL"); }break;
            case 0B100: { _snprintf_s(out_Buffer, BufferSize, BufferSize, "AH"); }break;
            case 0B101: { _snprintf_s(out_Buffer, BufferSize, BufferSize, "CH"); }break;
            case 0B110: { _snprintf_s(out_Buffer, BufferSize, BufferSize, "DH"); }break;
            case 0B111: { _snprintf_s(out_Buffer, BufferSize, BufferSize, "BH"); }break;
        }
    }
}

#if 0
void GetReg(disasm_state * State, u32 EffOperandSize, char * out_Buffer, u32 * out_BufferCount, u32 BufferSize, bits rex, bits reg, b32 IsRegField)
{
    
    string_result_file SIBAdress = ReadRegTable(State, EffOperandSize, rex, reg, IsRegField);
    
    regexp_support RegExpSupport = {};
    if(InitRegExpSource(&RegExpSupport, SIBAdress.Base, StringLength(SIBAdress.Base)))
    {
        while(RegExpSupport.SourceAt <= RegExpSupport.SourceLast)
        {
            Append(out_Buffer, out_BufferCount, BufferSize, RegExpSupport.SourceAt++, 1);
        }
    }
    
    EndRegExp(&RegExpSupport);
    
    /*
    
    R8
    R9
    R10
    R11
    R12
    R13
    R14
    R15
    
    //////////////////////
    
    RAX
    RCX
    RDX
    RBX
    RSP
    RBP
    RSI
    RDI
    
    //////////////////////
    
    R8D
    R9D
    R10D
    R11D
    R12D
    R13D
    R14D
    R15D
    
    ///////////////////////
    
    EAX
    ECX
    EDX
    EBX
    ESP
    EBP
    ESI
    EDI
    
    //////////////////////
    
    R8W
    R9W
    R10W
    R11W
    R12W
    R13W
    R14W
    R15W
    
    ////////////////////////
    
    AX
    CX
    DX
    BX
    SP
    BP
    SI
    DI
    
    
    ///////////////////////
    
    R8B
    R9B
    R10B
    R11B
    R12B
    R13B
    R14B
    R15B
    
    ///////////////////////
    
    AL
    CL
    DL
    BL
    SPL
    BPL
    SIL
    DIL
    
    ///////////////////////
    
    AL
    CL
    DL
    BL
    AH
    CH
    DH
    BH
    
    */
    
    if (EffOperandSize == 8) reg8(rex, reg, out_Buffer, BufferSize, IsRegField);
    else if(EffOperandSize == 64)
    {
        if ((IsRegField) ? TestBit(rex, 2) : TestBit(rex,0))
        {
            switch(reg.value)
            {
                case 0b000: { _snprintf_s(out_Buffer, BufferSize, BufferSize, "R8"); }break;
                case 0b001: { _snprintf_s(out_Buffer, BufferSize, BufferSize, "R9"); }break;
                case 0b010: { _snprintf_s(out_Buffer, BufferSize, BufferSize, "R10"); }break;
                case 0b011: { _snprintf_s(out_Buffer, BufferSize, BufferSize, "R11"); }break;
                case 0b100: { _snprintf_s(out_Buffer, BufferSize, BufferSize, "R12"); }break;
                case 0b101: { _snprintf_s(out_Buffer, BufferSize, BufferSize, "R13"); }break;
                case 0b110: { _snprintf_s(out_Buffer, BufferSize, BufferSize, "R14"); }break;
                case 0b111: { _snprintf_s(out_Buffer, BufferSize, BufferSize, "R15"); }break;
            }
        }
        else
        {
            switch(reg.value)
            {
                case 0b000: { _snprintf_s(out_Buffer, BufferSize, BufferSize, "RAX"); }break;
                case 0b001: { _snprintf_s(out_Buffer, BufferSize, BufferSize, "RCX"); }break;
                case 0b010: { _snprintf_s(out_Buffer, BufferSize, BufferSize, "RDX"); }break;
                case 0b011: { _snprintf_s(out_Buffer, BufferSize, BufferSize, "RBX"); }break;
                case 0b100: { _snprintf_s(out_Buffer, BufferSize, BufferSize, "RSP"); }break;
                case 0b101: { _snprintf_s(out_Buffer, BufferSize, BufferSize, "RBP"); }break;
                case 0b110: { _snprintf_s(out_Buffer, BufferSize, BufferSize, "RSI"); }break;
                case 0b111: { _snprintf_s(out_Buffer, BufferSize, BufferSize, "RDI"); }break;
            }
        }
    }
    else if(EffOperandSize == 32)
    {
        if((IsRegField) ? TestBit(rex, 2) : TestBit(rex,0))
        {
            switch(reg.value)
            {
                case 0b000: { _snprintf_s(out_Buffer, BufferSize, BufferSize, "R8D"); }break;
                case 0b001: { _snprintf_s(out_Buffer, BufferSize, BufferSize, "R9D"); }break;
                case 0b010: { _snprintf_s(out_Buffer, BufferSize, BufferSize, "R10D"); }break;
                case 0b011: { _snprintf_s(out_Buffer, BufferSize, BufferSize, "R11D"); }break;
                case 0b100: { _snprintf_s(out_Buffer, BufferSize, BufferSize, "R12D"); }break;
                case 0b101: { _snprintf_s(out_Buffer, BufferSize, BufferSize, "R13D"); }break;
                case 0b110: { _snprintf_s(out_Buffer, BufferSize, BufferSize, "R14D"); }break;
                case 0b111: { _snprintf_s(out_Buffer, BufferSize, BufferSize, "R15D"); }break;
            }
        }
        else
        {
            switch(reg.value)
            {
                case 0b000: { _snprintf_s(out_Buffer, BufferSize, BufferSize, "EAX"); }break;
                case 0b001: { _snprintf_s(out_Buffer, BufferSize, BufferSize, "ECX"); }break;
                case 0b010: { _snprintf_s(out_Buffer, BufferSize, BufferSize, "EDX"); }break;
                case 0b011: { _snprintf_s(out_Buffer, BufferSize, BufferSize, "EBX"); }break;
                case 0b100: { _snprintf_s(out_Buffer, BufferSize, BufferSize, "ESP"); }break;
                case 0b101: { _snprintf_s(out_Buffer, BufferSize, BufferSize, "EBP"); }break;
                case 0b110: { _snprintf_s(out_Buffer, BufferSize, BufferSize, "ESI"); }break;
                case 0b111: { _snprintf_s(out_Buffer, BufferSize, BufferSize, "EDI"); }break;
            }
        }
    }
    else if(EffOperandSize == 16)
    {
        if((IsRegField) ? TestBit(rex, 2) : TestBit(rex,0))
        {
            switch(reg.value)
            {
                case 0b000: { _snprintf_s(out_Buffer, BufferSize, BufferSize, "R8W"); }break;
                case 0b001: { _snprintf_s(out_Buffer, BufferSize, BufferSize, "R9W"); }break;
                case 0b010: { _snprintf_s(out_Buffer, BufferSize, BufferSize, "R10W"); }break;
                case 0b011: { _snprintf_s(out_Buffer, BufferSize, BufferSize, "R11W"); }break;
                case 0b100: { _snprintf_s(out_Buffer, BufferSize, BufferSize, "R12W"); }break;
                case 0b101: { _snprintf_s(out_Buffer, BufferSize, BufferSize, "R13W"); }break;
                case 0b110: { _snprintf_s(out_Buffer, BufferSize, BufferSize, "R14W"); }break;
                case 0b111: { _snprintf_s(out_Buffer, BufferSize, BufferSize, "R15W"); }break;
            }
        }
        else
        {
            switch(reg.value)
            {
                case 0b000: { _snprintf_s(out_Buffer, BufferSize, BufferSize, "AX"); }break;
                case 0b001: { _snprintf_s(out_Buffer, BufferSize, BufferSize, "CX"); }break;
                case 0b010: { _snprintf_s(out_Buffer, BufferSize, BufferSize, "DX"); }break;
                case 0b011: { _snprintf_s(out_Buffer, BufferSize, BufferSize, "BX"); }break;
                case 0b100: { _snprintf_s(out_Buffer, BufferSize, BufferSize, "SP"); }break;
                case 0b101: { _snprintf_s(out_Buffer, BufferSize, BufferSize, "BP"); }break;
                case 0b110: { _snprintf_s(out_Buffer, BufferSize, BufferSize, "SI"); }break;
                case 0b111: { _snprintf_s(out_Buffer, BufferSize, BufferSize, "DI"); }break;
            }
        }
    }
}
#endif

inline void PrintImmediateToBuffer(char * out_Buffer, u32 BufferSize, u32 Size, bits BitField)
{
    bits LE = {};
    LE = SwapBitfieldBytes(BitField);
    _snprintf_s(out_Buffer, BufferSize, BufferSize, " %0*llXh ", BitSizeToHexSize(Size), LE.value);
}

//TODO(Alex): REMOVE THIS!!
internal void 
GetSegmentOverridePrefixTable(group2_prefix SegmentOverridePrefix, char * out_Buffer, u32 BufferSize)
{
    
}

internal void 
append_segment_reg_masm(group2_prefix SegmentOverridePrefix, char * out_Buffer, u32 * out_BufferCount, u32 BufferSize)
{
    
    switch(SegmentOverridePrefix)
    {
        //Group 2 prefixes
        case group2_CSOverride:
        {
            Append(out_Buffer, out_BufferCount, BufferSize, "CS", StringLength("CS"));
        }break;
        
        case group2_SSOverride:
        {
            Append(out_Buffer, out_BufferCount, BufferSize, "SS", StringLength("SS"));
        }break;
        
        case group2_DSOverride:
        {
            Append(out_Buffer, out_BufferCount, BufferSize, "DS", StringLength("DS"));
        }break;
        
        case group2_ESOverride:
        {
            Append(out_Buffer, out_BufferCount, BufferSize, "ES", StringLength("ES"));
        }break;
        
        case group2_FSOverride:
        {
            Append(out_Buffer, out_BufferCount, BufferSize, "FS", StringLength("FS"));
        }break;
        
        case group2_GSOverride:
        {
            Append(out_Buffer, out_BufferCount, BufferSize, "GS", StringLength("GS"));
        }break;
        
    };
	
    
}


internal void 
append_segment_reg_masm(group2_prefix SegmentOverridePrefix, string * out_string)
{
    append_segment_reg_masm(SegmentOverridePrefix, out_string->buffer, &out_string->count, out_string->mem_size);
}

void GetSS(disasm_state * State, eff_address_size EffAddressSize, group2_prefix SegmentOverridePrefix, char * out_Buffer, u32 * out_BufferCount, u32 BufferSize, bits rex, bits ss, bits index, bits base)
{
    Assert(EffAddressSize != 16);
    
	u32 ss_s_mem_size = (1 << 8);
	string ss_s ={};
	make_string_size(&State->i_write_arena.Arena, &ss_s, 0, ss_s_mem_size);
	
    ReadSIBTable(State, EffAddressSize, TestBit(rex, 1), ss.value, index.value, &ss_s);
    
    regexp_support RegExpSupport = {};
    char * At = 0;
    if(InitRegExpSource(&RegExpSupport, ss_s.buffer, ss_s.count, &At))
    {
        while(PtrInsideString(&RegExpSupport, At))
        {
            Append(out_Buffer, out_BufferCount, BufferSize, At++, 1);
        }
    }
    
    EndRegExp(&RegExpSupport);
    
    
    /*
    
    R8 * 1
    R9 * 1
    R10 * 1
    R11 * 1
    R12 * 1
    R13 * 1
    R14 * 1
    R15 * 1
    
    R8 * 2
    R9 * 2
    R10 * 2
    R11 * 2
    R12 * 2
    R13 * 2
    R14 * 2
    R15 * 2
    
    R8 * 4
    R9 * 4
    R10 * 4
    R11 * 4
    R12 * 4
    R13 * 4
    R14 * 4
    R15 * 4
    
    R8 * 8
    R9 * 8
    R10 * 8
    R11 * 8
    R12 * 8
    R13 * 8
    R14 * 8
    R15 * 8
    
    ////////////////////////////////
    
    RAX * 1
    RCX * 1
    RDX * 1
    RBX * 1
    ""
    RBP * 1
    RSI * 1
    RDI * 1
    
    RAX * 2
    RCX * 2
    RDX * 2
    RBX * 2
    ""
    RBP * 2
    RSI * 2
    RDI * 2
    
    RAX * 4
    RCX * 4
    RDX * 4
    RBX * 4
    ""
    RBP * 4
    RSI * 4
    RDI * 4
    
    RAX * 8
    RCX * 8
    RDX * 8
    RBX * 8
    ""
    RBP * 8
    RSI * 8
    RDI * 8
    
    /////////////////////////////////
    
    R8D * 1
    R9D * 1
    R10D * 1
    R11D * 1
    R12D * 1
    R13D * 1
    R14D * 1
    R15D * 1
    
    R8D * 2
    R9D * 2
    R10D * 2
    R11D * 2
    R12D * 2
    R13D * 2
    R14D * 2
    R15D * 2
    
    R8D * 4
    R9D * 4
    R10D * 4
    R11D * 4
    R12D * 4
    R13D * 4
    R14D * 4
    R15D * 4
    
    R8D * 8
    R9D * 8
    R10D * 8
    R11D * 8
    R12D * 8
    R13D * 8
    R14D * 8
    R15D * 8
    
    ////////////////////////////////////
    
    
    EAX * 1
    ECX * 1
    EDX * 1
    EBX * 1
    ""
    EBP * 1
    ESI * 1
    EDI * 1
    
    EAX * 2
    ECX * 2
    EDX * 2
    EBX * 2
    ""
    EBP * 2
    ESI * 2
    EDI * 2
    
    EAX * 4
    ECX * 4
    EDX * 4
    EBX * 4
    ""
    EBP * 4
    ESI * 4
    EDI * 4
    
    EAX * 8
    ECX * 8
    EDX * 8
    EBX * 8
    ""
    EBP * 8
    ESI * 8
    EDI * 8
    
    */
    
#if 0    
    if(EffAddressSize == 64)
    {
        if (TestBit(rex, 1))
        {
            switch(ss.value)
            {
                case 0B00:
                {
                    switch(index.value)
                    {
                        case 0B000: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + R8 * 1" , BaseBuffer); }break;
                        case 0B001: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + R9 * 1" , BaseBuffer); }break;
                        case 0B010: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + R10 * 1", BaseBuffer); }break;
                        case 0B011: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + R11 * 1", BaseBuffer); }break;
                        case 0B100: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + R12 * 1", BaseBuffer); }break;
                        case 0B101: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + R13 * 1", BaseBuffer); }break;
                        case 0B110: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + R14 * 1", BaseBuffer); }break;
                        case 0B111: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + R15 * 1", BaseBuffer); }break;
                    }
                }break;
                
                case 0B01:
                {
                    switch(index.value) 
                    {
                        case 0B000: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + R8 * 2", BaseBuffer); }break;
                        case 0B001: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + R9 * 2", BaseBuffer); }break;
                        case 0B010: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + R10 * 2", BaseBuffer); }break;
                        case 0B011: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + R11 * 2", BaseBuffer); }break;
                        case 0B100: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + R12 * 2", BaseBuffer); }break;
                        case 0B101: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + R13 * 2", BaseBuffer); }break;
                        case 0B110: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + R14 * 2", BaseBuffer); }break;
                        case 0B111: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + R15 * 2", BaseBuffer); }break;	
                    }
                }break;
                
                case 0B10:
                {
                    switch(index.value)
                    {
                        case 0B000: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + R8 * 4", BaseBuffer); }break;
                        case 0B001: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + R9 * 4", BaseBuffer); }break;
                        case 0B010: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + R10 * 4", BaseBuffer); }break;
                        case 0B011: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + R11 * 4", BaseBuffer); }break;
                        case 0B100: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + R12 * 4", BaseBuffer); }break;
                        case 0B101: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + R13 * 4", BaseBuffer); }break;
                        case 0B110: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + R14 * 4", BaseBuffer); }break;
                        case 0B111: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + R15 * 4", BaseBuffer); }break;	
                    }
                }break;
                
                case 0B11:
                {
                    switch(index.value)
                    {
                        case 0B000: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + R8 * 8", BaseBuffer); }break;
                        case 0B001: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + R9 * 8", BaseBuffer); }break;
                        case 0B010: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + R10 * 8", BaseBuffer); }break;
                        case 0B011: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + R11 * 8", BaseBuffer); }break;
                        case 0B100: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + R12 * 8", BaseBuffer); }break;
                        case 0B101: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + R13 * 8", BaseBuffer); }break;
                        case 0B110: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + R14 * 8", BaseBuffer); }break;
                        case 0B111: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + R15 * 8", BaseBuffer); }break;	
                    }
                }break;
            }
        }
        else
        {
            
            switch(ss.value)
            {
                case 0B00:
                {
                    switch(index.value)
                    {
                        case 0B000: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + RAX * 1" , BaseBuffer); }break;
                        case 0B001: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + RCX * 1" , BaseBuffer); }break;
                        case 0B010: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + RDX * 1", BaseBuffer); }break;
                        case 0B011: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + RBX * 1", BaseBuffer); }break;
                        case 0B100: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s", BaseBuffer); }break;
                        case 0B101: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + RBP * 1", BaseBuffer); }break;
                        case 0B110: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + RSI * 1", BaseBuffer); }break;
                        case 0B111: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + RDI * 1", BaseBuffer); }break;
                    }
                }break;
                case 0B01:
                {
                    switch(index.value)
                    {
                        case 0B000: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + RAX * 2" , BaseBuffer); }break;
                        case 0B001: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + RCX * 2" , BaseBuffer); }break;
                        case 0B010: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + RDX * 2", BaseBuffer); }break;
                        case 0B011: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + RBX * 2", BaseBuffer); }break;
                        case 0B100: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s", BaseBuffer); }break;
                        case 0B101: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + RBP * 2", BaseBuffer); }break;
                        case 0B110: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + RSI * 2", BaseBuffer); }break;
                        case 0B111: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + RDI * 2", BaseBuffer); }break;
                    }
                }break;
                
                case 0B10:
                {
                    switch(index.value)
                    {
                        case 0b000: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + RAX * 4" , BaseBuffer); }break;
                        case 0b001: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + RCX * 4" , BaseBuffer); }break;
                        case 0b010: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + RDX * 4", BaseBuffer); }break;
                        case 0b011: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + RBX * 4", BaseBuffer); }break;
                        case 0b100: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s", BaseBuffer); }break;
                        case 0b101: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + RBP * 4", BaseBuffer); }break;
                        case 0b110: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + RSI * 4", BaseBuffer); }break;
                        case 0b111: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + RDI * 4", BaseBuffer); }break;
                    }
                }break;
                
                case 0b11:
                {
                    switch(index.value)
                    {
                        case 0b000: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + RAX * 8" , BaseBuffer); }break;
                        case 0b001: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + RCX * 8" , BaseBuffer); }break;
                        case 0b010: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + RDX * 8", BaseBuffer); }break;
                        case 0b011: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + RBX * 8", BaseBuffer); }break;
                        case 0b100: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s", BaseBuffer); }break;
                        case 0b101: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + RBP * 8", BaseBuffer); }break;
                        case 0b110: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + RSI * 8", BaseBuffer); }break;
                        case 0b111: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + RDI * 8", BaseBuffer); }break;
                    }
                }break;
            }
        }
    }
    else if(EffAddressSize == 32)
    {
        if (TestBit(rex, 1))
        {
            switch(ss.value)
            {
                case 0b00:
                {
                    
                    switch(index.value)
                    {
                        case 0b000: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + R8D * 1" , BaseBuffer); }break;
                        case 0b001: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + R9D * 1" , BaseBuffer); }break;
                        case 0b010: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + R10D * 1", BaseBuffer); }break;
                        case 0b011: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + R11D * 1", BaseBuffer); }break;
                        case 0b100: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + R12D * 1", BaseBuffer); }break;
                        case 0b101: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + R13D * 1", BaseBuffer); }break;
                        case 0b110: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + R14D * 1", BaseBuffer); }break;
                        case 0b111: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + R15D * 1", BaseBuffer); }break;
                    }
                    
                }break;
                
                case 0b01:
                {
                    switch(index.value)
                    {
                        case 0b000: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + R8D * 2" , BaseBuffer); }break;
                        case 0b001: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + R9D * 2" , BaseBuffer); }break;
                        case 0b010: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + R10D * 2", BaseBuffer); }break;
                        case 0b011: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + R11D * 2", BaseBuffer); }break;
                        case 0b100: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + R12D * 2", BaseBuffer); }break;
                        case 0b101: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + R13D * 2", BaseBuffer); }break;
                        case 0b110: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + R14D * 2", BaseBuffer); }break;
                        case 0b111: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + R15D * 2", BaseBuffer); }break;
                    }
                }break;
                
                case 0b10:
                {
                    switch(index.value)
                    {
                        case 0b000: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + R8D * 4" , BaseBuffer); }break;
                        case 0b001: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + R9D * 4" , BaseBuffer); }break;
                        case 0b010: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + R10D * 4", BaseBuffer); }break;
                        case 0b011: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + R11D * 4", BaseBuffer); }break;
                        case 0b100: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + R12D * 4", BaseBuffer); }break;
                        case 0b101: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + R13D * 4", BaseBuffer); }break;
                        case 0b110: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + R14D * 4", BaseBuffer); }break;
                        case 0b111: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + R15D * 4", BaseBuffer); }break;
                    }
                }break;
                
                case 0b11:
                {
                    switch(index.value)
                    {
                        case 0b000: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + R8D * 8" , BaseBuffer); }break;
                        case 0b001: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + R9D * 8" , BaseBuffer); }break;
                        case 0b010: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + R10D * 8", BaseBuffer); }break;
                        case 0b011: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + R11D * 8", BaseBuffer); }break;
                        case 0b100: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + R12D * 8", BaseBuffer); }break;
                        case 0b101: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + R13D * 8", BaseBuffer); }break;
                        case 0b110: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + R14D * 8", BaseBuffer); }break;
                        case 0b111: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + R15D * 8", BaseBuffer); }break;
                    }
                }break;
            }
        }
        else
        {
            switch(ss.value)
            {
                case 0b00:
                {
                    switch(index.value)
                    {
                        
                        case 0b000: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + EAX * 1" , BaseBuffer); }break;
                        case 0b001: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + ECX * 1" , BaseBuffer); }break;
                        case 0b010: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + EDX * 1", BaseBuffer); }break;
                        case 0b011: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + EBX * 1", BaseBuffer); }break;
                        case 0b100: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s", BaseBuffer); }break;
                        case 0b101: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + EBP * 1", BaseBuffer); }break;
                        case 0b110: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + ESI * 1", BaseBuffer); }break;
                        case 0b111: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + EDI * 1", BaseBuffer); }break;
                    }
                }break;
                
                case 0b01:
                {
                    switch(index.value)
                    {
                        case 0b000: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + EAX * 2" , BaseBuffer); }break;
                        case 0b001: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + ECX * 2" , BaseBuffer); }break;
                        case 0b010: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + EDX * 2", BaseBuffer); }break;
                        case 0b011: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + EBX * 2", BaseBuffer); }break;
                        case 0b100: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s", BaseBuffer); }break;
                        case 0b101: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + EBP * 2", BaseBuffer); }break;
                        case 0b110: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + ESI * 2", BaseBuffer); }break;
                        case 0b111: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + EDI * 2", BaseBuffer); }break;
                        
                    }
                }break;
                
                case 0b10:
                {
                    switch(index.value)
                    {
                        case 0b000: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + EAX * 4" , BaseBuffer); }break;
                        case 0b001: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + ECX * 4" , BaseBuffer); }break;
                        case 0b010: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + EDX * 4", BaseBuffer); }break;
                        case 0b011: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + EBX * 4", BaseBuffer); }break;
                        case 0b100: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s", BaseBuffer); }break;
                        case 0b101: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + EBP * 4", BaseBuffer); }break;
                        case 0b110: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + ESI * 4", BaseBuffer); }break;
                        case 0b111: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + EDI * 4", BaseBuffer); }break;
                    }
                }break;
                
                case 0b11:
                {
                    switch(index.value)
                    {
                        case 0b000: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + EAX * 8" , BaseBuffer); }break;
                        case 0b001: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + ECX * 8" , BaseBuffer); }break;
                        case 0b010: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + EDX * 8", BaseBuffer); }break;
                        case 0b011: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + EBX * 8", BaseBuffer); }break;
                        case 0b100: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s", BaseBuffer); }break;
                        case 0b101: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + EBP * 8", BaseBuffer); }break;
                        case 0b110: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + ESI * 8", BaseBuffer); }break;
                        case 0b111: { _snprintf_s(SIBBuffer, BufferSize, BufferSize,  "%s + EDI * 8", BaseBuffer); }break;
                    }
                }break;
            }
        }
    }
#endif
    
}


void Base(disasm_state * State, eff_operand_size EffOperandSize, eff_address_size EffAddressSize , group2_prefix SegmentOverridePrefix, char * out_Buffer, u32 * out_BufferCount, u32 BufferSize, bits rex, u64 mod_val)
{
    Assert(EffAddressSize != 16);
    
    //NOTE(Alex): ss index base 
    bits ss = Zeroes(2);
    bits index = Zeroes(3);
    bits base = Zeroes(3);
    
    ss.value = GetBits_msb(State, ss.bits_count);
    index.value = GetBits_msb(State, index.bits_count);
    base.value = GetBits_msb(State, base.bits_count);
    
	u32 b_s_mem_size = (1 << 8);
	string b_s = {}; 	
	make_string_size(&State->i_write_arena.Arena, &b_s, 0, b_s_mem_size);
	
    ReadBaseTable(State, EffAddressSize, TestBit(rex, 0), SafeTruncateU64ToU32(base.value), SafeTruncateU64ToU32(mod_val), &b_s);
    
    regexp_support RegExpSupport = {};
    
    char * At = 0;
    if(InitRegExpSource(&RegExpSupport, b_s.buffer, b_s.count, &At))
    {
        while(PtrInsideString(&RegExpSupport, At))
        {
            if(StringIsEqualRegExp(&RegExpSupport, At, "<sreg>", StringLength("<sreg>")))
            {
                
                if(SegmentOverridePrefix > group2_Invalid)
                {
                    append_segment_reg_masm(SegmentOverridePrefix, out_Buffer, out_BufferCount, BufferSize);
                }
                else if(!TestBit(rex, 0))
                {
                    switch(base.value)
                    {
                        case 0b100: { Append(out_Buffer, out_BufferCount, BufferSize, "SS", StringLength("SS")); }break;
                        case 0b101: 
                        {
                            switch(mod_val)
                            {
                                case 0b01:
                                case 0b10:
                                {
                                    Append(out_Buffer, out_BufferCount, BufferSize, "SS", StringLength("SS"));
                                }break;
                                default:
                                {
                                    Append(out_Buffer, out_BufferCount, BufferSize, "DS", StringLength("DS"));
                                }break;
                            }
                        }break;
                        default:
                        {
                            Append(out_Buffer, out_BufferCount, BufferSize, "DS", StringLength("DS"));
                        }break;
                    }
                }
                else 
                {
                    Append(out_Buffer, out_BufferCount, BufferSize, "DS", StringLength("DS"));
                }
                AdvanceSourcePtr(&RegExpSupport, &At);
            }
            
            else if(StringIsEqualRegExp(&RegExpSupport, At, "<size>", StringLength("<size>")))
            {
				
				u32 mem_size =  (1 << 8);
				string op_size_kw_s = {};
				make_string_size(&State->i_write_arena.Arena, &op_size_kw_s, 0, mem_size);
				
				get_mem_operand_size_kw_masm(State, EffOperandSize, &op_size_kw_s);
				Append(out_Buffer, out_BufferCount, BufferSize, op_size_kw_s.buffer, op_size_kw_s.count);
                //append_mem_operand_size_kw_masm(out_Buffer, out_BufferCount, BufferSize, EffOperandSize);
                AdvanceSourcePtr(&RegExpSupport, &At);
            }
            
            else if(StringIsEqualRegExp(&RegExpSupport, At, "<ss>", StringLength("<ss>")))
            {
                GetSS(State, EffAddressSize, SegmentOverridePrefix, out_Buffer, out_BufferCount, BufferSize, rex, ss, index, base);
                AdvanceSourcePtr(&RegExpSupport, &At);
            }
            
            else if(StringIsEqualRegExp(&RegExpSupport, At, "<disp32>", StringLength("<disp32>")))
            {
                u32 BufferCount = 0;
                char Buffer[MAX_BUFFER_SIZE] = {0};
                
                bits disp32 = Zeroes(32);
                disp32.value = GetBits_msb(State, disp32.bits_count);
                bits LE = SwapBitfieldBytes(disp32);
                
                ConvertBitsToString(Buffer, &BufferCount, MAX_BUFFER_SIZE, &LE);
                Append(out_Buffer, out_BufferCount, BufferSize, Buffer, BufferCount);
                
                AdvanceSourcePtr(&RegExpSupport, &At);
            }
            
            else if(StringIsEqualRegExp(&RegExpSupport, At, "<disp8>", StringLength("<disp8>")))
            {
                u32 BufferCount = 0;
                char Buffer[MAX_BUFFER_SIZE] = {0};
                
                bits disp8 = Zeroes(8);
                disp8.value = GetBits_msb(State, disp8.bits_count);
                bits LE = SwapBitfieldBytes(disp8);
                
                ConvertBitsToString(Buffer, &BufferCount, MAX_BUFFER_SIZE, &LE);
                Append(out_Buffer, out_BufferCount, BufferSize, Buffer, BufferCount);
                
                AdvanceSourcePtr(&RegExpSupport, &At);
            }
            
            else
            {
                Append(out_Buffer, out_BufferCount, BufferSize, At++, 1);
            }
            
        }
    }
    
    EndRegExp(&RegExpSupport);
    
#if 0    
    if(EffAddressSize == 64)
    {
        if(TestBit(rex, 0))
        {
            
            switch(base.value)
            {
                case 0b000: { _snprintf_s(out_Buffer, BufferSize, BufferSize, "R8"); }break;
                case 0b001: { _snprintf_s(out_Buffer, BufferSize, BufferSize, "R9"); }break;
                case 0b010: { _snprintf_s(out_Buffer, BufferSize, BufferSize, "R10"); }break;
                case 0b011: { _snprintf_s(out_Buffer, BufferSize, BufferSize, "R11"); }break;
                case 0b100: { _snprintf_s(out_Buffer, BufferSize, BufferSize, "R12"); }break;
                case 0b101: 
                { 
                    switch(mod.value)
                    {
                        case 0b00:
                        {
                            //bits(N) instruction = baseInstruction : sibbyte : disp32;
                            disp32.value = GetBits_msb(State, disp32.bits_count);
                            PrintImmediateToBuffer(out_Buffer, BufferSize, EffAddressSize, disp32);
                        }break;
                        case 0b01:
                        {
                            //NOTE(Alex): if MVEX/EVEX, then sbyte is interpreted as sbyte*N
                            //_snprintf_s(out_Buffer, BufferSize, BufferSize, "R13 + 0x%llx", disp8.value);
                            _snprintf_s(out_Buffer, BufferSize, BufferSize, "R13");
                        }break;
                        case 0b10:
                        {
                            //disp32.value = GetBits_msb(State, disp32.N);
                            //_snprintf_s(out_Buffer, BufferSize, BufferSize, "R13 + 0x%llx", disp32.value);
                            _snprintf_s(out_Buffer, BufferSize, BufferSize, "R13");
                        }break;
                        InvalidDefaultCase;
                    }
                }break;
                case 0b110: { _snprintf_s(out_Buffer, BufferSize, BufferSize, "R14"); }break;
                case 0b111: { _snprintf_s(out_Buffer, BufferSize, BufferSize, "R15"); }break;
            }
        }
        else
        {
            
            switch(base.value)
            {
                case 0b000: { _snprintf_s(out_Buffer, BufferSize, BufferSize, "RAX"); }break;
                case 0b001: { _snprintf_s(out_Buffer, BufferSize, BufferSize, "RCX"); }break;
                case 0b010: { _snprintf_s(out_Buffer, BufferSize, BufferSize, "RDX"); }break;
                case 0b011: { _snprintf_s(out_Buffer, BufferSize, BufferSize, "RBX"); }break;
                case 0b100: { _snprintf_s(out_Buffer, BufferSize, BufferSize, "RSP"); }break;
                case 0b101: 
                {
                    switch(mod.value)
                    {
                        case 0b00:
                        {
                            disp32.value = GetBits_msb(State, disp32.bits_count);
                            PrintImmediateToBuffer(out_Buffer, BufferSize, EffAddressSize, disp32);
                        }break;
                        case 0b01:
                        {
                            //disp8.value = GetBits_msb(State, disp8.N);
                            //NOTE(Alex): (defaults to SS), if MVEX/EVEX, then sbyte is interpreted as sbyte*N 
                            //_snprintf_s(out_Buffer, BufferSize, BufferSize, "RBP + 0x%llx", disp8.value);
                            _snprintf_s(out_Buffer, BufferSize, BufferSize, "RBP");
                        }break;
                        case 0b10:
                        {
                            //disp32.value = GetBits_msb(State, disp32.N);
                            //NOTE(Alex): (defaults to SS)  
                            //_snprintf_s(out_Buffer, BufferSize, BufferSize, "RBP + 0x%llx", disp32.value);
                            _snprintf_s(out_Buffer, BufferSize, BufferSize, "RBP");
                        }break;
                        InvalidDefaultCase;
                    }
                }break;
                case 0b110: { _snprintf_s(out_Buffer, BufferSize, BufferSize, "RSI"); }break;
                case 0b111: { _snprintf_s(out_Buffer, BufferSize, BufferSize, "RDI"); }break;
            }
        }
    }
    else if(EffAddressSize == 32)
    {
        if(TestBit(rex, 0))
        {
            
            switch(base.value)
            {
                case 0b000: { _snprintf_s(out_Buffer, BufferSize, BufferSize, "R8D"); }break;
                case 0b001: { _snprintf_s(out_Buffer, BufferSize, BufferSize, "R9D"); }break;
                case 0b010: { _snprintf_s(out_Buffer, BufferSize, BufferSize, "R10D"); }break;
                case 0b011: { _snprintf_s(out_Buffer, BufferSize, BufferSize, "R11D"); }break;
                case 0b100: { _snprintf_s(out_Buffer, BufferSize, BufferSize, "R12D"); }break;
                case 0b101:
                {
                    switch(mod.value)
                    {
                        case 0b00:
                        { 
                            disp32.value = GetBits_msb(State, disp32.bits_count);
                            PrintImmediateToBuffer(out_Buffer, BufferSize, EffAddressSize, disp32);
                        }break;
                        case 0b01:
                        {
                            //disp8.value = GetBits_msb(State, disp8.N);
                            //NOTE(Alex): if MVEX/EVEX, then sbyte is interpreted as sbyte*N
                            //_snprintf_s(out_Buffer, BufferSize, BufferSize, "R13D + 0x%llx", disp8.value);
                            _snprintf_s(out_Buffer, BufferSize, BufferSize, "R13D");
                        }break;
                        case 0b10:
                        {
                            //disp32.value = GetBits_msb(State, disp32.N);
                            //_snprintf_s(out_Buffer, BufferSize, BufferSize, "R13D + 0x%llx", disp32.value);
                            _snprintf_s(out_Buffer, BufferSize, BufferSize, "R13D");
                        }break;
                        InvalidDefaultCase;
                    }
                }break;
                case 0b110: { _snprintf_s(out_Buffer, BufferSize, BufferSize, "R14D"); }break;
                case 0b111: { _snprintf_s(out_Buffer, BufferSize, BufferSize, "R15D"); }break;
            }
        }
        else
        {
            
            switch(base.value)
            {
                case 0b000: { _snprintf_s(out_Buffer, BufferSize, BufferSize, "EAX"); }break;
                case 0b001: { _snprintf_s(out_Buffer, BufferSize, BufferSize, "ECX"); }break;
                case 0b010: { _snprintf_s(out_Buffer, BufferSize, BufferSize, "EDX"); }break;
                case 0b011: { _snprintf_s(out_Buffer, BufferSize, BufferSize, "EBX"); }break;
                case 0b100: { _snprintf_s(out_Buffer, BufferSize, BufferSize, "ESP"); }break;
                case 0b101:
                {
                    switch(mod.value)
                    {
                        case 0b00:
                        {
                            disp32.value = GetBits_msb(State, disp32.bits_count);
                            PrintImmediateToBuffer(out_Buffer, BufferSize, EffAddressSize, disp32);
                            // DS : [ <ss> + <disp32> ]
                        }break;
                        case 0b01:
                        {
                            //disp8.value = GetBits_msb(State, disp8.N);
                            //NOTE(Alex): (defaults to SS), if MVEX/EVEX, then sbyte is interpreted as sbyte*N 
                            //_snprintf_s(out_Buffer, BufferSize, BufferSize, "EBP + 0x%llx", disp8.value);
                            _snprintf_s(out_Buffer, BufferSize, BufferSize, "EBP");
                            
                            // SS : [ EBP + <ss> + <disp8> ]
                        }break;
                        case 0b10:
                        {
                            //disp32.value = GetBits_msb(State, disp32.N);
                            //NOTE(Alex): (defaults to SS)  
                            //_snprintf_s(out_Buffer, BufferSize, BufferSize, "EBP + 0x%llx", disp32.value);
                            _snprintf_s(out_Buffer, BufferSize, BufferSize, "EBP");
                            
                            // SS : [ EBP + <ss> + <disp32> ]
                        }break;
                        InvalidDefaultCase;
                    }
                }break;
                case 0b110: { _snprintf_s(out_Buffer, BufferSize, BufferSize, "ESI"); }break;
                case 0b111: { _snprintf_s(out_Buffer, BufferSize, BufferSize, "EDI"); }break;
            }
        }
    }
#endif
    
}


#if 0

u32 s(bits s, bits imm8)
{
    u32 Result = 0;
    if(s.value == 1)
    {
        if (imm8.value) 
        {
            Result = SignExtend(imm8.value);
        }
    }
    
    return Result;
}


//TODO(Alex): Check this and see what does it do?


//TODO(Alex): Does the language itself knows how to stringify bitfields?
func Address(bitfield farpointer) return string
return "[" "farpointer" "]"

#endif

internal void 
GetrAX64Reg(char * out_Buffer, u32 * out_BufferCount, u32 BufferSize, u32 EffOperandSize)
{
    switch(EffOperandSize)
    {
        case 8:
        {
            Append(out_Buffer, out_BufferCount, BufferSize, "Al", StringLength("Al"));
        }break;
        
        case 16:
        {
            Append(out_Buffer, out_BufferCount, BufferSize, "AX", StringLength("AX"));
        }break;
        
        case 32:
        {
            Append(out_Buffer, out_BufferCount, BufferSize, "EAX", StringLength("EAX"));
        }break;
        
        case 64:
        {
            Append(out_Buffer, out_BufferCount, BufferSize, "RAX", StringLength("RAX"));
        }break;
        
        InvalidDefaultCase;
    }
}

inline void 
GetFarPointerBitsCount(u32 * out_EffOperandSize)  
{
    if(out_EffOperandSize)
    {
        u32 EffOperandSize = *out_EffOperandSize;
        
        if (EffOperandSize == 64) 
        {
            EffOperandSize =  80;
        }
        else if (EffOperandSize == 32) 
        {
            EffOperandSize  = 48;
        }
        else 
        {
            Assert(EffOperandSize == 16);
            EffOperandSize = 32;
        }
        
        *out_EffOperandSize  = EffOperandSize;
    }
}


inline void
CXZ(disasm_state * State, char * out_Buffer, u32 * out_BufferCount, u32 BufferSize, u32 EffAddressSize)
{
    if(EffAddressSize == 64) 
    {
        Append(out_Buffer, out_BufferCount, BufferSize, "RCXZ", StringLength("RCXZ"));
    }
    else if(EffAddressSize == 32)
    {
        Append(out_Buffer, out_BufferCount, BufferSize, "ECXZ", StringLength("ECXZ"));
    }
    else 
    {
        Assert(EffAddressSize == 16);
        Append(out_Buffer, out_BufferCount, BufferSize, "CXZ", StringLength("CXZ"));
    }
}


inline void 
b(eff_operand_size *  out_EffOperandSize)
{
    if(out_EffOperandSize)
    {
        *out_EffOperandSize = operandsize_8;
    }
}


inline void
z(eff_operand_size * out_EffOperandSize)
{
    if(out_EffOperandSize)
    {
        eff_operand_size EffOperandSize = *out_EffOperandSize;
        
        if (EffOperandSize == operandsize_16) 
        {
            EffOperandSize = operandsize_16;
        }
        else if(EffOperandSize == operandsize_32)
        {
            EffOperandSize = operandsize_32;
        }
        else 
        {
            Assert(EffOperandSize == operandsize_64);
            EffOperandSize = operandsize_32;
        }
        
        *out_EffOperandSize = EffOperandSize;
    }
}


inline void 
v(eff_operand_size * out_EffOperandSize)
{
    if(out_EffOperandSize)
    {
        eff_operand_size EffOperandSize = *out_EffOperandSize;
        
        if (EffOperandSize == operandsize_16)
        {
            EffOperandSize = operandsize_16;
        }
        else if(EffOperandSize == operandsize_32)
        {
            EffOperandSize = operandsize_32;
        }
        else 
        {
            Assert(EffOperandSize == operandsize_64);
            EffOperandSize = operandsize_64;
        }
        
        *out_EffOperandSize = EffOperandSize;
    }
}

inline void 
vqp(eff_operand_size * out_EffOperandSize)
{
    if(out_EffOperandSize)
    {
        eff_operand_size OperandSize = *out_EffOperandSize;
        
        if (OperandSize == operandsize_16)
        {
            OperandSize = operandsize_16;
        }
        else if(OperandSize == operandsize_32)
        {
            OperandSize = operandsize_32;
        }
        else 
        {
            Assert(OperandSize == operandsize_64);
            OperandSize = operandsize_64;
        }
        
        *out_EffOperandSize = OperandSize;
    }
}

//TODO(Alex): Load this from file?
//TODO(Alex): Add Prefix identification
//TODO(Alex): Shall we make the user choose which size attributes  
//the instruction arquitecture should target? Or we use the current arquitecture?

#if 0
union efly_memreg_fields
{
    struct
    {
        uint32_t mod, reg, rm;
    };
    struct
    {
        uint32_t scale, index, base;
    };
    
};


#define GetMODRMByteFields(modrm) GetMemRegFields(modrm)
#define GetSIBByteFields(sib) GetMemRegFields(sib)

inline efly_memreg_fields 
GetMemRegFields(uint8_t Byte)
{
    efly_memreg_fields Result = {};
    Result.mod = (Byte >> 6) & 0x3;
    Result.reg = (Byte >> 3) & 0x7;
    Result.rm = (Byte >> 0) & 0x7;
    return Result;
}

struct table_id_result
{
    efly_table_id ID;
    uint32_t MainOpOffset; 
    uint8_t MODRMOffset; 
    uint32_t EntryID;
};


internal table_id_result
GetTableID(efly_disasm_state * DisasmState, uint8_t * MainOpByte)
{
    Assert(MainOpByte);
    table_id_result Result = {};
    
    uint8_t FirstByte, SecondByte, ThirdByte;
    FirstByte = *(MainOpByte + 0);
    SecondByte = *(MainOpByte + 1);
    ThirdByte = *(MainOpByte + 2);
    
    
    uint16_t EntryID = 0;
    if(FirstByte == 0x0F &&
       SecondByte == 0x38)
    {
        EntryID = ThirdByte;
        
        Result.ID = TableID_ThreeByteOpTable38H;
        Result.MainOpOffset = 2;
        Result.MODRMOffset = 3;
        Result.EntryID = EntryID;
    }
    
    else if(FirstByte == 0x0F &&
            SecondByte == 0x3A)
    
    {
        EntryID = ThirdByte;
        
        Result.ID = TableID_ThreeByteOpTable3AH;
        Result.MainOpOffset = 2;
        Result.MODRMOffset = 3;
        Result.EntryID = EntryID;
    }
    
    else if(
        (FirstByte == 0x80)  ||
        (FirstByte == 0x81)  ||
        (FirstByte == 0x82)  ||
        (FirstByte == 0x83)  ||
        (FirstByte == 0x8F)  ||
        (FirstByte == 0xC0)  ||
        (FirstByte == 0xC1)  ||
        (FirstByte == 0xD0)  ||
        (FirstByte == 0xD1)  ||
        (FirstByte == 0xD2)  ||
        (FirstByte == 0xD3)  ||
        (FirstByte == 0xF6)  ||
        (FirstByte == 0xF7)  ||
        (FirstByte == 0xFE)  ||
        (FirstByte == 0xFF)  ||
        (FirstByte == 0xC6)  ||
        (FirstByte == 0xC7)
        )
    {
        
        EntryID = (FirstByte) | (((SecondByte >> 3) & 0x7) << 11);
        
        Result.ID = TableID_OpExtensionTable;
        Result.MainOpOffset = 1;
        Result.MODRMOffset = 1;
        Result.EntryID = EntryID;
    }
    
    else if(
        ((FirstByte == 0x0F) 
         && (SecondByte == 0x00)) ||
        ((FirstByte == 0x0F)  
         && (SecondByte == 0x01)) ||
        ((FirstByte == 0x0F)  
         && (SecondByte == 0xBA)) ||
        ((FirstByte == 0x0F)  
         && (SecondByte == 0xC7)) ||
        ((FirstByte == 0x0F)  
         && (SecondByte == 0xB9)) ||
        ((FirstByte == 0x0F)  
         && (SecondByte == 0x71)) ||
        ((FirstByte == 0x0F)  
         && (SecondByte == 0x72)) ||
        ((FirstByte == 0x0F)  
         && (SecondByte == 0x73)) ||
        ((FirstByte == 0x0F)  
         && (SecondByte == 0xAE)) ||
        ((FirstByte == 0x0F)  
         && (SecondByte == 0x18)) 
        #if 0        
        //TODO(Alex): Check VEX prefix encoding 
        (
        (FirstByte == 0x0F)  
        && (SecondByte == 0x38)
        && (SecondByte == 0xF3)
        )
        #endif
        )
    {
        EntryID = (FirstByte) | (((SecondByte >> 3) & 0x7) << 11);
        
        Result.ID = TableID_OpExtensionTable;
        Result.MainOpOffset = 2;
        Result.MODRMOffset = 3;
        Result.EntryID = EntryID;
    }
    
    else if(FirstByte == 0x0F)
    {
        EntryID = (SecondByte);
        
        Result.ID = TableID_TwoByteOpTable;
        Result.MainOpOffset = 1;
        Result.MODRMOffset = 2;
        Result.EntryID = EntryID;
    }
    
    else if(
        ((*MainOpByte) >= 0xD8) &&
        ((*MainOpByte) <= 0xDF)
        )
    {
        switch(FirstByte)
        {
            case 0xD8:
            {
                Result.ID = TableID_EscapeOpTableD8;
            }break;
            case 0xDD:
            {
                Result.ID = TableID_EscapeOpTableDD;
            }break;
        }
        
        if((SecondByte >= 0x00) && (SecondByte <= 0xBF))
        {
            EntryID = (FirstByte) | (((SecondByte >> 3) & 0x7) << (3 + 8));
        }
        else
        {
            EntryID = (FirstByte) | (SecondByte << 8);
        }
        
        Result.EntryID = EntryID;
        Result.MainOpOffset = 1;
        Result.MODRMOffset = 1;
    }
    
    else
    {
        EntryID = (FirstByte);
        Result.ID = TableID_OneByteOpTable;
        Result.MainOpOffset = 0;
        Result.MODRMOffset = 1;
        Result.EntryID = EntryID;
    }
    
    return Result;
}


struct efly_rex_field
{
    uint32_t w, r, x, b;
};

inline efly_rex_field 
GetREXFields(uint32_t REXByte)
{
    efly_rex_field Result = {};
    
    if(REXByte)
    {
        Result.w = ((REXByte >> 3) & 0x1);
        Result.r = ((REXByte >> 2) & 0x1);
        Result.x = ((REXByte >> 1) & 0x1);
        Result.b = ((REXByte >> 0) & 0x1);
    }
    
    return Result;
}

struct efly_offset_selection
{
    efly_register_group * RegGroup;
    uint32_t Offset;
};

internal void
MakeOffsetSelection(efly_disasm_state * DisasmState, efly_decoder_context * Context, uint32_t Value, efly_offset_selection * Selection,  efly_decoder_flags Flags)
{
    efly_rex_field REX = GetREXFields(Context->REXByte);
    
    uint32_t A, B;
    A = (Value >> 0) & 0x7;
    B = (Value >> 3) & 0x7;
    
    if(Flags.FetchrmField)
    {
        if(REX.b)
        {
            Selection->RegGroup = DisasmState->RegGroups + RegType_GPR64;
        }
        
        Selection->Offset = A;
    }
    else
    {
        uint32_t REXField = (Flags.FetchMODRMByte) ? REX.r : REX.x;
        if(REXField)
        {
            Selection->RegGroup = DisasmState->RegGroups + RegType_GPR64;
        }
        
        Selection->Offset = B;
    }
}

internal void
PushRegisterName(efly_disasm_state * DisasmState, efly_decoder_context * Context, 
                 char * Buffer, uint32_t * out_BufferCount, uint32_t BufferSize, 
                 uint32_t OperandSize, efly_offset_selection * Selection)
{
    bit_info Info = {};
    if((Selection->RegGroup->Type == RegType_GPR) ||
       (Selection->RegGroup->Type == RegType_GPR64))
    {
        //TODO(Alex): We don't need operandSizes, we need offsets!
        Info = BitScanReverseU32(OperandSize);
    }
    
    if(Context->REXByte && (Info.Offset == 0) && (Selection->Offset >= 4))
    {
        Selection->RegGroup = DisasmState->RegGroups + RegType_UByte;
        Selection->Offset -= 4;
    }
    
    //TODO(Alex): Shall we add a null reg entry?
    efly_names_entry * Reg = DisasmState->TableRegs + Selection->RegGroup->Base + (Info.Offset * REG_TABLE_PITCH) + Selection->Offset; 
    Assert(Reg);
    Append(Buffer, out_BufferCount, BufferSize, Reg->Text, Reg->Count);
}


inline efly_decoder_context
BeginInstructionDecoding(processor_mode OperationMode, uint8_t * Base, memory_index VirtualAddress)
{
    efly_decoder_context Context = {};
    Context.IBase = Base;
    Context.EffAddressSize = (OperationMode == ProcessorMode_64bit)  ? DataSize_64Bit : DataSize_32Bit;
    Context.EffOperandSize = DataSize_32Bit; 
    Context.VirtualAddress = VirtualAddress;
    
    return Context;
}


inline uint32_t  
EndInstructionDecoding(efly_disasm_state * DisasmState, efly_decoder_context * Context)
{
    Assert(Context->IBase);
    Assert(Context->IByteCount > 0);
    uint32_t Result = Context->IByteCount;
    return Result;
}


internal b32
FetchRegisterOperand_(efly_disasm_state * DisasmState, efly_decoder_context * Context, char * Buffer, uint32_t * out_BufferCount, uint32_t BufferSize, 
                      uint32_t OperandSize, efly_decoder_flags Flags)
{
    b32 Result = false;
    
    efly_mnemonic_entry * Entry = &Context->Entry;
    uint32_t REXByte = Context->REXByte;
    b32 FetchrmField = Flags.FetchrmField;
    
    if(Buffer && out_BufferCount)
    {
        if(Entry->MODRMPresent && 
           (OperandSize != DataSize_Invalid)  &&    
           (Context->OpCount < Entry->OperandCount))
        {
            efly_offset_selection Selection = {};
            Selection.Offset = REG_OFFSET_INVALID;
            Selection.RegGroup = DisasmState->RegGroups + Entry->RegisterType;
            
            uint8_t * MODRMByte = (Context->MODRMByte);
            uint32_t Byte = 0;
            if(Selection.RegGroup->Type == RegType_X87)
            {
                //TODO(Alex): Make x87 decoding properly
                Selection.Offset = (FetchrmField) ? Entry->RegOffsetA : Entry->RegOffsetB;
            }
            else if(Flags.FetchMODRMByte)
            {
                MakeOffsetSelection(DisasmState, Context, *(MODRMByte), &Selection, Flags);
            }
            else
            {
                MakeOffsetSelection(DisasmState, Context, *(MODRMByte + 1), &Selection, Flags);
            }
            
            Assert(Selection.Offset < Selection.RegGroup->Count);
            PushRegisterName(DisasmState, Context, Buffer, out_BufferCount, BufferSize, OperandSize,  &Selection);
            Result = true;
        }
    }
    
    return Result;
}

internal uint32_t
GetMnemonicEntry(efly_disasm_state * DisasmState, efly_decoder_context * Context,  
                 char * Buffer, uint32_t * out_BufferCount , uint32_t BufferSize)
{
    //TODO(Alex): LoadTables in here?;
    //NOTE(Alex): (0x66 0xF2 0xF3) 0x0F) MainOpbyte
    uint32_t Result = 0;
    uint8_t * CByte = Context->IBase + Context->IByteCount;
    
#if EAGLEFLY_INTERNAL
    if(DisasmState->OperationMode == OperationMode_64Bit)
    {
        Assert((*CByte <= 0x40) ||
               (*CByte >= 0x4F));
    }
#endif
    
    table_id_result Table = GetTableID(DisasmState, CByte);
    Assert((Table.ID >= TableID_Invalid) && (Table.ID < TableID_Count));
    
    efly_table_group * Group = DisasmState->OpTableGroups + Table.ID;
    for(uint32_t Index = Group->FirstOpByteIndex;
        Index < Group->FirstOpByteIndex + Group->OpByteCount;
        ++Index)
    {
        efly_byte_entry * OpByteEntry = DisasmState->OpByteEntries + Index;
        if(Table.EntryID == OpByteEntry->ID)
        {
            Result = OpByteEntry->EntryIndex;
            break;
        }
    }
    
    Context->Entry = DisasmState->OpTableEntries[Result];
    efly_mnemonic_entry * Entry = &Context->Entry;
    
    if(Entry->RegisterOperandSize != DataSize_v)
    {
        Assert(Entry->RegisterOperandSize != DataSize_Effective);
        Context->EffOperandSize = Entry->RegisterOperandSize;
        
        if((Entry->RegisterOperandSize == DataSize_Forced64) && (DisasmState->OperationMode == OperationMode_64Bit))
        {
            Context->EffOperandSize = DataSize_64Bit;
        }
        else if(Entry->RegisterOperandSize == DataSize_OperatingMode)
        {
            Context->EffOperandSize = (DisasmState->OperationMode == OperationMode_64Bit) ? DataSize_64Bit : DataSize_32Bit;
        }
    }
    
    //TODO(Alex): Define EntryOffsets to particular bitfields
    if(Entry->OperationMode & DisasmState->OperationMode)
    {
        if(Entry->RegFieldInside)
        {
            efly_offset_selection Selection = {};
            Selection.RegGroup = DisasmState->RegGroups + Entry->RegisterType;
            
            efly_decoder_flags Flags = {};
            Flags.FetchrmField = true;
            MakeOffsetSelection(DisasmState, Context, *CByte, &Selection, Flags);
            PushRegisterName(DisasmState, Context, Buffer, out_BufferCount, BufferSize, Context->EffOperandSize, &Selection);
        }
    }
    
    Context->IByteCount += Table.MODRMOffset;
    Context->MODRMByte = (Context->IBase + Context->IByteCount);
    
    return Result;
}


inline b32 
IsRegisterOperand(uint32_t modrmbyte)
{
    b32 Result = (modrmbyte >= 0xC0) && (modrmbyte <= 0xFF);
    return Result;
}

inline b32 
SIBBytePresent(uint8_t * modrmbyte)
{
    //NOTE(Alex): 04 - BC 
    b32 Result = false;
    if(modrmbyte)
    {
        Result = (!IsRegisterOperand(*modrmbyte) && 
                  (((*modrmbyte & 0xF) == 0x4) || 
                   ((*modrmbyte & 0xF) == 0xC)
                   )
                  );
    }
    
    return Result;
}

internal void
PushSignExtendedValue(efly_disasm_state * DisasmState, uint8_t * EncodedDisp, uint32_t EncodedSize, uint32_t EffSize, char * Buffer, uint32_t * out_BufferCount, uint32_t BufferSize)
{
    uint8_t Byte = 0;
    if(EncodedSize == DataSize_8Bit)
    {
        Byte = EncodedDisp[0];
    }
    else
    {
        Assert(EncodedSize == DataSize_32Bit);
        Byte = EncodedDisp[EncodedSize - 1];
    }
    
    char Sign = '\0';
    if(Byte & 0x80)
    {
        Sign = 'F';
    }
    else
    {
        Sign = '0';
    }
    
    for(int32_t Index = 0;
        Index < (int32_t)((EffSize - EncodedSize) * 2);
        ++Index)
    {
        Append(Buffer, out_BufferCount, BufferSize, &Sign, 1);
    }
    
    char TempB[MAX_BUFFER_SIZE] = {0};
    for(int32_t Index = (EncodedSize - 1);
        Index >= 0;
        --Index)
    {
        uint32_t TempCount = __snprintf_s(TempB, MAX_BUFFER_SIZE, MAX_BUFFER_SIZE, "%0*X", 2, EncodedDisp[Index]);
        Append(Buffer, out_BufferCount, BufferSize, TempB, TempCount);
    }
    
}


#define OperationModeRealAddress(DisasmState) ((DisasmState)->OperationMode == OperationMode_RealAddress)
#define OperationMode64Bit(DisasmState) ((DisasmState)->OperationMode == OperationMode_64Bit)
#define OperationModeProcessorMode_32bit(DisasmState) ((DisasmState)->OperationMode == OperationMode_32Bit)
#define OperationModeIA32(DisasmState) OperationModeProcessorMode_32bit(DisasmState)

#define OperandByteCount(sibbytepresent)

internal void 
FetchOperands(efly_disasm_state * DisasmState, efly_decoder_context * Context, 
              char * RegBuffer, uint32_t * out_RegBufferCount, uint32_t RegBufferSize,  char * MemBuffer, uint32_t * out_MemBufferCount, uint32_t MemBufferSize)
{
    // NOTE(Alex): (Base + (Index * Scale) + Displacement)
    uint32_t ByteCount  = 0;
    efly_mnemonic_entry * Entry = &Context->Entry;
    
    if(Entry->MODRMPresent)
    {
        efly_decoder_flags Flags = {};
        Flags.FetchMODRMByte = true;
        Flags.FetchrmField = true;
        
        uint8_t * MODRMByte = (Context->MODRMByte);
        uint32_t modrmbyte = *MODRMByte;
        efly_memreg_fields MODRMFields = GetMODRMByteFields((uint8_t)modrmbyte);
        
        if(IsRegisterOperand(modrmbyte))
        {
            FetchRegisterOperand_(DisasmState, Context, MemBuffer, out_MemBufferCount, MemBufferSize, Context->EffOperandSize, Flags);
            ByteCount = 1;
        }
        else 
        {
            Assert(MODRMFields.mod != 0x3);
            
            //TODO(Alex): Addd 16 bit addressing modes
            uint32_t Displacement = DataSize_Invalid; 
            uint32_t BaseSize  = Context->EffAddressSize; 
            uint32_t IndexSize =  DataSize_Invalid; 
            
            switch(MODRMFields.mod)
            {
                case 0x0: 
                {
                    if(MODRMFields.rm == 0x5)
                    {
                        Displacement = DataSize_32Bit; 
                        BaseSize= DataSize_Invalid;
                    }
                    else
                    {
                        Displacement = DataSize_Invalid; 
                    }
                }break;
                case 0x1: 
                {
                    Displacement = DataSize_8Bit; 
                }break;
                case 0x2: 
                {
                    Displacement = DataSize_32Bit; 
                }break;
            }
            
            //TODO(Alex): do we want to ouput type info for a specific assembler language?
            char * DataTypes[64] = 
            {
                "byte",
                "word",
                "dword",
                "qword",
                
                "sbyte",
                "sword",
                "sdword",
                "sqword",
                
                "fword",
                
                "m128",
                "m256",
                "m512",
                
                "real4",
                "real8",
            }; 
            
            char * PtrString = "ptr";
            char * OpenBrackets = "[";
            char * CloseBrackets = "]";
            
            {
                char * Type = 0;
                uint32_t Offset = 0;
                if(Entry->OperandType == OperandType_FarPtr)
                {
                    Offset = 8;
                }
                else
                {
                    bit_info Info =  BitScanReverseU32(Context->EffOperandSize);
                    Offset = Info.Offset;
                }
                
                Type = DataTypes[Offset];
                char TempB[MAX_BUFFER_SIZE] = {0};
                uint32_t TempCount = __snprintf_s(TempB, MAX_BUFFER_SIZE, MAX_BUFFER_SIZE, "%*s %*s %*s", StringLength(Type), Type,  StringLength(PtrString) , PtrString,  StringLength(OpenBrackets), OpenBrackets);
                Append(MemBuffer, out_MemBufferCount, MemBufferSize, TempB, TempCount);
                
            }
            
            b32 sibbytepresent = false;
            if(SIBBytePresent(MODRMByte))
            {
                Flags.FetchMODRMByte = false;
                sibbytepresent = true; 
                IndexSize = Context->EffAddressSize;
                uint8_t sibbyte = *(MODRMByte + 1);
                
                efly_rex_field REX = GetREXFields(Context->REXByte);
                if(!REX.x && !(sibbyte & 0x8) && (((sibbyte >> 4) == 0x2) || 
                                                  ((sibbyte >> 4) == 0x6) || 
                                                  ((sibbyte >> 4) == 0xA) || 
                                                  ((sibbyte >> 4) == 0xE)))
                {
                    IndexSize = DataSize_Invalid;
                }
                
                b32 FetchBaseRegister = true;
                efly_memreg_fields SIBFields = GetSIBByteFields(sibbyte);
                if((SIBFields.base == 0x5) && (MODRMFields.mod == 0x0))
                {
                    Displacement = DataSize_32Bit; 
                    FetchBaseRegister = false;
                }
                
                if(FetchBaseRegister)
                {
                    FetchRegisterOperand_(DisasmState, Context, MemBuffer, out_MemBufferCount, MemBufferSize, BaseSize, Flags);
                    if(IndexSize > DataSize_Invalid)
                    {
                        char * Plus = " + ";
                        Append(MemBuffer, out_MemBufferCount, MemBufferSize, Plus, StringLength(Plus));
                    }
                }
                
                //NOTE(Alex): This follows IA-32 and x64 addressing modes special cases encondings
                Flags.FetchrmField = false;
                if(FetchRegisterOperand_(DisasmState, Context, MemBuffer, out_MemBufferCount, MemBufferSize, IndexSize, Flags))
                {
                    char * Symbol = " * ";;
                    char TempB[MAX_BUFFER_SIZE] = {0};
                    uint32_t Scale = (1 << ((sibbyte >> 0x6) & 0x3));
                    
                    Append(MemBuffer, out_MemBufferCount, MemBufferSize, Symbol, StringLength(Symbol));
                    uint32_t TempCount = _snprintf_s(TempB, MAX_BUFFER_SIZE, MAX_BUFFER_SIZE, "%0X", Scale);
                    Append(MemBuffer, out_MemBufferCount, MemBufferSize, TempB, TempCount);
                }
            }
            else
            {
                FetchRegisterOperand_(DisasmState, Context, MemBuffer, out_MemBufferCount, MemBufferSize, BaseSize, Flags);
            }
            
            uint32_t OperandByteCount =  ((sibbytepresent) ? 2 : 1) ;
            
            if(Displacement > DataSize_Invalid)
            {
                if(BaseSize > DataSize_Invalid)
                {
                    char *  Symbol = " + ";
                    Append(MemBuffer, out_MemBufferCount, MemBufferSize, Symbol, StringLength(Symbol));
                }
                
                uint8_t * Disp = (MODRMByte + OperandByteCount);
                PushSignExtendedValue(DisasmState, Disp, Displacement, Context->EffAddressSize, MemBuffer, out_MemBufferCount, MemBufferSize);
            }
            
            Append(MemBuffer, out_MemBufferCount, MemBufferSize, CloseBrackets, StringLength(CloseBrackets));
            ByteCount = (Displacement + OperandByteCount);
        }
        
        //TODO(Alex): Get rid of this!
        ++Context->OpCount;
        
        Flags.FetchMODRMByte = true;
        Flags.FetchrmField = false;
        //TODO(Alex) : Make sure that we fetch reg field when we are sure theres a register byte;
        FetchRegisterOperand_(DisasmState, Context, RegBuffer, out_RegBufferCount, RegBufferSize, Context->EffOperandSize, Flags);
    }
    
    Context->IByteCount += ByteCount;
}

internal void
FetchImmediateOperand(efly_disasm_state * DisasmState, efly_decoder_context * Context,
                      char * Buffer, uint32_t * out_BufferCount, uint32_t BufferSize)
{
    uint32_t ImmOperandSize = Context->Entry.ImmSize;
    if(ImmOperandSize != DataSize_Invalid)
    {
        uint32_t EffImmSize = Context->Entry.EffImmSize;
        
        //TODO(Alex): Expand this and use EffAddressSize and EffOperandSize
        if(EffImmSize == DataSize_Forced64)
        {
            EffImmSize = (DisasmState->OperationMode == OperationMode_64Bit) ? DataSize_64Bit : DataSize_Effective;
        }
        
        Assert(EffImmSize != DataSize_Effective);
        //EffImmSize = (EffImmSize == DataSize_Effective) ? EffOperandSize;
        
        uint8_t * imm = (Context->IBase + Context->IByteCount);
        PushSignExtendedValue(DisasmState, imm, ImmOperandSize, EffImmSize, Buffer, out_BufferCount, BufferSize);
        ++Context->OpCount;
    }
    else
    {
        //TODO(Alex): Missing output buffer, logging
    }
    
    Context->IByteCount += ImmOperandSize;
}


internal void
PrintInstruction(efly_disasm_state * DisasmState, efly_decoder_context * Context, 
                 char * MemB, uint32_t MemBC, 
                 char * RegB, uint32_t RegBC, 
                 char*  ImmB, uint32_t ImmBC)
{
    efly_mnemonic_entry * Entry = &Context->Entry;
    
    printf_s("%p: " , (void*)Context->VirtualAddress);
    
    uint8_t * OpByte = Context->IBase;
    for(uint32_t OpIndex = 0;
        OpIndex < X86_MAX_INSTRUCTION_OPCOUNT;
        ++OpIndex)
    {
        if(OpIndex < Context->IByteCount)
        {
            printf_s("%0*X ", 2, *OpByte++);
        }
        else
        {
            printf_s("%*s ", 2, "");
        }
    }
    
    printf_s("%*s " , Entry->MnemonicName.Count, Entry->MnemonicName.Text);
    
    char * Source, *Dest;
    uint32_t SourceC, DestC;
    
    if(Entry->RegToModrm)
    {
        Source = RegB;
        SourceC = RegBC;
        Dest = MemB;
        DestC = MemBC;
    }
    else
    {
        Source = MemB;
        SourceC = MemBC;
        Dest = RegB;
        DestC = RegBC;
    }
    
    printf_s("%*s ", DestC, Dest); 
    printf_s(", "); 
    printf_s("%*s ", SourceC, Source); 
    printf_s(", "); 
    printf_s("%*s ", ImmBC, ImmB); 
    printf_s("\n"); 
}


inline b32 
ContextByteIsEqual(efly_decoder_context * Context, uint8_t Comparand)
{
    Assert(Context);
    uint8_t * CByte = (Context->IBase + Context->IByteCount);
    b32 Result = (*CByte == Comparand);
    return Result;
}



inline void 
OperandSizeOverridePrefixPresent(efly_decoder_context * Context)
{
    if(ContextByteIsEqual(Context, 0x66))
    {
        Context->OperandSizeOverridePrefix = true;
        ++Context->IByteCount;
    }
}

inline void
AddressSizeOverridePrefixPresent(efly_decoder_context * Context)
{
    if(ContextByteIsEqual(Context, 0x67))
    {
        Context->AddressSizeOverridePrefix = true;
        ++Context->IByteCount;
    }
}

inline b32
EscapeOpcodeBytePresent(uint8_t * CByte)
{
    b32 Result = false;
    if(CByte)
    {
        Result = (*CByte == 0x0F);
    }
    
    return Result;
}

struct eflyop_group_info
{
    efly_table_id TableID;
    uint8_t OpByteCount;
};

internal b32 
InitializeOpTable(efly_disasm_state * DisasmState, char ** RegNamesTable, uint32_t RegNamesCount)
{
    b32 Result = false;
    
    //TODO(Alex): Make File I/O 
    //TODO(Alex): Define opcode file format
    if(DisasmState && RegNamesTable)
    {
        uint32_t RegGroupsCount[RegType_Count] =
        {
            4* 8, 
            4* 8,
            
            8,
            8,
            8,
            8,
            8,
            
            4,
        };
        
        uint32_t RegIndex = 0;
        for(uint32_t GroupIndex = 0;
            GroupIndex < RegType_Count;
            ++GroupIndex)
        {
            efly_register_group * RegGroup = DisasmState->RegGroups + GroupIndex;
            RegGroup->Type = (efly_register_type)GroupIndex;
            RegGroup->Base = RegIndex;
            RegGroup->Count = RegGroupsCount[GroupIndex];
            
            for(uint32_t Index = 0; 
                Index < RegGroup->Count;
                ++Index)
            {
                efly_names_entry * Reg = DisasmState->TableRegs + DisasmState->TableRegCount++;
                char * RegName = RegNamesTable[RegIndex];
                Reg->Text = RegName;
                Reg->Count = StringLength(RegName);
                
                ++RegIndex;
            }
        }
        
        char * ADDString = "ADD";
        char * SHLDString = "SHLD";
        char * PALIGNRString = "PALIGNR";
        char * VMRESUMEString = "VMRESUME";
        char * FLDString = "FLD";
        char * FUCOMString = "FUCOM";
        char * FADDString = "FADD";
        char * AADString= "AAD";
        char * BOUNDString= "BOUND";
        char * MOVString= "MOV";
        char * PUSHString= "PUSH";
        char * JMPString= "JMP";
        
        //NOTE(Alex): Make Null Entry 
        ++DisasmState->TotalEntryCount;
        
        //TODO(Alex): Start collapsing this? Macros or inline functions?
        //NOTE(Alex): Be careful because this has to be on the same order as group types are ordered
        
        //NOTE(Alex): One byte optable entries
        
        //TODO(Alex): These are not mnemonic entries really, they are OpByte ID entries!!
        efly_mnemonic_entry * ADD_0003 = DisasmState->OpTableEntries + DisasmState->TotalEntryCount++;
        ADD_0003->OpByteID = 0x0003;
        ADD_0003->MODRMPresent = true;
        ADD_0003->RegToModrm = false;
        ADD_0003->RegisterOperandSize = (u32)DataSize_v;
        ADD_0003->OperandCount = 2;
        ADD_0003->MnemonicName.Count = StringLength(ADDString);
        ADD_0003->MnemonicName.Text = ADDString;
        ADD_0003->OperationMode = OperationMode_64Bit | OperationMode_32Bit;
        ADD_0003->RegisterType = RegType_GPR;
        
        efly_mnemonic_entry * AAD_00D5 = DisasmState->OpTableEntries + DisasmState->TotalEntryCount++;
        AAD_00D5->OpByteID = 0x00D5;
        AAD_00D5->MODRMPresent = false;
        AAD_00D5->RegToModrm = false;
        AAD_00D5->OperandCount = 1;
        AAD_00D5->RegisterOperandSize = DataSize_Invalid;
        AAD_00D5->ImmSize = DataSize_BYTE;
        AAD_00D5->MnemonicName.Count = StringLength(AADString);
        AAD_00D5->MnemonicName.Text = AADString;
        AAD_00D5->OperationMode = OperationMode_32Bit;
        
        efly_mnemonic_entry * BOUND_0062 = DisasmState->OpTableEntries + DisasmState->TotalEntryCount++;
        BOUND_0062->OpByteID = 0x0062;
        BOUND_0062->MODRMPresent = true;
        BOUND_0062->RegToModrm = false;
        BOUND_0062->OperandCount = 2;
        BOUND_0062->RegisterOperandSize = DataSize_DWORD;
        BOUND_0062->ImmSize = DataSize_Invalid;
        BOUND_0062->MnemonicName.Count = StringLength(BOUNDString);
        BOUND_0062->MnemonicName.Text = BOUNDString;
        BOUND_0062->OperationMode = OperationMode_32Bit;
        
        efly_mnemonic_entry * MOV_0089 = DisasmState->OpTableEntries + DisasmState->TotalEntryCount++;
        MOV_0089->OpByteID = 0x0089;
        MOV_0089->MODRMPresent = true;
        MOV_0089->RegToModrm = true;
        MOV_0089->OperandCount = 2;
        MOV_0089->RegisterOperandSize = (u32)DataSize_v;
        MOV_0089->ImmSize = DataSize_Invalid;
        MOV_0089->MnemonicName.Count = StringLength(MOVString);
        MOV_0089->MnemonicName.Text = MOVString;
        MOV_0089->OperationMode = OperationMode_64Bit | OperationMode_32Bit;
        
        efly_mnemonic_entry * MOV_008B = DisasmState->OpTableEntries + DisasmState->TotalEntryCount++;
        MOV_008B->OpByteID = 0x008B;
        MOV_008B->MODRMPresent = true;
        MOV_008B->RegToModrm = false;
        MOV_008B->OperandCount = 2;
        MOV_008B->RegisterOperandSize = (u32)DataSize_v;
        MOV_008B->ImmSize = DataSize_Invalid;
        MOV_008B->MnemonicName.Count = StringLength(MOVString);
        MOV_008B->MnemonicName.Text = MOVString;
        MOV_008B->OperationMode = OperationMode_64Bit | OperationMode_32Bit;
        
        efly_mnemonic_entry * MOV_008A = DisasmState->OpTableEntries + DisasmState->TotalEntryCount++;
        MOV_008A->OpByteID = 0x008A;
        MOV_008A->MODRMPresent = true;
        MOV_008A->RegToModrm = false;
        MOV_008A->OperandCount = 2;
        MOV_008A->RegisterOperandSize = DataSize_8Bit;
        MOV_008A->ImmSize = DataSize_Invalid;
        MOV_008A->MnemonicName.Count = StringLength(MOVString);
        MOV_008A->MnemonicName.Text = MOVString;
        MOV_008A->OperationMode = OperationMode_64Bit | OperationMode_32Bit;
        
        efly_mnemonic_entry * PUSH_0050 = DisasmState->OpTableEntries + DisasmState->TotalEntryCount++;
        PUSH_0050->OpByteID = 0x0050;
        PUSH_0050->MODRMPresent = false;
        PUSH_0050->RegToModrm = false;
        PUSH_0050->RegFieldInside = true;
        PUSH_0050->OperandCount = 1;
        PUSH_0050->RegisterOperandSize = DataSize_OperatingMode;
        PUSH_0050->ImmSize = DataSize_Invalid;
        PUSH_0050->MnemonicName.Count = StringLength(PUSHString);
        PUSH_0050->MnemonicName.Text = PUSHString;
        PUSH_0050->OperationMode = OperationMode_64Bit | OperationMode_32Bit;
        
        efly_mnemonic_entry * PUSH_0054 = DisasmState->OpTableEntries + DisasmState->TotalEntryCount++;
        PUSH_0054->OpByteID = 0x0054;
        PUSH_0054->MODRMPresent = false;
        PUSH_0054->RegToModrm = false;
        PUSH_0054->RegFieldInside = true;
        PUSH_0054->OperandCount = 1;
        PUSH_0054->RegisterOperandSize = DataSize_OperatingMode;
        PUSH_0054->ImmSize = DataSize_Invalid;
        PUSH_0054->MnemonicName.Count = StringLength(PUSHString);
        PUSH_0054->MnemonicName.Text = PUSHString;
        PUSH_0054->OperationMode = OperationMode_64Bit | OperationMode_32Bit;
        
        efly_mnemonic_entry * JMP_00EB = DisasmState->OpTableEntries + DisasmState->TotalEntryCount++;
        JMP_00EB->OpByteID = 0x00EB;
        JMP_00EB->MODRMPresent = false;
        JMP_00EB->RegToModrm = false;
        JMP_00EB->OperandCount = 1;
        JMP_00EB->OperandType = OperandType_NearPtrRelative;
        JMP_00EB->EffImmSize = (u32)(DataSize_Forced64);
        JMP_00EB->ImmSize = DataSize_8Bit;
        JMP_00EB->MnemonicName.Count = StringLength(JMPString);
        JMP_00EB->MnemonicName.Text = JMPString;
        JMP_00EB->OperationMode = OperationMode_64Bit | OperationMode_32Bit;
        
        efly_mnemonic_entry * JMP_00E9 = DisasmState->OpTableEntries + DisasmState->TotalEntryCount++;
        JMP_00E9->OpByteID = 0x00E9;
        JMP_00E9->MODRMPresent = false;
        JMP_00E9->RegToModrm = false;
        JMP_00E9->OperandCount = 1;
        JMP_00E9->OperandType = OperandType_NearPtrRelative;
        JMP_00E9->EffImmSize = (u32)(DataSize_Forced64);
        JMP_00E9->ImmSize = DataSize_32Bit;
        JMP_00E9->MnemonicName.Count = StringLength(JMPString);
        JMP_00E9->MnemonicName.Text = JMPString;
        JMP_00E9->OperationMode = OperationMode_64Bit | OperationMode_32Bit;
        
        //NOTE(Alex): Two byte optable entries
        efly_mnemonic_entry * SHLD_00A4 = DisasmState->OpTableEntries + DisasmState->TotalEntryCount++;
        SHLD_00A4->OpByteID = 0x00A4;
        SHLD_00A4->MODRMPresent = true;
        SHLD_00A4->RegToModrm = true;
        SHLD_00A4->RegisterOperandSize = DataSize_v;
        SHLD_00A4->ImmSize = DataSize_BYTE;
        SHLD_00A4->OperandCount = 3;
        SHLD_00A4->MnemonicName.Count = StringLength(SHLDString);
        SHLD_00A4->MnemonicName.Text = SHLDString;
        SHLD_00A4->OperationMode = OperationMode_64Bit | OperationMode_32Bit;
        
        //NOTE(Alex): Three  byte 3A optable entries
        
        efly_mnemonic_entry * PALIGNR_000F = DisasmState->OpTableEntries + DisasmState->TotalEntryCount++;
        PALIGNR_000F->OpByteID = 0x000F;
        PALIGNR_000F->MODRMPresent = true;
        PALIGNR_000F->RegToModrm = false;
        PALIGNR_000F->ImmSize = DataSize_BYTE;
        PALIGNR_000F->RegisterOperandSize = DataSize_XMM;
        PALIGNR_000F->OperandCount = 3;
        PALIGNR_000F->MnemonicName.Count = StringLength(PALIGNRString);
        PALIGNR_000F->MnemonicName.Text = PALIGNRString;
        PALIGNR_000F->OperationMode = OperationMode_64Bit | OperationMode_32Bit;
        PALIGNR_000F->RegisterType = RegType_XMM;
        PALIGNR_000F->RegOffsetA = 0;
        PALIGNR_000F->RegOffsetB = 1;
        
        //NOTE(Alex): Opt extension table entries
        
        efly_mnemonic_entry * VMRESUME_000F = DisasmState->OpTableEntries + DisasmState->TotalEntryCount++;
        VMRESUME_000F->OpByteID = 0x000F;
        VMRESUME_000F->MODRMPresent = false;
        VMRESUME_000F->ExtendedOpcode = true;
        VMRESUME_000F->RegToModrm = false;
        VMRESUME_000F->ImmSize = DataSize_Invalid;
        VMRESUME_000F->RegisterOperandSize = DataSize_Invalid;
        VMRESUME_000F->OperandCount = 0;
        VMRESUME_000F->MnemonicName.Count = StringLength(VMRESUMEString);
        VMRESUME_000F->MnemonicName.Text = VMRESUMEString;
        VMRESUME_000F->OperationMode = OperationMode_64Bit | OperationMode_32Bit;
        
        efly_mnemonic_entry * ADD_0080 = DisasmState->OpTableEntries + DisasmState->TotalEntryCount++;
        ADD_0080->OpByteID = 0x0080;
        ADD_0080->MODRMPresent = true;
        ADD_0080->ExtendedOpcode = true;
        ADD_0080->RegToModrm = true;
        ADD_0080->ImmSize = DataSize_BYTE;
        ADD_0080->RegisterOperandSize = DataSize_Invalid;
        ADD_0080->OperandCount = 2;
        ADD_0080->MnemonicName.Count = StringLength(ADDString);
        ADD_0080->MnemonicName.Text = ADDString;
        ADD_0080->OperationMode = OperationMode_64Bit | OperationMode_32Bit;
        
        efly_mnemonic_entry * JMP_20FF = DisasmState->OpTableEntries + DisasmState->TotalEntryCount++;
        JMP_20FF->OpByteID = 0x20FF;
        JMP_20FF->MODRMPresent = true;
        JMP_20FF->ExtendedOpcode = true;
        JMP_20FF->RegToModrm = false;
        JMP_20FF->OperandType = OperandType_NearPtrAbsolute;
        JMP_20FF->RegisterOperandSize = (u32)(DataSize_Forced64);
        JMP_20FF->OperandCount = 1;
        JMP_20FF->MnemonicName.Count = StringLength(JMPString);
        JMP_20FF->MnemonicName.Text = JMPString;
        JMP_20FF->OperationMode = OperationMode_64Bit | OperationMode_32Bit;
        
        efly_mnemonic_entry * JMP_28FF = DisasmState->OpTableEntries + DisasmState->TotalEntryCount++;
        JMP_28FF->OpByteID = 0x28FF;
        JMP_28FF->MODRMPresent = true;
        JMP_28FF->ExtendedOpcode = true;
        JMP_28FF->RegToModrm = false;
        JMP_28FF->OperandType = OperandType_FarPtr;
        JMP_28FF->RegisterOperandSize = (u32)(DataSize_FarP_1616,
                                              DataSize_FarP_1632,
                                              DataSize_FarP_1664);
        JMP_28FF->OperandCount = 1;
        JMP_28FF->MnemonicName.Count = StringLength(JMPString);
        JMP_28FF->MnemonicName.Text = JMPString;
        JMP_28FF->OperationMode = OperationMode_64Bit | OperationMode_32Bit;
        
        //NOTE(Alex): EscapeOpTableDD  entries
        
        efly_mnemonic_entry * FLD_00DD = DisasmState->OpTableEntries + DisasmState->TotalEntryCount++;
        FLD_00DD->OpByteID = 0x00DD;
        FLD_00DD->MODRMPresent = true;
        FLD_00DD->RegToModrm = false;
        FLD_00DD->ImmSize = DataSize_Invalid;
        FLD_00DD->RegisterOperandSize = DataSize_64Bit;
        FLD_00DD->OperandCount = 1;
        FLD_00DD->MnemonicName.Count = StringLength(FLDString);
        FLD_00DD->MnemonicName.Text = FLDString;
        FLD_00DD->OperationMode = OperationMode_64Bit | OperationMode_32Bit;
        FLD_00DD->RegisterType = RegType_X87;
        
        efly_mnemonic_entry * FUCOM_E1DD = DisasmState->OpTableEntries + DisasmState->TotalEntryCount++;
        FUCOM_E1DD->OpByteID = 0xE1DD;
        FUCOM_E1DD->MODRMPresent = true;
        FUCOM_E1DD->RegToModrm = true;
        FUCOM_E1DD->OperandCount = 2;
        FUCOM_E1DD->ImmSize = DataSize_Invalid;
        FUCOM_E1DD->RegisterOperandSize = DataSize_FloatDoubleExtended;
        FUCOM_E1DD->MnemonicName.Count = StringLength(FUCOMString);
        FUCOM_E1DD->MnemonicName.Text = FUCOMString;
        FUCOM_E1DD->OperationMode = OperationMode_64Bit | OperationMode_32Bit;
        FUCOM_E1DD->RegisterType = RegType_X87;
        FUCOM_E1DD->RegOffsetA = 1;
        FUCOM_E1DD->RegOffsetB = 0;
        
        //NOTE(Alex): EscapeOpTableD8  entries
        
        efly_mnemonic_entry * FADD_C1D8 = DisasmState->OpTableEntries + DisasmState->TotalEntryCount++;
        FADD_C1D8->OpByteID = 0xC1D8;
        FADD_C1D8->MODRMPresent = true;
        FADD_C1D8->RegToModrm = true;
        FADD_C1D8->OperandCount = 2;
        FADD_C1D8->ImmSize = DataSize_Invalid;
        FADD_C1D8->RegisterOperandSize = DataSize_FloatDoubleExtended;
        FADD_C1D8->MnemonicName.Count = StringLength(FADDString);
        FADD_C1D8->MnemonicName.Text = FADDString;
        FADD_C1D8->OperationMode = OperationMode_64Bit | OperationMode_32Bit;
        FADD_C1D8->RegisterType = RegType_X87;
        FADD_C1D8->RegOffsetA = 0;
        FADD_C1D8->RegOffsetB = 1;
        
        uint32_t EntryInfoCount = 0;
        eflyop_group_info GroupInfos[128] = {};
        GroupInfos[0].TableID = TableID_OneByteOpTable;
        GroupInfos[0].OpByteCount = 10;
        GroupInfos[1].TableID = TableID_TwoByteOpTable;
        GroupInfos[1].OpByteCount = 1;
        GroupInfos[2].TableID = TableID_ThreeByteOpTable3AH;
        GroupInfos[2].OpByteCount = 1;
        GroupInfos[3].TableID = TableID_OpExtensionTable;
        GroupInfos[3].OpByteCount = 4;
        GroupInfos[4].TableID = TableID_EscapeOpTableDD;
        GroupInfos[4].OpByteCount = 2;
        GroupInfos[5].TableID = TableID_EscapeOpTableD8;
        GroupInfos[5].OpByteCount = 1;
        
        
        //NOTE(Alex): Some instructions need to check the extension codes for mnemonic entry matching (MODRM or nnn) 
        
        /*
        IMPORTANT(Alex): 
        
        OpByte ID encoding 
        
        0x [mod reg  rm]  [mainopbyte] 
        0x [00  reg 000]  [mainopbyte] 
        0x [00  000 000]  [mainopbyte] 
        
        */
        
        uint16_t OpByteIDS[256] =
        {
            //NOTE(Alex): One byte IDS
            0x0003,
            0x00D5,
            0x0062,
            0x0089,
            0x008B,
            0x008A,
            0x0050,
            0x0054,
            0x00EB,
            0x00E9,
            
            //NOTE(Alex):TwobyteIDS
            0x00A4,
            
            //NOTE(Alex):Threebyte3AIDS
            0x000F,
            
            //NOTE(Alex):OpExtensionbyteIDS
            0x000F,
            0x0080,
            0x20FF,//NOTE(Alex):MODRMByte
            0x28FF,//NOTE(Alex):MODRMByte
            
            //NOTE(Alex):EscapeDDbyteIDS
            0x00DD,//NOTE(Alex):MODRMByte
            0xE1DD,//NOTE(Alex):MODRMByte
            
            //NOTE(Alex):EscapeD8byteIDS
            0xC1D8, //NOTE(Alex): MODRM Byte
        };
        
        
        //NOTE(Alex): Null OpByte Entry
        uint32_t OpcodeIndex = 0;
        uint32_t EntryIndex = 1;
        
        for(uint32_t GroupIndex = 0; 
            GroupIndex < ArrayCount(GroupInfos);
            ++GroupIndex)
        {
            eflyop_group_info * Info = GroupInfos + GroupIndex; 
            if(Info->TableID != TableID_Invalid)
            {
                efly_table_group * Group = DisasmState->OpTableGroups + Info->TableID;
                Group->OpByteCount = Info->OpByteCount;
                Group->FirstOpByteIndex = EntryIndex;
                
                for(uint32_t Index = 0; 
                    Index < Group->OpByteCount;
                    ++Index)
                {
                    Assert(EntryIndex <= DisasmState->TotalEntryCount);
                    efly_byte_entry * OpByteEntry = DisasmState->OpByteEntries + EntryIndex;
                    OpByteEntry->ID = OpByteIDS[OpcodeIndex++];
                    OpByteEntry->EntryIndex = EntryIndex++;
                }
            }
        }
        
        DisasmState->OpByteEntryCount = OpcodeIndex;
        Result = true;
        
    }
    
    return Result;
}

inline b32
IsValidMnemonicEntry(efly_mnemonic_entry * Entry)
{
    b32 Result = false;
    if(Entry)
    {
        //TODO(Alex): Make a formal entry validation
        Result = (Entry->MnemonicName.Text) ? true : false;
    }
    
    return Result;
}


inline uint8_t * 
CurrentByte(efly_decoder_context * Context)
{
    uint8_t * Result = 0;
    if(Context)
    {
        Result = Context->IBase + Context->IByteCount;
    }
    return Result;
}
#endif

internal void CopyRDIString(disasm_state * State, char * out_Buffer, u32 * out_BufferCount, u32 BufferSize, processor_mode ProcessorMode, u32 EffAddressSize)
{
    if(EffAddressSize == 64)
    {
        Append(out_Buffer, out_BufferCount, BufferSize, "RDI", StringLength("RDI"));
    }
    else if(EffAddressSize == 32)
    {
        Append(out_Buffer, out_BufferCount, BufferSize, "EDI", StringLength("EDI"));
    }
    else if(EffAddressSize == 16)
    {
        Append(out_Buffer, out_BufferCount, BufferSize, "DI", StringLength("DI"));
    }
}

inline b32 
SegOverridePrefixPresent(group2_prefix group2_pref)
{
	b32 Result = (group2_pref >= group2_CSOverride && group2_pref <= group2_GSOverride);
	return (Result);
}

internal void 
write_addressing_mode_from_grammar(disasm_state * State, processor_mode ProcessorMode, instruction_context * ctx, eff_operand_size EffOperandSize, eff_address_size EffAddressSize, char * out_Buffer, u32 * out_BufferCount, u32 BufferSize, char * addr_mode, u32 addr_mode_size, u64 mod_val, u64 rm_val)
{
	
	char MODRMGrammar[] = 
    {
        //[Base + Index * Scale + displacement]
        "{(<Base> +) (<Index> * <Scale> +) (<displacement>)} | <Reg>"
    };
	
    if(out_Buffer && out_BufferCount)
    {
		
		group2_prefix group2_pref = ctx->Group2Prefix;        
		bits rex = ctx->rex;
		
        u32 LastBufferCount = *out_BufferCount;
        regexp_support RegExpSupport = {};
        
        char * At = 0;
        if(InitRegExpSource(&RegExpSupport, addr_mode, addr_mode_size, &At))
        {
            while(PtrInsideString(&RegExpSupport, At))
            {
                if(StringIsEqualRegExp(&RegExpSupport, At, "<sreg>", StringLength("<sreg>")))
                {
                    if(SegOverridePrefixPresent(group2_pref))
                    {
                        append_segment_reg_masm(group2_pref, out_Buffer, out_BufferCount, BufferSize);
                    }
                    else if(!TestBit(rex, 0))
                    {
                        if(((EffAddressSize == 32) || (EffAddressSize == 64)) && (rm_val == 0b101))
                        {
                            Append(out_Buffer, out_BufferCount, BufferSize, "SS", StringLength("SS"));
                        }
                        else if((EffAddressSize == 16) && ((rm_val == 0b010) || (rm_val == 0b011)))
                        {
                            Append(out_Buffer, out_BufferCount, BufferSize, "SS", StringLength("SS"));
                        }
                        else
                        {
                            Append(out_Buffer, out_BufferCount, BufferSize, "DS", StringLength("DS"));
                        }
                    }
                    else
                    {
                        Append(out_Buffer, out_BufferCount, BufferSize, "DS", StringLength("DS"));
                    }
                    
                    AdvanceSourcePtr(&RegExpSupport, &At);
                }
                
                else if(StringIsEqualRegExp(&RegExpSupport, At, "<size>", StringLength("<size>")))
                {
					
					u32 mem_size =  (1 << 8);
					string op_size_kw_s = {};
					make_string_size(&State->i_write_arena.Arena, &op_size_kw_s, 0, mem_size);
					
					get_mem_operand_size_kw_masm(State, EffOperandSize, &op_size_kw_s);
					Append(out_Buffer, out_BufferCount, BufferSize, op_size_kw_s.buffer, op_size_kw_s.count);
                    //append_mem_operand_size_kw_masm(out_Buffer, out_BufferCount, BufferSize, EffOperandSize);
                    AdvanceSourcePtr(&RegExpSupport, &At);
                }
                
                else if(StringIsEqualRegExp(&RegExpSupport, At, "<sib>", StringLength("<sib>")))
                {
                    *out_BufferCount = LastBufferCount;
                    Base(State, EffOperandSize, EffAddressSize , group2_pref, out_Buffer, out_BufferCount, BufferSize, rex, mod_val);
                    AdvanceSourcePtr(&RegExpSupport, &At);
                }
                
                else if(StringIsEqualRegExp(&RegExpSupport, At, "<disp32>", StringLength("<disp32>")))
                {
                    u32 BufferCount = 0;
                    char Buffer[MAX_BUFFER_SIZE] = {0};
                    
                    bits disp32 = Zeroes(32);
                    disp32.value = GetBits_msb(State, disp32.bits_count);
                    bits LE = SwapBitfieldBytes(disp32);
                    
                    ConvertBitsToString(Buffer, &BufferCount, MAX_BUFFER_SIZE, &LE);
                    Append(out_Buffer, out_BufferCount, BufferSize, Buffer, BufferCount);
                    AdvanceSourcePtr(&RegExpSupport, &At);
                }
                
                else if(StringIsEqualRegExp(&RegExpSupport, At, "<disp8>", StringLength("<disp8>")))
                {
                    u32 BufferCount = 0;
                    char Buffer[MAX_BUFFER_SIZE] = {0};
                    
                    bits disp8 = Zeroes(8);
                    disp8.value = GetBits_msb(State, disp8.bits_count);
                    bits LE = SwapBitfieldBytes(disp8);
                    
                    ConvertBitsToString(Buffer, &BufferCount, MAX_BUFFER_SIZE, &LE);
                    Append(out_Buffer, out_BufferCount, BufferSize, Buffer, BufferCount);
                    AdvanceSourcePtr(&RegExpSupport, &At);
                }
                
                else if(StringIsEqualRegExp(&RegExpSupport, At, "<disp16>", StringLength("<disp16>")))
                {
                    u32 BufferCount = 0;
                    char Buffer[MAX_BUFFER_SIZE] = {0};
                    
                    bits disp16 = Zeroes(16);
                    disp16.value = GetBits_msb(State, disp16.bits_count);
                    bits LE = SwapBitfieldBytes(disp16);
                    
                    ConvertBitsToString(Buffer, &BufferCount, MAX_BUFFER_SIZE, &LE);
                    Append(out_Buffer, out_BufferCount, BufferSize, Buffer, BufferCount);
                    AdvanceSourcePtr(&RegExpSupport, &At);
                }
                
                else
                {
                    Append(out_Buffer, out_BufferCount, BufferSize, At++, 1);
                }
                
                
            }
        }
        
        EndRegExp(&RegExpSupport);
		
    }
    
}

#if 0    
//TODO(Alex): Erase this call, we dont need it anymore!
internal void 
GetAdressingMode(disasm_state * State, processor_mode ProcessorMode, u32 EffOperandSize, u32 EffAddressSize, group2_prefix SegmentOverridePrefix, char * out_Buffer, u32 * out_BufferCount, u32 BufferSize, bits_array_ * BitsArray, bits rex)
{
    char MODRMGrammar[] = 
    {
        //[Base + Index * Scale + displacement]
        "{(<Base> +) (<Index> * <Scale> +) (<displacement>)} | <Reg>"
    };
    
    if(out_Buffer && out_BufferCount)
    {
        
        u32 LastBufferCount = *out_BufferCount;
        
        bits mod = get_bitfield_from_bitsarray_bytype(BitsArray, BitfieldType_mod);
        bits rm = get_bitfield_from_bitsarray_bytype(BitsArray, BitfieldType_rm);
        
        b32 look_rex_r = false;
        string_result_file AdressingMode = ReadModrmTable(State, ProcessorMode, EffOperandSize, EffAddressSize, mod.value, rm.value, rex, look_rex_r);
        
        regexp_support RegExpSupport = {};
        
        char * At = 0;
        if(InitRegExpSource(&RegExpSupport, AdressingMode.Base, StringLength(AdressingMode.Base), &At))
        {
            while(PtrInsideString(&RegExpSupport, At))
            {
                if(StringIsEqualRegExp(&RegExpSupport, At, "<sreg>", StringLength("<sreg>")))
                {
                    if(SegmentOverridePrefix > group2_Invalid)
                    {
                        append_segment_reg_masm(SegmentOverridePrefix, out_Buffer, out_BufferCount, BufferSize);
                    }
                    else if(!TestBit(rex, 0))
                    {
                        if(((EffAddressSize == 32) || (EffAddressSize == 64)) && (rm.value == 0b101))
                        {
                            Append(out_Buffer, out_BufferCount, BufferSize, "SS", StringLength("SS"));
                        }
                        else if((EffAddressSize == 16) && ((rm.value == 0b010) || (rm.value == 0b011)))
                        {
                            Append(out_Buffer, out_BufferCount, BufferSize, "SS", StringLength("SS"));
                        }
                        else
                        {
                            Append(out_Buffer, out_BufferCount, BufferSize, "DS", StringLength("DS"));
                        }
                    }
                    else
                    {
                        Append(out_Buffer, out_BufferCount, BufferSize, "DS", StringLength("DS"));
                    }
                    
                    AdvanceSourcePtr(&RegExpSupport, &At);
                }
                
                else if(StringIsEqualRegExp(&RegExpSupport, At, "<size>", StringLength("<size>")))
                {
                    append_mem_operand_size_kw_masm(out_Buffer, out_BufferCount, BufferSize, EffOperandSize);
                    AdvanceSourcePtr(&RegExpSupport, &At);
                }
                
                else if(StringIsEqualRegExp(&RegExpSupport, At, "<sib>", StringLength("<sib>")))
                {
                    *out_BufferCount = LastBufferCount;
                    Base(State, EffOperandSize, EffAddressSize , SegmentOverridePrefix, out_Buffer, out_BufferCount, BufferSize, rex, mod);
                    AdvanceSourcePtr(&RegExpSupport, &At);
                }
                
                else if(StringIsEqualRegExp(&RegExpSupport, At, "<disp32>", StringLength("<disp32>")))
                {
                    u32 BufferCount = 0;
                    char Buffer[MAX_BUFFER_SIZE] = {0};
                    
                    bits disp32 = Zeroes(32);
                    disp32.value = GetBits_msb(State, disp32.bits_count);
                    bits LE = SwapBitfieldBytes(disp32);
                    
                    ConvertBitsToString(Buffer, &BufferCount, MAX_BUFFER_SIZE, LE);
                    Append(out_Buffer, out_BufferCount, BufferSize, Buffer, BufferCount);
                    AdvanceSourcePtr(&RegExpSupport, &At);
                }
                
                else if(StringIsEqualRegExp(&RegExpSupport, At, "<disp8>", StringLength("<disp8>")))
                {
                    u32 BufferCount = 0;
                    char Buffer[MAX_BUFFER_SIZE] = {0};
                    
                    bits disp8 = Zeroes(8);
                    disp8.value = GetBits_msb(State, disp8.bits_count);
                    bits LE = SwapBitfieldBytes(disp8);
                    
                    ConvertBitsToString(Buffer, &BufferCount, MAX_BUFFER_SIZE, LE);
                    Append(out_Buffer, out_BufferCount, BufferSize, Buffer, BufferCount);
                    AdvanceSourcePtr(&RegExpSupport, &At);
                }
                
                else if(StringIsEqualRegExp(&RegExpSupport, At, "<disp16>", StringLength("<disp16>")))
                {
                    u32 BufferCount = 0;
                    char Buffer[MAX_BUFFER_SIZE] = {0};
                    
                    bits disp16 = Zeroes(16);
                    disp16.value = GetBits_msb(State, disp16.bits_count);
                    bits LE = SwapBitfieldBytes(disp16);
                    
                    ConvertBitsToString(Buffer, &BufferCount, MAX_BUFFER_SIZE, LE);
                    Append(out_Buffer, out_BufferCount, BufferSize, Buffer, BufferCount);
                    AdvanceSourcePtr(&RegExpSupport, &At);
                }
                
                else
                {
                    Append(out_Buffer, out_BufferCount, BufferSize, At++, 1);
                }
                
                
            }
        }
        
        EndRegExp(&RegExpSupport);
		
    }
    
    if (EffAddressSize == 64)
    {
        if (TestBit(rex, 0))
        {
            switch(mod.value)
            {
                case 0b00:
                {
                    switch(rm.value)
                    {
                        case 0b000: { _snprintf_s(out_Buffer, BufferSize, BufferSize,"%s : [ R8 ]", SegmentBuffer); }break;
                        case 0b001: { _snprintf_s(out_Buffer, BufferSize, BufferSize,"%s : [ R9 ]", SegmentBuffer); }break;
                        case 0b010: { _snprintf_s(out_Buffer, BufferSize, BufferSize,"%s : [ R10 ]", SegmentBuffer); }break;
                        case 0b011: { _snprintf_s(out_Buffer, BufferSize, BufferSize,"%s : [ R11 ]", SegmentBuffer); }break;
                        case 0b100: 
                        {
                            GetSIBByte(State, EffAddressSize, SegmentOverridePrefix, SIBBuffer, SegmentBuffer, BufferSize, rex, mod);
                            _snprintf_s(out_Buffer, BufferSize, BufferSize,  "%s : [ %s ]", SegmentBuffer, SIBBuffer); 
                        }break;
                        case 0b101: { GetAdressingModerm101(State, ProcessorMode, EffAddressSize, out_Buffer, BufferSize); }break;
                        case 0b110: { _snprintf_s(out_Buffer, BufferSize, BufferSize,  "%s : [ R14 ]", SegmentBuffer); }break;
                        case 0b111: { _snprintf_s(out_Buffer, BufferSize, BufferSize,  "%s : [ R15 ]", SegmentBuffer); }break;
                    }
                }break;
                
                
                case 0b01:
                {
                    
                    switch(rm.value)
                    {
                        case 0b000: 
                        { 
                            char ImmBuffer[MAX_BUFFER_SIZE] = {0};
                            disp8.value = GetBits_msb(State, disp8.bits_count);
                            PrintImmediateToBuffer(ImmBuffer, BufferSize, EffAddressSize, disp8);
                            _snprintf_s(out_Buffer, BufferSize, BufferSize, "%s : [ R8 + %s ]", SegmentBuffer, ImmBuffer);
                        }break;
                        case 0b001: 
                        { 
                            char ImmBuffer[MAX_BUFFER_SIZE] = {0};
                            disp8.Value = GetBits_msb(State, disp8.bits_count);
                            PrintImmediateToBuffer(ImmBuffer, BufferSize, EffAddressSize, disp8);
                            _snprintf_s(out_Buffer, BufferSize, BufferSize, "%s : [ R9 + %s ]", SegmentBuffer,  ImmBuffer);
                        }break;
                        case 0b010: 
                        { 
                            char ImmBuffer[MAX_BUFFER_SIZE] = {0};
                            disp8.Value = GetBits_msb(State, disp8.bits_count);
                            PrintImmediateToBuffer(ImmBuffer, MAX_BUFFER_SIZE, EffAddressSize, disp8);
                            _snprintf_s(out_Buffer, BufferSize, BufferSize, "%s : [ R10 + %s ]", SegmentBuffer, ImmBuffer);
                        }break;
                        case 0b011: 
                        { 
                            char ImmBuffer[MAX_BUFFER_SIZE] = {0};
                            disp8.Value = GetBits_msb(State, disp8.bits_count);
                            PrintImmediateToBuffer(ImmBuffer, MAX_BUFFER_SIZE, EffAddressSize, disp8);
                            _snprintf_s(out_Buffer, BufferSize, BufferSize, "%s : [ R11 + %s ]", SegmentBuffer , ImmBuffer);
                        }break;
                        case 0b100: 
                        {
                            GetSIBByte(State, EffAddressSize, SegmentOverridePrefix, SIBBuffer, SegmentBuffer, MAX_BUFFER_SIZE, rex, mod);
                            char ImmBuffer[MAX_BUFFER_SIZE] = {0};
                            disp8.Value = GetBits_msb(State, disp8.bits_count);
                            PrintImmediateToBuffer(ImmBuffer, MAX_BUFFER_SIZE, EffAddressSize, disp8);
                            _snprintf_s(out_Buffer, BufferSize, BufferSize, "%s : [ %s + %s ]", SegmentBuffer , SIBBuffer , ImmBuffer);
                        }break;
                        case 0b101: 
                        { 
                            char ImmBuffer[MAX_BUFFER_SIZE] = {0};
                            disp8.Value = GetBits_msb(State, disp8.bits_count);
                            PrintImmediateToBuffer(ImmBuffer, MAX_BUFFER_SIZE, EffAddressSize, disp8);
                            _snprintf_s(out_Buffer, BufferSize, BufferSize, "%s : [ R13 + %s ]", SegmentBuffer , ImmBuffer);
                        }break;
                        case 0b110:
                        { 
                            char ImmBuffer[MAX_BUFFER_SIZE] = {0};
                            disp8.Value = GetBits_msb(State, disp8.bits_count);
                            PrintImmediateToBuffer(ImmBuffer, MAX_BUFFER_SIZE, EffAddressSize, disp8);
                            _snprintf_s(out_Buffer, BufferSize, BufferSize, "%s : [ R14 + %s ]", SegmentBuffer , ImmBuffer);
                        }break;
                        case 0b111: 
                        { 
                            char ImmBuffer[MAX_BUFFER_SIZE] = {0};
                            disp8.Value = GetBits_msb(State, disp8.bits_count);
                            PrintImmediateToBuffer(ImmBuffer, MAX_BUFFER_SIZE, EffAddressSize, disp8);
                            _snprintf_s(out_Buffer, BufferSize, BufferSize, "%s : [ R15 + %s ]", SegmentBuffer , ImmBuffer);
                        }break;
                    }
                }break;
                
                case 0b10:
                {
                    
                    switch(rm.Value)
                    {
                        case 0b000: 
                        { 
                            char ImmBuffer[MAX_BUFFER_SIZE] = {0};
                            disp32.Value = GetBits_msb(State, disp32.bits_count);
                            PrintImmediateToBuffer(ImmBuffer, MAX_BUFFER_SIZE, EffAddressSize, disp32);
                            _snprintf_s(out_Buffer, BufferSize, BufferSize, "%s : [ R8 + %s ]", SegmentBuffer , ImmBuffer);
                        }break;
                        case 0b001: 
                        { 
                            char ImmBuffer[MAX_BUFFER_SIZE] = {0};
                            disp32.Value = GetBits_msb(State, disp32.bits_count);
                            PrintImmediateToBuffer(ImmBuffer, MAX_BUFFER_SIZE, EffAddressSize, disp32);
                            _snprintf_s(out_Buffer, BufferSize, BufferSize, "%s : [ R9 + %s ]", SegmentBuffer , ImmBuffer);
                        }break;
                        case 0b010: 
                        { 
                            char ImmBuffer[MAX_BUFFER_SIZE] = {0};
                            disp32.Value = GetBits_msb(State, disp32.bits_count);
                            PrintImmediateToBuffer(ImmBuffer, MAX_BUFFER_SIZE, EffAddressSize, disp32);
                            _snprintf_s(out_Buffer, BufferSize, BufferSize, "%s : [ R10 + %s ]", SegmentBuffer , ImmBuffer);
                        }break;
                        case 0b011: 
                        { 
                            char ImmBuffer[MAX_BUFFER_SIZE] = {0};
                            disp32.Value = GetBits_msb(State, disp32.bits_count);
                            PrintImmediateToBuffer(ImmBuffer, MAX_BUFFER_SIZE, EffAddressSize, disp32);
                            _snprintf_s(out_Buffer, BufferSize, BufferSize, "%s : [ R11 + %s ]", SegmentBuffer , ImmBuffer);
                        }break;
                        case 0b100: 
                        {
                            GetSIBByte(State, EffAddressSize, SegmentOverridePrefix,SIBBuffer, SegmentBuffer, MAX_BUFFER_SIZE, rex, mod);
                            char ImmBuffer[MAX_BUFFER_SIZE] = {0};
                            disp32.Value = GetBits_msb(State, disp32.bits_count);
                            PrintImmediateToBuffer(ImmBuffer, MAX_BUFFER_SIZE, EffAddressSize, disp32);
                            _snprintf_s(out_Buffer, BufferSize, BufferSize, "%s : [ %s + %s ]", SegmentBuffer, SIBBuffer , ImmBuffer);
                        }break;
                        case 0b101: 
                        { 
                            char ImmBuffer[MAX_BUFFER_SIZE] = {0};
                            disp32.Value = GetBits_msb(State, disp32.bits_count);
                            PrintImmediateToBuffer(ImmBuffer, MAX_BUFFER_SIZE, EffAddressSize, disp32);
                            _snprintf_s(out_Buffer, BufferSize, BufferSize, "%s : [ R13 + %s ]", SegmentBuffer , ImmBuffer);
                        }break;
                        case 0b110: 
                        { 
                            char ImmBuffer[MAX_BUFFER_SIZE] = {0};
                            disp32.Value = GetBits_msb(State, disp32.bits_count);
                            PrintImmediateToBuffer(ImmBuffer, MAX_BUFFER_SIZE, EffAddressSize, disp32);
                            _snprintf_s(out_Buffer, BufferSize, BufferSize, "%s : [ R14 + %s ]", SegmentBuffer , ImmBuffer);
                        }break;
                        case 0b111: 
                        { 
                            char ImmBuffer[MAX_BUFFER_SIZE] = {0};
                            disp32.Value = GetBits_msb(State, disp32.bits_count);
                            PrintImmediateToBuffer(ImmBuffer, MAX_BUFFER_SIZE, EffAddressSize, disp32);
                            _snprintf_s(out_Buffer, BufferSize, BufferSize, "%s : [ R15 + %s ]", SegmentBuffer , ImmBuffer);
                        }break;
                    }
                }break;
                
                case 0b11: 
                { 
                    GetReg(ProcessorMode, EffOperandSize, regBuffer, MAX_BUFFER_SIZE, rex, rm, false);
                    _snprintf_s(out_Buffer, BufferSize, BufferSize,  "%s", regBuffer); 
                }break;
            }
        }
        else
        {
            switch(mod.Value)
            {
                case 0b00:
                {
                    switch(rm.Value)
                    {
                        case 0b000: { _snprintf_s(out_Buffer, BufferSize, BufferSize,  "%s : [ RAX ]", SegmentBuffer ); }break;
                        case 0b001: { _snprintf_s(out_Buffer, BufferSize, BufferSize,  "%s : [ RCX ]", SegmentBuffer ); }break;
                        case 0b010: { _snprintf_s(out_Buffer, BufferSize, BufferSize,  "%s : [ RDX ]", SegmentBuffer ); }break;
                        case 0b011: { _snprintf_s(out_Buffer, BufferSize, BufferSize,  "%s : [ RBX ]", SegmentBuffer ); }break;
                        case 0b100: 
                        {
                            GetSIBByte(State, EffAddressSize,SegmentOverridePrefix, SIBBuffer, SegmentBuffer, MAX_BUFFER_SIZE, rex, mod);
                            _snprintf_s(out_Buffer, BufferSize, BufferSize,  "%s : [ %s ]", SegmentBuffer, SIBBuffer); 
                        }break;
                        case 0b101: { GetAdressingModerm101(State, ProcessorMode, EffAddressSize, out_Buffer, BufferSize); }break;
                        case 0b110: { _snprintf_s(out_Buffer, BufferSize, BufferSize,  "%s : [ RSI ]", SegmentBuffer ); }break;
                        case 0b111: { _snprintf_s(out_Buffer, BufferSize, BufferSize,  "%s : [ RDI ]", SegmentBuffer ); }break;
                    }
                }break;
                
                case 0b01:
                {
                    
                    switch(rm.Value)
                    {
                        case 0b000: 
                        { 
                            char ImmBuffer[MAX_BUFFER_SIZE] = {0};
                            disp8.Value = GetBits_msb(State, disp8.bits_count);
                            PrintImmediateToBuffer(ImmBuffer, MAX_BUFFER_SIZE, EffAddressSize, disp8);
                            _snprintf_s(out_Buffer, BufferSize, BufferSize, "%s : [ RAX + %s ]", SegmentBuffer , ImmBuffer);
                        }break;
                        case 0b001: 
                        { 
                            char ImmBuffer[MAX_BUFFER_SIZE] = {0};
                            disp8.Value = GetBits_msb(State, disp8.bits_count);
                            PrintImmediateToBuffer(ImmBuffer, MAX_BUFFER_SIZE, EffAddressSize, disp8);
                            _snprintf_s(out_Buffer, BufferSize, BufferSize, "%s : [ RCX + %s ]", SegmentBuffer , ImmBuffer);
                        }break;
                        case 0b010: 
                        { 
                            char ImmBuffer[MAX_BUFFER_SIZE] = {0};
                            disp8.Value = GetBits_msb(State, disp8.bits_count);
                            PrintImmediateToBuffer(ImmBuffer, MAX_BUFFER_SIZE, EffAddressSize, disp8);
                            _snprintf_s(out_Buffer, BufferSize, BufferSize, "%s : [ RDX + %s ]", SegmentBuffer , ImmBuffer);
                        }break;
                        case 0b011: 
                        {
                            char ImmBuffer[MAX_BUFFER_SIZE] = {0};
                            disp8.Value = GetBits_msb(State, disp8.bits_count);
                            PrintImmediateToBuffer(ImmBuffer, MAX_BUFFER_SIZE, EffAddressSize, disp8);
                            _snprintf_s(out_Buffer, BufferSize, BufferSize, "%s : [ RBX + %s ]", SegmentBuffer , ImmBuffer);
                        }break;
                        case 0b100: 
                        { 
                            GetSIBByte(State, EffAddressSize, SegmentOverridePrefix, SIBBuffer, SegmentBuffer, MAX_BUFFER_SIZE, rex, mod);
                            char ImmBuffer[MAX_BUFFER_SIZE] = {0};
                            disp8.Value = GetBits_msb(State, disp8.bits_count);
                            PrintImmediateToBuffer(ImmBuffer, MAX_BUFFER_SIZE, EffAddressSize, disp8);
                            _snprintf_s(out_Buffer, BufferSize, BufferSize, "%s : [ %s + %s ]", SegmentBuffer,  SIBBuffer, ImmBuffer);
                        }break;
                        case 0b101: 
                        { 
                            char ImmBuffer[MAX_BUFFER_SIZE] = {0};
                            disp8.Value = GetBits_msb(State, disp8.bits_count);
                            PrintImmediateToBuffer(ImmBuffer, MAX_BUFFER_SIZE, EffAddressSize, disp8);
                            _snprintf_s(out_Buffer, BufferSize, BufferSize, "%s : [ RBP + %s ]", SegmentBuffer , ImmBuffer);
                        }break;
                        case 0b110: 
                        {
                            char ImmBuffer[MAX_BUFFER_SIZE] = {0};
                            disp8.Value = GetBits_msb(State, disp8.bits_count);
                            PrintImmediateToBuffer(ImmBuffer, MAX_BUFFER_SIZE, EffAddressSize, disp8);
                            _snprintf_s(out_Buffer, BufferSize, BufferSize, "%s : [ RSI + %s ]", SegmentBuffer , ImmBuffer);
                        }break;
                        case 0b111: 
                        { 
                            char ImmBuffer[MAX_BUFFER_SIZE] = {0};
                            disp8.Value = GetBits_msb(State, disp8.bits_count);
                            PrintImmediateToBuffer(ImmBuffer, MAX_BUFFER_SIZE, EffAddressSize, disp8);
                            _snprintf_s(out_Buffer, BufferSize, BufferSize, "%s : [ RDI + %s ]", SegmentBuffer , ImmBuffer);
                        }break;
                    }
                }break;
                
                case 0b10:
                {
                    
                    switch(rm.Value)
                    {
                        case 0b000: 
                        { 
                            char ImmBuffer[MAX_BUFFER_SIZE] = {0};
                            disp32.Value = GetBits_msb(State, disp32.bits_count);
                            PrintImmediateToBuffer(ImmBuffer, MAX_BUFFER_SIZE, EffAddressSize, disp32);
                            _snprintf_s(out_Buffer, BufferSize, BufferSize, "%s : [ RAX + %s ]", SegmentBuffer , ImmBuffer);
                        }break;
                        case 0b001: 
                        { 
                            char ImmBuffer[MAX_BUFFER_SIZE] = {0};
                            disp32.Value = GetBits_msb(State, disp32.bits_count);
                            PrintImmediateToBuffer(ImmBuffer, MAX_BUFFER_SIZE, EffAddressSize, disp32);
                            _snprintf_s(out_Buffer, BufferSize, BufferSize, "%s : [ RCX + %s ]", SegmentBuffer , ImmBuffer);
                        }break;
                        case 0b010: 
                        {
                            char ImmBuffer[MAX_BUFFER_SIZE] = {0};
                            disp32.Value = GetBits_msb(State, disp32.bits_count);
                            PrintImmediateToBuffer(ImmBuffer, MAX_BUFFER_SIZE, EffAddressSize, disp32);
                            _snprintf_s(out_Buffer, BufferSize, BufferSize, "%s : [ RDX + %s ]", SegmentBuffer , ImmBuffer);
                        }break;
                        case 0b011: 
                        { 
                            char ImmBuffer[MAX_BUFFER_SIZE] = {0};
                            disp32.Value = GetBits_msb(State, disp32.bits_count);
                            PrintImmediateToBuffer(ImmBuffer, MAX_BUFFER_SIZE, EffAddressSize, disp32);
                            _snprintf_s(out_Buffer, BufferSize, BufferSize, "%s : [ RBX + %s ]", SegmentBuffer , ImmBuffer);
                        }break;
                        case 0b100: 
                        {
                            GetSIBByte(State, EffAddressSize, SegmentOverridePrefix,SIBBuffer, SegmentBuffer, MAX_BUFFER_SIZE, rex, mod);
                            char ImmBuffer[MAX_BUFFER_SIZE] = {0};
                            disp32.Value = GetBits_msb(State, disp32.bits_count);
                            PrintImmediateToBuffer(ImmBuffer, MAX_BUFFER_SIZE, EffAddressSize, disp32);
                            _snprintf_s(out_Buffer, BufferSize, BufferSize, "%s : [ %s + %s ]", SegmentBuffer, SIBBuffer, ImmBuffer);
                        }break;
                        case 0b101: 
                        {
                            char ImmBuffer[MAX_BUFFER_SIZE] = {0};
                            disp32.Value = GetBits_msb(State, disp32.bits_count);
                            PrintImmediateToBuffer(ImmBuffer, MAX_BUFFER_SIZE, EffAddressSize, disp32);
                            _snprintf_s(out_Buffer, BufferSize, BufferSize, "%s : [ RBP + %s ]", SegmentBuffer , ImmBuffer);
                        }break;
                        case 0b110: 
                        {
                            char ImmBuffer[MAX_BUFFER_SIZE] = {0};
                            disp32.Value = GetBits_msb(State, disp32.bits_count);
                            PrintImmediateToBuffer(ImmBuffer, MAX_BUFFER_SIZE, EffAddressSize, disp32);
                            _snprintf_s(out_Buffer, BufferSize, BufferSize, "%s : [ RSI + %s ]", SegmentBuffer , ImmBuffer);
                        }break;
                        case 0b111: 
                        { 
                            char ImmBuffer[MAX_BUFFER_SIZE] = {0};
                            disp32.Value = GetBits_msb(State, disp32.bits_count);
                            PrintImmediateToBuffer(ImmBuffer, MAX_BUFFER_SIZE, EffAddressSize, disp32);
                            _snprintf_s(out_Buffer, BufferSize, BufferSize, "%s : [ RDI + %s ]", SegmentBuffer , ImmBuffer);
                        }break;
                    }
                }break;
                
                case 0b11: 
                {
                    GetReg(ProcessorMode, EffOperandSize, regBuffer, MAX_BUFFER_SIZE, rex, rm, false);
                    _snprintf_s(out_Buffer, BufferSize, BufferSize,  "%s", regBuffer); 
                }break;
            }
        }
    }
    else if (EffAddressSize == 32)
    {
        if (TestBit(rex, 0))
        {
            switch(mod.Value)
            {
                case 0b00:
                {
                    
                    switch(rm.Value)
                    {
                        case 0b000: { _snprintf_s(out_Buffer, BufferSize, BufferSize,  "%s : [ R8D ]", SegmentBuffer ); }break;
                        case 0b001: { _snprintf_s(out_Buffer, BufferSize, BufferSize,  "%s : [ R9D ]", SegmentBuffer ); }break;
                        case 0b010: { _snprintf_s(out_Buffer, BufferSize, BufferSize,  "%s : [ R10D ]", SegmentBuffer ); }break;
                        case 0b011: { _snprintf_s(out_Buffer, BufferSize, BufferSize,  "%s : [ R11D ]", SegmentBuffer ); }break;
                        case 0b100: 
                        { 
                            GetSIBByte(State, EffAddressSize, SegmentOverridePrefix,SIBBuffer,SegmentBuffer,  MAX_BUFFER_SIZE, rex, mod);
                            _snprintf_s(out_Buffer, BufferSize, BufferSize,  "%s : [ %s ]",SegmentBuffer,  SIBBuffer); 
                        }break;
                        case 0b101: { GetAdressingModerm101(State, ProcessorMode, EffAddressSize, out_Buffer, BufferSize); }break;
                        case 0b110: { _snprintf_s(out_Buffer, BufferSize, BufferSize,  "%s : [ R14D ]", SegmentBuffer ); }break;
                        case 0b111: { _snprintf_s(out_Buffer, BufferSize, BufferSize,  "%s : [ R15D ]", SegmentBuffer ); }break;
                    }
                }break;
                
                case 0b01:
                {
                    
                    switch(rm.Value)
                    {
                        case 0b000: 
                        {
                            char ImmBuffer[MAX_BUFFER_SIZE] = {0};
                            disp8.Value = GetBits_msb(State, disp8.bits_count);
                            PrintImmediateToBuffer(ImmBuffer, MAX_BUFFER_SIZE, EffAddressSize, disp8);
                            _snprintf_s(out_Buffer, BufferSize, BufferSize, "%s : [ R8D + %s ]", SegmentBuffer, ImmBuffer);
                        }break;
                        case 0b001: 
                        { 
                            char ImmBuffer[MAX_BUFFER_SIZE] = {0};
                            disp8.Value = GetBits_msb(State, disp8.bits_count);
                            PrintImmediateToBuffer(ImmBuffer, MAX_BUFFER_SIZE, EffAddressSize, disp8);
                            _snprintf_s(out_Buffer, BufferSize, BufferSize, "%s : [ R9D + %s ]", SegmentBuffer, ImmBuffer);
                        }break;
                        case 0b010: 
                        {
                            char ImmBuffer[MAX_BUFFER_SIZE] = {0};
                            disp8.Value = GetBits_msb(State, disp8.bits_count);
                            PrintImmediateToBuffer(ImmBuffer, MAX_BUFFER_SIZE, EffAddressSize, disp8);
                            _snprintf_s(out_Buffer, BufferSize, BufferSize, "%s : [ R10D + %s ]", SegmentBuffer, ImmBuffer);
                        }break;
                        case 0b011: 
                        {
                            char ImmBuffer[MAX_BUFFER_SIZE] = {0};
                            disp8.Value = GetBits_msb(State, disp8.bits_count);
                            PrintImmediateToBuffer(ImmBuffer, MAX_BUFFER_SIZE, EffAddressSize, disp8);
                            _snprintf_s(out_Buffer, BufferSize, BufferSize, "%s : [ R11D + %s ]", SegmentBuffer, ImmBuffer);
                        }break;
                        case 0b100: 
                        {
                            GetSIBByte(State, EffAddressSize, SegmentOverridePrefix,SIBBuffer, SegmentBuffer, MAX_BUFFER_SIZE, rex, mod);
                            char ImmBuffer[MAX_BUFFER_SIZE] = {0};
                            disp8.Value = GetBits_msb(State, disp8.bits_count);
                            PrintImmediateToBuffer(ImmBuffer, MAX_BUFFER_SIZE, EffAddressSize, disp8);
                            _snprintf_s(out_Buffer, BufferSize, BufferSize, "%s : [ %s + %s ]", SegmentBuffer, SIBBuffer, ImmBuffer);
                        }break;
                        case 0b101: 
                        {
                            char ImmBuffer[MAX_BUFFER_SIZE] = {0};
                            disp8.Value = GetBits_msb(State, disp8.bits_count);
                            PrintImmediateToBuffer(ImmBuffer, MAX_BUFFER_SIZE, EffAddressSize, disp8);
                            _snprintf_s(out_Buffer, BufferSize, BufferSize, "%s : [ R13D + %s ]", SegmentBuffer, ImmBuffer);
                        }break;
                        case 0b110: 
                        { 
                            char ImmBuffer[MAX_BUFFER_SIZE] = {0};
                            disp8.Value = GetBits_msb(State, disp8.bits_count);
                            PrintImmediateToBuffer(ImmBuffer, MAX_BUFFER_SIZE, EffAddressSize, disp8);
                            _snprintf_s(out_Buffer, BufferSize, BufferSize, "%s : [ R14D + %s ]", SegmentBuffer, ImmBuffer);
                        }break;
                        case 0b111: 
                        {
                            char ImmBuffer[MAX_BUFFER_SIZE] = {0};
                            disp8.Value = GetBits_msb(State, disp8.bits_count);
                            PrintImmediateToBuffer(ImmBuffer, MAX_BUFFER_SIZE, EffAddressSize, disp8);
                            _snprintf_s(out_Buffer, BufferSize, BufferSize, "%s : [ R15D + %s ]", SegmentBuffer, ImmBuffer);
                        }break;
                    }
                }break;
                
                case 0b10:
                {
                    
                    switch(rm.Value)
                    {
                        case 0b000: 
                        { 
                            char ImmBuffer[MAX_BUFFER_SIZE] = {0};
                            disp32.Value = GetBits_msb(State, disp32.bits_count);
                            PrintImmediateToBuffer(ImmBuffer, MAX_BUFFER_SIZE, EffAddressSize, disp32);
                            _snprintf_s(out_Buffer, BufferSize, BufferSize, "%s : [ R8D + %s ]", SegmentBuffer, ImmBuffer);
                        }break;
                        case 0b001: 
                        { 
                            char ImmBuffer[MAX_BUFFER_SIZE] = {0};
                            disp32.Value = GetBits_msb(State, disp32.bits_count);
                            PrintImmediateToBuffer(ImmBuffer, MAX_BUFFER_SIZE, EffAddressSize, disp32);
                            _snprintf_s(out_Buffer, BufferSize, BufferSize, "%s : [ R9D + %s ]", SegmentBuffer, ImmBuffer);
                        }break;
                        case 0b010: 
                        {
                            char ImmBuffer[MAX_BUFFER_SIZE] = {0};
                            disp32.Value = GetBits_msb(State, disp32.bits_count);
                            PrintImmediateToBuffer(ImmBuffer, MAX_BUFFER_SIZE, EffAddressSize, disp32);
                            _snprintf_s(out_Buffer, BufferSize, BufferSize, "%s : [ R10D + %s ]", SegmentBuffer, ImmBuffer);
                        }break;
                        case 0b011: 
                        { 
                            char ImmBuffer[MAX_BUFFER_SIZE] = {0};
                            disp32.Value = GetBits_msb(State, disp32.bits_count);
                            PrintImmediateToBuffer(ImmBuffer, MAX_BUFFER_SIZE, EffAddressSize, disp32);
                            _snprintf_s(out_Buffer, BufferSize, BufferSize, "%s : [ R11D + %s ]", SegmentBuffer, ImmBuffer);
                        }break;
                        case 0b100: 
                        {
                            GetSIBByte(State, EffAddressSize, SegmentOverridePrefix,SIBBuffer, SegmentBuffer, MAX_BUFFER_SIZE, rex, mod);
                            char ImmBuffer[MAX_BUFFER_SIZE] = {0};
                            disp32.Value = GetBits_msb(State, disp32.bits_count);
                            PrintImmediateToBuffer(ImmBuffer, MAX_BUFFER_SIZE, EffAddressSize, disp32);
                            _snprintf_s(out_Buffer, BufferSize, BufferSize, "%s : [ %s + %s ]", SegmentBuffer, SIBBuffer, ImmBuffer);
                        }break;
                        case 0b101: 
                        {
                            char ImmBuffer[MAX_BUFFER_SIZE] = {0};
                            disp32.Value = GetBits_msb(State, disp32.bits_count);
                            PrintImmediateToBuffer(ImmBuffer, MAX_BUFFER_SIZE, EffAddressSize, disp32);
                            _snprintf_s(out_Buffer, BufferSize, BufferSize, "%s : [ R13D + %s ]", SegmentBuffer, ImmBuffer);
                        }break;
                        case 0b110: 
                        {
                            char ImmBuffer[MAX_BUFFER_SIZE] = {0};
                            disp32.Value = GetBits_msb(State, disp32.bits_count);
                            PrintImmediateToBuffer(ImmBuffer, MAX_BUFFER_SIZE, EffAddressSize, disp32);
                            _snprintf_s(out_Buffer, BufferSize, BufferSize, "%s : [ R14D + %s ]", SegmentBuffer, ImmBuffer);
                        }break;
                        case 0b111: 
                        { 
                            char ImmBuffer[MAX_BUFFER_SIZE] = {0};
                            disp32.Value = GetBits_msb(State, disp32.bits_count);
                            PrintImmediateToBuffer(ImmBuffer, MAX_BUFFER_SIZE, EffAddressSize, disp32);
                            _snprintf_s(out_Buffer, BufferSize, BufferSize, "%s : [ R15D + %s ]", SegmentBuffer, ImmBuffer);
                        }break;
                    }
                }break;
                
                case 0b11: 
                { 
                    GetReg(ProcessorMode, EffOperandSize, regBuffer, MAX_BUFFER_SIZE, rex, rm, false);
                    _snprintf_s(out_Buffer, BufferSize, BufferSize,  "%s", regBuffer); 
                }break;
            }
        }
        else
        {
            switch(mod.Value)
            {
                case 0b00:
                {
                    switch(rm.Value)
                    {
                        case 0b000: { _snprintf_s(out_Buffer, BufferSize, BufferSize,  "%s : [ EAX ]", SegmentBuffer); }break;
                        case 0b001: { _snprintf_s(out_Buffer, BufferSize, BufferSize,  "%s : [ ECX ]", SegmentBuffer); }break;
                        case 0b010: { _snprintf_s(out_Buffer, BufferSize, BufferSize,  "%s : [ EDX ]", SegmentBuffer); }break;
                        case 0b011: { _snprintf_s(out_Buffer, BufferSize, BufferSize,  "%s : [ EBX ]", SegmentBuffer); }break;
                        case 0b100: 
                        {
                            GetSIBByte(State, EffAddressSize, SegmentOverridePrefix,SIBBuffer, SegmentBuffer, MAX_BUFFER_SIZE, rex, mod);
                            _snprintf_s(out_Buffer, BufferSize, BufferSize,  "%s : [ %s ]", SegmentBuffer, SIBBuffer); 
                        }break;
                        case 0b101: { GetAdressingModerm101(State, ProcessorMode, EffAddressSize, out_Buffer, BufferSize); }break;
                        case 0b110: { _snprintf_s(out_Buffer, BufferSize, BufferSize,  "%s : [ ESI ]", SegmentBuffer); }break;
                        case 0b111: { _snprintf_s(out_Buffer, BufferSize, BufferSize,  "%s : [ EDI ]", SegmentBuffer); }break;
                    }
                }break;
                
                case 0b01:
                {
                    
                    switch(rm.Value)
                    {
                        case 0b000: 
                        { 
                            char ImmBuffer[MAX_BUFFER_SIZE] = {0};
                            disp8.Value = GetBits_msb(State, disp8.bits_count);
                            PrintImmediateToBuffer(ImmBuffer, MAX_BUFFER_SIZE, EffAddressSize, disp8);
                            _snprintf_s(out_Buffer, BufferSize, BufferSize, "%s : [ EAX + %s ]", SegmentBuffer, ImmBuffer);
                        }break;
                        case 0b001: 
                        { 
                            char ImmBuffer[MAX_BUFFER_SIZE] = {0};
                            disp8.Value = GetBits_msb(State, disp8.bits_count);
                            PrintImmediateToBuffer(ImmBuffer, MAX_BUFFER_SIZE, EffAddressSize, disp8);
                            _snprintf_s(out_Buffer, BufferSize, BufferSize, "%s : [ ECX + %s ]", SegmentBuffer, ImmBuffer);
                        }break;
                        case 0b010: 
                        {
                            char ImmBuffer[MAX_BUFFER_SIZE] = {0};
                            disp8.Value = GetBits_msb(State, disp8.bits_count);
                            PrintImmediateToBuffer(ImmBuffer, MAX_BUFFER_SIZE, EffAddressSize, disp8);
                            _snprintf_s(out_Buffer, BufferSize, BufferSize, "%s : [ EDX + %s ]", SegmentBuffer, ImmBuffer);
                        }break;
                        case 0b011: 
                        { 
                            char ImmBuffer[MAX_BUFFER_SIZE] = {0};
                            disp8.Value = GetBits_msb(State, disp8.bits_count);
                            PrintImmediateToBuffer(ImmBuffer, MAX_BUFFER_SIZE, EffAddressSize, disp8);
                            _snprintf_s(out_Buffer, BufferSize, BufferSize, "%s : [ EBX + %s ]", SegmentBuffer, ImmBuffer);
                        }break;
                        case 0b100: 
                        {
                            GetSIBByte(State, EffAddressSize, SegmentOverridePrefix,SIBBuffer, SegmentBuffer ,MAX_BUFFER_SIZE, rex, mod);
                            char ImmBuffer[MAX_BUFFER_SIZE] = {0};
                            disp8.Value = GetBits_msb(State, disp8.bits_count);
                            PrintImmediateToBuffer(ImmBuffer, MAX_BUFFER_SIZE, EffAddressSize, disp8);
                            _snprintf_s(out_Buffer, BufferSize, BufferSize, "%s : [ %s + %s ]", SegmentBuffer,  SIBBuffer, ImmBuffer);
                        }break;
                        case 0b101: 
                        {
                            char ImmBuffer[MAX_BUFFER_SIZE] = {0};
                            disp8.Value = GetBits_msb(State, disp8.bits_count);
                            PrintImmediateToBuffer(ImmBuffer, MAX_BUFFER_SIZE, EffAddressSize, disp8);
                            _snprintf_s(out_Buffer, BufferSize, BufferSize, "%s : [ EBP + %s ]", SegmentBuffer ,  ImmBuffer);
                        }break;
                        case 0b110: 
                        { 
                            char ImmBuffer[MAX_BUFFER_SIZE] = {0};
                            disp8.Value = GetBits_msb(State, disp8.bits_count);
                            PrintImmediateToBuffer(ImmBuffer, MAX_BUFFER_SIZE, EffAddressSize, disp8);
                            _snprintf_s(out_Buffer, BufferSize, BufferSize, "%s : [ ESI + %s ]", SegmentBuffer, ImmBuffer);
                        }break;
                        case 0b111: 
                        {
                            char ImmBuffer[MAX_BUFFER_SIZE] = {0};
                            disp8.Value = GetBits_msb(State, disp8.bits_count);
                            PrintImmediateToBuffer(ImmBuffer, MAX_BUFFER_SIZE, EffAddressSize, disp8);
                            _snprintf_s(out_Buffer, BufferSize, BufferSize, "%s : [ EDI + %s ]", SegmentBuffer, ImmBuffer);
                        }break;
                    }
                }break;
                
                case 0b10:
                {
                    
                    switch(rm.Value)
                    {
                        case 0b000: 
                        {
                            char ImmBuffer[MAX_BUFFER_SIZE] = {0};
                            disp32.Value = GetBits_msb(State, disp32.bits_count);
                            PrintImmediateToBuffer(ImmBuffer, MAX_BUFFER_SIZE, EffAddressSize, disp32);
                            _snprintf_s(out_Buffer, BufferSize, BufferSize, "%s : [ EAX + %s ]", SegmentBuffer, ImmBuffer);
                        }break;
                        case 0b001: 
                        { 
                            char ImmBuffer[MAX_BUFFER_SIZE] = {0};
                            disp32.Value = GetBits_msb(State, disp32.bits_count);
                            PrintImmediateToBuffer(ImmBuffer, MAX_BUFFER_SIZE, EffAddressSize, disp32);
                            _snprintf_s(out_Buffer, BufferSize, BufferSize, "%s : [ ECX + %s ]", SegmentBuffer, ImmBuffer);
                        }break;
                        case 0b010: 
                        { 
                            char ImmBuffer[MAX_BUFFER_SIZE] = {0};
                            disp32.Value = GetBits_msb(State, disp32.bits_count);
                            PrintImmediateToBuffer(ImmBuffer, MAX_BUFFER_SIZE, EffAddressSize, disp32);
                            _snprintf_s(out_Buffer, BufferSize, BufferSize, "%s : [ EDX + %s ]", SegmentBuffer, ImmBuffer);
                        }break;
                        case 0b011: 
                        { 
                            char ImmBuffer[MAX_BUFFER_SIZE] = {0};
                            disp32.Value = GetBits_msb(State, disp32.bits_count);
                            PrintImmediateToBuffer(ImmBuffer, MAX_BUFFER_SIZE, EffAddressSize, disp32);
                            _snprintf_s(out_Buffer, BufferSize, BufferSize, "%s : [ EBX + %s ]", SegmentBuffer, ImmBuffer);
                        }break;
                        case 0b100: 
                        {
                            GetSIBByte(State, EffAddressSize, SegmentOverridePrefix,SIBBuffer, SegmentBuffer, MAX_BUFFER_SIZE, rex, mod);
                            char ImmBuffer[MAX_BUFFER_SIZE] = {0};
                            disp32.Value = GetBits_msb(State, disp32.bits_count);
                            PrintImmediateToBuffer(ImmBuffer, MAX_BUFFER_SIZE, EffAddressSize, disp32);
                            _snprintf_s(out_Buffer, BufferSize, BufferSize, "%s : [ %s + %s ]", SegmentBuffer, SIBBuffer, ImmBuffer);
                        }break;
                        case 0b101: 
                        { 
                            char ImmBuffer[MAX_BUFFER_SIZE] = {0};
                            disp32.Value = GetBits_msb(State, disp32.bits_count);
                            PrintImmediateToBuffer(ImmBuffer, MAX_BUFFER_SIZE, EffAddressSize, disp32);
                            _snprintf_s(out_Buffer, BufferSize, BufferSize, "%s : [ EBP + %s ]", SegmentBuffer, ImmBuffer);
                        }break;
                        case 0b110: 
                        {
                            char ImmBuffer[MAX_BUFFER_SIZE] = {0};
                            disp32.Value = GetBits_msb(State, disp32.bits_count);
                            PrintImmediateToBuffer(ImmBuffer, MAX_BUFFER_SIZE, EffAddressSize, disp32);
                            _snprintf_s(out_Buffer, BufferSize, BufferSize, "%s : [ ESI + %s ]", SegmentBuffer, ImmBuffer);
                        }break;
                        case 0b111:
                        {
                            char ImmBuffer[MAX_BUFFER_SIZE] = {0};
                            disp32.Value = GetBits_msb(State, disp32.bits_count);
                            PrintImmediateToBuffer(ImmBuffer, MAX_BUFFER_SIZE, EffAddressSize, disp32);
                            _snprintf_s(out_Buffer, BufferSize, BufferSize, "%s : [ EDI + %s ]", SegmentBuffer, ImmBuffer);
                        }break;
                    }
                }break;
                
                case 0b11: 
                { 
                    GetReg(ProcessorMode, EffOperandSize, regBuffer, MAX_BUFFER_SIZE, rex, rm, false);
                    _snprintf_s(out_Buffer, BufferSize, BufferSize,  "%s", regBuffer); 
                }break;
            }
        }
    }
    
    else if (EffAddressSize == 16)
    {
        switch(mod.Value)
        {
            case 0b00:
            {
                switch(rm.Value)
                {
                    case 0b000: { _snprintf_s(out_Buffer, BufferSize, BufferSize,  "%s : [ BX + SI ]", SegmentBuffer); }break;
                    case 0b001: { _snprintf_s(out_Buffer, BufferSize, BufferSize,  "%s : [ BX + DI ]", SegmentBuffer); }break;
                    case 0b010: { _snprintf_s(out_Buffer, BufferSize, BufferSize,  "%s : [ BP + SI ]", SegmentBuffer); }break; //NOTE(Alex): (defaults to SS)
                    case 0b011: { _snprintf_s(out_Buffer, BufferSize, BufferSize,  "%s : [ BP + DI ]", SegmentBuffer); }break; //NOTE(Alex): (defaults to SS) 
                    case 0b100: { _snprintf_s(out_Buffer, BufferSize, BufferSize,  "%s : [ SI ]", SegmentBuffer); }break;
                    case 0b101: { _snprintf_s(out_Buffer, BufferSize, BufferSize,  "%s : [ DI ]", SegmentBuffer); }break;
                    case 0b110: 
                    {
                        char ImmBuffer[MAX_BUFFER_SIZE] = {0};
                        disp16.Value = GetBits_msb(State, disp16.bits_count);
                        PrintImmediateToBuffer(ImmBuffer, MAX_BUFFER_SIZE, EffAddressSize, disp16);
                        _snprintf_s(out_Buffer, BufferSize, BufferSize,  "%s : [ %s ]", SegmentBuffer, ImmBuffer ); 
                    }break;
                    case 0b111: { _snprintf_s(out_Buffer, BufferSize, BufferSize,  "%s : [ BX ]", SegmentBuffer); }break;
                }
            }break;
            
            case 0b01:
            {
                
                switch(rm.Value)
                {
                    case 0b000: 
                    { 
                        char ImmBuffer[MAX_BUFFER_SIZE] = {0};
                        disp8.Value = GetBits_msb(State, disp8.bits_count);
                        PrintImmediateToBuffer(ImmBuffer, MAX_BUFFER_SIZE, EffAddressSize, disp8);
                        _snprintf_s(out_Buffer, BufferSize, BufferSize, "%s : [ BX + SI + %s ]", SegmentBuffer, ImmBuffer);
                    }break;
                    case 0b001: 
                    { 
                        char ImmBuffer[MAX_BUFFER_SIZE] = {0};
                        disp8.Value = GetBits_msb(State, disp8.bits_count);
                        PrintImmediateToBuffer(ImmBuffer, MAX_BUFFER_SIZE, EffAddressSize, disp8);
                        _snprintf_s(out_Buffer, BufferSize, BufferSize, "%s : [ BX + DI + %s ]", SegmentBuffer, ImmBuffer);
                    }break;
                    case 0b010: 
                    {
                        char ImmBuffer[MAX_BUFFER_SIZE] = {0};
                        disp8.Value = GetBits_msb(State, disp8.bits_count);
                        PrintImmediateToBuffer(ImmBuffer, MAX_BUFFER_SIZE, EffAddressSize, disp8);
                        _snprintf_s(out_Buffer, BufferSize, BufferSize, "%s : [ BP + SI + %s ]", SegmentBuffer, ImmBuffer); //NOTE(Alex): defaults to SS
                    }break;
                    case 0b011: 
                    { 
                        char ImmBuffer[MAX_BUFFER_SIZE] = {0};
                        disp8.Value = GetBits_msb(State, disp8.bits_count);
                        PrintImmediateToBuffer(ImmBuffer, MAX_BUFFER_SIZE, EffAddressSize, disp8);
                        _snprintf_s(out_Buffer, BufferSize, BufferSize, "%s : [ BP + DI + %s ]", SegmentBuffer, ImmBuffer); //NOTE(Alex): defaults to SS
                    }break;
                    case 0b100: 
                    {
                        char ImmBuffer[MAX_BUFFER_SIZE] = {0};
                        disp8.Value = GetBits_msb(State, disp8.bits_count);
                        PrintImmediateToBuffer(ImmBuffer, MAX_BUFFER_SIZE, EffAddressSize, disp8);
                        _snprintf_s(out_Buffer, BufferSize, BufferSize, "%s : [ SI + %s ]", SegmentBuffer, ImmBuffer);
                    }break;
                    case 0b101: 
                    {
                        char ImmBuffer[MAX_BUFFER_SIZE] = {0};
                        disp8.Value = GetBits_msb(State, disp8.bits_count);
                        PrintImmediateToBuffer(ImmBuffer, MAX_BUFFER_SIZE, EffAddressSize, disp8);
                        _snprintf_s(out_Buffer, BufferSize, BufferSize, "%s : [ DI + %s ]", SegmentBuffer, ImmBuffer);
                    }break;
                    case 0b110: 
                    { 
                        char ImmBuffer[MAX_BUFFER_SIZE] = {0};
                        disp8.Value = GetBits_msb(State, disp8.bits_count);
                        PrintImmediateToBuffer(ImmBuffer, MAX_BUFFER_SIZE, EffAddressSize, disp8);
                        _snprintf_s(out_Buffer, BufferSize, BufferSize, "%s : [ BP + %s ]", SegmentBuffer, ImmBuffer);
                    }break;
                    case 0b111: 
                    {
                        char ImmBuffer[MAX_BUFFER_SIZE] = {0};
                        disp8.Value = GetBits_msb(State, disp8.bits_count);
                        PrintImmediateToBuffer(ImmBuffer, MAX_BUFFER_SIZE, EffAddressSize, disp8);
                        _snprintf_s(out_Buffer, BufferSize, BufferSize, "%s : [ BX + %s ]", SegmentBuffer, ImmBuffer);
                    }break;
                }
            }break;
            
            case 0b10:
            {
                
                switch(rm.Value)
                {
                    case 0b000: 
                    { 
                        char ImmBuffer[MAX_BUFFER_SIZE] = {0};
                        disp16.Value = GetBits_msb(State, disp16.bits_count);
                        PrintImmediateToBuffer(ImmBuffer, MAX_BUFFER_SIZE, EffAddressSize, disp16);
                        _snprintf_s(out_Buffer, BufferSize, BufferSize, "%s : [ BX + SI + %s ]", SegmentBuffer, ImmBuffer);
                    }break;
                    case 0b001: 
                    { 
                        char ImmBuffer[MAX_BUFFER_SIZE] = {0};
                        disp16.Value = GetBits_msb(State, disp16.bits_count);
                        PrintImmediateToBuffer(ImmBuffer, MAX_BUFFER_SIZE, EffAddressSize, disp16);
                        _snprintf_s(out_Buffer, BufferSize, BufferSize, "%s : [ BX + DI + %s ]", SegmentBuffer, ImmBuffer);
                    }break;
                    case 0b010: 
                    {
                        char ImmBuffer[MAX_BUFFER_SIZE] = {0};
                        disp16.Value = GetBits_msb(State, disp16.bits_count);
                        PrintImmediateToBuffer(ImmBuffer, MAX_BUFFER_SIZE, EffAddressSize, disp16);
                        _snprintf_s(out_Buffer, BufferSize, BufferSize, "%s : [ BP + SI + %s ]", SegmentBuffer, ImmBuffer); //NOTE(Alex): defaults to SS
                    }break;
                    case 0b011: 
                    { 
                        char ImmBuffer[MAX_BUFFER_SIZE] = {0};
                        disp16.Value = GetBits_msb(State, disp16.bits_count);
                        PrintImmediateToBuffer(ImmBuffer, MAX_BUFFER_SIZE, EffAddressSize, disp16);
                        _snprintf_s(out_Buffer, BufferSize, BufferSize, "%s : [ BP + DI + %s ]", SegmentBuffer, ImmBuffer); //NOTE(Alex): defaults to SS
                    }break;
                    case 0b100: 
                    {
                        char ImmBuffer[MAX_BUFFER_SIZE] = {0};
                        disp16.Value = GetBits_msb(State, disp16.bits_count);
                        PrintImmediateToBuffer(ImmBuffer, MAX_BUFFER_SIZE, EffAddressSize, disp16);
                        _snprintf_s(out_Buffer, BufferSize, BufferSize, "%s : [ SI + %s ]", SegmentBuffer, ImmBuffer);
                    }break;
                    case 0b101: 
                    {
                        char ImmBuffer[MAX_BUFFER_SIZE] = {0};
                        disp16.Value = GetBits_msb(State, disp16.bits_count);
                        PrintImmediateToBuffer(ImmBuffer, MAX_BUFFER_SIZE, EffAddressSize, disp16);
                        _snprintf_s(out_Buffer, BufferSize, BufferSize, "%s : [ DI + %s ]", SegmentBuffer, ImmBuffer);
                    }break;
                    case 0b110: 
                    { 
                        char ImmBuffer[MAX_BUFFER_SIZE] = {0};
                        disp16.Value = GetBits_msb(State, disp16.bits_count);
                        PrintImmediateToBuffer(ImmBuffer, MAX_BUFFER_SIZE, EffAddressSize, disp16);
                        _snprintf_s(out_Buffer, BufferSize, BufferSize, "%s : [ BP + %s ]", SegmentBuffer, ImmBuffer);
                    }break;
                    case 0b111: 
                    {
                        char ImmBuffer[MAX_BUFFER_SIZE] = {0};
                        disp16.Value = GetBits_msb(State, disp16.bits_count);
                        PrintImmediateToBuffer(ImmBuffer, MAX_BUFFER_SIZE, EffAddressSize, disp16);
                        _snprintf_s(out_Buffer, BufferSize, BufferSize, "%s : [ BX + %s ]", SegmentBuffer, ImmBuffer);
                    }break;
                }
            }break;
            
            
            case 0b11: 
            { 
                GetReg(ProcessorMode, EffOperandSize, regBuffer, MAX_BUFFER_SIZE, rex, rm, false);
                _snprintf_s(out_Buffer, BufferSize, BufferSize,  "%s", regBuffer); 
            }break;
        }
    }    
}

#endif

internal u32 
cvt_eff_operand_size_to_num(eff_operand_size OperandSize)
{
	u32 Result = 0;
	
	switch(OperandSize)
	{
		
		case operandsize_Invalid:	
		{
			Result = 0;
		}break;
		
		case operandsize_8:
		{
			
			Result = 8;
		}break;
		
		case operandsize_16:
		{
			Result = 16;
			
		}break;
		
		case operandsize_32:
		{
			
			Result = 32;
		}break;
		
		case operandsize_64:
		{
			Result = 64;
			
		}break;
		
		case operandsize_128:
		{
			Result = 128;
			
		}break;
		case operandsize_256:
		{
			
			Result = 256;
		}break;
		
		case operandsize_512:
		{
			Result = 512;
			
		}break;
		
		case operandsize_48:
		{
			Result = 48;
			
		}break;
		case operandsize_80:
		{
			
			Result = 80;
		}break;
		
		case operandsize_MemoryRange:
		{
			//NOTE(Alex): We set it as zero when undefined memory range
			Result = 0;
		}break;		
	}
	
	return Result;
}

//NOTE(Alex): this function works on the asumption that the valid input operand sizes are 16 32 or 64 
//NOTE(Alex): sign extension is done by the processor when executing instruction! We dont need to sign extend it on assembly listing
internal void
get_eff_operand_size(disasm_state * State, processor_mode ProcessorMode, instruction_context * ctx, u32 Index, eff_operand_size * out_OperandSize, eff_address_size EffAddressSize)
{
    Assert(out_OperandSize);
	instruction_info_ * InstructionInfo = ctx->i_info;
	b32 op_size_pref = ctx->OperandSizeOverridePrefixPresent;
	
    eff_operand_size op_size = *out_OperandSize;
	
	Assert(op_size == operandsize_16 || op_size == operandsize_32 ||op_size == operandsize_64);
	
    operand_size op_type = InstructionInfo->OperandSizes[Index];
    switch(op_type)
    {
        
        case OperandSize_a:
        {
            //Two one-word operands in memory or two double-word operands in memory, depending on operand-size attribute (only BOUND).
			//NOTE(Alex): We dont do anything here!
        }break;
        
        case OperandSize_b:
        {
            //Byte, regardless of operand-size attribute.
            op_size = operandsize_8;
        }break;
        
        case OperandSize_bcd:
        {
            op_size = operandsize_80;
        }break;
        
        case OperandSize_bs:
        {
            //Byte, sign-extended to the size of the destination operand.
            op_size = operandsize_8;
        }break;
        
        
        case OperandSize_vqp:
        {
            //Word or doubleword, depending on operand-size attribute, or quadword, promoted by REX.W in 64-bit mode.
        }break;
        
        case OperandSize_bsq:
		{
			//(Byte, sign-extended to 64 bits.)
			op_size = operandsize_8;
		}break;
		
        case OperandSize_bss:
		{
			//Byte, sign-extended to the size of the stack pointer (for example, PUSH (6A)).
			op_size = operandsize_8;
		}break;
        case OperandSize_c:
		{
			//Byte or word, depending on operand-size attribute. (unused even by Intel?)
		}break;
        case OperandSize_d:
		{
			//Doubleword, regardless of operand-size attribute.
			op_size = operandsize_32;
		}break;
        case OperandSize_di:
		{
			//Doubleword-integer. Only x87 FPU instructions (for example, FIADD).
			op_size = operandsize_32;
		}break;
        case OperandSize_dq:
		{
			//Double-quadword, regardless of operand-size attribute (for example, CMPXCHG16B).
			op_size = operandsize_128;
		}break;
		
        case OperandSize_dqp:
		{
			//Doubleword, or quadword, promoted by REX.W in 64-bit mode (for example, MOVSXD).
			if(op_size != operandsize_64 && op_size != operandsize_32)
			{
				op_size = operandsize_32;
			}
			
		}break;
        case OperandSize_dr:
		{
			//Double-real. Only x87 FPU instructions (for example, FADD).
			op_size = operandsize_64;
		}break;
        case OperandSize_ds:
		{
			//Doubleword, sign-extended to 64 bits (for example, CALL (E8).
			op_size = operandsize_32;
			
		}break;
        case OperandSize_e:
		{
			//x87 FPU environment (for example, FSTENV).
			op_size = operandsize_Invalid;
		}break;
        case OperandSize_er:
		{
			//Extended-real. Only x87 FPU instructions (for example, FLD).
			op_size = operandsize_80;
		}break;
        case OperandSize_p:
		{
			//32-bit or 48-bit pointer, depending on operand-size attribute (for example, CALLF (9A).
			if(op_size == operandsize_16)
			{
				op_size = operandsize_32;
			}
			else if(op_size == operandsize_32)
			{
				op_size = operandsize_48;
			}
			
		}break;
        case OperandSize_pi:
		{
			//Quadword MMX technology data.
			op_size = operandsize_64;
		}break;
        case OperandSize_pd:
		{
			//128-bit packed double-precision floating-point data.
			op_size = operandsize_128;
		}break;
        case OperandSize_ps:
		{
			//128-bit packed single-precision floating-point data.
			op_size = operandsize_128;
		}break;
        case OperandSize_psq:
		{
			//64-bit packed single-precision floating-point data.
			op_size = operandsize_64;
		}break;
        case OperandSize_pt:
		{
			//(80-bit far pointer.)
			op_size = operandsize_80;
		}break;
        case OperandSize_ptp:
		{
			//32-bit or 48-bit pointer, depending on operand-size attribute, or 80-bit far pointer, promoted by REX.W in 64-bit mode (for example, CALLF (FF /3)).
			if(op_size == operandsize_16)
			{
				op_size = operandsize_32;
			}
			else if(op_size == operandsize_32)
			{
				op_size = operandsize_48;
			}
			else if(op_size == operandsize_64)
			{
				op_size = operandsize_80;
			}
			
		}break;
        case OperandSize_q:
		{
			//Quadword, regardless of operand-size attribute (for example, CALL (FF /2)).
			op_size = operandsize_64;
		}break;
        case OperandSize_qi:
		{
			//Qword-integer. Only x87 FPU instructions (for example, FILD).
			op_size = operandsize_64;
		}break;
        case OperandSize_qp:
		{
			//Quadword, promoted by REX.W (for example, IRETQ).
			//op_size = operandsize_64;
		}break;
        case OperandSize_s:
		{
			//6-byte pseudo-descriptor, or 10-byte pseudo-descriptor in 64-bit mode (for example, SGDT).
			if(ProcessorMode == ProcessorMode_64bit)
			{
				op_size = operandsize_80;
			}
			else
			{
				op_size = operandsize_48;
			}
			
			
		}break;
        case OperandSize_sd:
		{
			//NOTE(Alex): Do we want here to set op_size to double-precision?
			//Scalar element of a 128-bit packed double-precision floating data.
			op_size = operandsize_128;
		}break;
        case OperandSize_si:
		{
			//Doubleword integer register (e. g., eax). (unused even by Intel?)
		}break;
		
        case OperandSize_sr:
		{
			//Single-real. Only x87 FPU instructions (for example, FADD).
			op_size = operandsize_32;
		}break;
        case OperandSize_ss:
		{
			//NOTE(Alex): Do we want here to set op_size to single-precision?
			//Scalar element of a 128-bit packed single-precision floating data.
			op_size = operandsize_128;
		}break;
        case OperandSize_st:
		{
			//x87 FPU state (for example, FSAVE).
			op_size = operandsize_Invalid;
		}break;
        case OperandSize_stx:
		{
			//x87 FPU and SIMD state (FXSAVE and FXRSTOR).
			op_size = operandsize_Invalid;
		}break;
        case OperandSize_t:
		{
			//10-byte far pointer.
			op_size = operandsize_80;
			
		}break;
        case OperandSize_v:
		{
			//Word or doubleword, depending on operand-size attribute (for example, INC (40), PUSH (50)).
			if(op_size == operandsize_64)
			{
				op_size = operandsize_32;
			}
			
		}break;
		
        case OperandSize_vds:
		{
			//Word or doubleword, depending on operand-size attribute, or doubleword, sign-extended to 64 bits for 64-bit operand size.
			if(op_size == operandsize_64)
			{
				op_size = operandsize_32;
			}
			
		}break;
		
		
        case OperandSize_vq:
		{
			//Quadword (default) or word if operand-size prefix is used (for example, PUSH (50)).
			if(op_size_pref)
			{
				op_size = operandsize_16;
			}
			else
			{
				op_size = operandsize_64;
			}
			
			
		}break;
        case OperandSize_vs:
		{
			//Word or doubleword sign extended to the size of the stack pointer (for example, PUSH (68)).
			if(op_size == operandsize_64)
			{
				op_size = operandsize_32;
			}
			
		}break;
        case OperandSize_w:
		{
			//Word, regardless of operand-size attribute (for example, ENTER).
			op_size = operandsize_16;
		}break;
        
		case OperandSize_wi:
		{
			//Word-integer. Only x87 FPU instructions (for example, FIADD).
			op_size = operandsize_16;
		}break;
		
		
		//NOTE(Alex): the following abbreviations are issued to indicate a dependency on address-size attribute instead of operand-size attribute. 
		
        case OperandSize_va:
		{
			//Word or doubleword, according to address-size attribute (only REP and LOOP families).
			//NOTE(AleX): Not used by disassmebler
			if(EffAddressSize == addresssize_32)
			{
				op_size = operandsize_32;
			}
			else if(EffAddressSize == addresssize_16)
			{
				op_size = operandsize_16;
			}
			else if(EffAddressSize == addresssize_64)
			{
				op_size = operandsize_32;
			}
			
		}break;
        case OperandSize_dqa:
		{
			//Doubleword or quadword, according to address-size attribute (only REP and LOOP families).
			//NOTE(AleX): Not used by disassmebler
			
			if(EffAddressSize == addresssize_32)
			{
				op_size = operandsize_32;
			}
			else if(EffAddressSize == addresssize_16)
			{
				op_size = operandsize_32;
			}
			else if(EffAddressSize == addresssize_64)
			{
				op_size = operandsize_64;
			}
			
		}break;
		
		
        case OperandSize_wa:
		{
			//Word, according to address-size attribute (only JCXZ instruction).
			//NOTE(AleX): Not used by disassmebler
		}break;
        
		case OperandSize_wo:
		{
			//Word, according to current operand size (e. g., MOVSW instruction).
			//NOTE(AleX): Not used by disassmebler
		}break;
        case OperandSize_ws:
		{
			//Word, according to current stack size (only PUSHF and POPF instructions in 64-bit mode).
			
			//NOTE(AleX): Not used by disassmebler
			
		}break;
        case OperandSize_da:
		{
			//Doubleword, according to address-size attribute (only JECXZ instruction).
			//NOTE(AleX): Not used by disassmebler
		}break;
        case OperandSize_do:
		{
			//Doubleword, according to current operand size (e. g., MOVSD instruction).
			//NOTE(AleX): Not used by disassmebler
			
		};
        case OperandSize_qa:
		{
			//Quadword, according to address-size attribute (only JRCXZ instruction).
			//NOTE(AleX): Not used by disassmebler
		}break;
        case OperandSize_qs:
		{
			//Quadword, according to current stack size (only PUSHFQ and POPFQ instructions).
			//NOTE(AleX): Not used by disassmebler
		}break;
        
        case OperandSize_f:
		{
			//(only PUSHF and POPF instructions in 64-bit mode).
			if(ProcessorMode == ProcessorMode_64bit)
			{
				op_size = operandsize_64;
			}
			
			if(op_size_pref)
			{
				op_size = operandsize_16;
			}
			
		}break;
        case OperandSize_cxz:
        {
			//(only JCXZ instruction).
            if(EffAddressSize == addresssize_64)
			{
				op_size =operandsize_64;
			}
			else if(EffAddressSize == addresssize_32)
			{
				op_size = operandsize_32;
			}
			else if (EffAddressSize == addresssize_16)
			{
				op_size = operandsize_16;
			}
			
        }break;
        
        
		default:
		{
			//NOTE(Alex): We set it to an invalid state so that we tell that the instruction doesnt define one
			op_size = operandsize_Invalid;
		}break;
    }
    
	*out_OperandSize = op_size;
}


internal void
InitGrammarTokenizer(tokenizer * out_Tokenizer, char * Buffer, u32 BufferCount)
{
    
}

internal token_type
GetNextGrammarToken(tokenizer * Tokenizer, char ** out_Ptr, u32 * out_Count)
{
    
}

internal void
init_instruction_context(instruction_context * ctx, instruction_info_ * InstructionInfoPtr, bits_array_ * BitsArrayPtr)
{
	ctx->rex = Zeroes(8);
	ctx->Group1Prefix = group1_Invalid;
	ctx->Group2Prefix = group2_Invalid;
	
	ctx->OperandSizeOverridePrefixPresent = false;
	ctx->AddressSizeOverridePrefixPresent = false;
	
	ctx->i_info = InstructionInfoPtr;
	ctx->BitsArrayPtr = BitsArrayPtr;
	ctx->InstructionFound = false;
}


//TODO(Alex): We don´t want to include this here! Erase it.

//#define DEFAULTSF64 true
//#define NOT_SUPPORTED true
//#define INVALID_64 true
//#define REPNE_VALID true

#define REP_VALID true
#define LOCK_VALID true
#define BRANCHHINT_VALID true

#include "eflyfile_generator.h"
#include "eflyfile_generator.cpp"

#include "eflyfile_instruction_infos_16_generated.cpp"
#include "eflyfile_instruction_infos_32_generated.cpp"
#include "eflyfile_instruction_infos_64_generated.cpp"

#include "eflyfile_opcode_ids_16_generated.cpp"
#include "eflyfile_opcode_ids_32_generated.cpp"
#include "eflyfile_opcode_ids_64_generated.cpp"



int main(int ArgumentCount , char ** Arguments )
{
    
    //TODO(Alex): Remove this, this should go into the platform layer
    HANDLE STDOutHandle = GetStdHandle(STD_OUTPUT_HANDLE); 
    win32_WriteFile(STDOutHandle, Arguments[1], StringLength(Arguments[1]));
    
    char EndOfFileString[MAX_BUFFER_SIZE] = {"\n"};
    u32 EndOfFileStringLength = StringLength(EndOfFileString);
    
    char SpaceString[MAX_BUFFER_SIZE] = {" "};
    u32 SpaceStringLength = StringLength(SpaceString);
    
	char CommaString[MAX_BUFFER_SIZE] = {","};
	u32 CommaStringLength = StringLength(CommaString);
	
	char SemiColonString[MAX_BUFFER_SIZE] = {";"};
	u32 SemiColonStrigLength = StringLength(SemiColonString);    
	
    win32_WriteFile(STDOutHandle, EndOfFileString, EndOfFileStringLength);
    
    char * ModeString = Arguments[1];
    u32 ModeStringLength = StringLength(ModeString);
    
    processor_mode u_pro_mode = ProcessorMode_Invalid;
    
    regexp_support InputSupport = {};
    char * At_ = 0;
    if(InitRegExpSource(&InputSupport, ModeString, ModeStringLength, &At_))
    {
        if(StringIsEqualRegExp(&InputSupport, At_, "-64", StringLength("-64")))
        {
            u_pro_mode = ProcessorMode_64bit;
            AdvanceSourcePtr(&InputSupport, &At_);
        }
        else if(StringIsEqualRegExp(&InputSupport, At_, "-32", StringLength("-32")))
        {
            u_pro_mode = ProcessorMode_32bit;
            AdvanceSourcePtr(&InputSupport, &At_);
        }
        else if(StringIsEqualRegExp(&InputSupport, At_, "-16", StringLength("-16")))
        {
            u_pro_mode = ProcessorMode_16bit;
            AdvanceSourcePtr(&InputSupport, &At_);
        }
        
    }
    
    Assert(u_pro_mode > ProcessorMode_Invalid);
    
    char * FileName = Arguments[2];
    debug_file_content PEContent = Debug_Win32ReadEntireFile(FileName);
    
    eflype_manager PEManager = {};
    if(eflype_InitParser(&PEManager, &PEContent))
    {
        eflype_section_header * TextHeader = GetSectionHeader(&PEManager, SectionID_text); 
        eflype_section_header * DataHeader = GetSectionHeader(&PEManager, SectionID_data); 
        char * DataPtr = (char*)GetFilePtrFromImageBase(&PEManager, DataHeader->PointerToRawData); 
        
        //TODO(Alex): Handle inappropriate encodings (invalid mode, not encodable, etc.)
		//NOTE(Alex): This will serve as my encodings file for now!
        
        memory_index tables_mem_size = Megabytes(40);
        void * tables_memory = VirtualAlloc(0, tables_mem_size, MEM_RESERVE|MEM_COMMIT, PAGE_READWRITE); 
        //memory_index MaxBitsArrayFiles = tables_mem_size / (memory_index)sizeof();
        
        file_manager FileManager = {};
        InitFileManager(&FileManager, tables_memory, tables_mem_size);
        
#ifdef EFLYFILE_TABLES_GENERATED
        
        CreateOpcodeIDS_16(&FileManager);
        CreateOpcodeIDS_32(&FileManager);
        CreateOpcodeIDS_64(&FileManager);
        
		CreateInstructionInfos_16(&FileManager);
		CreateInstructionInfos_32(&FileManager);
		CreateInstructionInfos_64(&FileManager);
        
#else
        
        //NOTE(Alex): Opcode Ids
        
        const eflyfile_bits mod = ZeroesFile(2, BitfieldType_mod);
        const eflyfile_bits reg = ZeroesFile(3, BitfieldType_reg);
        const eflyfile_bits rm = ZeroesFile(3, BitfieldType_rm);
        const eflyfile_bits tttn = ZeroesFile(4, BitfieldType_tttn);
        const eflyfile_bits eee = ZeroesFile(3, BitfieldType_eee);
        const eflyfile_bits sreg2 = ZeroesFile(2, BitfieldType_sreg2);
        const eflyfile_bits sreg3 = ZeroesFile(2, BitfieldType_sreg3);
        const eflyfile_bits s = ZeroesFile(1, BitfieldType_s);
        //const eflyfile_bits w = ZeroesFile(1, BitfieldType_w);
        
        BeginFileSection(&FileManager, FileSection_bits);
        
        // Jcc – Jump if Condition is Met - 8-bit displacement
        
        BeginInstructionBits(&FileManager);
        CopyBitsToFile(&FileManager, BitsIDFile(8, 0B01110000));
        EndInstructionBits(&FileManager);
        
        // JCXZ/JECXZ – Jump on CX/ECX Zero - Address-size prefix differentiates JCXZ and JECXZ
        
        BeginInstructionBits(&FileManager);
        CopyBitsToFile(&FileManager, BitsIDFile(8, 0B11100011));
        EndInstructionBits(&FileManager);
        
        
        // MOV – Move Data - MOV <AL> , <Ob>
        
        BeginInstructionBits(&FileManager);
        CopyBitsToFile(&FileManager, BitsIDFile(8, 0b10100000));
        EndInstructionBits(&FileManager);
        
        //MOV - Move Data - MOV <rAX> , <Ovqp>
        
        BeginInstructionBits(&FileManager);
        CopyBitsToFile(&FileManager, BitsIDFile(8, 0b10100001));
        EndInstructionBits(&FileManager);
        
        //MOV - Move Data - MOV <Ob> , <AL>
        
        BeginInstructionBits(&FileManager);
        CopyBitsToFile(&FileManager, BitsIDFile(8, 0b10100010));
        EndInstructionBits(&FileManager);
        
        
        //MOV - Move Data - MOV <Ovqp> , <rAX>
        
        BeginInstructionBits(&FileManager);
        CopyBitsToFile(&FileManager, BitsIDFile(8, 0b10100011));
        EndInstructionBits(&FileManager);
        
        // MOV – Move Data - "MOV <Ev>, <Gv>";
        
        BeginInstructionBits(&FileManager);
        CopyBitsToFile(&FileManager, BitsIDFile(8, 0b10001001));
        CopyBitsToFile(&FileManager, mod);
        CopyBitsToFile(&FileManager, reg);
        CopyBitsToFile(&FileManager, rm);
        EndInstructionBits(&FileManager);
        
        
#if 0        
        // Jcc – Jump if Condition is Met - 8-bit displacement
        BeginInstructionBits(&FileManager);
        CopyBitsToFile(&FileManager, BitsIDFile(4, 0B0111));
        CopyBitsToFile(&FileManager, tttn);
        EndInstructionBits(&FileManager);
        
        // Jcc – Jump if Condition is Met - full displacement
        
        BeginInstructionBits(&FileManager);
        CopyBitsToFile(&FileManager, BitsIDFile(12, 0B000011111000));
        CopyBitsToFile(&FileManager, tttn);
        EndInstructionBits(&FileManager);
        
        // JCXZ/JECXZ – Jump on CX/ECX Zero - Address-size prefix differentiates JCXZ and JECXZ
        
        BeginInstructionBits(&FileManager);
        CopyBitsToFile(&FileManager, BitsIDFile(8, 0B11100011));
        EndInstructionBits(&FileManager);
        
        // JMP – Unconditional Jump (to same segment) - short
        
        BeginInstructionBits(&FileManager);
        CopyBitsToFile(&FileManager, BitsIDFile(8, 0B11101011));
        EndInstructionBits(&FileManager);
        
        // JMP – Unconditional Jump (to same segment) - direct
        
        BeginInstructionBits(&FileManager);
        CopyBitsToFile(&FileManager, BitsIDFile(8, 0b11101001));
        EndInstructionBits(&FileManager);
        
        // JMP – Unconditional Jump (to same segment) - indirect
        
        BeginInstructionBits(&FileManager);
        CopyBitsToFile(&FileManager, BitsIDFile(8, 0b11111111));
        CopyBitsToFile(&FileManager, mod);
        CopyBitsToFile(&FileManager, BitsIDFile(3, 0b100));
        CopyBitsToFile(&FileManager, rm);
        EndInstructionBits(&FileManager);
        
        // JMP – Unconditional Jump (to other segment) - indirect intersegment
        
        BeginInstructionBits(&FileManager);
        CopyBitsToFile(&FileManager, BitsIDFile(8, 0b11111111));
        CopyBitsToFile(&FileManager, mod);
        CopyBitsToFile(&FileManager, BitsIDFile(3, 0b101));
        CopyBitsToFile(&FileManager, rm);
        EndInstructionBits(&FileManager);
        
        // JMP – Unconditional Jump (to other segment) - direct intersegment
        
        BeginInstructionBits(&FileManager);
        CopyBitsToFile(&FileManager, BitsIDFile(8, 0b11101010));
        EndInstructionBits(&FileManager);
        
        // DEC - Decrement by 1 - register Eb
        
        BeginInstructionBits(&FileManager);
        CopyBitsToFile(&FileManager, BitsIDFile(8, 0b11111110));
        CopyBitsToFile(&FileManager, mod);
        CopyBitsToFile(&FileManager, BitsIDFile(3, 0b001));
        CopyBitsToFile(&FileManager, rm);
        EndInstructionBits(&FileManager);
        
        // DEC - Decrement by 1 - register Ev
        
        BeginInstructionBits(&FileManager);
        CopyBitsToFile(&FileManager, BitsIDFile(8, 0b11111111));
        CopyBitsToFile(&FileManager, mod);
        CopyBitsToFile(&FileManager, BitsIDFile(3, 0b001));
        CopyBitsToFile(&FileManager, rm);
        EndInstructionBits(&FileManager);
        
        // DEC – Decrement by 1 - DEC <GPR_32>
        
        BeginInstructionBits(&FileManager);
        CopyBitsToFile(&FileManager, BitsIDFile(5, 0b01001));
        CopyBitsToFile(&FileManager, reg);
        EndInstructionBits(&FileManager);
        
        // MOV – Move Data - "MOV <Ev>, <Gv>";
        
        BeginInstructionBits(&FileManager);
        CopyBitsToFile(&FileManager, BitsIDFile(8, 0b10001001));
        CopyBitsToFile(&FileManager, mod);
        CopyBitsToFile(&FileManager, reg);
        CopyBitsToFile(&FileManager, rm);
        EndInstructionBits(&FileManager);
        
        // MOV – Move Data - "MOV <Eb>, <Gb>";
        
        BeginInstructionBits(&FileManager);
        CopyBitsToFile(&FileManager, BitsIDFile(8, 0b10001000));
        CopyBitsToFile(&FileManager, mod);
        CopyBitsToFile(&FileManager, reg);
        CopyBitsToFile(&FileManager, rm);
        EndInstructionBits(&FileManager);
        
        // MOV – Move Data - "MOV <Gb>, <Eb>";
        
        BeginInstructionBits(&FileManager);
        CopyBitsToFile(&FileManager, BitsIDFile(8, 0b10001010));
        CopyBitsToFile(&FileManager, mod);
        CopyBitsToFile(&FileManager, reg);
        CopyBitsToFile(&FileManager, rm);
        EndInstructionBits(&FileManager);
        
        // MOV – Move Data - "MOV <Gv>, <Ev>";
        
        BeginInstructionBits(&FileManager);
        CopyBitsToFile(&FileManager, BitsIDFile(8, 0b10001011));
        CopyBitsToFile(&FileManager, mod);
        CopyBitsToFile(&FileManager, reg);
        CopyBitsToFile(&FileManager, rm);
        EndInstructionBits(&FileManager);
        
        // MOV – Move Data - MOV Eb,Ib
        
        BeginInstructionBits(&FileManager);
        CopyBitsToFile(&FileManager, BitsIDFile(8, 0b11000110));
        CopyBitsToFile(&FileManager, mod);
        CopyBitsToFile(&FileManager, BitsIDFile(3, 0b000));
        CopyBitsToFile(&FileManager, rm);
        EndInstructionBits(&FileManager);
        
        // MOV – Move Data - MOV Ev,Iz
        
        BeginInstructionBits(&FileManager);
        CopyBitsToFile(&FileManager, BitsIDFile(8, 0b11000111));
        CopyBitsToFile(&FileManager, mod);
        CopyBitsToFile(&FileManager, BitsIDFile(3, 0b000));
        CopyBitsToFile(&FileManager, rm);
        EndInstructionBits(&FileManager);
        
        // MOV – Move Data - MOV <GPR_8>, <Ib>
        
        BeginInstructionBits(&FileManager);
        CopyBitsToFile(&FileManager, BitsIDFile(5, 0b10110));
        CopyBitsToFile(&FileManager, reg);
        EndInstructionBits(&FileManager);
        
        // MOV – Move Data - MOV <GPR_64>, <Iv>
        
        BeginInstructionBits(&FileManager);
        CopyBitsToFile(&FileManager, BitsIDFile(5, 0b10111));
        CopyBitsToFile(&FileManager, reg);
        EndInstructionBits(&FileManager);
        
        // MOV – Move Data - MOV <rAX_08>, <Ov>
        
        BeginInstructionBits(&FileManager);
        CopyBitsToFile(&FileManager, BitsIDFile(8, 0b10100000));
        EndInstructionBits(&FileManager);
        
        // MOV – Move Data - MOV <rAX_64>, <Ov>
        
        BeginInstructionBits(&FileManager);
        CopyBitsToFile(&FileManager, BitsIDFile(8, 0b10100001));
        EndInstructionBits(&FileManager);
        
        // MOV – Move Data - MOV <Ov>, <rAX_08>
        
        BeginInstructionBits(&FileManager);
        CopyBitsToFile(&FileManager, BitsIDFile(8, 0b10100010));
        EndInstructionBits(&FileManager);
        
        // MOV – Move Data - MOV <Ov>, <rAX_64>
        
        BeginInstructionBits(&FileManager);
        CopyBitsToFile(&FileManager, BitsIDFile(8, 0b10100011));
        EndInstructionBits(&FileManager);
        
        // IMUL – Signed Multiply - AL, AX, or EAX with register - IMUL Eb
        
        BeginInstructionBits(&FileManager);
        CopyBitsToFile(&FileManager, BitsIDFile(8, 0b11110110));
        CopyBitsToFile(&FileManager, mod);
        CopyBitsToFile(&FileManager, BitsIDFile(3, 0b101));
        CopyBitsToFile(&FileManager, rm);
        EndInstructionBits(&FileManager);
        
        // IMUL – Signed Multiply - AL, AX, or EAX with register - IMUL Ev
        
        BeginInstructionBits(&FileManager);
        CopyBitsToFile(&FileManager, BitsIDFile(8, 0b11110111));
        CopyBitsToFile(&FileManager, mod);
        CopyBitsToFile(&FileManager, BitsIDFile(3, 0b101));
        CopyBitsToFile(&FileManager, rm);
        EndInstructionBits(&FileManager);
        
        // IMUL – Signed Multiply - IMUL Gv,Ev
        
        BeginInstructionBits(&FileManager);
        CopyBitsToFile(&FileManager, BitsIDFile(16, 0b0000111110101111));
        CopyBitsToFile(&FileManager, mod);
        CopyBitsToFile(&FileManager, reg);
        CopyBitsToFile(&FileManager, rm);
        EndInstructionBits(&FileManager);
        
        // IMUL – Signed Multiply - IMUL Gv,Ev,Ib
        
        BeginInstructionBits(&FileManager);
        CopyBitsToFile(&FileManager, BitsIDFile(8, 0b01101011));
        CopyBitsToFile(&FileManager, mod);
        CopyBitsToFile(&FileManager, reg);
        CopyBitsToFile(&FileManager, rm);
        EndInstructionBits(&FileManager);
        
        // IMUL – Signed Multiply - IMUL Gv,Ev,Iz
        
        BeginInstructionBits(&FileManager);
        CopyBitsToFile(&FileManager, BitsIDFile(8, 0b01101001));
        CopyBitsToFile(&FileManager, mod);
        CopyBitsToFile(&FileManager, reg);
        CopyBitsToFile(&FileManager, rm);
        EndInstructionBits(&FileManager);
        
        //INS – Input String - INS Yb,DX
        
        BeginInstructionBits(&FileManager);
        CopyBitsToFile(&FileManager, BitsIDFile(8, 0b01101100));
        EndInstructionBits(&FileManager);
        
        //INS – Input String - INS Yz,DX
        
        BeginInstructionBits(&FileManager);
        CopyBitsToFile(&FileManager, BitsIDFile(8, 0b01101101));
        EndInstructionBits(&FileManager);
        
        // LODS - Load String - LODS AL,Xb
        
        BeginInstructionBits(&FileManager);
        CopyBitsToFile(&FileManager, BitsIDFile(8, 0b10101100));
        EndInstructionBits(&FileManager);
        
        // LODS - Load String - LODS rAX,Xv
        
        BeginInstructionBits(&FileManager);
        CopyBitsToFile(&FileManager, BitsIDFile(8, 0b10101101));
        EndInstructionBits(&FileManager);
        
        // MOVS – Move String - MOVS Yb,Xb
        
        BeginInstructionBits(&FileManager);
        CopyBitsToFile(&FileManager, BitsIDFile(8, 0b10100100));
        EndInstructionBits(&FileManager);
        
        // MOVS – Move String - MOVS Yv,Xv
        
        BeginInstructionBits(&FileManager);
        CopyBitsToFile(&FileManager, BitsIDFile(8, 0b10100101));
        EndInstructionBits(&FileManager);
        
        // OUTS – Output String - OUTS DX,Xb
        
        BeginInstructionBits(&FileManager);
        CopyBitsToFile(&FileManager, BitsIDFile(8, 0b01101110));
        EndInstructionBits(&FileManager);
        
        // OUTS – Output String - OUTS DX,Xz
        
        BeginInstructionBits(&FileManager);
        CopyBitsToFile(&FileManager, BitsIDFile(8, 0b01101111));
        EndInstructionBits(&FileManager);
        
        // STOS – Store String - STOS <Yb>, <AL>
        
        BeginInstructionBits(&FileManager);
        CopyBitsToFile(&FileManager, BitsIDFile(8, 0b10101010));
        EndInstructionBits(&FileManager);
        
        // STOS – Store String - STOS <Yv>, <rAX>
        
        BeginInstructionBits(&FileManager);
        CopyBitsToFile(&FileManager, BitsIDFile(8, 0b10101011));
        EndInstructionBits(&FileManager);
        
        // CMPS – Compare String - CMPS Yb,Xb
        
        BeginInstructionBits(&FileManager);
        CopyBitsToFile(&FileManager, BitsIDFile(8, 0b10100110));
        EndInstructionBits(&FileManager);
        
        // CMPS – Compare String - CMPS Yv,Xv
        
        BeginInstructionBits(&FileManager);
        CopyBitsToFile(&FileManager, BitsIDFile(8, 0b10100111));
        EndInstructionBits(&FileManager);
        
        //NOTE(Alex): Typo on specification - ... EFLAGS recording the results ...
        //SCAS – Scan String - SCAS Yb,AL
        
        BeginInstructionBits(&FileManager);
        CopyBitsToFile(&FileManager, BitsIDFile(8, 0b10101110));
        EndInstructionBits(&FileManager);
        
        //SCAS – Scan String - SCAS Yv,rAX
        
        BeginInstructionBits(&FileManager);
        CopyBitsToFile(&FileManager, BitsIDFile(8, 0b10101111));
        EndInstructionBits(&FileManager);
        
        // BTR – Bit Test and Reset - BTR Ev,Ib
        
        BeginInstructionBits(&FileManager);
        CopyBitsToFile(&FileManager, BitsIDFile(16, 0b0000111110111010));
        CopyBitsToFile(&FileManager, mod);
        CopyBitsToFile(&FileManager, BitsIDFile(3, 0b110));
        CopyBitsToFile(&FileManager, rm);
        EndInstructionBits(&FileManager);
        
        // BTR - Bit Test and Reset - BTR Ev,Gv
        
        BeginInstructionBits(&FileManager);
        CopyBitsToFile(&FileManager, BitsIDFile(16, 0b0000111110110011));
        CopyBitsToFile(&FileManager, mod);
        CopyBitsToFile(&FileManager, reg);
        CopyBitsToFile(&FileManager, rm);
        EndInstructionBits(&FileManager);
        
        // BT – Bit Test - BT Ev,Ib
        
        BeginInstructionBits(&FileManager);
        CopyBitsToFile(&FileManager, BitsIDFile(16, 0b0000111110111010));
        CopyBitsToFile(&FileManager, mod);
        CopyBitsToFile(&FileManager, BitsIDFile(3, 0b100));
        CopyBitsToFile(&FileManager, rm);
        EndInstructionBits(&FileManager);
        
        // BT - Bit Test - BT Ev,Gv
        
        BeginInstructionBits(&FileManager);
        CopyBitsToFile(&FileManager, BitsIDFile(16, 0b0000111110100011));
        CopyBitsToFile(&FileManager, mod);
        CopyBitsToFile(&FileManager, reg);
        CopyBitsToFile(&FileManager, rm);
        EndInstructionBits(&FileManager);
        
        // BTS – Bit Test and Set - BTS Ev,Ib
        
        BeginInstructionBits(&FileManager);
        CopyBitsToFile(&FileManager, BitsIDFile(16, 0b0000111110111010));
        CopyBitsToFile(&FileManager, mod);
        CopyBitsToFile(&FileManager, BitsIDFile(3, 0b101));
        CopyBitsToFile(&FileManager, rm);
        EndInstructionBits(&FileManager);
        
        // BTS - Bit Test and Set - BTS Ev,Gv
        
        BeginInstructionBits(&FileManager);
        CopyBitsToFile(&FileManager, BitsIDFile(16, 0b0000111110101011));
        CopyBitsToFile(&FileManager, mod);
        CopyBitsToFile(&FileManager, reg);
        CopyBitsToFile(&FileManager, rm);
        EndInstructionBits(&FileManager);
        
        // BTC – Bit Test and Complement - BTC Ev,Ib
        
        BeginInstructionBits(&FileManager);
        CopyBitsToFile(&FileManager, BitsIDFile(16, 0b0000111110111010));
        CopyBitsToFile(&FileManager, mod);
        CopyBitsToFile(&FileManager, BitsIDFile(3, 0b111));
        CopyBitsToFile(&FileManager, rm);
        EndInstructionBits(&FileManager);
        
        // BTC - Bit Test and Complement - BTC Ev,Gv
        
        BeginInstructionBits(&FileManager);
        CopyBitsToFile(&FileManager, BitsIDFile(16, 0b0000111110111011));
        CopyBitsToFile(&FileManager, mod);
        CopyBitsToFile(&FileManager, reg);
        CopyBitsToFile(&FileManager, rm);
        EndInstructionBits(&FileManager);
        
        // INC – Increment by 1 - INC Eb
        
        BeginInstructionBits(&FileManager);
        CopyBitsToFile(&FileManager, BitsIDFile(8, 0b11111110));
        CopyBitsToFile(&FileManager, mod);
        CopyBitsToFile(&FileManager, BitsIDFile(3, 0b000));
        CopyBitsToFile(&FileManager, rm);
        EndInstructionBits(&FileManager);
        
        // INC – Increment by 1 - INC Ev
        
        BeginInstructionBits(&FileManager);
        CopyBitsToFile(&FileManager, BitsIDFile(8, 0b11111111));
        CopyBitsToFile(&FileManager, mod);
        CopyBitsToFile(&FileManager, BitsIDFile(3, 0b000));
        CopyBitsToFile(&FileManager, rm);
        EndInstructionBits(&FileManager);
        
        // INC - Increment by 1 - INC <GPR_32>
        
        BeginInstructionBits(&FileManager);
        CopyBitsToFile(&FileManager, BitsIDFile(5, 0b01000));
        CopyBitsToFile(&FileManager, reg);
        EndInstructionBits(&FileManager);
        
        // ADD – Add - ADD Eb,Gb
        
        BeginInstructionBits(&FileManager);
        CopyBitsToFile(&FileManager, BitsIDFile(8, 0b00000000));
        CopyBitsToFile(&FileManager, mod);
        CopyBitsToFile(&FileManager, reg);
        CopyBitsToFile(&FileManager, rm);
        EndInstructionBits(&FileManager);
        
        // ADD – Add - ADD Ev,Gv
        
        BeginInstructionBits(&FileManager);
        CopyBitsToFile(&FileManager, BitsIDFile(8, 0b00000001));
        CopyBitsToFile(&FileManager, mod);
        CopyBitsToFile(&FileManager, reg);
        CopyBitsToFile(&FileManager, rm);
        EndInstructionBits(&FileManager);
        
        
        // ADD – Add - ADD Gb,Eb
        
        BeginInstructionBits(&FileManager);
        CopyBitsToFile(&FileManager, BitsIDFile(8, 0b00000010));
        CopyBitsToFile(&FileManager, mod);
        CopyBitsToFile(&FileManager, reg);
        CopyBitsToFile(&FileManager, rm);
        EndInstructionBits(&FileManager);
        
        // ADD – Add - ADD Gv,Ev
        
        BeginInstructionBits(&FileManager);
        CopyBitsToFile(&FileManager, BitsIDFile(8, 0b00000011));
        CopyBitsToFile(&FileManager, mod);
        CopyBitsToFile(&FileManager, reg);
        CopyBitsToFile(&FileManager, rm);
        EndInstructionBits(&FileManager);
        
        // ADD – Add - ADD Eb,Ib
        
        BeginInstructionBits(&FileManager);
        CopyBitsToFile(&FileManager, BitsIDFile(8, 0b10000000));
        CopyBitsToFile(&FileManager, mod);
        CopyBitsToFile(&FileManager, BitsIDFile(3, 0b000));
        CopyBitsToFile(&FileManager, rm);
        EndInstructionBits(&FileManager);
        
#endif
        
#if 0   
        //TODO(Alex): Missing this Add immediate instructions
        0b10000001
            0b10000010
            0b10000011
        
            0b100000sw
            mod 
            000 
            r/m 
#endif
        
        
        
            EndFileSection(&FileManager);
        
        
        //NOTE(Alex): Instruction Infos & Instruction Infos entries section
        
        operand_array OperandArray = {};
        
        BeginFileSection(&FileManager, FileSection_instruction_info);
        
        
        // Jcc – Jump if Condition is Met - 8-bit displacement
        
        InitOperandArray(&OperandArray);
        PushOperand(&OperandArray, OperandType_J, OperandSize_bs);
        PushInstructionInfo(&FileManager, "JO", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, DEFAULTSF64, !NOT_SUPPORTED, !INVALID_64, !REP_VALID, !REPNE_VALID, !LOCK_VALID);
        
        // JCXZ/JECXZ – Jump on CX/ECX Zero - Address-size prefix differentiates JCXZ and JECXZ
        //OperandSize_b, 
        
        
        InitOperandArray(&OperandArray);
        PushOperand(&OperandArray, OperandType_GR, OperandSize_cxz);
        BeginInstructionInfoGroup(&FileManager, "JCXZGR", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, DEFAULTSF64, !NOT_SUPPORTED, !INVALID_64, !REP_VALID, !REPNE_VALID, !LOCK_VALID);
        
        InitOperandArray(&OperandArray);
        PushOperand(&OperandArray, OperandType_J, OperandSize_bs);
        PushInstructionInfoEntry(&FileManager, "JCXZ", 16, OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, DEFAULTSF64, !NOT_SUPPORTED, !INVALID_64, !REP_VALID, !REPNE_VALID, !LOCK_VALID);
        
        InitOperandArray(&OperandArray);
        PushOperand(&OperandArray, OperandType_J, OperandSize_bs);
        PushInstructionInfoEntry(&FileManager, "JECXZ", 32, OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray,  DEFAULTSF64, !NOT_SUPPORTED, !INVALID_64, !REP_VALID, !REPNE_VALID, !LOCK_VALID);
        
        InitOperandArray(&OperandArray);
        PushOperand(&OperandArray, OperandType_J, OperandSize_bs);
        PushInstructionInfoEntry(&FileManager, "JRCXZ", 64, OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, DEFAULTSF64, !NOT_SUPPORTED, !INVALID_64, !REP_VALID, !REPNE_VALID, !LOCK_VALID);
        
        EndInstructionInfoGroup(&FileManager);
        
        
        // MOV – Move Data - MOV <AL> , <Ob>
        
        InitOperandArray(&OperandArray);
        PushOperand(&OperandArray, OperandType_AX, OperandSize_b);
        PushOperand(&OperandArray, OperandType_O, OperandSize_b);
        PushInstructionInfo(&FileManager, "MOV", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !DEFAULTSF64, !NOT_SUPPORTED, !INVALID_64, !REP_VALID, !REPNE_VALID, !LOCK_VALID);
        
        
        //MOV - Move Data - MOV <rAX> , <Ovqp>
        
        InitOperandArray(&OperandArray);
        PushOperand(&OperandArray, OperandType_AX, OperandSize_vqp);
        PushOperand(&OperandArray, OperandType_O, OperandSize_vqp);
        PushInstructionInfo(&FileManager, "MOV", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !DEFAULTSF64, !NOT_SUPPORTED, !INVALID_64, !REP_VALID, !REPNE_VALID, !LOCK_VALID);
        
        //MOV - Move Data - MOV <Ob> , <AL>
        
        InitOperandArray(&OperandArray);
        PushOperand(&OperandArray, OperandType_O, OperandSize_b);
        PushOperand(&OperandArray, OperandType_AX, OperandSize_b);
        PushInstructionInfo(&FileManager, "MOV", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !DEFAULTSF64, !NOT_SUPPORTED, !INVALID_64, !REP_VALID, !REPNE_VALID, !LOCK_VALID);
        
        //MOV - Move Data - MOV <Ovqp> , <rAX>
        
        InitOperandArray(&OperandArray);
        PushOperand(&OperandArray, OperandType_O, OperandSize_vqp);
        PushOperand(&OperandArray, OperandType_AX, OperandSize_vqp);
        PushInstructionInfo(&FileManager, "MOV", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !DEFAULTSF64, !NOT_SUPPORTED, !INVALID_64, !REP_VALID, !REPNE_VALID, !LOCK_VALID);
        
        // MOV – Move Data - "MOV <Ev>, <Gv>";
        
        InitOperandArray(&OperandArray);
        PushOperand(&OperandArray, OperandType_E, OperandSize_vqp);
        PushOperand(&OperandArray, OperandType_G, OperandSize_vqp);
        PushInstructionInfo(&FileManager, "MOV", OperandArray.Count, (u32*)OperandArray.TypesArray, (u32*)OperandArray.SizesArray, !DEFAULTSF64, !NOT_SUPPORTED, !INVALID_64, !REP_VALID, !REPNE_VALID, !LOCK_VALID);
        
#if 0        
        // Jcc – Jump if Condition is Met - full displacement
        PushInstructionInfo(&FileManager, OperandSize_z, DEFAULTSF64, NOT_SUPPORTED, !INVALID_64, !REP_VALID, !REPNE_VALID, !LOCK_VALID);
        
        // JCXZ/JECXZ – Jump on CX/ECX Zero - Address-size prefix differentiates JCXZ and JECXZ
        PushInstructionInfo(&FileManager, OperandSize_b, DEFAULTSF64, !NOT_SUPPORTED, !INVALID_64, !REP_VALID, !REPNE_VALID, !LOCK_VALID);
        
        // JMP – Unconditional Jump (to same segment) - short
        PushInstructionInfo(&FileManager, OperandSize_b, DEFAULTSF64, !NOT_SUPPORTED, !INVALID_64, !REP_VALID, !REPNE_VALID, !LOCK_VALID);
        
        // JMP – Unconditional Jump (to same segment) - direct
        PushInstructionInfo(&FileManager, OperandSize_z, DEFAULTSF64, NOT_SUPPORTED, !INVALID_64, !REP_VALID, !REPNE_VALID, !LOCK_VALID);
        
        // JMP – Unconditional Jump (to same segment) - indirect
        PushInstructionInfo(&FileManager, OperandSize_v, DEFAULTSF64, NOT_SUPPORTED, !INVALID_64, !REP_VALID, !REPNE_VALID, !LOCK_VALID);
        
        // JMP – Unconditional Jump (to other segment) - indirect intersegment
        PushInstructionInfo(&FileManager, OperandSize_p, !DEFAULTSF64, !NOT_SUPPORTED, !INVALID_64, !REP_VALID, !REPNE_VALID, !LOCK_VALID);
        
        // JMP – Unconditional Jump (to other segment) - direct intersegment
        PushInstructionInfo(&FileManager, OperandSize_p, !DEFAULTSF64, !NOT_SUPPORTED, INVALID_64, !REP_VALID, !REPNE_VALID, !LOCK_VALID);
        
        // DEC - Decrement by 1 - register Eb
        PushInstructionInfo(&FileManager, OperandSize_b, !DEFAULTSF64, !NOT_SUPPORTED, !INVALID_64, !REP_VALID, !REPNE_VALID, LOCK_VALID);
        
        // DEC - Decrement by 1 - register Ev
        PushInstructionInfo(&FileManager, OperandSize_v, !DEFAULTSF64, !NOT_SUPPORTED, !INVALID_64, !REP_VALID, !REPNE_VALID, LOCK_VALID);
        
        // DEC – Decrement by 1 - DEC <GPR_32>
        PushInstructionInfo(&FileManager, OperandSize_GPR_32, !DEFAULTSF64, !NOT_SUPPORTED, INVALID_64, !REP_VALID, !REPNE_VALID, !LOCK_VALID);
        
        // MOV – Move Data - "MOV <Ev>, <Gv>";
        PushInstructionInfo(&FileManager, OperandSize_v, !DEFAULTSF64, !NOT_SUPPORTED, !INVALID_64, !REP_VALID, !REPNE_VALID, !LOCK_VALID);
        
        // MOV – Move Data - "MOV <Eb>, <Gb>";
        PushInstructionInfo(&FileManager, OperandSize_b, !DEFAULTSF64, !NOT_SUPPORTED, !INVALID_64, !REP_VALID, !REPNE_VALID, !LOCK_VALID);
        
        // MOV – Move Data - "MOV <Gb>, <Eb>";
        PushInstructionInfo(&FileManager, OperandSize_b, !DEFAULTSF64, !NOT_SUPPORTED, !INVALID_64, !REP_VALID, !REPNE_VALID, !LOCK_VALID);
        
        // MOV – Move Data - "MOV <Gv>, <Ev>";
        PushInstructionInfo(&FileManager, OperandSize_v, !DEFAULTSF64, !NOT_SUPPORTED, !INVALID_64, !REP_VALID, !REPNE_VALID, !LOCK_VALID);
        
        // MOV – Move Data - MOV Eb,Ib
        PushInstructionInfo(&FileManager, OperandSize_b, !DEFAULTSF64, !NOT_SUPPORTED, !INVALID_64, !REP_VALID, !REPNE_VALID, !LOCK_VALID);
        
        // MOV – Move Data - MOV Ev,Iz
        PushInstructionInfo(&FileManager, OperandSize_v, !DEFAULTSF64, !NOT_SUPPORTED, !INVALID_64, !REP_VALID, !REPNE_VALID, !LOCK_VALID);
        
        // MOV – Move Data - MOV <GPR_8>, <Ib>
        PushInstructionInfo(&FileManager, OperandSize_GPR_08, !DEFAULTSF64, !NOT_SUPPORTED, !INVALID_64, !REP_VALID, !REPNE_VALID, !LOCK_VALID);
        
        // MOV – Move Data - MOV <GPR_64>, <Iv>
        PushInstructionInfo(&FileManager, OperandSize_GPR_64, !DEFAULTSF64, !NOT_SUPPORTED, !INVALID_64, !REP_VALID, !REPNE_VALID, !LOCK_VALID);
        
        // MOV – Move Data - MOV <rAX_08>, <Ov>
        PushInstructionInfo(&FileManager, OperandSize_rAX_08, !DEFAULTSF64, !NOT_SUPPORTED, !INVALID_64, !REP_VALID, !REPNE_VALID, !LOCK_VALID);
        
        // MOV – Move Data - MOV <rAX_64>, <Ov>
        PushInstructionInfo(&FileManager, OperandSize_rAX_64, !DEFAULTSF64, !NOT_SUPPORTED, !INVALID_64, !REP_VALID, !REPNE_VALID, !LOCK_VALID);
        
        // MOV – Move Data - MOV <Ov>, <rAX_08>
        PushInstructionInfo(&FileManager, OperandSize_rAX_08, !DEFAULTSF64, !NOT_SUPPORTED, !INVALID_64, !REP_VALID, !REPNE_VALID, !LOCK_VALID);
        
        // MOV – Move Data - MOV <Ov>, <rAX_64>
        PushInstructionInfo(&FileManager, OperandSize_rAX_64, !DEFAULTSF64, !NOT_SUPPORTED, !INVALID_64, !REP_VALID, !REPNE_VALID, !LOCK_VALID);
        
        // IMUL – Signed Multiply - AL, AX, or EAX with register - IMUL Eb
        PushInstructionInfo(&FileManager, OperandSize_b, !DEFAULTSF64, !NOT_SUPPORTED, !INVALID_64, !REP_VALID, !REPNE_VALID, !LOCK_VALID);
        
        // IMUL – Signed Multiply - AL, AX, or EAX with register - IMUL Ev
        PushInstructionInfo(&FileManager, OperandSize_v, !DEFAULTSF64, !NOT_SUPPORTED, !INVALID_64, !REP_VALID, !REPNE_VALID, !LOCK_VALID);
        
        // IMUL – Signed Multiply - IMUL Gv,Ev
        PushInstructionInfo(&FileManager, OperandSize_v, !DEFAULTSF64, !NOT_SUPPORTED, !INVALID_64, !REP_VALID, !REPNE_VALID, !LOCK_VALID);
        
        // IMUL – Signed Multiply - IMUL Gv,Ev,Ib
        PushInstructionInfo(&FileManager, OperandSize_v, !DEFAULTSF64, !NOT_SUPPORTED, !INVALID_64, !REP_VALID, !REPNE_VALID, !LOCK_VALID);
        
        // IMUL – Signed Multiply - IMUL Gv,Ev,Iz
        PushInstructionInfo(&FileManager, OperandSize_v, !DEFAULTSF64, !NOT_SUPPORTED, !INVALID_64, !REP_VALID, !REPNE_VALID, !LOCK_VALID);
        
        //INS – Input String - INS Yb,DX
        PushInstructionInfo(&FileManager, OperandSize_b, !DEFAULTSF64, !NOT_SUPPORTED, !INVALID_64, REP_VALID, !REPNE_VALID, !LOCK_VALID);
        
        //INS – Input String - INS Yz,DX
        PushInstructionInfo(&FileManager, OperandSize_z, !DEFAULTSF64, !NOT_SUPPORTED, !INVALID_64, REP_VALID, !REPNE_VALID, !LOCK_VALID);
        
        // LODS - Load String - LODS AL,Xb
        PushInstructionInfo(&FileManager, OperandSize_b, !DEFAULTSF64, !NOT_SUPPORTED, !INVALID_64, REP_VALID, !REPNE_VALID, !LOCK_VALID);
        
        // LODS - Load String - LODS rAX,Xv
        PushInstructionInfo(&FileManager, OperandSize_v, !DEFAULTSF64, !NOT_SUPPORTED, !INVALID_64, REP_VALID, !REPNE_VALID, !LOCK_VALID);
        
        // MOVS – Move String - MOVS Yb,Xb
        PushInstructionInfo(&FileManager, OperandSize_b, !DEFAULTSF64, !NOT_SUPPORTED, !INVALID_64, REP_VALID, !REPNE_VALID, !LOCK_VALID);
        
        // MOVS – Move String - MOVS Yv,Xv
        PushInstructionInfo(&FileManager, OperandSize_v, !DEFAULTSF64, !NOT_SUPPORTED, !INVALID_64, REP_VALID, !REPNE_VALID, !LOCK_VALID);
        
        // OUTS – Output String - OUTS DX,Xb
        PushInstructionInfo(&FileManager, OperandSize_b, !DEFAULTSF64, !NOT_SUPPORTED, !INVALID_64, REP_VALID, !REPNE_VALID, !LOCK_VALID);
        
        // OUTS – Output String - OUTS DX,Xz
        PushInstructionInfo(&FileManager, OperandSize_z, !DEFAULTSF64, !NOT_SUPPORTED, !INVALID_64, REP_VALID, !REPNE_VALID, !LOCK_VALID);
        
        // STOS – Store String - STOS <Yb>, <AL>
        PushInstructionInfo(&FileManager, OperandSize_b, !DEFAULTSF64, !NOT_SUPPORTED, !INVALID_64, REP_VALID, !REPNE_VALID, !LOCK_VALID);
        
        // STOS – Store String - STOS <Yv>, <rAX>
        PushInstructionInfo(&FileManager, OperandSize_v, !DEFAULTSF64, !NOT_SUPPORTED, !INVALID_64, REP_VALID, !REPNE_VALID, !LOCK_VALID);
        
        // CMPS – Compare String - CMPS Yb,Xb
        PushInstructionInfo(&FileManager, OperandSize_b, !DEFAULTSF64, !NOT_SUPPORTED, !INVALID_64, REP_VALID, REPNE_VALID, !LOCK_VALID);
        
        // CMPS – Compare String - CMPS Yv,Xv
        PushInstructionInfo(&FileManager, OperandSize_v, !DEFAULTSF64, !NOT_SUPPORTED, !INVALID_64, REP_VALID, REPNE_VALID, !LOCK_VALID);
        
        //SCAS – Scan String - SCAS Yb,AL
        PushInstructionInfo(&FileManager, OperandSize_b, !DEFAULTSF64, !NOT_SUPPORTED, !INVALID_64, REP_VALID, REPNE_VALID, !LOCK_VALID);
        
        //SCAS – Scan String - SCAS Yv,rAX
        PushInstructionInfo(&FileManager, OperandSize_v, !DEFAULTSF64, !NOT_SUPPORTED, !INVALID_64, REP_VALID, REPNE_VALID, !LOCK_VALID);
        
        // BTR – Bit Test and Reset - BTR Ev,Ib
        PushInstructionInfo(&FileManager, OperandSize_v, !DEFAULTSF64, !NOT_SUPPORTED, !INVALID_64, !REP_VALID, !REPNE_VALID, LOCK_VALID);
        
        // BTR - Bit Test and Reset - BTR Ev,Gv
        PushInstructionInfo(&FileManager, OperandSize_v, !DEFAULTSF64, !NOT_SUPPORTED, !INVALID_64, !REP_VALID, !REPNE_VALID, LOCK_VALID);
        
        // BT – Bit Test - BT Ev,Ib
        PushInstructionInfo(&FileManager, OperandSize_v, !DEFAULTSF64, !NOT_SUPPORTED, !INVALID_64, !REP_VALID, !REPNE_VALID, !LOCK_VALID);
        
        // BT - Bit Test - BT Ev,Gv
        PushInstructionInfo(&FileManager, OperandSize_v, !DEFAULTSF64, !NOT_SUPPORTED, !INVALID_64, !REP_VALID, !REPNE_VALID, !LOCK_VALID);
        
        // BTS – Bit Test and Set - BTS Ev,Ib
        PushInstructionInfo(&FileManager, OperandSize_v, !DEFAULTSF64, !NOT_SUPPORTED, !INVALID_64, !REP_VALID, !REPNE_VALID, LOCK_VALID);
        
        // BTS - Bit Test and Set - BTS Ev,Gv
        PushInstructionInfo(&FileManager, OperandSize_v, !DEFAULTSF64, !NOT_SUPPORTED, !INVALID_64, !REP_VALID, !REPNE_VALID, LOCK_VALID);
        
        // BTC – Bit Test and Complement - BTC Ev,Ib
        PushInstructionInfo(&FileManager, OperandSize_v, !DEFAULTSF64, !NOT_SUPPORTED, !INVALID_64, !REP_VALID, !REPNE_VALID, LOCK_VALID);
        
        // BTC - Bit Test and Complement - BTC Ev,Gv
        PushInstructionInfo(&FileManager, OperandSize_v, !DEFAULTSF64, !NOT_SUPPORTED, !INVALID_64, !REP_VALID, !REPNE_VALID, LOCK_VALID);
        
        // INC – Increment by 1 - INC Eb
        PushInstructionInfo(&FileManager, OperandSize_b, !DEFAULTSF64, !NOT_SUPPORTED, !INVALID_64, !REP_VALID, !REPNE_VALID, LOCK_VALID);
        
        // INC – Increment by 1 - INC Ev
        PushInstructionInfo(&FileManager, OperandSize_v, !DEFAULTSF64, !NOT_SUPPORTED, !INVALID_64, !REP_VALID, !REPNE_VALID, LOCK_VALID);
        
        // INC - Increment by 1 - INC <GPR_32>
        PushInstructionInfo(&FileManager, OperandSize_GPR_32, !DEFAULTSF64, !NOT_SUPPORTED, INVALID_64, !REP_VALID, !REPNE_VALID, !LOCK_VALID);
        
        // ADD – Add - ADD Eb,Gb
        PushInstructionInfo(&FileManager, OperandSize_b, !DEFAULTSF64, !NOT_SUPPORTED, !INVALID_64, !REP_VALID, !REPNE_VALID, LOCK_VALID);
        
        // ADD – Add - ADD Ev,Gv
        PushInstructionInfo(&FileManager, OperandSize_v, !DEFAULTSF64, !NOT_SUPPORTED, !INVALID_64, !REP_VALID, !REPNE_VALID, LOCK_VALID);
        
        // ADD – Add - ADD Gb,Eb
        PushInstructionInfo(&FileManager, OperandSize_b, !DEFAULTSF64, !NOT_SUPPORTED, !INVALID_64, !REP_VALID, !REPNE_VALID, !LOCK_VALID);
        
        // ADD – Add - ADD Gv,Ev
        PushInstructionInfo(&FileManager, OperandSize_v, !DEFAULTSF64, !NOT_SUPPORTED, !INVALID_64, !REP_VALID, !REPNE_VALID, !LOCK_VALID);
        
        // ADD – Add - ADD Eb,Ib
        PushInstructionInfo(&FileManager, OperandSize_b, !DEFAULTSF64, !NOT_SUPPORTED, !INVALID_64, !REP_VALID, !REPNE_VALID, LOCK_VALID);
#endif
        
        
        EndFileSection(&FileManager);
		
        
#endif //EFLYFILE_TABLES_GENERATED
        
		//TODO(Alex): Change string data_structure to add the count, so that its easily done
		//struct eflyfile_string
		//{
		//memory_index Count;
		//memory_index AbsOffset;
		//}
		
        BeginFileSection(&FileManager, FileSection_string);
        
        StartFileStringSection(&FileManager, StringSection_conditional_codes);
        
        PushStringToFile(&FileManager, "O");
        PushStringToFile(&FileManager, "NO");
        PushStringToFile(&FileManager, "B, NAE");
        PushStringToFile(&FileManager, "NB, AE");
        PushStringToFile(&FileManager, "E, Z");
        PushStringToFile(&FileManager, "NE, EZ");
        PushStringToFile(&FileManager, "BE, NA");
        PushStringToFile(&FileManager, "NBE, A");
        
        PushStringToFile(&FileManager, "S");
        PushStringToFile(&FileManager, "NS");
        PushStringToFile(&FileManager, "P, PE");
        PushStringToFile(&FileManager, "NP, PO");
        PushStringToFile(&FileManager, "L, NGE");
        PushStringToFile(&FileManager, "NL, GE");
        PushStringToFile(&FileManager, "LE, NG");
        PushStringToFile(&FileManager, "NLE, G");
        
        
        StartFileStringSection(&FileManager, StringSection_modrm_rm101_grammars);
        
        PushStringToFile(&FileManager, "CS : [ RIP + <disp32> ]");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ <disp32> ]");
        PushStringToFile(&FileManager, "CS : [ EIP + <disp32> ]");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ <disp32> ]");
        
        
        StartFileStringSection(&FileManager, StringSection_modrm_64_extended_grammars);
        
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ R8 ]");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ R9 ]");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ R10 ]");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ R11 ]");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ <sib> ]");
        PushStringToFile(&FileManager, "");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ R14 ]");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ R15 ]");
        
        
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ R8 + <disp8> ]");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ R9 + <disp8> ]");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ R10 + <disp8> ]");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ R11 + <disp8> ]");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ <sib> + <disp8> ]");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ R13 + <disp8> ]");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ R14 + <disp8> ]");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ R15 + <disp8> ]");
        
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ R8 + <disp32> ]");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ R9 + <disp32> ]");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ R10 + <disp32> ]");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ R11 + <disp32> ]");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ <sib> + <disp32> ]");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ R13 + <disp32> ]");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ R14 + <disp32> ]");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ R15 + <disp32> ]");
        
        
        StartFileStringSection(&FileManager, StringSection_modrm_64_grammars);
        
        
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ RAX ]");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ RCX ]");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ RDX ]");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ RBX ]");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ <sib> ]");
        PushStringToFile(&FileManager, "");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ RSI ]");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ RDI ]");
        
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ RAX + <disp8> ]");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ RCX + <disp8> ]");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ RDX + <disp8> ]");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ RBX + <disp8> ]");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ <sib> + <disp8> ]");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ RBP + <disp8> ]");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ RSI + <disp8> ]");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ RDI + <disp8> ]");
        
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ RAX + <disp32> ]");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ RCX + <disp32> ]");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ RDX + <disp32> ]");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ RBX + <disp32> ]");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ <sib> + <disp32> ]");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ RBP + <disp32> ]");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ RSI + <disp32> ]");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ RDI + <disp32> ]");
        
        
        StartFileStringSection(&FileManager, StringSection_modrm_32_extended_grammars);
        
        
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ R8D ]");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ R9D ]");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ R10D ]");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ R11D ]");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ <sib> ]");
        PushStringToFile(&FileManager, "");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ R14D ]");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ R15D ]");
        
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ R8D + <disp8> ]");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ R9D + <disp8> ]");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ R10D + <disp8> ]");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ R11D + <disp8> ]");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ <sib> + <disp8> ]");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ R13D + <disp8> ]");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ R14D + <disp8> ]");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ R15D + <disp8> ]");
        
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ R8D + <disp32> ]");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ R9D + <disp32> ]");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ R10D + <disp32> ]");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ R11D + <disp32> ]");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ <sib> + <disp32> ]");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ R13D + <disp32> ]");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ R14D + <disp32> ]");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ R15D + <disp32> ]");
        
        StartFileStringSection(&FileManager, StringSection_modrm_32_grammars);
        
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ EAX ]");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ ECX ]");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ EDX ]");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ EBX ]");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ <sib> ]");
        PushStringToFile(&FileManager, "");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ ESI ]");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ EDI ]");
        
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ EAX + <disp8> ]");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ ECX + <disp8> ]");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ EDX + <disp8> ]");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ EBX + <disp8> ]");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ <sib> + <disp8> ]");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ EBP + <disp8> ]");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ ESI + <disp8> ]");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ EDI + <disp8> ]");
        
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ EAX + <disp32> ]");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ ECX + <disp32> ]");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ EDX + <disp32> ]");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ EBX + <disp32> ]");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ <sib> + <disp32> ]");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ EBP + <disp32> ]");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ ESI + <disp32> ]");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ EDI + <disp32> ]");
        
        StartFileStringSection(&FileManager, StringSection_modrm_16_grammars);
        
        
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ BX + SI ]");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ BX + DI ]");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ BP + SI ]");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ BP + DI ]");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ SI ]");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ DI ]");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ <disp16> ]");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ BX ]");
        
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ BX + SI + <disp8> ]");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ BX + DI + <disp8> ]");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ BP + SI + <disp8> ]");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ BP + DI + <disp8> ]");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ SI + <disp8> ]");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ DI + <disp8> ]");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ BP + <disp8> ]");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ BX + <disp8> ]");
        
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ BX + SI + <disp16> ]");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ BX + DI + <disp16> ]");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ BP + SI + <disp16> ]");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ BP + DI + <disp16> ]");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ SI + <disp16> ]");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ DI + <disp16> ]");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ BP + <disp16> ]");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ BX + <disp16> ]");
        
        
        StartFileStringSection(&FileManager, StringSection_base_base101_grammars);
        
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ <ss>");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ R13 + <ss>");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ R13 + <ss>");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ <ss>");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ RBP + <ss>");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ RBP + <ss>");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ <ss>");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ R13D + <ss>");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ R13D + <ss>");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ <ss>");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ EBP + <ss>");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ EBP + <ss>");
        
        StartFileStringSection(&FileManager, StringSection_base_64_extended_grammars);
        
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ R8 + <ss>");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ R9 + <ss>");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ R10 + <ss>");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ R11 + <ss>");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ R12 + <ss>");
        PushStringToFile(&FileManager, "");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ R14 + <ss>");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ R15 + <ss>");
        
        StartFileStringSection(&FileManager, StringSection_base_64_grammars);
        
        
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ RAX + <ss>");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ RCX + <ss>");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ RDX + <ss>");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ RBX + <ss>");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ RSP + <ss>");
        PushStringToFile(&FileManager, "");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ RSI + <ss>");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ RDI + <ss>");
        
        
        StartFileStringSection(&FileManager, StringSection_base_32_extended_grammars);
        
        
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ R8D + <ss>");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ R9D + <ss>");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ R10D + <ss>");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ R11D + <ss>");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ R12D + <ss>");
        PushStringToFile(&FileManager, "");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ R14D + <ss>");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ R15D + <ss>");
        
        
        StartFileStringSection(&FileManager, StringSection_base_32_grammars);
        
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ EAX + <ss>");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ ECX + <ss>");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ EDX + <ss>");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ EBX + <ss>");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ ESP + <ss>");
        PushStringToFile(&FileManager, "");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ ESI + <ss>");
        PushStringToFile(&FileManager, "<size> ptr <sreg> : [ EDI + <ss>");
        
        
        StartFileStringSection(&FileManager, StringSection_ss_64_extended_grammars);
        
        PushStringToFile(&FileManager, "R8 * 1");
        PushStringToFile(&FileManager, "R9 * 1");
        PushStringToFile(&FileManager, "R10 * 1");
        PushStringToFile(&FileManager, "R11 * 1");
        PushStringToFile(&FileManager, "R12 * 1");
        PushStringToFile(&FileManager, "R13 * 1");
        PushStringToFile(&FileManager, "R14 * 1");
        PushStringToFile(&FileManager, "R15 * 1");
        
        PushStringToFile(&FileManager, "R8 * 2");
        PushStringToFile(&FileManager, "R9 * 2");
        PushStringToFile(&FileManager, "R10 * 2");
        PushStringToFile(&FileManager, "R11 * 2");
        PushStringToFile(&FileManager, "R12 * 2");
        PushStringToFile(&FileManager, "R13 * 2");
        PushStringToFile(&FileManager, "R14 * 2");
        PushStringToFile(&FileManager, "R15 * 2");
        
        PushStringToFile(&FileManager, "R8 * 4");
        PushStringToFile(&FileManager, "R9 * 4");
        PushStringToFile(&FileManager, "R10 * 4");
        PushStringToFile(&FileManager, "R11 * 4");
        PushStringToFile(&FileManager, "R12 * 4");
        PushStringToFile(&FileManager, "R13 * 4");
        PushStringToFile(&FileManager, "R14 * 4");
        PushStringToFile(&FileManager, "R15 * 4");
        
        PushStringToFile(&FileManager, "R8 * 8");
        PushStringToFile(&FileManager, "R9 * 8");
        PushStringToFile(&FileManager, "R10 * 8");
        PushStringToFile(&FileManager, "R11 * 8");
        PushStringToFile(&FileManager, "R12 * 8");
        PushStringToFile(&FileManager, "R13 * 8");
        PushStringToFile(&FileManager, "R14 * 8");
        PushStringToFile(&FileManager, "R15 * 8");
        
        StartFileStringSection(&FileManager, StringSection_ss_64_grammars);
        
        
        PushStringToFile(&FileManager, "RAX * 1");
        PushStringToFile(&FileManager, "RCX * 1");
        PushStringToFile(&FileManager, "RDX * 1");
        PushStringToFile(&FileManager, "RBX * 1");
        PushStringToFile(&FileManager, "");
        PushStringToFile(&FileManager, "RBP * 1");
        PushStringToFile(&FileManager, "RSI * 1");
        PushStringToFile(&FileManager, "RDI * 1");
        
        PushStringToFile(&FileManager, "RAX * 2");
        PushStringToFile(&FileManager, "RCX * 2");
        PushStringToFile(&FileManager, "RDX * 2");
        PushStringToFile(&FileManager, "RBX * 2");
        PushStringToFile(&FileManager, "");
        PushStringToFile(&FileManager, "RBP * 2");
        PushStringToFile(&FileManager, "RSI * 2");
        PushStringToFile(&FileManager, "RDI * 2");
        
        PushStringToFile(&FileManager, "RAX * 4");
        PushStringToFile(&FileManager, "RCX * 4");
        PushStringToFile(&FileManager, "RDX * 4");
        PushStringToFile(&FileManager, "RBX * 4");
        PushStringToFile(&FileManager, "");
        PushStringToFile(&FileManager, "RBP * 4");
        PushStringToFile(&FileManager, "RSI * 4");
        PushStringToFile(&FileManager, "RDI * 4");
        
        PushStringToFile(&FileManager, "RAX * 8");
        PushStringToFile(&FileManager, "RCX * 8");
        PushStringToFile(&FileManager, "RDX * 8");
        PushStringToFile(&FileManager, "RBX * 8");
        PushStringToFile(&FileManager, "");
        PushStringToFile(&FileManager, "RBP * 8");
        PushStringToFile(&FileManager, "RSI * 8");
        PushStringToFile(&FileManager, "RDI * 8");
        
        StartFileStringSection(&FileManager, StringSection_ss_32_extended_grammars);
        
        PushStringToFile(&FileManager, "R8D * 1");
        PushStringToFile(&FileManager, "R9D * 1");
        PushStringToFile(&FileManager, "R10D * 1");
        PushStringToFile(&FileManager, "R11D * 1");
        PushStringToFile(&FileManager, "R12D * 1");
        PushStringToFile(&FileManager, "R13D * 1");
        PushStringToFile(&FileManager, "R14D * 1");
        PushStringToFile(&FileManager, "R15D * 1");
        
        PushStringToFile(&FileManager, "R8D * 2");
        PushStringToFile(&FileManager, "R9D * 2");
        PushStringToFile(&FileManager, "R10D * 2");
        PushStringToFile(&FileManager, "R11D * 2");
        PushStringToFile(&FileManager, "R12D * 2");
        PushStringToFile(&FileManager, "R13D * 2");
        PushStringToFile(&FileManager, "R14D * 2");
        PushStringToFile(&FileManager, "R15D * 2");
        
        PushStringToFile(&FileManager, "R8D * 4");
        PushStringToFile(&FileManager, "R9D * 4");
        PushStringToFile(&FileManager, "R10D * 4");
        PushStringToFile(&FileManager, "R11D * 4");
        PushStringToFile(&FileManager, "R12D * 4");
        PushStringToFile(&FileManager, "R13D * 4");
        PushStringToFile(&FileManager, "R14D * 4");
        PushStringToFile(&FileManager, "R15D * 4");
        
        PushStringToFile(&FileManager, "R8D * 8");
        PushStringToFile(&FileManager, "R9D * 8");
        PushStringToFile(&FileManager, "R10D * 8");
        PushStringToFile(&FileManager, "R11D * 8");
        PushStringToFile(&FileManager, "R12D * 8");
        PushStringToFile(&FileManager, "R13D * 8");
        PushStringToFile(&FileManager, "R14D * 8");
        PushStringToFile(&FileManager, "R15D * 8");
        
        StartFileStringSection(&FileManager, StringSection_ss_32_grammars);
        
        
        PushStringToFile(&FileManager, "EAX * 1");
        PushStringToFile(&FileManager, "ECX * 1");
        PushStringToFile(&FileManager, "EDX * 1");
        PushStringToFile(&FileManager, "EBX * 1");
        PushStringToFile(&FileManager, "");
        PushStringToFile(&FileManager, "EBP * 1");
        PushStringToFile(&FileManager, "ESI * 1");
        PushStringToFile(&FileManager, "EDI * 1");
        
        PushStringToFile(&FileManager, "EAX * 2");
        PushStringToFile(&FileManager, "ECX * 2");
        PushStringToFile(&FileManager, "EDX * 2");
        PushStringToFile(&FileManager, "EBX * 2");
        PushStringToFile(&FileManager, "");
        PushStringToFile(&FileManager, "EBP * 2");
        PushStringToFile(&FileManager, "ESI * 2");
        PushStringToFile(&FileManager, "EDI * 2");
        
        PushStringToFile(&FileManager, "EAX * 4");
        PushStringToFile(&FileManager, "ECX * 4");
        PushStringToFile(&FileManager, "EDX * 4");
        PushStringToFile(&FileManager, "EBX * 4");
        PushStringToFile(&FileManager, "");
        PushStringToFile(&FileManager, "EBP * 4");
        PushStringToFile(&FileManager, "ESI * 4");
        PushStringToFile(&FileManager, "EDI * 4");
        
        PushStringToFile(&FileManager, "EAX * 8");
        PushStringToFile(&FileManager, "ECX * 8");
        PushStringToFile(&FileManager, "EDX * 8");
        PushStringToFile(&FileManager, "EBX * 8");
        PushStringToFile(&FileManager, "");
        PushStringToFile(&FileManager, "EBP * 8");
        PushStringToFile(&FileManager, "ESI * 8");
        PushStringToFile(&FileManager, "EDI * 8");
        
        StartFileStringSection(&FileManager, StringSection_reg_64_extended_grammars);
        
        PushStringToFile(&FileManager, "R8");
        PushStringToFile(&FileManager, "R9");
        PushStringToFile(&FileManager, "R10");
        PushStringToFile(&FileManager, "R11");
        PushStringToFile(&FileManager, "R12");
        PushStringToFile(&FileManager, "R13");
        PushStringToFile(&FileManager, "R14");
        PushStringToFile(&FileManager, "R15");
        
        StartFileStringSection(&FileManager, StringSection_reg_64_grammars);
        
        PushStringToFile(&FileManager, "RAX");
        PushStringToFile(&FileManager, "RCX");
        PushStringToFile(&FileManager, "RDX");
        PushStringToFile(&FileManager, "RBX");
        PushStringToFile(&FileManager, "RSP");
        PushStringToFile(&FileManager, "RBP");
        PushStringToFile(&FileManager, "RSI");
        PushStringToFile(&FileManager, "RDI");
        
        StartFileStringSection(&FileManager, StringSection_reg_32_extended_grammars);
        
        
        PushStringToFile(&FileManager, "R8D");
        PushStringToFile(&FileManager, "R9D");
        PushStringToFile(&FileManager, "R10D");
        PushStringToFile(&FileManager, "R11D");
        PushStringToFile(&FileManager, "R12D");
        PushStringToFile(&FileManager, "R13D");
        PushStringToFile(&FileManager, "R14D");
        PushStringToFile(&FileManager, "R15D");
        
        StartFileStringSection(&FileManager, StringSection_reg_32_grammars);
        
        PushStringToFile(&FileManager, "EAX");
        PushStringToFile(&FileManager, "ECX");
        PushStringToFile(&FileManager, "EDX");
        PushStringToFile(&FileManager, "EBX"); 
        PushStringToFile(&FileManager, "ESP");
        PushStringToFile(&FileManager, "EBP");
        PushStringToFile(&FileManager, "ESI");
        PushStringToFile(&FileManager, "EDI");
        
        StartFileStringSection(&FileManager, StringSection_reg_16_extended_grammars);
        
        
        PushStringToFile(&FileManager, "R8W");
        PushStringToFile(&FileManager, "R9W");
        PushStringToFile(&FileManager, "R10W");
        PushStringToFile(&FileManager, "R11W");
        PushStringToFile(&FileManager, "R12W");
        PushStringToFile(&FileManager, "R13W");
        PushStringToFile(&FileManager, "R14W");
        PushStringToFile(&FileManager, "R15W");
        
        StartFileStringSection(&FileManager, StringSection_reg_16_grammars);
        
        PushStringToFile(&FileManager, "AX");
        PushStringToFile(&FileManager, "CX");
        PushStringToFile(&FileManager, "DX");
        PushStringToFile(&FileManager, "BX");
        PushStringToFile(&FileManager, "SP");
        PushStringToFile(&FileManager, "BP");
        PushStringToFile(&FileManager, "SI");
        PushStringToFile(&FileManager, "DI");
        
        StartFileStringSection(&FileManager, StringSection_reg_8_extended_grammars);
        
        PushStringToFile(&FileManager, "R8B");
        PushStringToFile(&FileManager, "R9B");
        PushStringToFile(&FileManager, "R10B");
        PushStringToFile(&FileManager, "R11B");
        PushStringToFile(&FileManager, "R12B");
        PushStringToFile(&FileManager, "R13B");
        PushStringToFile(&FileManager, "R14B");
        PushStringToFile(&FileManager, "R15B");
        
        StartFileStringSection(&FileManager, StringSection_reg_8_rex_present_grammars);
        
        
        PushStringToFile(&FileManager, "AL");
        PushStringToFile(&FileManager, "CL");
        PushStringToFile(&FileManager, "DL");
        PushStringToFile(&FileManager, "BL");
        PushStringToFile(&FileManager, "SPL");
        PushStringToFile(&FileManager, "BPL");
        PushStringToFile(&FileManager, "SIL");
        PushStringToFile(&FileManager, "DIL");
        
        StartFileStringSection(&FileManager, StringSection_reg_8_grammars);
        
        
        PushStringToFile(&FileManager, "AL");
        PushStringToFile(&FileManager, "CL");
        PushStringToFile(&FileManager, "DL");
        PushStringToFile(&FileManager, "BL");
        PushStringToFile(&FileManager, "AH");
        PushStringToFile(&FileManager, "CH");
        PushStringToFile(&FileManager, "DH");
        PushStringToFile(&FileManager, "BH");
        
		StartFileStringSection(&FileManager, StringSection_reg_fp_grammars);
        
        PushStringToFile(&FileManager, "ST(0)");
        PushStringToFile(&FileManager, "ST(1)");
        PushStringToFile(&FileManager, "ST(2)");
        PushStringToFile(&FileManager, "ST(3)");
        PushStringToFile(&FileManager, "ST(4)");
        PushStringToFile(&FileManager, "ST(5)");
        PushStringToFile(&FileManager, "ST(6)");
        PushStringToFile(&FileManager, "ST(7)");
        
		StartFileStringSection(&FileManager, StringSection_reg_mmx_grammars);
        
        
        PushStringToFile(&FileManager, "MM0");
        PushStringToFile(&FileManager, "MM1");
        PushStringToFile(&FileManager, "MM2");
        PushStringToFile(&FileManager, "MM3");
        PushStringToFile(&FileManager, "MM4");
        PushStringToFile(&FileManager, "MM5");
        PushStringToFile(&FileManager, "MM6");
        PushStringToFile(&FileManager, "MM7");
		
		StartFileStringSection(&FileManager, StringSection_reg_xmm_grammars);
        
		
        PushStringToFile(&FileManager, "XMM0");
        PushStringToFile(&FileManager, "XMM1");
        PushStringToFile(&FileManager, "XMM2");
        PushStringToFile(&FileManager, "XMM3");
        PushStringToFile(&FileManager, "XMM4");
        PushStringToFile(&FileManager, "XMM5");
        PushStringToFile(&FileManager, "XMM6");
        PushStringToFile(&FileManager, "XMM7");
        PushStringToFile(&FileManager, "XMM8");
        PushStringToFile(&FileManager, "XMM9");
        PushStringToFile(&FileManager, "XMM10");
        PushStringToFile(&FileManager, "XMM11");
        PushStringToFile(&FileManager, "XMM12");
        PushStringToFile(&FileManager, "XMM13");
        PushStringToFile(&FileManager, "XMM14");
        PushStringToFile(&FileManager, "XMM15");
        
		StartFileStringSection(&FileManager, StringSection_reg_cr_grammars);
        
        PushStringToFile(&FileManager, "CR0");
        PushStringToFile(&FileManager, "CR2");
        PushStringToFile(&FileManager, "CR3");
        PushStringToFile(&FileManager, "CR4");
        
		
		StartFileStringSection(&FileManager, StringSection_reg_dr_grammars);
        
        PushStringToFile(&FileManager, "DR0");
        PushStringToFile(&FileManager, "DR1");
        PushStringToFile(&FileManager, "DR2");
        PushStringToFile(&FileManager, "DR3");
        PushStringToFile(&FileManager, "DR6");
        PushStringToFile(&FileManager, "DR7");
        
		
		StartFileStringSection(&FileManager, StringSection_reg_sreg_grammars);
        
        PushStringToFile(&FileManager, "ES");
        PushStringToFile(&FileManager, "CS");
        PushStringToFile(&FileManager, "SS");
        PushStringToFile(&FileManager, "DS");
        PushStringToFile(&FileManager, "FS");
        PushStringToFile(&FileManager, "GS");
        
		StartFileStringSection(&FileManager, StringSection_reg_treg_grammars);
        
        PushStringToFile(&FileManager, "TR3");
        PushStringToFile(&FileManager, "TR4");
        PushStringToFile(&FileManager, "TR5");
        PushStringToFile(&FileManager, "TR6");
        PushStringToFile(&FileManager, "TR7");
        
		StartFileStringSection(&FileManager, StringSection_reg_cx_grammars);
        
        PushStringToFile(&FileManager, "CL");
        PushStringToFile(&FileManager, "CX");
        PushStringToFile(&FileManager, "ECX");
        PushStringToFile(&FileManager, "RCX");
        
		StartFileStringSection(&FileManager, StringSection_reg_ax_grammars);
        
        PushStringToFile(&FileManager, "AL");
        PushStringToFile(&FileManager, "AX");
        PushStringToFile(&FileManager, "EAX");
        PushStringToFile(&FileManager, "RAX");
        
		StartFileStringSection(&FileManager, StringSection_reg_dx_grammars);
        
        PushStringToFile(&FileManager, "DL");
        PushStringToFile(&FileManager, "DX");
        PushStringToFile(&FileManager, "EDX");
        PushStringToFile(&FileManager, "RDX");
        
		StartFileStringSection(&FileManager, StringSection_mem_operand_size_kw_masm);
		/*
  NASM Data type syntax
1 byte (8 bit): byte, DB, RESB
2 bytes (16 bit): word, DW, RESW
4 bytes (32 bit): dword, DD, RESD
8 bytes (64 bit): qword, DQ, RESQ
10 bytes (80 bit): tword, DT, REST
16 bytes (128 bit): oword, DO, RESO, DDQ, RESDQ
32 bytes (256 bit): yword, DY, RESY
64 bytes (512 bit): zword, DZ, RESZ

  */        
		
        PushStringToFile(&FileManager, "invalid");
        PushStringToFile(&FileManager, "byte");
        PushStringToFile(&FileManager, "word");
        PushStringToFile(&FileManager, "dword");
        PushStringToFile(&FileManager, "qword");
        PushStringToFile(&FileManager, "oword");
        PushStringToFile(&FileManager, "yword");
        PushStringToFile(&FileManager, "zword");
        PushStringToFile(&FileManager, "fword");
        PushStringToFile(&FileManager, "tword");
        PushStringToFile(&FileManager, "mem_range");
		
		
        EndFileSection(&FileManager);
#if EAGLEFLY_INTERNAL
		/*
//TODO(Alex) : make this checksum a program of their own, so that we can test faster if we got it wrong!

info_i_count_16 = 978
op_i_count_16 = 979

info_i_count_32 = 1005
op_i_count_32 = 1006

info_i_count_64 = 1251 
op_i_count_64 = 1248



  */
		
		
		
		memory_index info_i_count_64  = (FileManager.InstructionInfosArena_64.Arena.Used / sizeof(eflyfile_instruction_info));
		memory_index info_i_count_32  = (FileManager.InstructionInfosArena_32.Arena.Used / sizeof(eflyfile_instruction_info));
		memory_index info_i_count_16  = (FileManager.InstructionInfosArena_16.Arena.Used / sizeof(eflyfile_instruction_info));
		
		memory_index op_i_count_16  = (FileManager.i_bits_header_arena_16.Arena.Used / sizeof(eff_instruction_bits_header));
		memory_index op_i_count_32  = (FileManager.i_bits_header_arena_32.Arena.Used / sizeof(eff_instruction_bits_header));
		memory_index op_i_count_64  = (FileManager.i_bits_header_arena_64.Arena.Used / sizeof(eff_instruction_bits_header));
		
		Assert(info_i_count_16 == op_i_count_16);
		Assert(info_i_count_32 == op_i_count_32);
		Assert(info_i_count_64 == op_i_count_64);
		
#endif
        
        /*
        
        R8
        R9
        R10
        R11
        R12
        R13
        R14
        R15
        
        //////////////////////
        
        RAX
        RCX
        RDX
        RBX
        RSP
        RBP
        RSI
        RDI
        
        //////////////////////
        
        R8D
        R9D
        R10D
        R11D
        R12D
        R13D
        R14D
        R15D
        
        ///////////////////////
        
        EAX
        ECX
        EDX
        EBX
        ESP
        EBP
        ESI
        EDI
        
        //////////////////////
        
        R8W
        R9W
        R10W
        R11W
        R12W
        R13W
        R14W
        R15W
        
        ////////////////////////
        
        AX
        CX
        DX
        BX
        SP
        BP
        SI
        DI
        
        
        ///////////////////////
        
        R8B
        R9B
        R10B
        R11B
        R12B
        R13B
        R14B
        R15B
        
        ///////////////////////
        
        AL
        CL
        DL
        BL
        SPL
        BPL
        SIL
        DIL
        
        ///////////////////////
        
        AL
        CL
        DL
        BL
        AH
        CH
        DH
        BH
        
        */
        
        
        /*
        SS Grammars
        
        R8 * 1
        R9 * 1
        R10 * 1
        R11 * 1
        R12 * 1
        R13 * 1
        R14 * 1
        R15 * 1
        
        R8 * 2
        R9 * 2
        R10 * 2
        R11 * 2
        R12 * 2
        R13 * 2
        R14 * 2
        R15 * 2
        
        R8 * 4
        R9 * 4
        R10 * 4
        R11 * 4
        R12 * 4
        R13 * 4
        R14 * 4
        R15 * 4
        
        R8 * 8
        R9 * 8
        R10 * 8
        R11 * 8
        R12 * 8
        R13 * 8
        R14 * 8
        R15 * 8
        
        ////////////////////////////////
        
        RAX * 1
        RCX * 1
        RDX * 1
        RBX * 1
        ""
        RBP * 1
        RSI * 1
        RDI * 1
        
        RAX * 2
        RCX * 2
        RDX * 2
        RBX * 2
        ""
        RBP * 2
        RSI * 2
        RDI * 2
        
        RAX * 4
        RCX * 4
        RDX * 4
        RBX * 4
        ""
        RBP * 4
        RSI * 4
        RDI * 4
        
        RAX * 8
        RCX * 8
        RDX * 8
        RBX * 8
        ""
        RBP * 8
        RSI * 8
        RDI * 8
        
        /////////////////////////////////
        
        R8D * 1
        R9D * 1
        R10D * 1
        R11D * 1
        R12D * 1
        R13D * 1
        R14D * 1
        R15D * 1
        
        R8D * 2
        R9D * 2
        R10D * 2
        R11D * 2
        R12D * 2
        R13D * 2
        R14D * 2
        R15D * 2
        
        R8D * 4
        R9D * 4
        R10D * 4
        R11D * 4
        R12D * 4
        R13D * 4
        R14D * 4
        R15D * 4
        
        R8D * 8
        R9D * 8
        R10D * 8
        R11D * 8
        R12D * 8
        R13D * 8
        R14D * 8
        R15D * 8
        
        ////////////////////////////////////
        
        
        EAX * 1
        ECX * 1
        EDX * 1
        EBX * 1
        ""
        EBP * 1
        ESI * 1
        EDI * 1
        
        EAX * 2
        ECX * 2
        EDX * 2
        EBX * 2
        ""
        EBP * 2
        ESI * 2
        EDI * 2
        
        EAX * 4
        ECX * 4
        EDX * 4
        EBX * 4
        ""
        EBP * 4
        ESI * 4
        EDI * 4
        
        EAX * 8
        ECX * 8
        EDX * 8
        EBX * 8
        ""
        EBP * 8
        ESI * 8
        EDI * 8
        
        */
        
        
        /*
        
        Base Grammars
        
        
        <segment register> : [ R8 + <ss> ]
        <segment register> : [ R9 + <ss> ]
        <segment register> : [ R10 + <ss> ]
        <segment register> : [ R11 + <ss> ]
        <segment register> : [ R12 + <ss> ]
        
        <segment register> : [ <ss> + <disp32> ]
        <segment register> : [ R13 + <ss> + <disp8> ]
        <segment register> : [ R13 + <ss> + <disp32> ]
        
        <segment register> : [ R14 + <ss> ]
        <segment register> : [ R15 + <ss> ]
        
        
        <segment register> : [ RAX + <ss> ]
        <segment register> : [ RCX + <ss> ]
        <segment register> : [ RDX + <ss> ]
        <segment register> : [ RBX + <ss> ]
        <segment register> : [ RSP + <ss> ]
        
        <segment register> : [ <ss> + <disp32> ]
        <segment register> : [ RBP + <ss> + <disp8> ]
        <segment register> : [ RBP + <ss> + <disp32> ]
        
        <segment register> : [ RSI + <ss> ]
        <segment register> : [ RDI + <ss> ]
        
        
        
        <segment register> : [ R8D + <ss> ]
        <segment register> : [ R9D + <ss> ]
        <segment register> : [ R10D + <ss> ]
        <segment register> : [ R11D + <ss> ]
        <segment register> : [ R12D + <ss> ]
        
        <segment register> : [ <ss> + <disp32> ]
        <segment register> : [ R13D + <ss> + <disp8> ]
        <segment register> : [ R13D + <ss> + <disp32> ]
        
        <segment register> : [ R14D + <ss> ]
        <segment register> : [ R15D + <ss> ]
        
        
        <segment register> : [ EAX + <ss> ]
        <segment register> : [ ECX + <ss> ]
        <segment register> : [ EDX + <ss> ]
        <segment register> : [ EBX + <ss> ]
        <segment register> : [ ESP + <ss> ]
        
        <segment register> : [ <ss> + <disp32> ]
        <segment register> : [ EBP + <ss> + <disp8> ]
        <segment register> : [ EBP + <ss> + <disp32> ]
        
        <segment register> : [ ESI + <ss> ]
        <segment register> : [ EDI + <ss> ]
        
        
        */
        
        
        
        
        
        /*
        MODRM grammars
        
        <segment register> : [ R8 ]
        <segment register> : [ R9 ]
        <segment register> : [ R10 ]
        <segment register> : [ R11 ]
        <segment register> : [ <sib> ]
        
        CS : [ RIP + <disp32> ] 
        <segment register> : [ <disp32> ]
        
        <segment register> : [ R14 ]
        <segment register> : [ R15 ]
        
        <segment register> : [ R8 + <disp8> ]
        <segment register> : [ R9 + <disp8> ]
        <segment register> : [ R10 + <disp8> ]
        <segment register> : [ R11 + <disp8> ]
        <segment register> : [ <sib> + <disp8> ]
        <segment register> : [ R13 + <disp8> ]
        <segment register> : [ R14 + <disp8> ]
        <segment register> : [ R15 + <disp8> ]
        
        <segment register> : [ R8 + <disp32> ]
        <segment register> : [ R9 + <disp32> ]
        <segment register> : [ R10 + <disp32> ]
        <segment register> : [ R11 + <disp32> ]
        <segment register> : [ <sib> + <disp32> ]
        <segment register> : [ R13 + <disp32> ]
        <segment register> : [ R14 + <disp32> ]
        <segment register> : [ R15 + <disp32> ]
        
        /////////////////////////////////////
        
        <segment register> : [ RAX ]
        <segment register> : [ RCX ]
        <segment register> : [ RDX ]
        <segment register> : [ RBX ]
        <segment register> : [ <sib> ]
        
        CS : [ RIP + <disp32> ] 
        <segment register> : [ <disp32> ]
        
        <segment register> : [ RSI ]
        <segment register> : [ RDI ]
        
        <segment register> : [ RAX + <disp8> ]
        <segment register> : [ RCX + <disp8> ]
        <segment register> : [ RDX + <disp8> ]
        <segment register> : [ RBX + <disp8> ]
        <segment register> : [ <sib> + <disp8> ]
        <segment register> : [ RBP + <disp8> ]
        <segment register> : [ RSI + <disp8> ]
        <segment register> : [ RDI + <disp8> ]
        
        <segment register> : [ RAX + <disp32> ]
        <segment register> : [ RCX + <disp32> ]
        <segment register> : [ RDX + <disp32> ]
        <segment register> : [ RBX + <disp32> ]
        <segment register> : [ <sib> + <disp32> ]
        <segment register> : [ RBP + <disp32> ]
        <segment register> : [ RSI + <disp32> ]
        <segment register> : [ RDI + <disp32> ]
        
        /////////////////////////////////////////////
        
        <segment register> : [ R8D ]
        <segment register> : [ R9D ]
        <segment register> : [ R10D ]
        <segment register> : [ R11D ]
        <segment register> : [ <sib> ]
        
        CS : [ EIP + <disp32> ]
        <segment register> : [ <disp32> ]
        
        <segment register> : [ R14D ]
        <segment register> : [ R15D ]
        
        <segment register> : [ R8D + <disp8> ]
        <segment register> : [ R9D + <disp8> ]
        <segment register> : [ R10D + <disp8> ]
        <segment register> : [ R11D + <disp8> ]
        <segment register> : [ <sib> + <disp8> ]
        <segment register> : [ R13D + <disp8> ]
        <segment register> : [ R14D + <disp8> ]
        <segment register> : [ R15D + <disp8> ]
        
        <segment register> : [ R8D + <disp32> ]
        <segment register> : [ R9D + <disp32> ]
        <segment register> : [ R10D + <disp32> ]
        <segment register> : [ R11D + <disp32> ]
        <segment register> : [ <sib> + <disp32> ]
        <segment register> : [ R13D + <disp32> ]
        <segment register> : [ R14D + <disp32> ]
        <segment register> : [ R15D + <disp32> ]
        
        /////////////////////////////////////////////
        
        <segment register> : [ EAX ]
        <segment register> : [ ECX ]
        <segment register> : [ EDX ]
        <segment register> : [ EBX ]
        <segment register> : [ <sib> ]
        
        CS : [ EIP + <disp32> ] 
        <segment register> : [ <disp32> ]
        
        <segment register> : [ ESI ]
        <segment register> : [ EDI ]
        
        <segment register> : [ EAX + <disp8> ]
        <segment register> : [ ECX + <disp8> ]
        <segment register> : [ EDX + <disp8> ]
        <segment register> : [ EBX + <disp8> ]
        <segment register> : [ <sib> + <disp8> ]
        <segment register> : [ EBP + <disp8> ]
        <segment register> : [ ESI + <disp8> ]
        <segment register> : [ EDI + <disp8> ]
        
        <segment register> : [ EAX + <disp32> ]
        <segment register> : [ ECX + <disp32> ]
        <segment register> : [ EDX + <disp32> ]
        <segment register> : [ EBX + <disp32> ]
        <segment register> : [ <sib> + <disp32> ]
        <segment register> : [ EBP + <disp32> ]
        <segment register> : [ ESI + <disp32> ]
        <segment register> : [ EDI + <disp32> ]
        
        ////////////////////////////////////////////
        
        <segment register> : [ BX + SI ]
        <segment register> : [ BX + DI ]
        <segment register> : [ BP + SI ]
        <segment register> : [ BP + DI ]
        <segment register> : [ SI ]
        <segment register> : [ DI ]
        <segment register> : [ <disp16> ]
        <segment register> : [ BX ]
        
        <segment register> : [ BX + SI + <disp8> ]
        <segment register> : [ BX + DI + <disp8> ]
        <segment register> : [ BP + SI + <disp8> ]
        <segment register> : [ BP + DI + <disp8> ]
        <segment register> : [ SI + <disp8> ]
        <segment register> : [ DI + <disp8> ]
        <segment register> : [ BP + <disp8> ]
        <segment register> : [ BX + <disp8> ]
        
        <segment register> : [ BX + SI + <disp16> ]
        <segment register> : [ BX + DI + <disp16> ]
        <segment register> : [ BP + SI + <disp16> ]
        <segment register> : [ BP + DI + <disp16> ]
        <segment register> : [ SI + <disp16> ]
        <segment register> : [ DI + <disp16> ]
        <segment register> : [ BP + <disp16> ]
        <segment register> : [ BX + <disp16> ]
        
        
        */
        
		memory_index state_mem_size = Megabytes(16);
		void * state_memory = VirtualAlloc(0, state_mem_size, MEM_RESERVE|MEM_COMMIT, PAGE_READWRITE);
		
        //NOTE(Alex): These will serve as our controlled buffered I/O decoder. 
        
		
        //TODO(Alex): Output code using RVA addresses, since are the ones the loader will use relative to the base of image
        //once you solve RVA's you have the 'REAl' structure of the image file loaded onto memory and you could dissect relative instruction offsets 
        //to other sections and offsets.
		
		u32 BranchHintVarCount = 0;
		disasm_state * State = (disasm_state*)state_memory;
		b32 Valid_Stream = false;
		
		if(state_memory && state_mem_size > 0)
		{
			if(!State->IsInitialized)
			{
				InitializeArena(&State->arena, (char*)state_memory + sizeof(disasm_state), state_mem_size - sizeof(disasm_state));
				SubArena(&State->arena, &State->i_write_arena, Megabytes(2));				
				SubArena(&State->arena, &State->i_match_arena, Megabytes(2));				
				
				
				State->start = (uint8_t*)GetFilePtrFromImageBase(&PEManager, TextHeader->PointerToRawData);;
				State->cursor = State->start;
				State->end = State->start + (TextHeader->SizeOfRawData);


				State->STDOutHandle = STDOutHandle;
				State->ProcessorMode = u_pro_mode;
				//TODO(Alex): test memory size, if buffer size bigger? low down buffer size?
				State->i_buffer.buffer = PushArray(&State->i_match_arena.Arena, MAX_I_BITS_BUFFER, instruction_bits);	
				if(State->i_buffer.buffer)
				{
					State->i_buffer.count = MAX_I_BITS_BUFFER;
					State->IsInitialized = true;
				}
				
			}
			
			if(!State->TablesInitialized)
			{	
				State->FilePtrBase = tables_memory;
				ReadInstructionTableInfo(State, &State->InstructionTableInfo);
				
				switch(State->ProcessorMode)
				{
					case ProcessorMode_16bit:
					{
						State->BitsCount = State->InstructionTableInfo.BitsCount_16;
						State->InstructionCount = State->InstructionTableInfo.InstructionCount_16;
						State->i_bits_header_offset = State->InstructionTableInfo.i_bits_header_offset_16;
						State->i_bits_bits_offset = State->InstructionTableInfo.i_bits_bits_offset_16;
						State->InstructionInfosOffset = State->InstructionTableInfo.InstructionInfosOffset_16;
					}break;
					
					case ProcessorMode_32bit:
					{
						State->BitsCount = State->InstructionTableInfo.BitsCount_32;
						State->InstructionCount = State->InstructionTableInfo.InstructionCount_32;
						State->i_bits_header_offset = State->InstructionTableInfo.i_bits_header_offset_32;
						State->i_bits_bits_offset = State->InstructionTableInfo.i_bits_bits_offset_32;
						State->InstructionInfosOffset = State->InstructionTableInfo.InstructionInfosOffset_32;
					}break;
					
					case ProcessorMode_64bit:
					{
						State->BitsCount = State->InstructionTableInfo.BitsCount_64;
						State->InstructionCount = State->InstructionTableInfo.InstructionCount_64;
						State->i_bits_header_offset = State->InstructionTableInfo.i_bits_header_offset_64;
						State->i_bits_bits_offset = State->InstructionTableInfo.i_bits_bits_offset_64;
						State->InstructionInfosOffset = State->InstructionTableInfo.InstructionInfosOffset_64;
					}break;
					
					InvalidDefaultCase;
				}
				
				State->TablesInitialized = true;
			}		
			
			//NOTE(Alex): With this way of doing it the processor uses the same cacheline for comparing sourcebits and destbits making it fast
			Valid_Stream = (State->IsInitialized && State->TablesInitialized);
        }
		
		
        u32 DFlag = 1;
        u32 BFlag = 1;
        
        u32 DefaultOperandSize = operandsize_Invalid;
        u32 DefaultAdressSize = addresssize_Invalid;
        u32 DefaultStackAddressSize = addresssize_Invalid;
        
        DefaultSizeAttributesForProcessorModes(State->ProcessorMode, BFlag, &DefaultOperandSize, &DefaultAdressSize, &DefaultStackAddressSize);
        memory_index TextVAddress = PEManager.OptHeader.ImageBase + TextHeader->VirtualAddress;
		
		while(Valid_Stream && (State->cursor <= State->end))
		{
			
			/*
			
   NOTE(Alex): the disassembler instruction fetcher can serve different ways, but ideally, 
   the thing we want to match against are the values,(therefore the datastructure) array of bits
   
   So I have i write cursor and a read cursor, so the buffer has to be relatively huge to work.
   
   If the read index inside the working buffer is close to end the write index inside the working buffer starts reading from file and adding them on the beginning of the buffer with new instructions, so the reading starting position will be always 0, and you have the last element count that fits properly.   
   
   so this works to find the instruction and to have the read an write synchronized! which is good!, but this doesnt respect the idea of having a priority queue or something like that,
   
   no it's ok, because once you find the match you could just reset the stream, by other thread while the instruction its being decoded, so that its filled with the hot instructions!
   
   So this is great because this synchronizes reads and writes, so reads dont have to have for writes. And since instructions are going to be ordered startig from hottest that's the best optimization you can do!
   
   There's a caveat, what happens if the read cursor reaches the write cursor? How do we know? well i need to finetune them, and have a semaphore synchronization process!  
   
   //SPECIFICATIONS - so when do yu want to read from file ??
   
   when initializing/resetting the bitbuffer and when the read index is getting at top of the buffer, those are the two signaling options.
   
   we have 4 files - 
   
   - The EXE file
   - The encodings file
   
   - The InstructionInfo File
   - The AssemblyGrammar File
   
   - STDOUT File
   
   the encodings file is going to be always in memory, so we can easily read from it!
   
   the EXE file can be huge and as is it cannot be read the whole thing at once! - so we need a streaming process for it., also, we need a way to have it the most of it in meemory so we can just be reading it!
   
   the instructionInfo and the assembly grammar they are the least necessary to be efficient so that we could just make the reads on a decent amount of time without any fancy mechanic.
   
   the STDOUT file has to be really efficient on displaying the data.  
   
   So ideally I have 3 threads - 
   
   - the first thread is the writer
   - the second thread is the reader
   - the third thread  is the disasembler
   
   The first and second thread work in symbiosis making it the most efficient, read write thing you could try
   
   The third thread waits for the reader to give him instruction results (in can be more than one!) - Note: this is a semaphore!
   
   
   --------------------------------------
   
   decoder that its going to receive as input the encoding tables - file pointer 
   and a buffer of instruction bytes, and its going to return a data structure with the assembly grammar and the instrucion_info for the instructions found, forget about the module and first see the whole thing working as the way i have it right now! , forget about threading just one thread reading the tables and returning the data structure, that's it! 
   
   */
			
			//TODO(Alex): Make sure State->baseframe  always starts on a new instruction 
			State->baseframe = State->cursor;
			State->SecureByteCount = 0;
			
			//TODO(Alex): do we want a temp memory buffer? here
			bits_array_  BitsArray_ = {};
			instruction_info_ InstructionInfoEntry = {};
			instruction_info_ InstructionInfo_ = {};
			
			instruction_context ctx = {};
			init_instruction_context(&ctx,  &InstructionInfo_, &BitsArray_);
			
			if(TextVAddress == 5368723351)
			{
				int x = 5;
			}
			
			
			//NOTE(Alex): There's some instructions that need rex prefix but, they are not encoded on the opcode id's therefore those opcodes won't get a hit.
			//and they will pass on to the more granular system of prefixing which grabs one byte at a time, which is ok, since we only care for grabbing the bits as we can!
			
			do                
			{
				
				ReadWorkingBuffer(State, &ctx);
				
				if(!ctx.InstructionFound)
				{
					
					//NOTE(Alex): REPE/REPZ and REPNE/REPNZ prefixes are used only with the CMPS and SCAS 
					// A segment-override prefix allows the ESI register to be associated with the CS, SS, ES, FS, or GS segment register
					// No segment override is allowed for the EDI register.
					
					//REP prefixes are allowed by 64-bit instructions
					
					//REP — Repeat while the ECX register not zero.
					//REPE/REPZ — Repeat while the ECX register not zero and the ZF flag is set.
					//REPNE/REPNZ — Repeat while the ECX register not zero and the ZF flag is clear.
					
					//REX prefixes are silently ignored on I/O Instructions in 64-Bit Mode.
					
					// The LOCK prefix can be prepended only to the following instructions and only to those forms of the instructions
					// where the destination operand is a memory operand: 
					//ADD, ADC, AND, BTC, BTR, BTS, CMPXCHG, CMPXCH8B, CMPXCHG16B, DEC, INC, NEG, NOT, OR, SBB, SUB, XOR, XADD, and XCHG.
					
					u64 Value = peekBits_noconsume_msb(State, 8);
					
					if(ctx.rex.value)
					{
						Assert(!"Invalid legacy prefix after rex prefix");
					}
					
					if(ByteIsPrefix(Value))
					{
						switch(Value)
						{
							case LockPrefix:
							{
								ctx.Group1Prefix = group1_LockPrefix;
							}break;
							
#if 0
							case BND:
							{
								
							};
#endif
							
							case REPNE_REPNZ:
							{
								ctx.Group1Prefix = group1_REPNE_REPNZ;
							}break;
							
							case REP_REPE:
							{
								ctx.Group1Prefix = group1_REP_REPE;
							}break;
							
							case OperandSizeOverridePrefix:
							{
								ctx.OperandSizeOverridePrefixPresent = true;
							}break;
							
							case AddressSizeOverridePrefix:
							{
								ctx.AddressSizeOverridePrefixPresent = true;
							}break;
							
							
							//Group 2 prefixes
							case CSOverride:
							{
								ctx.Group2Prefix = group2_CSOverride;
							}break;
							
							case SSOverride:
							{
								ctx.Group2Prefix = group2_SSOverride;
							}break;
							
							case DSOverride:
							{
								ctx.Group2Prefix = group2_DSOverride;
							}break;
							
							case ESOverride:
							{
								ctx.Group2Prefix = group2_ESOverride;
							}break;
							
							case FSOverride:
							{
								ctx.Group2Prefix = group2_FSOverride;
							}break;
							
							case GSOverride:
							{
								ctx.Group2Prefix = group2_GSOverride;
							}break;
							
							InvalidDefaultCase;
						}
						
						consumeBits_msb(State, 8);
						++State->SecureByteCount;
					}
					
					else if((State->ProcessorMode == ProcessorMode_64bit) && (REXPresent(State->ProcessorMode, Value)))
					{
						consumeBits_msb(State, 8);
						++State->SecureByteCount;
						ctx.rex.value = Value;
					}
					
					else
					{
						Valid_Stream = false;
					}
				}
			}
			while(!ctx.InstructionFound && Valid_Stream);
			
			temp_memory temp_mem = BeginTempMemory(&State->i_write_arena.Arena);
			
			if(ctx.InstructionFound)
			{
				
				//TODO(Alex): Do we want disassembler to work in chunks?
				
				u32 string_mem_size = Kilobytes(32);
				string o_buff = {};
				make_string_size(&State->i_write_arena.Arena, &o_buff, 0, string_mem_size);					
				
				instruction_info_ * InstructionInfo = ctx.i_info;
				bits_array_ * BitsArray = ctx.BitsArrayPtr;
				
				bits low_rex = get_bitfield_from_bitsarray_bytype(BitsArray, BitfieldType_low_rex);
				if(low_rex.bits_count)
				{
					ctx.rex = concat_bits(Bits(4, 0x4) , low_rex);
				}
				
				eff_operand_size EffOperandSize = (eff_operand_size)GetEffOperandSize(State->ProcessorMode, DefaultOperandSize, &ctx);
				eff_address_size EffAddressSize = (eff_address_size)GetEffAddressSize(State->ProcessorMode, DefaultAdressSize, &ctx);
				
				
				if(InstructionInfo->Type == InstructionType_Group)
				{
					eff_operand_size OperandSize = (eff_operand_size)EffOperandSize;					
					Assert(InstructionInfo->OperandCount = 1);
					get_eff_operand_size(State, State->ProcessorMode, &ctx, 0, &OperandSize, EffAddressSize);
					GetGrammarEntryInGroup(State, &InstructionInfoEntry, InstructionInfo, OperandSize);
					InstructionInfo = &InstructionInfoEntry;
				}
				
				
				switch(ctx.Group1Prefix)
				{
					case group1_LockPrefix:
					{
						if(InstructionInfo->LOCK_Valid)
						{
							bits mod_ = get_bitfield_from_bitsarray_bytype(BitsArray, BitfieldType_mod);
							if(mod_.bits_count && (mod_.value < 0b11))
							{
								Append(&o_buff, "LOCK ");
							}
							else
							{
								Assert(!"Invalid Lock Prefix");
							}
						}
						else
						{
							Assert(!"Invalid Lock Prefix");
						}
					}break;
					
					case group1_REP_REPE:
					{
						if(InstructionInfo->REP_Valid)
						{
							Append(&o_buff, "REP ");
						}
					}break;
					
					case group1_REPNE_REPNZ:
					{
						if(InstructionInfo->REP_Valid)
						{		
							Append(&o_buff, "REPNE ");
						}
					}
				}
				
				switch(ctx.Group2Prefix)
				{
					case group2_Branchtaken:
					{
						if(InstructionInfo->BranchHint_Valid)
						{
							
							u32 VarStrMemSize = (1 << 8);
							string VarStr = {}; 	
							make_string_size(&State->i_write_arena.Arena, &VarStr, 0, VarStrMemSize);
							ConvertU32ToASCHexString(VarStr.buffer, &VarStr.count, VarStr.mem_size, BranchHintVarCount, sizeof(BranchHintVarCount), false);

							Append(&o_buff, "branch_hint_ ");
							Append(&o_buff, &VarStr);
							Append(&o_buff, " db 0x3E\n");

						}
					}break;
					case group2_BranchNotTaken:
					{
						if(InstructionInfo->BranchHint_Valid)
						{
					
							u32 VarStrMemSize = (1 << 8);
							string VarStr = {}; 	
							make_string_size(&State->i_write_arena.Arena, &VarStr, 0, VarStrMemSize);
							ConvertU32ToASCHexString(VarStr.buffer, &VarStr.count, VarStr.mem_size, BranchHintVarCount, sizeof(BranchHintVarCount), false);
							
							Append(&o_buff, "branch_hint_ ");
							Append(&o_buff, &VarStr);
							Append(&o_buff, " db 0x2E\n");
							
						}
					}break;
					
					
				}				
				
				//TODO(Alex): Here we are not using rex bitfield inside opcode ids in 64 bit mode.

				//NOTE(Alex): This finds the first token with these regexp in the string. 
				//FindToken(&RegExpSupport, AssemblyGrammar, StringLength(AssemblyGrammar), &MnemonicToken, "[A-Z]*", StringLength("[A-Z]*"));
				//Append(o_buff.buffer, &o_buff.Count, MAX_BUFFER_SIZE, MnemonicToken.Base, MnemonicToken.Count);
								
#if NEW_EAGLEFLY_API
				//TODO(Alex): IMPORTANT(Alex): This is what we want from the grammar parser
				//TODO(Alex): forget about grammars, just give me the codes and i will print them out!
				
				//TODO(Alex): Add instruction legnth to TextVAddress;
				Append(&o_buff, InstructionInfo->MnemonicBuffer, InstructionInfo->MnemonicCount);				
				
				u32 addr_mode_mem_size = (1 << 8);
				string addr_mode = {}; 	
				make_string_size(&State->i_write_arena.Arena, &addr_mode, 0, addr_mode_mem_size);
				bits rex = ctx.rex;
				
				for(u32 Index = 0;
					Index < InstructionInfo->OperandCount;
					++Index)
				{
					Append(&o_buff, SpaceString, SpaceStringLength);
					//NOTE(Alex): we reuse the same buffer for each operand grammar, 
					addr_mode.count = 0;
					
					eff_operand_size OperandSize_ = (eff_operand_size)EffOperandSize;
					get_eff_operand_size(State, State->ProcessorMode, &ctx, Index, &OperandSize_, EffAddressSize);
					
					u32 operand_size_num = cvt_eff_operand_size_to_num(OperandSize_);
					
					group2_prefix Group2Prefix = ctx.Group2Prefix;
					operand_type * Type = InstructionInfo->OperandTypes + Index;
					switch(*Type)
					{
						
						case OperandType_J:
						{
							u32 mem_size = 1024;
							string t_buff = {};							
							make_string_size(&State->i_write_arena.Arena, &t_buff, 0, mem_size);
							
							bits Immediate = Zeroes(operand_size_num);
							Immediate.value = GetBits_msb(State, Immediate.bits_count);
							Immediate = SwapBitfieldBytes(Immediate);
							
							ConvertBitfieldToStringSize(&t_buff, operand_size_num, Immediate.value, Immediate.bits_count);
							Append(&o_buff, t_buff.buffer, t_buff.count);
							
						}break;
						
						case OperandType_O:
						{
							
							u32 mem_size = 1024;
							string s_selector_s = {};
							string u_offset_s = {};
							
							make_string_size(&State->i_write_arena.Arena, &s_selector_s, 0, mem_size);
							make_string_size(&State->i_write_arena.Arena, &u_offset_s, 0, mem_size);
							
							bits u_offset = Zeroes(EffAddressSize);
							u_offset.value = GetBits_msb(State, u_offset.bits_count);
							u_offset = SwapBitfieldBytes(u_offset);
							
							ConvertBitsToString(&u_offset_s, &u_offset);
							
							
							u32 op_mem_size =  (1 << 8);
							string op_size_kw_s = {};
							make_string_size(&State->i_write_arena.Arena, &op_size_kw_s, 0, op_mem_size);
							
							get_mem_operand_size_kw_masm(State, OperandSize_, &op_size_kw_s);
							Append(&o_buff, &op_size_kw_s);
							
							//append_mem_operand_size_kw_masm(&o_buff, OperandSize_);
							Append(&o_buff, " ptr ");
							
							if(Group2Prefix > group2_Invalid)
							{
								append_segment_reg_masm(Group2Prefix, &o_buff);
							}
							else
							{
								Append(&o_buff, "DS");
							}
							
							Append(&o_buff, " : [ ");
							Append(&o_buff, u_offset_s.buffer, u_offset_s.count);
							Append(&o_buff, " ]");
							
						}break;
						
						case OperandType_A:
						{
							
							
							u32 mem_size = 1024;
							string s_selector_s = {};
							string u_offset_s = {};
							
							make_string_size(&State->i_write_arena.Arena, &s_selector_s, 0, mem_size);
							make_string_size(&State->i_write_arena.Arena, &u_offset_s, 0, mem_size);
							
							
							bits u_offset = {};
							bits s_selector = Zeroes(16);
							
							u_offset.bits_count = operand_size_num - s_selector.bits_count;
							
							u_offset.value = GetBits_msb(State, u_offset.bits_count);
							s_selector.value = GetBits_msb(State, s_selector.bits_count);
							
							u_offset = SwapBitfieldBytes(u_offset);
							s_selector = SwapBitfieldBytes(s_selector);
							
							ConvertBitsToString(&s_selector_s, &s_selector);
							ConvertBitsToString(&u_offset_s, &u_offset);
							
							Append(&o_buff, s_selector_s.buffer, s_selector_s.count);
							Append(&o_buff, " : ");
							Append(&o_buff, u_offset_s.buffer, u_offset_s.count);
							
							
						}break;
						
						
						case OperandType_BA:
						{
							//NOTE(Alex):  The address is DS:RAX/EAX/AX. Segment overrides can be used.
							
							u32 op_mem_size =  (1 << 8);
							string op_size_kw_s = {};
							make_string_size(&State->i_write_arena.Arena, &op_size_kw_s, 0, op_mem_size);
							
							get_mem_operand_size_kw_masm(State, OperandSize_, &op_size_kw_s);
							Append(&o_buff, &op_size_kw_s);
							
							//append_mem_operand_size_kw_masm(&o_buff, OperandSize_);
							Append(&o_buff, " ptr ");
							
							if(Group2Prefix > group2_Invalid)
							{
								append_segment_reg_masm(Group2Prefix, &o_buff);
							}
							else
							{
								Append(&o_buff, "DS");
							}
							
							Append(&o_buff, " : [ ");
							GetrAX64Reg(o_buff.buffer, &o_buff.count, o_buff.mem_size, EffAddressSize);
							Append(&o_buff, " ]");	
							
						}break;
						
						case OperandType_BB:
						{
							//Set AL to memory byte DS:[(E)BX + unsigned AL].
							Assert(!"Only XLAT instrucion uses this operand_type as explicit operand but we use implicit operand mnemonic XLATB");
						}break;
						
						
						case OperandType_BD:
						{
							
							//" The default memory location is specified by DS:DI/EDI/RDI.  (the default segment register is DS, but this may be overridden with a segment-override prefix).
							Assert(!"only 0FF7 MASKMOVQ and 660FF7 MASKMOVDQU uses it as implicit memory operand");
						}break;
						
						case OperandType_C:
						{
							
							//The reg field of the ModR/M byte selects a control register (only MOV (0F20, 0F22)).
							
							bits Bits = get_bitfield_from_bitsarray_bytype(BitsArray, BitfieldType_eee);
							Assert(Bits.bits_count);
							append_bitfield_crs(&o_buff, SafeTruncateU64ToU32(Bits.value));
							
						}break;
						
						case OperandType_D:
						{
							
							bits Bits = get_bitfield_from_bitsarray_bytype(BitsArray, BitfieldType_eee);
							Assert(Bits.bits_count);
							append_bitfield_drs(&o_buff, SafeTruncateU64ToU32(Bits.value));
							
						}break;
						
						case OperandType_E:
						{
							//NOTE(Alex): Go for modrm byte
							
							bits mod = get_bitfield_from_bitsarray_bytype(BitsArray, BitfieldType_mod);
							bits rm = get_bitfield_from_bitsarray_bytype(BitsArray, BitfieldType_rm);
							
							b32 look_rex_r = false;
							get_gp_addressing_mode(State, State->ProcessorMode, OperandSize_, EffAddressSize, mod.value, rm.value, rex, look_rex_r, &addr_mode);
							write_addressing_mode_from_grammar(State, State->ProcessorMode, &ctx, OperandSize_, EffAddressSize, o_buff.buffer, &o_buff.count, o_buff.mem_size, addr_mode.buffer, addr_mode.count, mod.value, rm.value);
							
						}break;
						
						case OperandType_ES:
						{
							//(Implies original E). A ModR/M byte follows the opcode and specifies the operand. The operand is either a x87 FPU stack register or a memory address. If it is a memory address, the address is computed from a segment register and any of the following values: a base register, an index register, a scaling factor, or a displacement.
							//GetAdressingMode(State, ProcessorMode, OperandSize, EffAddressSize, Group2Prefix, o_buff.Buffer, &o_buff.Count, MAX_BUFFER_SIZE, &BitsArray, rex);								
							
							//TODO(Alex): Check that memory addressing can only be done with general purpose registers!								
							bits mod = get_bitfield_from_bitsarray_bytype(BitsArray, BitfieldType_mod);
							bits rm = get_bitfield_from_bitsarray_bytype(BitsArray, BitfieldType_rm);
							
							b32 look_rex_r = false;
							get_fp_addressing_mode(State, EffAddressSize, rex, look_rex_r, mod.value, rm.value, &addr_mode);
							
							write_addressing_mode_from_grammar(State, State->ProcessorMode, &ctx, OperandSize_, EffAddressSize, o_buff.buffer, &o_buff.count, o_buff.mem_size, addr_mode.buffer, addr_mode.count, mod.value, rm.value);
							
						}break;
						
						case OperandType_EST:
						{
							//(Implies original E). A ModR/M byte follows the opcode and specifies the x87 FPU stack register.
							bits rm = get_bitfield_from_bitsarray_bytype(BitsArray, BitfieldType_rm);
							
							b32 look_rex_r = false;
							read_reg_fp_table(State, rm.value, &addr_mode); 							
							Append(&o_buff, &addr_mode);							
							
						}break;
						
						
						case OperandType_F:
						{
							Assert(!"No instruction with explicit rFLAGS register");
						}break;
						
						
						case OperandType_G:
						{
							bits reg = get_bitfield_from_bitsarray_bytype(BitsArray, BitfieldType_reg);
							b32 look_rex_r = true;
							ReadRegTable(State, OperandSize_, rex, reg.value, look_rex_r, &addr_mode);
							Append(&o_buff, addr_mode.buffer, addr_mode.count);
						}break;
						
						
						case OperandType_H:
						{
							//The r/m field of the ModR/M byte always selects a general register, regardless of the mod field (for example, MOV (0F20)).
							bits rm = get_bitfield_from_bitsarray_bytype(BitsArray, BitfieldType_rm);
							b32 look_rex_r = false;
							ReadRegTable(State, OperandSize_, rex, rm.value, look_rex_r, &addr_mode);
							Append(&o_buff, addr_mode.buffer, addr_mode.count);
							
						}break;
						
						case OperandType_I:
						{
							
							//Immediate data. The operand value is encoded in subsequent bytes of the instruction.
							u32 mem_size = 1024;
							string t_buff = {};
							make_string_size(&State->i_write_arena.Arena, &t_buff, 0, mem_size);
							
							bits Immediate = Zeroes(operand_size_num);
							Immediate.value = GetBits_msb(State, Immediate.bits_count);
							Immediate = SwapBitfieldBytes(Immediate);
							
							ConvertBitsToString(&t_buff, &Immediate);
							Append(&o_buff, t_buff.buffer, t_buff.count);
							
						}break;
						
						case OperandType_M:
						{
							
							//The ModR/M byte may refer only to memory: mod != 11bin (BOUND, LEA, CALLF, JMPF, LES, LDS, LSS, LFS, LGS, CMPXCHG8B, CMPXCHG16B, F20FF0 LDDQU).                                
							bits mod = get_bitfield_from_bitsarray_bytype(BitsArray, BitfieldType_mod);
							bits rm = get_bitfield_from_bitsarray_bytype(BitsArray, BitfieldType_rm);
							
							if(mod.value == 0b11)
							{
								//TODO(Alex): Logging or make those operands data!
								Assert(!"Illegal memory instruction, accesing register pagefile");
							}
							
							
							b32 look_rex_r = false;
							get_gp_addressing_mode(State, State->ProcessorMode, OperandSize_, EffAddressSize, mod.value, rm.value, rex, look_rex_r, &addr_mode);
							write_addressing_mode_from_grammar(State, State->ProcessorMode, &ctx, OperandSize_, EffAddressSize, o_buff.buffer, &o_buff.count, o_buff.mem_size, addr_mode.buffer, addr_mode.count, mod.value, rm.value);
							
							
						}break;
						
						case OperandType_N:
						{
							
							//The R/M field of the ModR/M byte selects a packed quadword MMX technology register.
							
							bits mod = get_bitfield_from_bitsarray_bytype(BitsArray, BitfieldType_mod);
							bits rm = get_bitfield_from_bitsarray_bytype(BitsArray, BitfieldType_rm);
							
							Assert(mod.value == 0b11);								
							
							b32 look_rex_r = false;
							get_mmx_addressing_mode(State, EffAddressSize, rex, look_rex_r, mod.value, rm.value, &addr_mode);
							write_addressing_mode_from_grammar(State, State->ProcessorMode, &ctx, OperandSize_, EffAddressSize, o_buff.buffer, &o_buff.count, o_buff.mem_size, addr_mode.buffer, addr_mode.count, mod.value, rm.value);
							
						}break;
						
						case OperandType_P:
						{
							//The reg field of the ModR/M byte selects a packed quadword MMX technology register.
							bits reg = get_bitfield_from_bitsarray_bytype(BitsArray, BitfieldType_reg);
							b32 look_rex_r = true;
							
							read_reg_mmx_table(State, reg.value, &addr_mode);
							Append(&o_buff, addr_mode.buffer, addr_mode.count);
							
						}break;
						
						
						case OperandType_Q:
						{
							//A ModR/M byte follows the opcode and specifies the operand. The operand is either an MMX technology register or a memory address. If it is a memory address, the address is computed from a segment register and any of the following values: a base register, an index register, a scaling factor, and a displacement.
							bits mod = get_bitfield_from_bitsarray_bytype(BitsArray, BitfieldType_mod);
							bits rm = get_bitfield_from_bitsarray_bytype(BitsArray, BitfieldType_rm);
							
							b32 look_rex_r = false;
							get_mmx_addressing_mode(State, EffAddressSize, rex, look_rex_r, mod.value, rm.value, &addr_mode);
							write_addressing_mode_from_grammar(State, State->ProcessorMode, &ctx, OperandSize_, EffAddressSize, o_buff.buffer, &o_buff.count, o_buff.mem_size, addr_mode.buffer, addr_mode.count, mod.value, rm.value);
							
						}break;
						
						
						case OperandType_R:
						{
							//The mod field of the ModR/M byte may refer only to a general register (only MOV (0F20-0F24, 0F26)).
							
							bits mod = get_bitfield_from_bitsarray_bytype(BitsArray, BitfieldType_mod);
							bits rm = get_bitfield_from_bitsarray_bytype(BitsArray, BitfieldType_rm);
							
							Assert(mod.value == 0b11);							
							
							b32 look_rex_r = false;
							get_gp_addressing_mode(State, State->ProcessorMode, OperandSize_, EffAddressSize, mod.value, rm.value, rex, look_rex_r, &addr_mode);
							write_addressing_mode_from_grammar(State, State->ProcessorMode, &ctx, OperandSize_, EffAddressSize, o_buff.buffer, &o_buff.count, o_buff.mem_size, addr_mode.buffer, addr_mode.count, mod.value, rm.value);
							
						}break;
						
						
						case OperandType_S:
						{
							//The reg field of the ModR/M byte selects a segment register (only MOV (8C, 8E)).
							bits reg = get_bitfield_from_bitsarray_bytype(BitsArray, BitfieldType_reg);
							get_sreg_reg(State, SafeTruncateU64ToU32(reg.value), &addr_mode);							
							Append(&o_buff, addr_mode.buffer, addr_mode.count);
							
						}break;
						
						case OperandType_SC:
						{
							//Stack operand, used by instructions which either push an operand to the stack or pop an operand from the stack. Pop-like instructions are, for example, POP, RET, IRET, LEAVE. Push-like are, for example, PUSH, CALL, INT. No Operand type is provided along with this method because it depends on source/destination operand(s).
							Assert(!"No explicit stack operand!");
						}break;
						
						case OperandType_T:
						{
							//The reg field of the ModR/M byte selects a test register (only MOV (0F24, 0F26)).
							bits reg = get_bitfield_from_bitsarray_bytype(BitsArray, BitfieldType_reg);
							b32 look_rex_r = true;
							get_treg_reg(State, SafeTruncateU64ToU32(reg.value), &addr_mode);							
							Append(&o_buff, addr_mode.buffer, addr_mode.count);
							
						}break;
						
						case OperandType_U:
						{
							//The R/M field of the ModR/M byte selects a 128-bit XMM register.
							
							bits mod = get_bitfield_from_bitsarray_bytype(BitsArray, BitfieldType_mod);
							bits rm = get_bitfield_from_bitsarray_bytype(BitsArray, BitfieldType_rm);
							
							Assert(mod.value == 0b11);							
							
							b32 look_rex_r = false;
							read_xmm_table(State, rex, SafeTruncateU64ToU32(rm.value), look_rex_r, &addr_mode); 
							Append(&o_buff, addr_mode.buffer, addr_mode.count);
							
							
						}break;
						
						
						case OperandType_V:
						{
							//The reg field of the ModR/M byte selects a 128-bit XMM register.
							bits reg = get_bitfield_from_bitsarray_bytype(BitsArray, BitfieldType_reg);
							b32 look_rex_r = true;
							read_xmm_table(State, rex, SafeTruncateU64ToU32(reg.value), look_rex_r, &addr_mode);							
							Append(&o_buff, addr_mode.buffer, addr_mode.count);
							
						}break;
						
						
						case OperandType_W:
						{
							//A ModR/M byte follows the opcode and specifies the operand. The operand is either a 128-bit XMM register or a memory address. If it is a memory address, the address is computed from a segment register and any of the following values: a base register, an index register, a scaling factor, and a displacement
							
							bits mod = get_bitfield_from_bitsarray_bytype(BitsArray, BitfieldType_mod);
							bits rm = get_bitfield_from_bitsarray_bytype(BitsArray, BitfieldType_rm);
							
							b32 look_rex_r = false;
							get_xmm_addressing_mode(State, State->ProcessorMode, EffAddressSize, SafeTruncateU64ToU32(mod.value), SafeTruncateU64ToU32(rm.value), rex, look_rex_r, &addr_mode);
							write_addressing_mode_from_grammar(State, State->ProcessorMode, &ctx, OperandSize_, EffAddressSize, o_buff.buffer, &o_buff.count, o_buff.mem_size, addr_mode.buffer, addr_mode.count, mod.value, rm.value);
							
						}break;
						
						case OperandType_X:
						{
							//Memory addressed by the DS:eSI or by RSI (only MOVS, CMPS, OUTS, and LODS). In 64-bit mode, only 64-bit (RSI) and 32-bit (ESI) address sizes are supported. In non-64-bit modes, only 32-bit (ESI) and 16-bit (SI) address sizes are supported.
							Assert(!"No instruction with Explicit DS:eSI operand");
						}break;
						
						
						case OperandType_Y:
						{
							//Memory addressed by the ES:eDI or by RDI (only MOVS, CMPS, INS, STOS, and SCAS). In 64-bit mode, only 64-bit (RDI) and 32-bit (EDI) address sizes are supported. In non-64-bit modes, only 32-bit (EDI) and 16-bit (DI) address sizes are supported. The implicit ES segment register cannot be overriden by a segment prefix.
							Assert(!"No instruction with Explicit ES:eDI operand");
						}break;
						
						
						case OperandType_Z:
						{
							//The instruction has no ModR/M byte; the three least-significant bits of the opcode byte selects a general-purpose register
							bits reg = get_bitfield_from_bitsarray_bytype(BitsArray, BitfieldType_reg);
							b32 look_rex_r = false;
							ReadRegTable(State, OperandSize_, rex, reg.value, look_rex_r, &addr_mode);
							Append(&o_buff, addr_mode.buffer, addr_mode.count);
						}break;

						case OperandType_3:    
						{
							Append(&o_buff, "3");
						}break;
						
						case OperandType_1:    
						{
							Append(&o_buff, "1");
						}break;
						
						case OperandType_GSEG:
						{
							Append(&o_buff, "GS");
						}break;
						case OperandType_FSEG:
						{
							Append(&o_buff, "FS");
						}break;
						case OperandType_ESEG:
						{
							Append(&o_buff, "ES");
						}break;
						case OperandType_DSEG:
						{
							Append(&o_buff, "DS");
						}break;
						case OperandType_SSEG:
						{
							Append(&o_buff, "SS");
						}break;
						case OperandType_CSEG:
						{
							Append(&o_buff, "CS");
						}break;
						
				
						//NOTE(Alex): this is for Operand type rAX
						case OperandType_AX:
						{
							//GetrAX64Reg(o_buff.buffer, &o_buff.count, o_buff.mem_size, OperandSize);
							get_ax_reg_size(State, OperandSize_, &addr_mode);
							Append(&o_buff, addr_mode.buffer, addr_mode.count);
						}break;
						
						//NOTE(Alex): This are explicit registers
						
						case OperandType_CX:
						{
							get_cx_reg_size(State, OperandSize_, &addr_mode);
							Append(&o_buff, addr_mode.buffer, addr_mode.count);
						}break;
						
						case OperandType_DX:
						{
							get_dx_reg_size(State, OperandSize_, &addr_mode);
							Append(&o_buff, addr_mode.buffer, addr_mode.count);
						}break;
						
						
						case OperandType_ST:  
						{
							Append(&o_buff, "ST0");
						}break;
						
						InvalidDefaultCase;
					}
					
					if(Index < InstructionInfo->OperandCount - 1)
					{
						Append(&o_buff, CommaString, CommaStringLength);
					}
				}
				
				
				
				
				{		
					b32 s_extend = false;
					u32 PaddingSpace = 60;
					
					u32 ExtraSpace = PaddingSpace - o_buff.count;
					Assert(ExtraSpace >= 0);
					AddCharTimesAt(&o_buff, o_buff.buffer + o_buff.count, ' ', ExtraSpace);

					//Append(&o_buff, SpaceString, SpaceStringLength);
					Append(&o_buff, SemiColonString, SemiColonStrigLength);
					ConvertU64ToASCHexString(o_buff.buffer, &o_buff.count, o_buff.mem_size, TextVAddress, 64, s_extend);
					Append(&o_buff, SpaceString, SpaceStringLength);
					
					
					for(u8 * opcode_ptr = State->baseframe;
						opcode_ptr < State->cursor;
						++opcode_ptr)
					{
						ConvertU32ToASCHexString(o_buff.buffer, &o_buff.count, o_buff.mem_size, *opcode_ptr, 8, s_extend);
						Append(&o_buff, SpaceString, SpaceStringLength);
					}
					
					Append(&o_buff, EndOfFileString, EndOfFileStringLength);
					EagleflyWriteFile(State, o_buff.buffer, o_buff.count);
				}
#else
				
				u32 InstructionOperandSize = EffOperandSize;
				GetInstructionOperandSize(State, &InstructionInfo, &InstructionOperandSize);
				
				char LowerCaseInfo = {};
				regexp_token Token = {};
				
				regexp_support RegExpSupport = {};
				char * At = 0;
				
				
				//NOTE(Alex): Upper case letters
				if(InitRegExpSource(&RegExpSupport, AssemblyGrammar, StringLength(AssemblyGrammar), &At))
				{
					while(PtrInsideString(&RegExpSupport, At))
					{
						//NOTE(Alex): Conditional codes 
						if(StringIsEqualRegExp(&RegExpSupport, At, "<cc>", StringLength("<cc>")))
						{
							ConditionalCode(State, o_buff.Buffer, &o_buff.Count, MAX_BUFFER_SIZE, get_bitfield_from_bitsarray_bytype(&BitsArray , BitfieldType_tttn));
							AdvanceSourcePtr(&RegExpSupport, &At);
						}
						
						else if(StringIsEqualRegExp(&RegExpSupport, At, "<cxz>", StringLength("<cxz>")))
						{
							CXZ(State, o_buff.Buffer, &o_buff.Count, MAX_BUFFER_SIZE, EffAddressSize);
							AdvanceSourcePtr(&RegExpSupport, &At);
						}
						
						else if(StringIsEqualRegExp(&RegExpSupport, At, "<GPR_[0-9][0-9]>", StringLength("<GPR_[0-9][0-9]>"), &Token))
						{
							u32 Size = EffOperandSize;
							GetDataType(State, Token.Base, Token.Count, &Size, &LowerCaseInfo);
							CopyRegString(State, o_buff.Buffer, &o_buff.Count, MAX_BUFFER_SIZE, Size, rex, &BitsArray, false);
							AdvanceSourcePtr(&RegExpSupport, &At);
						}
						
						else if(StringIsEqualRegExp(&RegExpSupport, At, "<rAX_[0-9][0-9]>", StringLength("<rAX_[0-9][0-9]>"), &Token))
						{
							u32 Size = EffOperandSize;
							GetDataType(State, Token.Base, Token.Count, &Size, &LowerCaseInfo);
							GetrAX64Reg(o_buff.Buffer, &o_buff.Count, MAX_BUFFER_SIZE, Size);
							AdvanceSourcePtr(&RegExpSupport, &At);
						}
						
						else if(StringIsEqualRegExp(&RegExpSupport, At, "<J[a-z]>", StringLength("<J[a-z]>"), &Token))
						{
							u32 BranchDispBitCount = EffOperandSize; 
							GetDataType(State, Token.Base, Token.Count, &BranchDispBitCount, &LowerCaseInfo);
							if((LowerCaseInfo == 'z') || (LowerCaseInfo == 'b'))
							{
								u32 BufferCount = 0;
								char Buffer[MAX_BUFFER_SIZE] = {0};
								
								bits Immediate = Zeroes(BranchDispBitCount);
								Immediate.value = GetBits_msb(State, Immediate.bits_count);
								Immediate = SwapBitfieldBytes(Immediate);
								
								ConvertBitfieldToStringSize(Buffer, &BufferCount, MAX_BUFFER_SIZE, EffOperandSize, Immediate.value, Immediate.bits_count);
								
								Append(o_buff.Buffer, &o_buff.Count, MAX_BUFFER_SIZE, Buffer, BufferCount);
							}
							
							AdvanceSourcePtr(&RegExpSupport, &At);
						}
						
						else if(StringIsEqualRegExp(&RegExpSupport, At, "<I[a-z]>", StringLength("<I[a-z]>"), &Token))
						{
							u32 ImmediateOperandSize = EffOperandSize;
							GetDataType(State, Token.Base, Token.Count, &ImmediateOperandSize, &LowerCaseInfo);
							if((LowerCaseInfo == 'z') || (LowerCaseInfo == 'b') || (LowerCaseInfo == 'v'))
							{
								u32 BufferCount = 0;
								char Buffer[MAX_BUFFER_SIZE] = {0};
								
								bits Immediate = Zeroes(ImmediateOperandSize);
								Immediate.value = GetBits_msb(State, Immediate.bits_count);
								Immediate = SwapBitfieldBytes(Immediate);
								
								ConvertBitsToString(Buffer, &BufferCount, MAX_BUFFER_SIZE, Immediate);
								Append(o_buff.Buffer, &o_buff.Count, MAX_BUFFER_SIZE, Buffer, BufferCount);
							}
							
							AdvanceSourcePtr(&RegExpSupport, &At);
						}
						
						else if(StringIsEqualRegExp(&RegExpSupport, At, "<A[a-z]>", StringLength("<A[a-z]>"), &Token))
						{
							
							u32 ImmediateOperandSize = EffOperandSize;
							GetDataType(State, Token.Base, Token.Count, &ImmediateOperandSize, &LowerCaseInfo);
							if(LowerCaseInfo == 'p')
							{
								u32 SegmentSelectorBufferCount = 0;
								char SegmentSelectorBuffer[MAX_BUFFER_SIZE] = {0};
								u32 UnsignedOffsetBufferCount = 0;
								char UnsignedOffsetBuffer[MAX_BUFFER_SIZE] = {0};
								
								bits unsigned_offset = {};
								bits segment_selector = Zeroes(16);
								
								unsigned_offset.bits_count = ImmediateOperandSize - segment_selector.bits_count;
								
								unsigned_offset.value = GetBits_msb(State, unsigned_offset.bits_count);
								segment_selector.value = GetBits_msb(State, segment_selector.bits_count);
								
								unsigned_offset = SwapBitfieldBytes(unsigned_offset);
								segment_selector = SwapBitfieldBytes(segment_selector);
								
								ConvertBitsToString(SegmentSelectorBuffer, &SegmentSelectorBufferCount, MAX_BUFFER_SIZE, segment_selector);
								ConvertBitsToString(UnsignedOffsetBuffer, &UnsignedOffsetBufferCount, MAX_BUFFER_SIZE, unsigned_offset);
								
								Append(o_buff.Buffer, &o_buff.Count, MAX_BUFFER_SIZE, SegmentSelectorBuffer, SegmentSelectorBufferCount);
								Append(o_buff.Buffer, &o_buff.Count, MAX_BUFFER_SIZE, " : ", StringLength(" : "));
								Append(o_buff.Buffer, &o_buff.Count, MAX_BUFFER_SIZE, UnsignedOffsetBuffer, UnsignedOffsetBufferCount);
							}
							
							AdvanceSourcePtr(&RegExpSupport, &At);
							
						}
						
						else if(StringIsEqualRegExp(&RegExpSupport, At, "<Y[a-z]>", StringLength("<Y[a-z]>"), &Token))
						{
							u32 Size = EffOperandSize;
							GetDataType(State, Token.Base, Token.Count, &Size, &LowerCaseInfo);
							
							//TODO(Alex): instead of selecting this! we will have an instruction grammars group that based upon EffOperandSize attribute will select the appropiate complete syntax!
							switch(Size)
							{
								case 8:
								{
									Append(o_buff.Buffer, &o_buff.Count, MAX_BUFFER_SIZE, "B", StringLength("B"));
								}break;
								
								case 16:
								{
									Append(o_buff.Buffer, &o_buff.Count, MAX_BUFFER_SIZE, "W", StringLength("W"));
								}break;
								
								case 32:
								{
									Append(o_buff.Buffer, &o_buff.Count, MAX_BUFFER_SIZE, "D", StringLength("D"));
								}break;
								
								case 64:
								{
									Append(o_buff.Buffer, &o_buff.Count, MAX_BUFFER_SIZE, "Q", StringLength("Q"));
								}break;
							}
							
							AdvanceSourcePtr(&RegExpSupport, &At);
						}
						
						
						else if(StringIsEqualRegExp(&RegExpSupport, At, "<X[a-z]>", StringLength("<X[a-z]>"), &Token))
						{
							u32 Size = EffOperandSize;
							GetDataType(State, Token.Base, Token.Count, &Size, &LowerCaseInfo);
							
							switch(Size)
							{
								case 8:
								{
									Append(o_buff.Buffer, &o_buff.Count, MAX_BUFFER_SIZE, "B", StringLength("B"));
								}break;
								case 16:
								{
									Append(o_buff.Buffer, &o_buff.Count, MAX_BUFFER_SIZE, "W", StringLength("W"));
								}break;
								case 32:
								{
									Append(o_buff.Buffer, &o_buff.Count, MAX_BUFFER_SIZE, "D", StringLength("D"));
								}break;
								
								case 64:
								{
									Append(o_buff.Buffer, &o_buff.Count, MAX_BUFFER_SIZE, "Q", StringLength("Q"));
								}break;
								
								InvalidDefaultCase;
							}
							
							AdvanceSourcePtr(&RegExpSupport, &At);
						}
						
						
						else if(StringIsEqualRegExp(&RegExpSupport, At, "<O[a-z]>", StringLength("<O[a-z]>"), &Token))
						{
							u32 Size = EffOperandSize; 
							GetDataType(State, Token.Base, Token.Count, &Size, &LowerCaseInfo);
							
							u32 SegmentSelectorBufferCount = 0;
							char SegmentSelectorBuffer[MAX_BUFFER_SIZE] = {0};
							u32 UnsignedOffsetBufferCount = 0;
							char UnsignedOffsetBuffer[MAX_BUFFER_SIZE] = {0};
							
							bits unsigned_offset = Zeroes(EffAddressSize);
							unsigned_offset.Value = GetBits_msb(State, unsigned_offset.bits_count);
							unsigned_offset = SwapBitfieldBytes(unsigned_offset);
							
							ConvertBitsToString(UnsignedOffsetBuffer, &UnsignedOffsetBufferCount, MAX_BUFFER_SIZE, unsigned_offset);
							append_mem_operand_size_kw_masm(o_buff.Buffer, &o_buff.Count, MAX_BUFFER_SIZE, InstructionOperandSize);
							
							Append(o_buff.Buffer, &o_buff.Count, MAX_BUFFER_SIZE, " ptr ", StringLength(" ptr "));
							
							if(Group2Prefix > group2_Invalid)
							{
								append_segment_reg_masm(Group2Prefix, o_buff.Buffer, &o_buff.Count, MAX_BUFFER_SIZE);
							}
							else
							{
								Append(o_buff.Buffer, &o_buff.Count, MAX_BUFFER_SIZE, "DS", StringLength("DS"));
							}
							
							Append(o_buff.Buffer, &o_buff.Count, MAX_BUFFER_SIZE, " : [ ", StringLength(" : [ "));
							Append(o_buff.Buffer, &o_buff.Count, MAX_BUFFER_SIZE, UnsignedOffsetBuffer, UnsignedOffsetBufferCount);
							Append(o_buff.Buffer, &o_buff.Count, MAX_BUFFER_SIZE, " ]", StringLength(" ]"));
							
							AdvanceSourcePtr(&RegExpSupport, &At);
						}
						
						
						else if(StringIsEqualRegExp(&RegExpSupport, At, "<G[a-z]>", StringLength("<G[a-z]>"), &Token))
						{
							u32 Size = EffOperandSize;
							GetDataType(State, Token.Base, Token.Count, &Size, &LowerCaseInfo);
							if((LowerCaseInfo == 'z') || (LowerCaseInfo == 'v') || (LowerCaseInfo == 'b') || (LowerCaseInfo == 'p'))
							{
								CopyRegString(State, o_buff.Buffer, &o_buff.Count, MAX_BUFFER_SIZE, Size, rex, &BitsArray, true);
							}
							
							AdvanceSourcePtr(&RegExpSupport, &At);
						}
						
						else if(StringIsEqualRegExp(&RegExpSupport, At, "<E[a-z]>", StringLength("<E[a-z]>"), &Token))
						{
							//NOTE(Alex): Go for modrm byte
							u32 Size = EffOperandSize;
							GetDataType(State, Token.Base, Token.Count, &Size, &LowerCaseInfo);
							if((LowerCaseInfo == 'z') || (LowerCaseInfo == 'v') || (LowerCaseInfo == 'b') || (LowerCaseInfo == 'p'))
							{
								GetAdressingMode(State, ProcessorMode, Size, EffAddressSize, Group2Prefix, o_buff.Buffer, &o_buff.Count, MAX_BUFFER_SIZE, &BitsArray, rex);
							}
							
							AdvanceSourcePtr(&RegExpSupport, &At);
						}
						
						else if(StringIsEqualRegExp(&RegExpSupport, At, "<M[a-z]>", StringLength("<M[a-z]>"), &Token))
						{
							u32 Size = EffOperandSize;
							GetDataType(State, Token.Base, Token.Count, &Size, &LowerCaseInfo);
							
							bits mod_ = get_bitfield_from_bitsarray_bytype(&BitsArray, BitfieldType_mod);
							
							if(mod_.Value == 0b11)
							{
								//TODO(Alex): Logging or make those operands data!
								Assert(!"Illegal memory instruction, accesing register pagefile");
							}
							
							if((LowerCaseInfo == 'z') || (LowerCaseInfo == 'v') || (LowerCaseInfo == 'b') || (LowerCaseInfo == 'p'))
							{
								GetAdressingMode(State, ProcessorMode, Size, EffAddressSize, Group2Prefix, o_buff.Buffer, &o_buff.Count, MAX_BUFFER_SIZE, &BitsArray, rex);
							}
							
							AdvanceSourcePtr(&RegExpSupport, &At);
						}
						
						else
						{
							Append(o_buff.Buffer, &o_buff.Count, MAX_BUFFER_SIZE, At++, 1);
						}
					}
					
					
				}
				
				//TODO(Alex): Print to file instead!
				printf_s("%*s\n", o_buff.Count, o_buff.Buffer);
#endif
				
				goto INSTRUCTION_FOUND;
			}
			
		
			Valid_Stream = false;
			
			INSTRUCTION_FOUND:
			//NOTE(Alex): this is here so that compiler doesn´t put error empty label			

			TextVAddress += (memory_index)State->cursor - (memory_index)State->baseframe;


			EndTempMemory(&temp_mem);
		}
		
		int x = 4;

	}
    
    int x = 4;
}

