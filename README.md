# CFsolution
CF_solution
## Codeforces : _0Istahak

## Atcoder : Istahak_0



# System Model: Spatial-Temporal Hawkes Process for Learning Granger Causality

## 1. System Overview

```
┌─────────────────────────────────────────────────────────────────────────────┐
│                    SPATIAL-TEMPORAL HAWKES PROCESS SYSTEM                  │
├─────────────────────────────────────────────────────────────────────────────┤
│                                                                             │
│  INPUT: Raw Event Data {(ti, ei, ℓi)}i=1^N                                │
│      ↓                                                                      │
│  PHASE I: Spatial Processing                                               │
│      ↓                                                                      │
│  PHASE II: Hawkes Process Learning                                         │
│      ↓                                                                      │
│  OUTPUT: Spatial-Temporal Causality Graph G(U,E)                          │
│                                                                             │
└─────────────────────────────────────────────────────────────────────────────┘
```

### Core Components:
- **Input Module**: Multi-dimensional event sequences
- **Spatial Processing Engine**: Geographic clustering and transformation
- **Temporal Learning Engine**: MLE-SGLP algorithm adaptation
- **Causality Inference Engine**: Graph construction and validation
- **Output Interface**: Interpretable causality relationships

---

## 2. Input Data Model

### 2.1 Raw Event Structure
```
Event i = {
    Time:     ti ∈ [0, T]           # Temporal coordinate
    Type:     ei ∈ {1, 2, ..., E}   # Categorical event type
    Location: ℓi ∈ ℝ^d             # Spatial coordinate (d=2 for lat/lon)
}
```

### 2.2 Multi-Sequence Dataset
```
Dataset D = {
    Sequence 1: {(t1^1, e1^1, ℓ1^1), (t2^1, e2^1, ℓ2^1), ..., (tN1^1, eN1^1, ℓN1^1)}
    Sequence 2: {(t1^2, e1^2, ℓ1^2), (t2^2, e2^2, ℓ2^2), ..., (tN2^2, eN2^2, ℓN2^2)}
    ...
    Sequence C: {(t1^C, e1^C, ℓ1^C), (t2^C, e2^C, ℓ2^C), ..., (tNC^C, eNC^C, ℓNC^C)}
}
```

### 2.3 Data Quality Requirements
- **Temporal Ordering**: t1 ≤ t2 ≤ ... ≤ tN within each sequence
- **Spatial Validity**: Coordinates within study region boundaries
- **Type Consistency**: Event types consistently labeled across sequences

---

## 3. PHASE I: Spatial Processing System

```
┌─────────────────────────────────────────────────────────────────────────────┐
│                             PHASE I ARCHITECTURE                           │
├─────────────────────────────────────────────────────────────────────────────┤
│                                                                             │
│  Raw Locations {ℓi}     ┌─────────────────┐     Processed Locations        │
│        ↓               │   Coordinate    │            ↓                   │
│  ┌─────────────┐      →│  Preprocessing  │→    ┌─────────────┐            │
│  │ Lat/Lon     │       │     Module      │     │ Planar      │            │
│  │ Coordinates │       └─────────────────┘     │ Coordinates │            │
│  └─────────────┘                               └─────────────┘            │
│                                                        ↓                   │
│                         ┌─────────────────┐     Cluster Assignments       │
│                        │   K-means       │            ↓                   │
│                        │   Clustering    │→    ┌─────────────┐            │
│                        │    Module       │     │ {r1,r2,...} │            │
│                        └─────────────────┘     └─────────────┘            │
│                                                        ↓                   │
│  Original Events       ┌─────────────────┐     Spatial-Event Types        │
│  {(ti, ei, ℓi)}       │     Data        │     {(ti, ui)}                 │
│        ↓              │ Transformation  │            ↓                   │
│  ┌─────────────┐     →│     Module      │→    ┌─────────────┐            │
│  │ Multi-dim   │      │                 │     │ Augmented   │            │
│  │ Events      │      └─────────────────┘     │ Events      │            │
│  └─────────────┘                              └─────────────┘            │
│                                                                             │
└─────────────────────────────────────────────────────────────────────────────┘
```

### 3.1 Coordinate Preprocessing Module

**Function**: `Preprocess(ℓi) → ℓi'`

**Operations**:
1. **Projection Transformation**
   ```
   Geographic (lat, lon) → Planar (x, y)
   Methods: UTM, Lambert Conformal Conic, Mercator
   ```

