def neuralNetwork(inp, weight):
    prediction = inp * weight
    return prediction

print(neuralNetwork(2, 0.4))

def neuralNetwork_w(inps, weights):
    prediction = 0
    for i in range(len(inps)):
        prediction += inps[i] * weights[i]
    return prediction

print(neuralNetwork_w([150, 40], [0.3, 0.4]))

def neuralNetwork_out(inp, weights):
    prediction = [0,0]
    for i in range(len(weights)):
        prediction[i] += inp * weights[i]
    return prediction

print(neuralNetwork_out(5, [0.3,0.4]))

def neuralNetwork_m(inps, weights):
    prediction = [0] * len(weights)
    for i in range(len(weights)):
        for j in range(len(inps)):
            prediction[i] += inps[j] * weights[i][j]
    return prediction

weights = [
    [0.2, 0.1, 0.65],
    [0.3, 0.1, 0.7],
    [0.5, 0.4, 0.34]
]
inps = [50, 165, 45]
print(neuralNetwork_m(inps, weights))
