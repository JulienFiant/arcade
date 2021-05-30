//
// EPITECH PROJECT, 2018
// VectorCalc
// File description:
// process SFML vectors
//

#include "VectorCalc.hpp"
#include <iostream>

float VectorCalc::length_v2(float *v)
{
    return sqrt(v[0] * v[0] + v[1] * v[1]);
}

float VectorCalc::length_v2(float *v1, float *v2)
{
    return sqrt(((v2[0] - v1[0]) * (v2[0] - v1[0])) + ((v2[1] - v1[1]) * (v2[1] - v1[1])));
}

float *VectorCalc::base_v2(float *v)
{
    float tmp[2] = {v[0], v[1]};
    float *ret = tmp;
    float len = length_v2(v);

    ret[0] = ((float)ret[0]) / len;
    ret[1] = ((float)ret[1]) / len;
    return ret;
}

float *VectorCalc::base_v2(float *v1, float *v2)
{
    float tmp[2] = {v2[0] - v1[0], v2[1] - v1[1]};
    float *ret = tmp;
    float len = length_v2(v1, v2);

    ret[0] = ((float)ret[0]) / len;
    ret[1] = ((float)ret[1]) / len;
    return ret;
}
