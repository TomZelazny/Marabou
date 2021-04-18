#include <iostream>
#include <random>
#include <iomanip>
constexpr int FLOAT_MIN = 0;
constexpr int FLOAT_MAX = 1;

class DeepPolyLbHeuristics
{
public:
    static void defaultLb(
        unsigned i,
        double sourceUb,
        double sourceLb,
        double *_symbolicLb,
        double *_symbolicLowerBias,
        double *_lb)
    {
        // printf( "Using default DeepPoly heuristic for lower bound\n" );
        // For the lower bound, in general, x_f >= lambda * x_b, where
        // 0 <= lambda <= 1, would be a sound lower bound. We
        // use the heuristic described in section 4.1 of
        // https://files.sri.inf.ethz.ch/website/papers/DeepPoly.pdf
        // to set the value of lambda (either 0 or 1 is considered).
        if (sourceUb > -sourceLb)
        {
            // lambda = 1
            // Symbolic lower bound: x_f >= x_b
            // Concrete lower bound: x_f >= sourceLb
            _symbolicLb[i] = 1;
            _symbolicLowerBias[i] = 0;
            _lb[i] = sourceLb;
        }
        else
        {
            // lambda = 1
            // Symbolic lower bound: x_f >= 0
            // Concrete lower bound: x_f >= 0
            _symbolicLb[i] = 0;
            _symbolicLowerBias[i] = 0;
            _lb[i] = 0;
        }
    };
    //
    static void randomCoeffLb(
        unsigned i,
        double sourceLb,
        double *_symbolicLb,
        double *_symbolicLowerBias,
        double *_lb)
    {
        std::random_device rd;
        std::default_random_engine eng(rd());
        std::uniform_real_distribution<float> distr(FLOAT_MIN, FLOAT_MAX);
        std::setprecision(6);
        const float randCoeff = distr(eng);
        // printf("Using random DeepPoly heuristic for lower bound\n");
        _symbolicLb[i] = randCoeff;
        _symbolicLowerBias[i] = 0;
        _lb[i] = randCoeff * sourceLb;
    };
    //
    // static void ratioHeuristic(
    //     unsigned i,
    //     double sourceUb,
    //     double sourceLb,
    //     double *_symbolicLb,
    //     double *_symbolicLowerBias,
    //     double *_lb)
    // {};
    // //
    // static void defaultWithDeltaAndHalfHeuristic(
    //     unsigned i,
    //     double sourceUb,
    //     double sourceLb,
    //     double *_symbolicLb,
    //     double *_symbolicLowerBias,
    //     double *_lb)
    // {};
    // //
    // static void cardCountingHeuristic(
    //     unsigned i,
    //     double sourceUb,
    //     double sourceLb,
    //     double *_symbolicLb,
    //     double *_symbolicLowerBias,
    //     double *_lb)
    // {};
};