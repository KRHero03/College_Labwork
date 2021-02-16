function postfix = infixToPostfix(s)
    %infixToPostfix(s)
    %Parameters:
    %s : String
    %Returns Postfix expression converted from provided Infix expression
    %string.
    stack = '';
    top = 0;
    [n,m] = size(s);
    postfix = '';
    for i = 1:m
        if(s(i)=='+' || s(i)=='-' || s(i)=='/' || s(i)=='*')
            while(top~=0 && priority(s(i))<=priority(stack(top)))
                postfix = [postfix stack(top)];
                top = top - 1;
            end
            top = top + 1;
            stack(top) = s(i);
        elseif s(i)=='('
            top = top + 1;
            stack = [stack;s(i)];
        elseif s(i)==')'
            while (top~=0 && stack(top)~='(')
                postfix = [postfix stack(top)];
                top = top - 1;
            end    
            if top~=0 && stack(top)=='('
                top = top-1; 
            end
        else
            postfix = [postfix s(i)];  
        end
    end

    while top~=0
      postfix = [postfix stack(top)];
      top = top -1;
    end
  
end