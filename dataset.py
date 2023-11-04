# 导入所需的库
import os
import numpy as np
import cv2 # 用于图像处理
from sklearn.neighbors import KNeighborsClassifier # 用于K近邻分类器
from sklearn.naive_bayes import GaussianNB # 用于朴素贝叶斯分类器
from sklearn.metrics import accuracy_score # 用于计算准确率
import matplotlib.pyplot as plt # 用于绘制图像

# 定义两个数据集的路径
mnist_path = "/home/xanxushu/Desktop/Code_Linux/python/mnist-dataset/dataset"
cifar_path = "/home/xanxushu/Desktop/Code_Linux/python/cifar-dataset/dataset"

# 定义两个数据集的类别标签
mnist_labels = ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9"]
cifar_labels = ["airplane", "automobile", "bird", "cat", "deer", "dog", "frog", "horse", "ship", "truck"]

# 定义两个数据集的特征提取函数
def mnist_feature(img):
    # 对于Mnist数据集，直接使用像素值作为特征
    # 将图像转换为灰度图，并将其展平为一维向量
    img = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    feature = img.flatten()
    return feature

def cifar_feature(img):
    # 对于Cifar数据集，使用颜色直方图作为特征
    # 将图像分为三个通道，并对每个通道计算直方图，然后拼接起来作为一维向量
    b, g, r = cv2.split(img)
    b_hist = cv2.calcHist([b], [0], None, [256], [0, 256])
    g_hist = cv2.calcHist([g], [0], None, [256], [0, 256])
    r_hist = cv2.calcHist([r], [0], None, [256], [0, 256])
    feature = np.concatenate((b_hist, g_hist, r_hist), axis=0).flatten()
    return feature

# 定义两个数据集的训练和测试函数
def mnist_train_test():
    # 对于Mnist数据集，使用K近邻分类器
    # 创建一个空的列表，用于存储训练数据的特征和标签
    train_features = []
    train_labels = []
    
    # 遍历训练数据的每个类别文件夹，读取图像并提取特征，同时记录标签
    for label in mnist_labels:
        print("learn %s" % label) # 打印提示信息
        folder_path = os.path.join(mnist_path, "traindata", label) # 拼接文件夹路径
        file_names = os.listdir(folder_path) # 获取文件夹中的文件名列表
        for file_name in file_names: # 遍历每个文件名
            file_path = os.path.join(folder_path, file_name) # 拼接文件路径
            img = cv2.imread(file_path) # 读取图像
            feature = mnist_feature(img) # 提取特征
            train_features.append(feature) # 将特征添加到列表中
            train_labels.append(label) # 将标签添加到列表中
        
        print("%s learned!" % label) # 打印提示信息
    
    # 将训练数据的特征和标签转换为numpy数组，并打印其形状
    train_features = np.array(train_features)
    train_labels = np.array(train_labels)
    print("train features shape:", train_features.shape)
    print("train labels shape:", train_labels.shape)

    # 创建一个空的列表，用于存储测试数据的特征和标签
    test_features = []
    test_labels = []

    # 遍历测试数据的每个类别文件夹，读取图像并提取特征，同时记录标签
    for label in mnist_labels:
        print("test %s" % label) # 打印提示信息
        folder_path = os.path.join(mnist_path, "testdata", label) # 拼接文件夹路径
        file_names = os.listdir(folder_path) # 获取文件夹中的文件名列表
        for file_name in file_names: # 遍历每个文件名
            file_path = os.path.join(folder_path, file_name) # 拼接文件路径
            img = cv2.imread(file_path) # 读取图像
            feature = mnist_feature(img) # 提取特征
            test_features.append(feature) # 将特征添加到列表中
            test_labels.append(label) # 将标签添加到列表中
        
        print("%s tested!" % label) # 打印提示信息
    
    # 将测试数据的特征和标签转换为numpy数组，并打印其形状
    test_features = np.array(test_features)
    test_labels = np.array(test_labels)
    print("test features shape:", test_features.shape)
    print("test labels shape:", test_labels.shape)

    # 创建一个K近邻分类器对象，设置邻居数为5
    knn = KNeighborsClassifier(n_neighbors=5)

    # 使用训练数据的特征和标签训练分类器
    print("training KNN classifier...")
    knn.fit(train_features, train_labels)
    print("KNN classifier trained!")

    # 使用训练好的分类器对测试数据的特征做预测，并打印预测结果的形状
    print("predicting test data...")
    pred_labels = knn.predict(test_features)
    print("test data predicted!")
    print("pred labels shape:", pred_labels.shape)

    # 计算并打印测试数据的分类正确率
    acc = accuracy_score(test_labels, pred_labels)
    print("test accuracy:", acc)

    # 保存训练好的分类器模型到文件中
    np.save("knn_model.npy", knn)
    print("KNN model saved!")

