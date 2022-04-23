import utils
import matplotlib.pyplot as plt
import numpy as np
from linear_regression import LeastSquareRegression

# Hint: this is all the imports you need

numberOfFolds = 5
numberOfLambdas = 6
foldTrainingError = np.zeros(numberOfLambdas)
foldTestError = np.zeros(numberOfLambdas)
foldTestsetError = np.zeros(numberOfLambdas)

def main() :
	#LinearRegressionWithoutRegularization()
	linearRegL2(10)
	for i in range(0, numberOfLambdas) :
		foldTrainingError[i] = 0
		foldTestsetError[i] = 0
		foldTestError[i] = 0
	linearRegL2(100)


def linearRegL2(number) :
	for i in range(0,numberOfFolds) :
		linearRegressionForAFold(i,number)
	parameter = [0.1, 1, 10, 100, 500, 1000]
	parameterArray = np.zeros(numberOfLambdas)
	for i in range(0,numberOfLambdas) :
		foldTrainingError[i] = foldTrainingError[i]/numberOfFolds
		foldTestError[i] = foldTestError[i]/numberOfFolds
		foldTestsetError[i] = foldTestsetError[i]/numberOfFolds
		parameterArray[i] = np.log10(parameter[i])
	#print(parameterArray)
	print(foldTrainingError)
	print(foldTestError)
	print(foldTestsetError)
	plt.plot(parameterArray, foldTrainingError, markerfacecolor='red', label = "trainingError")
	plt.plot(parameterArray, foldTestError, markerfacecolor='blue', label = "crossValidationError")
	plt.plot(parameterArray, foldTestsetError, markerfacecolor='black', label = "testError")
	plt.title("Learning Curve with Regularization")
	plt.xlabel("Log of Lambdas")
	plt.ylabel("Error")
	plt.legend()
	plt.savefig(f"LearningCurveP6B{number}")
	plt.close()


def linearRegressionForAFold(foldNumber, number) :
	allData = utils.load_all_cross_validation_dataP6("P6/Data-set-2/Cross-validation", number)
	parameter = [0.1, 1, 10, 100, 500, 1000]
	trainingError = np.zeros(numberOfLambdas)
	testError = np.zeros(numberOfLambdas)
	testsetError = np.zeros(numberOfLambdas)
	for i in range(0,numberOfLambdas) :
		(trainingError[i], testError[i], testsetError[i]) = linearRegressionLamba(parameter[i], foldNumber, allData)
		#if parameter[i] == 100 :
		#	print(foldNumber + 1)
		#	print("Training Error : ")
		#	print(trainingError[i])
		#	print("Cross validation Error : ")
		#	print(testError[i])
		#	print("Test Error : ")
		#	print(testsetError[i])
		#print(parameterArray[i])
		foldTestError[i]+=testError[i]
		foldTrainingError[i]+=trainingError[i]	
		foldTestsetError[i] += testsetError[i]
	#plotGraph4B(trainingError, testError, parameterArray, foldNumber)


def linearRegressionLamba(parameter, foldNumber, allData) :
	(testDataLabel, trainingDataLabel) = utils.partition_cross_validation_fold(allData, foldNumber)
	#print(testDataLabel)
	#print(trainingDataLabel)
	testData, testLabels = testDataLabel
	trainingDataWithoutBias, trainingLabel = trainingDataLabel
	#print(trainingDataWithoutBias.shape[0])
	trainingData = convertIncludeBias(trainingDataWithoutBias)
	lg = LeastSquareRegression(parameter)
	(w,b) = lg.fit(trainingData, trainingLabel)
	#if parameter == 100 :
	#	print(foldNumber + 1)
	#	print("Weight : ")
	#	print(w)
	#	print("Bias : ")
	#	print(b)
	expectedLabels = lg.predict(testData)
	numberOfTestCases = testData.shape[0]
	#Cross Validation error
	actualTestErr = utils.mean_squared_error(expectedLabels, testLabels)
	expectedLabelsTrainingSet = lg.predict(trainingDataWithoutBias)
	actualTrainErr = utils.mean_squared_error(expectedLabelsTrainingSet, trainingLabel) 
	# Test error.
	testsetData = utils.load_data_from_txt_file("P6/Data-set-2/X_test.txt", False)
	testsetLabels = utils.load_data_from_txt_file("P6/Data-set-2/y_test.txt", True)
	predictedTestsetlabels = lg.predict(testsetData)
	testsetError = utils.mean_squared_error(predictedTestsetlabels, testsetLabels)
	return (actualTrainErr, actualTestErr, testsetError)

