# Lab 05 — Report

**Name: Jack Kane** <Full Name>

**StudentID: C00300324** <StudentID>


## Coverage summary

State coverage:  3 / 3
Transition coverage:  5 / 5

## Report (250-500 words max)

    1. Explain the difference between state coverage and transition coverage in your own words. Could a test suite achieve 100 % state coverage without achieving 100 % transition coverage? 

    State coverage is achieved when tests visit every state of the finite state machine, this is different to transition coverage as full transition coverage is only achieved when every transition has been tested, for example Off -> On -> Paused achieves full state coverage as every state is visited but it does not achieve full transition coverage as the transitions Paused -> Off, Paused -> On and On -> Off are never tested.

    In this lab I have achieved full state coverage and full transition coverage since there is a test for all transitions:
    EXPECT_EQ(m.transition(State::OFF, Event::powerOn), State::ON);         Off -> On
    EXPECT_EQ(m.transition(State::ON, Event::powerOff), State::OFF);        On -> Off
    EXPECT_EQ(m.transition(State::ON, Event::pause), State::PAUSED);        On -> Paused 
    EXPECT_EQ(m.transition(State::PAUSED, Event::resume), State::ON);       Paused -> On
    EXPECT_EQ(m.transition(State::PAUSED, Event::powerOff), State::OFF);    Paused -> Off   

    Having full transition coverage does also ensure full state coverage as there is always a transition to each state (unless the state has no way of raeaching it) so by covering all transitions you will always visit each state at least once.

    2. Give one example of a bug in `transition()` that would slip past state coverage but be caught by transition coverage.

    Using state coverage may lead to a bug being undetected on an untested transition, for example the tests: Off -> On -> Paused achieve full state coverage but do not cover the transition Paused -> Off, therefore this transition may function incorrectly and lead the state to remain in paused instead of off, this would still pass all tests since this transition is never tested. 
    Using full transition coverage would catch this bug and ensure transitions function as they are intended

## Screenshots
To be provided as:
* `screenshots/vscode.png`
* `screenshots/terminal.png`
