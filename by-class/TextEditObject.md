*** UID:0000EN | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000ON | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# TextEditObject

## Status

- Confidence: strong for class behavior, vtable identity, support-object placement, and scalar deleting destructor; medium-high for final field names and exact original header/source split.
- Likely source file: [UID:0000ON][TextEditPane](by-file/TextEditPane.md)
- Main address ranges: raw constructor/helper island `0x00594e60-0x00594f20` and scalar deleting destructor `0x00595670-0x005956ae`
- Current recovered file: `source-3/simroot_v2/class_TextEditObject.cpp`

## Class Purpose

`TextEditObject` is the base object for text-edit payloads or inline objects. It derives from `LObject`, stores an owner/type handle, installs a `TextEditObject` vtable, and provides a no-op virtual update hook that derived classes can override.

## Observed State

IDA-backed field usage currently supports this base layout:

```text
+0x000  vtable
+0x004  small state/type field returned by 0x00594eb0
+0x008  owner/type handle copied from the constructor argument and returned by 0x00594ee0
+0x00c  first payload/position word
+0x010  second payload/position word
```

## Method Families

| Address | Function | Role |
| --- | --- | --- |
| `0x00594e60-0x00594e99` | `TextEditObject::TextEditObject` | Raw constructor-shaped body; calls `LObject` initializer `0x004f4a80`, stores the caller argument at `+0x08`, installs vtable `0x0062e048`, and clears `+0x04/+0x0c/+0x10`. |
| `0x00594ea0-0x00594eab` | non-deleting cleanup helper | Reinstalls `TextEditObject` vtable and tail-jumps to the `LObject` cleanup helper `0x004f4a90`. |
| `0x00594eb0-0x00594eb4` | state/type accessor | Returns the dword at `+0x04`. |
| `0x00594ec0-0x00594ed5` | payload pair copy-out | Copies `+0x0c/+0x10` into the caller-provided output pair. |
| `0x00594ee0-0x00594ee4` | owner/type accessor | Returns the dword at `+0x08`. |
| `0x00594ef0-0x00594f03` | payload pair setter | Writes caller-provided values to `+0x0c/+0x10`. |
| `0x00594f10-0x00594f11` | no-op virtual hook | `nullsub_58`, vtable slot at `0x0062e054`. |
| `0x00594f20-0x00594f23` | no-op virtual hook | `nullsub_59`, returns with three arguments consumed. |
| `0x00595670-0x005956ae` | scalar deleting destructor | Vtable entry at `0x0062e048`; reinstalls base vtable, runs `LObject` cleanup, and conditionally deletes or sized-deletes according to scalar-delete flags. |

## Evidence Notes

- `EPFTextEditObject` inherits the same base shape and initializes `TextEditObject` fields before loading symbol frames.
- The class is tightly located next to `TextEditScrap` and `EPFTextEditObject`, supporting placement under the text-edit implementation module.
- 2026-06-06 live IDA MCP `lookup_funcs` confirms `0x00594e60` is still not promoted as an IDA function, while `0x00594f10` is `nullsub_58` size `0x1`, `0x00595670` is a `0x3e` scalar deleting destructor, neighboring `EPFTextEditObject` constructor `0x005954c0` is size `0xd0`, and `TextEditScrap` constructor `0x00594f30` is size `0x38`.
- 2026-06-06 raw IDA disassembly of `0x00594e60` shows a complete constructor-shaped body: call `0x004f4a80`, store the constructor argument at `+0x08`, write `??_7TextEditObject@@6B@` at `+0x00`, clear `+0x04`, `+0x10`, and `+0x0c`, then `retn 4`.
- 2026-06-06 IDA `xrefs_to 0x0062e048` reports the constructor vtable store at `0x00594e77`, cleanup helper store at `0x00594ea0`, `EPFTextEditObject` base-vtable restore at `0x00595590` and `0x00595636`, and `TextEditObject` destructor restore at `0x00595676`.
- 2026-06-06 vtable dword read shows `0x0062e048 -> 0x00595670`, `0x0062e04c -> 0x004f4b10`, `0x0062e050 -> 0x0041b6c0`, `0x0062e054 -> 0x00594f10`, and `0x0062e058 -> 0x00594f20`; `0x0062e05c` begins the adjacent `TextEditScrap` RTTI locator.
- IDA reports no direct code callers for the raw constructor, no-op hooks, or scalar deleting destructor. The destructor and no-op hook are vtable-reached; construction is evidenced by raw code and derived support-object initialization rather than direct caller xrefs.

## Cross-References

- [UID:0000ON][TextEditPane](by-file/TextEditPane.md)
- [UID:00004H][EPFTextEditObject](by-class/EPFTextEditObject.md)
- [UID:0000EP][TextEditScrap](by-class/TextEditScrap.md)
- [UID:0001JT][0x00594e60-0x005958fe.TextEditSupportObjectsAndFilter](by-memory/0x00594e60-0x005958fe.TextEditSupportObjectsAndFilter.md)
- [UID:00026O][0x0062df94-0x0062e26c.TextEditReadOnlyData](by-memory/0x0062df94-0x0062e26c.TextEditReadOnlyData.md)

## Changes

- Before: reconstruction autogen metadata was unclassified.
- Changed to: marked `RECONSTRUCTABLE:TRUE` while leaving `AUTOGEN_PARENT_UID` blank.
- Evidence: 2026-06-05 IDA MCP on `NexusTK.exe` (`md5 4247e04e20b65d6414c7238aa8ff5515`) confirmed the no-op virtual stub at `0x00594f10` and scalar deleting destructor at `0x00595670`; `0x00594e60` remains a raw non-function constructor start within the documented support-object cluster. The likely parent [UID:0000ON][TextEditPane](by-file/TextEditPane.md) passes 80/80, but this class page is only `76/78`, so the child-side parent gate does not pass. No C++ was emitted because the page is below the 95/95 reconstruction-code bar.
- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `76`, confidence `78`.
- Evidence: the page documents the base-object role, likely owner, constructor/no-op/destructor ranges, inheritance context, and support-object memory cluster; completion remains limited because exact file split and derived-object field semantics are not fully detailed.

- 2026-06-06 live IDA vtable/support-object pass:
  - Before: the class page stayed below the parent-attach gate and omitted the base helper/accessor island, exact vtable slots, and constructor raw-disassembly evidence.
  - Changed to: `COMPLETION:82`, `CONFIDENCE:86`, and parent [UID:0000ON][TextEditPane](by-file/TextEditPane.md).
  - Evidence: live IDA MCP confirmed the raw constructor body, helper/accessor island, `nullsub_58`/`nullsub_59` slots, scalar deleting destructor, vtable dwords, `TextEditScrap` boundary at `0x0062e05c`, and matching base-vtable restores from `EPFTextEditObject`. C++ remains blank because exact field names and source-quality declarations are below the 95/95 reconstruction-code gate.
