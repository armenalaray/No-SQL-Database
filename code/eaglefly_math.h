/*
Alejandro Armenta 
Math Library
*/

#ifndef EAGLEFLY_MATH_H

union vector_2 
{
    struct 
    {
        r32 x;
        r32 y;
    };
    
    r32 Values[2];
};


union vector_4
{
    struct
    {
        r32 x;
        r32 y;
        r32 z;
        r32 w;
    };
    struct 
    {
        r32 r;
        r32 g;
        r32 b;
        r32 a;
    };
    
    r32 Values[4];
};

union rectangle_2
{
    struct 
    {
        r32 MinX;
        r32 MinY;
        r32 MaxX;
        r32 MaxY;
    };
    struct 
    {
        vector_2 Min;
        vector_2 Max;
    };
    
    r32 Values[4];
};

//NOTE(Alex): Vectors Implementation
inline vector_2
Vector2(r32 x, r32 y)
{
    vector_2 Result = {x, y};
    return Result;
}


inline vector_2
operator+(vector_2 A, vector_2 B)
{
    vector_2 Result = {};
    Result.x = A.x + B.x;
    Result.y = A.y + B.y;
    
    return Result;
}


inline vector_2
operator-(vector_2 A, vector_2 B)
{
    vector_2 Result = {};
    Result.x = A.x - B.x;
    Result.y = A.y - B.y;
    
    return Result;
}

inline vector_2
operator-(vector_2 A)
{
    vector_2 Result = {};
    Result.x = -A.x;
    Result.y = -A.y;
    return Result;
}

inline vector_2
Hadamard(vector_2 A, vector_2 B)
{
    vector_2 Result = {};
    Result.x = A.x * B.x;
    Result.y = A.y * B.y;
    
    return Result;
}

inline vector_2
operator*(r32 Scalar, vector_2 B)
{
    vector_2  Result = {};
    Result.x = B.x * Scalar;
    Result.y = B.y * Scalar;
    return Result;
}

inline vector_2
operator*(vector_2 B, r32 Scalar)
{
    vector_2  Result = {};
    Result = Scalar * B;
    return Result;
}


//NOTE(Alex): rectangles Implementation
inline rectangle_2
RectMinDim(vector_2 Min, vector_2 Dim)
{
    rectangle_2 Result = {};
    Result.Min = Min;
    Result.Max = Min + Dim;
    return Result;
}

inline rectangle_2
Union(rectangle_2 A, rectangle_2 B)
{
    rectangle_2 Result = {};
    Result.Min.x = (A.Min.x <= B.Min.x) ? A.Min.x : B.Min.x;  
    Result.Min.x = (A.Min.y <= B.Min.y) ? A.Min.y : B.Min.y;  
    Result.Min.x = (A.Max.x >= B.Max.x) ? A.Max.x : B.Max.x;  
    Result.Min.x = (A.Max.y >= B.Max.y) ? A.Max.y : B.Max.y;  
    
    return Result;
}









#define EAGLEFLY_MATH_H
#endif