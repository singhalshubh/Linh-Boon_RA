import numpy as np
import utils
from scipy.optimize import minimize
from scipy.special import expit

class LogisticRegression():
    """ Logistic regression
    """
    def __init__(self, lam):
        """ Construct a least square regression object
        Don't modify this

        Args: 
            lam (float):
                regularization constant
                Default = 0 (ordinary logistic regression)
                If lam > 0 (regularized logistic regression)
        """
        self.lam = lam

    def logistic_loss(self, w, X, y):
        """ Compute the logistic loss

        Args: 
            w (numpy.array)
                Weight vector
            
            X (numpy.array)
                Input feature matrix

            y (numpy.array)
                Label vector
        
        Returns:
            Logistic loss
        
        """
        # Your solution goes here
        loss = 0
        numberOfInstances = len(X)
        epsilon = 1e-8
        for i in range(0,numberOfInstances) :
            loss += -1*(np.log(expit(y[i]*( np.dot(w,X[i]) ) ) + epsilon ))
        loss = loss/numberOfInstances
        if self.lam != 0 :
            loss += self.lam*np.dot(w[1:],w[1:])
        return loss

    def fit(self, X, y, w0=None):
        """ Learn the weight vector of the logistic regressor via 
        iterative optimization using scipy.optimize.minimize

        Args:
            X (numpy.array)
                Input feature matrix with shape (N,d)
            y (numpy.array)
                Label vector with shape (N,)
            w0 (numpy.array) 
                (Optional) initial estimate of weight vector

        Returns:
            (w, b)
                w (numpy.array):
                    Learned weight vector with shape (d,)
                    where d is the number of features of data X
                b (float)
                    Learned bias term

        """
        (N, d) = X.shape
        assert(y.shape == (N,))

        # You should initialize w0 here
        if not w0:
            w0 = [0.] * (d)
            # Do something instead of return
        res = minimize(self.logistic_loss, w0, args=(X, y)) 
        w  = res["x"]
        bias = w[0]
        w = w[1:]
        self.w = w
        self.bias = bias
        return(w, bias)
        
    def predict(self, X):
        """ Predict the label {+1, -1} of data points
        
        Args:
            X (numpy.array)
                Input feature matrix with shape (N, d)


        Returns:
            y (numpy.array)
                Predicted label vector with shape (N,)
                Each entry is in {+1, -1}
    
        """
        # Your solution goes here
        numberOfTestCases = X.shape[0]
        derivedHypothesis = np.zeros(numberOfTestCases)
        for i in range(0,numberOfTestCases) :
            z = np.dot(self.w, X[i]) + self.bias
            derivedHypothesis[i] = np.sign(z)
        return derivedHypothesis