2. **Boundary Enforcement**
   ```
   Filter: ℓi ∈ StudyRegion
   Remove: Outliers beyond geographic bounds
   ```

3. **Normalization**
   ```
   Scale: [xmin, xmax] → [0, 1]
   Center: Mean-centered coordinates
   ```

### 3.2 Spatial Clustering Module

**Algorithm**: K-means with K-means++ initialization

**Objective Function**:
```
J(C, R) = Σ(k=1 to K) Σ(i: ri=k) ||ℓi - ck||²
```

**Input Parameters**:
- Location set: L = {ℓi}i=1^N
- Number of clusters: K (user-specified or data-driven)
- Convergence tolerance: ε = 10^-6

**Output**:
- Region assignments: R = {r1, r2, ..., rN} where ri ∈ {1, 2, ..., K}
- Cluster centroids: C = {c1, c2, ..., cK}

**Alternative Methods**:
```
┌─────────────────┬─────────────────┬─────────────────┬─────────────────┐
│    Method       │   Advantages    │  Disadvantages  │   Use Cases     │
├─────────────────┼─────────────────┼─────────────────┼─────────────────┤
│ K-means         │ Fast, Simple    │ Convex clusters │ Uniform density │
│ GMM             │ Soft clustering │ More parameters │ Overlapping     │
│ DBSCAN          │ Irregular shape │ Density param   │ Varying density │
│ Hierarchical    │ Multi-scale     │ O(N²) complexity│ Nested regions  │
│ Administrative  │ Domain knowledge│ Fixed boundaries│ Policy analysis │
└─────────────────┴─────────────────┴─────────────────┴─────────────────┘
```

### 3.3 Data Transformation Module

**Encoding Function**:
```
ui = (ei - 1) × K + ri
```

**Properties**:
- Total spatial-event types: U = E × K
- Bijective mapping: Each (event_type, region) pair → unique index
- Preserves both spatial and event information

**Output Format**:
```
Transformed Dataset D' = {(ti, ui)}i=1^N
where ui ∈ {1, 2, ..., U}
```

---

## 4. PHASE II: Hawkes Process Learning System

```
┌─────────────────────────────────────────────────────────────────────────────┐
│                            PHASE II ARCHITECTURE                           │
├─────────────────────────────────────────────────────────────────────────────┤
│                                                                             │
│  Spatial-Event Data    ┌─────────────────┐    Basis Functions             │
│  {(ti, ui)}           │   Adaptive      │    {κm(t)}m=1^M                │
│        ↓              │    Basis        │           ↓                    │
│  ┌─────────────┐     →│   Selection     │→   ┌─────────────┐             │
│  │ Temporal    │      │    Module       │    │ Optimized   │             │
│  │ Sequences   │      └─────────────────┘    │ Basis Set   │             │
│  └─────────────┘                             └─────────────┘             │
│                                                      ↓                     │
│                      ┌─────────────────┐    Parameters {μu, auu'^(m)}     │
│                     │   MLE-SGLP      │           ↓                      │
│                     │   Algorithm     │→   ┌─────────────┐               │
│                     │   (EM-based)    │    │ Learned     │               │
│                     └─────────────────┘    │ Parameters  │               │
│                              ↑             └─────────────┘               │
│                     ┌─────────────────┐           ↓                      │
│                    │ Regularization  │    Causality Graph G(U,E)        │
│                    │ SGLP Framework  │           ↓                      │
│                    │ (L1 + Group)    │    ┌─────────────┐               │
│                    └─────────────────┘   →│ Inference   │               │
│                                           │ Engine      │               │
│                                           └─────────────┘               │
│                                                                           │
└─────────────────────────────────────────────────────────────────────────────┘
```

### 4.1 Multi-dimensional Hawkes Process Model

**Conditional Intensity Function**:
```
λu(t) = μu + Σ(u'=1 to U) ∫(0 to t⁻) φuu'(s) dNu'(t-s)
```

**Vector Representation**:
```
λ(t) = μ + Σ(ti<t) Φ(t - ti) e_νi
```

**Components**:
- **μu ≥ 0**: Baseline intensity (exogenous events)
- **φuu'(s) ≥ 0**: Impact function (influence from type u' to type u)
- **Nu'(t)**: Counting process for event type u'

### 4.2 Nonparametric Impact Function Model

**Basis Expansion**:
```
φuu'(t) = Σ(m=1 to M) auu'^(m) κm(t)
```

