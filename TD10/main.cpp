#include <Eigen/Dense>
#include <iostream>
#include <ctime>

using namespace std;
using namespace Eigen;


double evalPolynomial(const VectorXd &p, const double x){
  double result = 0.0;
  double power_x = 1.0;
    for (int i = 0; i < p.size(); i++) {
      result += p[i] * power_x;
      power_x *= x;
    }
    return result;
}

VectorXd polynomialFromRoots(const VectorXd &roots){
  VectorXd p = VectorXd::Ones(roots.size()+1);
  // Pour la premiere racine
  p(0)=-roots(0);
  // Pour les autres racines
  for (int i = 1; i < roots.size(); i++) {
    // On dépend de la case d'avant, on doit donc commencer par la fin
    for(int j = i; j > 0; --j){
      p(j) = p(j-1)-roots(i)*p(j);
    }
    p(0) *= -roots(i);
  }

  return p;
}

int main() {
  //VectorXd Polynom(3);
  //Polynom << -1, 6, 3;
  // cout << "Affichage final : " << evalPolynomial(Polynom, 3) << endl;

  VectorXd Roots(5);
  VectorXd Roots2(4);
  Roots2 << 1, 2, 3, 4;

  VectorXd result = polynomialFromRoots(Roots2);
  for (int i = 0; i < result.size(); i++) {
    cout << "La racine " << i << " est de "<< result(i) << endl;
  }



  Roots << 4, -2, 3, 4, 1;
  cout << "L'évaluation de polynome est de "<< evalPolynomial(polynomialFromRoots(Roots), 3) << endl;



  return 0;
}
