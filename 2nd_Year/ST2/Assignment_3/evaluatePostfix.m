function val = evaluatePostfix(postfix)
    %evaluatePostfix(postfix)
    %Parameters:
    %postfix: A vector containing postfix expression
    %Returns value of postfix expression after evaulation
    [m n] = size(postfix);
    stack = [];
    top = 0;
    pass = 1;
    for i=1:n
        if(postfix(i)=='+')
            if top<2
                pass = 0;
                break
            else
                val = stack(top) + stack(top-1);
                top  = top - 1;
                stack(top) = val;
            end
        elseif(postfix(i)=='-')
            if top<2
                pass = 0;
                break
            else
                val = stack(top) - stack(top-1);
                top  = top - 1;
                stack(top) = val;
            end
        elseif(postfix(i)=='*')
            if top<2
                pass = 0;
                break
            else
                val = stack(top) * stack(top-1);
                top  = top - 1;
                stack(top) = val;
            end
        elseif(postfix(i)=='/')
            if top<2 || stack(top-1)
                pass = 0;
                break;
            else
                val = stack(top) / stack(top-1);
                top  = top - 1;
                stack(top) = val;
            end
        elseif postfix(i)=='0' || postfix(i)=='1' || postfix(i)=='2' || postfix(i)=='3' || postfix(i)=='4' || postfix(i)=='5' || postfix(i)=='6' || postfix(i)=='7' || postfix(i)=='8' || postfix(i)=='9'
            top = top + 1;
            stack(top) = postfix(i) - '0';
        else
            pass = 0;
            break;
        end
    end
    if pass==0
        val = 'null';
    else
        val = stack(top);
    end

end