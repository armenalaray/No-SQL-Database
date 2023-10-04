//////////////////////////////////////////////////////
//
//Author: Alejandro Armenta
//Date: 2019
//File: meta_instruction_flags.h
//Company:
//
//(2018-2019) All rights reserved.
//
//////////////////////////////////////////////////////


#ifndef META_INSRUCTION_FLAGS_H
#define META_INSRUCTION_FLAGS_H


struct token_array
{
	u32 Count;
	token FirstToken[64];
};

struct meta_state
{
    HANDLE STDOutHandle;
};

struct mnemonic_result
{
	u32 Index;
	b32 Valid;
};

#endif


