# GEMP - UECE - ICPC Library

Code library for competitive programming purposes.

## On the Dependencies

It's necessary to install python and latex.

```script
sudo apt-get install python
sudo apt install texlive-latex-extra
sudo apt-get install latexmk
```

## On the Updates

If you have added any new algorithms to the repository run the commands below to update the README.md file.

```script
cd latex
g++ -std=c++17 extract.cpp
./a.out
```

## On the PDF 

After updating the README.md file, execute the command below to generate the PDF.

```script
cd latex
python3 generate_pdf.py
```

You can see the current version of the PDF [here](latex/GEMP-Notebook.pdf).


## On the Contents

**Graph**
- [x] [2SAT](code/graph/2SAT.cpp)
- [x] [BFS Zero One](code/graph/BFS_zero_one.cpp)
- [x] [Binary Lifting](code/graph/binary_lifting.cpp)
- [x] [Boruvka MST](code/graph/boruvka_MST.cpp)
- [x] [Center Of A Tree](code/graph/center_of_a_tree.cpp)
- [x] [Diameter And Center Of A Tree](code/graph/diameter_and_center_of_a_tree.cpp)
- [x] [Dijkstra](code/graph/dijkstra.cpp)
- [x] [Dinic](code/graph/dinic.cpp)
- [x] [Erdos Gallai Theorem](code/graph/erdos_gallai_theorem.cpp)
- [x] [Eulirian Path](code/graph/eulirian_path.cpp)
- [x] [Floyd Sucessor Graph](code/graph/floyd_sucessor_graph.cpp)
- [x] [Ford Fulkerson](code/graph/ford_fulkerson.cpp)
- [x] [Fully Dynamic Connectivity Check If Two Vertices Are In The Same Component](code/graph/fully_dynamic_connectivity_check_if_two_vertices_are_in_the_same_component.cpp)
- [x] [Fully Dynamic Connectivity Count Conected Components](code/graph/fully_dynamic_connectivity_count_conected_components.cpp)
- [x] [Hopcroft Karp](code/graph/hopcroft_karp.cpp)
- [x] [K Short Paths](code/graph/k_short_paths.cpp)
- [x] [Knapsack Dijkstra](code/graph/knapsack_dijkstra.cpp)
- [x] [Kuhn MCBM](code/graph/kuhn_MCBM.cpp)
- [x] [Lca With Square Root Decomposition](code/graph/lca_with_square_root_decomposition.cpp)
- [x] [Lca With Tree Linearization And Segment Tree](code/graph/lca_with_tree_linearization_and_segment_tree.cpp)
- [x] [Lca With Tree Linearization And Sparse Table](code/graph/lca_with_tree_linearization_and_sparse_table.cpp)
- [x] [Longest And Shortest Path In DAG](code/graph/longest_and_shortest_path_in_DAG.cpp)
- [x] [MCE MinimumEdgeCover](code/graph/MCE_MinimumEdgeCover.cpp)
- [x] [MPC MinimumPathCover](code/graph/MPC_MinimumPathCover.cpp)
- [x] [MVC MinimumVertexCover](code/graph/MVC_MinimumVertexCover.cpp)
- [x] [Maximum Clique](code/graph/maximum_clique.cpp)
- [x] [Min Cost Max Flow](code/graph/min_cost_max_flow.cpp)
- [x] [Prim](code/graph/prim.cpp)
- [x] [Tree Isomorfism](code/graph/tree_isomorfism.cpp)


**Data Structures**
- [x] [BIT 1D](code/data_structures/BIT_1D.cpp)
- [x] [BIT 2D](code/data_structures/BIT_2D.cpp)
- [x] [BIT Range Sum And Range Update](code/data_structures/BIT_range_sum_and_range_update.cpp)
- [x] [Centroid Decomposition](code/data_structures/centroid_decomposition.cpp)
- [x] [Color Update](code/data_structures/color_update.cpp)
- [x] [DSU With Partial Persistence](code/data_structures/DSU_with_partial_persistence.cpp)
- [x] [Dynamic Segment Tree With Lazy Propagation](code/data_structures/dynamic_segment_tree_with_lazy_propagation.cpp)
- [x] [Dynamic Segment Tree With Vector](code/data_structures/dynamic_segment_tree_with_vector.cpp)
- [x] [Heavy Light Decomposition Path And Subtree Queries](code/data_structures/heavy_light_decomposition_path_and_subtree_queries.cpp)
- [x] [Heavy Light Decomposition](code/data_structures/heavy_light_decomposition.cpp)
- [x] [Implicit Treap](code/data_structures/implicit_treap.cpp)
- [x] [LiChao Tree](code/data_structures/LiChao_tree.cpp)
- [x] [Max Queue](code/data_structures/max_queue.cpp)
- [x] [Merge Sort Tree Iterative](code/data_structures/merge_sort_tree_iterative.cpp)
- [x] [Merge Sort Tree Range Order Statistics Queries](code/data_structures/merge_sort_tree_range_order_statistics_queries.cpp)
- [x] [Merge Sort Tree With Set](code/data_structures/merge_sort_tree_with_set.cpp)
- [x] [Merge Sort Tree](code/data_structures/merge_sort_tree.cpp)
- [x] [Ordered Set With BIT](code/data_structures/ordered_set_With_BIT.cpp)
- [x] [PBDS](code/data_structures/PBDS.cpp)
- [x] [Persistent Segment Tree Without Vector](code/data_structures/persistent_segment_tree_without_vector.cpp)
- [x] [Persistent Segment Tree](code/data_structures/persistent_segment_tree.cpp)
- [x] [Segment Tree Iterative](code/data_structures/segment_tree_iterative.cpp)
- [x] [Segment Tree Tree 2D](code/data_structures/segment_tree_tree_2D.cpp)
- [x] [Segment Tree With Lazy Propagation](code/data_structures/segment_tree_with_lazy_propagation.cpp)
- [x] [Sparse Table RMQ](code/data_structures/sparse_table_RMQ.cpp)
- [x] [Treap](code/data_structures/Treap.cpp)
- [x] [TreeIsomorfismWithMap](code/data_structures/treeIsomorfismWithMap.cpp)
- [x] [TreeIsomorfismWithPolynomialHashing](code/data_structures/TreeIsomorfismWithPolynomialHashing.cpp)
- [x] [Two Stacks Trick](code/data_structures/two_stacks_trick.cpp)
- [x] [Wavelet Tree](code/data_structures/wavelet_tree.cpp)