**Matrix Form**:
```
Φ(t) = Σ(m=1 to M) A^(m) κm(t)
```

**Basis Function Types**:
```
┌─────────────────┬─────────────────────────────────┬─────────────────┐
│    Type         │            Formula              │   Properties    │
├─────────────────┼─────────────────────────────────┼─────────────────┤
│ Gaussian        │ κm(t) = 1/√(2πh²) exp(-(t-tm)²/2h²) │ Smooth, local   │
│ Exponential     │ κm(t) = αm exp(-βm t)           │ Monotonic decay │
│ Triangular      │ κm(t) = max(0, 1-|t-tm|/h)     │ Piecewise linear│
│ B-spline        │ Recursive B-spline definition    │ Smooth, compact │
└─────────────────┴─────────────────────────────────┴─────────────────┘
```

### 4.3 Log-likelihood System

**Single Sequence Likelihood**:
```
L(Θ) = Σ(i=1 to N) log λνi(ti) - Σ(u=1 to U) ∫(0 to T) λu(s) ds
```

**Expanded Form**:
```
L(Θ) = Σ(i=1 to N) log(μνi + Σ(j<i) Σ(m=1 to M) aνi,νj^(m) κm(τij))
       - Σ(u=1 to U) (T μu + Σ(j=1 to N) Σ(m=1 to M) au,νj^(m) Km(T - tj))
```

**Multi-sequence Extension**:
```
L(Θ) = Σ(c=1 to C) Lc(Θ)
```

### 4.4 EM Algorithm System

**E-step: Responsibility Computation**
```
Current Intensity:
λνi^(k)(ti) = μνi^(k) + Σ(j<i) Σ(m=1 to M) aνi,νj^(m,k) κm(τij)

Baseline Responsibility:
pii^(k) = μνi^(k) / λνi^(k)(ti)

Trigger Responsibility:
pij^(m,k) = aνi,νj^(m,k) κm(τij) / λνi^(k)(ti)
```

**M-step: Parameter Updates**
```
Baseline Intensity:
μu^(k+1) = Σ(c=1 to C) Σ(i: νi^c = u) pii^(k) / Σ(c=1 to C) Tc

Impact Coefficients:
auu'^(m,k+1) = (-B + √(B² - 4AC)) / 2A
```

### 4.5 Regularization Framework

**SGLP Penalty Function**:
```
R(A) = αS ||A||₁ + αG Σ(u,u') ||auu'||₂ + αP E(A)
```

**Component Details**:
```
┌─────────────────┬─────────────────────────────────┬─────────────────┐
│  Regularizer    │            Formula              │    Purpose      │
├─────────────────┼─────────────────────────────────┼─────────────────┤
│ L1 (Sparsity)   │ αS Σ|auu'^(m)|                 │ Feature selection│
│ Group L2        │ αG Σ ||auu'||₂                  │ Group sparsity  │
│ Pairwise        │ αP Σ ||auu' - auv'||²          │ Similarity      │
└─────────────────┴─────────────────────────────────┴─────────────────┘
```

**Proximal Operators**:
```
Soft Thresholding: Sα(z) = sign(z)(|z| - α)₊
Group Shrinkage: Applied to coefficient vectors
```

### 4.6 Adaptive Basis Selection

**Frequency Domain Approach**:
```
Step 1: Estimate bandwidth
h = (4σ̂⁵ / 3ΣNc)^(1/5)  [Silverman's rule]

Step 2: Bound spectral density
|λ̂(ω)| ≤ ΣNc √(2/2πh²) exp(-ω²h²/2)

Step 3: Find cutoff frequency
ω₀ = min{ω : ∫(ω to ∞) |λ̂(ω')| dω' ≤ ε}

Step 4: Set basis count
M = ⌈Tω₀/π⌉

Step 5: Place basis functions
tm = (m-1)T/M, m = 1, 2, ..., M
```

---

## 5. Granger Causality Inference System

