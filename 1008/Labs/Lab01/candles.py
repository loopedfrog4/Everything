#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'birthdayCakeCandles' function below.
#
# The function is expected to return an INTEGER.
# The function accepts INTEGER_ARRAY candles as parameter.
#

def birthdayCakeCandles(candles):
    # temp_highest = candles[0]
    # count = 0
    # for candle in candles:
        
    #     if candle == temp_highest:
    #         count += 1
    #     elif candle > temp_highest:
    #         count = 1
    #         temp_highest = candle
    # return count

    temp_highest = candles[0]
    count = 0
    for candle in candles:
        if temp_highest == candle:
            count += 1
        elif candle >= temp_highest:
            count = 1
            temp_highest = candle
    return count

array = [4,4,11,3,4,11,5]

print(birthdayCakeCandles(array))
