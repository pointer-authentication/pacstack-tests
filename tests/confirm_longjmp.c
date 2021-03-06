/*************************************************************************************
 * Copyright (c) 2019 Xiaoyang Xu, Masoud Ghaffarinia, Wenhao Wang, and Kevin Hamlen *
 * The University of Texas at Dallas                                                 *
 * Copyright (c) 2020 Aalto University Secure Systems Group                          *
 *                                                                                   *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of   *
 * this software and associated documentation files (the "Software"), to deal in     *
 * the Software without restriction, including without limitation the rights to      *
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of  *
 * the Software, and to permit persons to whom the Software is furnished to do so,   *
 * subject to the following conditions:                                              *
 *                                                                                   *
 * The above copyright notice and this permission notice shall be included in all    *
 * copies or substantial portions of the Software.                                   *
 *                                                                                   *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR        *
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS  *
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR    *
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER    *
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN           *
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.        *
 *************************************************************************************/
 
/* This file is part of the ConFIRM test suite, whose initial documentation can be
   found in the following publication:

   Xiaoyang Xu, Masoud Ghaffarinia, Wenhao Wang, Kevin W. Hamlen, and Zhiqiang Lin.
   "ConFIRM: Evaluating Compatibility and Relevance of Control-flow Integrity 
   Protections for Modern Software."  In Proceedings of the 28th USENIX Security
   Symposium, August 2019. 
   
   Modified for pacstack-tests by Thomas Nyman <thomas.nyman@aalto.fi> */

#include "confirm_setup.h"
#include <setjmp.h>

jmp_buf buf;
void longjmp_test();
void longjmp_callee1();
void longjmp_callee2();

int main()
{
    // Check if a CFI solution can handle unmatched call/return pair due to longjmp. 
    longjmp_test();
    printf("longjmp_test passed\n");

    return 0;
}

void longjmp_test()
{
    printf("5. a message in longjmp_test\n");
    // setjmp() returns 0 when called directly, so control flows to the else block.
    // The if block is executed as the jump target of longjmp().
    if (setjmp(buf))
        printf("8. a message after longjmp\n");
    else
        longjmp_callee1();
}

void longjmp_callee1()
{
    printf("6. a message in longjmp_callee1\n");
    longjmp_callee2();
}

void longjmp_callee2()
{
    printf("7. a message in longjmp_callee2\n");
    
    // This longjmp to longjmp_test() leads to an unmatched call/return pair,
    // followed by a return from longjmp_test to main.
    longjmp(buf, 1);
    printf("-1, oops, should never reach this!\n");
}

