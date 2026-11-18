# Atomic Toy Model – Computational Thinking Project

Fundamentals of Scientific Computing (Prof. Anuj Goyal, Prof. Saswata Bhattacharyya)

## What is in this folder

| File / folder | What it is |
|---|---|
| `atomic_toy_model.ipynb` | all the code for Tasks 1–9, already run (outputs are saved inside) |
| `pair_forces.c` | C version of the force calculation (Task 6), compiled by the notebook |
| `report/report.pdf` | the report to submit |
| `report/report.tex` | LaTeX source of the report (open in Overleaf to edit names etc.) |
| `figures/` | every plot used in the report (made by the notebook) |
| `data/` | every table as CSV, the test positions used for timing, and `summary.json` |
| `animations/` | trajectory movies as GIF and MP4 |

## How to run

1. Python 3 with `numpy` and `matplotlib` (Anaconda is fine).
2. `gcc` for the C part (Task 6). Linux/Mac usually have it; on Windows install MinGW-w64, or run the notebook in WSL or Google Colab. If gcc is missing, the C cells fail but the rest still works.
3. `ffmpeg` only for the `.mp4` files; the `.gif` files are made without it.
4. Open the notebook and run all cells from top to bottom. A full run took about 8 minutes on our machine (the three animations are the slowest part).

All random numbers use fixed seeds, so the physics results come out exactly the same. Timings depend on the computer.

## Before submitting

* Fill in group number, names, roll numbers and the contribution table (first page and Appendix B of `report/report.tex`, first cell of the notebook), then recompile the PDF (on Overleaf: upload `report/` and `figures/` keeping the folder structure).
* If you re-run the notebook on your own laptop, the timing and memory numbers (Tasks 5–8) will change; update them in the report, and set `RAM_GB` in Task 7 to your laptop's RAM.

## Model in one line

20 soft atoms (diameter r0 = 1) in a 10 x 10 box with reflecting walls; overlapping atoms are pushed apart by springs U = ½ k (r − r0)² with k = 10 and cutoff rc = r0; velocity Verlet with dt = 0.01.
