import numpy as np

def neuralNetwork(inps, weights):
    return inps.dot(weights)

inps = np.array([
    [150, 40],
    [140, 35],
    [155, 45],
    [185, 95],
    [145, 40],
    [195, 100],
    [180, 95],
    [170, 80],
    [160, 90],
])

weights = np.array([0.2,0.3])
true_predictions = np.array([0,0,0,100,0,100,100,100,100])
learning_rate = 0.00001

def get_error(true_prediction, prediction):
    return (true_prediction - prediction) ** 2

for i in range(2000):
    error = 0
    delta = 0
    for j in range(len(inps)):
        current_inp = inps[j]
        true_prediction = true_predictions[j]
        prediction = neuralNetwork(current_inp, weights)
        error += get_error(true_prediction, prediction)
        print("Prediction: %s, True_prediction: %s, Weights: %s" %(prediction, true_prediction, weights))
        delta += (prediction - true_prediction) * current_inp * learning_rate
    weights = weights - delta/len(inps)
    print("Errors: %s" % error)
    print("------------")

print(neuralNetwork(np.array([150,45]), weights))
print(neuralNetwork(np.array([170,85]), weights))
