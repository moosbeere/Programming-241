def NeuralNetwork(inp, weight):
    prediction = inp * weight #прямое распространение
    return prediction

# print(NeuralNetwork(2, 0.3))
def NeuralNetworks_2(inps, weigts):
    predict = 0
    for i in range(len(weigts)):
        predict += inps[i] * weigts[i]
    return predict

# print(NeuralNetworks_2([2,4], [0.1,0.2]))

def NeuralNetwork_3(inp, weights):
    predict = []
    for i in range(len(weights)):
        predict.append(inp * weights[i])
    return predict

# print(NeuralNetwork_3(4, [0.3, 0.2]))

def neuralNetwork_m(inps, weights):
    predict = [0] * len(weights)
    for i in range(len(weights)):
        ws = 0
        for j in range(len(inps)):
            ws += inps[j] * weights[i][j]
        predict[i] = ws
    if (predict[0] < predict[1]):
        weights[0][0] = round(weights[0][0] + 0.1, 2)
        print(weights[0][0])
        return neuralNetwork_m(inps, weights)
    elif (predict[0] > predict[1]):
        weight[0][0] -= 0.1
        print(weight[0][0])
        return neuralNetwork_m(inps, weights)
    return predict

inps = [11,7.7]
weight_1=[0.28, 0.1]
weight_2=[0.3, 0.1]
weight = [weight_1, weight_2]

print(neuralNetwork_m(inps, weight))

# (a1*b1 + a1*b3)

