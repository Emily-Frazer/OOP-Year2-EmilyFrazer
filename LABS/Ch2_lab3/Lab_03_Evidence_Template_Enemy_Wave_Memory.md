# Chapter 2 · Practical Lab 3 · Evidence
## Enemy wave memory console

Name or student identifier: [emily frazer]

Date (YYYY-MM-DD): [17/10/26]

Repository URL, if used: [(https://github.com/Emily-Frazer/OOP-Year2-EmilyFrazer.git)]

Visual Studio version: [complete]

Platform Toolset: v145 · Language: C++17 · Configuration: Debug · Platform: x64

---

## How to use this evidence record

Complete this file **while you work through the practical**.

Keep answers short. The practical already supplies the required behaviour and expected output, so you do not need to invent a second test suite or run unsafe memory experiments.

When you make a prediction, write it down before running the code. If the result differs, correct the code or your explanation and continue.

Never deliberately run a double delete, use-after-delete, out-of-bounds access or mismatched `delete`/`delete[]`.

---

## 01 · Project setup

**Project name:**

[ch2lab03]

**Files created:**

- [o ] `Main.cpp`
- [o ] `Enemy.h`
- [o ] `Enemy.cpp`
- [ o] `EnemyWave.h`
- [o ] `EnemyWave.cpp`

**Build settings checked:**

- [o ] Platform Toolset `v145`
- [o ] C++ Language Standard `ISO C++17`
- [o ] Warning Level `/W4`
- [o ] `Debug`
- [o ] `x64`

**First successful output:**

```text
Enemy wave memory lab
```

**Did the empty project build and run successfully?**

[yes]

If no, briefly record the problem you fixed:

[ not applicable]

---

## 02 · One dynamic Enemy

For the single-enemy stage, identify the object and the pointer separately.

**Allocation expression used:**

```cpp
[Enemy* pEnemy{ new Enemy{} };]
```

**Starting health predicted:**

[70]

**Health after 30 damage predicted:**

[40]

**Actual output:**

```text
[ SINGLE ENEMY
The enemy health is:70
The new enemy health: 40]
```

**Who owns the dynamically allocated Enemy?**

[the enemy class]

**Which statement releases that allocation?**

```cpp
[	delete pEnemy;
	pEnemy = nullptr;]
```

**Why does setting the pointer to `nullptr` not replace the required release?**

[it makes the pointer point to nothing or "null"]

---

## 03 · Raw dynamic Enemy array

The raw-array experiment uses three Enemy objects in one array allocation.

**Array count:**

[3]

**Prediction before running:**

- Enemy 0 health: [75]
- Enemy 1 health: [0]
- Enemy 2 health: [40]
- Alive enemies: [2]
- Total health: [115]

**Actual output:**

```text
[ENEMY IN MAIN ARRAY
Enemy in slot 0 Remaining health: 75
Enemy in slot 1 Remaining health: 0
Enemy in slot 2 Remaining Health: 40

Alive enemies 2
Total hp left = 115]
```

**Which cleanup form did you use?**

[deleting pEnemies contents and releasing the pointer]

**Why would deleting each element individually be incorrect for this array?**

[it risks an element being missed by accident]

### Objects versus pointer slots

Complete the statements.

`new Enemy[3]` creates ____an array of 3 new enemy objects in memory ________________.

`new Enemy*[3]{}` creates _____an array of 3 new enemy objects in memory_______________ and creates __a pointer to the____ Enemy objects.

---

## 04 · EnemyWave ownership

`EnemyWave` stores an `Enemy*` member and owns the array that pointer identifies.

**Accepted wave-count range:**

[0-5 inclusive]

**What happens for `EnemyWave{8}`?**

[the m_count becomes 0 and the array is a nullptr]

**Why is this forward declaration sufficient in `EnemyWave.h`?**

```cpp
class Enemy;
```

[so the arrays created have access to enemies members and member functions]

**Why must `EnemyWave.cpp` include `Enemy.h`?**

[so the arrays created have access to enemies members and member functions]

**Which allocation is owned by the EnemyWave destructor?**

[the allocation of the initialised array]

**Which cleanup form must the destructor use?**

[delete]

**Why are the copy constructor and copy assignment deleted?**

[]

---

## 05 · EnemyWave behaviour

For:

```cpp
EnemyWave wave{3};

wave.damageEnemy(0, 25);
wave.damageEnemy(1, 100);
wave.damageEnemy(2, 60);
```

**Prediction before running:**

- `count()`: [3]
- `healthAt(0)`: [75]
- `healthAt(1)`: [0]
- `healthAt(2)`: [40]
- `aliveCount()`: [2]
- `totalHealth()`: [115]

**Actual output:**

```text
[ENEMY FROM WAVE.H
 Enemy in slot 0 Remaining health: 75
Enemy in slot 1 Remaining health: 0
 Enemy in slot 2 Remaining Health: 40

Alive enemies 2
Total hp left = 115]
```

### Invalid index check

For:

```cpp
wave.damageEnemy(9, 10);
```

**Predicted return value:**

[-1]

**Did the stored health values remain unchanged?**

[yes]

**Why must the index be checked before `m_enemies[t_index]` is used?**

[to prevent the program checking outside the array]

---

## 06 · Invalid wave

**Prediction for `EnemyWave invalid{8}`:**

- count: [0]
- total health: [0]
- dynamic Enemy array allocated? [ no]

**Actual output:**

```text
[INVALID ENEMY FROM WAVE.H

Alive enemies 0
Total hp left = 0]
```

---

## Allocation ledger

Record the three ownership cases used in the practical.

| Allocation | What exists | Owner | Matching release |
|---|---|---|---|
| `new Enemy{}` | [a new enemy object] | [enemy class] | [delete, then make nullptr] |
| `new Enemy[enemyCount]` | [an enemy object array with a max of enemy count] | [enemy class] | [delete] |
| `new Enemy[m_count]` inside `EnemyWave` | [an enemy object array with a max of m_count] | [enemy wave class] | [delete] |

---

## Final console check

Paste your final program output.

```text
[enemy wave memory lab


 SINGLE ENEMY
The enemy health is:70
The new enemy health: 40

ENEMY IN MAIN ARRAY
Enemy in slot 0 Remaining health: 75
Enemy in slot 1 Remaining health: 0
Enemy in slot 2 Remaining Health: 40

Alive enemies 2
Total hp left = 115

ENEMY FROM WAVE.H
 Enemy in slot 0 Remaining health: 75
Enemy in slot 1 Remaining health: 0
 nemy in slot 2 Remaining Health: 40

Alive enemies 2
Total hp left = 115
INVALID ENEMY FROM WAVE.H

Alive enemies 0
Total hp left = 0]
```

**Does it match the published output in the practical?**

[yes]

If no, record the remaining difference:

[not applicable]

---

## Short understanding check

Answer each in one or two sentences.

**1. What is the difference between a pointer variable and the dynamically allocated object it identifies?**

[im having a hard time understanding this question, a pointer variable would be part of the object and the object is a mix of many variables no?]

**2. Why does `new Enemy[3]` use `delete[]` rather than `delete`?**

[the Enemy[] is an object array, you need to delete the whole array]

**3. Why does destroying an `EnemyWave` need to release its array?**

[to avoid the array being accessed while empty]

**4. Why does the raw pointer type alone not prove who owns the target?**

[there might be a subclass that owns the array]

**5. Why is a correct printed value not enough to prove that the lifetime logic is correct?**

[because if any input changes such as damage there  might be an unknown error]

---

## One problem I fixed

Complete this only if you encountered a genuine problem.

**What went wrong?**

[ no problem recorded]

**What did I change?**

[ / not applicable]

**What happened after rebuilding?**

[ / not applicable]

Do not invent an error if you did not encounter one.

---

## Optional stretch · `empty()`

Complete only if attempted.

**Did you add `bool empty() const;`?**

[yes / no / not attempted]

**Expected results:**

- `EnemyWave{0}` -> `true`
- `EnemyWave{8}` -> `true`
- `EnemyWave{3}` -> `false`

**Actual results:**

[complete / not attempted]

---

## Final checklist

- [ ] I created the Visual Studio solution and project from scratch.
- [ ] All five source/header files are included in the project.
- [ ] The project builds using v145, C++17, `/W4`, Debug and x64.
- [ ] The single dynamic Enemy is released with `delete`.
- [ ] The raw Enemy array is released with `delete[]`.
- [ ] `EnemyWave` rejects counts outside 0–5 without allocating.
- [ ] `EnemyWave` owns one dynamic Enemy array when its count is positive.
- [ ] `EnemyWave::~EnemyWave()` releases that array using `delete[]`.
- [ ] Every array index is validated before use.
- [ ] Copy construction and copy assignment remain disabled.
- [ ] Temporary boundary-check code has been removed.
- [ ] The final console output matches the practical.
- [ ] The final project builds successfully.

---

## Final note

One ownership or lifetime rule I can now explain without copying the workbook:

[complete]
