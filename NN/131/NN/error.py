import numpy as np


def neuralNetwork(inps, weights):
    return inps.dot(weights)

inps = np.array([150, 40])
weights = np.array([0.2, 0.3])
true_prediction = 50
prediction = neuralNetwork(inps, weights)

def get_error(true_prediction, prediction):
    return (true_prediction - prediction) ** 2




