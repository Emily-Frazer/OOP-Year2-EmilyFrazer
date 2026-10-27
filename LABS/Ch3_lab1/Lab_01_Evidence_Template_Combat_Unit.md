# Chapter 3 · Practical Lab 1 · Evidence
## Combat unit inheritance console

Name or student identifier: [c00322789 - Emily frazer]

Date (YYYY-MM-DD): [26/10/26]

Repository URL, if used: [complete / not used]

Visual Studio version: [2026]

Platform Toolset: **v145** · Language: **C++17** · Build: **Debug / x64** · Warning level: **/W4**

---

## How to use this record

Write short answers as you work through the practical. Use the **expected console output already printed in the lab**; you do not have to create separate test programs, write `assert` statements, or take a screenshot after every line. A short copied transcript or a text-based account is sufficient.

If a result differs, fix your source code and record the corrected result. Do not claim that an unrun or unsuccessful check passed.

## 01 · Project created from scratch

**Project and solution name:** [complete]

Files present:

- [complete ] `Main.cpp`
- [complete ] `CombatUnit.h`
- [complete ] `CombatUnit.cpp`
- [complete ] `Archer.h`
- [complete ] `Archer.cpp`

- [complete ] I selected v145, ISO C++17, `/W4`, and Debug/x64.
- [ complete] The first program built and printed `Combat unit inheritance lab`.

**If the first build needed a repair, what did you fix?**

[no repair required]

## 02 · CombatUnit base

What health did you give the first CombatUnit? [60]

What did `attackPower()` return? [0]

**Predict before running:** what should happen when the inner block ends?

[- combat unit should be printed]

**What actually appeared in your console?**

```text
Base unit
[+ Combat Unit
Guard health is: 60
Guard attack power is: 0
- Combat Unit]
```

**Why is `m_health` private rather than directly editable from `main()`?**

[this is to prevent health accidentally bering edited by other functions]

## 03 · Archer inheritance

**Predict before running:** write the order of the two constructor messages and the two destructor messages.

```text
[+combat unit
+archer

-archer
-combatUnit]
```

**Actual order:**

```text
[+combatUnit
+conbatUnit
+archer

-archer
-combatUnit
-CombatUnit]
```

**Starting health:** [80]

**Archer attack power:** [12]

**Why must the Archer constructor initialise `CombatUnit{t_health}` before its own body runs?**

[to receive the health member from the parent class]

**Can Archer directly access CombatUnit’s private `m_health`? Why?**

[yes because it is linked to the archer class]

## 04 · Copy or view?

Before running, predict the five attack results.

| Expression | Prediction | Observed |
|---|---|---|
| `archer.attackPower()` | [12] | [12] |
| `baseCopy.attackPower()` | [12] | [0] |
| `baseView.attackPower()` | [12] | [0] |
| `pBase->attackPower()` | [12] | [0] |
| `archer.attackPower()` again | [12] | [12] |

**Which declaration makes a new independent base object?**

[archer]

**Which declarations are only views of the original Archer?**

[baseCopy, baseView, pBase]

**Why does a base reference produce the base attack result even though it still refers to the Archer?**

[the pointers are pointing to the base attack of combatunit?]

**Why does the copied CombatUnit produce a destructor message without printing another parameterised constructor message?**

[because it was not a new object created with the constructor but a copy made by something else]

## 05 · Known-object conversion

Identify the complete object that `pUnit` points into: [archer]

**Expected base health:** [75]

**Expected recovered Archer attack:** [12]

**Observed values:** [75,12]

**What fact makes this particular `static_cast<Archer*>` valid?**

[it is looking into archer, not the combat unit itself.]

**Should either pointer be deleted in this lab? Explain briefly.**

[no as theyre just pointing to an objct that will be deconstructed after they are done, theyre only accessing the archer for a little bit]

## 06 · Access investigation

**Before changing the inheritance keyword, predict which access rule will change.**

[CombatUnit will not be able to be read, making everything have errors]

**Did you temporarily try `protected` inheritance?** [yes]

**If attempted, what did the compiler reject?**

[the compiler rejected any accessing of combatUnit due to it being protected / inaccessible]

- [complete ] I restored `class Archer : public CombatUnit`.
- [ complete] The restored project builds successfully.

## Final console check

- [complete] All four sections match the expected output published in the lab.
- [complete ] The program reports attack `12` directly, and `0` through the copied/base views.
- [complete ] A known-object cast reports base health `75` and recovered attack `9`.
- [complete ] The constructor/destructor messages appear in the expected order.
- [ complete] I have removed any temporary build-only faults.

**Remaining difference from the published output, if any:**

[none]

## One problem I fixed (only if applicable)

**What happened?** [no issue encountered]

**What did I change?** [not applicable]

**What happened after rebuilding?** [not applicable]

Please do not invent a fault if none occurred.

## Optional stretch · VeteranArcher

**Attempted?** [ no]

**Predicted attack for arrow power 12 and bonus 3:** [complete / not attempted]

**Observed:** [complete / not attempted]

**Why did you write `Archer::attackPower()` inside the third-level function?**

[one sentence / not attempted]

## Final reflection

In one or two sentences, explain one difference between **inheritance**, **object slicing**, and **viewing an existing derived object through its base type**.

[complete]