**Dynamic Programming**
- [x] [Coin Problem Topdown Dp](code/dynamic_programming/coin_problem_topdown_dp.cpp)
- [x] [Digit DP Sum Of Digits In Range](code/dynamic_programming/digit_DP_sum_of_digits_in_range.cpp)
- [x] [Edit Distance With DP](code/dynamic_programming/edit_distance_with_DP.cpp)
- [x] [Kadane 2D](code/dynamic_programming/kadane_2D.cpp)
- [x] [Kadane 3D](code/dynamic_programming/kadane_3D.cpp)
- [x] [Knapsack With Copies SqrtN Memory](code/dynamic_programming/knapsack_with_copies_sqrtN_memory.cpp)
- [x] [Knapsack With Repetition Recurrence](code/dynamic_programming/knapsack_with_repetition_recurrence.cpp)
- [x] [Knapsack Zero One Without Value](code/dynamic_programming/knapsack_zero_one_without_value.cpp)
- [x] [Knapsack0-kSemValor](code/dynamic_programming/Knapsack0-kSemValor.cpp)
- [x] [KnapsackErrichto](code/dynamic_programming/knapsackErrichto.cpp)
- [x] [KnapsackWithCopies](code/dynamic_programming/KnapsackWithCopies.cpp)
- [x] [KnapsackwithPDtopdown](code/dynamic_programming/KnapsackwithPDtopdown.cpp)
- [x] [Longest Common Subsequece And Edit Distance](code/dynamic_programming/longest_common_subsequece_and_edit_distance.cpp)
- [x] [Longest Increasing Subsequence](code/dynamic_programming/longest_increasing_subsequence.cpp)
- [x] [Subset Sum](code/dynamic_programming/subset_sum.cpp)
- [x] [Traveling Salesman Problem Bottom Up Dp](code/dynamic_programming/traveling_salesman_problem_bottom_up_dp.cpp)
- [x] [Traveling Salesman Problem Topdown Dp](code/dynamic_programming/traveling_salesman_problem_topdown_dp.cpp)


**String**
- [x] [Aho Corasick](code/string/aho_corasick.cpp)
- [x] [Dynamic Trie](code/string/dynamic_trie.cpp)
- [x] [KMP](code/string/KMP.cpp)
- [x] [LIS LDS](code/string/LIS_LDS.cpp)
- [x] [Longest Common Substring](code/string/longest_common_substring.cpp)
- [x] [Manacher](code/string/manacher.cpp)
- [x] [SA](code/string/SA.cpp)
- [x] [Suffix Array And Applications](code/string/suffix_array_and_applications.cpp)
- [x] [Suffix Array](code/string/suffix_array.cpp)
- [x] [Trie Static](code/string/trie_static.cpp)
- [x] [Trie With Vector](code/string/trie_with_vector.cpp)
- [x] [Trie](code/string/trie.cpp)
- [x] [Z Function](code/string/Z_function.cpp)


**Math**
- [x] [Baby Step Giant Step](code/math/baby_step_giant_step.cpp)
- [x] [Catalan Numbers](code/math/catalan_numbers.cpp)
- [x] [Chinese Remainder Theorem](code/math/chinese_remainder_theorem.cpp)
- [x] [Conversion Base](code/math/conversion_base.cpp)
- [x] [Counting Number Of Times That A Digit Appears Until N](code/math/counting_number_of_times_that_a_digit_appears_until_n.cpp)
- [x] [Fast Fourier Transform](code/math/fast_fourier_transform.cpp)
- [x] [Gaussian Elimination For Max Subset Xor](code/math/gaussian_elimination_for_max_subset_xor.cpp)
- [x] [Karatsuba](code/math/karatsuba.cpp)
- [x] [Matrix Exponentiation](code/math/matrix_exponentiation.cpp)
- [x] [Miller Rabin](code/math/miller_rabin.cpp)
- [x] [Mobius](code/math/mobius.cpp)
- [x] [Mod Gaussian Elimination](code/math/mod_gaussian_elimination.cpp)
- [x] [Mod Integer](code/math/Mod_Integer.cpp)
- [x] [Modular Arithmetic](code/math/modular_arithmetic.cpp)
- [x] [Mulmod Trick](code/math/mulmod_trick.cpp)
- [x] [Pollard Rho](code/math/pollard_rho.cpp)


