function maxIndex = findMaxIndex(y)
  %findMaxIndex(y)
  %Parameters:
  %y : Vector
  %Returns maxIndex that is a vector of linear indices for which the elements in y
  %is equal to the maximum value in y.
  maxIndex = find(y==max(y));
end