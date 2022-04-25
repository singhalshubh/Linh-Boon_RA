#!/usr/bin/python3

import utils
import matplotlib.pyplot as plt
import numpy as np
from logistic_regression import LogisticRegression

numberOfFolds = 5
numberOfLambdas = 1
foldTrainingError = np.zeros(numberOfLambdas)
foldTestError = np.zeros(numberOfLambdas)
foldTestsetError = np.zeros(numberOfLambdas)

# HINT: this is really all the imports you need
def main() :
	LogisticRegressionWithoutRegularization()
	parameterArray = np.zeros(numberOfLambdas)
	for i in range(0,5) :
		logisticRegressionForAFold(i)
	for i in range(0,numberOfLambdas) :
		foldTrainingError[i] = foldTrainingError[i]/numberOfFolds
		foldTestError[i] = foldTestError[i]/numberOfFolds
		foldTestsetError[i] = foldTestsetError[i]/numberOfFolds
		parameterArray[i] = i-(numberOfLambdas-1)
	print(foldTrainingError)
	print(foldTestError)
	print(foldTestsetError)
	# plt.plot(parameterArray, foldTrainingError, markerfacecolor='red', label = "trainingError")
	# plt.plot(parameterArray, foldTestError, markerfacecolor='blue', label = "crossValidationError")
	# plt.plot(parameterArray, foldTestsetError, markerfacecolor='black', label = "testError")
	# plt.title("Learning Curve with Regularization")
	# plt.xlabel("Log of Lambdas")
	# plt.ylabel("Error")
	# plt.legend()
	# plt.savefig("LearningCurveP4B")
	# plt.close()

def LogisticRegressionWithoutRegularization() :
	trainingError = np.zeros(10)
	testError = np.zeros(10)
	trainingExamples = np.zeros(10)
	for i in range(0,10) :
		(trainingError[i], testError[i], trainingExamples[i]) =  logisticRegression((i+1)*10)
	print("Training Error")
	print(trainingError)
	print("Test Error")
	print(testError)
	plotGraph(trainingError, testError, trainingExamples)


def plotGraph(trainingError, testError, trainingExamples) :
	plt.plot(trainingExamples, trainingError, markerfacecolor='red', label = "trainingError")
	plt.plot(trainingExamples, testError, markerfacecolor='blue', label = "testError")
	plt.title("Learning Curve")
	plt.legend()
	plt.xlabel("Number of Training Examples")
	plt.ylabel("Error")
	plt.savefig("LearningCurveP4A")
	plt.close()

#def plotGraph4B(trainingError, testError, parameterArray, foldNumber) :
#	plt.plot(parameterArray, trainingError, markerfacecolor='red', label = "trainingError")
#	plt.plot(parameterArray, testError, markerfacecolor='blue', label = "testError")
#	plt.title(f"Learning Curve for FOLD{foldNumber+1}")
#	plt.xlabel("LOG(10, lambda)")
#	plt.ylabel("Error")
#	plt.savefig(f"LearningCurve4B-Fold{foldNumber+1}")
#	plt.close()

def convertIncludeBias(dataWithoutBias) :
	(numberOfInstances, numberOfFeatures) = dataWithoutBias.shape
	data = np.zeros((numberOfInstances, numberOfFeatures+1))
	for i in range (0, numberOfInstances) :
		for j in range (0, numberOfFeatures+1) :
			if j == 0 :
				data[i][j] = 1.
			else :
				data[i][j] = dataWithoutBias[i][j-1]
	return data

def errorReport(numberOfTestCases, testLabels, expectedLabels) :
	error = 0
	for i in range(0,numberOfTestCases) :
		if testLabels[i] != expectedLabels[i] :
			error += 1
	return error

def logisticRegressionForAFold(foldNumber) :
	allData = utils.load_all_cross_validation_data("P4/Cross-validation")
	parameter = [1E-7, 1E-6, 1E-5, 1E-4, 1E-3, 1E-2, 0.1, 1]
	#parameter = [1E-7 ,1, 10,1000,100000,10000000,10000000000, 100000000000000]
	parameterArray = np.zeros(numberOfLambdas)
	trainingError = np.zeros(numberOfLambdas)
	testError = np.zeros(numberOfLambdas)
	testsetError = np.zeros(numberOfLambdas)
	for i in range(0,numberOfLambdas) :
		(trainingError[i], testError[i], testsetError[i]) = logisticRegressionLamba(parameter[i], foldNumber, allData)
		parameterArray[i] = i-(numberOfLambdas-1)
		foldTestError[i]+=testError[i]
		foldTrainingError[i]+=trainingError[i]
		foldTestsetError[i] += testsetError[i]
	#plotGraph4B(trainingError, testError, parameterArray, foldNumber)


def logisticRegressionLamba(parameter, foldNumber, allData) :
	(testDataLabel, trainingDataLabel) = utils.partition_cross_validation_fold(allData, foldNumber)
	testData, testLabels = testDataLabel
	trainingDataWithoutBias, trainingLabel = trainingDataLabel
	#print(trainingDataWithoutBias.shape[0])
	trainingData = convertIncludeBias(trainingDataWithoutBias)
	lg = LogisticRegression(parameter)
	lg.fit(trainingData, trainingLabel, None)
	expectedLabels = lg.predict(testData)
	numberOfTestCases = testData.shape[0]
	#Cross Validation error
	actualTestErr = (errorReport(numberOfTestCases, testLabels, expectedLabels))
	testError = actualTestErr/numberOfTestCases
	expectedLabelsTrainingSet = lg.predict(trainingDataWithoutBias)
	actualTrainErr = errorReport(trainingDataWithoutBias.shape[0], trainingLabel, expectedLabelsTrainingSet) 
	trainingError = actualTrainErr/trainingDataWithoutBias.shape[0]
	# Test error.
	testsetData = utils.load_data_from_txt_file("P4/X_test.txt", False)
	testsetLabels = utils.load_data_from_txt_file("P4/y_test.txt", True)
	predictedTestsetlabels = lg.predict(testsetData)
	testsetError = errorReport(testsetData.shape[0], testsetLabels, predictedTestsetlabels)/testsetData.shape[0]
	return (trainingError, testError, testsetError)
	


def logisticRegression(fileNumber) :
	dataWithoutBias = utils.load_data_from_txt_file(f"P4/Train-subsets/X_train_{fileNumber}%.txt", False)
	#data with bias included
	data = convertIncludeBias(dataWithoutBias)
	labels = utils.load_data_from_txt_file(f"P4/Train-subsets/y_train_{fileNumber}%.txt", True)
	#print(data[0])
	#print(dataWithoutBias[0])
	#Train the sample for a file
	lg = LogisticRegression(0)
	lg.fit(data, labels, None)
	testcaseData = utils.load_data_from_txt_file("P4/X_test.txt", False)
	testLabels = utils.load_data_from_txt_file("P4/y_test.txt", True)
	expectedLabels = lg.predict(testcaseData)
	numberOfTestCases = testcaseData.shape[0]
	testError = errorReport(numberOfTestCases, testLabels, expectedLabels)
	expectedLabelsTrainingSet = lg.predict(dataWithoutBias)
	trainingError = errorReport(dataWithoutBias.shape[0],labels, expectedLabelsTrainingSet)
	return ((trainingError/dataWithoutBias.shape[0]),(testError/numberOfTestCases), (dataWithoutBias.shape[0]))


if __name__ == "__main__":
    main()