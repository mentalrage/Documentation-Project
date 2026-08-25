** TARGET-REPORT-UID:0002A8 **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002A8 MoreInfoPaneSingletonSlot Source-Quality Report

## Finalized Report / Current Recommendation

FINISHED report-only research for [UID:0002A8][0x0069bed4-0x0069bed8.MoreInfoPaneSingletonSlot](../../../../../by-memory/0x0069bed4-0x0069bed8.MoreInfoPaneSingletonSlot.md).

- Current recommendation: keep the target with [UID:0000P0][UserLookPane](../../../../../by-file/UserLookPane.md), close the old "source-level retention open" wording as a high-probability retained source global, and document the source-facing declaration as `MoreInfoPane *g_pMoreInfoPane = 0;`.
- Final disposition: reconstructable four-byte zero-initialized writable pointer slot, owned/emitted through `NexusTK/ui/panels/UserLookPane.cpp`.
- Score recommendation: raise from `85/86` to `88/89`.
- Metadata recommendation: keep `CANONICAL_OWNER:0000P0`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000P0`, blank `EMITTER_POSITION_OPTIONAL`.
- C++ recommendation: populate the target's formal code block with the declaration-only draft below. The constructor assignment itself belongs to [UID:0003RI][0x0059f260-0x0059f4fd.UserLookPaneConstructor](../../../../../by-memory/0x0059f260-0x0059f4fd.UserLookPaneConstructor.md), not this data-slot page.
- No by-* documentation files were edited. `by-memory/-coverage-report.md` was not edited.

## Target

- Target UID: `0002A8`
- Target path: `by-memory/0x0069bed4-0x0069bed8.MoreInfoPaneSingletonSlot.md`
- Current target state: `COMPLETION:85`, `CONFIDENCE:86`, `CANONICAL_OWNER:0000P0`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000P0`, blank formal C++.
- Current shared coverage row is stale at `75% : medium`.
- Assignment row checked: `tools/leaser/Agents/SupervisorAssignments.md` lists `B004-goal2-more-info-pane-singleton-slot-source-quality-0002A8-20260619` for Agent-B004.

## Evidence Checked

- Target page: `by-memory/0x0069bed4-0x0069bed8.MoreInfoPaneSingletonSlot.md`.
- Support pages: `by-file/UserLookPane.md`, `by-class/UserLookPane.md`, `by-class/MoreInfoPane.md`, `by-class/ProfilePane.md`, `by-memory/0x0059f260-0x0059f4fd.UserLookPaneConstructor.md`, `by-memory/0x005a22e0-0x005a233d.MoreInfoPaneRawConstructor.md`, `by-memory/0x0059f260-0x005a2523.UserLookPaneAndProfilePanes.md`, `by-memory/0x0062eccc-0x0062ef0c.UserLookReadOnlyData.md`, `by-type/by-vtable/UserLookPaneFamilyVtables.md`, and `by-memory/0x0066d000-0x0069d000.DataSection.md`.
- Adjacent storage pages: `by-memory/0x0069bed0-0x0069bed4.UserListDialogHuntersListOnlyFlag.md` and `by-memory/0x0069bed8-0x0069bee0.TargetSelectionModeFlags.md`.
- Generated output route: `auto-generated/NexusTK/ui/panels/UserLookPane.cpp` currently contains only the empty emitter marker for UID `0002A8`.
- Generated/shared reports: `auto-generated/-ag-memory-coverage.md`, `project-level/-auto-completion-stats.md`, `project-level/-resolved.md`, `project-level/-unresolved.md`, and `by-memory/-coverage-report.md`.
- Source placement reference: `by-project-structure/proposed-source-tree.md` keeps `MoreInfoPane` and `ProfilePane` inside `ui/panels/UserLookPane.cpp`, with `LegendPane` separate/shared.
- Binary checked directly: `E:\NTK\Resources\NexusTK\NexusTK.exe`.

## Direct Binary Recheck

The PE scan independently validates the older IDA notes instead of copying them forward.

- Image base: `0x00400000`.
- `.text`: `0x00401000-0x0060c4ac`, raw-backed.
- `.rdata`: `0x0060d000-0x0066c0be`, raw-backed.
- `.data`: `0x0066d000-0x0069ce24`, raw `0x26ac00-0x278400`; bytes after the raw payload through the virtual end are zero-fill.
- Target VA `0x0069bed4` is inside `.data` but has no file raw offset, so it is zero-initialized BSS-style storage inside the writable section.
- Searching the whole executable for little-endian `d4 be 69 00` found exactly one hit, in `.text` at VA `0x0059f35e`, the immediate operand of the instruction at `0x0059f35c`.
- Disassembly from the function start confirms:

