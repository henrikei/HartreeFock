#include "h_321g.h"

H_321G::H_321G()
{
    rowvec exp1 = {5.4471780, 0.8245470};
    rowvec exp2 = {0.1831920};

    rowvec coeffs1 = {0.1562850, 0.9046910};
    rowvec coeffs2 = {1.0};

    irowvec powers1 = {0, 0, 0};
    irowvec powers2 = {0, 0, 0};


    exponents.push_back(exp1);
    exponents.push_back(exp2);

    coeffs.push_back(coeffs1);
    coeffs.push_back(coeffs2);

    powers.push_back(powers1);
    powers.push_back(powers2);

    angMom = 0;

    for (int i = 0; i < (int)coeffs.size(); i++){
        int l = sum(powers.at(i));
        for (int j = 0; j < (int)coeffs.at(i).n_elem; j++){
            if (l == 0){
                coeffs.at(i)(j) *= pow(2*exponents.at(i)(j)/M_PI, 0.75);
            } else if (l == 1){
                coeffs.at(i)(j) *= pow(2*exponents.at(i)(j)/M_PI, 0.75)*2*sqrt(exponents.at(i)(j));
            }
        }
    }
}
