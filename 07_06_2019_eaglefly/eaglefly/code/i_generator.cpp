//////////////////////////////////////////////////////
//
//Author: Alejandro Armenta 
//Date: 2019
//File: i_generator.cpp
//Company: 
//
//All rights reserved.
//
//////////////////////////////////////////////////////

/*

//NOTE(Alex): 

This follows the rules and grammars of the instructions tables to generate new instructions tests for disassembler

What i want from this is something that i could mantain easily. So the idea here is that im creating the tables,
and that's ok. the most important thing here is to mantain the maximum amount of time of development, just adding entries to the tables, 

such that the things that use them can just add up every time it needs to!

i couil make them interdependently, and maintain 

the ideal thing would be to have a grammar that has the optional fields all over the place so that the thing could just follow up the grammar 

you already have the encodings, so use them to generate random bit values for each bitfield, once you get that,

you can generate other random values on the instructions (SIB) immmediate etc. 


*/



int main()


