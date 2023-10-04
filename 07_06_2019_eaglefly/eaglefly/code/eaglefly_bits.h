//////////////////////////////////////////////////////
//
//Author: Alejandro Armenta
//Date: 2019
//File: eaglefly_bits.h
//Company:
//
//(2018-2019) All rights reserved.
//
//////////////////////////////////////////////////////


#ifndef EAGLEFLY_BITS_H


#ifdef EAGLEFLY_ARQ_64
#undef EAGLEFLY_ARQ_64
#endif

#ifdef EAGLEFLY_ARQ_32
#undef MAX_BITS_COUNT
#endif


#if (EAGLEFLY_ARQ == 64)
#define MAX_BITS_COUNT 64
#elif (EAGLEFLY_ARQ == 32)
#define MAX_BITS_COUNT 32
#endif


struct buffered_io
{
    u8 * start;
    u8 * end;
    u8 * cursor;
    
    //TODO(Alex): error_code errorcode;
    //TODO(Alex): Add function pointer here?
};

//TODO(Alex): Change this to bits_64!!!
struct bits
{
    //NOTE(Alex): We treat each Value as a huge Little endian - LSB 64-bit unsigned integer
    bitfield_type type;
    u32 bits_count;
    u64 value;
	bits * next;
};


#define EAGLEFLY_BITS_H
#endif