def LinearRegressionWithoutRegularization() :
	trainingError = np.zeros(10)
	testError = np.zeros(10)	
	trainingExamples = np.zeros(10)
	for i in range(0,10) :
		(trainingError[i], testError[i], trainingExamples[i]) =  linearRegression((i+1)*10)
	print(trainingError)
	print(testError)
	plotGraph(trainingError, testError, trainingExamples)

	trainingErrorB = np.zeros(2)
	testErrorB = np.zeros(2)
	trainingExamplesB = np.zeros(2)
	for i in range(0,2) :
		(trainingErrorB[i], testErrorB[i], trainingExamplesB[i]) = linearRegression6B1(10**(i+1))



def plotGraph(trainingError, testError, trainingExamples) :
	plt.plot(trainingExamples, trainingError, markerfacecolor='red', label = "trainingError")
	plt.plot(trainingExamples, testError, markerfacecolor='blue' , label = "testError")
	plt.title("Learning Curve")
	plt.xlabel("Number of Training Examples")
	plt.ylabel("Error")
	plt.legend()
	plt.savefig("LearningCurveP6A(1)")
	plt.close()


def plotGraph6A2(predictedLabels, trueLabels, data  ) :
	plt.plot(data, predictedLabels, color='red')
	plt.scatter(data, trueLabels)
	plt.title("Learning Curve for 100% training set")
	plt.xlabel("Test Instances")
	plt.ylabel("Label")
	plt.savefig("LearningCurveP6A(2)")
	plt.close()


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

def linearRegression6B1(fileNumber) :
	dataWithoutBias = utils.load_data_from_txt_file(f"P6/Data-set-2/Train-subsets/X_train_{fileNumber}%.txt", False)
	data = convertIncludeBias(dataWithoutBias)
	labels = utils.load_data_from_txt_file(f"P6/Data-set-2/Train-subsets/y_train_{fileNumber}%.txt", True)
	#print(dataWithoutBias[0])
	#Train the sample for a file
	lg = LeastSquareRegression(0)
	(w,b) = lg.fit(data, labels)
	testcaseData = utils.load_data_from_txt_file("P6/Data-set-2/X_test.txt", False)
	testLabels = utils.load_data_from_txt_file("P6/Data-set-2/y_test.txt", True)
	expectedLabels = lg.predict(testcaseData)
	numberOfTestCases = testcaseData.shape[0]
	testError = utils.mean_squared_error(expectedLabels, testLabels)
	expectedLabelsTrainingSet = lg.predict(dataWithoutBias)
	trainingError = utils.mean_squared_error(expectedLabelsTrainingSet, labels)
	print(fileNumber)
	print("Weight")
	print(w)
	print("Bias")
	print(b)
	print("trainingerr")
	print(trainingError)
	print("testerr")
	print(testError)
	print("\n")

	return (trainingError,testError, (dataWithoutBias.shape[0]))


def linearRegression(fileNumber) :
	dataWithoutBias = utils.load_data_from_txt_file(f"P6/Data-set-1/Train-subsets/X_train_{fileNumber}%.txt", False)
	data = convertIncludeBias(dataWithoutBias)
	labels = utils.load_data_from_txt_file(f"P6/Data-set-1/Train-subsets/y_train_{fileNumber}%.txt", True)
	#print(dataWithoutBias[0])
	#Train the sample for a file
	lg = LeastSquareRegression(0)
	(w,b) = lg.fit(data, labels)
	testcaseData = utils.load_data_from_txt_file("P6/Data-set-1/X_test.txt", False)
	testLabels = utils.load_data_from_txt_file("P6/Data-set-1/y_test.txt", True)
	expectedLabels = lg.predict(testcaseData)
	numberOfTestCases = testcaseData.shape[0]
	testError = utils.mean_squared_error(expectedLabels, testLabels)
	expectedLabelsTrainingSet = lg.predict(dataWithoutBias)
	trainingError = utils.mean_squared_error(expectedLabelsTrainingSet, labels)

	if fileNumber == 100 :
		print("Wight and bias")
		print(w)
		print(b)
		print(fileNumber)
		plotGraph6A2(expectedLabels, testLabels, testcaseData)

	return (trainingError,testError, (dataWithoutBias.shape[0]))




if __name__ == "__main__":
    main()