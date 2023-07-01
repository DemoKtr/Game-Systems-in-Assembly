#include "MathEngine.h"

int MathEngine::rectangular(Vector2* v1, Vector2* v2, Vector2* v3)
{
    float v1v2, v1v3, v2v3;
    v1v2 = v1->Distance(v2);
    v1v3 = v1->Distance(v3);
    v2v3 = v2->Distance(v3);
    int is = 5;

    __asm
    {
        fld v1v2               
        fmul st(0), st(0)      
        fld v1v3               
        fmul st(0), st(0)      
        faddp st(1), st(0)    
        fld v2v3              
        fmul st(0), st(0)     
        fcomi st(0), st(1)     
        jne not_equal         
        mov is, 1             
        jmp done               

        not_equal :
        mov is, 0             

            done :
            ; Continue execution of the code
    }

    return is;
}
