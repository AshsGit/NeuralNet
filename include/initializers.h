#ifndef INCLUDE_INITIALIZERS_H
#define INCLUDE_INITIALIZERS_H

#include "../external/eigen/Eigen/Dense"

template <size_t _R, size_t _H>
Eigen::Matrix<float, _R, _H> random_matrix_init()
{
	return Eigen::MatrixXf::Random().normalize();
};

#include "./activations_impl.h"

#endif
