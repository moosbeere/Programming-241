import numpy as np


def neuralNetwork(inps, weights):
    prediction_h = inps.dot(weights[0])
    prediction_out = prediction_h.dot(weights[1])
    return prediction_out

inps = np.array([23, 45])

weight_h_1 = [0.4, 0.1]
weight_h_2 = [0.3, 0.2]
weight_out_1 = [0.4, 0.1]
weight_out_2 = [0.3, 0.1]
weights_h = np.array([weight_h_1, weight_h_2]).T
weights_out = np.array([weight_out_1, weight_out_2]).T
weight = [weights_h, weights_out]

print(neuralNetwork(inps, weight))