```
┌─────────────────────────────────────────────────────────────────────────────┐
│                        CAUSALITY INFERENCE ENGINE                          │
├─────────────────────────────────────────────────────────────────────────────┤
│                                                                             │
│  Learned Parameters    ┌─────────────────┐    Binary Causality            │
│  {μu, auu'^(m)}       │     Graph       │    Guu' ∈ {0,1}               │
│        ↓              │  Construction   │           ↓                    │
│  ┌─────────────┐     →│     Module      │→   ┌─────────────┐             │
│  │ Impact      │      └─────────────────┘    │ Adjacency   │             │
│  │ Functions   │                             │ Matrix      │             │
│  └─────────────┘      ┌─────────────────┐    └─────────────┘             │
│                      │  Significance   │           ↓                    │
│                      │    Testing      │    Statistical Validation      │
│                      │    Module       │           ↓                    │
│                      └─────────────────┘    ┌─────────────┐             │
│                                            │ Validated   │             │
│                      ┌─────────────────┐   │ Causality   │             │
│                     │  Effect Size    │   │ Graph       │             │
│                     │ Quantification  │   └─────────────┘             │
│                     │    Module       │          ↓                     │
│                     └─────────────────┘   Interpretable Results        │
│                                                                         │
└─────────────────────────────────────────────────────────────────────────────┘
```

### 5.1 Graph Construction Module

**Adjacency Matrix**:
```
Guu' = I{||auu'||₂ > τ}
```

**Thresholding Strategies**:
```
┌─────────────────┬─────────────────────────────────┬─────────────────┐
│    Method       │            Formula              │   Application   │
├─────────────────┼─────────────────────────────────┼─────────────────┤
│ Fixed threshold │ τ = 0.01 (user-specified)      │ Simple, fast    │
│ Percentile      │ τ = quantile(||auu'||₂, 0.95)  │ Data-adaptive   │
│ Cross-validation│ τ = argmin CV-error             │ Optimal         │
│ FDR control     │ Benjamini-Hochberg procedure    │ Statistical     │
└─────────────────┴─────────────────────────────────┴─────────────────┘
```

### 5.2 Significance Testing Module

**Bootstrap Procedure**:
```
For b = 1 to B:
    1. Simulate surrogate dataset from fitted model Θ̂
    2. Re-estimate parameters: Θ̂^(b)
    3. Compute test statistics: Tuu'^(b) = ||âuu'^(b)||₂

Empirical p-value:
p-value(uu') = #{b : Tuu'^(b) ≥ Tuu'} / B
```

**Multiple Testing Correction**:
```
FDR Control (Benjamini-Hochberg):
1. Sort p-values: p(1) ≤ p(2) ≤ ... ≤ p(U²)
2. Find largest k: p(k) ≤ k·α/U²
3. Reject hypotheses 1, 2, ..., k
```

### 5.3 Effect Size Quantification

**Infectivity Measure**:
```
Infectivity(uu') = Σ(m=1 to M) auu'^(m) ∫(0 to ∞) κm(s) ds
```

**Interpretation**: Expected number of type-u events triggered by one type-u' event

### 5.4 Spatial-Temporal Causality Taxonomy

**For indices u = (e-1)K + k and u' = (e'-1)K + k':**

```
┌─────────────────┬─────────────────┬─────────────────┬─────────────────┐
│ Causality Type  │  Event Types    │    Regions      │  Interpretation │
├─────────────────┼─────────────────┼─────────────────┼─────────────────┤
│ Intra-Intra     │ e = e'          │ k = k'          │ Self-excitation │
│ Intra-Inter     │ e = e'          │ k ≠ k'          │ Spatial spread  │
│ Inter-Intra     │ e ≠ e'          │ k = k'          │ Local cascades  │
│ Inter-Inter     │ e ≠ e'          │ k ≠ k'          │ Cross-influence │
└─────────────────┴─────────────────┴─────────────────┴─────────────────┘
```

---

## 6. Computational Complexity Model

### 6.1 Time Complexity

**Phase I Complexity**:
```
┌─────────────────┬─────────────────────────────────────────────────────┐
│    Component    │                 Complexity                          │
├─────────────────┼─────────────────────────────────────────────────────┤
│ Preprocessing   │ O(N·d)                                             │
│ K-means         │ O(N·d·K·Titer)                                     │
│ Transformation  │ O(N)                                               │
│ Total Phase I   │ O(N·d·K·Titer)                                     │
└─────────────────┴─────────────────────────────────────────────────────┘
```

**Phase II Complexity**:
```
┌─────────────────┬─────────────────────────────────────────────────────┐
│    Component    │                 Complexity                          │
├─────────────────┼─────────────────────────────────────────────────────┤
│ Basis selection │ O(N log N)                                         │
│ EM algorithm    │ O(M·N²·U²) per iteration                          │
│ Regularization  │ O(M·U²)                                            │
│ Total Phase II  │ O(TEM·M·N²·U²) where TEM = EM iterations           │
└─────────────────┴─────────────────────────────────────────────────────┘
```

