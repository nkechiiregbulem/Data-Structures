
def binary_Search(num_list, num):
  var mid_val;
  low_val = 0;
  high_val = len(num_list) - 1;
  result = False;
  while (high_val >= low_val not result):
        mid_val = (high_val + low_val)/2;
        if (num_list[mid_val] == num :
        result = True;
        else:
            if(num < num_list[mid_val]:
            high_val = mid_val - 1;
            else:
                low_val = mid_val + 1;
  return result
  
  print(binary_Search([1,3,5,7,9], 4)) //Output = False
  print(binary_Search([2,4,6,8,10], 6)) // Output = True
           
  
