*** UID:0001WG | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# VirusChecker Process Tree Layout

## Status

- Entity kind: object and helper tree layout for [UID:0000FW][VirusChecker](by-class/VirusChecker.md).
- Confidence: strong for observed offsets and owner, medium for final source-facing type names.
- Likely owner header: `security/VirusChecker.h`.
- Evidence basis: IDA MCP decompilation of `0x005c0460`, `0x005c04e0`, `0x005c0940-0x005c0fe1`, and vtable/data xref checks on 2026-05-26 and 2026-05-31.

## VirusChecker Object

Observed object footprint through offset `+0x08`:

| Offset | Field hypothesis | Evidence |
| --- | --- | --- |
| `0x00` | vptr | Constructor, destructor, and scalar deleting destructor write object vptr `0x006310e0`. |
| `0x04` | process/module path tree header node pointer | Constructor stores the result of `0x005796d0`; destructor reads this pointer, destroys the child tree, resets header links, and frees the header. |
| `0x08` | path tree node count | Constructor clears it; insertion helper increments the count through the embedded tree object; destructor clears it after resetting the tree. |

Active generated output names the `+0x08` field `m_state`, but IDA evidence fits `std::set`/tree node count behavior. Keep the final name open until the container wrapper is reconstructed.

## Tree Node

Observed node layout through the string payload:

| Offset | Field hypothesis | Evidence |
| --- | --- | --- |
| `0x00` | left child | Insertion, traversal, and recursive cleanup follow this as the left branch. |
| `0x04` | parent | Destructor and insertion use this as the parent/header link. |
| `0x08` | right child | Traversal and recursive cleanup follow this as the right branch. |
| `0x0c` | red/black color byte | Insert/rebalance helpers read and write this byte during rotations. |
| `0x0d` | nil/header flag byte | Traversal loops stop when this byte is nonzero. |
| `0x10` | path string payload | Allocation helper copies the path into `node + 0x10`; cleanup destroys the string at this offset. |

The helper family is consistent with an MSVC-style ordered set/tree storing scanned module path strings. It should remain source-local to `VirusChecker`, not promoted to a general container source file unless wider reuse is proven.

## IDA Evidence

- 2026-05-31 IDA MCP `lookup_funcs` rechecked the involved function boundaries: constructor `0x005c0460` size `0x80`, destructor `0x005c04e0` size `0xbd`, node insert/allocation helpers from `0x005c0940` through `0x005c0fa0`, and next non-owner function `0x005c0ff0` as `WaitableTimer`.
- 2026-05-31 IDA MCP decompilation of `0x005c0460` stores the singleton at `dword_69BF94`, writes the `VirusChecker` vtable, zeroes `this[1]` and `this[2]`, and stores `sub_5796D0()` into `this[1]`, matching object offsets `+0x04` header pointer and `+0x08` count.
- 2026-05-31 IDA MCP decompilation of `0x005c04e0` reads the header pointer from `this+0x04`, destroys the child tree from `header+0x04`, resets header links at `+0x00/+0x04/+0x08`, clears `this+0x08`, frees the header, and clears `dword_69BF94`.
- 2026-05-31 IDA MCP decompilation of `0x005c0ac0`, `0x005c0b40`, `0x005c0ca0`, and `0x005c0fa0` confirms node links at `+0x00/+0x04/+0x08`, color byte `+0x0c`, header/nil byte `+0x0d`, and copied string payload at `+0x10`.
- 2026-05-31 IDA MCP xrefs confirm the callback chain: `0x005c07b0` references process callback `0x005c0aa0`, and `0x005c0aa0` references module callback `0x005c09f0`.

## Remaining Caveats

- Final source-facing names for the embedded tree wrapper and node type remain open. The behavior matches an ordered path set, but the exact original typedef/class name is not known.
- Live activation remains unresolved: IDA currently has no direct caller for the constructor/load-helper path, so this layout is documented as reconstructable source-owned code but not yet proven startup-critical.
- No `RECONSTRUCTION_CPP CODE` is emitted yet. The final C++ shape should wait until the `VirusChecker` source file, external DLL function-pointer names, and tree wrapper naming are near-final.

## Cross-References

- [UID:0000FW][VirusChecker](by-class/VirusChecker.md)
- [UID:0000P5][VirusChecker](by-file/VirusChecker.md)
- [UID:0001NU][0x005c0460-0x005c0fe1.VirusChecker](by-memory/0x005c0460-0x005c0fe1.VirusChecker.md)
- [UID:0001NV][0x005c05a0-0x005c0937.VirusCheckerV3LoadAndScan](by-memory/0x005c05a0-0x005c0937.VirusCheckerV3LoadAndScan.md)
- [UID:0001NW][0x005c0940-0x005c0fe1.VirusCheckerProcessTreeHelpers](by-memory/0x005c0940-0x005c0fe1.VirusCheckerProcessTreeHelpers.md)
- [UID:0001YU][SecuritySingletonVtables](by-type/by-vtable/SecuritySingletonVtables.md)

## Changes

- 2026-05-31 completion/confidence and reconstructable update:
  - What existed before: `COMPLETION:0`, `CONFIDENCE:0`, and blank `RECONSTRUCTABLE`.
  - Changed to: `COMPLETION:78`, `CONFIDENCE:88`, and `RECONSTRUCTABLE:TRUE`.
  - Summary/evidence: IDA MCP rechecked constructor/destructor/tree helper boundaries, decompiled object and node field access, verified callback xrefs, and confirmed the next function boundary at `0x005c0ff0`. Scores remain below 95 because final source type names and live activation are still unresolved.
