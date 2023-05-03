#include "main.h"

class MyMath {
    private:
    const double kPi = 3.14156;

    public:
    double Sum_(double a, double b) {
            return a + b;
        }

    double Square_(double a) {
            return a * a;
        }

    /* Add here the following functions:
        * subtration
        * division
        * overloaded function to sum_ that sums a vector
        * surface of circle
        * circumference of circle
        * Vector product (3 * 3)
        * Matrix multiplication (2 x 2)
        * sin(a)
    */
    double Sub(double a, double b){
            return a-b;
    }

    double Division(double a, double b){
            return a/b;
    }

    double Sum_(std::vector<double> v){
            // overloaded function to sum up a vector
            double total = 0.0;
            for (double d : v) {
                total += d;
            }
            return total;
    }

    double SoC(double r){
            return 3.1415926*pow(r,2);
    }

    double CoC(double r){
            return 3.1415926*2*r;
    }

    std::vector<double> VectorProduct(std::vector<double> v1, std::vector<double> v2) {
            std::vector<double> result(3);
            result[0] = v1[1] * v2[2] - v1[2] * v2[1];
            result[1] = v1[2] * v2[0] - v1[0] * v2[2];
            result[2] = v1[0] * v2[1] - v1[1] * v2[0];
            return result;
    }

    std::vector<std::vector<double>> MatrixMultiply(std::vector<std::vector<double>> m1, std::vector<std::vector<double>> m2) {
        std::vector<std::vector<double>> result(2, std::vector<double>(2, 0.0));
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    result[i][j] += m1[i][k] * m2[k][j];
                }
            }
        }
        return result;
    }

    double Sine_(double a){
        return sin(a);
    }

};

int main() {
  MyMath math_;

  // Implement Input

  std::cout << "Sum is =  " << math_.Sum_(1.0, 1.0) << std::endl;

  std::cout << "Square is =  " << math_.Square_(2.0) << std::endl;

  std::cout << "Sub is =  " << math_.Sub(3.0, 1.0) << std::endl;

  std::cout << "Division is =  " << math_.Division(14.0, 2.0) << std::endl;

  std::cout << "VecSum is =  " << math_.Sum_({1.0,2.0,3.0,4.0,5.0}) << std::endl;

  std::cout << "surface of circle is =  " << math_.SoC(3.0) << std::endl;

  std::cout << "circumference of circle is =  " << math_.CoC(3.0) << std::endl;

  // vector product
  std::vector<double> v1 = {1.0, 2.0, 3.0};
  std::vector<double> v2 = {4.0, 5.0, 6.0};
  std::vector<double> result = math_.VectorProduct(v1, v2);
  std::cout << "Vector Product is = : ";
    for (int i = 0; i < result.size(); i++) {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;
  

  // matrix multiplication
  std::vector<std::vector<double>> m1 = { {1.0, 2.0}, {3.0, 4.0} };
  std::vector<std::vector<double>> m2 = { {5.0, 6.0}, {7.0, 8.0} };
  std::vector<std::vector<double>> result1 = math_.MatrixMultiply(m1, m2);
  std::cout << "Matrix Multiplication is =" << std::endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            std::cout << result1[i][j] << " ";
        }
        std::cout << std::endl;
    }
  

  std::cout << "sin(a) is =  " << math_.Sine_(3.0) << std::endl;
  
  return 0;
}