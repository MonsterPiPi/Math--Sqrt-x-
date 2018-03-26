//: A UIKit based Playground for presenting user interface
  


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
