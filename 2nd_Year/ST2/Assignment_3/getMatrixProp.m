function [charEq,eigenVal,eigenVec] = getMatrixProp(A)
    %getMatrixProp(A)
    %Parameters:
    %A : Matrix
    %Returns following values:-
    %charEq : Characterisitc equation of matrix A
    %eigenVal : Eigen values of matrix A
    %eigenVec: Eigen vector of matrix A

    syms x;
    Asym = sym(A);
    charEq = charpoly(Asym,x);
    [eigenVec, D] = eig(A);
    eigenVal = diag(D);  
end