/*
NOTE(Alex): eaglefly_custom_debug.cpp

This is the user debug API, that serves the debug dispatcher,
it will work as a wrapper, and as a debug control on compile time. 

This is the entry point for user debug. Print formatted data, dumpers, set breakpoints, etc. 
*/


internal void * 
Win32AllocateMemory(memory_index Size)
{
    void * Result = 0;
    //TODO(Alex): Alignment?
    //Assert(IsPower2(Alignment));
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


WRITE_ENTIRE_FILE(Win32WriteEntireFile)
{
    b32 Result = false;
    HANDLE Handle = CreateFileA(FileName,
                                GENERIC_WRITE,
                                FILE_SHARE_WRITE,
                                0,
                                OPEN_EXISTING,
                                FILE_ATTRIBUTE_NORMAL,
                                0);
    if(Handle)
    {
        DWORD BytesWritten = 0;
        if(WriteFile(Handle, Data, BytesToWrite, &BytesWritten, 0))
        {
            Result = true;
        }
        else
        {
            //TODO(Alex): Logging
        }
        CloseHandle(Handle);
    }
    else
    {
        //TODO(Alex): Check if ERROR_FILE_NOT_FOUND 
    }
    return Result;
}

READ_ENTIRE_FILE(Win32ReadEntireFile)
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
            u32 U32Size = TruncateU64ToU32(U64Size.QuadPart);
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

#else
//TODO(Alex): Cross platform debugging?
#endif

struct tokenizer
{
    char * At;
};

int main(int ArgCount, char ** Arguments)
{
    debug_file_content FC = Win32ReadEntireFile(Arguments[1]);
    if(FC.Content)
    {
        tokenizer Tokenizer = {};
        Tokenizer.At = (char*)FC.Content;
    }
    
    return 0;
}
















