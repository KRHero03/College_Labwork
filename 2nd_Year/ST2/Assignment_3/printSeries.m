function  printSeries(n)
  %printSeries(n)
  %Parameters:
  %n : Integer 32 bit
  %Prints required series along with its value in format 'double'.
  %Example:
  %For n = 3,
  %1!/2*3*4 + 2!/3*4*5 + 3!/4*5*6 = 1.250000e-01
  a=0.0;
  temp = 1.0;
  fprintf('The required series is as follows:-\n');
  for i = 1:n
      fprintf('%d!/%d*%d*%d ',i,i+1,i+2,i+3);
      if i~=n
          fprintf('+ ');
      else
          fprintf('= ');
      end
      temp = temp*i;
      a = a + double(double(temp)/double((i+1)*(i+2)*(i+3)));
  end
  fprintf('%d\n',a);
end