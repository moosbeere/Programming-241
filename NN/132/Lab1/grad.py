from webbrowser import get

import numpy as np

from Lab1.hidden import weight


def neuralNetwork(inps, weights):
    return inps.dot(weights)

def get_error(true_prediction, prediction):
    return(true_prediction - prediction)**2

inps = np.array([
    [150, 40],
    [170, 80],
    [160, 90]
])
weights = np.array([0.2,0.3])
true_predictions = np.array([50,120,140])
learning_rate = 0.00001

for i in range(500):
    error = 0
    for j in range(len(inps)):
        current_inp = inps[j]
        true_prediction = true_predictions[j]
        prediction = neuralNetwork(current_inp, weights)
        error +=get_error(true_prediction, prediction)
        print("Prediction: %s, True_prediction: %s, Weights: %s " %(prediction, true_prediction, weights))
        delta = (prediction - true_prediction) * current_inp * learning_rate
        weights -= delta
    print("Error: %s" %error)
    print("---------")
