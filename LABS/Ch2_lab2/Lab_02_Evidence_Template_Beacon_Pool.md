# Chapter 2 · Practical Lab 2 · Evidence
## Beacon pool console

Name or student identifier: [emily frazer]

Date (YYYY-MM-DD): [6/10/26]

Repository URL, if used: [https://github.com/Emily-Frazer/OOP-Year2-EmilyFrazer.git]

Visual Studio version: [2026]

Platform Toolset: v145 · Language: C++17 · Configuration: Debug · Platform: x64

---

## How to use this evidence record

Complete this file **while you work through the lab**.

Keep answers short. You do not need to invent a separate test suite, use `assert`, or create extra screenshots. The practical already gives you the calls and expected console results needed for the core checks.

When the lab asks for a prediction, write it down before you run the program. If your prediction is wrong, correct the code or your explanation and continue.

---

## 01 · Project setup

**Project name:**

[Ch2_Lab2]

**Files created:**

- [o ] `Main.cpp`
- [o ] `Beacon.h`
- [ o] `Beacon.cpp`
- [o ] `Receiver.h`
- [ o] `Receiver.cpp`
- [o ] `BeaconPool.h`
- [o] `BeaconPool.cpp`

**Build settings checked:**

- [ o] Platform Toolset `v145`
- [o ] C++ Language Standard `ISO C++17`
- [ o] Warning Level `/W4`
- [o ] `Debug`
- [o ] `x64`

**First successful console output:**

```text
Beacon pool lab
```

**Did the starter project build and run successfully?**

[yes]

If no, briefly record the problem you fixed:

[complete / not applicable]

---

## 02 · Receiver and Beacon

The receiver uses a `Beacon const&` parameter but does not contain a `Beacon` by value.

**Why is this enough in `Receiver.h`?**

```cpp
class Beacon;
```

[it is looking for the memory where the object created by the beacon class, this means it does not need to find all the different pieces of the beacon object, just where it is stored in memory for reference]

**Which files did you include in `Receiver.cpp` before calling `t_beacon.x()`?**

[receiver.h and beacon.h]

**Prediction before running:**

A receiver at 35 and a beacon at 10 should have range: [25]

**Actual output:**

```text
[Connection Check
range to beacon: 25]
```

**Status:**

[complete]

---

## 03 · BeaconPool composition

`BeaconPool` contains:

```cpp
Beacon m_beacons[CAPACITY];
```

**Why does `BeaconPool.h` need the complete `Beacon` definition rather than only a forward declaration?**

[beacon pool is telling how many beacons will be created, in this instance it makes multiple beacon objects using the class, it is not referencing a singular beacon rather creationg multiple beacons a once once the beacon pool is called]

**What does this declaration permit?**

```cpp
friend class BeaconPool;
```

[friend classes can access the private and the public members of the class its included in, beaconPool needs to know the contents of beacon in this case]

**Does friendship itself make `BeaconPool` own a `Beacon`?**

[no, it doesn't inherently own it but can access the private members to know information about beacon]

**Status:**

[/ complete]

---

## 04 · Request logic

For a valid request, the pool should activate the first free slot.

### Published sequence

**My prediction before running:**

- request 30 -> slot [0]
- request 60 -> slot [1]
- request 90 -> slot [2]
- request 50 when full -> slot [-1]

**Actual values:**

- request 30 -> slot [0]
- request 60 -> slot [1]
- request 90 -> slot [2]
- request 50 when full -> slot [-1]

**What range of signal strengths does your `request()` accept?**

[0-100 inclusive]

**When should `s_successfulRequests` increase?**

[when there is a successful request to activate a beacon, and one gets marked as active]

**Status:**

[complete]

---

## 05 · Release and reuse

The core sequence releases the second checkout and then requests a new strength of 75.

**Prediction before running:**

- released slot: [1]
- released result: [true]
- strength after release: [0]
- reused slot: [1]

**Actual result:**

```text
[Connection Check
Range to beacon: 25

Pool A
Start active: 0
Request 30 -> slot 0
Request 60 -> slot 1
Request 90 -> slot 2
Request 50 -> slot -1
Active beacons: 3
Successful requests: 3

Release and reuse
Released slot 1: true
Strength after release: 0
Request 75 -> slot 1
Active beacons: 3
Successful requests: 4]
```

**Why does `reset()` clear the strength as well as the active flag?**

[i resets the beacons stats to their base, making it able to be activated again with a new strength]

**Why must `release()` validate the index before accessing the array?**

[if it tries to access outside the array the program will result in an error, preventing this is best]

**Status:**

[complete]

---

## 06 · Per-object state and shared state

Before running the second-pool experiment, complete the predictions.

**Pool B starts with active count:**

[3]

**Its first successful request should use slot:**

[0]

**Should using Pool B change Pool A's active count?**

[no]

**Expected shared successful-request tally after the Pool B request:**

[3]

**Actual output:**

```text
[Pool B
Pool B active: 0
Pool B request 25 -> slot 0
Pool A active: 3
Pool B active: 1
Successful requests: 5]
```

Complete the statements:

`m_beacons` is _in a per object state_ state because each `BeaconPool` object has its own array.

`s_successfulRequests` is _in a class wide_ state because every `BeaconPool` object refers to the same tally.

---

## 07 · Boundary check

Use a fresh `BeaconPool` and temporarily request strength `0`.

**Prediction:**

- returned slot: [0]
- active count afterwards: [1]
- should the shared tally increase? [yes]

**Actual result:**

[Pool c request 0 -> slot0
successful reqs: 6
pool c active count:1]

Restore the final `Main.cpp` afterwards.

---

## Final console check

Your final output should match the practical:

```text
Beacon pool lab

Connection check
Range to beacon: 25

Pool A
Start active: 0
Request 30 -> slot 0
Request 60 -> slot 1
Request 90 -> slot 2
Request 50 -> slot -1
Active beacons: 3
Successful requests: 3

Release and reuse
Released slot 1: true
Strength after release: 0
Request 75 -> slot 1
Active beacons: 3
Successful requests: 4

Pool B
Pool B active: 0
Pool B request 25 -> slot 0
Pool A active: 3
Pool B active: 1
Successful requests: 5
```

**Paste your final console output below:**

```text
[
Connection Check
Range to beacon: 25

Pool A
Start active: 0
Request 30 -> slot 0
Request 60 -> slot 1
Request 90 -> slot 2
Request 50 -> slot -1
Active beacons: 3
Successful requests: 3

Release and reuse
Released slot 1: true
Strength after release: 0
Request 75 -> slot 1
Active beacons: 3
Successful requests: 4

Pool B
Pool B active: 0
Pool B request 25 -> slot 0
Pool A active: 3
Pool B active: 1
Successful requests: 5]
```

**Does it match?**

[yes]

If no, record the remaining difference:

[complete]

---

## Short understanding check

Answer each in one or two sentences.

**1. Why can `Receiver.h` forward-declare `Beacon`?**

[it includes a memory reference to beacon, allowing it to forward declare]

**2. Why can `BeaconPool.h` not use only the same forward declaration for its array?**

[the forward declaration is for the class beacon, not the object it creates for the array m_beacons, beacon pool can access the members in the beacon class instead]

**3. What does `friend class BeaconPool;` grant, and what does it not grant?**

[it allows the class defined as friend to access the private members and functions of the class it is defined in, this can allow for 2 classses to acces a private date member instead of having to make an entire class public for one other class]

**4. Why are `poolA` and `poolB` independent even though they use the same class?**

[they are 2 different arrays of beacon objects, they were not made as the same array]

**5. Why can `successfulRequests()` be called using `BeaconPool::successfulRequests()`?**

[in my understanding this is how you call a function when it belongs to a class but isnt attached to an object?]

---

## One problem I fixed

Complete this only if you encountered a genuine problem.

**What went wrong?**

[the full capacity variable was not returning -1, it kept returning 0]

**What did I change?**

[i realised i was being silly and thought CAPACITY = 3 meant the index went from 0 to 3, so i was doing a check for index == 3 when index couldnt even go that high, i changed the check to make it check for == CAPACITY instead of == 3]

**What happened after rebuilding?**

[it worked as expected after i realised the issue and fixed]

Do not invent an error if you did not encounter one.

---

## Optional stretch · `full()`

Complete only if attempted.

**Did you add `bool full() const;`?**

[not attempted]

**Expected results:**

- new pool: `false`
- after three successful requests: `true`
- after one release: `false`

**Actual results:**

[not attempted]

---

## Final checklist

- [o ] I created the solution and project from scratch.
- [ o] All seven source/header files are included in the project.
- [ o] The project builds with v145, C++17, `/W4`, Debug and x64.
- [o ] `Receiver.h` uses a forward declaration of `Beacon`.
- [o ] `Receiver.cpp` includes the complete `Beacon` definition before calling Beacon members.
- [o ] `BeaconPool.h` includes `Beacon.h` because it stores Beacon objects by value.
- [o ] `request()` validates strength, uses the first free slot and returns `-1` when it cannot serve a request.
- [o ] `release()` validates the index and resets released state.
- [o ] `activeCount()` reports the state of one pool only.
- [o ] `successfulRequests()` reports the shared class-wide tally.
- [o ] My final console output matches the practical.
- [o ] Temporary boundary-check edits have been restored.
- [ o] The final project builds successfully.

---

## Final note

One class-relationship concept I can now explain without copying the workbook:

[friendship between classes can be useful for a class that needs to access certain private functions or member data sets, this is easier than having the whole class be public!]
