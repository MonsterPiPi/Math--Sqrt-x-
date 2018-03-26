## Name: Sqrt(x)
## Tags: Math
**Implement int sqrt(int x).  
  Compute and return the square root of x.    
  x is guaranteed to be a non-negative integer.**  
### Example 1:
>Input: 4  
 Output: 2
>
### Example 2:
>Input: 8  
 Output: 2  
 Explanation: The square root of 8 is 2.82842..., and since we want to return an integer, the decimal part will be truncated.
>

## Answer:
## Swift 4.X 
```swift
/**
 This is impressed Newton version, and it costs O(1) time.
 */
class Solution {
   func mySqrt(_ x: Int) -> Int {
    assert(x >= 0)
    
    if (x == 0 || x == 1)
    {
        return x
    }
    
    var tmp = Float(x)
    let xhalf = Float(0.5) * tmp
    var i = withUnsafePointer(to: &tmp) {
        return $0.withMemoryRebound(to: Int.self, capacity: 1) {
            return $0.pointee
        }
    }
    
    i = 0x5f375a86 - (i >> 1);
    
    tmp = withUnsafePointer(to: &i) {
        return $0.withMemoryRebound(to: Float.self, capacity: 1) {
            return $0.pointee
        }
    }
    
    
    tmp = tmp * (Float(1.5) - xhalf * tmp * tmp)
    tmp = tmp * (Float(1.5) - xhalf * tmp * tmp)
    tmp = tmp * (Float(1.5) - xhalf * tmp * tmp)
    
    let ret = Int(1 / tmp)
    
    if (ret * ret > x)
    {
        return ret - 1
    }
    
    return ret
    }

}
```
## C
```c
/*
 This is impressed Newton version, and it costs O(1) time.
 */
int mySqrt(int x) {
    
     
     assert(x >= 0);  
    
        if (x == 0 || x == 1)  
        {  
            return x;  
        }  
    
        float tmp = x;  
        float xhalf = 0.5f * tmp;  
        int i = *(int *)&tmp;  
          
        i = 0x5f375a86 - (i >> 1);   
          
        tmp = *(float *)&i;  
        tmp = tmp * (1.5f - xhalf * tmp * tmp);  
        tmp = tmp * (1.5f - xhalf * tmp * tmp);  
        tmp = tmp * (1.5f - xhalf * tmp * tmp);  
  
        int ret = 1  /  tmp;  
        if (ret * ret > x)  
        {  
            return ret - 1;  
        }  
    
        return ret;  
}
```
