function is = isArmstrongNumber(A)
  %isArmstrongNumber(A)
  %Parameters:
  %A : Integer 32 bits
  %Returns true if A is an Armstrong number, false otherwise.
  %Armstrong number: A number which satisfies the following relation:
  %Sum of cubes of A's digits = A
  
  num = A;
  sum = 0;
  len = strlength(string(num));
  while num>0
    rem = mod(num,10);
    sum = sum + power(rem,len);
    num = idivide(num,10);
  end
  if sum==A
    is = true;
  else
    is = false;
  end
  
end