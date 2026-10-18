# LeetCode C++ Workspace

For cross-platform development, use CMake as the common build entry point.
Open this folder directly in Visual Studio or CLion.

```text
cmake -S . -B build
cmake --build build --config Debug
```

The executable is generated under `build/bin/`. On Visual Studio, open
`LeetCode.sln`, select `Debug | x64`, and press `Ctrl+F5`.

## Daily workflow

1. Copy `common/template.cpp` to a topic folder, such as
   `src/problems/array/0001_two_sum.cpp`.
2. Implement only the `Solution` class in that problem file. Keep it free of
   `common/` includes so it can be pasted into LeetCode directly.
3. In `main.cpp`, change the problem `#include` and add local test data.
4. Run or debug with CMake, Visual Studio, or another CMake-aware IDE.
5. Copy the problem file's includes and `Solution` class into LeetCode.

## Common library

- `common/structures.h`: local `lc::ListNode`, `lc::TreeNode`, and `lc::Node`.
- `common/utils.h`: list/tree construction, cleanup, and console printing.
- `common/stdc++.h`: C++17 standard-library umbrella header for this MSVC project.
- `common/all.h`: local debugging entry point; includes `stdc++.h` and `utils.h`.
- `common/template.cpp`: a submission-safe starting point.

The `lc::` namespace prevents the local helpers from colliding with the node
types that LeetCode supplies. Do not paste `common/structures.h` or
`common/utils.h`, `common/stdc++.h`, or `common/all.h` into the LeetCode editor.

## Suggested folders

Create topic folders below `src/problems/` as you need them:

```text
src/
  problems/
    array/  string/  linked_list/  stack_queue/
    binary_tree/  graph/  dynamic_programming/
    backtracking/  binary_search/  greedy/
  interview/
    hot100/  top150/  company/  mock/
notes/
```

## Build system

`CMakeLists.txt` is the cross-platform build definition. It compiles only
`main.cpp`; the selected problem is included by `main.cpp`. Keep only one
problem selected at a time so multiple `Solution` classes are not compiled
together.

No IDE-specific project files are required. Visual Studio and CLion both load
the project from `CMakeLists.txt`.