**Overall Complexity**: O(N·d·K·Titer + TEM·M·N²·(E·K)²)

### 6.2 Space Complexity

```
┌─────────────────┬─────────────────────────────────────────────────────┐
│    Component    │                Memory Usage                         │
├─────────────────┼─────────────────────────────────────────────────────┤
│ Event storage   │ O(N)                                               │
│ Parameters      │ O(M·U²) = O(M·E²·K²)                              │
│ Responsibilities│ O(N²) [sparse with truncation]                     │
│ Basis cache     │ O(M·N²) [sparse]                                   │
│ Total          │ O(N² + M·E²·K²)                                     │
└─────────────────┴─────────────────────────────────────────────────────┘
```

---

## 7. System Outputs and Interpretation

### 7.1 Primary Outputs

```
Output Package = {
    ┌─────────────────┐
    │ Causality Graph │ ──── G(U,E): Directed graph with U nodes
    └─────────────────┘
    
    ┌─────────────────┐
    │ Impact Matrix   │ ──── I ∈ ℝ^(U×U): Effect sizes
    └─────────────────┘
    
    ┌─────────────────┐
    │ Parameters      │ ──── Θ̂ = {μ̂, Â^(1), ..., Â^(M)}
    └─────────────────┘
    
    ┌─────────────────┐
    │ Spatial Regions │ ──── {c₁, c₂, ..., cₖ}, assignments
    └─────────────────┘
    
    ┌─────────────────┐
    │ Diagnostics     │ ──── Log-likelihood, AIC, BIC, p-values
    └─────────────────┘
}
```

### 7.2 Interpretability Framework

**Regional Analysis**:
```
Regional Activity Score:
A(k) = Σ(e=1 to E) μ(e-1)K+k

Cross-Regional Influence:
C(k→k') = Σ(e,e'=1 to E) I((e-1)K+k, (e'-1)K+k')
```

**Event Type Analysis**:
```
Event Clustering within Regions:
Intra-regional causality patterns

Spatial Propagation Patterns:
How event types spread across space
```

**Temporal Dynamics**:
```
Peak Impact Times:
t* = argmax_t Σ(m=1 to M) auu'^(m) κm(t)

Decay Rates:
Half-life analysis of impact functions
```

---

## 8. System Validation and Quality Assurance

### 8.1 Validation Pipeline

```
┌─────────────────────────────────────────────────────────────────────────────┐
│                           VALIDATION FRAMEWORK                             │
├─────────────────────────────────────────────────────────────────────────────┤
│                                                                             │
│  Synthetic Data     ┌─────────────────┐    Ground Truth Comparison         │
│  Generation        │   Parameter     │                                     │
│        ↓           │   Recovery      │                                     │
│  ┌─────────────┐  →│   Validation    │→                                    │
│  │ Controlled  │   └─────────────────┘                                     │
│  │ Experiments │                                                           │
│  └─────────────┘   ┌─────────────────┐    Performance Metrics             │
│                   │  Computational  │                                     │
│                   │  Performance    │                                     │
│                   │  Benchmarking   │                                     │
│                   └─────────────────┘                                     │
│                                                                           │
│  Real Data        ┌─────────────────┐    Domain Expert Validation        │
│  Application     │   Predictive    │                                     │
│        ↓         │   Performance   │                                     │
│  ┌─────────────┐ →│   Assessment    │→                                    │
│  │ Domain      │  └─────────────────┘                                     │
│  │ Datasets    │                                                          │
│  └─────────────┘  ┌─────────────────┐    Interpretability Assessment     │
│                  │  Interpretability│                                     │
│                  │   and Usability │                                     │
│                  │   Evaluation    │                                     │
│                  └─────────────────┘                                     │
│                                                                           │
└─────────────────────────────────────────────────────────────────────────────┘
```

### 8.2 Quality Metrics

**Accuracy Metrics**:
```
┌─────────────────┬─────────────────────────────────────────────────────┐
│     Metric      │                 Formula                             │
├─────────────────┼─────────────────────────────────────────────────────┤
│ Precision       │ TP / (TP + FP)                                     │
│ Recall          │ TP / (TP + FN)                                     │
│ F1-Score        │ 2·Precision·Recall / (Precision + Recall)         │
│ AUROC           │ Area under ROC curve                               │
│ AUPRC           │ Area under Precision-Recall curve                 │
└─────────────────┴─────────────────────────────────────────────────────┘
```

