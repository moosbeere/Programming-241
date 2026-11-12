import numpy as np

def neuralNetwork(inps, weights):
    prediction_h = inps.dot(weights[0])
    prediction_h2 = prediction_h.dot(weights[1])
    prediction_out = prediction_h2.dot(weights[2])
    return prediction_out

weight_h = np.array([[0.4, 0.1], [0.3, 0.2], [0.6, 0.2]]).T
weight_h1 = np.array([[0.4, 0.1], [0.3, 0.2], [0.6, 0.2]])
weight_out = np.array([[0.4, 0.1], [0.3, 0.1], [0.7, 0.4]]).T
weights = [weight_h, weight_h1, weight_out]
inp = np.array([23,45])

print(neuralNetwork(inp, weights))