```asm
0x0059f2ec: push     0x174
0x0059f2f1: call     0x4f4aa0
0x0059f2f6: mov      esi, eax
0x0059f302: test     esi, esi
0x0059f304: je       0x59f354
0x0059f333: call     0x58dce0
0x0059f338: mov      dword ptr [esi], 0x62ed58
0x0059f33e: mov      dword ptr [esi + 0xa0], 0x62edd0
0x0059f348: mov      dword ptr [esi + 0xa4], 0x62ee00
0x0059f354: xor      esi, esi
0x0059f356: mov      dword ptr [edi + 0xf8], esi
0x0059f35c: mov      dword ptr [0x69bed4], esi
0x0059f362: mov      ecx, dword ptr [edi + 0xf8]
0x0059f36e: call     0x5446b0
```

This proves the exact data flow: allocate `0x174` bytes, construct/setup a child pane, install the `MoreInfoPane` vtables, store the resulting pointer in `UserLookPane + 0xf8`, then copy the same pointer to `0x0069bed4`. If allocation fails, `esi` is zeroed and both the member and global receive null.

## Heuristic / Inference Reanalysis And Validation

### `dword_69BED4` / `unk_69BED4`

- Best source-facing name: `g_pMoreInfoPane`.
- Evidence: the slot is a four-byte writable pointer, receives the just-created `MoreInfoPane*`, and all relevant support docs place `MoreInfoPane` as a user-look-local child. `project-level/-resolved.md` already maps `dword_69BED4` to `MoreInfoPane`.
- Rejected `dword_69BED4` / `unk_69BED4` as final source names: they are compiler/IDA placeholders and carry no source meaning.
- Rejected `s_pMoreInfoPane` as the primary recommendation: internal static linkage is possible, but the final executable has no reads. A non-static `g_` global is the stronger source-shape explanation for why an otherwise dead assignment is retained in a non-LTCG style build.
- Remaining uncertainty: exact original spelling and linkage cannot be proven without PDB/map/source metadata. This caps confidence below final-audit quality but does not block a descriptive first draft.

### Global Versus Member

- Best member name: `UserLookPane::m_moreInfoPane` at offset `+0xf8`.
- Best global name: `g_pMoreInfoPane` at `0x0069bed4`.
- Evidence: the constructor writes both locations from the same `esi` value. The member is immediately reloaded and passed to `0x005446b0`, so the live object relationship is member-owned. The global has no direct reads or address-taken references in the PE scan.
- Rejected "member-only duplicate" as the full answer: the absolute store to `0x0069bed4` is a real instruction and cannot be explained by the member field alone.
- Final inference: the member is the live ownership mechanism; the global is a retained singleton/debug/compatibility alias of that child.

### Source Retention Versus Compiler/Linker Residue

- Best inference: source-retained global storage, probably from an assignment like `g_pMoreInfoPane = m_moreInfoPane;` in the `UserLookPane` constructor.
- Evidence: the compiler/linker can allocate zero-fill storage, but it does not invent a semantic absolute write to a `MoreInfoPane*` slot after a child-pane construction sequence. The write is in ordinary project constructor code, not a CRT initializer, import thunk, vtable, EH table, or relocation-only artifact.
- Rejected "generated binary residue": no compiler artifact pattern explains a standalone global pointer assignment to a UI child after vtable installation.
- Rejected "pure debug-only local removed from source": the final executable still contains both storage and the write, so the rebuilt source must preserve a source-level declaration if the constructor body is later reconstructed accurately.
- Rejected "source-level global is disproven by no reads": no reads prove the global is not live behavior in this binary, but they do not disprove that the source declared and assigned it.

### Owner And Source Placement

- Best direct owner/emitter for this report: [UID:0000P0][UserLookPane](../../../../../by-file/UserLookPane.md).
- Evidence: `UserLookPane.cpp` owns the constructor, `MoreInfoPane`/`ProfilePane` local child classes, the `MoreInfoPane` vtable family, and the target's only write. `by-project-structure/proposed-source-tree.md` independently places `MoreInfoPane` and `ProfilePane` inside `ui/panels/UserLookPane.cpp`.
- Rejected `MoreInfoPane` class as canonical owner for this data slot: the slot is not accessed by `MoreInfoPane` methods; it is assigned by `UserLookPane::UserLookPane` as module state.
- Rejected `UserLookPane` class as narrower canonical owner for this data slot: the slot is not a class member or vtable/type artifact; it is file/module-level static storage adjacent to the user-look source.
- Rejected `GeneralPurposePanel`: it constructs `UserLookPane` but never touches this global.
- Rejected adjacent `.data` owners: `0x0069bed0-0x0069bed4` is the UserList hunters-list-only flag and `0x0069bed8-0x0069bee0` is target-selection mode state. Address adjacency is weak evidence and contradicted by xrefs/source families.
- No by-global page currently exists for `g_pMoreInfoPane`. Creating one later would be structurally reasonable for consistency with other `g_p...` pane globals, but it is not required to close this target because no reader/clear-helper/lifecycle API exists beyond the constructor write. The exact implementation checklist therefore keeps the target file-owned and emits the declaration directly through UID `0000P0`.

