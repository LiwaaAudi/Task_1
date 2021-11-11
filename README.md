# Task Nr. 1

Using an object-oriented programming model, write a program that would allow you to perform mathematical operations 
(addition, subtraction, multiplication, division, comparison) with rational numbers. Rational numbers are numbers that 
can be expressed as fractions, and the numerator and denominator of fractions are integers. 
For example: ½, 2/3, 15/32, 65/4, 16/5.

Write a class for rational numbers. Class data - rational numbers, i.e. a pair of integer variables 
(numerator and denominator). The class must have the following methods: addition, subtraction, multiplication, 
division, more, negative and operations +, -, *, /> and multiplication of -1.

Methods of addition, subtraction, multiplication, division, negative must return rational numbers. 
The function more returns the value of the bool type.

The composition operation a + b will be called as a. composition(b), and operation a> b is called as a.more (b).

Each abstract data type requires a constructor that creates objects. The constructor must create objects using a 
pair of integers numbers. Any integer number is a rational number (we can explain it as the same number divided by 1). 
Also wee a constructor with one parameter of an integer number.

Also need include input and output methods in the class. The input method must have an istream type argument and read a 
rational number from the keyboard or file like this form "numerator/denominator". The second method output must have an 
ostream type argument and output a rational number to the screen or file like the same form "numerator/denominator".

Write the function main () and test the implementation of your class by calculating the results of the following steps:

a / b + c / d

(a * d + b * c) / (b * d)

a / b-c / d

(a * d-b * c) / (b * d)

(a / b) / (c / d)

(a * d) / (c * b)

- (a / b)

(a / b)> (c / d)

(a / b) = = (c / d)

where a and b are rational numbers.

The numerator can be positive or negative. The denominator must be positive.