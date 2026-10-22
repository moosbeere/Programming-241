inps = [23, 45]

weight_h_1 = [0.4, 0.1]
weight_h_2 = [0.3, 0.2]
weight_out_1 = [0.4, 0.1]
weight_out_2 = [0.3, 0.1]
weights_h = [weight_h_1, weight_h_2]
weights_out = [weight_out_1, weight_out_2]
weight = [weights_h, weights_out]

def neuralNetwork(inps, weights):
    predict_h = [0] * len(weights[0])
    for i in range(len(weights[0])):
        ws = 0
        for j in range(len(inps)):
            ws += inps[j] * weights[0][i][j]
        predict_h[i] = ws
    predict_out = [0] * len(weights[1])
    for i in range(len(weights[1])):
        ws = 0
        for j in range(len(predict_h)):
            ws += predict_h[j] * weights[1][i][j]
        predict_out[i] = ws
    return predict_out

print(neuralNetwork(inps, weight))



