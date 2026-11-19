import numpy as np

def neuralNetwork(inps, weights):
    return inps.dot(weights)

def relu(x):
    return (x > 0) * x

def get_error(true_prediction, prediction):
    return (true_prediction - prediction) ** 2
inps = np.array([[15,10],
                 [15,15],
                 [15,20],
                 [25,10]])

true_predictions = np.array([[10,20,15, 20]]).T
layer_hid_size = 3
layer_in_size = len(inps[0])
layer_out_size = len(true_predictions[0])

weights_h = 2 * np.random.random((layer_in_size, layer_hid_size)) - 1
weights_out = 2 * np.random.random((layer_hid_size, layer_out_size)) - 1

# print(weights_h)
# print(weights_out)

prediction_hid = relu(inps[0].dot(weights_h))
print(prediction_hid)
prediction_out = prediction_hid.dot(weights_out)
print(prediction_out)