def cifar_train_test():
    # 对于Cifar数据集，使用朴素贝叶斯分类器
    # 创建一个空的列表，用于存储训练数据的特征和标签
    train_features = []
    train_labels = []
    
    # 遍历训练数据的每个类别文件夹，读取图像并提取特征，同时记录标签
    for label in cifar_labels:
        print("learn %s" % label) # 打印提示信息
        folder_path = os.path.join(cifar_path, "traindata", label) # 拼接文件夹路径
        file_names = os.listdir(folder_path) # 获取文件夹中的文件名列表
        for file_name in file_names: # 遍历每个文件名
            file_path = os.path.join(folder_path, file_name) # 拼接文件路径
            img = cv2.imread(file_path) # 读取图像
            feature = cifar_feature(img) # 提取特征
            train_features.append(feature) # 将特征添加到列表中
            train_labels.append(label) # 将标签添加到列表中
        
        print("%s learned!" % label) # 打印提示信息
    
    # 将训练数据的特征和标签转换为numpy数组，并打印其形状
    train_features = np.array(train_features)
    train_labels = np.array(train_labels)
    print("train features shape:", train_features.shape)
    print("train labels shape:", train_labels.shape)

    # 创建一个空的列表，用于存储测试数据的特征和标签
    test_features = []
    test_labels = []

    # 遍历测试数据的每个类别文件夹，读取图像并提取特征，同时记录标签
    for label in cifar_labels:
        print("test %s" % label) # 打印提示信息
        folder_path = os.path.join(cifar_path, "testdata", label) # 拼接文件夹路径
        file_names = os.listdir(folder_path) # 获取文件夹中的文件名列表
        for file_name in file_names: # 遍历每个文件名
            file_path = os.path.join(folder_path, file_name) # 拼接文件路径
            img = cv2.imread(file_path) # 读取图像
            feature = cifar_feature(img) # 提取特征
            test_features.append(feature) # 将特征添加到列表中
            test_labels.append(label) # 将标签添加到列表中
        
        print("%s tested!" % label) # 打印提示信息
    
    # 将测试数据的特征和标签转换为numpy数组，并打印其形状
    test_features = np.array(test_features)
    test_labels = np.array(test_labels)
    print("test features shape:", test_features.shape)
    print("test labels shape:", test_labels.shape)

    # 创建一个朴素贝叶斯分类器对象，假设特征服从高斯分布
    gnb = GaussianNB()

    # 使用训练数据的特征和标签训练分类器
    print("training Gaussian Naive Bayes classifier...")
    gnb.fit(train_features, train_labels)
    print("Gaussian Naive Bayes classifier trained!")

    # 使用训练好的分类器对测试数据的特征做预测，并打印预测结果的形状
    print("predicting test data...")
    pred_labels = gnb.predict(test_features)
    print("test data predicted!")
    print("pred labels shape:", pred_labels.shape)

    # 计算并打印测试数据的分类正确率
    acc = accuracy_score(test_labels, pred_labels)
    print("test accuracy:", acc)

    # 保存训练好的分类器模型到文件中
    np.save("gnb_model.npy", gnb)
    print("Gaussian Naive Bayes model saved!")

# 调用两个数据集的训练和测试函数，分别处理两个数据集
print("processing Mnist dataset...")
mnist_train_test()
print("Mnist dataset processed!")

print("processing Cifar dataset...")
cifar_train_test()
print("Cifar dataset processed!")
