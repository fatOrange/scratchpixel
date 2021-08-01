#include <random> 
#include <cstdlib> 
#include <cstdio> 
 
static const int MAX_NUM = 20;  // items in the population are numbered (number between 0 and 20) 
static const int MAX_FREQ = 50; // number of items holding a particular number varies between 1 and 50 
 
int main(int argc, char **argv) 
{ 
    int minSampples = atoi(argv[1]); // minimum sample size 
    int maxSampples = atoi(argv[2]); // maximum sample size 
    std::mt19937 rng; 
    int population[MAX_NUM + 1]; 
    int popSize = 0; 
    float popMean = 0; 
    float popVar = 0; 
    static const int numSamples = 1000; 
 
    rng.seed(17); 
 
    // creation population
    std::uniform_int_distribution<uint32_t> distr(1,MAX_FREQ); 
 
    for (int i = 0; i <= MAX_NUM; ++i) { 
        population[i] = distr(rng); 
        popSize += population[i]; 
        popMean += population[i] * i; // prob * x_i 
        popVar += population[i] * i * i; // prob * x_i^2 
    } 
 
    popMean /= popSize; 
    popVar /= popSize; 
    popVar -= popMean * popMean; 
    fprintf(stderr, "size %d mean %f var %f\n", popSize, popMean, popVar); 
     std::uniform_int_distribution<uint32_t> n_samples_distr(minSampples, maxSampples); 
    std::uniform_int_distribution<uint32_t> pick_item_distr(0, popSize - 1); 
 
    float expectedValueMean = 0, varianceMean = 0;
    int meanCount[MAX_NUM+1];
    for(int i = 0;i<MAX_NUM;i++) meanCount[i] = 0;
    // now that we have some data and stats to work with sample it
    for (int i = 0; i < numSamples; ++i) { 
        int n = n_samples_distr(rng); // sample size 
        float sample_mean = 0, sample_variance = 0; 
        // draw samples from population and compute stats
        for (int j = 0; j < n; ++j) { 
            int item_index = pick_item_distr(rng), k; 
            for (k = 0; k <= MAX_NUM; ++k) { 
                item_index -= population[k]; 
                if (item_index < 0) break; 
 
            } 
            // k is the value we picked up from population, 
            // this is the outcome a number between [0:20]
            sample_mean += k; 
            sample_variance += k * k; 
        } 
        sample_mean /= n; 
        sample_variance /= n; 
        sample_variance -= sample_mean * sample_mean; 
        
        float c1[3] = { 1, 0, 0 }; 
        float c2[3] = { 0, 0, 1 }; 
        float t = (n - minSampples) / (float)(maxSampples - minSampples); 
        float r = c1[0] * (1 - t) + c2[0] * t; 
        float g = c1[1] * (1 - t) + c2[1] * t; 
        float b = c1[2] * (1 - t) + c2[2] * t; 
        printf("sample mean: %f sample variance: %f col: %f %f %f;\n", sample_mean, sample_variance, r, g, b); 
    } 
 
    return 0; 
} 