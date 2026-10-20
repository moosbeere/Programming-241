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

print(NeuralNetwork_3(4, [0.3, 0.2]))
