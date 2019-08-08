import tensorflow as tf
import numpy as np

learning_rate = 0.001
training_epochs = 100
batch_size = 4
display_step = 1

n_hidden_1 = 32
n_hidden_2 = 16
n_input = 32
n_classes = 2

xx = tf.placeholder("float", [None, n_input])
yy = tf.placeholder("float", [None, n_classes])

def multilayer(xx, weights, biases):
    layer_1 = tf.add(tf.matmul(xx, weights['h1']), biases['b1'])
    layer_1 = tf.nn.relu(layer_1)

    layer_2 = tf.add(tf.matmul(layer_1, weights['h2']), biases['b2'])
    layer_2 = tf.nn.relu(layer_2)

    out_layer = tf.matmul(layer_2, weights['out']) + biases['out']
    return out_layer

weights = {
    'h1': tf.Variable(tf.random_normal([n_input, n_hidden_1])),
    'h2': tf.Variable(tf.random_normal([n_hidden_1, n_hidden_2])),
    'out': tf.Variable(tf.random_normal([n_hidden_2, n_classes]))
}

biases = {
    'b1': tf.Variable(tf.random_normal([n_hidden_1])),
    'b2': tf.Variable(tf.random_normal([n_hidden_2])),
    'out': tf.Variable(tf.random_normal([n_classes]))
}
pred = multilayer(xx, weights, biases)

cost = tf.reduce_mean(tf.nn.softmax_cross_entropy_with_logits(logits=pred, labels=yy))
optimizer = tf.train.AdamOptimizer(learning_rate=learning_rate).minimize(cost)

init = tf.global_variables_initializer()

with tf.Session() as sess:
    sess.run(init)
    for epoch in range(training_epochs):
        avg_cost = 0
        total_batch = int(len(x_train)/batch_size)
        X_batches = np.array_split(x_train, total_batch)
        Y_batches = np.array_split(y_train, total_batch)

        for i in range(total_batch):
            batch_x, batch_y = X_batches[i], Y_batches[i]
            _, c = sess.run([optimizer, cost], feed_dict = {xx: batch_x, yy: batch_y})
            avg_cost+= c/total_batch
        if epoch % display_step == 0:
            print("Epoch:", '%04d' % (epoch+1), "cost=", "{:.9f}".format(avg_cost))
    print('Its over!')

    corr_pred = tf.equal(tf.argmax(pred, 1), tf.argmax(yy, 1))
    acc = tf.reduce_mean()
    print("Accuracy:", acc.eval({xx: x_test, yy: y_test}))
    global result
    result = tf.argmax(pred, 1).eval({xx: x_test, yy: y_test})

