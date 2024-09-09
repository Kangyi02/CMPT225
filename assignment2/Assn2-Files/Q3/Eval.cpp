/* 
 * Eval.cpp
 *
 * Description: Evaluation of infix expressions using two Stacks.
 *
 * Author:
 * Date:
 */

#include <iostream>
#include "Scanner.h"
#include "Stack.h"  // GENERIC STACK

using std::cout;
using std::endl;
using std::cin;


int main () {
    Scanner S(cin);
    Token t;

    Stack<Token> numstack, opstack;  // 2x Stacks of type Token
    

    t = S.getnext();

    // Implement the algorithm
    while (t.tt != eof || (!opstack.isEmpty()))
    {
        if (t.tt == integer)
        {
            numstack.push(t);
            t = S.getnext();
        }
        else if (t.tt == lptok)
        {
            opstack.push(t);
            t = S.getnext();
        }
        else if (t.tt == rptok)
        {
            if (opstack.peek().tt == lptok) 
            {
                opstack.pop();
                t = S.getnext();
            }
            else
            {
                int num1 = numstack.pop().val;
                int num2 = numstack.pop().val;
                Token operatorType = opstack.pop();
                Token result;
                result.tt = integer;

                if (operatorType.tt == pltok)
                {
                    result.val = num1 + num2;
                }
                else if (operatorType.tt == mitok)
                {
                    result.val = num2 - num1;
                }
                else if (operatorType.tt == asttok)
                {
                    result.val = num1 * num2;
                }
                else if (operatorType.tt == slashtok)
                {
                    result.val = num2 / num1;
                }
                numstack.push(result);
                // for testing
                // cout << result.val << endl; 
            }
        }
        else if (t.tt == pltok || t.tt == mitok || t.tt == eof)
        {
            if ((!opstack.isEmpty()) && (opstack.peek().tt == pltok || opstack.peek().tt == mitok || opstack.peek().tt == asttok || opstack.peek().tt == slashtok))
            {
                int num1 = numstack.pop().val;
                int num2 = numstack.pop().val;
                Token operatorType = opstack.pop();
                Token result;
                result.tt = integer;
                if (operatorType.tt == pltok)
                {
                    result.val = num1 + num2;
                }
                else if (operatorType.tt == mitok)
                {
                    result.val = num2 - num1;
                }
                else if (operatorType.tt == asttok)
                {
                    result.val = num1 * num2;
                }
                else if (operatorType.tt == slashtok)
                {
                    result.val = num2 / num1;
                }
                numstack.push(result);
                // for testing
                // cout << result.val << endl; 
            }
            else
            {
                opstack.push(t);
                t = S.getnext();
            }
        }
        else if (t.tt == asttok || t.tt == slashtok)
        {
            if ((!opstack.isEmpty()) && (opstack.peek().tt == asttok || opstack.peek().tt == slashtok))
            {
                int num1 = numstack.pop().val;
                int num2 = numstack.pop().val;
                Token operatorType = opstack.pop();
                Token result;
                result.tt = integer;
                if (operatorType.tt == pltok)
                {
                    result.val = num1 + num2;
                }
                else if (operatorType.tt == mitok)
                {
                    result.val = num2 - num1;
                }
                else if (operatorType.tt == asttok)
                {
                    result.val = num1 * num2;
                }
                else if (operatorType.tt == slashtok)
                {
                    result.val = num2 / num1;
                }
                numstack.push(result);
                // for testing
                // cout << result.val << endl; 
            }
            else
            {
                opstack.push(t);
                t = S.getnext();
            }   
        }
    }
  
    cout << numstack.pop().val << endl;

    return 0;
}

