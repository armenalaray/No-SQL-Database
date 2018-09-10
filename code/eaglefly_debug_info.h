/*

Alejandro Armenta Ayala
eaglefly_debug_info.h 
Debug Information that the tracer will use 

*/

//TODO(Alex): Do we want to add dinamically user typedefs in here?
enum efly_fundamental_type 
{
    FType_8b,
    FType_16b,
    FType_32b,
    FType_64b,
    FType_128b,
    FType_256b,
    FType_512b,
};

enum efly_sym_type
{
    SymType_Function,
    SymType_Global,
    SymType_Local,
    SymType_StructClass,
};

struct efly_target_type
{
    efly_fundamental_type FType;
    char * Name;
    efly_target_type * Next;
};


//NOTE(Alex): Addresses are relative to code segment pointer! (Far Pointers)
enum efly_lexical_scope_type
{
    LScope_Function,
    LScope_Thunk,
    LScope_Block,
    LScope_StructClass,
};

struct efly_function_data;
struct efly_thunk_data;
struct efly_block_data;
struct efly_struct_class_data;

struct efly_symbol_entry
{
    //TODO(Alex): Local Scope
    memory_index MemoryAddress;
    u32 TypeIndex;//NOTE(Alex): Index to the types table to prevent deduplication
    
    efly_sym_type SymType;
    union
    {
        //TODO(Alex): Add Extra symbols
        char * FuncSymbol;
        char * GlobalSymbol;
        char * LocalSymbol;
        char * StructClassSymbol;
    };
    
    efly_target_type * TargetType;
    efly_symbol_entry * Next;
};

//NOTE(Alex): Scope 0 is going to be the Root always
//NOTE(Alex): efly_lexical_scope and opcode_block map to the same code segmentation
//TODO(Alex): Align this to the next power of 2 greater than sizeof(efly_lexical_scope) 512
#pragma pack(push, 1) 
struct efly_lexical_scope
{
    u32 ScopeIndex;
    efly_lexical_scope_type Type;
    
    union
    {
        //NOTE(Alex): This is C/C++ Language dependent
        efly_function_data * FuncScope;
        efly_thunk_data * ThunkScope;
        efly_block_data * BlockScope;
        efly_struct_class_data * StructClass;
    };
    
    efly_symbol_entry * SymbolBlock;
    
    efly_lexical_scope * Next;
    efly_lexical_scope * Prev;
};
#pragma pack(pop)

struct efly_opcode_block
{
    u32 ScopeIndex;
    u32 CodeSegmentIndex;
    memory_index BeginOffset;
    memory_index EndOffset;
    
    //NOTE(Alex): This data captures scope independent symbol information 
    efly_symbol_entry * SymbolBlock;
    
    efly_opcode_block * Next;
    efly_opcode_block * Prev;
};

enum efly_target_architecture
{
    TA_x86,
    TA_x64,
    //TODO(Alex): which platforms are we targeting? , are we gonna target  any other than x86,x64?
    TA_ARM,
};

struct efly_compiland_module
{
    u32 PESectionIndex;
    u32 SourceFileCount;
    
    //TODO(Alex): u32 ModeViewFlags; Ways to display different views?
    efly_opcode_block OpcodeSentinel;
    efly_lexical_scope RootLexicalScope;
};


struct efly_debug_info
{
    char * TargetID;
    efly_target_architecture TA;
    efly_target_type * TypesTable;
    
#if 0    
    u32 ModuleCount;
    efly_compiland_module Modules[4096];
#else
    efly_opcode_block OpcodeSentinel;
    efly_lexical_scope LexicalScopeSentinel;
#endif
    
};


