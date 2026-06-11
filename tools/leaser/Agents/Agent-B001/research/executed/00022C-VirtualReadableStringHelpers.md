# B001-021 Final Report - 00022C VirtualReadableStringHelpers

## FINAL REPORT / Current Recommendation

- Target: [UID:00022C] `by-memory/0x004b12a0-0x004b13ce.VirtualReadableStringHelpers.md`.
- Final recommendation: assign to direct class parent [UID:00004V] `File`; route through [UID:0000JB] `File.cpp` source root.
- Final state: `COMPLETION:88`, `CONFIDENCE:90`, `RECONSTRUCTABLE:TRUE`, `AUTOGEN_PARENT_UID:00004V`, C++ block blank.
- Classification: reconstructable File-stream helper pair.
- Split decision: no split children are needed. The two functions are exact sibling helpers over the same `File` virtual stream contract; splitting would not change ownership or improve by-structure routing.
- Report state: final. Temporary lease override was followed; no leases were created.

Concrete supervisor/A-agent action:

- Accept the `00022C` repair as a File-class helper assignment.
- No additional child pages are needed for this range.
- Remaining caveats are non-blocking source-reconstruction naming issues, not ownership blockers.

## Changed Files

Manual B001-021 documentation changes:

- `by-memory/0x004b12a0-0x004b13ce.VirtualReadableStringHelpers.md`
  - Raised `85/88 -> 88/90`.
  - Set `AUTOGEN_PARENT_UID:00004V`.
  - Rewrote ownership from unresolved StringUtil/StringBase candidate to File stream helper pair.
- `by-class/File.md`
  - Raised `85/88 -> 86/89`.
  - Added `00022C` as a File-class helper pair and documented the File-stream slot evidence.
- `by-file/File.md`
  - Raised `85/87 -> 86/88`.
  - Added `00022C` to the File source-root contents and documented the B001-021 ownership sync.
- `by-file/StringUtil.md`
  - Removed `00022C` from likely contents and changed prior candidate-owner wording to rejected direct-owner wording.
- `by-file/StringBase.md`
  - Changed prior candidate-owner wording to note that `StringBase` is a callee/dependency, not the direct owner.
- `by-memory/-coverage-report.md`
  - Synced the `00022C` row to `88%`, parent File, and current IDA-backed wording.
- `by-file/-coverage-report.md`
  - Synced the `File` row to `86%` and included the `00022C` assignment.
- `by-class/-coverage-report.md`
  - Synced the `File` row to `86%` and included the `00022C` assignment.
- `tools/leaser/Agents/Agent-B001/research/00022C-VirtualReadableStringHelpers.md`
  - Replaced earlier progress notes with this final report.

Validator-managed side effects:

- `tools/validator.ini`: autogen metadata and reference index were rebuilt/updated by validator.
- `auto-generated/-ag-memory-coverage.md`: regenerated after the `00022C` parent update.
- `project-level/-auto-completion-stats.md`: validator updated projected path completion state.

## Validation Results

Targeted validators were run with `python source-3/project-documentation/tools/validator.py --mode file --file <path> --apply`.

| File | Result |
| --- | --- |
| `by-memory/0x004b12a0-0x004b13ce.VirtualReadableStringHelpers.md` | `ok: 1`; completion `88`, confidence `90`, parent updated from blank to `00004V`; generated memory coverage updated. |
| `by-class/File.md` | `ok: 1`; completion `86`, confidence `89`. |
| `by-file/File.md` | `ok: 1`; completion `86`, confidence `88`. |
| `by-file/StringUtil.md` | `ok: 1`. |
| `by-file/StringBase.md` | `ok: 1`. |
| `by-memory/-coverage-report.md` | `ok: 1`. |
| `by-file/-coverage-report.md` | `ok: 1`. |
| `by-class/-coverage-report.md` | `ok: 1`. |

All targeted scans reported `last used UID: 00032N`.

## Supporting Research

### IDA Evidence Summary

Live IDA MCP evidence against `NexusTK.exe` MD5 `4247e04e20b65d6414c7238aa8ff5515` confirmed:

- `lookup_funcs`:
  - `0x004b12a0` is `sub_4B12A0`, size `0x94`, range `0x004b12a0-0x004b1334`.
  - `0x004b1340` is `sub_4B1340`, size `0x8e`, range `0x004b1340-0x004b13ce`.
  - `0x004b129b`, `0x004b1334`, and `0x004b13ce` are not function starts; `0x004b13d0` begins the next function.
- `disasm` confirms alignment padding before, between, and after the pair: `0x004b129b-0x004b12a0`, `0x004b1334-0x004b1340`, and `0x004b13ce-0x004b13d0`.
- `callers` and `xrefs_to` report no direct callers or function-start/address-taken refs for either helper.
- `find_bytes` found no raw little-endian address references to `0x004b12a0` or `0x004b1340`.
- `decompile 0x004b12a0` shows virtual calls at `this->vtable + 0x14`, `+0x1c`, and `+0x20`, plus string-buffer callees.
- `decompile 0x004b1340` shows a virtual call at `this->vtable + 0x24`, followed by string conversion/assignment/release helpers.
- `py_eval` over the File-family vtables shows:
  - abstract `File` vtable `0x006188e4`: slots `+0x14`, `+0x1c`, `+0x20`, and `+0x24` are `__purecall`;
  - `DATFile` vtable `0x00618924`: those slots resolve to `0x0049c2d0`, `0x0049c2f0`, `0x0049c310`, `0x0049c3e0`;
  - `StdioFile` vtable `0x0062d5ac`: those slots resolve to `0x00582200`, `0x004f5ad0`, `0x00582230`, `0x005822d0`.

That slot match is the ownership pivot: the receiver is the existing `File` stream interface, not a new virtual-readable type and not a string class.

### Ownership Ranking

1. [UID:00004V] `File` class, accepted.
   - Strongest evidence: both helpers are `__thiscall` methods over File virtual slots. The child is now `88/90`, class parent is `86/89`, and file source root is `86/88`.

2. [UID:0000JB] `File.cpp`, accepted as source root, not direct parent.
   - This is the correct file-level root through the `File` class page. Direct attachment to the file would bypass the narrower class owner.

3. [UID:0000JD] `FileIO`, rejected as direct parent.
   - Useful umbrella/source-layout context, but `File` is the narrower direct owner.

4. [UID:0000OB] `StringUtil`, rejected.
   - String helpers are callees for destination buffer work. They are dependencies, not the receiver/owner.

5. [UID:0000OA] `StringBase`, rejected.
   - Same reason: the helper bodies pass string outputs/temporaries to StringBase-like routines, but `this` is a File-stream object.

6. [UID:00003G] `DATFile` or [UID:0000E6] `StdioFile`, rejected.
   - They implement the slots, but the helpers are generic over the abstract File interface and should not be owned by either concrete subclass.

7. New `VirtualReadable` / `ReadableString` owner, rejected.
   - The unresolved interface is now identified as the existing File stream vtable contract. Creating a new owner would duplicate the File model.

8. Adjacent `FieldMapPane` or `PoolAllocatorCore`, rejected.
   - IDA-confirmed padding and behavior separate this helper pair from both neighboring ranges.

## Caveats

- Current IDA has no direct callers or address-taken refs for the two helper starts. This leaves final source-facing method names and public/protected/private declaration placement unresolved.
- Original source grouping could still have been compact `FileIO.cpp` rather than separate `File.cpp`; this does not affect the direct by-structure parent, which is the `File` class.
- Reconstruction C++ remains blank under the 95/95 source-emission gate.
