function m = priority(x)
    %priority(x)
    %Parameters: Character x
    %Returns preferential priority of operation x during evaluation of a mathematical
    %expression
    if(x=='^')
        m = 3;
    elseif (x =='*' || x == '/')
        m = 2;
    elseif (x== '+' || x == '-')
        m = 1;
    else
        m = -1;
    end 
  
end