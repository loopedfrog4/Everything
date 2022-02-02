#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'migratoryBirds' function below.
#
# The function is expected to return an INTEGER.
# The function accepts INTEGER_ARRAY arr as parameter.
#

def migratoryBirds(arr):
    # return max(sorted(set(arr)), key=arr.count)
    bird_id_1_count = 0
    bird_id_2_count = 0
    bird_id_3_count = 0
    bird_id_4_count = 0
    bird_id_5_count = 0
    
    for bird_id in arr:
        if bird_id == 1:
            bird_id_1_count += 1
        elif bird_id == 2:
            bird_id_2_count += 1
        elif bird_id == 3:
            bird_id_3_count += 1
        elif bird_id == 4:
            bird_id_4_count += 1
        elif bird_id == 5:
            bird_id_5_count += 1
    h = "hello"
array = [1, 2, 3, 4, 5, 4, 3, 2, 1, 3, 4]
print(migratoryBirds(array))