### Type And Storage

- Best type: `MoreInfoPane *`.
- Size/range: four bytes, `0x0069bed4-0x0069bed8`.
- Initial value: zero, by virtual zero-fill in `.data`.
- Rejected `int`, `DWORD`, flag, table entry, or vtable interpretation: the only write source is a heap pointer after `MoreInfoPane` vtable stores, and the address is not in `.rdata`/vtable storage.

### Reachability And Call Route

- Only direct reference to the storage in the executable is the write at `0x0059f35c`.
- The containing constructor [UID:0003RI] has one documented caller from `GeneralPurposePanel` at `0x004b8477`.
- No read, clear, destructor reset, address-taken, or second writer was found by raw PE immediate search. Existing docs likewise report one direct xref and no direct reads.
- Inference: runtime behavior does not depend on this global in the current binary; preserving the declaration and later constructor assignment is about faithful source/data reconstruction, not about a live access path.

### Split / Range Decision

- Keep the exact four-byte range. It contains one pointer slot and no mixed sub-items.
- Do not merge with the preceding UserList flag or following TargetSelection flags; xref families and owners differ.
- Do not split smaller; a pointer is already the minimal meaningful source/storage unit.

### Open-Question Closure

- Source-retention question: closed as high-probability source-retained global storage, with no direct runtime consumers.
- Final source-facing name: closed to descriptive `g_pMoreInfoPane`; original spelling remains unprovable and caps confidence.
- Owner/source placement: closed to `UserLookPane.cpp` for this implementation pass.
- Emit/no-code policy: no-code is no longer the best recommendation. The target clears the combined-score/emitter gate and has a safe range-limited declaration draft.

## First-Draft C++ Recommendation

Populate UID `0002A8` with declaration-only C++:

```cpp
MoreInfoPane *g_pMoreInfoPane = 0;
```

Reasoning: the target range is the storage for a zero-initialized global pointer, not the constructor write instruction. The declaration is compact, mid-2000s-compatible C++ and does not invent behavior outside the range. The corresponding assignment should be added only when [UID:0003RI] `UserLookPaneConstructor` receives constructor C++:

```cpp
m_moreInfoPane = constructedMoreInfoPane;
g_pMoreInfoPane = m_moreInfoPane;
```

That assignment sketch is support context only and must not be pasted into UID `0002A8`.

## Ranked Ownership Analysis

### 1. `UserLookPane.cpp` / UID `0000P0`

- Evidence for: only write is in `UserLookPane::UserLookPane`; `MoreInfoPane` is a local child of the user-look module; file, class, executable, vtable, `.rdata`, and proposed-source-tree docs all agree.
- Evidence against: the final original variable spelling/linkage is unknown, and no direct reads prove a broader API.
- Decision: accept as direct owner/emitter for this report.

### 2. New by-global `g_pMoreInfoPane`

- Evidence for: the item is a source-level global pointer and the project has many `g_p...Pane` by-global pages.
- Evidence against: no reader, clear-helper, helper API, or lifecycle outside the constructor write exists, so creating a separate global page is useful but not necessary for current reconstruction and would require a new UID during implementation.
- Decision: do not require creation in the first callback. Mention as optional future normalization only if the supervisor wants every pane singleton slot represented as by-global.

### 3. `MoreInfoPane` class / UID `00008Q`

- Evidence for: the pointer type is `MoreInfoPane*`.
- Evidence against: no `MoreInfoPane` method accesses the storage, and the write occurs in `UserLookPane::UserLookPane`.
- Decision: reject as canonical owner for this slot.

### 4. Adjacent `.data` or section ownership

- Evidence for: the slot is physically adjacent to other writable globals.
- Evidence against: adjacent rows are UserList and TargetSelection owners with unrelated xref sets; `.data` is a section container, not a source owner.
- Decision: reject.

## Target / Support Implementation Checklist

