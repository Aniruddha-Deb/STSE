#include "market.hpp"

Market::Market() {
    // market spawning algorithm:
    // - Spawn N stocks 
    // - For each stock:
    //   - allocate it a market cap
    //   - (Optional, maybe later) allocate it a growth prospect
    //     Market cap is determined from a lognormal distribution (a normal
    //     distribution was fitted to logarithm of the numbers in 
    //     market_cap_data.txt, giving mu~5 and sigma~1. Ideally, would've been
    //     an exponential distribution, but fitting the tail was creating 
    //     problems.), whereas growth prospects are determined by a uniform random
    //     variable in (-30°,30°). (? Prove this creates a brownian motion w/ drift)
    // - Randomly partition the market M into submarkets M_i
    // - For each submarket:
    //   - Assign a strong correlation (b/w 0.7-1) to the companies inside the submarket
    // - For all pairs of submarkets M_i and M_j:
    //   - Assign a weak correlation W (b/w 0.3-0.7) to the two submarkets
    //   - Assign a correlation W_ab between stock a \in M_i and stock b \in M_b. 
    //     W_ab would be normally distributed about W with an appropriate standard
    //     deviation (say,10% of W?)
    //
    // This gives us enough parameters for our Market: defining intercorrelated
    // brownian motions across all the stocks being traded.
    //
    // ? is this the property of the market, or of an _analyst_? The analyst 
    // would determine the Fair Value, in a sense, of the securities. Agents
    // would have the ability to take the analyst's inputs in that case. Maybe 
    // multiple analyst inputs would be available, which agents can base their 
    // strategies on?
    // Analyst would be a non-market participating agent. 
    // 
}