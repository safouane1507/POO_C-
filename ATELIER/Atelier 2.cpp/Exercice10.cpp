#include <iostream>
using namespace std;

class Complexe {
public:
    float re, im;
    Complexe(float r = 0, float i = 0) { re = r; im = i; }
    Complexe addition(Complexe c) { return Complexe(re + c.re, im + c.im); }
    Complexe soustraction(Complexe c) { return Complexe(re - c.re, im - c.im); }
    Complexe multiplication(Complexe c) { return Complexe(re * c.re - im * c.im, re * c.im + im * c.re); }
    Complexe division(Complexe c) {
        float denom = c.re * c.re + c.im * c.im;
        return Complexe((re * c.re + im * c.im) / denom, (im * c.re - re * c.im) / denom);