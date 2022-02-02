import torch as ty
import numpy as np

def model(x,weights):
    return x @ weights.t() + b

inputs = np.array([[73, 67, 43], 
                   [91, 88, 64], 
                   [87, 134, 58], 
                   [102, 43, 37], 
                   [69, 96, 70]], dtype='float32')

targets = np.array([[56, 70], 
                    [81, 101], 
                    [119, 133], 
                    [22, 37], 
                    [103, 119]], dtype='float32')

inputs = ty.from_numpy(inputs)
targets = ty.from_numpy(targets)

w = ty.randn(2,3, requires_grad=True)
b = ty.rand(2, requires_grad=True)

print("Prediction \n", (model(inputs,w)))
print("Target \n", targets)