import numpy as np
import utils


class LeastSquareRegression():
    """ Least square regression
    """
    def __init__(self, lam=0):
        """ Construct a least square regression object
        Don't modify this
        
        Args: 
            lam (float):
                regularization constant
                Default = 0 (ordinary least square regression)
                If lam > 0 (regularized least square regression)
        """
        self.lam = lam
    
    def fit(self, X, y):
        """ Learn the weights of the linear regression model
        by solving for w in closed form
        Args:
            X (numpy.array)
                Input feature data with shape (N, d)
                
            y (numpy.array)
                Label vector with shape (N,)

        Returns:
            (w, b)
                w (numpy.array):
                    Learned weight vector with shape (d,)
                    where d is the number of features of data X
                b (float)
                    Learned bias term
        
        """
        N, d = X.shape
        assert(y.shape == (N,))

        xTranspose = np.transpose(X)
        array = np.matmul(xTranspose, X, dtype=np.double)

        if self.lam != 0 :
            x = np.arange( (d*d), dtype=int).reshape(d,d)
            #print(x)
            regularizationMatrix = np.full_like(x,0., dtype = np.double)
            for i in range(1,d) : 
                regularizationMatrix[i][i] = self.lam*(N)
            #print(regularizationMatrix)
            array1 = np.add( np.matmul(xTranspose, X, dtype=np.double), regularizationMatrix)
            tempInverse = np.linalg.inv(array1)
            w = np.matmul(tempInverse,np.matmul(xTranspose, y) )
            bias = w[0]
            w = w[1:]
            #print(w)
            self.w = w
            self.bias = bias
            return(w, bias)
        else :
            tempInverse = np.linalg.inv(array)
            w = np.matmul(np.array(tempInverse),np.matmul(xTranspose, y) )
            bias = w[0]
            w = w[1:]
            self.w = w
            self.bias = bias
            return(w, bias)
    
    def predict(self, X):
        """ Do prediction on given input feature matrix

        Args:
            X (numpy.array)
                Input feature matrix with shape (N, d)
        Returns:
            Predicted output vector with shape (N,)
        
        """
        
        # Your solution goes here
        numberOfTestCases = X.shape[0]
        derivedHypothesis = np.zeros(numberOfTestCases)
        for i in range(0,numberOfTestCases) :
            derivedHypothesis[i] = np.dot(self.w, X[i]) + self.bias
        return derivedHypothesis