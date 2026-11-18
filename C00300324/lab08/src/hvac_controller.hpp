// Lab 08 - Test design from logic: HVAC smoke purge interlock

#pragma once

// Inputs, all digital:
//   A  smokeDetected   optical smoke detector in the exhaust duct   (true = dense smoke)
//   B  manualOverride  emergency switch held by the safety officer  (true = engaged)
//   C  damperOpen      fire damper limit switch                     (true = fully open and locked)
//   D  fanHealthy      purge fan interlock                          (true = running, airflow proven)
//
// Output:
//   true  -> start the smoke purge (F = 1)
//   false -> purge stays off       (F = 0)

class HVACController {
public:
    bool evaluateSmokePurge(bool smokeDetected, bool manualOverride,
                            bool damperOpen, bool fanHealthy) const;
};
