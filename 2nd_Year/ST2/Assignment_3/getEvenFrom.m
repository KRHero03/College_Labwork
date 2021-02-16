function evenVal = getEvenFrom(A)
    %getEvenFrom(A)
    %Parameters:
    %A : Matrix
    %Returns evenVal that is a vector of elements that are present in matrix A and
    %even.
    [m,n] = size(A);
    evenVal = [];
    for i = 1:m
        for j = 1:n
            if mod(A(i,j),2)==0       
                evenVal = [evenVal A(i,j)];
            end
        end
    end
end