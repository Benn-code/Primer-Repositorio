#include "integration.h"

double trapezoid(double a, double b, int N, fptr fun){
    double Deltax = (b-a)/N;
    double suma = 0.0;
    for(int k = 1; k <= N-1; k++) {
    //for(int k = N-1; k >= 1; k--) {
        double xk = a + k*Deltax;
        suma = suma + fun(xk);
    } 
    double result = Deltax*(0.5*fun(a) + suma + 0.5*fun(b));
    return result;
}

double simpson(double a, double b, int N, fptr fun){
    // N must be even
	if (N % 2 != 0) {
		N++;
	}
	double Deltax = (b-a)/N;
	double suma1 = 0.0;
    for(int k = 1; k <= N/2; k++) {
		double xk = a + (2*k - 1)*Deltax;
		suma1 += fun(xk);
	}
	double suma2 = 0.0;
    for(int k = 1; k <= N/2 - 1; k++) {
		double xk = a + (2*k)*Deltax;
		suma2 += fun(xk);
	}
	double result = Deltax*(fun(a) + 4*suma1 + 2*suma2 + fun(b))/3.0;

	return result;
}

double richardson(double a, double b, int N, fptr f, algptr alg, int alpha) {
    double aux = std::pow(2.0, alpha);
    double val1 = alg(a, b, N, f);
    double val2 = alg(a, b, 2*N, f);
    return (aux*val2 - val1)/(aux - 1.0);
}

double gauss2(double a, double b, fptr fun){
    // aux
    double aux1 = (b-a)/2;
    double aux2 = (b+a)/2;

    // define point coordinates
    double x0 = -1.0/std::sqrt(3.0);
    double x1 = +1.0/std::sqrt(3.0);
    
    //define weigths
    double w0 = 1.0;
    double w1 = 1.0;
    
    // compute integral
    double result = w0*fun(aux1*x0 + aux2) + w1*fun(aux1*x1+aux2);
    return aux1*result;
}

/* double gauss3(double a, double b, fptr fun)
 {
     // aux
     double aux1 = (b-a)/2;
     double aux2 = (b+a)/2;

     // define point coordinates
     double x0 = -std::sqrt(3.0/5.0);
     double x1 = 0;
     double x2 = +std::sqrt(3.0/5.0);
    
     //define weigths
     double w0 = 5.0/9.0;
     double w1 = 8.0/9.0;
     double w2 = 5.0/9.0;
    
     // compute integral
     double result = w0*fun(aux1*x0 + aux2) + w1*fun(aux1*x1+aux2) + w2*fun(aux1*x2+aux2);
     return aux1*result;
 } */

double gauss3(double a, double b, fptr fun){
    // aux
    double aux1 = (b-a)/2.0;
    double aux2 = (b+a)/2.0;

    // define point coordinates
    std::vector<double> x(3);
    x[0] = -std::sqrt(3.0/5.0);
    x[1] = 0;
    x[2] = +std::sqrt(3.0/5.0);
    
    //define weigths
    std::vector<double> w;
    w.resize(3);
    w[0] = 5.0/9.0;
    w[1] = 8.0/9.0;
    w[2] = 5.0/9.0;
    
    // compute integral
    double result = 0.0;
    for(int k = 0; k < 3; ++k){
        result = result + w[k]*fun(aux1*x[k] + aux2);
    }
    return aux1*result;
}

double gauss5(double a, double b, fptr fun) {
    double aux1 = (b - a) / 2.0;
    double aux2 = (b + a) / 2.0;

    std::vector<double> x(5);
    x[0] = -std::sqrt((5.0 + 2.0 * std::sqrt(10.0 / 7.0)) / 9.0);
    x[1] = -std::sqrt((5.0 - 2.0 * std::sqrt(10.0 / 7.0)) / 9.0);
    x[2] = 0.0;
    x[3] = -x[1]; // simétrico
    x[4] = -x[0]; // simétrico

    std::vector<double> w(5);
    w[0] = (322.0 - 13.0 * std::sqrt(70.0)) / 900.0;
    w[1] = (322.0 + 13.0 * std::sqrt(70.0)) / 900.0;
    w[2] = 128.0 / 225.0;
    w[3] = w[1]; // simétrico
    w[4] = w[0]; // simétrico

    double result = 0.0;
    for (int i = 0; i < 5; ++i) {
        result += w[i] * fun(aux1 * x[i] + aux2);
    }
    return aux1 * result;
}

