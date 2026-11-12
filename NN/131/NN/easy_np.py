import numpy as np

def neuralNetwork(inps, weights):
    prediction_h = inps.dot(weights[0])
    prediction_out = prediction_h.dot(weights[1])
    return prediction_out

weight_h = np.array([[0.4, 0.1], [0.3, 0.2]]).T
weight_out = np.array([[0.4, 0.1], [0.3, 0.1]]).T
weights = [weight_h, weight_out]
inp = np.array([23,45])

print(neuralNetwork(inp, weights))