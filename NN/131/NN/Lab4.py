import numpy as np

# def neuralNetwork(inp, weight):
#     return inp* weight
#
# inp = 30
# weight = 0.2
# true_prediction = 70
# learning_rate = 0.01
#
# def get_error(true_prediction, prediction):
#     return (true_prediction - prediction) ** 2
#
# for i in range(20):
#     prediction = neuralNetwork(inp, weight)
#     error = get_error(true_prediction, prediction)
#     print("Prediction: %.10f, Weight: %.5f, Error: %.20f" %(prediction, weight, error))
#     delta = (prediction - true_prediction) * inp * learning_rate
#     weight -= delta



# def neuralNetwork(inps, weight):
#     return inps.dot(weight)
#
# inps = np.array([150,40])
# weight = np.array([0.2, 0.3]).T
# true_prediction = 1
# learning_rate = 0.0001
#
# def get_error(true_prediction, prediction):
#     return (true_prediction - prediction) ** 2
#
# for i in range(50):
#     prediction = neuralNetwork(inps, weight)
#     error = get_error(true_prediction, prediction)
#     print("Prediction: %.10f, Weight: %s, Error: %.20f" %(prediction, weight, error))
#     delta = (prediction - true_prediction) * inps * learning_rate
#     delta[0]=0
#     weight -= delta


# def neuralNetwork(inp, weights):
#     return inp * weights
#
# inps = 150
# weight = np.array([0.2, 0.3])
# true_prediction = np.array([50,120])
# learning_rate = 0.000001
#
# def get_error(true_prediction, prediction):
#     return (true_prediction - prediction) ** 2
#
# for i in range(300):
#     prediction = neuralNetwork(inps, weight)
#     error = get_error(true_prediction, prediction)
#     print("Prediction: %s, Weight: %s, Error: %s" %(prediction, weight, error))
#     delta = (prediction - true_prediction) * inps * learning_rate
#     weight -= delta


# def neuralNetwork(inp, weights):
#     return inps.dot(weights)
#
# inps = np.array([150, 40])
# weights = np.array([[0.2, 0.3],[0.5,0.7]]).T
# true_prediction = np.array([50,120])
# learning_rate = 0.00001
#
# def get_error(true_prediction, prediction):
#     return (true_prediction - prediction) ** 2
#
# for i in range(50):
#     prediction = neuralNetwork(inps, weights)
#     error = get_error(true_prediction, prediction)
#     print("Prediction: %s, Weight: %s, Error: %s" %(prediction, weights, error))
#     delta = (prediction - true_prediction) * inps * learning_rate
#     weights -= delta

def neuralNetwork(inps, weights):
    return inps.dot(weights)

inps = np.array([[150, 40],
                 [170,80],
                 [160,90]])

weights = np.array([0.2, 0.3]).T
true_predictions = np.array([50,120,140])
learning_rate = 0.00001

def get_error(true_prediction, prediction):
    return (true_prediction - prediction) ** 2
# #стохастический градиентный спуск
# for i in range(500):
#     for j in range(len(inps)):
#         current_inp = inps[j]
#         true_prediction = true_predictions[j]
#         prediction = neuralNetwork(current_inp, weights)
#         error = get_error(true_prediction, prediction)
#         print("Prediction: %s, Weight: %s, Error: %s" %(prediction, weights, error))
#         delta = (prediction - true_prediction) * current_inp * learning_rate
#         weights -= delta
#     print("------------")

#полный градиентный спуск
for i in range(500):
    error = 0
    for j in range(len(inps)):
        current_inp = inps[j]
        true_prediction = true_predictions[j]
        prediction = neuralNetwork(current_inp, weights)
        error += get_error(true_prediction, prediction)
        print("Prediction: %s, True_prediction: %s, Weights: %s" %(prediction, true_prediction, weights))
        delta = (prediction - true_prediction) * current_inp * learning_rate
        weights -= delta
    print("Errors: %s" % error)
    print("------------")