/*double gauss5(double a, double b, fptr fun) {
    std::vector<double> x = {
        -0.906179845938664,
        -0.538469310105683,
         0.0,
         0.538469310105683,
         0.906179845938664
    };

    std::vector<double> w = {
        0.236926885056189,
        0.478628670499366,
        0.568888888888889,
        0.478628670499366,
        0.236926885056189
    };

    double aux1 = (b - a) / 2.0;
    double aux2 = (b + a) / 2.0;
    double result = 0.0;

    for (int i = 0; i < 5; ++i) {
        result += w[i] * fun(aux1 * x[i] + aux2);
    }

    return aux1 * result;
}*/

double gauss7(double a, double b, fptr fun) {
    std::vector<double> x = {
        -0.949107912342759,
        -0.741531185599394,
        -0.405845151377397,
         0.0,
         0.405845151377397,
         0.741531185599394,
         0.949107912342759
    };

    std::vector<double> w = {
        0.129484966168870,
        0.279705391489277,
        0.381830050505119,
        0.417959183673469,
        0.381830050505119,
        0.279705391489277,
        0.129484966168870
    };

    double aux1 = (b - a) / 2.0;
    double aux2 = (b + a) / 2.0;
    double result = 0.0;

    for (int i = 0; i < 7; ++i) {
        result += w[i] * fun(aux1 * x[i] + aux2);
    }

    return aux1 * result;
}

double gauss13(double a, double b, fptr fun) {
    std::vector<double> x = {
        -0.9841830547185881, -0.9175983992229779, -0.8015780907333099,
        -0.6423493394403402, -0.4484927510364469, -0.2304583159551348,
         0.0,
         0.2304583159551348,  0.4484927510364469,  0.6423493394403402,
         0.8015780907333099,  0.9175983992229779,  0.9841830547185881
    };

    std::vector<double> w = {
        0.0404840047653159, 0.0921214998377284, 0.1388735102197872,
        0.1781459807619457, 0.2078160475368885, 0.2262831802628972,
        0.2325515532308739,
        0.2262831802628972, 0.2078160475368885, 0.1781459807619457,
        0.1388735102197872, 0.0921214998377284, 0.0404840047653159
    };

    double aux1 = (b - a) / 2.0;
    double aux2 = (b + a) / 2.0;
    double result = 0.0;

    for (int i = 0; i < 13; ++i) {
        result += w[i] * fun(aux1 * x[i] + aux2);
    }

    return aux1 * result;
}

double gauss30(double a, double b, fptr fun) {
    std::vector<double> x = {
        -0.99689348407465, -0.98366812327975, -0.96002186496831,
        -0.92620004742927, -0.88256053579205, -0.82956576238277,
        -0.76777743210483, -0.69785049479331, -0.62052618298924,
        -0.53662414814202, -0.44703376953809, -0.35270472553088,
        -0.25463692616789, -0.15386991360858, -0.05147184255532,
         0.05147184255532,  0.15386991360858,  0.25463692616789,
         0.35270472553088,  0.44703376953809,  0.53662414814202,
         0.62052618298924,  0.69785049479331,  0.76777743210483,
         0.82956576238277,  0.88256053579205,  0.92620004742927,
         0.96002186496831,  0.98366812327975,  0.99689348407465
    };

    std::vector<double> w = {
        0.00796819249617, 0.01846646831109, 0.02878470788332,
        0.03879919256963, 0.04840267283059, 0.05749315621762,
        0.06597422988218, 0.07375597473771, 0.08075589522942,
        0.08689978720108, 0.09212252223779, 0.09636873717464,
        0.09959342058679, 0.10176238974841, 0.10285265289356,
        0.10285265289356, 0.10176238974841, 0.09959342058679,
        0.09636873717464, 0.09212252223779, 0.08689978720108,
        0.08075589522942, 0.07375597473771, 0.06597422988218,
        0.05749315621762, 0.04840267283059, 0.03879919256963,
        0.02878470788332, 0.01846646831109, 0.00796819249617
    };

    double aux1 = (b - a) / 2.0;
    double aux2 = (b + a) / 2.0;
    double result = 0.0;

    for (int i = 0; i < 30; ++i) {
        result += w[i] * fun(aux1 * x[i] + aux2);
    }

    return aux1 * result;
}