1. Update target `by-memory/0x0069bed4-0x0069bed8.MoreInfoPaneSingletonSlot.md`.
2. Change metadata to `COMPLETION:88`, `CONFIDENCE:89`; keep owner/emitter `0000P0`.
3. Replace the old "source-level retention remains open" wording with the closed inference: high-probability source-retained `MoreInfoPane*` global alias, no direct reads/consumers in the current executable.
4. Add PE evidence: `.data` virtual zero-fill, no raw file offset for `0x0069bed4`, exactly one executable little-endian reference, and the disassembly sequence at `0x0059f2ec-0x0059f36e`.
5. Add source-facing names: `UserLookPane::m_moreInfoPane` for `this+0xf8` and `g_pMoreInfoPane` for `0x0069bed4`.
6. Add rejected alternatives: compiler-generated residue, member-only duplicate, `MoreInfoPane` class ownership, adjacent UserList/TargetSelection ownership, no-code policy, and generic `dword_69BED4` naming.
7. Populate target `RECONSTRUCTION_CPP CODE` with `MoreInfoPane *g_pMoreInfoPane = 0;`.
8. Update `by-file/UserLookPane.md` to close the direct-read/retention caveat and name the slot `g_pMoreInfoPane` while keeping `MoreInfoPane` as a local child and `LegendPane` as a shared caveat.
9. Update `by-class/UserLookPane.md` to record `m_moreInfoPane` at `+0xf8`, the `g_pMoreInfoPane` write, and the no-read negative evidence.
10. Update `by-class/MoreInfoPane.md` to replace "medium-high for whether the observed singleton slot was source-retained" with the high-probability source-retained global-alias conclusion, while preserving that this does not broaden ownership beyond `UserLookPane.cpp`.
11. Update `by-memory/0x0059f260-0x005a2523.UserLookPaneAndProfilePanes.md` and `by-memory/0x0059f260-0x0059f4fd.UserLookPaneConstructor.md` so their open singleton-slot wording matches this conclusion.
12. Update `by-memory/0x0066d000-0x0069d000.DataSection.md` child work queue to remove UID `0002A8` from "still need final declaration/name decisions" after the target is updated.
13. Do not edit `by-memory/-coverage-report.md`; use the supervisor-owned replacement row below.
14. Run scoped validators after implementation, at minimum the target file and edited support files; then refresh generated output as needed so `auto-generated/NexusTK/ui/panels/UserLookPane.cpp` contains the UID `0002A8` declaration.

## Exact Supervisor-Owned Coverage Row

Placement: replace the current UID `0002A8` row immediately after UID `0002A7` and before UID `0002A9` in `by-memory/-coverage-report.md`.

```markdown
    - [UID:0002A8][0x0069bed4-0x0069bed8.MoreInfoPaneSingletonSlot](by-memory/0x0069bed4-0x0069bed8.MoreInfoPaneSingletonSlot.md) 0x0069bed4-0x0069bed8 | global-data pointer | MoreInfoPaneSingletonSlot : reconstructable : 88% : strong : Source-retained `MoreInfoPane*` global best named `g_pMoreInfoPane`, owned/emitted through [UID:0000P0][UserLookPane](by-file/UserLookPane.md); PE scan confirms zero-filled `.data` storage and exactly one direct reference, the `UserLookPane::UserLookPane` write at `0x0059f35c` immediately after storing the same child pointer at `this+0xf8`. No direct reads/address-taken refs remain in the final executable, so treat it as a dead/debug/compatibility singleton alias rather than the live ownership mechanism; the live child relationship is `UserLookPane::m_moreInfoPane` at `+0xf8`, and constructor-assignment C++ belongs to [UID:0003RI][0x0059f260-0x0059f4fd.UserLookPaneConstructor](by-memory/0x0059f260-0x0059f4fd.UserLookPaneConstructor.md).
```

## Validator Baseline

Command run from `E:\NTK\GhidraBridge\source-3\project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [0002A8-MoreInfoPaneSingletonSlot-source-quality-removed.md](0002A8-MoreInfoPaneSingletonSlot-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Result: exit code `0`, `ok: 1`.

Relevant output:

```text
mode: file
scanned markdown files: 1
ok: 1
ok           0002A8 by-memory/0x0069bed4-0x0069bed8.MoreInfoPaneSingletonSlot.md UID header exists
dry run only; pass --apply to write changes
```

The remaining validator lines were broad autogen dry-run/noop messages and existing unrelated marker warnings; no target failure was reported.

## Changed Files In This Report-Only Pass

- Created: `tools/leaser/Agents/Agent-B004/research/0002A8-MoreInfoPaneSingletonSlot-source-quality.md`.
- To be updated after this report: `tools/leaser/Agents/Agent-B004/notes.md` with the report path and pending supervisor-owned coverage text.
- Not edited: all by-* docs and `by-memory/-coverage-report.md`.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000004165","destination_path":"executed-b-agent-research/B004/0002A8-MoreInfoPaneSingletonSlot-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:29","uid":"0002A8"} -->
<!-- {"agent":"B004","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002A8-MoreInfoPaneSingletonSlot-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B004/0002A8-MoreInfoPaneSingletonSlot-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002A8"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
