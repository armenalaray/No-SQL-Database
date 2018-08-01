#ifndef TTF_PREP_H


struct table_head
{
    u32 Tag;
    u32 CheckSum;
    u32 Offset;
    u32 Length;
};

struct ttf_state
{
    char * At;
    u32 TableCount;
    
    //TODO(Alex): Cache Tables as needed.
};




#define TTF_PREP_H
#endif