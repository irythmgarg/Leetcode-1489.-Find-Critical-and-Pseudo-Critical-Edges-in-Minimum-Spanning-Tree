# Leetcode-1489.-Find-Critical-and-Pseudo-Critical-Edges-in-Minimum-Spanning-Tree
# ✨ Critical and Pseudo-Critical Edges in Minimum Spanning Tree

This project solves the LeetCode problem: **Critical and Pseudo-Critical Edges in Minimum Spanning Tree** using **Kruskal's Algorithm** with **Disjoint Set Union (DSU)**. It efficiently classifies edges into two categories:

- ✅ **Critical Edges**: Edges that are essential to form the Minimum Spanning Tree (MST).
- ✅ **Pseudo-Critical Edges**: Edges that can be part of some MST but are not necessary.

---

## 🚀 Problem Statement
Given a weighted, undirected graph, your task is to find:
- All **critical** edges (removing them increases the MST weight or disconnects the graph)
- All **pseudo-critical** edges (they can appear in some MSTs but not all)

---

## ⚖️ Algorithm Used
- **Kruskal's MST Algorithm**
- **Disjoint Set Union (Union Find)** with Path Compression and Union by Rank

---

## 📊 Approach

### Step 1: Track Edge Indices
Each edge is appended with its original index before sorting.

### Step 2: Sort Edges
Sort the edge list based on weight (ascending).

### Step 3: Compute Base MST
Run Kruskal's algorithm without any edge exclusion or inclusion to get the MST weight.

### Step 4: Classify Each Edge
- **Critical Check**: Exclude the edge, run Kruskal. If resulting MST is invalid or heavier, it's critical.
- **Pseudo-Critical Check**: Force-include the edge, run Kruskal. If MST weight remains the same, it's pseudo-critical.

---

## 📈 Time & Space Complexity
- **Time Complexity**: \(O(E \log E + E \cdot \alpha(N))\)
- **Space Complexity**: \(O(N + E)\)

Where:
- \(E\) = Number of edges
- \(N\) = Number of nodes
- \(\alpha\) = Inverse Ackermann function (nearly constant)

---

## 📁 Example
```cpp
Input: n = 5,
edges = [[0,1,1],[1,2,1],[2,3,2],[0,3,2],[0,4,3],[3,4,3],[1,4,6]]
Output: [[0,1],[2,3,4,5]]
Explanation:
- Edges [0,1] are critical.
- Edges [2,3,4,5] can appear in some MSTs but not all.
```

---


## 💡 Key Concepts
- **Disjoint Set (Union-Find)**: Efficiently checks for cycle formation and merges components.
- **Kruskal's Algorithm**: Optimal for MST in sparse graphs.
- **Edge Classification**: Helps identify edge impact in overall connectivity and weight.

---

## 🚀 Extensions
This approach can be used for:
- Road network planning
- Communication link optimization
- Resilient network design

---

## 📄 License
This implementation is for educational purposes and can be reused with attribution.

---

Made with ❤️ using C++ and classic algorithms!

