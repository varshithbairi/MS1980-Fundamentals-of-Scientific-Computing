# Atomic Toy Model – Accuracy, Efficiency, Dissipation and Innovation

Computational Thinking Project · MS1980 Fundamentals of Scientific Computing
Instructors: Prof. Anuj Goyal and Prof. Saswata Bhattacharyya · **Group 16**

A small 2D molecular-dynamics simulator: 20 soft atoms in a 10 × 10 box. Overlapping atoms are pushed apart by springs, U = ½ k (r − r₀)², with k = 10 and cutoff r_c = r₀ = 1, and the atoms move with velocity Verlet (Δt = 0.01). With this simulator we study energy conservation and the choice of time step, dissipation, float32 vs float64, the speed and memory of Python, NumPy and C, and two improvements of our own: a cell-linked neighbour list and spring walls.

## Group members

| Name | Tasks |
|---|---|
| Varshith | Model setup, pair forces, verification and animation (Tasks 1, 2) |
| Merwyn Kumar | Time integration, energy and dissipation (Tasks 3, 4) |
| Jeevan Paul | Precision, Python/NumPy/C timing and memory (Tasks 5, 6, 7) |
| Susheel Chandra | Innovations, final recommendation, report (Tasks 8, 9) |

## Files

| File / folder | What it is |
|---|---|
| `atomic_toy_model.ipynb` | All the code for Tasks 1–9, with comments. It has already been run, so every table, plot and movie can be seen without running it again. |
| `pair_forces.c` | C version of the pair force (Task 6). The notebook compiles it with gcc, so it must be in the same folder as the notebook. |
| `report.pdf` | The project report: model, algorithm, implementation details, verification and all results. |
| `animations/` | The three movies as GIF and MP4: `trajectory_N20` (the 20-atom trajectory), `euler_vs_verlet_dt0.05` (Euler next to Verlet at a big time step) and `conservative_vs_dissipative` (γ = 0 next to γ = 0.5). |
| `figures/`, `data/` | Made by the notebook when it runs: every plot (PNG), every table (CSV) and `summary.json`. |

The video presentation is submitted separately.

## Requirements

- Python 3 (we used 3.11) with `numpy`, `matplotlib` and Jupyter (Jupyter Notebook, JupyterLab, VS Code or Google Colab).
- A 64-bit `gcc` for the C code in Task 6:
  - Windows: the 64-bit MinGW-w64 build from [WinLibs](https://winlibs.com/), unzipped to `C:\mingw64`. The notebook calls `C:\mingw64\bin\gcc.exe`. A 32-bit gcc does not work with 64-bit Python (`WinError 193`).
  - Linux, Mac and Google Colab: the normal `gcc` (already installed on Colab).
- `ffmpeg` (optional), only for the MP4 copy of the movie. The GIF is made without it.

## How to run

**Windows (Jupyter or VS Code)**

1. Put `atomic_toy_model.ipynb` and `pair_forces.c` in the same folder.
2. Open the notebook and run all cells from top to bottom (Jupyter: *Kernel → Restart & Run All*; VS Code: *Run All*).

**Google Colab**

1. Open the notebook in Colab and upload `pair_forces.c` with the folder icon on the left. Colab deletes uploaded files when the session ends.
2. In the Task 6 cell, change `GCC = r"C:\mingw64\bin\gcc.exe"` to `GCC = "gcc"`.
3. Run all cells (*Runtime → Run all*).

A full run takes roughly 10–20 minutes on a laptop; the movies and the timing cells of Tasks 6–8 take the longest. The notebook creates the folders `figures/`, `data/` and `animations/` itself.

## How to check the results

- **Task 1** prints the correctness checks for all 2001 saved steps (d_ij = d_ji, d_ii = 0, no atom is its own neighbour, ‖Σ F_i‖ ≈ 10⁻¹⁶, every atom stays inside the box) and compares a head-on two-atom collision with the exact solution.
- The Python loop, NumPy, C and cell-list versions of the force are compared with each other; they agree to about 10⁻¹⁵.
- All random numbers use fixed seeds, so every physics result (energies, energy errors, relaxation times) comes out exactly the same on every computer. Run times and memory numbers (Tasks 5–8) depend on the computer.
- When the notebook runs, it saves the main movie as `animations/trajectory_N20.gif` and `.mp4`, and shows the Euler-vs-Verlet and conservative-vs-dissipative movies as GIFs inside the notebook. The `.gif` and `.mp4` files of those two movies in `animations/` come from an earlier run of the same code.

## What is where in the notebook

| Section | What it does |
|---|---|
| 0. The model | Parameters, force and energy functions, wall reflection, and the Euler / velocity Verlet simulator |
| Task 1 | Verification checks and the exact two-atom collision test |
| Task 2 | Trajectory movie and the numbers behind it (escapes, stuck atoms, jumps, energy, clustering) |
| Task 3 | K, U and E for four time steps with Euler and Verlet, where the error comes from, long runs from 8 starts, choice of Δt |
| Task 4 | Drag force −γv, energy balance, steady-state criterion and relaxation times |
| Task 5 | float32 vs float64: energy, trajectories, memory and speed |
| Task 6 | Python loop vs NumPy vs C: timing, scaling with N and the bottleneck |
| Task 7 | Memory of the vectorized method and when it becomes impractical |
| Task 8 | Innovations: cell-linked neighbour list (speed and memory) and spring walls (accuracy) |
| Task 9 | Cutoff study and the final recommended configuration |

## Main results

- Velocity Verlet with Δt = 0.01 keeps the energy error below 1 % over 50 000 steps for 8 different starting configurations; Euler gains 119 % energy in 5000 steps.
- With a drag force the atoms come to rest after t_relax ≈ 10/γ.
- float32 gives the same energy accuracy as float64 with half the memory, but no real gain for 20 atoms.
- The cell list grows like N^1.2 instead of N² and is faster than NumPy from N = 200 on; spring walls make the long-run energy error 12 times smaller.

## Use of AI

We used Claude as an AI assistance tool during the development of this project for the following purposes:

- **Debugging:** To identify errors, understand issues in the code, and help resolve implementation problems.
- **Notebook formatting:** To improve the presentation and organization of the Jupyter Notebook, including formatting Markdown cells, structuring explanations, and presenting points in a clear and readable manner.
- **Report formatting:** To assist with formatting and organizing the project report.

AI assistance was mainly used for debugging, improving readability, and formatting. The implementation, experiments, analysis, and interpretation of results were carried out by the group.
