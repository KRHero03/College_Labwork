function result = getResult(A)
  %getResult(A)
  %Parameters:
  %A : Vector that contains marks of students
  %Returns a vector that contains 1 if student passed, 0 otherwise.
  %Passing condition:- A(i)>30
  result = A>30;
  
end