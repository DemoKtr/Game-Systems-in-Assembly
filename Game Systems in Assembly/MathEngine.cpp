#include "MathEngine.h"
#include <iostream>
int MathEngine::rectangular(Vector2* v1, Vector2* v2, Vector2* v3)
{
    float v1v2, v1v3, v2v3;
    v1v2 = v1->Distance(v2);
    v1v3 = v1->Distance(v3);
    v2v3 = v2->Distance(v3);
    int is = 5;
    float dif = 0.01f;
  
    
    __asm
    {
 
        finit
        fld v1v2
        fmul st(0), st(0)
        fld v2v3
        fmul st(0), st(0)
        faddp st(1), st(0)
        fld v1v3
        fmul st(0), st(0)
        fsub st(0), st(1); Obliczenie ró¿nicy miêdzy wartoœciami v2v3 a sum¹ kwadratów v1v2 i v1v3
        fld dif; Za³adowanie wartoœci dif na stos FPU
        fcomip st(0), st(1)
        jae equals
        mov is,0
        jmp end

       

            equals :
        mov is, 1
            jmp end

            end :


           
    }
    
    return is;
}
