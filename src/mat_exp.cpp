// [[Rcpp::depends(RcppArmadillo)]]

#include <RcppArmadillo.h>
#include <iostream>

using namespace std;
using namespace Rcpp;

// [[Rcpp::export]]
// gaussian kernel transform in cpp
arma::mat gauss_cpp(const arma::mat& x, double sigma) {
  // arma::mat y = arma::exp(-arma::pow(x, 2) / (2 * sigma * sigma));
  // exp(-((x-mu)^2)/(2*sigma^2)) / (sigma*sqrt(2*pi))
  arma::mat y = arma::exp(-arma::square(x) / (2 * sigma * sigma)) / (sigma * sqrt(2 * M_PI));
  return y;
}

// [[Rcpp::export]]
// gaussian kernel transform for a vector in cpp
arma::vec gauss_vec_cpp(const arma::vec& x, double sigma) {
  // arma::mat y = arma::exp(-arma::pow(x, 2) / (2 * sigma * sigma));
  // exp(-((x-mu)^2)/(2*sigma^2)) / (sigma*sqrt(2*pi))
  arma::vec y = arma::exp(-arma::square(x) / (2 * sigma * sigma)) / (sigma * sqrt(2 * M_PI));
  return y;
}

// [[Rcpp::export]]
arma::vec rep_each_cpp(int l, int n) {
  arma::vec x = arma::linspace(1, l, l);
  arma::vec y = arma::repelem(x, n, 1);
  return y;
}

// [[Rcpp::export]]
// compute euclidean distances in cpp
arma::mat euclidean_cpp(const arma::mat& x, const arma::mat& y) {
  arma::mat d = arma::sqrt(arma::sum(arma::pow(x - y, 2), 1));
  return d;
}

// [[Rcpp::export]]
// average a list of matrices in rcpp
arma::sp_mat meanMat_cpp(const List& l, int nrow, int ncol) {
  arma::sp_mat m;
  m.zeros(nrow, ncol);

  for (int i = 0; i < l.size(); i++) {
    // m += l[i];
    arma::sp_mat x = l[i];
    m = m + x;
  }
  // m /= l.size();
  m = m / l.size();
  return m;
}

// [[Rcpp::export]]
// compute variance of each column of a matrix in cpp
arma::mat varMat_cpp(const arma::mat& x) {
  arma::mat m = arma::var(x, 0);
  return m;
}

// [[Rcpp::export]]
// compute standard deviation of each column of a matrix in cpp
arma::mat stdMat_cpp(const arma::mat& x) {
  arma::mat m = arma::stddev(x, 0);
  return m;
}


// [[Rcpp::export]]
// compute pearson correlation between correpsonding columns of two matrices in cpp
arma::vec pearson_col_cpp(const arma::mat& x, const arma::mat& y) {
  arma::vec res(x.n_cols);
  for (int i = 0; i < x.n_cols; i++) {
    res.subvec(i,i) = arma::cor(x.col(i), y.col(i), 0);
  }
  return res;

}










// // [[Rcpp::export]]
// // generate regular sequence in cpp
// arma::vec reg_seq_cpp(int n, int k) {
//   arma::vec x = arma::linspace(0, n*k, n+1);
//   return x;
// }

// // [[Rcpp::export]]
// // repeat vector by a given number of times
// arma::vec rep_vec_cpp(arma::vec x, int n) {
//   arma::vec y = arma::repmat(x, n, 1);
//   return y;
// }

// // [[Rcpp::export]]
// // repeat each element in a vector by a given number of times
// arma::vec rep_each_cpp(arma::vec x, int n) {
//   arma::vec y = arma::repelem(x, n, 1);
//   return y;
// }


// // [[Rcpp::export]]
// // gaussian kernel transform in cpp
// arma::mat gauss_kernel_cpp2(arma::mat x, double sigma) {
//   // arma::mat y = arma::exp(-arma::pow(x, 2) / (2 * sigma * sigma));
//   arma::mat y = arma::exp(-arma::pow(x, 2) / (2 * sigma * sigma));
//   return y;
// }

// // [[Rcpp::export]]
// // element-wise matrix exponential in cpp
// arma::mat expmat_cpp(arma::mat x) {
//   arma::mat y = arma::exp(x);
//   return y;
// }