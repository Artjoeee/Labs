#pragma once

namespace Varparm 
{
    // ivarparm функция
    int ivarparm(int count, ...);

    // svarparm функция
    int svarparm(short count, ...);

    // fvarparm функция
    double fvarparm(float maxFloat, ...);

    // dvarparm функция
    double dvarparm(double maxDouble, ...);
}