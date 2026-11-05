import numpy as np


def neuralNetwork(inp, weight):
    return inp.dot(weight)

prediction = neuralNetwork(np.array(0.9), 0.2)
true_prediction = 0.2

def get_errors(true_prediction, prediction):
    return (true_prediction - prediction) ** 2

# print(get_errors(true_prediction, prediction))
inp = np.array(0.9)
weight = np.array(0.2)
true_prediction = 0.2

for i in range(10):
    prediction = neuralNetwork(inp, weight)
    error = get_errors(true_prediction, prediction)
    print("Prediction: %.10f, Weight: %.5f, Error: %.20f" % (prediction, weight, error))
    delta = (prediction - true_prediction) * inp
    weight = weight - delta