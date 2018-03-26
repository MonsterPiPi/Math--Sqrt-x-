//
//  main.c
//  Math--Sqrt(x)
//
//  Created by Bobby Negoat on 3/26/18.
//  Copyright © 2018 Mac. All rights reserved.
//

#include <stdio.h>
#include <assert.h>

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

int main(int argc, const char * argv[]) {
    int num = 4, num1 = 7;
    printf("%d \n", mySqrt(num));
    printf("%d \n", mySqrt(num1));
    return 0;
}
