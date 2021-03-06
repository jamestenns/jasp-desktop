
Bayesian Paired Samples T-Test
==========================

The paired samples t-test allows you to test the null hypothesis that the population mean of the difference between paired observations equals 0.

Assumptions
-----------
- Numeric difference score.
- The difference scores are a random sample from the population.
- The difference scores are normally distributed in the population.

Options
-------
### Hypothesis:
- Group 1 &ne; Group 2: Two-sided alternative hypothesis that the population mean of the difference does not equal 0.
- Group 1 &gt Group 2: One-sided alternative hypothesis that the population mean of the difference is larger than 0.
- Group 1 &lt; Group 2: One sided alternative hypothesis that the population mean of the difference is smaller than 0.

### Bayes Factor
- BF10: Bayes factor to quantify evidence for the alternative hypothesis relative to the null hypothesis.
- BF01: Bayes factor to quantify evidence for the null hypothesis relative to the alternative hypothesis.
- Log(BF10): Natural logarithm of BF10.

### Prior
- Cauchy prior width: Scale of the Cauchy prior density on effect size under the alternative hypothesis, the default is 0.707.

### Missing Values
 - Exclude cases analysis by analysis: In case of multiple t-tests within a single analysis, each test will be conducted using all cases with valid data for the difference score for the particular t-test. Sample sizes may therefore vary across the tests.
 - Exclude cases listwise: In case of multiple t-tests within a single analysis, each t-test will be conducted using only cases with valid data for all difference scores. Sample size is therefore constant across the tests. 
 
Output
-------

### Bayesian One Sample T-Test
- BF10 (or BF01): Bayes factor. If one-sided test is requested: 
  - BF+0: Bayes factor that quantifies evidence for the one-sided alternative hypothesis that the difference is larger than 0.
  - BF-0: Bayes factor that quantifies evidence for the one-sided alternative hypothesis that the difference is smaller than 0.
  - BF0+: Bayes factor that quantifies evidence for the null hypothesis relative to the one-sided alternative hypothesis that the difference is larger than 0.
  - BF0-: Bayes factor that quantifies evidence for the null hypothesis relative to the one-sided alternative hypothesis that the difference is smaller than 0.
- error %: The error of a Gaussian quadrature integration routine used for the computation of the Bayes factor.

Example
-------

### Data set: 
- Moon and Aggression

### Input: 
- The null hypothesis that the average difference between the number of disruptive behaviors on full moon days ("Moon") and not full moon days ("Other") equals 0 is tested against the 
two sided alternative hypothesis that the average difference in disruptive behaviors differs from 0.

### Output: 
- The data are 1521 times more likely under the two sided alternative hypothesis that the average difference between the number of disruptive behaviors on full moon days ("Moon") and not full moon days ("Other") 
differs from 0 than under the null hypothesis that the average difference in disruptive behaviors equals 0, BF10 = 1521, with error % = 5.014e-9. 

Additional Options
-------
### Additional Statistics:
- Descriptives: Sample size, sample mean, sample standard deviation, standard error of the mean.

### Plots
- Prior and posterior: Displays the prior and posterior density of the effect size under the alternative hypothesis.
  - Additional info: Adds Bayes factor computed with the user-defined prior; adds pizza plot depicting the odds of the data under the null vs. alternative hypothesis; adds the median and 95% credible interval of the posterior density.
- Bayes factor robustness check: Displays Bayes factor as a function of the width of the Cauchy prior on effect size. The scale of the Cauchy prior is varied between 0 and 1.5, creating progressively more uninformative priors.
- Sequential analysis: Displays the development of the Bayes factor as the data come in using the user-defined prior. 
 - Robustness check: Additional to the analysis with the user-defined prior, displays the results of the sequential analysis using the wide (TBA) and ultrawide prior (TBA).
 
Additional Output
-------

### Descriptives:
- N: Sample size.
- Mean: Sample mean. 
- SD: Sample standard deviation.
- SE: Standard error of the mean.

### Plots:
- Prior and posterior: Displays the prior (dashed line) and posterior (solid line) density of the effect size under the alternative hypothesis; the gray circles represent the height of the prior and the posterior density at effect size delta = 0. The horizontal solid line represents the width of the 95% credible interval of the posterior.
 - Additional info: Displays the Bayes factor computed with the user-defined prior; displays a pizza plot depicting the odds of the data under the null vs. alternative hypothesis; displays the median and 95% credible interval of the posterior density.
- Bayes factor robustness check: Displays Bayes factor as a function of the width of the Cauchy prior on effect size. The black circle represents the Bayes factor computed with a wide prior; the white circle represents the Bayes factor computed with an ultrawide prior; the gray circle represents the Bayes factor computed with the user-defined prior.
- Sequential analysis: Displays the development of the Bayes factor as a function of the number of paired observations (n) using the user-defined prior.
 - Robustness check: Displays the development of the Bayes factor as a function of the number of paired observations (n) using the wide and ultrawide prior. The black circle represents the Bayes factor computed with a wide prior; the white circle represents the Bayes factor computed with an ultrawide prior; the gray circle represents the Bayes factor computed with the user-defined prior.

References
-------
- Morey, R.D., Rouder, J.N., Pratte, M.S., & Speckman, P.L. (2011). Using MCMC chain outputs to efficiently estimate Bayes factors. Journal of Mathematical Psychology, 55, 368-378.
- Rouder, J.N., Speckman, P.L., Sun, D., Morey, R.D., & Iverson, G. (2009). Bayesian t-tests for accepting and rejecting the null hypothesis. Psychonomic Bulletin & Review, 16, 225-237.
- Perception and Cognition Lab (University of Missouri): Bayes factor calculators. http://pcl.missouri.edu/bayesfactor