**Geometry**
- [x] [Andrew Algorithm Convex Hull](code/geometry/andrew_algorithm_convex_hull.cpp)
- [x] [Build Two Lines That Go Through All Points Of A Set](code/geometry/build_two_lines_that_go_through_all_points_of_a_set.cpp)
- [x] [Check If A Point Is Inside A Convex Polygon](code/geometry/check_if_a_point_is_inside_a_convex_polygon.cpp)
- [x] [Convex Hull Trick](code/geometry/convex_hull_trick.cpp)
- [x] [Distance Between Nearest Pair Of Points](code/geometry/distance_between_nearest_pair_of_points.cpp)
- [x] [Dynamic Convex Hull Trick](code/geometry/dynamic_convex_hull_trick.cpp)
- [x] [Enclosing Circle R2](code/geometry/enclosing_circle_R2.cpp)
- [x] [Enclosing Circle R3](code/geometry/enclosing_circle_R3.cpp)
- [x] [Geometry Stan](code/geometry/geometry_stan.cpp)
- [x] [Graham Scan](code/geometry/graham_scan.cpp)
- [x] [Maximum Dot Product](code/geometry/maximum_dot_product.cpp)
- [x] [Radial Sort](code/geometry/radial_sort.cpp)
- [x] [Segment Intersection](code/geometry/segment_intersection.cpp)


**Miscellaneous**
- [x] [Big Num Product](code/miscellaneous/big_num_product.cpp)
- [x] [Count Divisors](code/miscellaneous/count_divisors.cpp)
- [x] [Count Sort](code/miscellaneous/count_sort.cpp)
- [x] [Counting Different Elements In A Path With Mo](code/miscellaneous/counting_different_elements_in_a_path_with_Mo.cpp)
- [x] [Custom Hash Function Unordered Map Or Set](code/miscellaneous/custom_hash_function_unordered_map_or_set.cpp)
- [x] [Divide Conquer Optimization](code/miscellaneous/divide_conquer_optimization.cpp)
- [x] [FastIO](code/miscellaneous/fastIO.cpp)
- [x] [Fence Problem With Max Flow](code/miscellaneous/fence_problem_with_max_flow.cpp)
- [x] [Gen Random Tree](code/miscellaneous/gen_random_tree.cpp)
- [x] [Histogram](code/miscellaneous/histogram.cpp)
- [x] [Inclusion Exclusion](code/miscellaneous/inclusion_exclusion.cpp)
- [x] [Index Compression](code/miscellaneous/index_compression.cpp)
- [x] [Karp Rabin](code/miscellaneous/karp_rabin.cpp)
- [x] [Knapsack With Backtraking](code/miscellaneous/knapsack_with_backtraking.cpp)
- [x] [Knuth Optimization](code/miscellaneous/knuth_optimization.cpp)
- [x] [Lontest Substring That Is A Correct Bracket Sequence](code/miscellaneous/lontest_substring_that_is_a_correct_bracket_sequence.cpp)
- [x] [Maximum Subarray Xor](code/miscellaneous/maximum_subarray_xor.cpp)
- [x] [Mo](code/miscellaneous/mo.cpp)
- [x] [Odd Rectangles Area](code/miscellaneous/odd_rectangles_area.cpp)
- [x] [Quick Sort And Select](code/miscellaneous/quick_sort_and_Select.cpp)
- [x] [Rectangles Union Area](code/miscellaneous/rectangles_union_area.cpp)
- [x] [Small To Large](code/miscellaneous/small_to_large.cpp)
- [x] [Square Root Decomposition](code/miscellaneous/square_root_decomposition.cpp)
- [x] [String Matching Hash Sqrtdecomp](code/miscellaneous/string_matching_hash_sqrtdecomp.cpp)


**Useful Scripts**
- [x] [Brute](code/useful_scripts/brute.cpp)
- [x] [Gen Tree2](code/useful_scripts/gen_tree2.cpp)
- [x] [Gen Tree](code/useful_scripts/gen_tree.cpp)
- [x] [Gen](code/useful_scripts/gen.cpp)
- [x] [Makefile](code/useful_scripts/makefile)
- [x] [Sol](code/useful_scripts/sol.cpp)
- [x] [Stress Test Animated](code/useful_scripts/stress_test_animated.sh)
- [x] [Stress With Checker](code/useful_scripts/stress_with_checker.sh)
- [x] [Stress](code/useful_scripts/stress.sh)


