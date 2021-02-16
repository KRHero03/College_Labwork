function postfixExp = prefixToPostfix(prefix)
    %prefixToPostfix(postfix)
    %Parameters:
    %prefix: A string containing prefix expression
    %Returns postfix expression of given prefix expression
    
    [m,n] = size(prefix);
    postfix = strings(n);
    pass = 1;
    top = 0;
    prefix = flip(prefix);
    for i=1:n        
        if(prefix(i)=='+' || prefix(i)=='*' || prefix(i)=='/' || prefix(i)=='-')
            if(top<2)
                pass = 0;
                break;
            else
                op1 = postfix(top);
                op2 = postfix(top-1);
                top = top - 1;
                postfix(top) = strcat(op1,op2,prefix(i));
            end
        elseif prefix(i)=='0' || prefix(i)=='1' || prefix(i)=='2' || prefix(i)=='3' || prefix(i)=='4' || prefix(i)=='5' || prefix(i)=='6' || prefix(i)=='7' || prefix(i)=='8' || prefix(i)=='9'
            top = top + 1;
            postfix(top) = prefix(i);
        else
            pass = 0;
            break;
        end
    end
    if(pass==0)
        postfixExp = 'null';
    else
        postfixExp = postfix(top);
end