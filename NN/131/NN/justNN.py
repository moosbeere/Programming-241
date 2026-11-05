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

def neuralNetwork_h(inps, weights):
    prediction_h = [0]*len(weights[0])
    for i in range(len(weights[0])):
        for j in range(len(inps)):
            prediction_h[i] += inps[j] * weights[0][i][j]
    prediction_out = [0]*len(weights[1])
    for i in range(len(weights[1])):
        for j in range(len(prediction_h)):
            prediction_out[i] += prediction_h[j] * weights[1][i][j]
    return prediction_out

weight_h = [[0.4, 0.1], [0.3, 0.2]]
weight_out = [[0.4, 0.1], [0.3, 0.1]]
weights = [weight_h, weight_out]
inp = [23,45]

print(neuralNetwork_h(inp, weights))

