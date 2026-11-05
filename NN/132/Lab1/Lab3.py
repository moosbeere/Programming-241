import numpy as np


def neuralNetwork(inp, weight):
    return inp.dot(weight)

prediction = neuralNetwork(np.array(0.9), 0.2)
true_prediction = 0.2

def get_errors(true_prediction, prediction):
    return (true_prediction - prediction) ** 2
# несколько входов и один выход
# inp = np.array([150,40])
# weight = np.array([0.2, 0.3])
# true_prediction = 1
# learning_rate = 0.00001

# несколько выходов и один вход
# inp = np.array(150)
# weight = np.array([0.2, 0.3])
# true_prediction = np.array([50, 120])
# learning_rate = 0.00001

# несколько выходов и несколько входов
inp = np.array([150, 40])
weight = np.array([[0.2, 0.3], [0.5, 0.7]]).T
true_prediction = np.array([50, 120])
learning_rate = 0.00001

for i in range(45):
    prediction = neuralNetwork(inp, weight)
    error = get_errors(true_prediction, prediction)
    print("Prediction: %s, Weight: %s, Error: %s" % (prediction, weight, error))
    delta = (prediction - true_prediction) * inp * learning_rate
    weight = weight - delta