*** UID:0000QR | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000IS | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000IS | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:20 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
DescPane *g_pDescPane = NULL;

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pDescPane

## Status

- Confidence: very strong for source type/name, loader-zero initialization,
  exactly four class-island refs, one definition, file ownership, source
  position, and storage coverage.
- Address: `0x0069adf8`
- Memory doc: [UID:0001PB][0x0069adf8-0x0069adfc.g_pDescPane](by-memory/0x0069adf8-0x0069adfc.g_pDescPane.md)
- Proposed owner file: [UID:0000IS][DescPane](by-file/DescPane.md)

## Symbol Role

`g_pDescPane` is the active description pane singleton. The `DescPane` constructor stores the live object pointer here, the non-deleting and scalar deleting destructors clear it, and a small getter returns the pointer.

B005's 2026-06-18 source-quality pass confirms that `dword_69ADF8` should not remain the source-facing name. All observed refs are inside the `DescPane` island, the constructor first-draft C++ should use `g_pDescPane = this;`, and the B010 getter pass now emits [UID:00012M][0x0049d770-0x0049d776.DescPaneGetSingleton](by-memory/0x0049d770-0x0049d776.DescPaneGetSingleton.md) as `return g_pDescPane;`.

## Evidence Notes

- A 2026-05-25 follow-up records this global as resolved data at the reviewed four-byte storage range documented as `0x0069adf8-0x0069adfc`.
- IDA MCP `py_eval` reports the raw item as `dword_69ADF8`, size `4`, in `.data`.
- IDA xrefs to `0x0069adf8` include:
  - `0x0049d731` inside the raw `DescPane` constructor store;
  - `0x0049d75a` inside the non-deleting destructor clear;
  - `0x0049d770` inside the singleton getter read;
  - `0x0049d860` inside the scalar deleting destructor clear.
- No external caller/xref fanout was observed in the current IDA query, so source ownership stays with `DescPane.cpp`.
- 2026-05-26 recheck: IDA MCP `py_eval` still reports `0x0069adf8` as `dword_69ADF8`, size `4`, in `.data`; `xrefs_to 0x0069adf8` still lists only the four `DescPane` island refs above.
- 2026-06-18 B005 raw-memory immediate scan saw the storage ref in the constructor at `0x0049d733`, destructor at `0x0049d75c`, getter at `0x0049d771`, and scalar destructor at `0x0049d862`; the instruction addresses remain `0x0049d731`, `0x0049d75a`, `0x0049d770`, and `0x0049d860`.
- B005 rejected feature-dialog ownership and generic anonymous global treatment because no xrefs leave the `DescPane` lifecycle/getter island.

## Cross-References

- [UID:00003Q][DescPane](by-class/DescPane.md)
- [UID:0000IS][DescPane](by-file/DescPane.md)
- [UID:00012K][0x0049d6f0-0x0049d89f.DescPane](by-memory/0x0049d6f0-0x0049d89f.DescPane.md)
- [UID:0001PB][0x0069adf8-0x0069adfc.g_pDescPane](by-memory/0x0069adf8-0x0069adfc.g_pDescPane.md)

## 2026-07-16 B001 UID0002NA Accepted Callback

- Applied `92/94`, file position 20, and the exact managed definition plus
  storage child route.
- The complete class declaration supplies `extern DescPane *g_pDescPane;`.
  This page supplies the one source definition
  `DescPane *g_pDescPane = NULL;`.
- UID0001PB proves the slot is in the loader-zero-filled `.data` virtual tail.
  The four refs are constructor publish, ordinary-destructor clear, getter
  read, and scalar-wrapper clear; no external registry or feature-dialog ref
  exists.
- Raw `dword_69ADF8`, duplicate storage, dynamic initialization, and a broader
  singleton owner are rejected.

## Changes

- 2026-07-16 B001 UID0002NA accepted callback:
  - Raised `88/86 -> 92/94`, set file position 20, installed the exact managed
    global definition/child route, and preserved the complete four-ref
    lifecycle evidence.
- 2026-06-19 B010 getter source-quality incorporation:
  - Before: the page tied `g_pDescPane` to constructor C++ but did not state that the singleton getter child now emits with the source-facing name.
  - Changed to: recorded that [UID:00012M][0x0049d770-0x0049d776.DescPaneGetSingleton](by-memory/0x0049d770-0x0049d776.DescPaneGetSingleton.md) should return `g_pDescPane` in first-draft C++ and keep `dword_69ADF8` as raw evidence only.
  - Summary/evidence: raw getter bytes read the four-byte singleton storage, and all storage refs remain confined to the `DescPane` lifecycle/getter island.
- 2026-06-18 B005 constructor source-quality incorporation:
  - Before: the page documented `dword_69ADF8` as the IDA name but did not explicitly tie the new constructor C++ to `g_pDescPane`.
  - Changed to: recorded B005's confirmation that `g_pDescPane` is the source-facing singleton name and that `dword_69ADF8` should not be used in emitted constructor code.
  - Summary/evidence: constructor publish, destructor/scalar-destructor clear, getter read, and no external xref fanout all remain confined to the `DescPane` island.
- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `88/86`. Summary/evidence: the page documents address, memory page, owner, constructor/destructor/getter xrefs, no external fanout, recheck notes, and class/file/memory refs.
- 2026-06-05: Marked reconstructable under [UID:0000IS][DescPane](by-file/DescPane.md). Evidence: live IDA MCP reports four xrefs to `0x0069adf8`; decompilation confirms `0x0049d740` and `0x0049d840` clear `dword_69ADF8`, while `0x0049d770` returns the active singleton pointer.