**Stability Metrics**:
```
Parameter Variance: Var(Θ̂) across multiple runs
Clustering Stability: Adjusted Rand Index consistency
Cross-validation Error: k-fold CV performance
```

---

## 9. Implementation Guidelines

### 9.1 Software Architecture

```
┌─────────────────────────────────────────────────────────────────────────────┐
│                         SOFTWARE ARCHITECTURE                              │
├─────────────────────────────────────────────────────────────────────────────┤
│                                                                             │
│  ┌─────────────┐    ┌─────────────┐    ┌─────────────┐    ┌─────────────┐ │
│  │    Data     │    │   Spatial   │    │   Hawkes    │    │  Causality  │ │
│  │   Loader    │ → │  Processor  │ → │   Learner   │ → │  Inference  │ │
│  │   Module    │    │   Module    │    │   Module    │    │   Module    │ │
│  └─────────────┘    └─────────────┘    └─────────────┘    └─────────────┘ │
│         ↓                   ↓                   ↓                   ↓     │
│  ┌─────────────┐    ┌─────────────┐    ┌─────────────┐    ┌─────────────┐ │
│  │Configuration│    │ Clustering  │    │ Optimization│    │Visualization│ │
│  │   Manager   │    │  Utilities  │    │   Engine    │    │   Engine    │ │
│  └─────────────┘    └─────────────┘    └─────────────┘    └─────────────┘ │
│                                                                             │
└─────────────────────────────────────────────────────────────────────────────┘
```

### 9.2 Key Implementation Considerations

**Numerical Stability**:
```
• Add ε ∈ [10⁻¹², 10⁻⁸] to intensities before log
• Truncate kernels at horizon W where κm(W) ≈ 0
• Use numerically stable log-sum-exp operations
• Implement adaptive step sizing in optimization
```

**Scalability Optimizations**:
```
• Sparse matrix operations (CSR/CSC format)
• Vectorized computations (NumPy/JAX)
• GPU acceleration for matrix operations
• Parallel processing for cross-validation
• Memory-mapped arrays for large datasets
```

**Robustness Features**:
```
• Input validation and error handling
• Automatic parameter bounds enforcement
• Convergence diagnostics and warnings
• Fallback strategies for edge cases
```

---

## 10. System Benefits and Advantages

### 10.1 Theoretical Advantages

```
✓ Maintains all theoretical guarantees of MLE-SGLP
✓ Convex optimization with global optimum
✓ Statistical consistency under regularity conditions
✓ Principled uncertainty quantification
✓ Formal causality interpretation (Granger causality)
```

### 10.2 Computational Advantages

```
✓ Polynomial time complexity O(N²U²M)
✓ Efficient sparse regularization
✓ Parallelizable across event type pairs
✓ Memory-efficient with truncation
✓ Scalable to large datasets
```

### 10.3 Practical Advantages

```
✓ Handles irregular spatial distributions
✓ Flexible spatial resolution (user-controlled K)
✓ Interpretable spatial-temporal causality patterns
✓ Works with limited training data (regularization)
✓ Domain-agnostic methodology
```

---

## 11. Applications and Use Cases

### 11.1 Domain Applications

```
┌─────────────────┬─────────────────────────────────────────────────────┐
│    Domain       │              Use Cases                              │
├─────────────────┼─────────────────────────────────────────────────────┤
│ Epidemiology    │ Disease outbreak tracking, intervention planning   │
│ Criminology     │ Crime pattern analysis, predictive policing        │
│ Urban Planning  │ Traffic flow analysis, infrastructure planning     │
│ Social Media    │ Information diffusion, influence propagation       │
│ Finance         │ Market contagion, risk management                  │
│ Seismology      │ Earthquake aftershock prediction                   │
│ Ecology         │ Species migration, habitat connectivity            │
│ Marketing       │ Viral marketing, brand diffusion                   │
└─────────────────┴─────────────────────────────────────────────────────┘
```

### 11.2 Expected Insights

```
• Spatial propagation patterns of events
• Critical regions for intervention
• Cross-regional influence networks
• Temporal dynamics of spatial spread
• Event type interactions within/across regions
• Early warning indicators for cascading events
```

---

This comprehensive system model provides a complete framework for understanding, implementing, and applying the spatial-temporal Hawkes process methodology for learning Granger causality. The structured presentation ensures clarity while maintaining technical rigor and practical applicability.
