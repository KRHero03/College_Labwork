function r = findQuadraticRoots(a,b,c)
  %findQuadraticRoots(A)
  %Parameters:
  %a: Quadratic Coefficient
  %b: Linear Coefficient
  %c: Constant
  %Returns roots of quadratic equation formed using provided coefficients
  %in the form of [a,b]
  assert(a~=0);
  disp(a);
  disp(b);
  disp(c);
  r1 = (-b/(2*a)) - (sqrt(double(b*b - 4*a*c))/(2*a));
  r2 = (-b/(2*a)) + (sqrt(double(b*b - 4*a*c))/(2*a));
  r = [r1 r2];
end