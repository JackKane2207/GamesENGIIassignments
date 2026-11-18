// Lab 08 - Test design from logic: HVAC smoke purge interlock

// Problem statement
//   The air handling unit must start the smoke purge (F = 1) when any of these holds:
//     R1  smoke detected AND manual override engaged                    A and B
//     R2  smoke detected AND damper open AND purge fan healthy          A and C and D
//     R3  manual override engaged AND damper open                       B and C
//     R4  all four inputs true (kept by the engineers for redundancy)   A and B and C and D
//   F = (A and B) or (A and C and D) or (B and C) or (A and B and C and D)
//
// Tasks (full detail in Lab08_Overview)
//   Part 1  Truth table, determination conditions p_A..p_D, GACC/CACC/RACC pairs.
//   Part 2  K-maps of F and not-F, minimal DNF. Then replace the body of evaluateSmokePurge below with
//           your minimal DNF.
//   Part 3  test/lab08_tests.cpp: a Determination suite and a DNF suite.
//   Part 4  A script in scripts/ that builds the project, checks all 16 input
//           conditions through hvac_cli, runs the test suites and writes the logs.
//   Part 5  Lab08_Report.md explaining how you reached each answer.
//
// Submission
//   studentLabs/<REG>/lab08/  with src/, test/, scripts/, CMakeLists.txt,
//   results/conditions.csv, run_log.txt, screenshots/vscode.png,
//   screenshots/terminal.png and Lab08_Report.md (or .docx / .pdf).
//   Deadline: Tuesday 17 November 2026, 09:00.

#include "hvac_controller.hpp"

bool HVACController::evaluateSmokePurge(bool smokeDetected, bool manualOverride,
                                        bool damperOpen, bool fanHealthy) const
{
    // TODO (Part 2): return your minimised expression in terms of the four inputs.
    (void)smokeDetected;
    (void)manualOverride;
    (void)damperOpen;
    (void)fanHealthy;
    return false;
}
