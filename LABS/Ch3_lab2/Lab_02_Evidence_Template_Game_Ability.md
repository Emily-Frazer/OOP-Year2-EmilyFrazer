# Chapter 03 · Practical Lab 02 · Evidence
## Game ability virtual console

Student identifier: [c00322789]

Date (YYYY-MM-DD): [2/11/26]

Visual Studio version: [2026]

Platform Toolset: v145 · ISO C++17 · /W4 · Debug / x64

Repository URL, if used: [https://github.com/Emily-Frazer/OOP-Year2-EmilyFrazer/tree/main]

---

## How to complete this record

Fill this in while you work through the practical. Short answers are sufficient. You do **not** need to invent new tests, create a testing framework, or take screenshots of every step. The practical already gives you the expected console output.

For each prediction, make your prediction **before** running the code. When the program behaves differently, fix the code or explain your revised understanding. Record only genuine problems; do not manufacture a compiler error to fill an evidence box.

---

## 01 · Project setup

Project name: [ch3_lab2]

Check the files you created from scratch:

- [o ] `Main.cpp`
- [o ] `Abilities.h`
- [o ] `Abilities.cpp`
- [o ] `Runner.h`
- [ o] `Runner.cpp`

- [o ] v145 selected
- [o ] ISO C++17 selected
- [o ] `/W4` selected
- [ o] Debug / x64 selected
- [ o] The starter program built and printed `Game ability lab`

One project problem I solved, if applicable: [none]

## 02 · Non-virtual calls

The first version of `GameAbility::activate()` is **not virtual**. A `GameAbility const&` refers to a `ShieldAbility` object.

My prediction for the three calls:

- Direct ShieldAbility: [20]
- GameAbility base reference: [20]
- Direct HealAbility: [15]

Actual output:

```text
[Direct: Shield Power: 20
Base view: Generic ability
Second Type:Heal power: 15]
```

Why does the base reference use that function body? [it is accessing the base activate function because it is pointing to where shield power is built from]

## 03 · Virtual calls and override

After adding `virtual` in `GameAbility` and `override` to both concrete classes:

Expected base-reference result: [Shieldpower: 20]

Actual base-reference result: [shieldpower: 20]

Which part of this declaration must match the base to make the override valid?

```cpp
void activate() const override;
```

[the function name must be the same as the base to make the override work]

If you attempted the build-only `const` mismatch: first useful diagnostic or concise explanation: [complete / not attempted]

- [ o] The original matching declaration has been restored.

## 04 · Abstract GameAbility

What is the purpose of the following declaration?

```cpp
virtual void activate() const = 0;
```

[it makes it so the code cannot make a completed object for the ability]

Which of the following may be a complete object? Record the explanation.

- `GameAbility generic{10};` — [rejected] because [gamability is now an abstract class]
- `ShieldAbility shield{20};` — [allowed] because [shield ability is a fully usable classs]

- [ o] The temporary abstract-object build-only experiment has been removed.
- [ o] The remaining valid program builds.

## 05 · Virtual destructor and ownership

One `HealAbility{7}` is created with `new` and owned through `GameAbility*`.

Expected destructor messages after the matching `delete`:

```text
[-gameability]
```

Observed two-line destructor trace:

```text
[- heal ability, - game ability]
```

Why does the base destructor need to be virtual for this deletion? [one sentence]

Why should you **not** delete a pointer that merely refers to a local `ShieldAbility`? [those pointers are only borrowing the value and can cause undefined behaviour]

## 06 · Generic runner

Your runner should **not** name the concrete classes. It works through the GameAbility interface.

Given the three slots `&shield`, `nullptr`, `&heal`:

Predicted number of activations: [2]

Actual number: [2]

Were shield and heal's stored powers unchanged? [yes]

Boundary calls:

| Call | Predicted | Actual |
|---|---|---|
| `activateReady(nullptr, 0)` | [Empty: 0] | [Empty: 0] |
| `activateReady(nullptr, 1)` | [Missing array: -1] | [Missing array: -1] |

Why must the runner check a slot for `nullptr` before calling `power()` or `activate()`? [nullptr has no value which will cause an error when accessed in the array]

Why can a third concrete ability join the array without a new branch in `Runner.cpp`? [one sentence]

## Final output

Paste your final console transcript, or provide an agreed accessible text equivalent:

```text
[THEE virtual stuff lab
Direct: Shield Power: 20
Base view: Shield Power: 20
Second Type:Heal power: 15
Shield Power: 20
Heal power: 15
Activated: 2
Powers: 20  15
Empty: 0
Missing array:-1
owned action

Heal power: 7
- Heal ability
- Game ability
Leaving scope
- Heal ability
- Game ability
-Shield ability
- Game ability]
```

Does it match the practical's published final output? [yes]

If no, record the remaining difference: [not applicable]

## One real problem I fixed (optional)

What happened? [none]

What changed? [not applicable]

What happened after rebuilding? [not applicable]

## Optional stretch · DashAbility

- [ ] Not attempted
- [ ] Attempted: implemented `DashAbility` with `activate() const override`
- [ ] Runner works with DashAbility without edits to `Runner.cpp`

My extra output (if attempted): [complete / not attempted]

## Final checklist

- [ ] My project was created from an Empty Project.
- [ ] All five required files are present in the Visual Studio project.
- [ ] The program builds with v145, C++17, /W4, Debug / x64.
- [ ] The initial non-virtual result has been understood and recorded.
- [ ] `activate()` is virtual and then pure in the final base class.
- [ ] Both concrete `activate() const` declarations use `override` correctly.
- [ ] `GameAbility` cannot be instantiated as a complete object.
- [ ] The base destructor is virtual and has a matching definition.
- [ ] The owned dynamically allocated `HealAbility` is deleted exactly once.
- [ ] The runner skips invalid/null/inactive inputs according to the brief.
- [ ] Temporary deliberate compilation failures have been removed.
- [ ] The final console output matches the published example.

One concept I can now explain without looking at the code: [complete]
