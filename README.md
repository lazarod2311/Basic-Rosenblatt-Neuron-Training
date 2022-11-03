# Basic-Rosenblatt-Neuron-Training
## This repository contains a C language code about a basic Rosenblatt neuron Training.
### This code was created as a work for the discipline of applied artificial intelligence of the higher course of technology in data science.
The objective is to train a Rosenblatt neuron, obtaining the weights, to be able to separate numbers using a six-digit input value. The same was written to separate higher and lower values than my university registration number (RU).  

The neural training was performed using a C code developed observing the following steps:
1. Asks the user for the RU value and stores it in an array of characters;
1. Receives the values of the number of training epochs and the learning rate and
stores in integer and double-precision floating-point variables, respectively;
1. Converts the RU character array to a single integer value;
1. Create a vector of weights W and assign them the value of 1. The weight variable W0 (bias)
was initialized to -1 when declared;
1. A random number is generated, which will not be repeated in another training period, and the
stores in a colon: The whole number in an integer variable and type the
type in a vector also of type integer;
1. The value of the generated random number is compared with the value of the RU and if this value is
greater than or equal to the RU value, the output reference receives 1 and otherwise receives -
1;
1. With the reference value established, neural training is performed using the
following steps:
*  At each epoch, the value of the random number generated at the neuron's input is inserted, where it is multiplied by the weights and entered in an adder block.
*  The values are added together and with the neuron activation threshold (bias), generating the Yi value.
*  After that, the output with the activation function (unit step) is generated as follows:  
 If Yi > 0, Output = 1  
 If Yi < 0, Output = -1  
* The error is calculated considering the reference, where the error value will be given by: error = output - reference.
* If the error value is different from zero, the weights are modified and, in the case of the model proposed here, the activation threshold (bias) is also modified. For this, use the following mathematical apparatus:  
𝑊(𝑖 + 1) = 𝑊(𝑖) - ∆𝑊  
∆𝑊 = 𝑋𝑖 ⋅ 𝑒 ⋅ n  
Where n is the learning rate, e is the error, and Xi is a neuron input.  
W0(𝑖 + 1) = W0(𝑖) + ∆W0  
∆W0 = 𝑒 ⋅ n  
* Finally, training is performed using the RU value in the last epoch of training and the weights and threshold (bias) are shown on the screen.  

