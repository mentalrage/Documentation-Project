*** UID:0000SP | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000P6 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000P6 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
VoteMenuPane *g_pVoteMenuPane = NULL;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pVoteMenuPane

## Status

- Confidence: strong for address, owner, zero-initialized storage, lifecycle, source definition, and right-button dismissal consumers.
- Address: `0x0069ba38`
- Memory doc: [UID:0001Q0][0x0069ba38-0x0069ba3c.g_pVoteMenuPane](by-memory/0x0069ba38-0x0069ba3c.g_pVoteMenuPane.md)
- Proposed owner file: [UID:0000P6][VoteMenuPane](by-file/VoteMenuPane.md)

## Symbol Role

`g_pVoteMenuPane` is the active vote popup singleton. `VoteMenuPane` constructor stores the newly created pane here, and both ordinary and deleting destructors clear it.

The neighboring [UID:0000N7][RightButtonMenuPane](by-file/RightButtonMenuPane.md) event/cancel code checks this pointer to dismiss an active vote popup while right-click menu interaction changes.

Source-facing definition:

```cpp
VoteMenuPane *g_pVoteMenuPane = NULL;
```

B014's 2026-06-19 VoteMenuPane class pass confirms the definition belongs in [UID:0000P6][VoteMenuPane](by-file/VoteMenuPane.md). The direct storage page [UID:0001Q0][0x0069ba38-0x0069ba3c.g_pVoteMenuPane](by-memory/0x0069ba38-0x0069ba3c.g_pVoteMenuPane.md) remains the exact `.data` evidence record and should not duplicate the emitted source definition.

## Evidence Notes

- IDA MCP `py_eval` on 2026-06-05 reported item head `0x0069ba38`, size 4, segment `.data`, IDA name `dword_69BA38`, and eight direct data references. B001's 2026-06-17 live `get_bytes 0x0069ba30 size 0x14` recheck supersedes the stale initial-byte wording and reads `00 00 00 00` at `0x0069ba38`.
- Direct read refs are confined to [UID:0000N7][RightButtonMenuPane](by-file/RightButtonMenuPane.md) paths: `0x00554ca5`, `0x00554ee8`, and `0x00554f1a` inside `0x00554c40-0x00554f59`, plus `0x00554f93` inside `0x00554f90-0x00554fb3` and `0x005552a3` inside `0x005552a0-0x005552ba`.
- The raw constructor body `0x005558d0-0x00555942` publishes the singleton at `0x005558f8`, initializes vote selection bytes, stores the vote type at `this+0xfc`, installs three `VoteMenuPane` vtable views at offsets `+0x00`, `+0xa0`, and `+0xa4`, copies a `0x21`-wide-character target name, and returns with `retn 8`.
- The ordinary destructor `0x00555950-0x005559bc` restores `VoteMenuPane` vtables, runs pane cleanup helpers `0x00544ce0` and `0x00544d70`, clears `dword_69BA38` at `0x0055599d`, then calls base cleanup `0x00544580`.
- The scalar deleting destructor `0x00556320-0x005563cd` performs the same vtable restoration and cleanup sequence, clears `dword_69BA38` at `0x00556374`, and conditionally frees the object through `0x004f4ac0`.
- `callers 0x005558d0`, `0x00555950`, `0x005559c0`, and `0x00556320` report no direct static callers in the current graph. The constructor is a raw body with no modeled IDA function object, while the input/destructor paths are vtable or indirect paths.

## Data Caveat

Older automatic labels sometimes describe the `0x0069ba38` reads as a bulletin-session pointer. Treat those labels as owner pollution. `g_pBulletinSession` is a separate bulletin/mail dialog singleton, while `0x0069ba38` is the vote popup singleton.

## Cross-References

- [UID:0000FX][VoteMenuPane](by-class/VoteMenuPane.md)
- [UID:0000P6][VoteMenuPane](by-file/VoteMenuPane.md)
- [UID:0001Q0][0x0069ba38-0x0069ba3c.g_pVoteMenuPane](by-memory/0x0069ba38-0x0069ba3c.g_pVoteMenuPane.md)
- [UID:0000N7][RightButtonMenuPane](by-file/RightButtonMenuPane.md)

## Changes

- 2026-05-31: Updated reconstruction metadata and scores from live IDA evidence.
  - Before: completion/confidence were `0/0`, reconstructable state was blank, and no parent file UID was assigned.
  - After: `COMPLETION:76`, `CONFIDENCE:84`, `RECONSTRUCTABLE:TRUE`, and `AUTOGEN_PARENT_UID:0000P6` for [UID:0000P6][VoteMenuPane](by-file/VoteMenuPane.md). The old blank-C++ threshold rationale from this pass is superseded by the 2026-06-19 source global definition.
  - Evidence: IDA MCP rechecked `0x0069ba38` as a 4-byte singleton pointer with 8 data xrefs spanning VoteMenuPane construction/destruction and RightButtonMenuPane dismissal reads; it also preserves the automatic alias warning.
- 2026-06-05: Raised completion/confidence from `76/84` to `86/90`, kept the page reconstructable under [UID:0000P6][VoteMenuPane](by-file/VoteMenuPane.md), removed stale automatic-label provenance wording, and refreshed the evidence with live IDA storage, xref, raw-constructor, destructor, and caller-list checks.
- 2026-06-17 B001 source-quality correction:
  - Summary/evidence: live `get_bytes 0x0069ba30 size 0x14` reads zero-initialized bytes at `0x0069ba38`, superseding stale `0xffffffff` wording while preserving the eight-xref singleton lifecycle and RightButtonMenuPane read evidence.
- 2026-06-19 B014 VoteMenuPane singleton implementation:
  - Changed to `COMPLETION:87`, `CONFIDENCE:91`, and populated first-draft source global C++ as `VoteMenuPane *g_pVoteMenuPane = NULL;`.
  - Summary/evidence: B014 reanalysis ties the global to the accepted `VoteMenuPane.cpp` class shell, confirms zero-initialized `.data` storage, constructor publish, ordinary destructor clear, scalar deleting destructor glue clear, and RightButtonMenuPane cleanup use. Old threshold language is superseded by the current combined reconstruction gate.
