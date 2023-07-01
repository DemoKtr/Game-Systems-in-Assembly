#include "MathEngine.h"
#include <iostream>
int MathEngine::rectangular(Vector2* v1, Vector2* v2, Vector2* v3)
{
    float v1v2, v1v3, v2v3;
    v1v2 = v1->Distance_asm(v2);
    v1v3 = v1->Distance_asm(v3);
    v2v3 = v2->Distance_asm(v3);
    int is = 0;
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
        jb notequalsv2
        fld dif
        fchs
        fcomip st(0),st(1)
        ja notequalsv2
        mov is, 1
        jmp end

    notequalsv2:
            fld v1v3 
            fmul st(0), st(0) 
            fld v2v3
            fmul st(0), st(0)
            faddp st(1), st(0)
            fld v1v2
            fmul st(0),st(0)
            fsub st(0),st(1)   
            fld dif; Za³adowanie wartoœci dif na stos FPU
            fcomip st(0), st(1)
            jb notequalsv3
            fld dif
            fchs
            fcomip st(0), st(1)
            ja notequalsv3
            mov is, 1
            jmp end
    notequalsv3 :
                fld v1v3
                fmul st(0), st(0)

                fld v1v3
                fmul st(0), st(0)
                faddp st(1), st(0)
                fld v2v3
                fmul st(0), st(0)
                fsub st(0), st(1)
                fld dif; Za³adowanie wartoœci dif na stos FPU
                fcomip st(0), st(1)
                jb end
                fld dif
                fchs
                fcomip st(0), st(1)
                ja end
                mov is, 1
                jmp end
    
    
    
   

        end :


           
    }
    
    return is;
}
